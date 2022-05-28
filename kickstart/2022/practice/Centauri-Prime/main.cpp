
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

int check(char x){
	if(x == 'y') return 0 ;
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return 1 ;
	else return 2 ;
}

void Run() {
	// run your code here
	string str ;
	cin >> str ;
	string ruler ;
	int res = check(tolower(str[str.size() - 1])) ;
	if(res == 0) ruler = "nobody" ;
	else if(res == 1) ruler = "Alice";
	else ruler = "Bob" ;
	cout << str << " is ruled by " << ruler <<".";
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


