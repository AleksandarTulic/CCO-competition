#include <iostream>
#include <vector>
using namespace std;

char m[51][51];

bool direction1(string g, int r, int c)
{
    for (int i=0;i<g.size();i++)
        if (g[i]!=m[r][c]) return false;
        else c++;
    return true;
}

bool direction2(string g, int r, int c)
{
    for (int i=0;i<g.size();i++)
        if (g[i]!=m[r][c]) return false;
        else r++;
    return true;
}

bool direction3(string g, int r, int c)
{
    for (int i=0;i<g.size();i++)
        if (g[i]!=m[r][c]) return false;
        else r--;
    return true;
}

bool direction4(string g, int r, int c)
{
    for (int i=0;i<g.size();i++)
        if (g[i]!=m[r][c]) return false;
        else c--;
    return true;
}

bool direction5(string g, int r, int c)
{
    for (int i=0;i<g.size();i++)
        if (g[i]!=m[r][c]) return false;
        else c++,r++;
    return true;
}

bool direction6(string g, int r, int c)
{
    for (int i=0;i<g.size();i++)
        if (g[i]!=m[r][c]) return false;
        else c--,r--;
    return true;
}

bool direction7(string g, int r, int c)
{
    for (int i=0;i<g.size();i++)
        if (g[i]!=m[r][c]) return false;
        else c--,r++;
    return true;
}

bool direction8(string g, int r, int c)
{
    for (int i=0;i<g.size();i++)
        if (g[i]!=m[r][c]) return false;
        else c++,r--;
    return true;
}

void find_word(string g, int r, int c)
{
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            if (direction1(g,i,j)) {cout<<i+1<<" "<<j+1<<endl;return;}
            else if (direction2(g,i,j)) {cout<<i+1<<" "<<j+1<<endl;return;}
            else if (direction3(g,i,j)) {cout<<i+1<<" "<<j+1<<endl;return;}
            else if (direction4(g,i,j)) {cout<<i+1<<" "<<j+1<<endl;return;}
            else if (direction5(g,i,j)) {cout<<i+1<<" "<<j+1<<endl;return;}
            else if (direction6(g,i,j)) {cout<<i+1<<" "<<j+1<<endl;return;}
            else if (direction7(g,i,j)) {cout<<i+1<<" "<<j+1<<endl;return;}
            else if (direction8(g,i,j)) {cout<<i+1<<" "<<j+1<<endl;return;}
    return;
}

int main()
{
    int tests;
    cin>>tests;

    while (tests--)
    {
        int r,c;
        cin>>r>>c;

        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
            {
                cin>>m[i][j];
                if (islower(m[i][j])) m[i][j]=toupper(m[i][j]);
            }

        int n;
        cin>>n;

        string g;
        getline(cin,g,'\n');

        while (n--)
        {
            getline(cin,g,'\n');

            string t="";
            for (int i=0;i<g.size();i++)
                if (islower(g[i])) t+=toupper(g[i]);
                else t+=g[i];

            find_word(t,r,c);
        }

        cout<<endl;
    }
    return 0;
}
