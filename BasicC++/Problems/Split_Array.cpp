#include<bits/stdc++.h>
#define REP(b) for(int i=0;i<b;i++)
typedef long long ll;
using namespace std;

int NumberofWays(int *a, int n, int pos, string s1, string s2, ll sum1, ll sum2){
    if(pos==n){
        if(sum1==sum2){
            cout<<s1<<"and "<<s2<<"\n";
            return 1;
        }
        return 0;
    }
    int ans1= NumberofWays(a, n, pos+1, s1+to_string(a[pos])+" ", s2, sum1+a[pos], sum2);
    int ans2= NumberofWays(a, n, pos+1, s1, s2+to_string(a[pos])+" ", sum1, sum2+a[pos]);

    return ans1+ans2;
}
int main(){
    int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

    cout<<NumberofWays(a, n, 0, "", "", 0, 0);
}