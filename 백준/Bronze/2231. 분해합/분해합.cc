#include<iostream>
using namespace std;
int n, cnt, sum;
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cnt = i;
		sum = cnt;
		while (cnt) {
			sum += (cnt % 10);
			cnt /= 10;
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
	return 0;
}