
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
	// trick make GCD as low as possible i.e. = 2 
	int a , b ;
	cin >> a >> b ;
	if(a%2 == 0) b - a >= 2 ? cout << a << " " << a + 2 : cout << -1 ;
	else b - a >= 3 ? a % 3 == 0 ? cout << a << " " << a + 3 : cout << a + 1 << " " << a + 3 : cout << -1 ;
	cout << endl ;
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


