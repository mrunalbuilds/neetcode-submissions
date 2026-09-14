class Solution {
public:
    int trap(vector<int>& height) {
        //we need to trap the water
        // so there should be boundaries
        // have left array with max number till i
        // and also right array with max number till i
        // eg: left - 0,2,2,3,3,3,3,3,3,3 right - 3,3,3,3,3,3,3,3,2,1
        // we need to trap is left > [i] and right > [i] (boundaries)

        // we can also do it in one go
        //check max left and use min height to calculcate trap water
        //optimal solution with 2 pointers
        //we keep checking if l<r or r<l to make sure there is higher wall on right and left
        int l=0,r=height.size()-1;
        int trapped = 0;
        int maxRight = 0, maxLeft = 0;
        while(l<=r){
            if(height[l] <= height[r]){
                if(height[l] < maxLeft){
                    trapped += (maxLeft - height[l]);
                }else if(height[l] >= maxLeft)
                    maxLeft = height[l];
                l++;
            }else{
                if(height[r] < maxRight){
                    trapped += (maxRight - height[r]);
                }else if(height[r] >= maxRight)
                    maxRight = height[r];
                r--;
            }
        }

        return trapped;
    }
};
