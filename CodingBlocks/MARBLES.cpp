 #include<bits/stdc++.h>
 #include<iostream>

 using namespace std;

 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         long long n,k,minnk,i,answer=1;
         cin>>n>>k;
         n--;
         k--;
         if(k>n-k)
            minnk=n-k;
         else
            minnk=k;
         for(i=0;i<minnk;i++)
         {
             answer=answer*(n-i);
             answer=answer/(i+1);
         }
         cout<<answer<<endl;
     }
 }
