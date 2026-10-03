#include <stdio.h>
#define MAX_SIZE 100
/* Дектярев Михаил Павлович
П.И. 1-1
Поиск и преобразование одномерного массива
*/
int main(void) {
    int a[MAX_SIZE], n, x;
    printf("Enter n (1..100): ");
    if (scanf("%d", &n) != 1) {
        printf("Input error\n");
        return 1;
    }
    if (n < 1 || n > MAX_SIZE) {
        printf("Size error\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Input error\n");
            return 1;
        }
        if (a[i] < -1000 || a[i] > 1000) {
            printf("Value error\n");
            return 1;
        }
    }
    printf("Enter x (-1000..1000): ");
    if (scanf("%d", &x) != 1) {
        printf("Input error\n");
        return 1;
    }
    if (x < -1000 || x > 1000) {
        printf("Value error\n");
        return 1;
    }
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[minIndex]) minIndex = i;
        if (a[i] > a[maxIndex]) maxIndex = i;
    }
    int first = -1, count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            if (first == -1) first = i;
            count++;
        }
    }
    printf("Original:");
    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\nMin = %d, index = %d\n",
           a[minIndex], minIndex);
    printf("Max = %d, index = %d\n",
           a[maxIndex], maxIndex);
    if (first == -1) {
        printf("Not found\n");
    } else {
        printf("First index = %d\n", first);
    }
    printf("Count = %d\n", count);

    for (int i = 0; i < n / 2; i++) {
        int right = n - 1 - i;
        int temp = a[i];
        a[i] = a[right];
        a[right] = temp;
    }
    printf("Reversed:");
    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
    return 0;
}
