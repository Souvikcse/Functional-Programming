package com.company;

public class ROR {
    static long calc(String in, String patt, int i, int j, long[][] dp){
        if (j==patt.length())
            return 1;
        if (i==in.length())
            return 0;
        if (dp[i][j]!=-1)
            return dp[i][j];

        if (in.charAt(i)== patt.charAt(j)){
            long sol1=calc(in, patt, i+1, j+1, dp);
            long sol2=calc(in, patt, i+1, j, dp);
            dp[i][j]= sol1+sol2;
            return dp[i][j];
        }
        else {
            dp[i][j]= calc(in, patt, i+1, j, dp);
            return dp[i][j];
        }

    }
    public static void main(String[] args) {
        String s="ROOORO";
        String pattern="ROR";
        long[][] dp=new long[s.length()][3];
        for (int k=0;k<s.length();k++)
            for (int l=0;l<3;l++)
                dp[k][l]=-1;

        System.out.println(calc(s, pattern, 0, 0, dp));
    }
}