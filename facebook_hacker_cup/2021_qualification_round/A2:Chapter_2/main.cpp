/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Mon Jun  6 18:30:10 IST 2022
	Link to problem / contest : https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2
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


void addEdge(char a , char b , vector<vector<int>> & adj){
	adj[a - 'A'].PB(b - 'A') ;
}

int bfs(int s , int t , vector<vector<int>> & adj){
	queue<int> q ;
	vector<bool> vis(26 , false) ;
	q.push(s) ;

	int curr = 0 ;
	while(!q.empty()){
		int n = q.size() ;
		while(n--){
			int c = q.front() ;
			if(c == t) return curr ;
			q.pop() ;
			for(int x : adj[c]){
				if(!vis[x]){
					vis[x] = true ;
					q.push(x) ;
				}
			}
		}
		++curr ; 
	}
	return INT_MAX ;	
}

void solve(int tc){
	// to execute for each test case
	vector<vector<int>> adj(26) ;
	cout << "Case #" << tc << ": " ;
	string s ;
	cin >> s ;
	int k  ;
	cin >> k ;
	for(int i = 0 ; i < k ; i++){	
		string a ;
		cin >> a ; 
		addEdge(a[0] , a[1] , adj) ;
	}
	int res = INT_MAX ;
	for(char ch = 'A' ;  ch <= 'Z' ; ch++){
		int curr = 0 ;
		for(char x : s){
			if(x != ch){
				int cost = bfs(x - 'A', ch - 'A' , adj) ;
				if(cost == INT_MAX){
					curr = INT_MAX ;
					break ;
				}
				else curr += cost ;
			}
		}
		res = min(res , curr) ;
	}
	res == INT_MAX ? cout << -1 << endl : cout << res << endl ;
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

