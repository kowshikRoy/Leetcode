/*
* Source : https://leetcode.com/problems/longest-word-in-dictionary/description/
* Diff   : Easy
* Author : Repon Kumar Roy
* Date   : 2017-11-09
*/

/*********************************************************************************
* Given a list of strings words representing an English Dictionary, 
* find the longest word in words that can be built one character at a time by other words in words. 
* If there is more than one possible answer, 
* return the longest word with the smallest lexicographical order.
* If there is no answer, return the empty string.

/-----------------------------------------------------------------------------------
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
-------------------------------------------------------------------------------------
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. 
However, "apple" is lexicographically smaller than "apply".
-------------------------------------------------------------------------------------

* Note:
* All the strings in the input will only contain lowercase letters.
* The length of words will be in the range [1, 1000].
* The length of words[i] will be in the range [1, 30].

*********************************************************************************/

/********************************************************************************
* Solution: O(Nlog(N)), Dynamic Programming
* Sort the string decreasing according to their length. 
* For each word, check if the previous word(poping the last character of the word) is possible
* to make. If yes, then this word is also possible. Otherwise, Set the value to -inf.
********************************************************************************/


bool cmp(string a, string b)
{
    return a.length() < b.length();
}
class Solution {
public:
    
    string longestWord(vector<string>& words) {
        unordered_map<string,int> Map;
        sort(words.begin(), words.end(), cmp);
        string ans;
        int cnt = -1;
        for(int i = 0; i < words.size(); i ++ ) {
            if(words[i].size() == 1) {
                Map[words[i]] = 1;
            }
            else {
                string k = words[i]; k.pop_back();
                if(Map.count(k)) Map[words[i]] = 1 + Map[k];
                else Map[words[i]] = -1e8;
            }
            if(Map[words[i]] > cnt || (Map[words[i]] == cnt) && words[i] < ans ) {
                cnt = Map[words[i]];
                ans = words[i];
            }
        }
        return ans;
        
        
    }
};
