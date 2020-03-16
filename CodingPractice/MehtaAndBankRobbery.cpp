#include<iostream>
#include<algorithm>
#include<vector>
typedef long long int ll;
using namespace std;

int n, w;
int main(){
    cin>>n>>w;

    pair<int,int> *item = new pair<int, int>[n];
    for(int i=0;i<n;i++){
        cin>>item[i].first>>item[i].second;
    }
    sort(item, item+n);
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(w+1, vector<int>(2)));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j][0] = dp[i-1][j][0];

            if(j>=item[i-1].second){
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-item[i-1].second][0]+item[i-1].first);
            }
        }
    }
    int primes[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for(int pr=1;pr<=10;pr++){
        int p = pr%2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
            dp[i][j][p] = dp[i-1][j][p];

            if(j>=item[i-1].second){
                dp[i][j][p] = max(dp[i][j][p], max(dp[i-1][j-item[i-1].second][p]+item[i-1].first, dp[i-1][j-item[i-1].second][p^1]+item[i-1].first*primes[pr]));
            }
        }
    }
    }
    cout<<dp[n][w][0] <<endl;
}