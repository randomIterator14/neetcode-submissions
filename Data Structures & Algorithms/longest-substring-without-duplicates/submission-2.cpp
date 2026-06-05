class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            zxyzxyz    

        */
        unordered_map<char, int> memo;
        int maxLen = 0, st = -1;
        for (int i = 0;i < s.size();i++) {
            if (memo.find(s[i]) != memo.end()) {
               st = max(st, memo[s[i]]);
            } 
            memo[s[i]] = i;
            maxLen = max(maxLen, i - st);
        }
        return maxLen;
    }
};
