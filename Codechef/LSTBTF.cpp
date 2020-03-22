#include <iostream>
#include<unordered_set>
#include<vector>
using namespace std;

unordered_set<int> uset;
vector<int> v;
int sum;
bool can_find(int i, int n){
    if(i==n){
        return (uset.find(sum)!=uset.end());
    }
    for(int k=1;k<10;k++){
        v[i] = k;
        sum += k*k;
        if(can_find(i+1, n))
            return true;
        sum -= k*k;
    }
    return false;
} 
int main()
{
    for(int i=1;i<=9000;i++){
        uset.insert(i*i);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        v.resize(n);
        sum = 0;
        if(!can_find(0, n))
            cout<<"-1";
        else{
            for(int x:v)
                cout<<x;
        }

        cout<<endl;
    }
}
