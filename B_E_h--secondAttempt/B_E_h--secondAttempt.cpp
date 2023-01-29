#include <iostream>
#include <vector>

using namespace std;

void visit(const int* p, int& days, vector<int>& visited, int whoToVisit, int kid) {
	visited.push_back(whoToVisit);
	if (p[whoToVisit] == kid) {
		return;
	}
	days++;
	visit(p, days, visited, p[whoToVisit], kid);
}

void solution() {
	int n, days = 1;
	cin >> n;

	vector<int> d(n + 1, 0);
	int* p = new int[n + 1];
	p[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		days = 1;
		vector<int> visited;
		if (d[i] == 0) {
			visit(p, days, visited, i, i);
			for (auto r : visited) {
				d[r] = days;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
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