#include <iostream>
#include <iomanip>
using namespace std;

int fatorial(int n){
	if(n < 2){
		return 1;
	}
	return fatorial(n-1) * n;
}

int main(){
    int n;
    
    cin >> n;

    cout << fatorial(n);
}