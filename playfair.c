#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char matrix[5][5];

int isRepeated(char c) {
    int flag = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(matrix[i][j] == c) {
                flag = 1;
                return flag;
            }
        }
    }
    return flag;
}

void toUpper(char *text) {
    for(int i = 0; i < strlen(text); i++)
        text[i] = toupper(text[i]);
}

void prepareMatrix(char *key) {
    int counter = 0;
    char currentChar = 'A';
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(isRepeated(key[counter]) == 0) {
                matrix[i][j] = key[counter];
                counter++;
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if((matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')) {
                continue;
            } else {
                if(isRepeated(currentChar) == 0) {
                    if(currentChar == 'J') {
                        currentChar++;
                        j--;
                        continue;
                    }
                    matrix[i][j] = currentChar;
                    currentChar++;
                } else {
                    j--;
                    currentChar++;
                }
            }
        }
    }
}

void printMatrix() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void encrypt(char *plaintext, char *key) {
    toUpper(key);
    toUpper(plaintext);
    prepareMatrix(key);

    for(int i = 0; i < strlen(plaintext); i += 2) {
        char pair[] = {plaintext[i], plaintext[i + 1]};

        if(pair[1] == '\0')
            pair[1] = 'X';

        if(pair[0] == pair[1]) {
            pair[1] = 'X';
            i--;
        }

        if(pair[0] == 74)
            pair[0] = 'I';
        if(pair[1] == 74)
            pair[1] = 'I';

        int firstCharIndex[2];
        int secondCharIndex[2];

        for(int i = 0; i <  5; i++) {
            for(int j = 0; j < 5; j++) {
                if(matrix[i][j] == pair[0])  {
                    firstCharIndex[0] = i;
                    firstCharIndex[1] = j;
                } else if(matrix[i][j] == pair[1]) {
                    secondCharIndex[0] = i;
                    secondCharIndex[1] = j;
                }
            }
        }

        if(firstCharIndex[0] == secondCharIndex[0]) {
            firstCharIndex[1] = (firstCharIndex[1] + 1) % 5;
            secondCharIndex[1] = (secondCharIndex[1] + 1) % 5;
        } else if(firstCharIndex[1] == secondCharIndex[1]) {
            firstCharIndex[0] = (firstCharIndex[0] + 1) % 5;
            secondCharIndex[0] = (secondCharIndex[0] + 1) % 5;
        } else {
            int temp = firstCharIndex[1];
            firstCharIndex[1] = secondCharIndex[1];
            secondCharIndex[1] = temp;
        }

        pair[0] = matrix[firstCharIndex[0]][firstCharIndex[1]];
        pair[1] = matrix[secondCharIndex[0]][secondCharIndex[1]];

        plaintext[i] = pair[0];
        plaintext[i + 1] = pair[1];
    }
}

void decrypt(char *ciphertext) {
    for(int i = 0; i <  strlen(ciphertext); i += 2) {
        char pair[] = {ciphertext[i], ciphertext[i + 1]};

        int firstCharIndex[2];
        int secondCharIndex[2];

        for(int i = 0; i <  5; i++) {
            for(int j = 0; j < 5; j++) {
                if(matrix[i][j] == pair[0])  {
                    firstCharIndex[0] = i;
                    firstCharIndex[1] = j;
                } else if(matrix[i][j] == pair[1]) {
                    secondCharIndex[0] = i;
                    secondCharIndex[1] = j;
                }
            }
        }

        if(firstCharIndex[0] == secondCharIndex[0]) {
            firstCharIndex[1] = (firstCharIndex[1] - 1) % 5;
            secondCharIndex[1] = (secondCharIndex[1] - 1) % 5;
        } else if(firstCharIndex[1] == secondCharIndex[1]) {
            firstCharIndex[0] = (firstCharIndex[0] - 1) % 5;
            secondCharIndex[0] = (secondCharIndex[0] - 1) % 5;
        } else {
            int temp = firstCharIndex[1];
            firstCharIndex[1] = secondCharIndex[1];
            secondCharIndex[1] = temp;
        }

        pair[0] = matrix[firstCharIndex[0]][firstCharIndex[1]];
        pair[1] = matrix[secondCharIndex[0]][secondCharIndex[1]];

        ciphertext[i] = pair[0];
        ciphertext[i + 1] = pair[1];
    }
}


int main() {
    char text[MAX];
    char key[MAX];

    printf("Enter the text: ");
    scanf("%s", text);

    fflush(stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(text, key);
    printf("%s\n", text);

    decrypt(text);
    printf("%s\n", text);

    return 0;
}