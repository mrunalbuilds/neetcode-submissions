class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            // remove elements that cannot be the left boundary
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            // if stack is empty, there is no smaller element on left
            // otherwise, stack top is the left boundary
            if(st.empty()){
                left[i] = -1;
            }else{
                left[i] = st.top();
            }
            // current index becomes a candidate for future bars
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            // if stack is empty, there is no smaller element on right
            // otherwise, stack top is the right boundary
            if(st.empty()){
                right[i] = n;
            }else{
                right[i] = st.top();
            }
            // current index becomes a candidate for future bars
            st.push(i);
        }

        int area = 0;
        for(int i=0;i<n;i++){
            int width = right[i]-left[i]-1;
            area = max(area, heights[i]*width);
        }

        return area;
    }
};
