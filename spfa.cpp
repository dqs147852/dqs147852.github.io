//https://nazo.one-story.cn/
#include <bits/stdc++.h>
using namespace std;
int dis[1000005], first[1000005];
int n, m, cnt, u, v, w;
bool in[1000005];

struct node {
	int to;//жу╣Ц
	int w;
	int next;
} edge[1000005];

inline void add(int u, int v, int w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = first[u];
	first[u] = cnt;
}
queue<int>que;

inline void spfa(int u) {
	dis[u] = 0;
	que.push(u);
	in[u] = 0;
	while (!que.empty()) {
		u = que.front();
		que.pop();
		in[u] = 0;
		for (int i  = first[u]; i != 0; i = edge[i].next) {
			int v = edge[i].to, w = edge[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!in[v]) {
					que.push(v);
					in[v] = 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		dis[i] = 0x3f3f3f3f;
	}
	while (m--) {
		cin >> u >> v >> w;
		add(u, v, w);

	}
	dis[1] = 0;
	spfa(1);
	cout << dis[n];
}
