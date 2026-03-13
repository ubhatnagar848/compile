#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int key[10];
    int keySize;

    cout << "Enter the message: ";
    getline(cin, text);

    cout << "Enter key size: ";
    cin >> keySize;

    cout << "Enter the key numbers:\n";
    for (int i = 0; i < keySize; i++) {
        cin >> key[i];
    }

    int length = text.length();
    int rows = (length + keySize - 1) / keySize;

    char matrix[100][100];
    int index = 0;

    // Fill the matrix row-wise
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keySize; j++) {
            if (index < length) {
                matrix[i][j] = text[index];
                index++;
            } else {
                matrix[i][j] = 'X'; // padding
            }
        }
    }

    // Read columns based on key order
    cout << "Encrypted text: ";
    for (int k = 1; k <= keySize; k++) {
        for (int j = 0; j < keySize; j++) {
            if (key[j] == k) {
                for (int i = 0; i < rows; i++) {
                    cout << matrix[i][j];
                }
            }
        }
    }

    return 0;
}
