#include<iostream>
using namespace std;

int main(){
    int a=5;
    int *p;
    p=&a;

    cout<<a<<"\n";
    cout<<*p<<"\n";
    cout<<p<<"\n";
    cout<<&a<<"\n";
    cout<<*(++p)<<"\n";
    cout<<a;
}