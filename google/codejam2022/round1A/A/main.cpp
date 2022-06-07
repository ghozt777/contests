
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
	int tt ;
	cin >> tt ;
	for(int tc = 1 ; tc <= tt ; tc++){
		cout << "Case #" << tc << ": " ;
		Run();
	}

    return 0;
}

void Run() {
	// run your code here
	string str ;
	cin >> str ;
	string res = "" ;
	for(int i = 0 ; i < str.length() ; i++){
		char start = str[i] ;
		int j = i ;
		while(j < str.length() && str[j] == start) ++j ;
		res += str[i] ;
		if(j != str.length() && str[i] < str[j]) res += str[i] ;
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

