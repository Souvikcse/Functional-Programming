#include<bits/stdc++.h>
typedef long long ll;
#define Size(a) (int)sizeof(a)/sizeof(a[0])
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

class Data{
    public:
    int val;
    int freq;
};
bool compare(Data o1, Data o2){
    if(o1.freq == o2.freq)
      return (o1.val < o2.val);

    return (o1.freq > o2.freq);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
       int n;
       cin>>n;
       Data ar[61];
       REP(0, 61, 1){
           ar[i].val=i;
           ar[i].freq=0;
       }
       REP(0, n, 1){
           int x;
           cin>>x;
           ar[x].freq++;
       }
       sort(ar, ar+61, compare);
       int k=0;
       while(ar[k].freq){
           int value=ar[k].val;
           REP(0, ar[k].freq, 1){
               cout<<value<<" ";
           }
           k++;
       }
       cout<<"\n";
    }
}