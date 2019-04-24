// 5.2
// linear search

#include <cstdio>

bool linearSearch(int A[], int n, int key)
{
    int i = 0;
    A[n] = key;
    while ( A[i] != key )
    {
        i++;
    }
    if ( i == n ) return false;
    else return true;
}

int main()
{
    int A[10000], i, n, q, t;
    int sum = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d", &t);
        if (linearSearch(A, n, t)) sum++;
    }

    printf("%d\n", sum);

    return 0;
}