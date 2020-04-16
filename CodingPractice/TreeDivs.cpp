#include<bits/stdc++.h>
typedef long long int ll;
#define N 1000001
using namespace std;

int coun[N] = {0};
//bool visited[N];

void sieve(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i)
            coun[j] += 1;
    }
}
int dp1[N];
int dp2[N];
void dfs(int node, vector<int> *v, int par){
    int sum1 =0, sum2 = 0;

    for(int x:v[node]){
        if(x==par)   continue;
        dfs(x, v, node);
        sum1 += dp2[x];
        sum2 += max(dp1[x], dp2[x]);
    }
    dp1[node] = sum1+coun[node];
    dp2[node] = sum2;
}
int main()
{
    sieve();
    int n;
    cin>>n;
    vector<int> v[n+1];
    int x, y;
    for(int i=0;i<(n-1);i++){
     	cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, v, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
}