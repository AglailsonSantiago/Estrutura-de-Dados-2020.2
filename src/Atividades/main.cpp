#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(int n);
double euler(int n);

int main() {
	double e;
	double n;
	cin >> n;
	e = euler(n);
	cout << setprecision(7) << e;
}

double fatorial(int n){
	if(n < 2){
		return 1;
	}
	return fatorial(n-1) * n;
}

double euler(int n){
	double e = 1.0;
	for(int i = n; i > 0; i--){
		e = e + (1.0/fatorial(i));
	}
	return e;
}