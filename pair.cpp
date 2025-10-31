#include <bits/stdc++.h>
using namespace std;
pair<string, int> p;

int main() {
	cin >> p.first >> p.second;
	p = make_pair("jb", 1);
	cout << "Fruit:" << p.first << "\n";
	cout << "Count:" << p.second << "\n";
	//pair一对
	//1.创建
	//根据题已安排pair<int,string> p;
	//2.赋值
	//①cin >> p.first >> p.second;
	//②p.frist=??
	//③p = make_pair(？, ?);--always
}