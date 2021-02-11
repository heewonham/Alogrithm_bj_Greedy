#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	int i, j, k = 0, count = 0;
	int min = 0;
	int test, appl;
	cin >> test;
	vector<int> emp(test);


	while (k < test) {
		cin >> appl;
		vector<pair<int, int>> case1(appl);

		for (i = 0; i < appl; i++) {
			cin >> case1[i].first >> case1[i].second;
		}
		std::sort(case1.begin(), case1.end(), compare);

		i = 1;
		min = case1[0].second;
		count = appl;
		while (i < appl) {
			if (case1[i].second > min) {
				count--;
			}
			else {
				min = case1[i].second;
			}
			i++;
		}
		emp[k] = count;
		k++;
	}
	for (i = 0; i < test; i++) {
		cout << emp[i] << endl;
	}
}
