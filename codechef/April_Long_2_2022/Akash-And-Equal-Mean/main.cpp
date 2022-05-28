
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

ll __sum(ll a){
	return a * (a + 1) / 2 ;
}

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
	int n ;
	cin >> n ;
	vector<double> arr(n) ;
	unordered_map<double , ll> m ;
	unordered_set<double> considered ;
	double sum = 0 ;
	for(auto & a : arr){
		 cin >> a ;
		 sum += a ;
		 m[a]++ ;
	}
	ll res  = 0 ;
	double check = 2.0 * sum / n ;
	for(int i = 0 ; i < n ; i++){
		if(considered.find(arr[i]) == considered.end()){
			double toFind = check - arr[i] ;
			if(toFind == arr[i]){
				considered.insert(arr[i]) ;
				res += __sum(m[arr[i]] - 1) ;
			}
			else if(m[toFind]){
				considered.insert(arr[i]) ;
				considered.insert(toFind) ;
				res += m[toFind] * m[arr[i]] ;
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


