#include<cmath>
#include<iostream>

using namespace std;

void Run();

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t ;
	cin >> t ;
	while(t--) Run();

    return 0;
}

void Run() {
	int n , r , b ;
	cin >> n >> r >> b ;
	int smallGroupSize = r / (b + 1) ;
	int bigGroupSize = smallGroupSize + 1 ;
	int nBigGroups = r % (b + 1) ;
	int nSmallGroups = (b + 1) - nBigGroups ;
	for(int i =0 ; i < nBigGroups ; i++){
		for(int j = 0 ; j < bigGroupSize ; j++) cout << 'R' ;
		cout << 'B' ;
	}
	for(int i =0 ; i < nSmallGroups ; i++){
		for(int j = 0 ; j < smallGroupSize ; j++) cout << 'R' ;
		if(i != nSmallGroups - 1) cout << 'B'  ;
		
	}
	cout << endl ;
}

