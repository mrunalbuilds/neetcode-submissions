class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //merge sort 2 array
        // find 2 mids if array size is even

        //if n1+n2 is even then there should be 2 numbers
        //we can do 2 pointer approach

        //index is (m+n)/2
        // whlie count <= index
        // if j<i
        // j++; count++

        //optimal aaproach
        //divide it into 2 partitions left1, left2 and right1 and right2

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int low = 0;
        int high = nums1.size();

        while (low <= high) {
            int partition1 = (low + high) / 2;

            int leftCount = (nums1.size() + nums2.size() + 1) / 2;
            int partition2 = leftCount - partition1;

            int left1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int right1 = (partition1 == nums1.size()) ? INT_MAX : nums1[partition1];

            int left2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int right2 = (partition2 == nums2.size()) ? INT_MAX : nums2[partition2];

            if (left1 <= right2 && left2 <= right1) {

                if ((nums1.size() + nums2.size()) % 2 == 1) {
                    return max(left1, left2);
                }

                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            else if (left1 > right2) {
                high = partition1 - 1;
            }
            else {
                low = partition1 + 1;
            }
        }

        return 0.0;
        

    }
};
