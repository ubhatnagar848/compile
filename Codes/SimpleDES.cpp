#include <iostream>
using namespace std;

/* Permutation tables */
int P10[10] = {3,5,2,7,4,10,1,9,8,6};
int P8[8]  = {6,3,7,4,8,5,10,9};
int IP[8]  = {2,6,3,1,4,8,5,7};
int IP_INV[8] = {4,1,3,5,7,2,8,6};
int EP[8]  = {4,1,2,3,2,3,4,1};
int P4[4]  = {2,4,3,1};

/* S-Boxes */
int S0[4][4] = {
    {1,0,3,2},
    {3,2,1,0},
    {0,2,1,3},
    {3,1,3,2}
};

int S1[4][4] = {
    {0,1,2,3},
    {2,0,1,3},
    {3,0,1,0},
    {2,1,0,3}
};

/* Function to apply permutation */
void permute(int in[], int out[], int p[], int size) {
    for (int i = 0; i < size; i++) {
        out[i] = in[p[i] - 1];
    }
}

/* Left shift */
void leftShift(int arr[], int size) {
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
}

/* XOR operation */
void XOR(int a[], int b[], int out[], int size) {
    for (int i = 0; i < size; i++) {
        out[i] = a[i] ^ b[i];
    }
}

/* F function */
void fk(int bits[], int key[]) {
    int left[4], right[4], ep[8], xored[8];
    int s0out[2], s1out[2], p4out[4];

    for (int i = 0; i < 4; i++) {
        left[i] = bits[i];
        right[i] = bits[i + 4];
    }

    permute(right, ep, EP, 8);
    XOR(ep, key, xored, 8);

    int row = xored[0] * 2 + xored[3];
    int col = xored[1] * 2 + xored[2];
    int val = S0[row][col];
    s0out[0] = val / 2;
    s0out[1] = val % 2;

    row = xored[4] * 2 + xored[7];
    col = xored[5] * 2 + xored[6];
    val = S1[row][col];
    s1out[0] = val / 2;
    s1out[1] = val % 2;

    int sboxout[4] = {s0out[0], s0out[1], s1out[0], s1out[1]};
    permute(sboxout, p4out, P4, 4);
    XOR(left, p4out, left, 4);

    for (int i = 0; i < 4; i++) {
        bits[i] = left[i];
    }
}

/* Swap function */
void swapBits(int bits[]) {
    for (int i = 0; i < 4; i++) {
        int temp = bits[i];
        bits[i] = bits[i + 4];
        bits[i + 4] = temp;
    }
}

int main() {
    int key[10], plaintext[8];
    int p10[10], left[5], right[5];
    int key1[8], key2[8];
    int ip[8];

    cout << "Enter 10-bit key: ";
    for (int i = 0; i < 10; i++) {
        cin >> key[i];
    }

    cout << "Enter 8-bit plaintext: ";
    for (int i = 0; i < 8; i++) {
        cin >> plaintext[i];
    }

    /* Key generation */
    permute(key, p10, P10, 10);

    for (int i = 0; i < 5; i++) {
        left[i] = p10[i];
        right[i] = p10[i + 5];
    }

    leftShift(left, 5);
    leftShift(right, 5);

    int combined[10];
    for (int i = 0; i < 5; i++) {
        combined[i] = left[i];
        combined[i + 5] = right[i];
    }

    permute(combined, key1, P8, 8);

    leftShift(left, 5);
    leftShift(left, 5);
    leftShift(right, 5);
    leftShift(right, 5);

    for (int i = 0; i < 5; i++) {
        combined[i] = left[i];
        combined[i + 5] = right[i];
    }

    permute(combined, key2, P8, 8);

    /* Encryption */
    permute(plaintext, ip, IP, 8);
    fk(ip, key1);
    swapBits(ip);
    fk(ip, key2);

    int ciphertext[8];
    permute(ip, ciphertext, IP_INV, 8);

    cout << "Ciphertext: ";
    for (int i = 0; i < 8; i++) {
        cout << ciphertext[i];
    }

    return 0;
}
