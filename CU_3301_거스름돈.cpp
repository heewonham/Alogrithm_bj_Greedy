#include <iostream>
#include <stdlib.h>
using namespace std;

int Dpoint(int n, int k, int* D, int* C);
int main() {
	const int k = 8; // ���� ���� ����
	int D[k] = { 5000,1000,500,100,50,10,5,1 };
	int n; // �ݾ�
	cin >> n; // �ݾ� �Է�
	int* C = (int*)malloc(sizeof(int)*n+1);
	cout << Dpoint(n/10, k, D, C);
}
int Dpoint(int n, int k, int* D, int* C) {
	int i, j;
	// �ʱ�ȭ
	for (j = 1; j <= n; j++)
		C[j] = n + 1;
	C[0] = 0;
	// ���� ���� ã��
	for (j = 1; j <= n; j++) {
		for (i = 0; i < k; i++) {
			if ((D[i] <= j) && C[j] > C[j - D[i]] + 1) {
				C[j] = C[j - D[i]] + 1;
			}
		}
	}
	return C[n];
}
