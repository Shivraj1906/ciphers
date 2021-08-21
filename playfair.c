#include<stdio.h>
#include<string.h>
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

int main() {
    char text[MAX];
    char key[MAX];

    printf("Enter the text: ");
    scanf("%s", text);

    fflush(stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    // printf("%s\n", text);
    // printf("%s\n", key);

    prepareMatrix(key);

    printMatrix();
    return 0;
}