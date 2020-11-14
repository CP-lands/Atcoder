#include<bits/stdc++.h>

//https://atcoder.jp/contests/abc159/tasks/abc159_d
using namespace std;

long long comb(int n, int k)
{
    long long res = 1;
    for(int i = 1; i <= k; i++){
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int, int> mm;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        ++mm[v[i]];
    }
    long long sum = 0;
    for(auto x: mm){
        if(x.second > 1){
            sum += comb(x.second, 2);
        }
    }
    for(int i = 0; i < n; i++){
        if(mm[v[i]] < 2) cout<<sum<<'\n';
        else{
            long long tmp = comb(mm[v[i]], 2);
            tmp = sum - tmp;
            tmp += comb(mm[v[i]] - 1, 2);
            cout<<tmp<<'\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}