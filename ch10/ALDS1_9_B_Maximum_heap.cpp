// 10.3
// 最大ヒープ

#include <iostream>
using namespace std;
#define MAX 500000

int H, A[MAX + 1];

void maxHeapify(int i)
{
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    if (l <= H && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r <= H && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int main()
{
    int i;

    cin >> H;
    for (i = 1; i <= H; i++)
        cin >> A[i];

    for (i = H / 2; i >= 1; i--)
        maxHeapify(i);

    for (i = 1; i <= H; i++)
    {
        cout << " " << A[i];
    }
    cout << endl;
    return 0;
}