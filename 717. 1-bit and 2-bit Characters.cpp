/*
* Source : https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
* Diff   : Easy
* Author : Repon Kumar Roy
* Date   : 2017-11-13
*/

/********************************************************************************
  We have two special characters. The first character can be represented by one bit 0. 
  The second character can be represented by two bits (10 or 11).

  Now given a string represented by several bits.
  Return whether the last character must be a one-bit character or not.
  The given string will always end with a zero.
  
  Input: 
  bits = [1, 0, 0]
  Output: True
  Explanation: 
  The only way to decode it is two-bit character and one-bit character. 
  So the last character is one-bit character.

  Input: 
  bits = [1, 1, 1, 0]
  Output: False
  Explanation: 
  The only way to decode it is two-bit character and two-bit character. 
  So the last character is NOT one-bit character.

  ******************************************************************************/
  
  /*-----------------------------------------------------------------------------
    Solution: O(N)
    Iterate through the array. if current number is 1, then increment index by 2, otherwise 1.
    Check if a new character begins at bits.size()-1.
 ---------------------------------------------------------------------------------*/
    
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i = 0; i < bits.size(); i++ ) {
            if(i == bits.size()-1) return 1;
            if(bits[i] == 1)  i++;
        }
        return 0;
    }
};
    
