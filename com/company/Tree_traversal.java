package com.company;
import java.io.*;
import java.util.Arrays;

public class Tree_traversal {
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
//    static class BufferOutput {
//
//        private DataOutputStream dout;
//        final private int BUFFER_SIZE = 1 << 16;
//        private byte[] buffer;
//        private int pointer = 0;
//
//        public BufferOutput() {
//            buffer = new byte[BUFFER_SIZE];
//            dout = new DataOutputStream(System.out);
//        }
//
//        public BufferOutput(OutputStream out) {
//
//            buffer = new byte[BUFFER_SIZE];
//            dout = new DataOutputStream(out);
//        }
//
//        public void writeBytes(byte arr[]) throws IOException {
//
//            int bytesToWrite = arr.length;
//
//            if (pointer + bytesToWrite >= BUFFER_SIZE) {
//                flush();
//            }
//            for (int i = 0; i < bytesToWrite; i++) {
//                buffer[pointer++] = arr[i];
//            }
//        }
//
//        public void writeString(String str) throws IOException {
//            writeBytes(str.getBytes());
//        }
//
//        public void flush() throws IOException {
//            dout.write(buffer, 0, pointer);
//            dout.flush();
//            pointer = 0;
//        }
//
//        public void close() throws IOException {
//            dout.close();
//        }
//    }
    static class Node{
        int data;
        Node left, right;
    }
    static Node head;
    static int search(int[] ar, int val){
        for (int i=0;i<ar.length;i++)
            if (ar[i] == val)
                return i;

        return -1;
    }
    static Node buildTree(int[] in, int[] pre){
        if (in.length == 0 || pre.length == 0)
            return null;

        Node root = new Node();
        int rootIdx = search(in, pre[0]);

        root.left = buildTree(Arrays.copyOfRange(in, 0, rootIdx), Arrays.copyOfRange(pre, 1, rootIdx+1));

        root.right = buildTree(Arrays.copyOfRange(in, rootIdx+1, in.length), Arrays.copyOfRange(pre, rootIdx+1, pre.length));

        root.data = pre[0];
        return root;
    }
    static void printPostOrder(Node root){
        if (root == null)
            return;

        printPostOrder(root.left);
        printPostOrder(root.right);
        System.out.print(root.data + " ");
    }
    public static void main(String[] args) throws IOException {
        //Reader sc = new Reader();
        //BufferOutput bO = new BufferOutput();
        int in[] = { 4, 2, 5, 1, 3, 6 };
        int pre[] = { 1, 2, 4, 5, 3, 6 };

        head = buildTree(in, pre);
        printPostOrder(head);
    }
}
