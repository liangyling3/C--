//输入n，找出前n个素数 
#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int x, int *primes, int count);

int main(){
	int number, i;
	cin >> number;
	int * primes;
	primes = new int[number];
	for (i = 0; i < number; i ++){
		primes[i] = 2;
	}
	int count = 1;
	i = 3;
	while (count < number) {
		if (isPrime(i, primes, count)) {
			primes[count++] = i;
		}
		i ++;
	}
	
	for (i = 0; i < number; ++ i) {
		cout << primes[i] << " ";
		if ((i+1)%5 == 0) cout << '\n';
	}
	
	delete [] primes;
	return 0;
} 

int isPrime(int x, int *primes, int count){
	for (int i = 0; i < count; ++i){
		if (x % primes[i] == 0) return 0;
	}
	return 1;
} 
