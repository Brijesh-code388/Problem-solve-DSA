#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define REP for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;

int prime(int n)
{
	for (int i = 2; i * i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	long long int n;
	cin >> n;
	cout << prime(n);
	return 0;
}

//complexity root n