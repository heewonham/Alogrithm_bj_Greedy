#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, L;
	int i,j, start;
	int tape = 0;

	cin >> N >> L;
	std::vector<int> leaking(N);

	for (i = 0; i < N; i++) {
		cin >> leaking[i];
	}
	std::sort(leaking.begin(), leaking.end());
	for (i = 0; i < N; i++) {
		tape++;
		start = leaking[i] + L - 1;
		for (j = i + 1; j < N && start >= leaking[j]; j++) {
			i = j;
		}
	}
	cout << tape;
}
