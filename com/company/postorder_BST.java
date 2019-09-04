package com.company;

import java.io.*;
import java.util.*;

public class postorder_BST {

    static class BST_Node{
        int data;
        BST_Node left, right;
    }
    static int findlarger(int[] ar){
        int index = 0;
        for (int i=1; i<ar.length;i++) {
            if (ar[i] > ar[0]) {
                index = i;
                break;
            }
        }
        if (index == 0)
            index = ar.length;

        return index;
    }
    static BST_Node head;
    static BST_Node build_BST(int[] pre){
        if(pre.length == 0)
            return null;

        BST_Node temp = new BST_Node();
        temp.data = pre[0];
        int n = pre.length;

        int loc = findlarger(pre);
        temp.left = build_BST(Arrays.copyOfRange(pre, 1, loc));
        if (loc != n)
        temp.right = build_BST(Arrays.copyOfRange(pre, loc, n));

        return temp;
    }
    static void Inorder(BST_Node root){
        if (root == null)
            return;

        Inorder(root.left);
        System.out.print(root.data + " ");
        Inorder(root.right);
    }
    public static void main(String[] args) {
        int pre[] = new int[]{10, 5, 1, 7, 40, 50};
        head = build_BST(pre);
        Inorder(head);
    }
}
