#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc161/tasks/abc161_d
using namespace std;
 
void Solve(){
    int k;
    cin>>k;
    if(k < 10){
        cout<<k<<endl;
        return;
    }
    queue<long long> q;
    int res = 9;
    for(long long i = 1; i < 10; i++)
        q.push(i);
    while(true){
        long long current = q.front();
        q.pop();
        long long a = current * 10 + current % 10 - 1;
        long long b = current * 10 + current % 10;
        long long c = current * 10 + current % 10 + 1;
        if(current % 10 > 0){
            res++;
            q.push(a);
            if(res == k){
                cout<<a<<'\n';
                return;
            }
        }
        res++;
        if(res == k){
            cout<<b<<'\n';
            return;
        }
        q.push(b);
        if(current % 10 < 9){
            res++;
            q.push(c);
            if(res == k){
                cout<<c<<'\n';
                return;
            }
        }
    }
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    while(q--){
        Solve();
    }
}