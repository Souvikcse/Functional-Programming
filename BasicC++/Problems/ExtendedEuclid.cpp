#include<iostream>
#include<vector>
typedef long long ll;
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
using namespace std;

class Triplet{
    public:
    int gcd, x, y;
};
int gcd(int a, int b){
    if(b==0)
        return a;

    return gcd(b, a%b);
}
Triplet extendedEuclid(int a, int b){
   if(b==0){
       Triplet ans;
       ans.x=1;
       ans.y=0;
       ans.gcd=a;
       return ans;
   }
   Triplet small_ans= extendedEuclid(b, a%b);
   Triplet ans;
   ans.x= small_ans.y;
   ans.y= small_ans.x - ((a/b)*small_ans.y);
   ans.gcd=small_ans.gcd;

   return ans;
}
//Let us assume inverse exists
int moduloInverse(int a, int m){
    Triplet ans=extendedEuclid(a, m);
    return (ans.x+m)%m;
}
int main(){
    cout<<moduloInverse(6, 7);
    //cout<<ans.x<<" "<<ans.y;

}