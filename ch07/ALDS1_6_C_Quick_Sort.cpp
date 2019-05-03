// 7.3
// クイックソート

#include <stdio.h>
#include <limits.h>
#define MAX 100000
#define SENTINEL INT_MAX

struct Card
{
    char suit;
    int value;
};
struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];
int n;

void merge(struct Card A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i].value <= R[j].value)
        {
            A[k] = L[i++];
            // i++;
        }
        else
        {
            A[k] = R[j++];
            // j++;
        }
    }
}

void mergeSort(struct Card A[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(struct Card A[], int p, int r)
{
    struct Card x = A[r], t;
    int i = p - 1;
    // これ
    for (int j = p; j < r; j++)
    {
        if (A[j].value <= x.value)
        {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;
    return i + 1;
}

void quickSort(struct Card A[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int isStable(int n, struct Card A[], struct Card B[])
{
    int stable = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i].suit != B[i].suit)
            stable = 0;
    }
    return stable;
}

int main()
{
    struct Card A[MAX], B[MAX];
    char S[10];
    int stable = 1, v;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", S, &v);
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A, 0, n);
    quickSort(B, 0, n - 1);

    stable = isStable(n, A, B);

    if (stable == 1)
    {

        printf("Stable\n");
    }
    else
    {
        printf("Not stable\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c %d\n", B[i].suit, B[i].value);
    }
    return 0;
}