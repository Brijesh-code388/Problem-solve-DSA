#include <bits/stdc++.h>
using namespace std;


int32_t main()
{

    int t;
    cin >> t;
    int a[5];
    while (t--)
    {
        int k;int sum=0;int min;
        cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
        min=a[0];
        for(int i=0;i<3;i++){
          if(a[i]<min){
              min=a[i];
              k=i;
          }
        }
        for(int i=0;i<3;i++){
            if(i!=k){
               sum=sum+a[i];
            } 
        }
        if(a[k]<=a[4]){
            if(sum<=a[3]){
                cout<<"YES";
            }else{
                cout<<"NO";
            }
        }else{
            cout<<"NO";  
        }


    }
    return 0;
}