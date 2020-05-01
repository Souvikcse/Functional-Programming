/*
// Sample code to perform I/O:
*/
#include <iostream>
using namespace std;

void left_shift(unsigned short int& n){
	if((1<<15)&n){
		n<<=1;
		n|=1;
	}
	else n<<=1;
}
void right_shift(unsigned short int& n){
	if(n&(1<<0)){
		n>>=1;
		n|= 1<<15;
	}
	else   n>>=1;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		unsigned short int n;
		int m;
		char c;
		cin>>n>>m>>c;

		if(c=='L'){
		for(int i=0;i<m;i++)        left_shift(n);
		}
		else{
			for(int i=0;i<m;i++)     right_shift(n);
		}

		cout << n << "\n";
	}
}
