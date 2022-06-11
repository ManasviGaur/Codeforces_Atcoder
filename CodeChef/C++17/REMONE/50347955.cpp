#include <bits/stdc++.h>

using namespace std;

/********************************MACROS********************************/

#define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vt vector
#define pb push_back
#define F first
#define S second
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue

/*******************************DEBUGGER*******************************/

#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                                    \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(c i) \
    {
sim > struct rge
{
    c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug
{
#ifndef ONLINE_JUDGE
    ~debug()
    {
        cerr << endl;
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c &)
    {
        ris;
    }
#endif
}
;
#define deb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/******************************ALGORITHMS******************************/

int __pow(int x, int y, int m)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return res % m;
}
int __pow(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y >>= 1;
        x = (x * x);
    }
    return res;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int mi(int x, int M) { return __pow(x, M - 2, M); }
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
/******************************MAIN**CODE******************************/

const int N = 1e5 + 2, inf = 1e18, M = 1e9 + 7;
int test, n, k, m, x, query;

void test_case()
{
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(all(a));
    sort(all(b));
    int tmp1 = b[0] - a[0];
    int tmp2 = b[n - 2] - a[n - 1];
    if (tmp1 <= 0)
    {
        cout << tmp2 << endl;
        return;
    }
    if (tmp2 <= 0)
    {
        cout << tmp1 << endl;
        return;
    }
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    bool flag1 = 1, flag2 = 1;
    for (int i = 0; i < n - 1; i++)
    {
        s.insert(b[i] - tmp1);
        {
            if (s.size() != n)
            {
                flag1 = 0;
                break;
            }
        }
    }
    s.clear();
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int i = 0; i < n - 1; i++)
    {
        s.insert(b[i] - tmp2);
        {
            if (s.size() != n)
            {
                flag2 = 0;
                break;
            }
        }
    }
    if (flag1 && flag2)
    {
        cout << min(tmp1, tmp2) << endl;
        return;
    }
    if (flag1)
        cout << tmp1 << endl;
    else
        cout << tmp2 << endl;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    test = 1;
    cin >> test;
    while (test--)
        test_case();
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
