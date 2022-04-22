
#include <bits/stdc++.h>
using namespace std;
#define mode 1000000007
#define ll long long int


int32_t main()
{

    int t;
    cin >> t;
  
   
    while (t--)
    {       
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++){
           cin>>a[i];
       }
       int odd=0,even=0;
       for(int i=0;i<n;i++){
           if(a[i]%2==0){
               even+=1;
           }else{
               odd+=1;
           }
       }
       if(n%2==1){
           int x=min(even,n/2+1)+min(odd,n/2);
            cout<<x<<endl;
       }else{
           int y=min(even,n/2)+min(odd,n/2);
            cout<<y<<endl;
       }

    }
    return 0;
}