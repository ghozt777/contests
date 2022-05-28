
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)


void Run();
void printArray(int[] , int) ;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t ;
	cin >> t ;
	while(t--) Run();
    return 0;
}

bool isPowerOfTwo(ll n){
   if(n==0) return false;
   return (ceil(log2(n)) == floor(log2(n)));
}

void Run() {
	// run your code here
	ll n ;
	cin >> n ;
	set<ll> s ;
	for(int i = 0 ; i < n ; i++){
		ll a ;
		cin >> a ;
		s.insert(a) ;
	}
	ll res = 0 ;
	unordered_set<ll> p2 ;
	for(auto x : s){
		if(isPowerOfTwo(x)){
			p2.insert(x) ;
			++res ;
		}
	} 
	for(auto x : s){
		if(isPowerOfTwo(x)) continue ;
		while(x != 0){
			ll p = pow(2 , floor(log2(x))) ;
			if(p2.find(p) == p2.end()){
				p2.insert(p) ;
				++res ;
			}
			x -= p ;
		}
	}
	cout << res << endl ;
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


