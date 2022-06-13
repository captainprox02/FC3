#include <bits/stdc++.h>
using namespace std;
string X, Y;

void LCS(int m, int n)
{
    int **a;
    a = new int *[m + 1];
    for (int i = 0; i <= m; i++)
        a[i] = new int[n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            a[i][j] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (X[i - 1] == Y[j - 1])
                a[i][j] = 1 + a[i - 1][j - 1];
            else
                a[i][j] = max(a[i][j - 1], a[i - 1][j]);

    for (int i = 0; i <= n; i++)
    {
        cout<<endl;
        for (int j = 0; j <= m; j++){
            cout << a[i][j] << " ";
        }
    }
}

int main()
{
    X = "AXBNX";
    Y = "AXBNX";
    int m = X.length();
    int n = Y.length();
    long t1, t2, kq;
    LCS(m, n);
}