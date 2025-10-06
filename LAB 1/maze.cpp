/**
*   ^~^  ,
*  ('Y') )
*  /   / 
* (||/)
**/
#include <bits/stdc++.h>
#define TASK ""

using ll = long long;
using ld = long double;
#define pii pair<int,int>
#define bend(a) a.begin(), a.end()
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second

using namespace std;

const ll INF = 1e17 + 9;
const int N = 2e6 + 7;

struct P {
    int r, c, s;
};

const int MAXN = 1005;
int a[MAXN][MAXN];
int d[MAXN][MAXN];
int n, m;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool isValid(int nr, int nc) {
    return nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == 0 && d[nr][nc] == -1;
}

int bfs(int sr, int sc) {
    if (a[sr][sc] == 1) return -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = -1;

    queue<P> q;
    d[sr][sc] = 1;
    q.push({sr, sc, 1});

    while (!q.empty()) {
        P cur = q.front();
        q.pop();
        int r = cur.r;
        int c = cur.c;
        int steps = cur.s;

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) return steps;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(nr, nc)) {
                d[nr][nc] = steps + 1;
                q.push({nr, nc, steps + 1});
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    int ri, ci;
    cin >> n >> m >> ri >> ci;
    int r = ri - 1;
    int c = ci - 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int res = bfs(r, c);
    cout << res << endl;
    

    return 0;
}
