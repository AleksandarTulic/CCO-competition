#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int n;
vector <vector <char> > m(27);
pair <char, char> niz[100001];
map <char, bool> flag;
int br = 0;

bool check(char ele, char poz)
{
    for (int i=0;i<m[poz - 'A'].size();i++)
        if ( ele == m[poz - 'A'][i] ) return false;
    return true;
}

int main()
{
    cin>>n;

    string g;
    getline(cin, g, '\n');

    while (n--)
    {
        getline(cin,g,'\n');
        if ( g[g.size()-1] >= 'A' && g[g.size()-1] <= 'Z' ) niz[br++] = {g[0], g[g.size()-1]};
        else m[g[0] - 'A'].push_back(g[g.size()-1]);

        flag[g[0]] = true;
    }

    bool nako = true;
    while (1)
    {
        nako = true;
        for (int i=0;i<br;i++)
            for (int j=0;j<m[niz[i].second - 'A'].size();j++)
                if ( check(m[niz[i].second - 'A'][j], niz[i].first) )
                {
                    nako = false;
                    m[niz[i].first - 'A'].push_back(m[niz[i].second - 'A'][j]);
                }

        if ( nako ) break;
    }

    for (int i=0;i<=26;i++)
    {
        sort(m[i].begin(), m[i].end());
        if ( flag[i+'A'] ) cout<<(char)(i+'A')<<" = {";
        for (int j=0;j<m[i].size();j++)
            if ( j == m[i].size() - 1 ) cout<<m[i][j];
            else cout<<m[i][j]<<",";
        if ( flag[i+'A'] ) cout<<"}"<<endl;
    }
    return 0;
}
