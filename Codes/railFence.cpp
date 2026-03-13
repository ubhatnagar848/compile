#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int rails;

    cout << "Enter the message: ";
    getline(cin, text);

    cout << "Enter number of rails: ";
    cin >> rails;

    // If rails is 1, cipher text is same as input
    if (rails == 1) {
        cout << "Encrypted text: " << text;
        return 0;
    }

    // Create a 2D array and fill with '\n'
    char rail[100][100];

    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < text.length(); j++) {
            rail[i][j] = '\n';
        }
    }

    int row = 0;
    bool down = false;

    // Place characters in zig-zag pattern
    for (int i = 0; i < text.length(); i++) {
        rail[row][i] = text[i];

        if (row == 0 || row == rails - 1) {
            down = !down;
        }

        if (down) {
            row++;
        } else {
            row--;
        }
    }

    // Read the rail array row by row
    cout << "Encrypted text: ";
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < text.length(); j++) {
            if (rail[i][j] != '\n') {
                cout << rail[i][j];
            }
        }
    }

    return 0;
}
