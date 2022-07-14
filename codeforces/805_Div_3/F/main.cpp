/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Fri Jul 15 00:41:38 IST 2022
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
#define all(x) x.begin(),x.end()
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
	cin>>n;
	vector<ll> a(n);
	priority_queue<ll> pq;
	for(ll i=0;i<n;i++){
		// remove all trailing zeroes by dividing with 2
		ll x;
		cin>>x;
		while(x%2==0)x/=2;
		a[i]=x;
	}
	for(ll i=0;i<n;i++){
		// remove all trailing zeroes by dividing with 2
		ll x;
		cin>>x;
		while(x%2==0)x/=2;
		pq.push(x);
	}
	sort(all(a));
	ll curr=n-1;
	// search for a prefix in b for each a -> b[i] >= a[i] it not then its not possible
	while(curr>=0){
		if(a[curr]==pq.top()){
			pq.pop();
			--curr;
			continue;
		}
		if(a[curr]>pq.top()){
			cout<<"NO\n" ;
			return;
		}
		else{
			ll curr_max=pq.top();
			pq.pop();
			pq.push(curr_max>>1); // strip the last bit and search again -> prefix search
		}
	}
	cout<<"YES\n" ;
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

