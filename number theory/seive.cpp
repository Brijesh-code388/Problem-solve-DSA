#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007
#define endl '\n'

int is_prime[1000001];

void sieve()
{
	int max = 10;
	for (int i = 1; i <= max; i++)
	{
		is_prime[i] = 1;
	}
	is_prime[0] = 1;
	is_prime[1] = 1;
	for (int i = 2; i * i < max; ++i)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= max; j += i)
			{
				is_prime[j] = 0;
			}
		}
	}
}

int main()
{

	sieve();
	for (int i = 1; i <= 10; ++i)
	{
		cout << is_prime[i] << " ";
	}
}