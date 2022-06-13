#include <iostream>
using namespace std;

//O(n3)

void sol1(int *a, int n)
{
    int smax = a[0], d = 0, c = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int s = 0;
            for (int k = i; k <= j; k++)
                s = s + a[k];
            if (s > smax)
            {
                smax = s;
                d = i;
                c = j;
            }
        }
    cout << "\n Doan con co tong lon nhat la " << smax << "\n";
    for (int k = d; k <= c; k++)
        cout << " " << a[k];
}

int maxSubArraySum(int a[], int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];
    for (int i = 1; i < size; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main()
{
    int a[13] = {2, 7, -10, 4, 6, -5, 4, 2, -6, 7, -8, 1, 2};
    int n = 13;
    sol1(a, n);
}