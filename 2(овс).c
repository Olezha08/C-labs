#include <stdio.h>
#include <stdlib.h>

int isPerfectSquare(int num) {
    int i;
    for(i = 1; i * i <= num; i++) {
        if(num % i == 0 && num / i == i) {
            return 1;
        }
    }
    return 0;
}

void solveQuadraticEquation(int a, int b, int c) {
    int discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        float root1 = (-b + sqrt(discriminant)) / (2 * a);
        float root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different. Root 1 = %.2f and Root 2 = %.2f\n", root1, root2);
    }
    else if (discriminant == 0) {
        float root = -b / (2 * a);
        printf("Roots are real and same. Root = %.2f\n", root);
    }
    else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and different. Root 1 = %.2f + %.2fi and Root 2 = %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Not enough arguments.\n");
        return 1;
    }

    char *flag = argv[1];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    int num3 = atoi(argv[4]);

    if (strcmp(flag, "-q") == 0) {
        if (argc != 6) {
            printf("Invalid number of arguments for flag -q. Expected 4, got %d\n", argc - 2);
            return 1;
        }
        solveQuadraticEquation(num1, num2, num3);
    }
    else if (strcmp(flag, "-m") == 0) {
        if (argc != 5) {
            printf("Invalid number of arguments for flag -m. Expected 3, got %d\n", argc - 2);
            return 1;
        }
        if (num2 % num1 == 0) {
            printf("The first number is a multiple of the second number.\n");
        } else {
            printf("The first number is not a multiple of the second number.\n");
        }
    }
    else if (strcmp(flag, "-t") == 0) {
        if (argc != 6) {
            printf("Invalid number of arguments for flag -t. Expected 4, got %d\n", argc - 2);
            return 1;
        }
        if (num1 + num2 > num3 && num1 + num3 > num2 && num2 + num3 > num1) {
            printf("The numbers can be sides of a right triangle.\n");
        } else {
            printf("The numbers cannot be sides of a right triangle.\n");
        }
    }
    else {
        printf("Invalid flag.\n");
        return 1;
    }

    return 0;
}