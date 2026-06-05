class Solution {
private:
    unordered_map<char, int> getCounts(string s) {
        unordered_map<char, int> cnt;
        for (char ch: s) {
            cnt[ch]++;
        }
        return cnt;
    }

    bool contains(unordered_map<char, int> s, unordered_map<char, int> t) {
        for (const auto &[key, value]: t) {
            if (value > s[key])
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        /*
            Shortest String  where cnts(s) match cnts(t)
            Logic: 
            add chars until cnt match, then pop from head and expand again till
        */
        int n = s.size();
        int m = t.size();
        
        if (n < m)
            return "";

        int minLength = INT_MAX;
        int startIdx = -1;
        unordered_map<char, int> tCnts = getCounts(t);
        unordered_map<char, int> sCnts;
        int st = 0, en = 0;

        while (en < n) {
            // expand until equal
            while (en < n && !contains(sCnts, tCnts)) {
                sCnts[s[en]]++;
                en++;
            }
            // shrink until equal
            while (st < en && contains(sCnts, tCnts)) {
                // note en is exclusive
                int length = en - st;
                if (minLength > length) {
                    minLength = min(minLength, length);
                    startIdx = st;
                }
                sCnts[s[st]]--;
                st++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(startIdx, minLength);
    }
};
