#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int all[1000001]={0};

int main()

{

    all[1]=1;all[2]=0;

    for(int i=2;i<=1000;i++){

        if(all[i])continue;

        for(int j=2*i;j<=1000000;j+=i){

            all[j]=1;

        }

    }


    int t;

    cin>>t;

    for(int i=0;i<t;i++){

        long long lng;

        cin>>lng;

        long long sqr=sqrt(lng);

            cout<<((sqr*sqr==lng && !all[sqr])?"YES\n":"NO\n");

    }

    return 0;
}