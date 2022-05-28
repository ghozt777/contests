
#include<iostream>
#include<vector>
using namespace std ;
using ll = int ;
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
void solve(){
	ll n ;
	cin >> n ;
	vector<ll> a(n) ;
	vector<ll> b(n) ;
	read(a) ;
	read(b) ;
	ll res = 0 ;
	for(int i = 0 ; i < n ; i++) for(int j = i + 1 ; j < n ; j++) if((a[i] ^ a[j]) == (b[i] ^ b[j])) ++res ;
	cout << res << endl ;
}

int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
	int t ;
	cin >> t ;
	while(t--) solve() ;
	return 0 ;
}

