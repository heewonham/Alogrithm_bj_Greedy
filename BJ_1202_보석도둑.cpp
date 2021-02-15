#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second; // ��������
}
int main() {
	int i, bagCount = 0, c;
	int n, k; // ���� ����, ���� ����
	long sum = 0; // ������ �ִ���
	std::multiset<int>::iterator it;

	cin >> n >> k;
	std::vector<pair<int,int>> jewels(n);
	std::multiset<int> bags;

	// ������ ���Կ� ���� �Է�
	for (i = 0; i < n; i++) {
		cin >> jewels[i].first >> jewels[i].second;
	}
	// ������ ����
	for (i = 0; i < k; i++) {
		cin >> c;
		bags.insert(c);
		bagCount++;
	}

	std::sort(jewels.begin(), jewels.end(), compare);
	for (i = 0; i < n; i++) { // ����
		if (bagCount == 0) break;
		it = bags.lower_bound(jewels[i].first);
		if (it != bags.end()) {// ���� �ִٸ�
			sum += (long)jewels[i].second;
			bags.erase(it);
			bagCount--;
		}
	}
	cout << sum;
}
