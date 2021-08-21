#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

void encrypt(char *plaintext, int key) {
    for(int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = toupper(plaintext[i]);
        int temp = plaintext[i] - 'A';
        temp = (temp + key) % 26;
        plaintext[i] = temp + 'A';
    }    
}

void decrypt(char *ciphertext, int key) {
    for(int i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = toupper(ciphertext[i]);
        int temp = ciphertext[i] - 'A';
        temp = abs((temp - key) % 26);
        ciphertext[i] = temp + 'A';
    }
}

int toCharCode(char c) {
    return toupper(c) - 'A';
}

int main() {
    char plaintext[MAX];
    char key;
    printf("Enter the key: ");
    scanf("%c", &key);

    fflush(stdin);
    
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, toCharCode(key));

    printf("encrypted text: %s\n", plaintext);

    decrypt(plaintext, toCharCode(key));

    printf("Original text: %s\n", plaintext);
    return 0;
}