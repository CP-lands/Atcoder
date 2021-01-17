//--------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://atcoder.jp/contests/keyence2021/tasks/keyence2021_a
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
#define bug cout<<"bug here\n"
typedef long long ll;
 
void Solve(){
    int n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < n; i++)
        cin>>b[i];
    vector<ll> c(n);
    vector<ll> dp1(n);
    for(int i = 0; i < n; i++){
        dp1[i] = a[i];
        if(i > 0){
            dp1[i] = max(dp1[i], dp1[i - 1]);
        }
    }
    ll maxx = 0;
    for(int i = 0; i < n; i++){
        c[i] = max(maxx, a[i] * b[i]);
        c[i] = max(c[i], dp1[i] * b[i]);
        maxx = max(maxx, c[i]);
    }
 
    for(auto x: c) cout<<x<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}