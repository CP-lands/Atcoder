#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc168/tasks/abc168_d
using namespace std;
 
void Solve(){
 	int n, m;
 	cin>>n>>m;
 	vector<int> g[n + 1];
 	while(m--){
 		int u, v;
 		cin>>u>>v;
 		g[u].push_back(v);
 		g[v].push_back(u);
 	}
 	vector<int> trace(n + 1);
 	trace[1] = 0;
 	queue<int> q;
 	vector<int> vst(n + 1);
 	vst[1] = true;
 	q.push(1);
 	while(!q.empty()){
 		int current = q.front();
 		q.pop();
 		for(auto x: g[current]){
 			if(!vst[x]){
 				vst[x] = true;
 				q.push(x);
 				trace[x] = current;
 			}
 		}
 	}
 	bool good = true;
 	for(int i = 1; i <= n; i++){
 		if(!vst[i]) good = false;
 	}
 	if(good){
 		cout<<"Yes\n";
 		for(int i = 2; i <= n; i++) cout<<trace[i]<<'\n';
 	}
 	else cout<<"No\n";
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}