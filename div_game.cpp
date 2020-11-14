#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc169/tasks/abc169_d
using namespace std;
 
bool isPrime(long long n){
	if(n < 2) return false;
	for(int i = 2; (long long)i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}
void Solve(){
	long long n;
	cin>>n;
	if(isPrime(n)){
		cout<<1<<'\n';
		return;
	}
	int res = 0;
	vector<long long> prime;
	for(int i = 2; i < 1e6; i++){
		if(isPrime(i)){
			prime.push_back(i);
		}
	}
	for(auto x: prime){
		if(n < x) break;
		int l = 0;
		while(n % x == 0){
			n /= x;
			l++;
		}
		for(int k = 1; k * (k + 1) / 2 <= l; k++){
			//cout<<k<<" "<<res<<endl;
			res++;
		}
		//cout<<res<<endl;
		//cout<<n<<" "<<l<<" "<<res<<endl;
	}
	if(isPrime(n)) res++;
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