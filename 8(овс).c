#include <stdio.h>

int main() {
    int arr[128];
    int n;

    // Считываем размер массива
    printf("Введите размер массива: ");
    scanf("%d", &n);

    // Считываем элементы массива
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    char choice;

    // Считываем выбор пользователя
    printf("Выберите операцию (a-e): ");
    scanf(" %c", &choice);

    // Объявляем новый массив
    int new_arr[128];
    int new_n = 0;

    // В зависимости от выбора пользователя выполняем соответствующую операцию
    switch (choice) {
        case 'a':
            // a) числа, стоящие на нечётных позициях
            for (int i = 1; i < n; i += 2) {
                new_arr[new_n++] = arr[i];
            }
            break;
        case 'b':
            // b) чётные числа
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    new_arr[new_n++] = arr[i];
                }
            }
            break;
        case 'c':
            // c) наиболее далёкое (по значению) от текущего значения
            for (int i = 0; i < n; i++) {
                int max_dist = 0;
                int max_val = arr[i];
                for (int j = 0; j < n; j++) {
                    int dist = arr[i] - arr[j];
                    if (dist < 0) dist *= -1;
                    if (dist > max_dist) {
                        max_dist = dist;
                        max_val = arr[j];
                    }
                }
                new_arr[new_n++] = max_val;
            }
            break;
        case 'd':
            // d) сумма элементов, которые предшествуют текущему элементу
            int sum = 0;
            for (int i = 0; i < n; i++) {
                new_arr[new_n++] = sum;
                sum += arr[i];
            }
            break;
        case 'e':
            // e) сумма элементов, которые меньше текущего элемента
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < n; j++) {
                    if (arr[j] < arr[i]) {
                        sum += arr[j];
                    }
                }
                new_arr[new_n++] = sum;
            }
            break;
        default:
            printf("Неверный выбор операции.\n");
            return 0;
    }

    // Выводим новый массив
    printf("Новый массив: ");
    for (int i = 0; i < new_n; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n");

    return 0;
}
