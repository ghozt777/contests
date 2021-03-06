/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun May 29 02:45:11 IST 2022
	Link to problem / contest : https://atcoder.jp/contests/dp/tasks/dp_i
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
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}

vector<double> p ;

vector<vector<double>> memo(3000 , vector<double>(3000 , -1)) ;

double bf(int n , int k){ // memoized
	if(n == 0) return k == 0 ? 1.00 : 0.00 ;
	if(memo[n][k] != -1) return memo[n][k] ;
	return memo[n][k] = p[n - 1] * bf(n - 1 , k - 1) + (1.00 - p[n - 1]) * bf(n - 1 , k);
}

double bruteforce(){
	const int n = p.size() ;
	const int k = n / 2 + 1 ;
	double res = 0.00 ;
	for(int i = k ; i<= n ; i++) res += bf(n, i) ; 
	return res ; 
}

double _dp(){
	const int n = p.size() ;
	vector<vector<double>> dp(n + 1 , vector<double>(n + 1 , 0.000)) ;
	dp[0][0] = 1.000 ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= i ; j++) dp[i][j] = p[i - 1] * dp[i - 1][j - 1] + (1 - p[i - 1]) * dp[i - 1][j] ;
	}
	const int k = p.size() / 2 + 1 ;
	double res = 0.00 ;
	for(int i = k ; i <= n ; i++) res += dp[n][i] ;
	return res ;
}


void solve(){
	// to execute for each test case
	int n ;
	cin >> n ;
	p.resize(n) ;
	read(p) ;
	cout << _dp() << endl ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
	cout << std::fixed;
    cout << std::setprecision(12);
	int t = 1;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

