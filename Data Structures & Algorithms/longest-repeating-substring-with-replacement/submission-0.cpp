class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            XYYX k =2
            k - maxCount >= 0
            XYYX

            AAABABB
            AAAB

            while k - maxCount >= 0 expand right
            then start shrinking
        */
        int n = s.size();
        int maxF = 0, l = 0;
        int maxLength = 0;
        unordered_map<char, int> cnt;

        for (int r = 0;r < n;r++) {
            cnt[s[r]]++;
            maxF = max(maxF, cnt[s[r]]);

            while((r - l + 1 - maxF) > k) {
                cnt[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
