#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
#define ld long double
#define ch char
typedef unsigned long long ull;
st s;
int nxt[10000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int i = 0;
	nxt[0] = 0, nxt[1] = 0;
	for (int j = 2; j <= s.size(); j++) {
		while (i > 0 && s[i] != s[j - 1])
			i = nxt[i];
		if (s[i] == s[j - 1])
			i++;
		nxt[j] = i;

	}

	for (int i = 0 ; i <= s.size(); i++)
		cout << nxt[i] << " ";
	return 0;
}
