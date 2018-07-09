#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    int m;
    cin>>m;

    double a[m];
    for (int i=0;i<m;i++) cin>>a[i];

    sort(a,a+m);

    for (int q=1;q<=100;q++)
    {
        int br=0;

        for (double i=0;i<m;i++)
        {
            for (double j=0;j<=2000000;j++)
            {
                if ( round(j*100/q) == a[(int)i] ) { br++; break; }
                else if ( round(j*100/q) > a[(int)i] ) { br=-10; break; }
            }

            if ( br==-10 ) break;
        }

        if ( br == m )
        {
            cout<<q<<endl;
            break;
        }
    }
    return 0;
}
