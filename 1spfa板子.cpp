#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, s;
int u, v, w, cnt;
int first[1000005], dis[1000005], visit[10000005]; //最新的一条边
queue<int> que;

struct node {
	int to;//终点
	int w;
	int next;
} edge[5000005];

inline void add(int u, int v, int w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = first[u];
	first[u] = cnt;
}

signed main() {
	cin >> n >> m >> s;
	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for (int i = 1 ; i <= n ; i++) {
		dis[i] = INT_MAX;
	}
	dis[s] = 0;
	que.push(s);
	visit[s] = 1;
	while ( !que.empty() ) {
		u = que.front();
		que.pop();
		visit[u] = 0;
		for (int i = first[u] ; i != 0 ; i = edge[i].next) {
			v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].w) {
				dis[v] = dis[u] + edge[i].w;
				if (visit[v] == 0) {
					que.push(v);
					visit[v] = 1;
				}
			}
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << dis[i] << " ";
	}
}