package com.company;

import java.math.BigInteger;
import java.util.*;

public class Julka {
    static void compute(BigInteger N, BigInteger K){
        BigInteger x,y;

        x=N.subtract(K);
        x=x.divide(BigInteger.valueOf(2));
        y=x.add(K);

        System.out.println(y);
        System.out.println(x);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=10;
        while(t>0){
            BigInteger N=sc.nextBigInteger();
            BigInteger K=sc.nextBigInteger();
            compute(N, K);
            t--;
        }
    }
}
