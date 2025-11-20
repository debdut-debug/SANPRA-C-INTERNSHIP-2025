#include <stdio.h>

void encrypt(char ch, FILE *out) {
    fputc(ch + 3, out);
}

void decrypt(char ch, FILE *out) {
    fputc(ch - 3, out);
}

int main() {
    FILE *in, *out;
    char ch;
    int choice;

    printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        in = fopen("input.txt", "r");
        out = fopen("encrypted.txt", "w");
        while((ch = fgetc(in)) != EOF)
            encrypt(ch, out);
    } else {
        in = fopen("encrypted.txt", "r");
        out = fopen("decrypted.txt", "w");
        while((ch = fgetc(in)) != EOF)
            decrypt(ch, out);
    }

    fclose(in);
    fclose(out);
    printf("Operation completed successfully.\n");
    return 0;
}
