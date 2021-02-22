#include <iostream>
#include <vector>
using namespace std;
int main() {
	int i, j, max = 0;
	long long buySum = 0, buyCount = 0, sell = 0;
	int t, n;

	cin >> t;
	vector<long long> profit(t);
	for (i = 0; i < t; i++) {
		max = buySum = buyCount = sell = 0;
		// �Է�
		cin >> n;
		vector<int> days(n);
		for (j = 0; j < n; j++) {
			cin >> days[j];
		}

		// ���ͷ� ���
		for (j = n-1; j >= 0; j--) {
			if (max < days[j]) {
				sell += (buyCount * max) - buySum;
				max = days[j];
				buySum = buyCount = 0;
			}
			else if (max == days[j]) continue;
			else {
				buySum += days[j];
				buyCount++;
			}
		}
		sell += (buyCount * max) - buySum;
		profit[i] = sell;
	}
	// ���
	for (i = 0; i < t; i++) {
		cout << profit[i] << " ";
	}
}
