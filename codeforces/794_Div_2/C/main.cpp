/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
        Time: Wed May 25 23:44:39 IST 2022
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


void solve(){
	// to execute for each test case
	ll n ;
	cin >> n ;
	vector<ll> arr(n) ;
	for(auto & a : arr) cin >> a ;
	sort(arr.begin() , arr.end()) ;
	for(ll i = 0 ; i < n ; i++){
		if(i + 1 < n && arr[i] == arr[i + 1]){
			ll j = i;
			while(arr[i] == arr[j + 1]){
				if(j < n - 1) ++j ;
				else break ;
			}
			ll s = j - i + 1 ;
			ll ns = n - s ;
			if(abs(s - ns) >= 1){
				cout << "NO\n" ;
				return ;
			}
			i = j + 1 ;
		}
	}
	for(ll i = 1 ; i < n - 1; i += 2){
		ll j = i + 1 ;
		while(j != n - 1 && arr[i] == arr[j]) ++j ;
		swap(arr[i] , arr[j]) ;
	}
	cout << "YES\n" ;
	for(ll x : arr) cout << x << " " ;
	cout << endl ;
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

