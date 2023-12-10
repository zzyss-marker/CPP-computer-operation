#include<iostream>
using namespace std;
bool isprime(int a)
{
	for (int i = 2; i <= a / 2; i++)
	{
		if (a % i == 0)
			return false;
		else
			return true;
	}
}
int main()
{
	for (int i = 4; i <= 20; i = i + 2)
		for (int j = 0; j <= i / 2; j++)
			if (isprime(j) && isprime(i - j))
				cout << i << "=" << j << "+" << i - j << endl;
	return 0;
}
