package com.company;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class EvaluatingFunctions {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        BigInteger x=sc.nextBigInteger();

        BigInteger ans=x.pow(3);
        ans=ans.multiply(BigInteger.valueOf(4));
       // System.out.print(ans+" ");
        ans=ans.add(x.pow(2).multiply(BigInteger.valueOf(5)));
       // System.out.print(ans+" ");
        ans=ans.subtract(x.multiply(BigInteger.valueOf(6)));
        ans=ans.add(BigInteger.valueOf(14));
        System.out.println(ans);
    }
}
