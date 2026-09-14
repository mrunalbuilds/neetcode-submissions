class Solution {
public:
    int characterReplacement(string s, int k) {
        //record frequency of each char
        //replace most number of freq with smallest or == k in the window
        // replacement = window size - max freq

        int l = 0, maxfreq = 0, ans = 0;

        unordered_map<char,int> mp;

        for(int r=0;r<s.size();r++){
            mp[s[r]]++;

            maxfreq = max(maxfreq, mp[s[r]]);

            int replacement = (r-l+1) - maxfreq;

            while( replacement > k){
                mp[s[l]]--;
                l++;
                replacement = (r-l+1) - maxfreq;
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
