
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

    int t;
    int n,a,b;
    cin >> t;
    
    

    while (t--)
    {
        int n,a,b;
        int zero=0,one=0;
        int sum=0;
        string s;

        cin>>n>>a>>b;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero+=1;
            }
            if(s[i]=='1'){
                one+=1;
            }
        }
        sum=zero*a+one*b;
        cout<<sum<<endl;
    }
    return 0;
}