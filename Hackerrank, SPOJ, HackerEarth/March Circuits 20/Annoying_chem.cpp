#include<iostream>
typedef long long int ll;
#define N 100000000
using namespace std;

int main(){
     int x, y, p, q;
    scanf("%d%d%d%d", &x, &y, &p, &q); 

    ll b1, b2, b3;
    for(b3 = 1; b3 <= N; b3++) {
        if(!((p * b3) % x) && !((q * b3) % y)) {
            b1 = (p * b3) / x;
            b2 = (q * b3) / y;
            break;
        }
    }
    printf("%lld %lld %lld\n", b1, b2, b3);
}