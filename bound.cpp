#include <bits/stdc++.h>
//using namespace std;

int main() {
	//2.lower_bound(a+1,a+n+1,x)-a
	//在有序的序列a中,找到第一个大于等于x的元素的下标

	//3.upper_bound(a+1,a+n+1,x)-a
	//在有序的序列a中,找到第一个大于x的元素的下标

	//技巧:
	//通过upper_bound - lower_bound 得到元素的数量
	int a[1005] = {1, 2, 4, 6, 7, 21, 56, 56, 56, 56, 123, 234, 1232};
	std::cout << std::upper_bound(a + 0, a + 15, 56) - std::lower_bound(a + 0, a + 15, 56);


	return 0;
}
