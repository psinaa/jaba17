#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 1000

int* full_array(int* ptr_array, int n);
int put_array(int* ptr_array, int n);
void sort_buble(int* ptr_array, int n);
void sort_select(int* ptr_array, int n);
void ShakerSort(int* ptr_array, int n);
void insertSort(int* ptr_array, int n);

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    int ptr_array[N];
    full_array(ptr_array, n);
    printf("Шейкерная сортировка\n");
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    ShakerSort(ptr_array, n);
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    printf("\nВремя сортировки %i(миллисекунд)\n", fTimeStop - fTimeStart);
    printf("\n");

    printf("\nСортировка пузырьком\n");
    clock_t fTimeSta, fTimeSto;
    fTimeSta = clock() * 1000 / CLOCKS_PER_SEC;
    sort_buble(ptr_array, n);
    fTimeSto = clock() * 1000 / CLOCKS_PER_SEC;
    printf("\nВремя сортировки %i(миллисекунд)\n", fTimeSto - fTimeSta);
    printf("\n");

    printf("\nСортировка выбором\n");
    clock_t fTimeS, fTimeF;
    fTimeS = clock() * 1000 / CLOCKS_PER_SEC;
    sort_select(ptr_array, n);
    fTimeF = clock() * 1000 / CLOCKS_PER_SEC;
    printf("\nВремя сортировки %i(миллисекунд)\n", fTimeF - fTimeS);
    printf("\n");

    printf("\nСортировка вставками\n");
    clock_t fTimeStar, fTimeFin;
    fTimeStar = clock() * 1000 / CLOCKS_PER_SEC;
    insertSort(ptr_array, n);
    fTimeFin = clock() * 1000 / CLOCKS_PER_SEC;
    printf("\nВремя сортировки %i(миллисекунд)\n", fTimeFin - fTimeStar);
    printf("\n");
}
int* full_array(int* ptr_array)
{
    for (int i = 0; i < N; i++)
    {
        ptr_array[i] = rand() % 10;
    }
}
int put_array(int* ptr_array, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d", ptr_array[i]);
    }
}

void sort_insert(int* ptr_array, int n) {
    int temp;
    int j;
    for (int i = 1; i < n - 1; i++) {
        temp = ptr_array[i];
        j = i;
        if (ptr_array[j - 1] > temp && j > 0) {
            ptr_array[j] = ptr_array[j - 1];
            j--;
        }
        else {
            ptr_array[j] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%i ", ptr_array[i]);
    }
}

void sort_buble(int* ptr_array, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ptr_array[j] < ptr_array[j + 1]) {
                int tmp = ptr_array[j];
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%i ", ptr_array[i]);
    }
}
void sort_select(int* ptr_array, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (ptr_array[j] < ptr_array[min])
                min = j;
        int b = ptr_array[i];
        ptr_array[i] = ptr_array[min];
        ptr_array[min] = b;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ptr_array[i]);
    printf("\n");
    return 0;
}
void ShakerSort(int* ptr_array, int n)
{
    int leftMark = 1;
    int rightMark = n - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
            if (ptr_array[i - 1] > ptr_array[i]) {
                int buff;
                buff = ptr_array[i];
                ptr_array[i] = ptr_array[i - 1];
                ptr_array[i - 1] = buff;
            }

        leftMark++;
        for (int i = leftMark; i <= rightMark; i++)
            if (ptr_array[i - 1] > ptr_array[i])
            {
                int buff;
                buff = ptr_array[i];
                ptr_array[i] = ptr_array[i - 1];
                ptr_array[i - 1] = buff;
            }
        rightMark--;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ptr_array[i]);
    printf("\n");
}
void insertSort(int* ptr_array, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; ++i)
    {
        tmp = ptr_array[i];
        for (j = i - 1; j >= 0 && ptr_array[j] > tmp; --j)
            ptr_array[j + 1] = ptr_array[j];
        ptr_array[j + 1] = tmp;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ptr_array[i]);
    printf("\n");
}