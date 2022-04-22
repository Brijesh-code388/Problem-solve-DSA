
#include <bits/stdc++.h>
using namespace std;
#define mode 1000000007
#define int long long int
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return; //returns recursively
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// UTILITY FUNCTIONS
// Function to print an array

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int32_t main()
{
    time_t start, end;

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    cout << endl;
    time(&start);

    //bubble

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         if (a[i] > a[j])
    //         {
    //             int t = a[i];
    //             a[i] = a[j];
    //             a[j] = t;
    //         }
    //     }
    // }

    //quick
    //quickSort(a, 0, n - 1);

    //mearge
    mergeSort(a, 0, n - 1);

    time(&end);
    double time_taken = double(end - start);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    cout << endl;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl
         << endl;

    return 0;
}