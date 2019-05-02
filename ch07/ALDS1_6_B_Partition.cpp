// 7.2
// パーティション

#include <stdio.h>
#include <iostream>
#define MAX 100000
using namespace std;

int n, A[MAX];

int partition(int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = 0; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(A[j], A[i]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int main()
{
    int q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    // partition
    q = partition(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        if (i == q)
        {
            printf("[%d]", A[i]);
        }
        else
        {
            printf("%d", A[i]);
        }
    }
    printf("\n");

    return 0;
}