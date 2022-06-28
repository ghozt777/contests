/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun Jun 19 13:49:15 IST 2022
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

ll _sum(ll n){
	return n*(n+1)/2 ;
}

ll ap(ll a , ll d , ll n){
	return n*(2*a+(n-1)*d)/2;
}

void solve(){
	// to execute for each test case
	int n , m ;
	cin >> n >> m ;
	// vector<vector<ll>> grid(n,vector<ll>(m)) ;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		grid[i][j]=i*m+(j+1);
	// 	}
	// }
	// vector<vector<ll>> dp(n,vector<ll>(m,0)) ;
	// for(int i=0;i<m;i++){
	// 	if(i==0) dp[0][i]=grid[0][i];
	// 	else dp[0][i] = dp[0][i-1]+grid[0][i];
	// }
	// for(int i=0;i<n;i++){
	// 	if(i==0) dp[i][0]=grid[i][0];
	// 	else dp[i][0] = dp[i-1][0]+grid[i][0];
	// }
	// for(int i=1;i<n;i++){
	// 	for(int j=1;j<m;j++){
	// 		dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
	// 	}
	// }
	// cout<< dp[n-1][m-1] << endl ;
	if(n==1){
		cout << _sum(m) << endl ;
		return ;
	}
	else{
		ll res = _sum(m) + ap(2*m,m,n-1) ;
		cout << res << endl ;
	}
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t ;
	cin >> t ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

