#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string P,C,D;
    int K;
    cout << "Enter Plain Text: ";
    getline(cin, P);
    cout << "Enter Key: ";
    cin>>K;
    C = P;
    ///
    cout<<"\nCipher Text: ";
    for(int i=0;i<P.length();i++){
        C[i] = ( P[i] - 'a' + K ) % 26 + 'a';
    }
    for(int i=0;i<P.length();i++){
        cout<<C[i];
    }
    ///
    cout<<"\nDecrypted Text: ";
    for(int i=0;i<P.length();i++){
        D[i] = ( C[i] - 'a' - K ) % 26 + 'a';
    }
    for(int i=0;i<P.length();i++){
        cout<<D[i];
    }
}