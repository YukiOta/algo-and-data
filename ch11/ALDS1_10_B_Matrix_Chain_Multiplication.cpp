// 11.4
// 連鎖行列積

#include <iostream>
#include <algorithm>
using namespace std;

static const int N = 100;
static const int INFTY = (1 << 30);

int main()
{
    int n;
    int p[N + 1], m[N + 1][N + 1];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i - 1] >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++)
    {
        int i_max = n - l + 1;
        for (int i = 1; i <= i_max; i++)
        {
            int j = i + l - 1;
            m[i][j] = INFTY;
            for (int k = i; k <= j - 1; k++)
            {
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    cout << m[1][n] << endl;

    return 0;
}