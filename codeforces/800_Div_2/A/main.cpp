/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Thu Jun 16 19:57:26 IST 2022
	Link to problem / contest : 
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

#define REP(i,s,e) for(int i=s;i<=e;i++)
#define EB emplace_back
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i=0;i<n;i++)
#define fr(itr, n) for(int itr=0;itr<n;itr++)
#define F(s,e) for(int i=s;i<=e;i++)
#define c(arr,x) count(arr.begin() , arr.end() , x)
#define _max(arr) * max_element(arr.begin() , arr.end())
#define _min(arr) * min_element(arr.begin() , arr.end())
#define _max_pos(arr) max_element(arr.begin() , arr.end()) - arr.begin()
#define _min_pos(arr) min_element(arr.begin() , arr.end()) - arr.begin()
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = pow(10,9)+7 ;
// graphs
vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}
// count set bits in a given number
template <typename T>
int cnt_set_bits(T n){int res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------------------------------------------------------------------------------

void solve(){
	// to execute for each test case
	int a , b ;
	cin >> a >> b ;
	if(a==(b+1)){
		for(int i=0;i<b;i++) cout<<"01";
		cout<<"0";
	}
	else if(b==(a+1)){
		for(int i=0;i<a;i++) cout<<"10";
		cout<<1;	
	}
	else if(a==b){
		for(int i=0;i<a;i++) cout<<"10";
	}
	else if(a>b){
		int q=a/(b+1) ;
		int r=a%(b+1) ;
		int m=b ;
		for(int i=0;i<m+1;i++){
			if(i<r) for(int j=0;j<q+1;j++)cout<<"0";
			else for(int j=0;j<q;j++)cout<<"0";
			if(b)cout<<"1";
			--b; 
		}
	}
	else{
		int q=b/(a+1) ;
		int r=b%(a+1) ;
		int m=a;
		for(int i=0;i<m+1;i++){
			int ub = 0 ;
			if(i<r) ub=q+1 ;
			else ub=q ;
			for(int j=0;j<ub;j++)cout<<"1" ;
			if(a)cout<<"0";
			--a; 
		}
	}
	cout << endl ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
    cout << std::fixed;
    cout << std::setprecision(12);
	int t ;
	cin >> t ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

