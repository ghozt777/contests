/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sat May 28 18:10:56 IST 2022
	Link to problem / contest : https://atcoder.jp/contests/dp/tasks/dp_f
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

string bruteforce(string & s , string & t , string curr , ll n1 , ll n2){
	if(!n1 || !n2) return curr ;
	if(s[n1 - 1] == t[n2 - 1]) return bruteforce(s , t , curr + s[n1 - 1] , n1 - 1 , n2 - 1) ;
	else{
		string a = bruteforce(s , t , curr , n1 - 1 , n2) ;
		string b = bruteforce(s , t , curr , n1, n2 - 1) ;
		return a.length() >= b.length() ? a : b ; 
	} 
}

string _dp(string & s, string & t){
	const int n = s.length() ;
	const int m = t.length() ;
	string * dp[n + 1][m + 1] ;
	dp[0][0] = new string("") ;
	for(int i = 0 ; i <= n ; i++)dp[i][0] = dp[0][0] ;
	for(int i = 0 ; i <= m ; i++)dp[0][i] = dp[0][0] ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(s[i - 1] == t[j - 1]) dp[i][j] = new string(* dp[i - 1][j - 1] + s[i - 1]) ;
			else dp[i][j] = dp[i - 1][j]->length() >= dp[i][j - 1]->length() ? dp[i - 1][j] : dp[i][j - 1] ;
		}
	}
	return * dp[n][m] ;
}	

string dp_optimized(string & s , string & t){
	const int n = s.length() ;
	const int m = t.length() ;

	int dp[n + 1][m + 1] ;
	memset(dp , 0 , sizeof(dp)) ;
	char trace[n + 1][m + 1] ;

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(s[i - 1] == t[j -1]){
				dp[i][j] = dp[i - 1][j - 1] + 1 ;
				trace[i][j] = 'E' ;
			}
			else if(dp[i - 1][j] > dp[i][j - 1]){
				dp[i][j] = dp[i - 1][j] ;
				trace[i][j] = 'I' ;
			}
			else{
				dp[i][j] = dp[i][j - 1] ;
				trace[i][j] = 'J' ;
			}
		}
	}

	int i = n ;
	int j = m ;

	string res = "" ;

	while(i >= 1 && j >= 1){
		if(trace[i][j] == 'E') res += s[i - 1] , --i , --j ;
		else if(trace[i][j] == 'I') --i  ;
		else --j ;
	}

	reverse(res.begin()  ,res.end());

	return res ;
}

void solve(){
	// to execute for each test case
	string s , t ;
	cin >> s >> t ;
	// string res = bruteforce(s , t , "" , s.length() , t.length()) ;
	// string res = _dp(s , t) ;
	// reverse(res.begin() , res.end()) ;
	cout << dp_optimized(s , t) << endl ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	int t  = 1;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

