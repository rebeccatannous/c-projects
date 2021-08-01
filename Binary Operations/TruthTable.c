#include <stdio.h>
#include <string.h>

int main() {
    //stores all the possible variables that the user might choose
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //number of variables
    int n;
    //used to add 1 to the  one's complement and store the carry in
    int add = 1;
    int or = 0;
    int and = 1;
    int num;
    int neg;

    //Prompts the user for the number of bits/variables
    printf("How many variables\n");
    scanf("%d", & n);

    //2 to the power n rows
    int k = 1;
    for (int i = 0; i < n; i++) {
        k = k * 2;
    }
    printf(" ");

    //prints the variables according to the number specified by the user
    for (int i = 0; i < n; i++)
        printf("%c \t ", alphabet[i]);
    printf("AND ");
    printf("\tOR ");
    printf("\tA' ");

    //to store the value of every variable by rows
    char binary[n];

    //fill the array with zeros, this is the first row
    for (int i = 0; i < n; i++) {
        binary[i] = '0';
    }

    //Another array of the same length to store the digits after every addition
    char bin[strlen(binary)];

    printf("\n ");

    //outer loop to repeat the operation 2^n times which is the number of rows
    while (k != 0) {
        /*Ands the variables by performing a multiplication of the values of every row, if the answer is 0
        then at least one value is 0 and therefore AND is also 0*/
        for (int i = 0; i < n; i++) {
            num = (int)(binary[i] - '0');
            and = and * num;
        }

        /*Ors the variables by checking if at least one value is 1 so the value of OR is also 1*/
        for (int i = 0; i < n; i++) {
            if (binary[i] == '1')
                or = 1;
        }

        //prints every character in the array separated by tab
        for (int i = 0; i < n; i++) {
            printf("%c \t ", binary[i]);
        }

        //Performs the negation of A the first variable
        if (binary[0] == '1') {
            neg = 0;
        } else {
            neg = 1;

        }

        //prints OR , AND and the negation
        printf("%d \t", and);
        printf("%d \t", or);
        printf("%d", neg);

        printf("\n ");

        //Loop to perform the binary addition, in other words fill the truth table
        for (int s = strlen(binary); s >= 0; s--) {
            if (binary[s] == '1' && add == 1) {
                bin[s] = '0';
            } else if (binary[s] == '0' && add == 1) {
                bin[s] = '1';
                add = 0;
            } else {
                bin[s] = binary[s];
            }
        }

        //function to copy the elements of bin to binary after every addition
        strcpy(binary, bin);

        //decrement k the number of rows
        k--;

        //resets the value of and, or and add
        and = 1;
        or = 0;
        add = 1;

    }

}
