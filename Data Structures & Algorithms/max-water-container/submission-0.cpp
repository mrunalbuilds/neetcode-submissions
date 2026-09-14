class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int area = 0;
        while( l < r){
            int product = (r-l) * (min(heights[l],heights[r]));
            area = max(product,area);

            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }

        return area;
    }
};
