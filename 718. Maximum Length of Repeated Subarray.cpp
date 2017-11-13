/*
* Source : https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
* Diff   : Medium
* Author : Repon Kumar Roy
* Date   : 2017-11-13
*/

/****************************************************************************************
  Given two integer arrays A and B, return the maximum length of an subarray 
  that appears in both arrays.
  Example 1:
  Input:
  A: [1,2,3,2,1]
  B: [3,2,1,4,7]
  Output: 3
  Explanation: 
  The repeated subarray with maximum length is [3, 2, 1].
  Note:
  1 <= len(A), len(B) <= 1000
  0 <= A[i], B[i] < 100
*****************************************************************************************/

/*----------------------------------------------------------------------------------------
Solution: O(N^2) Dynamic Programming
dp(i,j) = Maximum length of a subarray which appears in both arrays starting with ith index
of A and j th index of B.
dp(i,j) = { 0                 if A(i) != B(j)
          { 1 + dp(i+1,j+1)   if A(i) = B(j)
 
 Solution: O(Nlog(N))
 $ Binary Search on the length.
 $ Generate all the hashvalue of substring of length mid of array A and B. If there is a hash present in both the array,
 So a string of this length is possible.
 $ It remains of the fact that if there is an answer of length i, there is always a substring i-1, which present in 
 both the arrays.
 *-----------------------------------------------------------------------------------------/


class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n= A.size(), m = B.size();
        vector< vector< int > > dp(n+1, vector<int> (m+1));
        for(int i= 0;i <n;i++) dp[i][m] = 0;
        for(int i= 0;i <m;i++) dp[n][i] = 0;
        int ans = 0;
        for(int i = n-1;i >= 0; i--){
            for(int j = m-1;j >= 0; j -- ) {
                if(A[i] == B[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans; 
    }
};




class Solution {
public:
    bool check(int l, vector< int > &A, vector< int > &B)
    {
        int base = 137;
        int mod = 1e8+7;
        int N = max(A.size(), B.size());
        vector< long long > pw(N+1);
        pw[0] = 1;
        for(int i = 1; i <= N; i ++) pw[i] = (base * pw[i-1]) % mod;
        
        int n  = A.size(), m = B.size();
        vector< long long> dp(N+1);
        unordered_set< long long > s;
        dp[n] = 0;
        for(int i = n-1;i >= 0; i -- ) {
            dp[i] = (A[i] + base *dp[i+1] ) % mod;
            if(i + l - 1 < n) {
                long long k = ((dp[i] - dp[i+l] * pw[l]) % mod + mod) %mod;
                s.insert(k);
            }
        }
        dp[m] = 0;
        for(int i = m-1;i >= 0; i -- ) {
            dp[i] = (B[i] + base *dp[i+1] ) % mod;
            if(i + l - 1 < m) {
                long long k = ((dp[i] - dp[i+l] * pw[l]) % mod + mod) %mod;
                if(s.count(k)) return 1;
            }
        }
        
        return 0;
        
        
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int n= A.size(), m = B.size();
        int low = 0, high = min(n,m), ans, mid;
        
        while(low <= high) {
            mid = (low + high)/2;
            if(check(mid,A,B)){
                ans = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
};
