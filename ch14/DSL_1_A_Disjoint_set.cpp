// 14.1
// 互いに素な集合

#include <iostream>
#include <vector>

using namespace std;

class DisjointSet
{
public:
    vector<int> rank, p;

    DisjointSet(int size)
    {
        rank.resize(size);
        p.resize(size);
        for (int i = 0; i < size; i++)
        {
            makeSet(i);
        }
    }

    void makeSet(int x)
    {
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y)
    {
        return findSet(x) == findSet(y);
    }

    int findSet(int x)
    {
        if (p[x] != x)
        {
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    void unite(int x, int y)
    {
        link(findSet(x), findSet(y));
    }

    void link(int x, int y)
    {
        if (rank[x] > rank[y])
        {
            p[y] = x;
        }
        else
        {
            p[x] = y;
            if (rank[x] == rank[y])
            {
                rank[y]++;
            }
        }
    }
};

int main()
{
    int n, q, a, b;
    int t;

    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);

    for (int i = 0; i < q; i++)
    {
        cin >> t >> a >> b;
        if (t == 0)
            ds.unite(a, b);
        else if (t == 1)
            if (ds.same(a, b))
                cout << 1 << endl;
            else
                cout << 0 << endl;
    }

    return 0;
}