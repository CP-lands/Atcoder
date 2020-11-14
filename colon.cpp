#include<bits/stdc++.h>
 
//https://atcoder.jp/contests/abc168/tasks/abc168_c
using namespace std;
 
#define pi  3.14159265358979323846
 
double abss(double a){
	if(a >= 0) return a;
	else return -a;
}
double minn(double a, double b){
	if(a <= b) return a;
	else return b;
}
void Solve(){
 	double a, b, h, m;
 	cin>>a>>b>>h>>m;
 	if(a > b){
 		double c = a;
 		a = b;
 		b = c;
 	}
 	h += (m / 60);
 	h *= 5;
 	double d = abss(h - m);
 	d = minn(d, 60 - d);
 	//cout<<d<<endl;
 	double res = 0;
 	double degree = d * 6;
 	//cout<<degree<<endl;
 	double x = cos(degree * pi / 180) * a;
 	double y = b - x;
 	double z = sin(degree * pi / 180) * a;
 	res = z * z + y * y;
 	res = sqrt(res);
 	//cout<<x<<" "<<y<<" "<<z<<endl;
 	cout<<fixed<<setprecision(15)<<res<<'\n';
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}