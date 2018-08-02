#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

int main()
{
    int n;
    cin>>n;

    set <vector <int> > s;
    for (int i=0;i<n;i++)
    {
        vector <int> ele(6);
        for (int j=0;j<6;j++) cin>>ele[j];

        sort(ele.begin(),ele.end());
        s.insert(ele);
    }

    if ( s.size() != n ) cout<<"Twin snowflakes found."<<endl;
    else cout<<"No two snowflakes are alike."<<endl;
    return 0;
}
