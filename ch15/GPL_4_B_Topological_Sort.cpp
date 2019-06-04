// 15.2
// トポロジカルソート

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
using namespace std;

static const int MAX = 100000;
static const int INFTY = (1 << 29);

int N;
int indeg[MAX];
bool V[MAX];
list<int> out;
vector<int> G[MAX];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    V[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        out.push_back(u);
        for ( int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            indeg[v]--;
            if (indeg[v] == 0 && !V[v])
            {
                V[v] = true;
                q.push(v);
            }
        }
    }

}

void toposort()
{

    for (int i = 0; i < N; i++)
    {
        indeg[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < G[i].size(); j++)
        {
            int v = G[i][j];
            indeg[v]++;
        }
    }

    for (int i = 0; i < N; i++)
        if (indeg[i] == 0 && !V[i])
            bfs(i);

    for ( list<int>::iterator it = out.begin(); it != out.end(); it++)
    {
        cout << *it << endl;
    }

}

int main()
{
    int s, t, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        V[i] = false;

    for (int i = 0; i < M; i++)
    {
        cin >> s >> t;
        G[s].push_back(t);
    }

    toposort();

    return 0;
}