#include<bits/stdc++.h>
typedef long double ld;
using namespace std;

vector<pair<int, int>> coordinates;
vector<int> ingredients;
ld dist[37][37];
ld dp[37][1<<13];
int n, k;

ld euclideandistance(pair<int, int> p1, pair<int, int> p2){
    int dx= p1.first - p2.first;
    int dy= p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}
ld shoptrip(int pos, int mask){
    if(pos == 0 && mask == ((1<<k)-1))
        return 0;

    if(dp[pos][mask]!=-1)
        return dp[pos][mask];

    dp[pos][mask]= INT_MAX;
    for(int i=0;i<=n;i++){
        //if(i==pos)  continue;

        if((mask|ingredients[i])!=mask || i==0){
            dp[pos][mask]= min(dp[pos][mask], dist[pos][i]+ shoptrip(i, mask|ingredients[i]));
        }
    }
    return dp[pos][mask];
}
int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>k;

        coordinates.push_back(make_pair(0, 0));
        ingredients.push_back(0);

        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            coordinates.push_back(make_pair(x, y));
        }
        int possible=0;
        for(int i=0;i<n;i++){
            cin>>s;
            reverse(s.begin(), s.end());

            int tmp_mask=0;
            for(int j=0;j<k;j++)
                tmp_mask|= ((1<<j)*(s[j]-'0'));

            possible|= tmp_mask;
            ingredients.push_back(tmp_mask);
        }
        int ALL= (1<<k)-1;
        if(possible!=ALL){
            cout<<"-1"<<"\n";
            continue;
        }
        // Calculating the euclidean distance between every points
        memset(dist,0,sizeof(dist));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dist[i][j] = euclideandistance(coordinates[i], coordinates[j]);
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<(1<<k);j++){
                dp[i][j]=-1;
            }
        }
        ld ans= shoptrip(0, 0);
        cout<<fixed<<setprecision(11)<<ans<<"\n";
        coordinates.clear();
        ingredients.clear();
    }
}