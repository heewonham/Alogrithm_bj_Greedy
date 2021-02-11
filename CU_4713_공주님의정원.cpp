#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int j, i, index = 0;
	int flowerN; // �ɵ��� ��
	int chooseF = 0; // ���õ� ��
	int month = 9; // 3��1�Ϻ��� 11�� 30�ϱ��� �� �Ǿ��°�? 
	bool chk = false; // ��ȭ�� ���°�?
	int finish_m = 0, finish_d = 0;
	int start_m = 3, start_d = 1;
	cin >> flowerN;

	std::vector <vector<int>> flowers(flowerN, vector<int>(4,0));
	std::vector <int> seed(flowerN, 0);

	for (i = 0; i < flowerN; i++) {
		for (j = 0; j < 4; j++) {
			cin >> flowers[i][j];
		}
	}
	sort(flowers.begin(), flowers.end());

	// 1~3���� ���������� ���� ū
	while (month != 0) {
		for (i = 0; i < flowerN; i++) { // ���������� ���� �� �� ����
			if (flowers[i][0] > start_m || (flowers[i][0] == start_m && flowers[i][1] > start_d)) break;
			if ((finish_m < flowers[i][2] || (finish_m <= flowers[i][2] && finish_d <= flowers[i][3]))
				&& seed[i] == 0) {
				chk = true;
				finish_m = flowers[i][2];
				finish_d = flowers[i][3];
				index = i;
			}
		}
		// ��ȭ���ٸ� ���� �߻�
		if (!chk) {
			chooseF = 0;
			break;
		}

		// ���Ǿ��ִ� �� üũ
		seed[index] = 1;
		month -= finish_m - start_m;
		start_m = finish_m;
		start_d = finish_d;

		chooseF++;
		chk = false;
	}
	cout << chooseF;
}
