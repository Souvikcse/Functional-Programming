package com.company;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class JPandPlan {
    static class Reader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

     /*   public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }*/

        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
    static boolean on_edge(int x, int y, int n, int m){
        if (x==0 || y==0 || x==n-1 || y==m-1)
            return true;
        return false;
    }
    static boolean desired_path(int[][] height, int i, int j, int h){
        if (on_edge(i, j, height.length, height[0].length)){
            return true;
        }
        else {
            if ((height[i][j] - height[i - 1][j]) <= h) {
                if (desired_path(height, i - 1, j, h))                   //UP
                    return true;
            }
            if ((height[i][j] - height[i][j - 1]) <= h) {
                if (desired_path(height, i, j - 1, h))                   //LEFT
                    return true;
            }
            if ((height[i][j] - height[i + 1][j]) <= h) {
                if (desired_path(height, i + 1, j, h))                   //DOWN
                    return true;
            }
            if ((height[i][j] - height[i][j + 1]) <= h) {
                if (desired_path(height, i, j + 1, h))                   //RIGHT
                    return true;
            }
        }

        return false;
    }
    public static void main(String[] args) throws IOException {
        Reader sc=new Reader();
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[][] height=new int[n][m];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                height[i][j]=sc.nextInt();

        int dx=sc.nextInt()-1;
        int dy=sc.nextInt()-1;
        int h=sc.nextInt();
        boolean ans=desired_path(height, dx, dy, h);
        if (ans)
            System.out.println("YES");
        else
            System.out.println("NO");

        sc.close();
    }
}
