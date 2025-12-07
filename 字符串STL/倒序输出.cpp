#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	cin >> s;
	//直接将原来的变
	reverse( s.begin(), s.end() );
	cout << s;
	return 0;
}