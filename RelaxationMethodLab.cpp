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
    return x*x*x-2*x*x-x+2;
}

ld Derivative(ld x)
{
    return 3*x*x-4*x-1;
}

ld DDerivative(ld x)
{
    return 6*x-4;
}

int signum(ld x)
{
    if(x>0)return 1;
    else return -1;
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
    cout<<"Enter the approximate segment: ";
    cin>>a>>b;
    if (signum(Derivative(a))!=signum(Derivative(b)))error();
    ld m1 = min(fabs(Derivative(a)),fabs(Derivative(b)));
    ld M1 = max(fabs(Derivative(a)),fabs(Derivative(b)));
    ld DDerivativeExtr = (ld)4/6;
    if (a<=DDerivativeExtr && DDerivativeExtr<=b){
        m1=min(m1,fabs(Derivative(DDerivativeExtr)));
        M1=max(M1,fabs(Derivative(DDerivativeExtr)));
    }
    ld t0 = 2/(m1+M1);
    ld q0 =(M1-m1)/(M1+m1);
    ld x0 = (a+b)/2;
    int n0 = floor( (log(max(x0-a,b-x0)/eps))/log(1/q0) )+1;
    cout<<"The conditions of the theorem are satisfied"<<endl;
    cout<<"The a priori number of operations is "<<n0<<endl;
    int cnt = 0 ;
    ld methodSign = - signum(Derivative(a));
    ld xPrev = -inf ;
    ld xNext = x0;
    for (int i=0;;++i){
        cout<<i+1<<" value of x is "<<xNext<<". "<<"Function value is "<<F(xNext)<<endl;
        if (fabs(xNext-xPrev)<eps){
            cout<<"Required accuracy achieved"<<endl;
            break;
        }
        ++cnt;
        xPrev=xNext;
        xNext = xPrev + methodSign*t0*F(xPrev);
    }
    cout<<"Actual number of operations is "<<cnt<<endl;
    cout<<"Result x value is "<<xNext<<". "<<"Function value is "<<F(xNext)<<endl;

}
//ывлодр
//10 1
//cbcccaacaa
//7 8
