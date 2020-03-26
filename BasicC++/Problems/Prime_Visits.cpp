#include<iostream>
#include<cstring>
using namespace std;

int count[1000005] = {0};
void sieve(){
    bool is_prime[1000005];
    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=1002;i++){
        if(is_prime[i]){
            for(int j=2*i;j<1000005;j+=i)
                is_prime[j] = false;
        }
    }
    for(int i=1;i<1000005;i++){
        count[i] = count[i-1];
        if(is_prime[i])   count[i]++; 
    }
}
int main(){
    sieve();
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;

        int ans = count[b] - count[a-1];
        cout<< ans << endl;
    }
}