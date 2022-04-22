//now we have fix size of bag 
//WE HAVE N TYPE OF ITEM (HAS ITS OWN WAIGHT AND VALUE) AND WE HAVE TO SELECT THE ITEM SUCH THAT WE HAVE MAX BENIFIT BY VALUE

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    int val[n];
    int wt;

    memset(arr, -1, sizeof(arr));
    memset(val, -1, sizeof(val));

    cout<<"Add waight and value"<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cin>>val[i];
    }

    cout<<"add max waight";
    cin>>wt;

    int dp[n+1][wt+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<wt+1;j++)
        {
            dp[i][j]=-1;
        }
    }

    //print of first
    for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<wt+1;j++)
            {
               cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }       
    cout<<endl;


    for(int j=0;j<wt+1;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }


    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<wt+1;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]= max(val[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
             for(int i=0;i<n+1;i++)
             {
                 for(int j=0;j<wt+1;j++)
                 {
                      cout<<dp[i][j]<<" ";
                 }
                 cout<<endl;
             }
                cout<<endl;
        }
    }


     for(int i=0;i<n+1;i++)
     {
         for(int j=0;j<wt+1;j++)
         {
             cout<<dp[i][j]<<" ";
         }
         cout<<endl;
     }

    cout<< dp[n][wt];
    return 0;
}