#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Функция для проверки, является ли символ цифрой в заданной системе счисления
bool isDigit(char c, int base) {
    if (base <= 10) {
        return c >= '0' && c <= '0' + base - 1;
    } else {
        return (c >= '0' && c <= '9') || (toupper(c) >= 'A' && toupper(c) <= 'A' + base - 11);
    }
}

// Функция для конвертации символа цифры в число
int digitToValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return toupper(c) - 'A' + 10;
    }
}

// Функция для конвертации числа в заданной системе счисления в десятичное число
int convertToDecimal(char* num, int base) {
    int result = 0;
    int length = 0;
    
    for (int i = 0; num[i] != '\0'; i++) {
        length++;
    }
    
    for (int i = 0; num[i] != '\0'; i++) {
        int power = length - i - 1;
        result += digitToValue(num[i]) * pow(base, power);
    }
    
    return result;
}

int main() {
    int base;
    char num[100];
    int maxNum = 0;
    
    // Ввод основания системы счисления
    printf("Введите основание системы счисления (от 2 до 36): ");
    scanf("%d", &base);
    
    // Проверка валидности основания
    if (base < 2 || base > 36) {
        printf("Некорректное основание системы счисления.\n");
        return 0;
    }
    
    // Ввод чисел в заданной системе счисления
    printf("Введите числа в системе счисления с основанием %d (для окончания введите 'Stop'): ", base);
    
    while (true) {
        scanf("%s", num);
        
        // Проверка на окончание ввода
        if (strcmp(num, "Stop") == 0) {
            break;
        }
        
        // Проверка валидности числа
        bool isValid = true;
        for (int i = 0; num[i] != '\0'; i++) {
            if (!isDigit(num[i], base)) {
                isValid = false;
                break;
            }
        }
        
        // Если число валидно, конвертируем его в десятичную систему и обновляем максимальное число
        if (isValid) {
            int decimalNum = convertToDecimal(num, base);
            int absNum = abs(decimalNum);
            
            if (absNum > maxNum) {
                maxNum = absNum;
            }
        } else {
            printf("Некорректное число.\n");
        }
    }
    
    // Вывод максимального числа в заданных системах счисления
    printf("Максимальное по модулю число: %d в системе с основанием 9\n", maxNum);
    printf("Максимальное по модулю число: %d в системе с основанием 18\n", maxNum);
    printf("Максимальное по модулю число: %d в системе с основанием 27\n", maxNum);
    printf("Максимальное по модулю число: %d в системе с основанием 36\n", maxNum);
    
    return 0;
}
