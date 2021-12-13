#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace std;
//using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;

//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll INF = 1e18;
const ll NINF = -(1e18);
ll mod = 1e9 + 7;

ll n;
vector<ll> a;

ll count_inv()
{
    ll ans = 0;
    ordered_set s;
    for (ll i = n - 1; i >= 0; i--)
    {
        ans += s.order_of_key(a[i]);
        s.insert(a[i]);
    }
    return ans;
}

void solve_case()
{
    cin >> n;
    a = vector<ll>(n);
    set<ll> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    ll m = s.size();
    if (m != n)
    {
        cout << "YES\n";
        return;
    }
    ll cnt = count_inv();
    if (cnt % 2)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    clock_t clk = clock();
    cout << fixed << setprecision(6);
    long long int t = 1;
    cin >> t;
    while (t--)
    {
        solve_case();
    }
    cerr << fixed << setprecision(6) << "Time: " << ((double)(clock() - clk)) / CLOCKS_PER_SEC << "\n";
    return 0;
}