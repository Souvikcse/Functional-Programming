#include <iostream>
using namespace std;

int a[101];
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        int last = -1;
        bool ans = true;
        for(int i=0;i<n;i++){
            if(a[i] ){
                if(last!=-1)     ans = (i-last)>=6? true:false;
                last = i;
                if(!ans)   break;
            }
        }
        ans == true? cout<<"YES":cout<<"NO";
        cout<<"\n";
    }
}
