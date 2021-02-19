#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	if (a.second.first == b.second.first) {
		if (a.first == b.first) return a.second.second > b.second.second;
		return a.first < b.first;
	}
	return a.second.first < b.second.first;
}
int main() {
	int i, j,max = 0;
	long sum = 0;
	int townN, containN, infoN;
	int remain = 0;
	int a, b, c;

	cin >> townN >> containN;
	cin >> infoN;

	vector<pair<int, pair<int, int> > > boxInfo;
	vector<int> truck(townN, 0);

	for (i = 0; i < infoN; i++) {
		cin >> a >> b >> c;
		boxInfo.push_back(pair<int, pair<int, int> >(a, pair<int, int>(b, c)));
	}
	
	std::sort(boxInfo.begin(), boxInfo.end(), compare);

	for (i = 0; i < infoN; i++) {
		max = remain = 0;
		for (j = boxInfo[i].first; j < boxInfo[i].second.first; j++) {
			if (truck[j] > max) max = truck[j];
		}
		remain = (containN - max < boxInfo[i].second.second) ?
			containN - max : boxInfo[i].second.second;
		sum += remain;
		for (j = boxInfo[i].first; j < boxInfo[i].second.first && remain > 0; j++) {
			truck[j] += remain;
		}
	}
	cout << sum;
}
