#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;

int tests;
int n;
int A[10001];
int B[10001];

bool prime_or_not(int b)
{
    for (int i=2;i<=sqrt(b);i++)
        if (b % i == 0) return false;
    return true;
}

int main()
{
    scanf("%d",&tests);
    while (tests--)
    {
        cin>>n;
        int br=0;
        for (int i=0;i<n;i++)
        {
            cin>>A[i];
            if (A[i]%2==0) br++;
        }

        if (br==n) cout<<"This sequence is anti-primed."<<endl;
        else
        {
            int minn=2000000000;
            for (int i=0;i<n-1;i++)
            {
                int suma=A[i];
                for (int j=i+1;j<n;j++)
                {
                        suma+=A[j];
                        if (prime_or_not(suma) && minn>(j-i+1))
                        {
                            minn=j-i+1;
                            br=0;
                            for (int ii=i;ii<=j;ii++)
                            {
                                B[br]=A[ii];
                                br++;
                            }
                        }
                }
            }
            if (minn==2000000000) cout<<"This sequence is anti-primed."<<endl;
            else
            {
                cout<<"Shortest primed subsequence is length "<<minn<<": ";
                for (int i=0;i<br;i++)
                    cout<<B[i]<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}
