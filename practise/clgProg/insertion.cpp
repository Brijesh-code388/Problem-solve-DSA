#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[],int n)
{
    clock_t start_t,end_t,total_t;
   
 int i,j,temp;
 start_t = clock();
 printf("starting time ,start_t =%ld\n",start_t);
 for(i=1;i<n;i++)
 {
     temp=a[i];
     j=i-1;
     while(j>=0 && a[j]>temp)
     {
         a[j+1]=a[j];
         j--;
     }
     a[j+1]=temp;
 }
 end_t = clock();
printf("ending time,end_t = %ld\n",end_t);

total_t =end_t-start_t;
printf("total time taken by CPU :%ld\n",total_t);
}


int main()
{

int n,i;
printf("Enter how many number of element insert into array:");
scanf("%d",&n);
printf("\n");

int a[n];
int b=0;
for(i=n;i<0;i--)
{
     a[b]=i;
     b++;
    //a[i]=rand();
}


insertionSort(a,n);


/*int d;
printf("Sorted Array:\n");

for(d=0;d<n;d++)
{
    printf("            %d",a[d]);
    printf("\n");
}*/
return 0;
}

