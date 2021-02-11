#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,i,j;
	long sum = 0L;
	
	cin >> n;
	
	std::vector<int> km(n-1);
	std::vector<int> gas(n);
	
	for(i=0; i< n-1; i++){
		cin >> km[i];
	}
	for(i=0; i < n; i++){
		cin >> gas[i];
	}
	
	i = 0;
	while(i < n-1){
		sum += (long)gas[i] * (long)km[i];
		j = i+1;
		while(gas[i] <= gas[j]&&j < n-1){
			sum += (long)gas[i] * (long)km[j];
			j++; 
		}
		i = j;

	}
	cout << sum;
} 
