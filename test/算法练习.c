#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int* new = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int j = digitsSize - 1, count = 0, sz = 0;
    digits[j]++;
    for (int i = 0; i < digitsSize; i++)
    {
        new[i] = digits[j--] + count;
        count = 0;
        sz++;
        if (new[i] == 10)
        {
            new[i] = 0;
            count = 1;
        }
    }
    if (new[sz-1] == 0)
    {
        new[digitsSize] = 1;
        sz++;
    }
    *returnSize = sz;
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        int tmp = new[left];
        new[left] = new[right];
        new[right] = tmp;
        left++;
        right--;
    }

    return new;
}
int main()
{
    int digits[] = { 9,9,9 };
    int digitsSize = 3, returnsz = 0;
    int* nice = plusOne(digits, digitsSize, &returnsz);

    for (int i = 0; i < returnsz; i++)
    {
        printf("%d ", nice[i]);
    }

    return 0;
}