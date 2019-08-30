package com.company;

public class String_Maker {
    static int mod=1000000007;
    static int calc(String a, String b, String c, int i1, int i2, int i3){
        if (i3==c.length())
            return 1;
        if (i1==a.length() && i2==b.length())
            return 0;

        if (i1 < a.length() && i2 < b.length() && a.charAt(i1)==c.charAt(i3) && b.charAt(i2)==c.charAt(i3)){
            int ans1=calc(a, b, c, i1+1, i2, i3+1);
            int ans2=calc(a, b, c, i1, i2+1, i3+1);
            int ans3=calc(a, b, c, i1+1, i2+1, i3);
            return (ans1+ans2+ans3)%mod;
        }
        else if (i1<a.length() && a.charAt(i1)==c.charAt(i3)){
            int ans1=calc(a, b, c, i1+1, i2, i3+1);
            int ans2=calc(a, b, c, i1+1, i2, i3);
            return (ans1+ans2)%mod;
        }
        else if (i2<b.length() && b.charAt(i2)==c.charAt(i3)){
            int ans1=calc(a, b, c, i1, i2+1, i3+1);
            int ans2=calc(a, b, c, i1, i2+1, i3);
            return (ans1+ans2)%mod;
        }
        else {
            return calc(a, b, c, i1+1, i2+1, i3);
        }
    }
    static int solve(String a,String b,String c){
        return calc(a, b, c, 0, 0, 0);
    }
    public static void main(String[] args) {
        String a="abc";
        String b="abc";
        String c="abc";

        solve(a, b, c);
    }
}
