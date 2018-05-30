#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>

using namespace std;

struct point{ int x,y; };

bool orjentacija(point a, point b, point c)
{
    if ( ((b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y)) < 0 ) return true;
    return false;
}

int main()
{
    int n;
    cin>>n;

    point ko[n];
    for (int i=0;i<n;i++) cin>>ko[i].x>>ko[i].y;

    int left = 0;
    for (int i=1;i<n;i++)
        if ( ko[left].x > ko[i].x ) left=i;
    int p = left,q;
    vector <point> w;

    do
    {
        q=(p+1)%n;
        for (int i=0;i<n;i++)
            if (orjentacija(ko[p],ko[i],ko[q])) q=i;

        w.push_back({ko[p].x,ko[p].y});
        p=q;
    }while (p!=left);

    int pov = 0;
    int j=w.size()-1;
    for (int i=0;i<w.size();i++)
    {
        pov+=(w[j].x + w[i].x)*(w[j].y - w[i].y);
        j=i;
    }

    cout<<abs(pov/100)<<endl;
    return 0;
}
