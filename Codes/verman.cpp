#include<iostream>
#include<string>
using namespace std;
int main()
{
    string p,k;
    cout<<"Text: ";
    cin>>p;
    cout<<"Key: ";
    cin>>k;
    string e=p;
    for(int i=0;i<p.length();i++)
    {
        int a=int(p[i])-'A';
        int b=int(k[i])-'A';
        int c=a^b;
        e[i]=char(c+'A');
    }
    cout<<"Encrypted: ";
    cout<<e;
   
}
