#include<iostream>
using namespace std;

string factorial(int n){
    int ar[1000];
    int j=0;
    int x=n;
    while (n){
        ar[j]=n%10;
        j++;
        n/=10;
    }
    int size=j;
    for(int num=x-1;num>=1;num--){
    int carry=0;
    for(int i=0;i<size;i++){
        int prod=(num*ar[i])+carry;
        ar[i]=prod%10;
        carry=prod/10;
    }
    while(carry){
        ar[size]=carry%10;
        carry/=10;
        size++;
    }
    }
    string ans="";
    for(int i=size-1;i>=0;i--){
        ans.append(to_string(ar[i]));
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
}