#include <bits/stdc++.h>
using namespace std;

int main() {
	string s = "wqnmlgdsb";
	//s.replace(起点下标 , 长度 , 子串);
	s.replace( 3, 4, "oh");
	cout << s;
	return 0;
}