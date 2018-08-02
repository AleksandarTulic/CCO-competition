#include <iostream>

using namespace std;

int pretvori(string n)
{
    int br=1;

    if (n.size()==2)
    {
        br=10;
    }

    int s=0;

    for (int i=0;i<n.size();i++)
    {
        int e=n[i]-48;
        s+=br*e;
        br/=10;
    }

    return s;
}

int main()
{
    int n;

    int T[18][3];

    cin>>n;

    string a1,a2;

    int m[100][3];

    for (int i=0;i<18;i++)
    {
        for (int j=0;j<=2;j++)
        {
            m[i][j]=1;
        }
    }

    string ispis="NISTA",is;

    for (int i=0;i<n;i++)
    {
        cin>>a1;
        
        cin>>a2;

        string g2;
        char d2=a2[a2.size()-1];
        int b2;

        for (int j=0;j<a2.size();j++)
        {
            if (!isalpha(a2[j]))
            {
                g2+=a2[j];
            }
        }

        b2=pretvori(g2)-1;

        if (d2=='A') m[b2][0]=1;
        else if (d2=='B') m[b2][1]=1;
        else m[b2][2]=1;
        
        int b1;

        string g1;

        for (int j=0;j<a1.size();j++)
        {
            if (!isalpha(a1[j]))
            {
                g1+=a1[j];
            }
        }

        b1=pretvori(g1)-1;

        char d1=a1[a1.size()-1];

        if (d1=='A') m[b1][0]=0;
        else if (d1=='B') m[b1][1]=0;
        else m[b1][2]=0;

        if (m[b1][0]+m[b1][1]+m[b1][2]<=1 && !m[b1][1] && ispis=="NISTA")
        {
            ispis="The tower collapses after removing ";
            is=a1;
        }
        
    }

    if (ispis=="NISTA") cout<<"The tower never collapses"<<endl;
    else cout<<ispis<<is<<endl;

    return 0;
}
