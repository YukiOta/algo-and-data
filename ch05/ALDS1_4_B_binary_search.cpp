// 5.3
// binary search

// *---
// STL用いる例
// *---

#include <cstdio>
#include <algorithm>
using namespace std;

int A[1000000], n, sum;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int q, k;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &k);
        if (*lower_bound(A, A + n, k) == k)
            sum++;
    }

    printf("%d", sum);

    return 0;
}

// *---
// scratchでやる例
// *---

// #include <cstdio>

// bool binarySearch(int A[], int n, int key)
// {
//     int left = 0, right = n;
//     int mid;
//     while (left < right)
//     {
//         mid = ( left + right ) / 2;
//         if (A[mid] == key) return true;
//         if (key < A[mid]) right = mid;
//         // + 1が重要
//         else if(key > A[mid]) left = mid + 1;
//     }
//     return false;
// }

// int main()
// {
//     int A[1000000], i, n, q, t;
//     int sum = 0;

//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &A[i]);
//     }

//     scanf("%d", &q);
//     for (i = 0; i < q; i++)
//     {
//         scanf("%d", &t);
//         if (binarySearch(A, n, t)) sum++;
//     }

//     printf("%d\n", sum);

//     return 0;
// }