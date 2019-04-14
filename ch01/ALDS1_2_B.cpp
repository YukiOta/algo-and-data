// 3.4
// selection sort

#include <iostream>
using namespace std;

int selectionSort(int A[], int N)
{
    int minj, count = 0;
    bool flag = 0;

    for (int i = 0; i < N - 1; i++)
    {
        minj = i;
        flag = 0;
        for (int j = i; j < N; j++)
        {
            if (A[j] < A[minj]) {
                minj = j;
                flag = 1;
            }
        }
        swap(A[i], A[minj]);
        if (flag) {
            count++;
        }
    }

    return count;
}

int main()
{
    int A[100], N, count;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    count = selectionSort(A, N);

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}