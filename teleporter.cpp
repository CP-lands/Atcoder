#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc167/tasks/abc167_d
using namespace std;
 
void Solve(){
	int n;
	long long k;
	cin>>n>>k;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++)
		cin>>v[i];
	vector<bool> vst(n + 1);
	vector<int> res;
	int i = 1;
	res.push_back(i);
	int c = 1;
	while(!vst[i]){
		vst[i] = true;
		i = v[i];
		if(vst[i]){
			c = i;
			break;
		}
		res.push_back(i);
	}
	int num = 0;
	for(int i = 0; i < res.size(); i++){
		if(res[i] == c){
			num = i;
			c = res.size() - i;
			break;
		}
	}
	
	if(k < res.size()){
		cout<<res[k]<<'\n';
		return;
	}
	k -= (res.size() - c);
	k = k % c;
	cout<<res[num + k]<<'\n';
	return;
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}