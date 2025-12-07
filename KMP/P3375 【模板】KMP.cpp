#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
#define ld long double
#define ch char
typedef unsigned long long ull;
st s1, s2;
int nxt[1000005];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s1 >> s2;
	int i = 0 ;
	for (int j = 2 ; j <= s2.size(); j++) {
		while (i > 0 and s2[i] != s2[j - 1])
			i = nxt[i];
		if (s2[i] == s2[j - 1])
			i++;
		nxt[j] = i;
	}
	i = 0;//匹配成功子串长度
	for (int j = 0 ; j < s1.size(); j++) {
		while (i > 0 and s2[i] != s1[j])
			i = nxt[i];
		if (s2[i] == s1[j])
			i++;
		if (i == s2.size()) {
			ans.push_back(j - i + 1);
			i = nxt[i];
		}
	}
	for (auto t : ans)
		cout << t + 1 << "\n";
	for (int i = 1 ; i <= s2.size(); i++) {
		cout << nxt[i] << " ";
	}
	return 0;
}
