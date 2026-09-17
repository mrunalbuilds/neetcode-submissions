func findMin(nums []int) int {
	//min = mid
	//if mis > low && mid > high thne if high > low search in second ahlf
	//else in first
	//if mid is lesser than both low and high then tha is minimum

	low := 0
	high := len(nums)-1

	for low < high {
		mid := (low+high)/2

		if nums[mid] > nums[high]{
			low = mid+1
		}else if nums[mid] < nums[high]{
			high = mid
		}
			
		
	}

	return nums[low]
}
