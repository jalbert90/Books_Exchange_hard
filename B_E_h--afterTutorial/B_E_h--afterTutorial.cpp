#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> p(n), ans(n);

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		--p[i];
	}

	for (int i = 0; i < n; i++) {
		if (!ans[i]) {
			vector<int> cur;
			int cnt = 0;

			while (!ans[i]) {
				cur.push_back(i);
				cnt++;
				ans[i]++;
				i = p[i];
			}

			for (auto el : cur) {
				ans[el] = cur.size();
			}
		}
	}

	for (auto el : ans) {
		cout << el << " ";
	}
}

int main() {
	int q;
	cin >> q;

	for (;q--;) {
		solve();
		cout << endl;
	}
}