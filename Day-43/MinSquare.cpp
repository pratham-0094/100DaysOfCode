#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 2, MOD = 1e9 + 7;

int dp[N];
int minSquare(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        return n;
    }
    if (dp[n] != MOD)
    {
        return dp[n];
    }
    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], 1 + minSquare(n - i * i));
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < N; i++)
    {
        dp[i] = MOD;
    }

    cout << minSquare(n) << endl;

    vector<int> dp(n + 1, MOD);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; i * i + j <= n; j++)
        {
            dp[i * i + j] = min(dp[i * i + j], 1 + dp[j]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}