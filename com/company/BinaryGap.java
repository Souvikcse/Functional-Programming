package com.company;

import java.util.Scanner;

public class BinaryGap {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- >0){
        int n= sc.nextInt();

        int gap = 0;
        int maxGap = -1;
        int lim = (int) (Math.log(n) / Math.log(2));
        boolean flag = false;
        for (int i=0;i<=(lim);i++){
            if ((n & (1<<i)) == 0)
                gap++;
            else{
                if (gap > maxGap && flag)
                    maxGap = gap;

                flag = true;
                gap = 0;
            }
        }
        System.out.println(maxGap);
        }
    }
}
