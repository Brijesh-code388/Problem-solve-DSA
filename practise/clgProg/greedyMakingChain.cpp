
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int i,n=5;
    float w[n]={10,20,30,40,50};
    float v[n]={20,30,66,40,60};
    int W=100;
    float wet=0;
    float s[n];

    float x[n]={0,0,0,0,0};
    for (int i = 0; i < n; i++)
    {
        s[i]=v[i]/w[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (s[i] < s[j])
            {
                float t=s[j];
                s[j]=s[i];
                s[i]=t;
                t=w[j];
                w[j]=w[i];
                w[i]=t;
                t=v[j];
                v[j]=v[i];
                v[i]=t;
                
            }
        }
    }
    for(int i=0;i<n;i++){
        if(wet<W){
            if(wet+w[i]<=W){
                x[i]=1;

            }else{
                x[i]=(W-wet)/w[i];
            }
            wet=wet+x[i]*w[i];
        }

    } 
    int sum=0;
    for (int i = 0; i < n; i++)
    {   
        sum+=x[i]*v[i];
    }
    cout<<sum;
    return 0;
}