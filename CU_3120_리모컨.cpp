#include <iostream>
using namespace std;
int remote(int num) {
	if (num == 0) return 0;
	else if (num > 7) return remote(num - 10)+1;
	else if (num > 2) return remote(num - 5)+1;
	else if (num > 0) return remote(num - 1)+1;
	else if (num > -3) return remote(num + 1)+1;
	else if (num > -8) return remote(num + 5)+1;
	else return remote(num + 10)+1;
}
int main() {
	int st, fi;
	cin >> st >> fi;
	cout << remote(st - fi);
}
