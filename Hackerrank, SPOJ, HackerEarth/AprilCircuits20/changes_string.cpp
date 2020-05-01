#include<iostream>
#define N 1000001
using namespace std;

int co_A[N], co_B[N];
int ans[N];
int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
        int n;
        cin>>n;
        cin>>s;
        co_A[0] = co_B[0] = 0;
        s[0]=='A'? co_A[0]=1:co_B[0]=1;

        for(int i=1;i<n;i++){
            co_A[i] = co_A[i-1];
            co_B[i] = co_B[i-1];
            s[i]=='A'? co_A[i]+=1:co_B[i]+=1;
        }
        int result = INT32_MAX;
        ans[0] = co_A[n-1];
        result = min(result, ans[0]);
        for(int i=1;i<n;i++){
            ans[i] = co_B[i-1]+co_A[n-1]-co_A[i-1];
            result = min(ans[i], result);
        }
        result = min(result, co_B[n-1]);
        cout << result << "\n";
    }
}