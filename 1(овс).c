#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функция для проверки, является ли число простым
int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Функция для разделения числа на отдельные цифры
void separateDigits(int num) {
    while (num > 0) {
        printf("%d ", num % 10);
        num /= 10;
    }
    printf("\n");
}

// Функция для вычисления факториала
int factorial(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Недостаточно аргументов командной строки.\n");
        return 1;
    }
    
    int number = atoi(argv[1]);  // Преобразуем первый аргумент в целое число
    
    // Проверяем флаги и выполняем соответствующие операции
    if (argv[2][0] == '-') {
        switch (argv[2][1]) {
            case 'h':
                printf("Числа, кратные %d в пределах 100:\n", number);
                for (int i = number; i <= 100; i += number) {
                    printf("%d ", i);
                }
                printf("\n");
                break;
            
            case 'p':
                if (isPrime(number)) {
                    printf("%d - простое число.\n", number);
                } else {
                    printf("%d - составное число.\n", number);
                }
                break;
            
            case 's':
                printf("Разделение числа %d на отдельные цифры:\n", number);
                separateDigits(number);
                break;
            
            case 'e':
                printf("Вычисление степеней числа %d от 1 до 10:\n", number);
                if (number > 10) {
                    printf("Ограничение на вводимое число: оно должно быть не больше 10.\n");
                } else {
                    for (int i = 1; i <= 10; i++) {
                        printf("%d ^ %d = %f\n", number, i, pow(number, i));
                    }
                }
                break;
            
            case 'a':
                int sum = 0;
                for (int i = 1; i <= number; i++) {
                    sum += i;
                }
                printf("Сумма всех чисел от 1 до %d: %d\n", number, sum);
                break;
            
            case 'f':
                printf("Факториал числа %d: %d\n", number, factorial(number));
                break;
            
            default:
                printf("Некорректный флаг.\n");
                break;
        }
    } else {
        printf("Некорректный флаг.\n");
    }
    
    return 0;
}