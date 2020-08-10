#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define M 1000000007
#define ll long long
#define pb push_back
#define fo(i,N) for(int i = 0 ; i < N ; i++)
#define foo(i,x,N) for (int i = x; i < N ; i++)
#define fill(a,val) memset(a,val,sizeof(a))
#define fastio()  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define ff first
#define ss second
#define MAX 1234567
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(a) a.begin(),a.end()
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define vi vector<int>
#define pii pair<int,int>
#define pqb priority_queue<pair<pair<ll,ll>,int>>
#define pqs priority_queue<ll,vector <ll>,greater<ll>>
#define int ll
/// find_by_order() -- returns the iterator to the kth largest
/// order_of_key() -- number of elements strictly less than k
ll mpow(ll x, ll y, ll m) {if ( y == 0) return 1;  if ( y & 1) return (x % m * mpow(x, y - 1, m) % m) % m; else  {ll temp = mpow(x, y / 2, m) % m; return (temp * temp) % m;}}
ll power(ll x, ll y) {if ( y == 0) return 1;  if ( y & 1) return (x * power(x, y - 1)); else  {ll temp = power(x, y / 2); return (temp * temp);}}
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        pbds;
void wandan23() {
    fastio()
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[1000005][8];
int ok2[4][4];
int ok3[8][8];
int arr[4][1000005];


void pre2()
{
    int flag = 1;

    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            flag = 1;

            int total = (bool) (i & 1) + (bool)(i & 2);
            total += (bool)(j & 1) + (bool) (j & 2);
            if (total % 2 != 0)
                ok2[i][j] = 1;
            else
                ok2[i][j] = 0;

        }
    }
}

void pre3()
{
    int flag = 1;

    for (int i = 0 ; i < 8 ; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            flag = 1;
            for (int k = 0 ; k < 2 ; k++)
            {

                int total = (bool)(i & (1 << k)) + (bool)(i & (1 << (k + 1)));
                total += (bool)(j & (1 << k)) + (bool)(j & (1 << (k + 1)));;
                if (total % 2 == 0)
                    flag = 0;

            }

            if ( flag)
                ok3[i][j] = 1;
            else
                ok3[i][j] = 0;

        }
    }
}

void solve3(int m)
{   int cur;
    cur = arr[0][0] + 2 * arr[1][0] + 4 * arr[2][0];
    for (int i = 0; i < 8; i++)
        dp[0][i] = __builtin_popcount(cur ^ i);

    for (int i = 1; i < m; i++)
    {
        cur = arr[0][i] + 2 * arr[1][i] + 4 * arr[2][i];
        // cout << cur << endl;
        for (int j = 0; j < 8; j++)
        {
            dp[i][j] = 1e9;
            for (int mask = 0 ; mask < 8; mask++)
            {
                if ( ok3[j][mask])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][mask] + __builtin_popcount(cur ^ j));
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < 8; i++) {
        ans = min(ans, dp[m - 1][i]);

    }
    cout << ans << endl;
}
void solve2(int m)
{   int cur;
    cur = arr[0][0] + 2 * arr[1][0];
    for (int i = 0; i < 4; i++)
        dp[0][i] = __builtin_popcount(cur ^ i);

    for (int i = 1; i < m; i++)
    {
        cur = arr[0][i] + 2 * arr[1][i] ;
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] = 1e9;
            for (int mask = 0 ; mask < 4; mask++)
            {
                if ( ok2[j][mask])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][mask] + __builtin_popcount(cur ^ j));
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < 4; i++)ans = min(ans, dp[m - 1][i]);
    cout << ans << endl;
}



signed main() {

    wandan23();
    pre2();
    pre3();

    int n, m;
    cin >> n >> m;

    if ( min(n, m) > 3)
    {
        cout << -1 << endl;
        return 0;
    }

    if ( min(n, m) == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    char c;
    fo(i, n)
    {
        fo(j, m)
        {   cin >> c;
            arr[i][j] = c - '0';

        }
    }

    if ( n == 2)
        solve2(m);
    else
        solve3(m);




}




















