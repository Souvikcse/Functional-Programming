#include<iostream>
#include<queue>
#include<cstdlib>
#define Size(a) (int)sizeof(a)/sizeof(a[0])
#define REP(a, b, c) for(int i=a;i<b;i=i+c)
typedef long long ll;
using namespace std;

class Hostel{
    public:
    int x,y;
    Hostel(int x, int y){
        this->x=x;
        this->y=y;
    }
    ll dist(){
        int xd=abs(x);
        int yd=abs(y);
        return xd*xd + yd*yd;
    }
};
class HostelComparision{
    public:
    //Method to overload () operator
    bool operator () (Hostel a, Hostel b){
        return a.dist()<b.dist();
    }
};
int main(){
    int Q, K;
    cin>>Q>>K;
    priority_queue<Hostel, vector<Hostel>, HostelComparision> pq;
    REP(0, Q, 1){
        int type;
        cin>> type;
        if (type == 1)
        {
            int x, y;
            cin>>x>>y;
            Hostel ob(x, y);
            if(pq.size() == K){
                Hostel p=pq.top();
                if(ob.dist() < p.dist()){
                    pq.pop();
                    pq.push(ob);
                }
            }
            else{
                pq.push(ob);
            }
        }
        else{
            Hostel h=pq.top();
            cout<<h.dist()<<"\n";
        }
    }
}