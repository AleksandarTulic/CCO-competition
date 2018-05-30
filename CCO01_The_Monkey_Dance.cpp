#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int broj_koraka(pair <int, int> A[], int n, int broj)
{
    int kor=0;

    int prov=broj;
    while (kor<2000000000)
    {
        for (int i=0;i<n;i++)
            if ( A[i].first == broj ) { broj=A[i].second; kor++; break; }

        if ( broj == prov ) return kor;
    }

    return 0;
}

unsigned long long nzd(unsigned long long a, unsigned long long b)
{
    if ( a == 0 ) return b;
    return nzd(b%a,a);
}

unsigned long long nzs(unsigned long long a, unsigned long long b) { return (a*b)/nzd(a,b); }

int main()
{
    int n;
    cin>>n;

    while (n!=0)
    {
        pair <int, int> A[n];

        for (int i=0;i<n;i++) cin>>A[i].first>>A[i].second;

        vector <unsigned long long> broj;

        for (int i=1;i<=n;i++)
        {
            bool prov=false;
            for (int j=0;j<n;j++)
            if ( i == A[j].first ) {prov=true;break;}

            if ( prov )
            {
                int a=broj_koraka(A,n,i);

                if ( a != 0 ) broj.push_back(a);
            }
        }

        if ( broj.size() == 1 ) cout<<broj[0]<<endl;
        else
        {
            unsigned long long a=nzs(broj[0],broj[1]);

            for (int i=2;i<broj.size();i++) a=nzs(a,broj[i]);

            cout<<a<<endl;
        }
        cin>>n;
    }
    return 0;
}
