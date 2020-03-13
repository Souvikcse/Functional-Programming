#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int price[10002];
bool search(int x, int n){
    int start=0, end=n-1;
    while (start<=end){
        int mid=(start+end)>>1;
        if(price[mid]==x)
            return true;
        else if(price[mid]>x)
            end=mid-1;
        else
            start=mid+1;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    vector<string> vs;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>price[i];
        }
        int sum;
        cin>>sum;
        sort(price, price+n);
        int small=0, large=0, diff=INT32_MAX;
        for(int i=0;i<n;i++){
            int ns=sum-price[i];
            if(search(ns, n)){
                int sm=min(price[i], ns);
                int lg=max(price[i], ns);
                if((lg-sm)<diff){
                    diff= lg-sm;
                    small=sm;
                    large=lg;
                }
            }
        }
        string s="Deepak should buy roses whose prices are "+to_string(small)+" and "+to_string(large)+".";
        vs.push_back(s);
    }
    for(string x:vs){
        cout<<x<<endl;
    }
}