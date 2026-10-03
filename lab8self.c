#include <stdio.h>
#define MAX_SIZE 100

int main(void) {
    int a[MAX_SIZE], n, x, y;

    if (scanf("%d", &n) != 1) 
    {
        printf("Input error\n");
        return 1;
    }
    if (n < 1 || n > MAX_SIZE) 
    {
        printf("Size error\n");
        return 1;
    }
    for (int i = 0; i < n; i++) 
    {
        if (scanf("%d", &a[i]) != 1) 
        {
            printf("Input error\n");
            return 1;
        }
        if (a[i] < -1000 || a[i] > 1000) 
        {
            printf("Value error\n");
            return 1;
        }
    }
    if (scanf("%d", &x) != 1) 
    {
        printf("Input error\n");
        return 1;
    }
    if (x < -1000 || x > 1000) 
    {
        printf("Value error\n");
        return 1;
    }
    if (scanf("%d", &y) != 1) 
    {
        printf("Input error\n");
        return 1;
    }
    if (y < -1000 || y > 1000) 
    {
        printf("Value error\n");
        return 1;
    }

    // Поиск вхождений по исходным данным
    int first = -1, last = -1, count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] == x) 
        {
            if (first == -1) first = i;
            last = i;
            count++;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        if (a[i] == x) 
        {
            a[i] = y;
        }
    }

    printf("После:");
    for (int i = 0; i < n; i++) 
    {
        printf(" %d", a[i]);
    }
    printf("\n");

    if (first == -1) 
    {
        printf("Not found\n");
        printf("count = 0\n");
    } 
    else 
    {
        printf("count = %d\n", count);
        printf("first = %d\n", first);
        printf("last = %d\n", last);
    }

    return 0;
}
