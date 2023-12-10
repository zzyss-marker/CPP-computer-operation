#include <iostream>
using namespace std;
int main()
{
	int a[4], p;
	cout << "请输入需要加密的数据：" << endl;
	for (int i = 0; i < 4; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cout << a[i];
	for (int i = 0; i < 4; i++)
	{
		a[i] = a[i] + 5;
		a[i] = a[i] % 10;
	}
	p = a[0], a[0] = a[3], a[3] = p;
	p = a[1], a[1] = a[2], a[2] = p;
	cout << "加密后为：";
	for (int i = 0; i < 4; i++)
		cout << a[i];
	return 0;
}
