#include<iostream>
using namespace std;
int n, dt[1010][5], res;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> dt[i][0] >> dt[i][1] >> dt[i][2];

		if (i) {
			dt[i][0] += (dt[i - 1][1] < dt[i - 1][2] ? dt[i - 1][1] : dt[i - 1][2]);
			dt[i][1] += (dt[i - 1][0] < dt[i - 1][2] ? dt[i - 1][0] : dt[i - 1][2]);
			dt[i][2] += (dt[i - 1][0] < dt[i - 1][1] ? dt[i - 1][0] : dt[i - 1][1]);
		}
	}

	res = dt[n - 1][0];
	res = res < dt[n - 1][1] ? res : dt[n - 1][1];
	res = res < dt[n - 1][2] ? res : dt[n - 1][2];

	cout << res;
}