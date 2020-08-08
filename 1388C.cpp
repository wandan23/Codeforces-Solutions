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
int n, m;
vector <int> adj[100005];
int h[100005];
int p[100005];
ll child[100005];
ll happy[100005];

bool dfs(int cur, int par)
{
    child[cur] = p[cur];
    happy[cur] = 0;


    for (int nxt : adj[cur])
    {
        if ( nxt == par)
            continue;
        bool temp = dfs(nxt, cur);
        if ( !temp)
            return false;
        child[cur] += child[nxt];
        happy[cur] += happy[nxt];
    }

    if ( abs(h[cur]) > child[cur])
        return false;
    if ( ((child[cur] + h[cur]) % 2) == 1)
        return false;

    int hp = (child[cur] + h[cur]) / 2;
    if ( happy[cur] > hp)
        return false;

    happy[cur] = hp;
    return true;

}

signed main() {
    wandan23();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        foo(i, 1, n + 1)
        {   cin >> p[i];
            adj[i].clear();
        }

        foo(i, 1, n + 1)
        {
            cin >> h[i];

        }
        int x, y;
        fo(i, n - 1)
        {
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }


        if ( dfs(1, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        // foo(i, 1, n + 1)
        // cout << child[i] << "  " << happy[i] << endl;



    }
}




















