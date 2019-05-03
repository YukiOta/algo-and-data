// 7.4
// 計測ソート
// not working

#include <stdio.h>
#include <stdlib.h>
#define NMAX 2000001
#define AMAX 10000
#define VMAX 10000

int main()
{
    unsigned short *A, *B;
    int C[VMAX + 1];
    int n, i, j;
    scanf("%d", &n);

    A = (unsigned short *)malloc(sizeof(short) * n + 1);
    B = (unsigned short *)malloc(sizeof(short) * n + 1);

    for (i = 0; i <= VMAX; i++)
        C[i] = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%hu", &A[i + 1]);
        C[A[i + 1]]++;
    }
    for (i = 1; i <= VMAX; i++)
        C[i] = C[i] + C[i - 1];
    for (j = 1; j <= n; j++)
    {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    return 0;
}

// int countingSort(int A[], int B[], int n)
// {
//     int C[AMAX + 1];
//     for (int i = 0; i <= AMAX; i++)
//     {
//         C[i] = 0;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         C[A[i + 1]]++;
//     }
//     for (int i = 1; i <= AMAX; i++)
//     {
//         C[i] = C[i] + C[i - 1];
//     }
//     for (int i = n; i >= 1; i--)
//     {
//         B[C[A[i]]] = A[i];
//         C[A[i]]--;
//     }
// }

// int main()
// {
//     int n, A[NMAX], B[NMAX];
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &A[i + 1]);
//     }

//     // counting sort
//     countingSort(A, B, n);

//     for (int i = 1; i <= n; i++)
//     {
//         if (i > 1)
//             printf(" ");
//         printf("%d", B[i]);
//     }
//     printf("\n");
//     return 0;
// }