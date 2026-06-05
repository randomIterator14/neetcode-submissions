class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m)
            return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0;i < 26;i++) {
            if (s1Count[i] == s2Count[i])
                matches++;
        }

        int st = 0;
        for (int en = n;en < m;en++) {
            if (matches == 26)
                return true;

            int idx = s2[en] - 'a';
            s2Count[idx]++;

            if (s2Count[idx] == s1Count[idx])
                matches++;
            else if (s2Count[idx] == (s1Count[idx] + 1))
                matches--;

            idx = s2[st] - 'a';
            s2Count[idx]--;

            if (s2Count[idx] == s1Count[idx])
                matches++;
            else if (s2Count[idx] == (s1Count[idx] - 1))
                matches--;

            st++;        
        }
        return matches == 26;
    }
};
