/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sat May 28 21:47:06 IST 2022
	Link to problem / contest : https://atcoder.jp/contests/dp/tasks/dp_h
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
const ll MOD = 1000000000 + 7 ;


vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}

ll dp[1001][1001] ;

ll dfs(vector<vector<char>> & grid , int i , int j){
	if(dp[i][j] != -1) return dp[i][j] % MOD ;
	if(i == grid.size() - 1 && j == grid[0].size() - 1) return 1 ;
	if(i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#') return 0 ;
	int res = 0 ;
	res = res % MOD + dfs(grid , i + 1 , j) % MOD ;
	res = res % MOD + dfs(grid , i , j + 1) % MOD ;
	return dp[i][j] = res % MOD ;
}


void solve(){
	// to execute for each test case
	memset(dp , -1 , sizeof(dp)) ;
	int H , W ;
	cin >> H >> W ;
	vector<vector<char>> grid(H , vector<char>(W)) ;
	for(int i = 0 ; i < H ; i++){
		for(int j = 0 ; j < W ; j++){
			cin >> grid[i][j] ;
		}
	}

	cout << dfs(grid, 0 , 0)  << endl ;

}


int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	int t = 1 ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

