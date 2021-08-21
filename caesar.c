#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 100

void encrypt(char *plaintext) {
    for(int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = toupper(plaintext[i]);
        int temp = plaintext[i] - 'A';
        temp = (temp + 3) % 26;
        plaintext[i] = temp + 'A';
    }    
}

void decrypt(char *ciphertext) {
    for(int i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = toupper(ciphertext[i]);
        int temp = ciphertext[i] - 'A';
        temp = abs((temp - 3) % 26);
        ciphertext[i] = temp + 'A';
    }
}

int main() {
    char plaintext[MAX];

    scanf("%s", plaintext);

    encrypt(plaintext);

    printf("%s\n", plaintext);

    decrypt(plaintext);

    printf("%s\n", plaintext);
    return 0;
}