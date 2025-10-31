#include <bits/stdc++.h>
using namespace std;
int father[100005];
int n, m, a, b, t;

inline int find(int x) {
	if (father[x] == x) {
		return x;
	} else {
		father[x] = find(father[x]);
		return father[x];
	}

}

inline void merge(int i, int j) {
	father[find(j)] = find(i);
	return ;
}

int main() {
	
}
