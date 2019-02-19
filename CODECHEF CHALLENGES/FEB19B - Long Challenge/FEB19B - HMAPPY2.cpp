#include <bits/stdc++.h>
#include <cstdio>
#define ll unsigned long long
using namespace std;

ll checkWinOrLose(ll n, ll a, ll b, ll k)
{
    if (__gcd(a, b) != 1)
    {
        ll count = n / __gcd(a, b);
        count = count - (n / max(a, b));
        if (count >= k)
        {
            return 1;
        }
        return 0;
    }
    ll count = (n / a) + (n / b) - ((n / (a * b)) * 2);
    if (count >= k)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n, a, b, k;
        scanf("%lld %lld %lld %lld", &n, &a, &b, &k);
        if (checkWinOrLose(n, a, b, k))
        {
            printf("%s\n", "Win");
        }
        else
        {
            printf("%s\n", "Lose");
        }
    }
    return 0;
}