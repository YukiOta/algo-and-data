// 11.3
// 最長共通部分列

#include <iostream>
#include <string>
#include <algorithm>
#define N_MAX 1000
#define Q_MAX 150
using namespace std;

int lcs(string X, string Y)
{
    int c[N_MAX + 1][N_MAX + 1];
    int m = X.size();
    int n = Y.size();
    int maxl = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    for (int i = 0; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= m; j++)
        c[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i] == Y[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);

            maxl = max(maxl, c[i][j]);
        }
    }
    return maxl;
}

int main()
{
    string s1, s2;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}