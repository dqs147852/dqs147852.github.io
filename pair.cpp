#include <bits/stdc++.h>
using namespace std;
pair<string, int> p;

int main() {
	cin >> p.first >> p.second;
	p = make_pair("jb", 1);
	cout << "Fruit:" << p.first << "\n";
	cout << "Count:" << p.second << "\n";
	//pairһ��
	//1.����
	//�������Ѱ���pair<int,string> p;
	//2.��ֵ
	//��cin >> p.first >> p.second;
	//��p.frist=??
	//��p = make_pair(��, ?);--always
}