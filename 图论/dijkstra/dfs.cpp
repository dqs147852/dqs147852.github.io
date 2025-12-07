#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[25][25], u, v, w, mmax = INT_MIN, visit[25], sum;

inline void dfs(ll x) {
	for (ll i = 1 ; i <= n ; i++) {
		if ( a[x][i] != 0 && visit[i] == 0) {
			visit[i] = 1;
			sum += a[x][i];
			mmax = max(mmax, sum);
			dfs(i);
			visit[i] = 0;
			sum -= a[x][i];
		}
	}
}

int main() {
	cin >> n >> m ;
	while (m--) {
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = w;
	}


	for (ll i = 1 ; i <= n ; i++) {
		memset(visit, 0, sizeof(visit));
		visit[i] = 1;
		sum = 0;
		dfs(i);
	}
	cout << mmax;
	return 0;
}