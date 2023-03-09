#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ull unsigned long long
#define iter set<int>::iterator
#define iter1 set<int>::iterator
#define y1 ajsdkflhasdkf
using namespace std;

const int N=1e6+7;
const int inf=1e9+1e9;
const int mod=1e9+7;
//const ld eps=1e-9;


ld eps,a,b;

ld F(ld x)
{
    return x*x*x-7*x-6;
}

ld phi(ld x)
{
    return (x*x*x-6)/7.0;
}

ld phiDerivative(ld x)
{
    return 3*x*x/7.0;
}

void error()
{
    cout<<"The conditions of the theorem are not satisfied"<<endl;
    exit(0);
}

int main ()
{
    cout<<fixed<<setprecision(5);
    cout<<"Enter needed precision: ";
    cin>>eps;
    ld a=-1.1,b=1.1;
    ld q=0.6;
    ld x0=-0.5;
    ld S=1.6;
    if (q<fabs(phiDerivative(b)) || q<fabs(phiDerivative(a)))error();
    if (fabs(phi(x0)-x0)>(1-q)*S)error();
    int n0 = floor(log(fabs(phi(x0)-x0)/((1-q)*eps))/log(1/q))+1;
    cout<<"The conditions of the theorem are satisfied"<<endl;
    cout<<"The a priori number of operations is "<<n0<<endl;
    int cnt = 0 ;
    ld xPrev = -inf ;
    ld xNext = x0;
    for (int i=0;;++i){
        cout<<i+1<<" value of x is "<<xNext<<". "<<"Function value is "<<F(xNext)<<endl;
        if (fabs(xNext-xPrev)<eps/2){
            cout<<"Required accuracy achieved"<<endl;
            break;
        }
        ++cnt;
        xPrev=xNext;
        xNext = phi(xPrev);
    }
    cout<<"Actual number of operations is "<<cnt<<endl;
    cout<<"Result x value is "<<xNext<<". "<<"Function value is "<<F(xNext)<<endl;
}
//ывлодр
//10 1
//cbcccaacaa
//7 8
