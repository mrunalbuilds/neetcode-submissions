func findMin(nums []int) int {
	// we can also do mid-1 and mid+1, but calculate min in each condition
	// we will have a variable storing the min value
	low := 0
    high := len(nums)-1
    ans := math.MaxInt
    for low <= high {
        mid := (low+high)/2
        if nums[low] <= nums[high]{
            ans = min(ans,nums[low])
            return ans
        }

        if nums[high] > nums[mid]{
            ans = min(ans,nums[mid])
            high = mid-1
        }else {
            ans = min(ans,nums[low])
            low = mid+1
        }
    }
    return 0
}
