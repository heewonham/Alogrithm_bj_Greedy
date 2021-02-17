#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k;
	int h, i, j, max = 0;
	int isChange = 0;
	int maxIdx = 0, idx = 101;
	bool chk = false;

	cin >> n >> k;
	vector<int> sched(k);
	vector<int> plugin(n, 0);

	for (i = 0; i < k; i++) {
		cin >> sched[i];
	}

	for (i = 0; i < k; i++) {
		chk = false;
		// 1. ��Ⱑ �̹� �ִ°�?
		for (j = 0; j < n; j++) {
			if (plugin[j] == sched[i]) { chk = true; break; }
		}

		// 2. �� �ڸ��� �ִ°�?
		if (!chk) {
			for (j = 0; j < n; j++) {
				if (plugin[j] == 0) {
					plugin[j] = sched[i];
					chk = true;
					break;
				}
			}
		}

		// 3. �� �ڸ��� ���°�? 
		if (!chk) {
			max = -1;
			for (j = 0; j < n; j++) { //��� plug�� �� ���� ����� �� �ִ°�?
				idx = 101; 
				for (h = i + 1; h < k; h++) {
					if (plugin[j] == sched[h]) { idx = h; break; }
				}
				if (idx == 101) {
					// ������ ����� ���� ����.
					maxIdx = j;
					break;
				}
				else {
					if (max < idx) { maxIdx = j; max = idx; }
				}
			}
			plugin[maxIdx] = sched[i];
			isChange++;
		}
	}
	cout << isChange;
}
