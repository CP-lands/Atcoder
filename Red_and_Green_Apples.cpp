#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc160/tasks/abc160_e
using namespace std;
 
void Solve(){
    int x, y, a, b, c;
    cin>>x>>y>>a>>b>>c;
    vector<int> aa(a), bb(b), cc(c);
    for(int i = 0; i < a; i++) cin>>aa[i];
    for(int i = 0; i < b; i++) cin>>bb[i];
    for(int i = 0; i < c; i++) cin>>cc[i];
    sort(aa.rbegin(), aa.rend());
    sort(bb.rbegin(), bb.rend());
    sort(cc.rbegin(), cc.rend());
    long long res = 0;
    int ia = 0, ib = 0;
    while(ia < x){
        res += aa[ia];
        ia++;
    }
    ia--;
    while(ib < y){
        res += bb[ib];
        ib++;
    }
    ib--;
    int i = 0;
    while(i < c){
        if((ia >= 0 && aa[ia] < cc[i])){
            if(ib >= 0 && bb[ib] < aa[ia]){
                res -= bb[ib];
                res += cc[i];
                ib--;
            }
            else{
                res -= aa[ia];
                res += cc[i];
                ia--;
            }
        }
        else if(ib >= 0 && bb[ib] < cc[i]){
            res -= bb[ib];
            res += cc[i];
            ib--;
        }
        i++;
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
        Solve();
    }
}