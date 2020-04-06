#include <iostream>
typedef long long int ll;
#include <cmath>
#define N 1000001
using namespace std;

int a[N];
int ar[N];
int main(){
    int t;
    scanf("%d", &t);
    int n;
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
            ar[i] = a[i];
        }

        int start = 0, end = 0;
        ll prod = 1;
        ll l;
        ll ans = 0;
        while(end<n){
            if(a[end]&1){
                while(end<n && a[end]&1){
                    end++;
                }
                l = end-start;
                ans += (l*(l+1))/2;
                start = end+1;
            }
            else{
                start=end+1;
            }
            end++;
         }
        start = 0, end = 0;
        int count2 = 0;
        for(int i=0;i<n;i++){
            if((a[i]%4)==0){
                a[i] = 4;
                ar[i] = 4;
            }
        }
        while(end<n && start<n){
            while((a[end]%2)==0){
               // cout<<"he\n";
                count2++;
                a[end]/=2;
            }
            if(count2>=2){
                ans += n-end;
                while((ar[start]%2)==0){
                    //cout<<a[start]<<"\n";
                count2--;
                ar[start]/=2;
            }
                start++;
            }
            else{
                end++;
            }
           // cout<<ans<<"\n";
        }
        printf("%lld\n", ans);
    }
}