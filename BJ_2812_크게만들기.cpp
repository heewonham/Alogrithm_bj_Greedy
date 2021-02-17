#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main() {
	int n, k, i;
	string num;
	deque<char> maximum;

	cin >> n >> k;
	cin >> num;

	for (i = 0; i < n; i++) {
		while( k  > 0&& !maximum.empty() && maximum.back() < num[i]) {
			maximum.pop_back();
			k--;
		}
		maximum.push_back(num[i]);
	}

	for (i = 0; i < maximum.size()-k; i++)
		cout << maximum[i];
}
