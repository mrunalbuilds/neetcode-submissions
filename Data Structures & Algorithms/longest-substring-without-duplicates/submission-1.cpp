class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //declare map char and ind
        // if character is found l = mp[s[r]] +1
        // length = r-l+1

        unordered_map<char, int> mp;
        int l = 0, maxLen = 0;

        for(int r=0;r<s.size();r++){
            if (mp.find(s[r]) != mp.end()){
                l = max(l,mp[s[r]]+1);
            }

            maxLen = max(maxLen, r-l+1);
            mp[s[r]] = r;
        }

        return maxLen;
    }
};
