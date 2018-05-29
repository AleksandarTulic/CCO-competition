#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <utility>

using namespace std;

vector<pair<string, string> > graf;
int p=200000000;
vector <char> cesta;

void path(vector <bool> zau, string poc, string kraj, int korak, vector <char> put)
{
    if (poc == kraj)
    {
        if (p > put.size())
        {
            p=put.size();

            if ( cesta.empty() == false ) cesta.erase(cesta.begin(),cesta.begin()+cesta.size());

            for (int i=0;i<p;i++)
                cesta.push_back(put[i]);
        }
        return;
    }

    put.push_back(poc[0]);
    for (int i=0;i<graf.size();i++)
        if ( graf[i].first == poc && zau[i] == false)
        {
            zau[i]=true;

            for (int j=0;j<graf.size();j++)
               if ( graf[i].first == graf[j].second && graf[i].second == graf[j].first ) {zau[j]=true;break;}
            path(zau,graf[i].second,kraj,korak+1,put);
        }
    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;

        graf.push_back({a,b});
        graf.push_back({b,a});
    }

    sort(graf.begin(),graf.end());

    while (m--)
    {
        string a,b;
        cin>>a>>b;
        p=200000000;

        vector <char> put;
        vector <bool> zau(graf.size(),false);
        if (cesta.empty() == false) cesta.erase(cesta.begin(),cesta.begin()+cesta.size());

        path(zau,a,b,0,put);

        cesta.push_back(b[0]);
        for (int i=0;i<cesta.size();i++) cout<<cesta[i];
        cout<<endl;
    }
    return 0;
}
