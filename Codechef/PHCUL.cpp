#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x,y;
};
Point a[3][5001];
int limit[3];
double distance(Point p1, Point p2){
    double a= pow(p1.x - p2.x, 2);
    double b= pow(p1.y - p2.y, 2);
    return sqrt(a+b);
}
double f(int idx, int n, int m, int k, Point prev){
    if(__builtin_popcount(idx)==3)
        return 0;
    
    cout<<"H"<<" ";
    double ans=INT_MAX;
    for(int i=0;i<3;i++){
        if((idx&(1<<i))==0){
            for(int j=0;j<limit[i];j++){
                ans=min(ans, f((idx|(1<<i)), n, m, k, a[i][j])+distance(prev, a[i][j]));
            }
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        Point p;
        p.x=x, p.y=y;
        int n,m,k;
        cin>>n>>m>>k;
        limit[0]=n, limit[1]=m, limit[2]=k;
        for(int i=0;i<n;i++){
            cin>>a[0][i].x>>a[0][i].y;
        }
        for(int i=0;i<m;i++){
            cin>>a[1][i].x>>a[1][i].y;
        }
        for(int i=0;i<k;i++){
            cin>>a[2][i].x>>a[2][i].y;
        }
        cout<<setprecision(12)<< f(0, n, m, k, p)<<endl;
    }
}