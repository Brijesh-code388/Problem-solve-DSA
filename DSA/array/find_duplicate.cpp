#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

// using set is very easy
// also by sortng we can easyly do it

int find_duplicate(vector<int> &nums)
{
    int dup = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        int c = abs(nums[i]);
        if (nums[c] < 0)
        {
            dup = c;
        }
        nums[c] *= -1;
    }
    for (auto &num : nums)
        num = abs(num);

    return dup;
}
int main()
{
    vector<int> vect{1, 3, 2, 3, 4};
    cout << find_duplicate(vect);
    return 0;
}

