#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int j, i, index = 0;
	int flowerN; // 꽃들의 수
	int chooseF = 0; // 선택된 꽃
	int month = 9; // 3월1일부터 11월 30일까지 꽃 피었는가? 
	bool chk = false; // 변화가 없는가?
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

	// 1~3월의 시작점부터 가장 큰
	while (month != 0) {
		for (i = 0; i < flowerN; i++) { // 시작점부터 가장 긴 달 선택
			if (flowers[i][0] > start_m || (flowers[i][0] == start_m && flowers[i][1] > start_d)) break;
			if ((finish_m < flowers[i][2] || (finish_m <= flowers[i][2] && finish_d <= flowers[i][3]))
				&& seed[i] == 0) {
				chk = true;
				finish_m = flowers[i][2];
				finish_d = flowers[i][3];
				index = i;
			}
		}
		// 변화없다면 문제 발생
		if (!chk) {
			chooseF = 0;
			break;
		}

		// 꽃피어있는 달 체크
		seed[index] = 1;
		month -= finish_m - start_m;
		start_m = finish_m;
		start_d = finish_d;

		chooseF++;
		chk = false;
	}
	cout << chooseF;
}
