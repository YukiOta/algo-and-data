// 5.6
// allocation

#include <cstdio>
#define MAX 100000
typedef long long llong;

int n, k;
llong W[MAX];

int checkP(llong P)
{
    int w_i = 0;
    for (int i = 0; i < k; i++)
    {
        llong w = 0;
        while (w + W[w_i] <= P)
        {
            w += W[w_i];
            w_i += 1;
            if (w_i == n)
                return w_i;
        }
    }
    return w_i;
}

llong solver()
{
    llong left = 0;
    llong right = MAX * MAX;
    llong mid;
    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (checkP(mid) >= n)
            right = mid;
        else
            left = mid;
    }
    return right;
}

int main()
{
    llong answer;
    scanf("%d %d", &n, &k);
    for (int i; i < n; i++)
    {
        scanf("%d", &W[i]);
    }

    answer = solver();
    printf("%d\n", answer);

    return 0;
}