#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
int arr[SIZE];
srand(time(0)); // Инициализация генератора случайных чисел
// Заполнение массива случайными числами
for (int i = 0; i < SIZE; i++) {
    arr[i] = rand();
}

// Нахождение максимального и минимального элементов
int max = arr[0];
int min = arr[0];
int max_index = 0;
int min_index = 0;

for (int i = 1; i < SIZE; i++) {
    if (arr[i] > max) {
        max = arr[i];
        max_index = i;
    }
    if (arr[i] < min) {
        min = arr[i];
        min_index = i;
    }
}

// Печатаем исходный массив
printf("Исходный массив: ");
for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
}
printf("\n");

// Печатаем максимального и минимального элементов
printf("Максимальный элемент: %d\n", max);
printf("Минимальный элемент: %d\n", min);

// Поменять местами максимальный и минимальный элементы
int temp = arr[max_index];
arr[max_index] = arr[min_index];
arr[min_index] = temp;

// Печатаем измененный массив
printf("Измененный массив: ");
for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
}
printf("\n");

return 0;

}