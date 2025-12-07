#include <bits/stdc++.h>
using namespace std;

long long u, v, w, t, s, e;
long long n, m;
long long a[205][205];

int main() {
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			if (i != j)
				a[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v >> w;
		a[u][v] = min(a[u][v], w);

	}
	for (int k = 1 ; k <= n ; k++) {//¹ý¶Éµã
		for (int i = 1 ; i <= n ; i++) {//start
			for (int j = 1 ; j <= n ; j++) {//end
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> s >> e;
		if (a[s][e] < 0x3f3f3f3f / 2) {
			cout << a[s][e];
		} else {
			cout << "impossible";
		}
		cout << "\n";
	}
}