/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sat Jun 18 20:02:17 IST 2022
	Link to problem / contest : 
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<ll> ;
using vvi = vector<vi> ;
using pi = pair<ll , ll> ;

#define REP(i,s,e) for(ll i=s;i<=e;i++)
#define EB emplace_back
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(ll i=0;i<n;i++)
#define fr(itr, n) for(ll itr=0;itr<n;itr++)
#define F(s,e) for(ll i=s;i<=e;i++)
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
void init(ll v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(ll s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}
// count set bits in a given number
template <typename T>
ll cnt_set_bits(T n){ll res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------------------------------------------------------------------------------

void solve(){
	// to execute for each test case
	ll n;
	cin >> n ;
	vi arr(n) ;
	read(arr) ;
	pair<ll,ll> a={INT_MAX,-1};
	pair<ll,ll> b={INT_MAX,-1};
	for(ll i=0;i<n;i++){
		if(i%2==0){
			if(arr[i]<a.first)a={arr[i],i};
		}
		else{
			if(arr[i]<b.first)b={arr[i],i};
		}
	}
	if(n%2==0){	
		if(a.first>b.first){
			cout<<"Mike\n" ;
		}
		else if(b.first>a.first){
			cout<<"Joe\n" ;
		}
		else{
			if(b.second>a.second)cout<<"Joe\n" ;
			else cout<<"Mike\n";
		}
	}
	else{
		cout<<"Mike\n";	
	}
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	ll t ;
	cin >> t ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

