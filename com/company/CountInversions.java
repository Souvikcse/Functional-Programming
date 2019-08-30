package com.company;

import java.io.*;
public class CountInversions {
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
    static int count=0;
    static void merge(int[] ar, int left, int mid, int right){
        int n1=mid-left+1;
        int n2=right - mid;

        int[] L=new int[n1];
        int[] R=new int[n2];

        for (int i=0; i<n1; ++i)
            L[i] = ar[left + i];
        for (int j=0; j<n2; ++j)
            R[j] = ar[mid + 1+ j];

        int k=left;
        int i=0, j=0;
        while (i<n1 && j<n2){
            if(L[i]<=R[j]){
                ar[k]=L[i++];
            }
            else{
                count+=n1-i;
                ar[k]=R[j++];
            }
            k++;
        }
        while (i<n1){
            ar[k++]=L[i++];
        }
        while (j<n2){
            ar[k++]=R[j++];
        }
    }
    static void sort(int[] arr, int l, int r){
        if(l<r){
            int mid=(l+r)/2;

            sort(arr, l, mid);
            sort(arr, mid+1, r);

            merge(arr, l, mid, r);
        }
    }
    public static void main(String[] args) throws IOException {
        Reader sc=new Reader();
        int n=sc.nextInt();
        int[] ar=new int[n];
        for(int i=0;i<n;i++)
            ar[i]=sc.nextInt();

        sort(ar, 0, n-1);
        System.out.println(count);
    }
}
