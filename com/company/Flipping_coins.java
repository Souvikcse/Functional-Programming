package com.company;

import java.util.*;

public class Flipping_coins {
    static int solve(int a[],int n){
        int curr_sum=0;
        int best=0, start=0, end=0, s=0;
        for (int i=0;i<a.length;i++){
            if (a[i]==0)
                curr_sum+=1;
            else
                curr_sum-=1;

            if (best < curr_sum)
            {
                best = curr_sum;
                start = s;
                end = i;
            }

            if (curr_sum < 0)
            {
                curr_sum = 0;
                s = i + 1;
            }
        }
        int index=0;
        int c=0;
        while (index<a.length){
            if (index>=start && index<=end){
            }
            else {
                if (a[index]==1)
                    c+=1;
            }
            index++;
        }
        if (end==start){
            if (a[end]==1){
                c=best+1;
            }
        }
        else {
            c+=best;
        }
            return c;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] ar=new int[n];
        for (int i=0;i<n;i++)
            ar[i]=sc.nextInt();

        System.out.println(solve(ar, n));
    }
}
