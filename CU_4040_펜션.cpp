#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int days(int** r, int n, int m, int nn);

int main() {
	int n, m, s, t;
	int i, j;
	int change = 0; // ��ȭ Ƚ��

	// ���� ���� �ޱ�
	cin >> n >> m;

	// 2���� �迭�����
	int** room = new int* [n];
	for (i = 0; i < n; i++) {
		room[i] = new int[m] {};
	}
	// ���ڿ��� ��Ȳ�ޱ�
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
	// �� �Խ� ���
	cin >> s >> t;
	int ss = s - 1; // ���۳�¥ ����
	int max = 0; // �����ӹ���
	while (ss < t - 1) {
		int chk = 0;
		for (j = 0; j < m; j++) { // ���ϳ��� ����
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

	// �޸� ����
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
