#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int bestDefense(int *a, int *def, int n)
{
    int d[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = def[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        int power = (a[i - 1] + a[i + 1]);
        if (d[i] > power)
        {
            d[i] -= power;
        }
        else
        {
            d[i] = 0;
        }
    }
    // ************** For 1st Soldier *************
    int power = (a[n - 1] + a[1]);
    if (d[0] > power)
    {
        d[0] -= power;
    }
    else
    {
        d[0] = 0;
    }
    // ************** For Last Soldier ***********
    power = (a[n - 2] + a[0]);
    if (d[n - 1] > power)
    {
        d[n - 1] -= power;
    }
    else
    {
        d[n - 1] = 0;
    }
    // ************** For print ******************
    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
    cout << "\n";
    // ************** End ************************
    auto pos = max_element(d, d + n);
    if (*pos == 0)
    {
        return -1;
    }
    return (pos - d);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int *attack = new int[n];
        int *defense = new int[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &attack[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &defense[i]);
        }
        int res = bestDefense(attack, defense, n);
        if (res == -1)
        {
            printf("%d\n", -1);
        }
        else
        {
            printf("%d\n", defense[res]);
        }
    }
    return 0;
}