#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int days(int** r, int n, int m, int nn);

int main() {
	int n, m, s, t;
	int i, j;
	int change = 0; // 변화 횟수

	// 관리 일자 받기
	cin >> n >> m;

	// 2차원 배열만들기
	int** room = new int* [n];
	for (i = 0; i < n; i++) {
		room[i] = new int[m] {};
	}
	// 숙박예약 현황받기
	for (i = 0; i < n; i++) {
		char* list = new char[m + 1];
		cin >> list;
		for (j = 0; j < m; j++) {
			if (list[j] == 'X')
				room[i][j] = 0;
			else if (list[j] == 'O')
				room[i][j] = (i == 0) ? 1 : room[i - 1][j] + 1;
		}
		delete list;
	}
	// 고객 입실 퇴실
	cin >> s >> t;
	int ss = s - 1; // 시작날짜 변동
	int max = 0; // 오래머물기
	while (ss < t - 1) {
		int chk = 0;
		for (j = 0; j < m; j++) { // 방하나씩 보기
			if (room[ss][j] != 0) {
				chk = 1;
				int tp = days(room, ss, j, t - 1);
				max = max < tp ? tp : max;
			}
		}
		if (chk == 0) { change = 0; break; }
		ss += max;
		max = 0;
		change++;
	}
	cout << change - 1;

	// 메모리 삭제
	for (i = 0; i < n; i++) {
		delete[] room[i];
	}
	delete[] room;
}
int days(int** r, int n, int m, int nn) {
	if (n < nn) {
		if (r[n][m] == 0) return 0;
		else if (r[n][m] > 0) return 1 + days(r, n + 1, m, nn);
	}
	else return 0;
}
