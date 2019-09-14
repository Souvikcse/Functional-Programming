#include<iostream>
using namespace std;

int main(){
    int a=5;
    int *p;
    p=&a;

    cout<<sizeof(int*)<<"\n";
    cout<<a<<"\n";
    cout<<*p<<"\n";
    cout<<p<<"\n";
    cout<<&a<<"\n";
    cout<<*(++p)<<"\n";
    cout<<a<<endl;
}