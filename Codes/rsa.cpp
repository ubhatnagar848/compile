#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int pr(int a,int b,int m)
{
 int res=1;
 a=a%m;
 while(b>0)
 {
 if(b & 1)
 {
 res=(res*a)%m;
 }
 a=(a*a)%m;
 b=b/2;
 }
 return res;
}
int main()
{
 int p,q;
 cout<<"Enter p: ";
 cin>>p;
 cout<<"Enter q: ";
 cin>>q;
 if(p==-1 || q==-1)
 {
 p=61;
 q=53;
 }
 int e,d,n;
 int phi=(p-1)*(q-1);
 n=p*q;
 for(e=2;e<phi;e++)
 {
 if (__gcd(e,phi)==1)
 {
 break;
 }
 }
 for(d=2;d<phi;d++)
 {
 if((e*d)%phi==1)
 {
 break;
 }
 }
 cout<<"\nPublic Key: ("<<e<<", "<<n<<")\n";
 cout<<"Private Key: ("<<d<<", "<<n<<")\n";
 cin.ignore();
 string name;
 cout<<"\nEnter Input (P): ";
 getline(cin,name);
 vector<int> encrypted;
 cout<<"\nASCII Values: ";
 for(char ch:name)
 {
 cout<<(int)ch<<" ";
 }
 cout<<"\n\nCipher Text (C): ";
 for(char ch:name)
 {
 int ascii=(int)ch;
 int cipher=pr(ascii,e,n);
 encrypted.push_back(cipher);
 cout<<cipher<<" ";
 }
 cout<<"\n\nDecrypted: ";
 for(int cipher:encrypted)
 {
 int decrypted=pr(cipher, d, n);
 cout<<(char)decrypted;
 }
} 
