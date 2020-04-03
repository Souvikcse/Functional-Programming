#include <iostream>
#include<cmath>
#define N 1000001
using namespace std;

int count[N] = {0};
int p_factors[N] = {0};
void sieve(){
    
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            count[j]+=1;
        }
    } 
    for (int p = 2; p < N; p++)  
        if (p_factors[p] == 0)  
            for (int i = p; i<N; i += p)  
                p_factors[i]++;

}
// bool check(int num, int divs, int pfs){
//     int d = 1;
//     int ans = 0;
//     int n = num;
//     int sqroot = sqrt(num);
//     for(int i=2;i<=sqroot;i++){
//         if(num%i==0){
//             ans += 1;
//             int c=0;
//             while((num%i)==0){
//                 c++;
//                 num/=i;
//             }
//             d*=(c+1);
//         }
//     }
//     if(num!=1){
//         d*=2;
//         ans+=1;
//     }
//     //cout << n <<"-> " << d << " " << ans << "\n";
//     return (d==divs && ans==pfs);
// }
int main() {
    int t;
    cin>>t;
    sieve();
    while(t--){
        int x, k;
        cin>>x>>k;

        int i;
        bool ans = false;
        // for(i=1;i<=1000000;i++){
        //     //cout << i <<"-> " << count[i] << " " << p_factors[i] << "\n";
        //     if(count[i]==x && p_factors[i]==k){
        //         ans = true;
        //         break;
        //     }
        // }
        if(x==2 && k!=1){
            ans = false;
        }
        ans == true? cout<<"1":cout<<"0";
        cout<<"\n";
    }
}