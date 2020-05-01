#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    int a[n], b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<m;i++)    cin>>b[i];

    sort(a, a+n);
    sort(b, b+m);
    if(b[m-1]<a[n-1]){
        cout << "-1\n";
        return 0;
    }
    int ans = 1, last = 0;
    int j = 0;
    for(int i=0;i<n;i++){
        if(j==m){
            j = last;
            ans += 2;
        }
        if(b[j]<a[i]){
            last = lower_bound(b, b+m, a[i]) - b;
            j = last;
        }
        j++;
    }
    cout << ans << endl;
}