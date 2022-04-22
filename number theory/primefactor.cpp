#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007
#define endl '\n'

void prime_fact(int n)
{
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			int c = 0;
			while (n % i == 0)
			{
				n = n / i;
				c++;
			}
			cout << i << "^" << c << endl;
		}
	}
	if (n > 1)
	{
		cout << n << "^" << 1 << endl;
	}
}

int main()
{

	int n;
	cin >> n;
	prime_fact(n);
}

// time complexity : root n