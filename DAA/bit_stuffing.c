#include <stdio.h>
#include <string.h>

void bitStuffing(char data[], char stuffed[]) {
    int count = 0;
    int j = 0;

    for (int i = 0; data[i] != '\0'; i++) {
        stuffed[j++] = data[i];

        if (data[i] == '1') {
            count++;

            // Insert a 0 after five consecutive 1s
            if (count == 5) {
                stuffed[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    stuffed[j] = '\0';
}

void bitDeStuffing(char stuffed[], char destuffed[]) {
    int count = 0;
    int j = 0;

    for (int i = 0; stuffed[i] != '\0'; i++) {
        destuffed[j++] = stuffed[i];

        if (stuffed[i] == '1') {
            count++;

            // Skip the stuffed 0 after five consecutive 1s
            if (count == 5) {
                if (stuffed[i + 1] == '0') {
                    i++;
                }
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    destuffed[j] = '\0';
}

int main() {
    char data[100];
    char stuffed[200];
    char destuffed[200];

    printf("Enter the bit stream: ");
    scanf("%99s", data);

    bitStuffing(data, stuffed);

    printf("\nOriginal bit stream : %s", data);
    printf("\nStuffed bit stream  : %s", stuffed);

    bitDeStuffing(stuffed, destuffed);

    printf("\nDe-stuffed bit stream: %s\n", destuffed);

    return 0;
}