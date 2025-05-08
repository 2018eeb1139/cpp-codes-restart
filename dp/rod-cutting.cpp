int dp[1001][1001];
// int func(int idx,int N,vector<int> &price){
//     if(idx<0) return 0;
//     if(N==0) return 0;
//     if(dp[idx][N] != -1) return dp[idx][N];
//     int ans = func(idx-1,N,price);
//     if(N-(idx+1)>=0){
//         ans = max(ans,func(idx,N-(idx+1),price)+price[idx]);
//     }
//     return dp[idx][N] = ans;
// }
int cutRod(vector<int> &price)
{
    // code here
    // memset(dp,-1,sizeof(dp));
    int n = price.size();
    // return func(n-1,n,price);
    vector<int> length(n);
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int j = 0; j < n + 1; j++)
    {
        dp[j][0] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][n];
}