//now we have fix size of bag 
//WE HAVE N TYPE OF ITEM (HAS ITS OWN WAIGHT AND VALUE) AND WE HAVE TO SELECT THE ITEM SUCH THAT WE HAVE MAX BENIFIT BY VALUE

#include <bits/stdc++.h>
using namespace std;
int static t[100][1000];
int ks(int [],int [],int,int );

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
    memset(t,-1,sizeof(t));
    for(int j=0;j<wt+1;j++){
        t[0][j]=0;
    }
    for(int i=0;i<n+1;i++){
        t[i][0]=0;
    }
    int x=ks(arr,val,wt,n);

    for(int i=0;i<n+1;i++)
     {
         for(int j=0;j<wt+1;j++)
         {
             cout<<t[i][j]<<" ";
         }
         cout<<endl;
     }
    cout<<endl;


    cout<<x<<endl;
    return 0;
}




    int ks(int wt[],int val[],int w,int n){
        if(n==0||w==0)
        {
            return 0;
        }
        if(t[n][w]!=-1)
        {
            cout<<n<<" "<<w<<endl;
            return t[n][w];
        }
        if(wt[n-1]<=w)
        {
            return t[n][w]=max(val[n-1]+ks(wt,val,w-wt[n-1],n-1),ks(wt,val,w,n-1));
        }
        else if(wt[n-1]>w)
        {
            return t[n][w]=ks(wt,val,w,n-1);
        }
        else
        {
            return 0;
        }
    }