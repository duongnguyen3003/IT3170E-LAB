/**
* ^~^  ,
* ('Y') )
* /   / 
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
int n, a[N], temp[N], res = 0;


void countAndMergeSort(int left, int right) 
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    countAndMergeSort(left, mid);
    countAndMergeSort(mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) 
    {
        if (a[i] <= a[j]) 
        {
            temp[k++] = a[i++];
        } 
        else
        {
            temp[k++] = a[j++];
            res += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (int i = left; i <= right; i++) a[i] = temp[i];
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
    }

    countAndMergeSort(1, n);
    cout << res;

    return 0;
}
