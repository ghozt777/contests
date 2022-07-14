/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun Jun 19 13:49:22 IST 2022
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

void solve(){
	// to execute for each test case
	int n = 0 ;
	cin>>n;
	vector<vector<ll>> arr(n,vector<ll>(2));
	map<ll,ll> m;
	for(int i=0;i<n;i++)cin>>arr[i][0]>>arr[i][1];
	for(auto x:arr){
		++m[x[0]];
		++m[x[1]];
		if(m[x[0]]>2||m[x[1]]>2){
			cout<<"NO\n" ;
			return;
		}
	}
	vector<ll> color(n,-1);
	for(auto x:arr){
		if(color[x[0]]==-1){
			if(color[x[1]]!=-1)color[x[0]]=color[x[1]]==1?2:1;
			else{
				color[x[0]]=1;
				color[x[1]]=2;
			}
		}
		else if(color[x[1]]==-1){
			color[x[1]]=color[x[0]]==1?2:1;	
		}
		else{
			if(color[x[0]]==color[x[1]]){
				cout<<"NO\n" ;
				return;
			}
		}
	}
	cout<<"YES\n";
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

