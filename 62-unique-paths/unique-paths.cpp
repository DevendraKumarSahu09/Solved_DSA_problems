// Tabulation -------------------------------------------------

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


// Memoization -------------------------------------------------

// class Solution {
// public:
//     int solve(int row, int col, vector<vector<int> > &dp){

//         if(row<0 || col<0) return 0;
        
//         if(row == 0 && col == 0) return 1;

//         if(dp[row][col] != -1) return dp[row][col];

//         int up=0, left=0;

//         if (row - 1 >= 0) 
//             if (dp[row - 1][col] != -1) {
//                 up = dp[row - 1][col];
//             } else {
//                 up = solve(row - 1, col, dp);
//                 dp[row - 1][col] = up;
//             }

//         if (col - 1 >= 0) 
//             if (dp[row][col - 1] != -1) {
//                 left = dp[row][col - 1];
//             } else {
//                 left = solve(row, col - 1, dp);
//                 dp[row][col - 1] = left;
//             }

//         dp[row][col] = up+left;
//         return dp[row][col];
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int> > dp(m, vector<int>( n, -1));
//         return solve(m-1,n-1,dp);
//     }
// };



//Recursion---------------

// class Solution {
// public:
//     int solve(int row, int col){

//         if(row<0 || col<0){
//             return 0;
//         }

//         if(row == 0 && col == 0){
//             return 1;
//         }

//         int up = solve(row-1, col);
//         int left = solve(row, col-1);

//         int ans = up+left;
//         return ans;
//     }

//     int uniquePaths(int m, int n) {
//         return solve(m-1,n-1);
//     }
// };