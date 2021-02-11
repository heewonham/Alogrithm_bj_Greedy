#include <iostream>
using namespace std;

void sort(double* k, int count, double kal);
int main() {
	int num, i, aPrice, bPrice, aKal, count = 0;
	double perA, totalK = 0, totalP = 0;
	cin >> num;
	int* bKal = (int*)malloc(sizeof(int) * num);
	double* K = (double*)malloc(sizeof(double) * num);

	cin >> aPrice >> bPrice;
	cin >> aKal;
	
	// 피자 : 달러당 칼로리
	perA = aKal / (float)aPrice;
	totalP += aPrice;
	totalK += aKal;
	
	// 토핑 
	for (i = 0; i < num; i++) {
		cin >> bKal[i];
		double kal = bKal[i] / (double)bPrice;
		if (perA <= kal) {
			sort(K, count, bKal[i]);
			count++;
		}
	}
	for (i = 0; i < count; i++) {
		if (((totalK + K[i]) / (totalP + bPrice)) >= totalK / totalP) {
			totalP += bPrice;
			totalK += K[i];
		}
		else
			break;
	}
	cout << int(totalK/totalP);
}
void sort(double* k, int count, double kal) {
	int i;
	for (i = count; i > 0; i--) {
		if (k[i - 1] < kal) k[i] = k[i - 1];
		else break;
	}
	k[i] = kal;
}
