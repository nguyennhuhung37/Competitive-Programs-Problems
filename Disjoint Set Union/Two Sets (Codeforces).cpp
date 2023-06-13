#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 5;
int n, a, b, p[MAX], fa[MAX];
map<int, int> mp;

// Union Find with Compression Path
int Find(int x)
{
    if (fa[x] != x)
        fa[x] = Find(fa[x]);
    return fa[x];
}

// Normal Union without Weighted Path
void Union(int u, int v)
{
    int uu = Find(u);
    int vv = Find(v);
    if (uu != vv)
        fa[uu] = v;
}

int main()
{
    if (scanf("%d%d%d", &n, &a, &b) == 3)
    {
        int Max = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i]);
            mp[p[i]] = i;
            Max = max(Max, p[i]);
        }
        if (Max >= max(a, b))
            printf("NO\n");
        else
        {
            for (int i = 0; i <= n + 1; i++)
            {
                fa[i] = i;
            }
            for (int i = 1; i <= n; i++)
            {
                if (mp[a - p[i]])
                    Union(i, mp[a - p[i]]);
                else
                    Union(i, n + 1);
                if (mp[b - p[i]])
                    Union(i, mp[b - p[i]]);
                else
                    Union(i, 0);
            }
            int A = Find(0);
            int B = Find(n + 1);
            if (A != B)
            {
                printf("YES\n");
                for (int i = 1; i <= n; i++)
                {
                    if (i != 1)
                        printf(" ");
                    if (Find(i) == A)
                        printf("0");
                    else
                        printf("1");
                }
                printf("\n");
            }
            else
                printf("NO\n");
        }
    }
    return 0;
}
