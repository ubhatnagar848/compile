#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    cout<<"Text: ";
    cin>>a;
    int i=0;
    char x='x';
    while(i<a.length())
    {
        if(i%2==0 && a[i]==a[i+1])
        {
            a.insert(i+1,1,x);
            i=0;
        }
        i++;
    }
    if(a.length()%2==1)
    {
        a.insert(a.length(),1,x);
    }
    cout<<a;
    string key;
    cout<<"\nKey: ";
    cin>>key;
    int k=0;
    char b[5][5];
    string str="abcdefghiklmnopqrstuvwxyz";
    int c=0;
    int r=0;
    for(int i=0;i<key.length();i++)
    {
        for(int j=0;j<str.length();j++)
        {
            if(key[i]==str[j])
            {
                str.erase(j,1);
                b[r][c]=key[i];
                c++;
                if(c==5)
                {
                    c=0;
                    r++;
                }
            }
        }
    }
    for(int i=r;i<5;i++)
    {
        for(int j=c;j<5;j++)
        {
            b[i][j]=str[0];
            str.erase(0,1);
        }
        c=0;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<a.length();i=i+2)
    {
        char a1=a[i];
        char a2=a[i+1];
        int r1,c1,r2,c2;
        for(int r=0;r<5;r++)
        {
            for(int c=0;c<5;c++)
            {
                if(b[r][c]==a1)
                {
                    r1=r;
                    c1=c;
                }
                if(b[r][c]==a2)
                {
                    r2=r;
                    c2=c;
                }
            }
        }
        if(r1==r2)
        {
            cout<<b[r1][(c1+1)%5];
            cout<<b[r2][(c2+1)%5];
        }
        else if(c1==c2)
        {
            cout<<b[(r1+1)%5][c1];
            cout<<b[(r2+1)%5][c2];
        }
        else
        {
            cout<<b[r1][c2];
            cout<<b[r2][c1];
        }
    }
}
