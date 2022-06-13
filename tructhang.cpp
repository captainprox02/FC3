#include <iostream>
using namespace std;
int *kq, *chon, *v; // các mảng
int n, dem = 0;
void khoitao()
{
    n = 4;
    v = new int[n];
    v[0] = 5;
    v[1] = 3;
    v[2] = 1;
    v[3] = 4;
    // v[4] = 6;
    // v[5] = 2;
    // v[6] = 3;
    // v[7] = 9;
    chon = new int[n];
    kq = new int[n];
    for (int j = 0; j < n; j++)
    {   // cout << v[j] << " ";
        chon[j] = kq[j] = 0;
    }
}

void inkq()
{
    cout << "\n Cach thu " << ++dem << " :";
    for (int j = 0; j < n; j++)
        cout << " " << kq[j];
}


void tim(int i, int d)
{
    if (i > n)
        inkq(); // nếu đã đủ hết n bình xăng thì in kq
    else
        for (int j = 0; j < n; j++) // duyệt hết các bình xăng
        {
            if (chon[j] == 0 && v[j] > d)
            // nếu bình xăng chưa được chọn và có thể bay hơn khoảng cách d
            {
                kq[i - 1] = v[j];
                chon[j] = 1; // lấy bình xăng và đánh dấu đã lấy
                tim(i + 1, v[j] - d);
                kq[i - 1] = 0;
                chon[j] = 0;
            }
        }
}


int main()
{

    int d = 2;
    khoitao();
    tim(1, d);
}
