
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

void Run() {
	// run your code here
	ll n ;
	cin >> n ;
	vector<ll> arr(n) ;
	if(arr[n - 1] < arr[n - 2]){
		cout << "NO\n" ;
		return ; 
	}
	for(auto & a : arr) cin >> a ;
	bool once = false ;
	for(int i = 0 ; i < arr.size() - 1 ; i++){
		if(arr[i] > arr[i + 1]){
			if(!once){
				once = true ;
				swap(arr[i], arr[i + 1]) ;
				if(i != 0) i -= 2 ;
			}
			else{
				cout << "NO\n" ;
				return ;
			}
		}
	}
	cout << "YES\n" ;
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


