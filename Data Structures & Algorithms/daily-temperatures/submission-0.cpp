class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //find the next maximum and result will be length between them
        vector<int> result(temperatures.size(), 0);;
        stack<int> st;
        for(int i=0;i<temperatures.size();i++){
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int top = st.top();

                result[top] = i - top;
                st.pop();
            }

            st.push(i);
        }

        return result;
    }
};
