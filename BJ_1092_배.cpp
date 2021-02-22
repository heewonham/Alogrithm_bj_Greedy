#include <iostream>
#include<deque>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int i, weight, count = 0;
	int n, m;
	deque<int> box;
	deque<int> tmp;

	cin >> n;
	vector<int> crane(n);
	for (i = 0; i < n; i++) {
		cin >> crane[i];
	}
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> weight;
		box.push_back(weight);
	}

	sort(crane.begin(), crane.end());
	sort(box.begin(), box.end());

	if (box.back() > crane[n - 1])
		count = -1;
	else {
		while(!box.empty()){
			for (i = n - 1; i >= 0 && !box.empty(); i--) {
				while (!box.empty() &&crane[i] < box.back()) {
					tmp.push_back(box.back());
					box.pop_back();
				}
				if (!box.empty() && crane[i] >= box.back()) {
					box.pop_back();
				}
			}
			count++;
			while (!tmp.empty()) {
				box.push_back(tmp.back());
				tmp.pop_back();
			}
		}
	}
	cout << count;
}
