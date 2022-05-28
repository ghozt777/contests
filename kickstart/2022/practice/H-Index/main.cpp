
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
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": " ; Run() ; cout << endl ;
	}

    return 0;
}

int check(vi & arr , int k , int x){
	int ans = 0 ;
	for(int i = 0 ; i <= k ; i++){
		if(arr[i] >= x) ++ans ;
	}
	return ans ;
}

void Run() {
	// run your code here
	int n ;
	cin >> n ;
	vi arr(n) ;
	for(auto & a : arr) cin >> a ;
	priority_queue<int , vi , greater<int> > pq ;
	int hindex = 0 ;
	for(int x : arr){
		if(x > hindex){
			pq.push(x) ;
			while(pq.top() <= hindex) pq.pop() ;
			if(pq.size() > hindex) ++hindex ;
		}
		cout << hindex << " " ;
	}
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


