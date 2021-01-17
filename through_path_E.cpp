//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
//https://atcoder.jp/contests/abc187/tasks/abc187_e
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
const int N = 2e5 + 1;
vector<int> g[N];
vector<pair<int, int>> v(N);
ll dp[N];
vector<int> parent(N);
 
void dfs1(int u, int t = -1){
    for(auto x: g[u]){
        if(x == t) continue;
        parent[x] = u;
        dfs1(x, u);
    }
}
void dfs(int u, int k = -1){
    for(auto x: g[u]){
        if(x == k) continue;
        dp[x] += dp[u];
        dfs(x, u);
    }
} 
void Solve(){
    int n;
    cin>>n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin>>a>>b;
        v[i] = {a, b};
        g[a].pb(b); 
        g[b].pb(a);
    }
    for(int i = 0; i < N; i++){
        dp[i] = 0;
        parent[i] = 0;
    }
    dfs1(1);
    int q;
    cin>>q;
    while(q--){
        int t, e, x;
        cin>>t>>e>>x;
        int a = v[e].fi;
        int b = v[e].se;
        if(t == 1){
            if(parent[b] == a){
                dp[1] += x;
                dp[b] -= x;
            }
            else{
                dp[a] += x;
            }
        }
        else{
            if(parent[a] == b){
                dp[1] += x;
                dp[a] -= x;
            }
            else{
                dp[b] += x;
            }
        }
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout<<dp[i]<<nl;
    }
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}