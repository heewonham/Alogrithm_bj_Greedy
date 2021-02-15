#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second; // 내림차순
}
int main() {
	int i, bagCount = 0, c;
	int n, k; // 보석 개수, 가방 개수
	long sum = 0; // 보석의 최대합
	std::multiset<int>::iterator it;

	cin >> n >> k;
	std::vector<pair<int,int>> jewels(n);
	std::multiset<int> bags;

	// 보석의 무게와 가격 입력
	for (i = 0; i < n; i++) {
		cin >> jewels[i].first >> jewels[i].second;
	}
	// 가방의 무게
	for (i = 0; i < k; i++) {
		cin >> c;
		bags.insert(c);
		bagCount++;
	}

	std::sort(jewels.begin(), jewels.end(), compare);
	for (i = 0; i < n; i++) { // 보석
		if (bagCount == 0) break;
		it = bags.lower_bound(jewels[i].first);
		if (it != bags.end()) {// 값이 있다면
			sum += (long)jewels[i].second;
			bags.erase(it);
			bagCount--;
		}
	}
	cout << sum;
}
