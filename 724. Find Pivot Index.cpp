/*
* Source : https://leetcode.com/problems/find-pivot-index/description/
* Diff   : Easy
* Author : Repon Kumar Roy
* Date   : 2017-11-09
*/

/********************************************************************************** 
* Given an array of integers nums, write a method that returns the "pivot" index of this array.
* We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
* If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

* Example 1:
* Input: 
* nums = [1, 7, 3, 6, 5, 6]
* Output: 3
* Explanation: 
* The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
* Also, 3 is the first index where this occurs.
* Example 2:
* Input: 
*  nums = [1, 2, 3]
* Output: -1
* Explanation: 
* There is no index that satisfies the conditions in the problem statement.  
**********************************************************************************/

/********************************************************************************** 
* Solution: O(N)
* Just iterate through the array, calculate the total sum of the array. 
* Again iterate through the array, calculating sum of left side and the right side. 
* If the sums are equal, return that index.
* If no index is found, return -1.
* Pitfall : Use long long to store value. 
**********************************************************************************/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i ++ ) sum += nums[i];
        long long pre = 0;
        for(int i = 0; i < n; i ++) {
            sum -= nums[i];
            if(pre == sum) {
                return i;
            }
            pre += nums[i];
        }
        return -1;
    }
};
