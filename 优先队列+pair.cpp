#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
//���ȶ��� ���pair ---->����pair�е�first��������
int main() {
	que.push(make_pair(1, 3));
	que.push(make_pair(5, 5));
	que.push(make_pair(4, 8));
	cout << que.top().first << " " << que.top().second << "\n";
	que.pop();
	cout << que.top().first << " " << que.top().second << "\n";
	que.pop();
	cout << que.top().first << " " << que.top().second << "\n";
	que.pop();
}