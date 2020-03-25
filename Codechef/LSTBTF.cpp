#include<iostream>
#include<cmath>
using namespace std;

int ar[1000001];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++)   ar[i] = 1;
        int sum = n;

        int index = n-1;
        while(sum<(n*81)){
            int x = (int)sqrt(sum);
            if((x*x)==sum) break;

            while(ar[index]==9)   index--;
            sum -= ar[index]*ar[index];
            ar[index]++;
            sum += ar[index]*ar[index];
            for(int i=index+1;i<n;i++){
                sum -= ar[i]*ar[i];
                ar[i] = ar[index];
                sum += ar[i]*ar[i];
            }
            index = n-1;
        }
        for(int i=0;i<n;i++)   printf("%d", ar[i]);
        printf("\n");
    }
}