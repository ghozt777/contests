// NOTE:  use the pattern to get the final result -> genList(n)

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
void genList(ll);
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t ;
	cin >> t ;
	while(t--) Run();

    return 0;
}

void Run() {
	// run your code here


	ll n ;
	cin >> n ;

	/*
		DEBUG MODE : 
	*/

	// to see the pattern for the answer uncomment the next line :

	// genList(n) ;


	/*
		DEBUG MODE END
	*/


	--n ;
	if(n % 4 == 0){	
		ll q = n / 4 ;
		ll res = 5 + 4 * (q - 1) ;
		cout << res << endl ;
		return ;
	}
	else if(n % 4 == 3){
		ll q = n / 4 ;
		ll res = 7 + 4 * q ;
		cout << res << endl ;
		return ;
	}
	else cout << 3 << endl ;
	return ;
}



void genList(ll n) {
	// try to see the trend in the list
	cout << "-- GENERATED LIST OF POSSIBLE ANSWERS FROM (2 - " << n << ") --" << endl ;
	ll curr = 1 ;
	bool _xor = true ;
	cin >> n ;
	for(int i = 2 ; i <= n ; i++){
		if(_xor) curr ^= i ;
		else curr &= i ;
		_xor = !_xor ;
		cout << curr << endl ;
	}
	cout << "------ END OS LIST ----------" << endl ;
	cout << "CORRECT ANSWER: " << curr << "\n" ;
	cout << "----------------------" << endl ;
	return ;
}



void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}





