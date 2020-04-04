#include <iostream>
#include<cmath>
#define N 1000001
using namespace std;

int count[N] = {0};
int p_factors[N] = {0};
int fastPower(int a, int b){
    int res=1;
    while (b)
    {
      if(b&1)
        res*=a;
    a*=a;
    b>>=1;
    //cout<<res<<" "<<a<<endl;
    }
    return res;
}
pair<int, int> primeFactors(int n)  
{  
    int count = 0, dist_count = 0;  
    while (n % 2 == 0)  {  
        count++;
        dist_count = 1;
        n = n/2;  
    }  
  
    bool flag;
    for (int i = 3; i <= sqrt(n); i = i + 2)  {   
        flag = true;
        while (n % i == 0)  
        {  
            if (flag)
            {
                dist_count++;
                flag = false;
            }
            count++;  
            n = n/i;  
        }  
    }  

    if (n > 2)  
    {
        count++;
        dist_count++;
    }

    return make_pair(count, dist_count);  
} 
int main() {
    int t;
    cin>>t;
    //sieve();
    while(t--){
        int x, k;
        cin>>x>>k;

        if (k == 1 && x > 1){
            cout << 1 << "\n";
            continue;
        }

        if(x<=k || k>=30 || fastPower(2, k)>x){
            cout<<"0"<<"\n";
            continue;
        }

        std::pair<int, int> ans = primeFactors(x);

        if (ans.first < k)     cout << 0 << "\n";
        else                   cout << 1 << "\n";

    }
}