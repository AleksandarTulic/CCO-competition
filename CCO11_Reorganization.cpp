#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int d;
    cin>>d;

    map <int, int> m;
    m[d]=0;

    set <pair <int, int> > s;
    std::set <pair <int, int> >::iterator poz;
    s.insert({d,0});
    bool flag = true;

    for (int i=1;i<n;i++)
    {
        cin>>d;

        poz=s.lower_bound({d,i});
        if ( poz == s.begin() ) flag = false;

        m[(--poz)->first]++;
        if ( m[poz->first] == 2 ) s.erase(poz);

        s.insert({d,i});
    }

    if ( flag ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
