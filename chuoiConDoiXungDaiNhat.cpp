#include <iostream>
using namespace std;
string S;
int dx_dp(int n)
{
    int **a;
    a = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = new int[n + 1];
    for (int i = 1; i <= n; i++)
        a[i][i] = 1;
    for (int i = n - 1; i > 0; i--)
        for (int j = i + 1; j <= n; j++)
            if (S[i - 1] == S[j - 1])
                a[i][j] = 2 + a[i + 1][j - 1];
            else
                a[i][j] = max(a[i + 1][j], a[i][j - 1]);
    
    for(int i = 0; i< n - 1 ; i++){
        cout<<endl;
        for(int j = i ; j< n; j++){
            cout << a[i][j] << " ";
        }
    }

    cout<<endl;
    return a[1][n];
}

int main(){
    S = "AXBNX";
    int n = S.length();
    cout << dx_dp(n) << endl;
}