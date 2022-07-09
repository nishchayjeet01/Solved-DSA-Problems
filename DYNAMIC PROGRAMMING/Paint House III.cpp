int dp[25][105][105];
//piche_color neighbour_target index

int solve(int cnt, int index, int piche, vector<int> &v, vector<vector< int>> &cost, int target, int m, int n)
{
    if (index >= m)
    {
        if (cnt != target)
            return 1e8;
        return 0;
    }

    if (dp[piche][cnt][index] != -1)
        return dp[piche][cnt][index];

    dp[piche][cnt][index] = 1e8;

    if (v[index] == 0)
    {
        for (int i = 1; i < n + 1; ++i)
        {

            if (i != piche)
            {
                dp[piche][cnt][index] = min(dp[piche][cnt][index], solve(cnt + 1, index + 1, i, v, cost, target, m, n) + cost[index][i - 1]);
            }
            else
            {
                dp[piche][cnt][index] = min(dp[piche][cnt][index], solve(cnt, index + 1, i, v, cost, target, m, n) + cost[index][i - 1]);
            }
        }
    }
    else
    {

        if (v[index] != piche)
        {
            dp[piche][cnt][index] = min(dp[piche][cnt][index], solve(cnt + 1, index + 1, v[index], v, cost, target, m, n));
        }
        else
        {
            dp[piche][cnt][index] = min(dp[piche][cnt][index], solve(cnt, index + 1, v[index], v, cost, target, m, n));
        }
    }
    return dp[piche][cnt][index];

}

class Solution
{
    public:
        int minCost(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target)
        {
            memset(dp, -1, sizeof(dp));

            int ans = 1e8;

            ans=solve(0,0,0,houses,cost,target,m,n);

            if (ans == 1e8)
                ans = -1;
            return ans;
        }
};