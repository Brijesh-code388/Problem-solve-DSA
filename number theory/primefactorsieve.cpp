#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define mod 1000000007
#define endl '\n'

int arr[1000001];

void sieve(){
	int max=1000000;
	for (int i = 1; i <= max; i++)
	{
		arr[i]=-1;
	}
	for (int i = 2; i <= max; i++)
	{
		if (arr[i]==-1)
		{
			for (int j = i; j <= max; j+=i)
			{
				if (arr[j]==-1)
				{
					arr[j]=i;
				}
			}
		}
	}
}


int main()
{	
	sieve();
	for (int i = 1; i<=100;  i++)
	{
	 	cout<<arr[i]<<endl;
	}
    int a=100;
    cout<<endl;

    while(a && a!=1){
        cout<<arr[a]<<endl;
        a=a/arr[a];
    }

}	