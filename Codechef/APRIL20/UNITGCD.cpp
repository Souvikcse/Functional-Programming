#include <iostream>
#include<cmath>
#include<unordered_set>
#define N 1000001
using namespace std;

bool is_prime[N];
void sieve(){
    is_prime[1] = true;
    for(int i=2;i<1002;i++){
        if(!is_prime[i]){
            for(int j=2*i;j<N;j+=i)
                is_prime[j] = true;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        
    }
}