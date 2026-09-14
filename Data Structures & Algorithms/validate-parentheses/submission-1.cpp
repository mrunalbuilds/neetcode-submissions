class Solution {
public:
    bool isValid(string s) {
        //can do we 2 pointers
        stack<char> valid;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                valid.push(s[i]);
            }
            else{
                if (valid.empty())
                    return false;
                if(s[i] == ')' && valid.top() == '(' || s[i] == '}' && valid.top() == '{' 
                    || s[i] == ']' && valid.top() == '['){
                            valid.pop();
                }else{
                    return false;
                }
            }
            
        }

        return valid.empty();
    }
};
