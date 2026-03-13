#include <iostream>
using namespace std;

int main()
{
    string p;
    cout << "Text (UPPERCASE, even length): ";
    cin >> p;

    int key[2][2] = {
        {3, 3},
        {2, 5}
    };

    cout << "Encrypted Text: ";

    for (int i = 0; i < p.length(); i += 2)
    {
        int p1 = p[i]   - 'A';
        int p2 = p[i+1] - 'A';

        int c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        int c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        cout << char(c1 + 'A');
        cout << char(c2 + 'A');
    }

    return 0;
}
