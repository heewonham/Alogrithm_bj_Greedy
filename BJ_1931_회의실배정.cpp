#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int i, j, n = 0;
	int count, s;

	cin >> n;
	std::vector<pair<int, int>> confer;

	for (i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		confer.push_back(pair<int, int>(a,b));
	}
	std::sort(confer.begin(), confer.end(),compare);

	s = confer[0].second;
	count = 1;
	for (i = 1; i < n; i++) {
		if (s <= confer[i].first) {
			s = confer[i].second;
			count++;
		}
	}
	cout << count;
}
