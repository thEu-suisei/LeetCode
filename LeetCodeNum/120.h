#include "include.h"

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        for(int i = 0; i < n; i++)
        {
            dp[i].resize(i+1);
        }

        // 边界dp
        dp[0][0]=triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = triangle[i][0]+dp[i-1][0];
            dp[i][i] = triangle[i][i]+dp[i-1][i-1];
        }

        // 状态转移dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+tri[i][j]
        for (int i = 2; i < n; i++)
        {
            for (int j = 1; j < i ; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }

        int temp = dp[n-1][0];
        for(int i = 1 ; i < n ; i++)
        {
            temp = min(temp, dp[n-1][i]);
        }
        return temp;
    }
};