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
#define int ll
#define vi vector<int>
#define pii pair<int,int>
#define pqb priority_queue<pair<pair<ll,ll>,int>>
#define pqs priority_queue<ll,vector <ll>,greater<ll>>
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

vector <pair<int, int>> adj[100005];
int w[100005];
int c[100005];

void dfs(int cur, int par)
{

    if ( par != 0 && adj[cur].size() == 1)
    {   c[par] = 1;
        return;
    }

    for (auto nxt : adj[cur])
    {
        if ( nxt.ss == par)
            continue;

        dfs(nxt.ff, nxt.ss);

        c[par] += c[nxt.ss];
    }
}

int getdiff(int i)
{
    return 1ll * w[i] * c[i] - (1ll * w[i] / 2 * c[i]);
}


signed main() {
    // wandan23();
    int t;
    cin >> t;
    while (t--)
    {   int n, S;
        cin >> n >> S;
        int x, y, z;
        fill(c, 0);
        fo(i, n - 1)
        {
            cin >> x >> y >> w[i + 1];
            adj[x].pb({y, i + 1});
            adj[y].pb({x, i + 1});
        }

        dfs(1, 0);
        // for (int i = 1; i < n ; i++)
        //     cout << c[i] << ' ';

        //scout << endl;


        set <pair<int, int>> s;
        int cur = 0;
        for (int i = 1; i < n; i++)
        {
            cur += w[i] * c[i];
            s.insert({getdiff(i), i});
        }

        int ans = 0;
        while ( cur > S)
        {   //cout << "atak" << endl;
            auto temp = s.rbegin()->second;
            auto it = s.end();
            it--;
            s.erase(it);
            cur -= getdiff(temp);
            w[temp] /= 2;
            s.insert({getdiff(temp), temp});
            ans++;
            //cout << ans << " " << cur << endl;
        }
        cout << ans << endl;
        foo(i, 1, n + 1)
        adj[i].clear();

    }
}



















 
