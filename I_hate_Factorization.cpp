#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc166/tasks/abc166_d
using namespace std;
 
long long poww(int t){
    long long res = t;
    for(int i = 0; i < 4; i++)
        res *= t;
    return res;
}
 
void Solve(){
    int n;
    cin>>n;
    long long a;
    int i = 0;
    while(true){
        a = poww(i);
        long long rest = a - n;
        if(rest <= 0){
            for(int j = 0; j >= -200; j--){
                long long k = poww(j);
                if(k == rest){
                    cout<<i<<" "<<j<<'\n';
                    return;
                }
            }
        }
        else{
            for(int j = 0; j <= 200; j++){
                long long k = poww(j);
                if(k == rest){
                    cout<<i<<" "<<j<<'\n';
                    return;
                }
            }
        }
        i++;
    }
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}