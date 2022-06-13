#include<iostream>
using namespace std;
long long ck(int m,int n){

    if(m==0&&n==0)
            return 0;
    else
        if(m==0||n==0)
            return 1;
        else return ck(m,n-1)+ck(m-1,n);
}

int main()
{
    
    int m=4,n=2;
    long long kq = ck(m,n);
    cout <<"\nSo cach di tren luoi: "<<m<<",n"<<n<<"la:"<<kq;

}