/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
        Time: Thu May 26 00:03:31 IST 2022
	Link to problem / contest : 
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
const ll MOD = 10e9+7 ;

vvi adj ;
vector<bool> vis ;

void init(int v){
	adj.clear() ;
	vis.clear() ;
	adj.resize(v) ;
	vis.resize(v , false) ;
}

void dfs(int s){
	vis[s] = true ;
	for(auto x : adj[s]) if(!vis[x]) dfs(x) ;
}

unordered_map<string , bool> dp ;

int a0 , b0 , c0 , d0 , a1 , b1 , c1 , d1 ;


bool check(string & str , int curr){
	if(a1 >= a0 && b1 >= b0 && c1 >= c0 && d1 >= d0) return true ;
	string sub = str.substr(curr , str.length() - curr + 1) ;
	if(dp[sub]) return dp[sub] ;
	if(curr >= str.length()) return a1 >= a0 && b1 >= b0 && c1 >= c0 && d1 >= d0 ;
	bool res = false ;
	if(str[curr] == 'A'){
		if(curr != str.length() - 1 && str[curr + 1] == 'B'){
			++a1 ;
			res = res || check(str , curr + 1) ;
			if(res) return res ;
			--a1 ;
			++c1 ;
			res = res || check(str , curr + 2) ;
			if(res) return res ;
			--c1 ;
		}
		else{
			++a1 ;
			res = res || check(str , curr + 1) ;
			if(res) return res ;
			--a1 ;
		}
	}

	else{
		if(curr != str.length() - 1 && str[curr + 1] == 'A'){
			++b1 ;
			res = res || check(str , curr + 1) ;
			if(res) return res ;
			--b1 ;
			++d1 ;
			res = res || check(str , curr + 2) ;
			if(res) return res ;
			--d1 ;
		}
		else{
			++b1 ;
			res = res || check(str , curr + 1) ;
			if(res) return res ;
			--b1 ;
		}
	}
	dp[sub] = res ;
	return res ;
}


void solve(){
	// to execute for each test case
	cin >> a0 >> b0 >> c0 >> d0 ;
	a1 = b1 = c1 = d1 = 0 ;
	string str ;
	cin >> str ;
	check(str , 0) ? cout << "YES\n" : cout << "NO\n" ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	int t ;
	cin >> t ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

