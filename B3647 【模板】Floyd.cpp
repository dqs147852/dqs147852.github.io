#include <bits/stdc++.h>
using namespace std;

long long u, v, w;
long long n, m;
long long a[1000][1000];

int main() {
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			if (i != j)
				a[i][j] = INT_MAX;
		}
	}
	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v >> w;
		a[u][v] = min(a[u][v], w);
		a[v][u] = min(a[u][v], w);
	}
	for (int k = 1 ; k <= n ; k++) {//¹ý¶Éµã
		for (int i = 1 ; i <= n ; i++) {//start
			for (int j = 1 ; j <= n ; j++) {//end
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}