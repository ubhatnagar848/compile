#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string p;
    string k;
    cout<<"Text: ";
    cin>>p;
    cout<<"Key: ";
    cin>>k;
    int l=k.length();
    int a=0;
    string e=p;
    for(int i=0;i<p.length();i++)
    {
        if(a==l)
        {
            a=0;
        }
        if(isupper(p[i]) && isupper(k[a]))
        {
            e[i]=(char)((((int)(p[i]-'A')+(int)(k[a]-'A'))%26)+'A');
        }
        else if(isupper(p[i]) && islower(k[a]))
        {
            e[i]=(char)((((int)(p[i]-'A')+(int)(k[a]-'a'))%26)+'A');
        }
        else if(islower(p[i]) && isupper(k[a]))
        {
            e[i]=(char)((((int)(p[i]-'a')+(int)(k[a]-'A'))%26)+'a');
        }
        else if(islower(p[i]) && islower(k[a]))
        {
            e[i]=(char)((((int)(p[i]-'a')+(int)(k[a]-'a'))%26)+'a');
        }
        a++;
    }
    cout<<"Encrypted Text: ";
    for(int i=0;i<p.length();i++)
    {
        cout<<e[i];
    }
    a=0;
    string d=e;
    for(int i=0;i<p.length();i++)
    {
        if(a==l)
        {
            a=0;
        }
        if(isupper(e[i]) && isupper(k[a]))
        {
            d[i]=(char)((((int)(e[i]-'A')-(int)(k[a]-'A')+26)%26)+'A');
        }
        else if(isupper(e[i]) && islower(k[a]))
        {
            d[i]=(char)((((int)(e[i]-'A')-(int)(k[a]-'a')+26)%26)+'A');
        }
        else if(islower(e[i]) && isupper(k[a]))
        {
            d[i]=(char)((((int)(e[i]-'a')-(int)(k[a]-'A')+26)%26)+'a');
        }
        else if(islower(e[i]) && islower(k[a]))
        {
            d[i]=(char)((((int)(e[i]-'a')-(int)(k[a]-'a')+26)%26)+'a');
        }
        a++;
    }
    cout<<endl;
    cout<<"Decrypted Text: ";
    for(int i=0;i<p.length();i++)
    {
        cout<<d[i];
    }
}
