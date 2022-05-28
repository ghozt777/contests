
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

bool _check(string a , string b){
	int c = 0 ;
	string sa(a) ;
	string sb(b) ;
	for(char x = 'a' ; x <= 'k' ; x++){
		sa[0] = x ;
		if(sa == sb) ++c ;
	}
	sa[0] = a[0] ;
	for(char x = 'a' ; x <= 'k' ; x++){
		sa[1] = x ;
		if(sa == sb) ++c ;
	}
	return c == 1 ;
}

unordered_set<string> considered ;

bool check(string a , string b){
	string s = a + "|" + b ;
	string sb = b + "|" + a ;
	return considered.find(s) == considered.end() && considered.find(sb) == considered.end() ;
}

string sereialize(string a , string b){
	return a + "|" + b  ;
}

void Run() {
	// run your code here
	int n ;
	cin >> n ;
	vector<string> arr(n) ;
	unordered_map<string , ll> m ;
	for(auto & a : arr){
		 cin >> a ;
		 ++m[a] ;
	}
	ll res = 0 ;
	for(auto x : arr){
		char a0 = x[0] ;
		char a1 = x[1] ;
		string cp = x ;
		for(char y = 'a' ; y <= 'k' ; y++){
			if(y != a0){
				cp[0] = y ;
				if(m[cp] && check(x , cp)){
					considered.insert(sereialize(x , cp)) ;
					res += m[x] * m[cp] ;
				}
			}
		}
		cp[0] = a0 ;
		for(char y = 'a' ; y <= 'k' ; y++){
			if(y != a1){
				cp[1] = y ;
				if(m[cp] && check(x , cp)){
					considered.insert(sereialize(x , cp)) ;
					res += m[x] * m[cp] ;
				}
			}
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


