#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool compare(pair <long, long> a, pair<long, long> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	int i,binCount = 1;
	int N;
	cin >> N;
	vector<pair<long, long>> classTime(N);
	multiset<long> bin;
	std::multiset<long>::iterator it;

	for (i = 0; i < N; i++) {
		cin >> classTime[i].first >> classTime[i].second;
	}
	sort(classTime.begin(), classTime.end(), compare);

	bin.insert(classTime[0].second);
	for (i = 1; i < N; i++) {

		it = bin.begin();
		if (*it <= classTime[i].first) {
			bin.erase(it);
			bin.insert(classTime[i].second);

		}
		else {
			binCount++;
			bin.insert(classTime[i].second);
		}
	}
	cout << binCount;
}
