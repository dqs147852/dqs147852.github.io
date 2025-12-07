#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
#define ld long double
#define ch char
typedef unsigned long long ull;
int n, k;
int a[1000005];
deque <int> que, que1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	//µÝÔö
	for (int i = 1 ; i <= n ; i++) {

		if (!que.empty() && que.front() < i - k + 1)
			que.pop_front();
		while (!que.empty() && a[que.back()] >= a[i])
			que.pop_back();
		que.push_back(i);
		if (i >= k)
			cout << a[que.front()] << " ";
	}
	que = que1;
	cout << "\n";
	//µÝ¼õ
	for (int i = 1 ; i <= n ; i++) {

		if (!que.empty() && que.front() < i - k + 1)
			que.pop_front();
		while (!que.empty() && a[que.back()] <= a[i])
			que.pop_back();
		que.push_back(i);
		if (i >= k)
			cout << a[que.front()] << " ";
	}

	return 0;
}
