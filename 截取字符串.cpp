#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	s = "1101010";
	//��ȡ�ַ���   �棺s.substr(����±�,��ȡ����);
	//��ȡ�ַ���   �棺s.substr(����±�);----�����ص�����
	cout << s << "\n";
	cout << s.substr(2) << "\n";//
	cout << s.substr(0, 3) << "\n";
	cout << 9 / 10;
	return 0;
}