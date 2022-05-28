/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sat May 28 21:19:33 IST 2022
	Link to problem / contest : https://atcoder.jp/contests/dp/tasks/dp_g
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

#define PB emplace_back
#define PBK pop_back
#define PBC push_back
#define MP make_pair
#define f(n) for(int i=0;i<n;i++)
#define fr(itr, n) for(int itr=0;itr<n;itr++)
#define F(s,e) for(int i=s;i<=e;i++)
#define c(arr,x) count(arr.begin() , arr.end() , x)
#define _max(arr) * max_element(arr.begin() , arr.end())
#define _min(arr) * min_element(arr.begin() , arr.end())
#define _max_pos(arr) max_element(arr.begin() , arr.end()) - arr.begin()
#define _min_pos(arr) min_element(arr.begin() , arr.end()) - arr.begin()
#define what_is(x) cout << #x << ": " << x << endl ;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}
// requires c++17
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = 10e9+7 ;


vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}

void addEdge(int u , int v){ adj[u].PBC(v); }

int dp[100001] ;

int dfs(int s){
	if(dp[s] != -1) return dp[s] ;
	int res = INT_MIN ;
	for(auto x : adj[s]) res = max(res , 1 + dfs(x)) ;
	return dp[s] = max(res , 0) ;
}

void solve(){
	// to execute for each test case
	memset(dp , -1 , sizeof(dp)) ;
	int n , m ;
	cin >> n >> m ;
	init(n) ;
	f(m){
		int x , y ;
		cin >> x >> y ;
		addEdge(x - 1,y - 1) ;
	}

	int res = 0 ;

	for(int i = 0 ; i < n ; i++){
		res = max(res , dfs(i)) ;
	}

	cout << res << endl ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	int t = 1;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

