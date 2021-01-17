//--------my brain isn't at home right now------------------
#include<bits/stdc++.h> 

//https://atcoder.jp/contests/abc187/tasks/abc187_d 
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n;
    cin>>n;
    vector<tuple<ll, int, int>> v;
    ll a = 0, b = 0;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin>>x>>y;
        v.emplace_back(2 * x + y, x, y);
        b += x;
    }
    sort(v.rbegin(), v.rend());
    int res = 0;
    for(auto &x: v){
        if(a > b) break;
        res++;
        a += get<1>(x) + get<2>(x);
        b -= get<1>(x);
    }
 
    cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}