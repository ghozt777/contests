
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
	while(t--)Run();

    return 0;
}

void Run() {
	// run your code here
	int n ;
	cin >> n ;
	string str ;
	cin >> str ;
	ll res = 0 ;
	if(n == 2) res = 2 ;
	else{
		int s , e ;
		s = n / 2 ;
		e = n / 2 ;
		char x = str[s] ;
		while(s > 0){
			if(str[s - 1] == x) --s ;
			else break ;
		} 
		while(e < n - 1){
			if(str[e + 1] == x) ++e ;
			else break ;
		}
		res += e - s + 1 ;
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


