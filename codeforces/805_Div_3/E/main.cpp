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
// count set bits in a given number
template <typename T>
int cnt_set_bits(T n){int res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------------------------------------------------------------------------------

bool isBipartite(vector<vector<int>>&adj,vector<int>&color,vector<bool>&vis,int p,int s){
	vis[s]=true;
	if(color[s]==-1){
		color[s]=p==1?2:1;
		for(int x:adj[s]){
			if(!isBipartite(adj,color,vis,color[s],x)) return false;
		}
		return true;
	}
	else return color[s]!=p;
}

void solve(){
	// to execute for each test case
	int n = 0 ;
	cin>>n;
	vector<vector<ll>> arr(n,vector<ll>(2));
	map<ll,ll> m;
	for(int i=0;i<n;i++){
		cin>>arr[i][0]>>arr[i][1];
		++m[arr[i][0]];
		++m[arr[i][1]];
	}
	vector<vector<int>> adj(n);
	vector<bool> vis(n,false);
	vector<int> color(n,-1);
	for(int i=0;i<n;i++){
		if(m[arr[i][0]]>2||m[arr[i][1]]>2||arr[i][0]==arr[i][1]){
			cout<<"NO\n" ;
			return;
		}
		adj[arr[i][0]-1].push_back(arr[i][1]-1);
		adj[arr[i][1]-1].push_back(arr[i][0]-1);
	}

	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(!isBipartite(adj,color,vis,-1,i)){
				cout<<"NO\n";
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

