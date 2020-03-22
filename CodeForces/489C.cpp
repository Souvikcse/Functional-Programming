#include<iostream>
#include<cstring>
using namespace std;

bool possible(int n, int sum){
    return (sum>=0 && sum<=(9*n));
}
void find(int n, int S){
    bool ans = false;
    string num = "";
    int sum = S;

    for(int i=1;i<=n;i++){
        int d = i!=1? 0:1;
        for(;d<10;d++){
            if(possible(n-i, sum-d)){
                num += char('0'+d);
                sum-=d;
                break;
            }
        }
    }
    if(num.length()==n)  ans = true;
    string small = num;
    num = "";
    sum = S;
    for(int i=1;i<=n;i++){
        int lim = i!=1? 0:1;
        for(int d=9;d>=lim;d--){
            if(possible(n-i, sum-d)){
                num += char('0'+d);
                sum-=d;
                break;
            }
        }
    }
    if(n==1 && S<=9){
        ans = true;
        small = num = char('0'+S);
    }
    if(!ans)   cout<<"-1 -1";
    else
        cout<<small<< " "<< num;
}
int main(){
    int len, sum;
    cin>>len>>sum;

    find(len, sum);
    cout<<endl;
}