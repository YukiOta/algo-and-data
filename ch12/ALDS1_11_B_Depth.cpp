// 12.3
// Depth First Search

#include <iostream>
#include <stack>
using namespace std;
static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n;
int M[N][N];
int color[N], d[N], f[N], tt;
int nt[N];

int next(int u)
{
    for (int v = nt[u]; v < n; v++)
    {
        nt[u] = v + 1;
        if (M[u][v])
            return v;
    }
    return -1;
}

void dfs_visit(int r)
{
    for (int i = 0; i < n; i++)
        nt[i] = 0;
    stack<int> S;
    S.push(r);
    color[r] = GRAY;
    d[r] = ++tt;

    while (!S.empty())
    {
        int u = S.top();
        int v = next(u);
        if (v != -1)
        {
            if (color[v] == WHITE)
            {
                color[v] = GRAY;
                d[v] = ++tt;
                S.push(v);
            }
        } else {
            S.pop();
            color[u] = BLACK;
            f[u] = ++tt;
        }
    }
}

void dfs_init()
{
    for (int i = 0; i < n; i++)
    {
        // init
        color[i] = 0;
        nt[i] = 0;
    }
    tt = 0;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == WHITE)
            dfs_visit(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
}

int main()
{
    int u, k, v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        // ノード番号、出次数のインプット
        cin >> u >> k;
        u -= 1;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            v -= 1;
            M[u][v] = 1;
        }
    }

    dfs_init();

    return 0;
}