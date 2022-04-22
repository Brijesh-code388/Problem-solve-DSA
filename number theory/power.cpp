#include <bits/stdc++.h>
using namespace std;

long long int power(long long int a, long long int n)
{
	long long int ans = 1;
	while (n)
	{
		if (n % 2 == 1)
		{
			ans = ans * a;
			n--;
		}
		else
		{
			a = a * a;
			n = n / 2;
		}
	}
	return ans;
}

int main()
{
	long long int a, n;
	cin >> a >> n;
	cout << power(a, n);
	return 0;
}

//complexity lon n