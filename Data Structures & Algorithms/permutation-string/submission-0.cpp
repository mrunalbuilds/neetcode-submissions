class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //create a frequency map
        //using sliding window check if the sub string frequencies in hash map
        //have sliding window of length of s1

        unordered_map<char,int> freq;
        for(int i=0;i<s1.size();i++){
            freq[s1[i]]++;
        }

        int i=0, j=0;
        unordered_map<char,int> window;

        while(j < s2.size()){
            window[s2[j]]++;
            int len = j-i+1;
            if(len < s1.size()){
                j++;
            }else if(len == s1.size()){
                if (window == freq)
                    return true;

                window[s2[i]]--;
                if (window[s2[i]] == 0)
                    window.erase(s2[i]);

                i++;
                j++;
            }
        }

        return false;
    }
};
