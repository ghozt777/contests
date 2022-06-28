/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sat Jun 18 20:02:20 IST 2022
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


bool dfs(vvi &grid, int i, int j,int curr){
	if(i>=grid.size()||j>=grid[0].size()) return false;
	if((i==grid.size()-1)&&(j==grid[0].size()-1)) return curr+grid[i][j]==0;
	if(dfs(grid,i+1,j,curr+grid[i][j])) return true ; 
	else if(dfs(grid,i,j+1,curr+grid[i][j])) return true ;
	return false ;
}

void debug(vector<vector<pi>> &dp){
	for(int i=1;i<dp.size();i++){
		for(int j=1;j<dp[0].size();j++){
			cout<<"("<<dp[i][j].first<<","<<dp[i][j].second<<") " ;
		}
		cout<<endl;
	}
}

void solve(){
	// to execute for each test case
	// memset(dp,-1,sizeof(dp));
	int n , m ;
	cin >> n >> m ;
	vvi grid(n,vi(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	if((n+m)%2==0){
		cout<<"NO\n";
		return;
	}
	vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(m+1,{0,0}));
	for(int i=1;i<=n;i++)dp[i][1]={dp[i-1][1].first+grid[i-1][0],dp[i-1][1].second+grid[i-1][0]};
	for(int i=1;i<=m;i++)dp[1][i]={dp[1][i-1].first+grid[0][i-1],dp[1][i-1].second+grid[0][i-1]};
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			pi top=dp[i-1][j];
			pi left=dp[i][j-1];
			dp[i][j].first=max({ top.first+grid[i-1][j-1] , left.first+grid[i-1][j-1]  }) ;
			dp[i][j].second=min({ top.second+grid[i-1][j-1] , left.second+grid[i-1][j-1]  }) ;
		}
	}
	// debug(dp);
	if(dp[n][m].first%2==1){
		cout<<"NO\n" ;
		return ;
	}
	if(dp[n][m].first>=0&&dp[n][m].second<=0){
		cout<<"YES\n" ;
	}
	else{
		cout<<"NO\n";
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
