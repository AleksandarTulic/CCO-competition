#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string>
using namespace std;

int n;
char t[2001][2001];
int DP[2001][2001];

int main()
{
    cin>>n;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            cin>>t[i][j];
            if (t[i][j]=='.') DP[i][j]=0;
            else DP[i][j]=1;
        }

    for (int i=n-1;i>=0;i--)
        for (int j=0;j<n;j++)
            if (t[i][j]=='#' && t[i+1][j]=='#') DP[i][j]=min(DP[i+1][j+1],DP[i+1][j-1])+1;

    int suma=0;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            suma+=DP[i][j];

    cout<<suma<<endl;
    return 0;
}
