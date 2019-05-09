// 8.5
// 木巡回の応用：木の復元

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, pos;
vector<int> pre, in, post;

void reconstruction(int l, int r)
{
    if ( l >= r)
        return;
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    reconstruction(l, m);
    reconstruction(m+1, r);
    post.push_back(root);
}

void solve()
{
    pos = 0;
    reconstruction(0, pre.size());
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << post[i];
    }
    cout << endl;
}

int main()
{
    int k;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        pre.push_back(k);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        in.push_back(k);
    }

    solve();

    return 0;
}