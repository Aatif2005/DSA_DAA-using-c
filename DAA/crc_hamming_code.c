#include <stdio.h>
#include <string.h>
void xorOperation(char dividend[], char divisor[], int pos, int divisorLen) {
    for (int j = 0; j < divisorLen; j++) {
        dividend[pos + j] =
            (dividend[pos + j] == divisor[j]) ? '0' : '1';
    }
}
void crc(char data[], char divisor[], char remainder[]) {
    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);
    char temp[200];
    strcpy(temp, data);
    // Perform modulo-2 division
    for (int i = 0; i <= dataLen - divisorLen; i++) {
        if (temp[i] == '1') {
            xorOperation(temp, divisor, i, divisorLen);
        }
    }
    // Copy remainder
    strcpy(remainder, temp + dataLen - divisorLen + 1);
}
int main() {
    char data[100], divisor[30];
    char appendedData[150], remainder[100], codeword[150];
    int dataLen, divisorLen;
    printf("Enter data bits: ");
    scanf("%s", data);
    printf("Enter generator bits: ");
    scanf("%s", divisor);
    dataLen = strlen(data);
    divisorLen = strlen(divisor);
    // Append zeros to the data
    strcpy(appendedData, data);
    for (int i = 0; i < divisorLen - 1; i++) {
        appendedData[dataLen + i] = '0';
    }
    appendedData[dataLen + divisorLen - 1] = '\0';
    // Calculate CRC remainder
    crc(appendedData, divisor, remainder);
    // Create transmitted codeword
    strcpy(codeword, data);
    strcat(codeword, remainder);
    printf("\nCRC Remainder : %s", remainder);
    printf("\nTransmitted Codeword : %s\n", codeword);
    // Receiver side
    char received[150];
    char checkRemainder[100];
    printf("\nEnter received codeword: ");
    scanf("%s", received);
    crc(received, divisor, checkRemainder);
    int error = 0;
    for (int i = 0; checkRemainder[i] != '\0'; i++) {
        if (checkRemainder[i] == '1') {
            error = 1;
            break;
        }
    }
    if (error)
        printf("Error detected in received data.\n");
    else
        printf("No error detected.\n");

    return 0;
}