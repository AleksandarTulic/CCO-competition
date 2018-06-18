#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> ele;
    for (int i=1;i<=n;i++) ele.push_back(i);

    int t;
    cin>>t;
    pair <int, int> k[t];
    for (int i=0;i<t;i++) cin>>k[i].first>>k[i].second;

    int br = 0;
    do
    {
        int poz1 = 0;
        int poz2 = 0;
        bool flag = true;

        for (int i=0;i<t;i++)
        {
            for (int j=0;j<ele.size();j++)
            {
                if ( ele[j] == k[i].first ) poz1=j;
                if ( ele[j] == k[i].second ) poz2=j;
            }

            if ( poz1 < poz2 )
            {
                flag=false;
                break;
            }
        }

        if ( flag ) br++;

    }while (next_permutation(ele.begin(),ele.end()));

    cout<<br<<endl;
    return 0;
}
