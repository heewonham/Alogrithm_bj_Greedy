#include <iostream>
#include <vector>
using namespace std;
int main(){
	int i, num, money;
	int count = 0;
	cin >> num >> money;
	std::vector<int> m(num, 0);

	for (i = 0; i < num; i++) {
		cin >> m[i];
	}
	for (i = num - 1; i >= 0; i--) {
		while (money >= m[i]) {
			money -= m[i];
			count++;
		}
		if (money == 0) break;
	}
	cout << count;
}
