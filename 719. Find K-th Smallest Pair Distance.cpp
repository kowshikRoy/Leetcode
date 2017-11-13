/*
* Source : https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
* Diff   : Hard
* Author : Repon Kumar Roy
* Date   : 2017-11-09
*/

/**************************************************************************************
  Given an integer array, return the k-th smallest distance among all the pairs. 
  The distance of a pair (A, B) is defined as the absolute difference between A and B.

  Example 1:
  Input:
  nums = [1,3,1]
  k = 1
  Output: 0 
  Explanation:
  Here are all the pairs:
  (1,3) -> 2
  (1,1) -> 0
  (3,1) -> 2
  Then the 1st smallest distance pair is (1,1), and its distance is 0.

  Note: 
  2 <= len(nums) <= 10000.
  0 <= nums[i] < 1000000.
  1 <= k <= len(nums) * (len(nums) - 1) / 2.
***************************************************************************************/
/*------------------------------------------------------------------------------------
  Solution: O(Nlog(N)log(MAX))
  1. First sort the input array. 
  2. Binary Search on the answer.
  3. To check if it is possible or not, iterate through the whole array index
  and check, the number of pair has difference at most k. Nlog(N)
  
  Solution 2: O(N log(MAX))
  In the previous solution, step 3 has done using lower_bound, But using two pointer method this can be done using O(N)
  The problem is similar to find the number of pair which has difference less than Mid;
  
  *----------------------------------------------------------------------------------/
  
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int low = 0, high = 1000000, mid , ans;
        sort(nums.begin(), nums.end());
        while(low <= high) {
            mid = (low + high)/2;
            int v = 0;
            for(int i = 0; i < nums.size(); i++) {
                int d = lower_bound(nums.begin(), nums.begin() + i, nums[i] - mid) - nums.begin();
                v += max(0, i - d);
            }
            if(v >= k) {
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int low = 0, high = 1000000, mid , ans;
        sort(nums.begin(), nums.end());
        while(low <= high) {
            mid = (low + high)/2;
            int v = 0;
            int j = 0;
            for(int i = 0; i < nums.size(); i++) {
                while(j < nums.size() && nums[i] - nums[j] > mid) j ++;
                v += i - j;
            }
            if(v >= k) {
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};
