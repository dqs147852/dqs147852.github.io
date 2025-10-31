#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, step;
};
int n, m, sx, sy, ex, ey;
int a[1005][1005];
int book[1005][1005];
queue<node> que;
node t;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> sx >> sy >> ex >> ey;
	t = {sx, sy, 0};
	book[sx][sy] = 1;
	que.push(t);
	while (!que.empty()) {
		for (int i = 0 ; i < 4 ; i++) {
			int newx = que.front().x + dx[i];
			int newy = que.front().y + dy[i];
			if (a[newx][newy] == 0 && newx >= 1 && newx <= n && newy >= 1 && newy <= m && book[newx][newy] == 0) {
				t = {newx, newy, que.front().step + 1};
				que.push(t);
				book[newx][newy] = 1;
				if (newx == ex && newy == ey) {
					cout << t.step;
					return 0;
				}

			}
		}
		que.pop();
	}
}
