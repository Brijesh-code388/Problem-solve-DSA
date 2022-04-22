#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
 void MergeSort(int[],int ,int,int);
 void Merge( int[],int ,int);

 

int main()
{
    int n,i,p,s;
    printf("Enter how many number of element insert into array:");
    scanf("%d",&n);
    printf("\n");

 

    int a[n];

 

for(i=0;i<n;i++)
{
    scanf("%d",&a[i]);

 

}
printf("Given array is \n");
for(i=0;i<n;i++)
{
    printf("%d ",a[i]);
}

 


MergeSort(a,0,n-1);

 

printf("\nSorted array is \n");
for(i=0;i<n;i++)
{
    printf("%d ",a[i]);
}

 return 0;

}

 

void MergeSort(int a[],int p,int s)
{
    if(p<s)
    {
        int q = p+(s-p)/2;
        MergeSort(a,p,q);
        MergeSort(a,q+1,s);
        Merge(a,p,q,s);
    }

 

}

 

void Merge(int a[],int p,int q,int s)
{
    int i,j,k;
    int n1 = q-p+1;
    int n2 = s-q;
    int L[n1],R[n2];

 

    for(i=0;i<n1;i++)
    {
        L[i]=a[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=a[q+1+j];
    }

 

    i=0;
    j=0;
    k=1;

 

    while(i < n1 && j < n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
           a[k]=R[j];
           j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}