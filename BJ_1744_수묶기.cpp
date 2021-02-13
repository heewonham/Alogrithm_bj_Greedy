#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int i, j, n;
	int index = 0;
	long sum = 0;
	long max = 0;

	cin >> n;
	std::vector<int> line(n, 0);

	for (i = 0; i < n; i++) {
		cin >> line[i];
		sum += line[i];
	}

	std::sort(line.begin(), line.end());
	
	for (i = n - 1; i > 0;  i =  i -2) { // ¾ç¼ö
		max = sum;
		max -= line[i] + line[i - 1];
		max += (long)line[i] * (long)line[i - 1];
		if (line[i] < 0 && line[i - 1] < 0) { index = i; break; }
		if (max <= sum) { index =  i; break; }
		else { sum = max; index = i - 2; }
	}

	for (i = 0; i < index; i = i + 2) {
		max = sum;
		max -= line[i] + line[i + 1];
		max += (long)line[i] * (long)line[i + 1];
		if (max <= sum) break;
		else { sum = max; }
	}

	cout << sum;
}
