//--------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  

//https://atcoder.jp/contests/keyence2021/tasks/keyence2021_b
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
#define bug cout<<"bug here\n"
typedef long long ll;
 
void Solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    int zeroes = 0;
    map<int, int> mm;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        if(v[i] == 0) zeroes++;
        ++mm[v[i]];
    }
    int s = min(zeroes, k);
    vector<int> g[s];
    for(int i = 0; i < s; i++){
        for(int j = 0; j < n; j++){
            if(mm[j] == 0) break;
            else{
                g[i].pb(j);
                mm[j]--;
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < s; i++){
        res += g[i].back() + 1;
    }
    cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}