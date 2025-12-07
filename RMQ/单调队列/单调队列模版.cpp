deque<int> que;//存储下标

for (int i = 0; i < n; i++) {
//1.先处理边界:移除越界的队首元素
	while (!que.empty() and que.front() < i - k + 1)
		que.pop_front();
//2.再维护单调性:从队尾移除破坏单调性的元素
	while (!que.empty() and a[que.back()] <= a[i])
		que.pop_back();// 求最大值用<=，最小值用>=
//3.加入当前元素
	que.push_back(i);
//4.记录结果(窗口形成后)
	if (i >= k)
		cout << a[ que.front()] << "";
}