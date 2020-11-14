#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc162/tasks/abc162_d
using namespace std;
 
void Solve(){
    int n;
    string s;
    cin>>n>>s;
    if(n < 3){
        cout<<0<<'\n';
        return;
    }
    map<int, char> mm;
    vector<int> r, g, b;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == 'R') r.push_back(i);
        else if(s[i - 1] == 'G') g.push_back(i);
        else b.push_back(i);
        mm[i] = s[i - 1];
    }
    long long res = 0;
    //rgb
    for(auto x: r){
        int a = upper_bound(g.begin(), g.end(), x) - g.begin();
        if(a >= g.size()) continue;
        for(int i = a; i < g.size(); i++){
            int c = upper_bound(b.begin(), b.end(), g[i]) - b.begin();
            if(c >= b.size()) continue;
            res += b.size() - c;
            int k = g[i] - x;
            k = g[i] + k;
            if(mm.count(k)){
                if(mm[k] == 'B') res--;
            }
        }
    }
    //rbg
    for(auto x: r){
        int a = upper_bound(b.begin(), b.end(), x) - b.begin();
        if(a >= b.size()) continue;
        for(int i = a; i < b.size(); i++){
            int c = upper_bound(g.begin(), g.end(), b[i]) - g.begin();
            if(c >= g.size()) continue;
            res += g.size() - c;
            int k = b[i] - x;
            k = b[i] + k;
            if(mm[k] == 'G') res--;
        }
    }
    //grb
    for(auto x: g){
        int a = upper_bound(r.begin(), r.end(), x) - r.begin();
        if(a >= r.size()) continue;
        for(int i = a; i < r.size(); i++){
            int c = upper_bound(b.begin(), b.end(), r[i]) - b.begin();
            if(c >= b.size()) continue;
            res += b.size() - c;
            int k = r[i] - x;
            k = r[i] + k;
            if(mm[k] == 'B') res--;
        }
    }
    //gbr
    for(auto x: g){
        int a = upper_bound(b.begin(), b.end(), x) - b.begin();
        if(a >= b.size()) continue;
        for(int i = a; i < b.size(); i++){
            int c = upper_bound(r.begin(), r.end(), b[i]) - r.begin();
            if(c >= r.size()) continue;
            res += r.size() - c;
            int k = b[i] - x;
            k = b[i] + k;
            if(mm[k] == 'R') res--;
        }
    }
    //brg
    for(auto x: b){
        int a = upper_bound(r.begin(), r.end(), x) - r.begin();
        if(a >= r.size()) continue;
        for(int i = a; i < r.size(); i++){
            int c = upper_bound(g.begin(), g.end(), r[i]) - g.begin();
            if(c >= g.size()) continue;
            res += g.size() - c;
            int k = r[i] - x;
            k = r[i] + k;
            if(mm[k] == 'G') res--;
        }
    }
    //bgr
    for(auto x: b){
        int a = upper_bound(g.begin(), g.end(), x) - g.begin();
        if(a >= g.size()) continue;
        for(int i = a; i < g.size(); i++){
            int c = upper_bound(r.begin(), r.end(), g[i]) - r.begin();
            if(c >= r.size()) continue;
            res += r.size() - c;
            int k = g[i] - x;
            k = g[i] + k;
            if(mm[k] == 'R') res--;
        }
    }
 
    cout<<res<<'\n';
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int test_case = 1;
    //cin>>test_case;
    while(test_case--){
        Solve();
    }
}