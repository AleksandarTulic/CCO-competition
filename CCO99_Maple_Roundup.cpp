#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct point{ double x; double y; };

double udaljenost(double x1, double y1, double x2, double y2) { return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }

bool orjentacija(point a, point b, point c)
{
    if ( ((b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y)) < 0 ) return true;
    else return false;
}

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;

        cin>>n;

        point ko[n];

        for (int i=0;i<n;i++) cin>>ko[i].x>>ko[i].y;

        int left=0;
        for (int i=1;i<n;i++)
            if ( ko[left].x > ko[i].x ) left=i;

        vector <point> w;

        int w1=left,w2;
        do
        {
            w2=(w1+1)%n;
            for (int i=0;i<n;i++)
                if ( orjentacija(ko[w1],ko[i],ko[w2]) ) w2=i;

            w.push_back({ko[w1].x,ko[w1].y});
            w1=w2;
        }while (w1!=left);

        double uda=0.0;
        for (int i=0;i<w.size();i++)
        {
            double x1,y1,x2,y2;
            if ( i==(w.size()-1) )
            {
                x1=w[i].x;
                y1=w[i].y;
                x2=w[0].x;
                y2=w[0].y;
            }
            else
            {
                x1=w[i].x;
                y1=w[i].y;
                x2=w[i+1].x;
                y2=w[i+1].y;
            }
            uda+=udaljenost(x1,y1,x2,y2);
        }

        cout<<setprecision(2)<<fixed<<uda<<endl;
    }
    return 0;
}
