class Solution {
public:
    string minWindow(string s, string t) {
        //have frequency map of string t
        //iterate through s, keep checking if it present in map
        //if it is present start the window

        unordered_map<char,int> freq;

        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }

        unordered_map<char,int> window;
        int minLen = INT_MAX;
        int l=0, r=0;
        int start;
        int count = 0;

        while(r < s.size()){
            //check if r is present
            if(freq.find(s[r]) != freq.end()){
                //start the window
                //end when all the characters from t are covered

                window[s[r]]++;
                if(window[s[r]] <= freq[s[r]]){
                    count++;
                }
            }

            //shrink from l when count is met in window
            while(count == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }

                if (freq.find(s[l]) != freq.end()) {
                    window[s[l]]--;

                    if (window[s[l]] < freq[s[l]])
                        count--;
                }

                l++;
            }

            r++;
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
