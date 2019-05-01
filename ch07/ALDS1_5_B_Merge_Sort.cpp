// 7.1
// マージソート

#include <stdio.h>
#include <limits.h>
#define MAX 500000
// intの最大値に注意する
#define SENTINEL INT_MAX

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int count, n;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        count++;
        if (L[i] <= R[j])
        {
            A[k] = L[i++];
            // i += 1;
        }
        else
        {
            A[k] = R[j++];
            // j += 1;
        }
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int A[MAX];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    // merge sort
    mergeSort(A, 0, n);

    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", count);

    return 0;
}