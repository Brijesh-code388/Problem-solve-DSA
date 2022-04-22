
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n=3;
    int N=5;
    int m=999;
    int d[n]={1,2,3};
    //int d[n]={2,4,5};
    int c[n][N+1];
    for(int i=0;i<n;i++)
    {
        c[i][0]=0;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<N+1;j++)
        {   
            if(i==0&&j<d[i]){
                c[i][j]=m;
            } 
            else if(i==0){
                c[i][j]=1+c[0][j-d[i]];
            }
            else if(j<d[i]){
                c[i][j]=c[i-1][j];
            }
            else{
                if(c[i-1][j]<(1+c[i][j-d[i]])){
                    c[i][j]=c[i-1][j];
                }else{
                    c[i][j]=1+c[i][j-d[i]];
                }
                
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<N+1;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=n-1;i>=0;i--){
        if(c[i][N]!=c[i-1][N]){
            if(N%d[i]==0&&N!=0){
                int a=N/d[i];
                cout<<a<<"*"<<d[i]<<endl;
                N=N-d[i]*a;
            }
        }
        //cout<<"i is "<<i<<endl;
    }
    return 0;
}// int d[n]={2,4,5};