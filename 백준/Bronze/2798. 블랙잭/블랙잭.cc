#include<iostream>
using namespace std;
int n, m, a[110], res, cnt;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				cnt = a[i] + a[j] + a[k];
				if (cnt <= m && cnt > res) res = cnt;
			}
		}
	}

	cout << res;
}