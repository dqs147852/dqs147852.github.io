#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, s, u, v, w;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;

struct node {
	int to, w, next;
} edge[5000000];
int first[100000];

inline void add( int u, int v, int w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = first[u];
	first[u] = cnt;
}
int dis[100005];
int visit[1000005];

int main() {
	cin >> n >> m >> s;
	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for (int i = 1 ; i <= n ; i++ )
		dis[i] = INT_MAX;
	dis[s] = 0;
	//ÓÅ»¯

	que.push(make_pair(0, s));
	while (!que.empty()) {
		int u = que.top().second;
		que.pop();
		if (visit[u] == 1)
			continue;
		else
			visit[u] = 1;
		for (int i = first[u]; i != 0; i = edge[i].next) {
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].w) {
				dis[v] = dis[u] + edge[i].w;
				que.push(make_pair(dis[v], v));
			}
		}
	}




	//
	for (int i = 1 ; i <= n ; i++)
		cout << dis[i] << " ";
	return 0;
}
