
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
	int x , y ;
	cin >> x >> y ;
	if((x % 2 == 1 && y % 2 == 1) || x == 1 || y == 1){
		cout << -1 << endl ;
		return ;
	}
	string s1 = ""  , s2 = "" ;
	if(x % 2 == 1){
		s1 = "a" ;
		s2 = "a" ;
		--x ;
	}
	if(y % 2 == 1){
		s1 = "b" ;
		s2 = "b" ;
		--y ;
	}
	if(s1.length()){
		for(int j = 0 ; j < y / 2 ; j++){
			s1.insert(0 , "b") ;
			s1 += "b" ;
		}

		for(int j = 0 ; j < x / 2 ; j++){
			s1.insert(0 , "a") ;
			s1 += "a" ;
		}

		for(int j = 0 ; j < x / 2 ; j++){
			s2.insert(0 , "a") ;
			s2 += "a" ;
		}

		for(int j = 0 ; j < y / 2 ; j++){
			s2.insert(0 , "b") ;
			s2 += "b" ;
		}
	}
	else{
		for(int i = 0 ; i < x ; i++) s1 += "a" ;
		for(int i = 0 ; i < y ; i++) s2 += "b" ;
		for(int j = 0 ; j < y / 2 ; j++){
			s1.insert(0 , "b") ;
			s1 += "b" ;
		}
		for(int j = 0 ; j < x / 2 ; j++){
			s2.insert(0 , "a") ;
			s2 += "a" ;
		}
	}

	cout << s1 << endl ;
	cout << s2 << endl ;
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


