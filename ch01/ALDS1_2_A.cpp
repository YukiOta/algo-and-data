// 3.3
// bubble sort

#include <iostream>
using namespace std;

int bubbleSort(int A[], int N)
{
    int j;
    int count = 0;
    bool flag = 1;

    while (flag)
    {
        flag = 0;
        for (j = N - 1; j >= 1; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j-1]);
                count++;
                flag = 1;
            }
        }
    }
    return count;
}

int main()
{
    int N, i, count, A[100];

    cin >> N;
    for (i = 0; i < N; i++)
        cin >> A[i];

    count = bubbleSort(A, N);

    for (i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}