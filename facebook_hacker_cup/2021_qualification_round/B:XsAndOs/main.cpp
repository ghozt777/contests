/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Tue Jun  7 12:23:23 IST 2022
	Link to problem / contest : [Dhttps://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

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
#define what_is(x) cout << #x << ": " << x << endl ;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}
// requires c++17
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = pow(10,9)+7 ;


vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}


void solve(int tc){
	// to execute for each test case
	cout << "Case #" << tc << ": " ;
	int n ;
	cin >> n ;
	vector<vector<char>> grid(n , vector<char>(n)) ;
	for(int i = 0 ; i < n ; i++) read(grid[i]) ;
	int best = INT_MAX ; 

	vector<vector<pi>> solutions ;

	for(int i = 0 ; i < n ; i++){
		int space = 0 ;
		int o = 0 ;
		vi J ; 
		for(int j = 0 ; j < n ; j++){
			o += grid[i][j] == 'O' ;
			space += grid[i][j] == '.' ;
			if(grid[i][j] == '.') J.PB(j) ;
		}
		if(o != 0 || space == 0) continue ;
		if(space < best){
			best = space ;
			solutions.clear() ;
			solutions.resize(0) ;
			vector<pi> solution ;
			for(int j : J) solution.PB({i , j}) ;
			solutions.PB(solution) ;
		}
		else if(space == best){
			vector<pi> solution ;
			for(int j : J) solution.PB({i , j}) ;
			solutions.PB(solution) ;
		}
	}

	vector<vector<pi>> solutions2 ;

	for(int j = 0 ; j < n ; j++){
		int space = 0 ;
		int o = 0 ;
		vi I ;
		for(int i = 0 ; i < n ; i++){
			if(grid[i][j] == '.') ++space ;
			if(grid[i][j] == 'O') ++o ;
			if(grid[i][j] == '.') I.PB(i) ;
		}
		if(o != 0 || space == 0) continue ;
		if(space < best){
			best = space ;
			solutions2.clear() ;
			solutions2.resize(0) ;
			vector<pi> solution ;
			for(int i : I) solution.PB({i , j}) ;
			solutions2.PB(solution) ;
		}
		else if(best == space){
			vector<pi> solution ;
			for(int i : I) solution.PB({i , j}) ;
			solutions2.PB(solution) ;	
		}
	}


	set<vector<pi>> final ; 

	for(auto x : solutions) final.insert(x) ;
	for(auto x : solutions2) final.insert(x) ;
	int res = 0 ;
	for(auto x : final){
		if(x.size() == best) ++res ;
	}

	best == INT_MAX ? cout << "Impossible" << endl : cout << best << " " << res << endl ;

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
	for(int tc = 1 ; tc <= t ; tc++) solve(tc) ;

	return EXIT_SUCCESS ;
}

