#include <bits/stdc++.h>
using namespace std;

int main() {
	//binary_search 二分查找【确定是否存在】
	//binary_search(a+1,a+n+1,x)
	//返回值是1 代表存在
	//返回值是0 代表不存在
	int a[1005] = {1, 5, 7, 23, 123, 145, 1354, 3466};
	cout << binary_search(a + 0, a + 7 + 1, 114514);
}
