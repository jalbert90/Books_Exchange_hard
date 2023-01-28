#include <iostream>

using namespace std;

void visit(const int* p, int& days, int i, int kid) {
	if (p[i] == kid) return;
	days++;
	visit(p, days, p[i], kid);
}

void solution() {
	int n, days = 1;
	cin >> n;

	int* p = new int[n + 1];
	p[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		days = 1;
		visit(p, days, i, i);
		cout << days << " ";
	}

	delete[] p;
}

int main() {
	int q;
	cin >> q;

	while (q--) {
		solution();
		cout << endl;
	}
}