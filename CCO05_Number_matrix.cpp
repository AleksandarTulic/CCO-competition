#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r,c;
int m[101][101];
bool p[101][101];
bool check=false;

void on_false()
{
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        p[i][j]=false;
}

void flood(int x, int y, int a, int b, int d)
{
    if (x>=r || x<0 || y<0 || y>=c) return;
    if (m[x][y]!=a && m[x][y]!=b && m[x][y]!=d) return;
    if (p[x][y]) return;
    if (x==r-1)
    {
        check=true;
        return;
    }

    p[x][y]=true;

    flood(x+1,y,a,b,d);
    flood(x-1,y,a,b,d);
    flood(x,y+1,a,b,d);
    flood(x,y-1,a,b,d);
}

int main()
{
    cin>>c>>r;

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        cin>>m[i][j];

    vector <int> br;

    br.push_back(m[0][0]);

    for (int i=1;i<c;i++)
    {
        bool prov=true;

        for (int j=0;j<br.size();j++)
        if (m[0][i]==br[j]) {prov=false;break;}

        if (prov) br.push_back(m[0][i]);
    }

    sort(br.begin(),br.end());

    int bri=0;

    for (int i=0;i<br.size();i++)
    {
        if (bri==c) break;
        on_false();
        check=false;

        for (int j=0;j<=9;j++)
        {
            for (int k=0;k<=9;k++)
            {

                for (int g=0;g<c;g++)
                {
                    flood(0,g,br[i],j,k);

                if (check)
                {
                    vector <int> broj;
                    broj.push_back(br[i]);
                    broj.push_back(j);
                    broj.push_back(k);

                    sort(broj.begin(),broj.end());

                    for (int i=0;i<broj.size();i++) cout<<broj[i]<<" ";
                    return 0;
                }
                on_false();
                }
                on_false();
            }
            on_false();
        }
        bri++;
    }

    cout<<"-1 -1 -1"<<endl;
    return 0;
}
