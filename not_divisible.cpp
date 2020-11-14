#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc170/tasks/abc170_d
using namespace std;
 
const int N = 1e6 + 1;
bool good[N];
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int, int> mm;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        ++mm[v[i]];
        if(mm[v[i]] > 1) good[v[i]] = true;
    }
    sort(v.begin(), v.end());
    if(v[0] == 1){
        if(good[1]) cout<<0<<'\n';
        else cout<<1<<'\n';
        return;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(!good[v[i]]) res++;
        int p = v[i];
        for(int j = 2 * p; j < N; j += p){
            good[j] = true;
        }
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}