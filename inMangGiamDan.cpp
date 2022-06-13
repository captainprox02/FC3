#include <iostream>
#include <algorithm>
using namespace std;

//(O(nlgn))!

void solution2(int a[], int n)
{
    cout<<"\n Noi dung day giam dan : "<<endl;
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}

int main()
{
    int a[] = {3,2,7,6,9,8,5};
    solution2(a,7);
}