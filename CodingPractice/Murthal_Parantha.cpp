#include<iostream>
using namespace std;

int main(){
    int p;
    cin>>p;
    int l;
    cin>>l;
    int rank[l];
    for(int i=0;i<l;i++){
        cin>> rank[i];
    }
    int ans;
    int start = 0;
    int end = 1e9;
    while(start<=end){
        int time = (start+end)>>1;
        int total = 0;
        for(int i=0;i<l;i++){
            int parathas = 0;
            while((rank[i]*parathas*(parathas+1))<=(2*time))    parathas++;
            parathas--;
            total += parathas;
        }
        if(total>=p)    {
            end = time-1;
            ans = time;
            }
        else start = time+1;
    }
    cout << ans << endl;

}