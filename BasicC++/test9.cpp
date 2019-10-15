#include<iostream>
#include<cstring>
using namespace std;
void print(int i, int n, int open, int close, char out[]){
	if(i==2*n){
        out[i]='\0';
		cout<<out<<" "<<strlen(out)<<"\n";
        return;
	}
    if(open<n){
        out[i]='(';
        print(i+1, n, open+1, close, out);
    }
    if(close<open){
        out[i]=')';
        print(i+1, n, open, close+1, out);
    }
}
int main() {
    char output[100];
	int n;
	cin>>n;
	print(0, n, 0, 0, output);
}