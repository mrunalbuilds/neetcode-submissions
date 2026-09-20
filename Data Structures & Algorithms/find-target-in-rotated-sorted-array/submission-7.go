func search(nums []int, target int) int {
	low := 0
	high := len(nums)-1

	for low <= high{
		mid := (low+high)/2

		if nums[mid] == target{
			return mid
		}
		
		//left side is not sorted
		//we just compare with sorted side if target is present if not then it is in 
		//unsorted side
		if nums[mid] >= nums[high] {
			if target >= nums[low] && target <= nums[mid]{
				high = mid-1
			}else{
				low = mid+1
			}
		}else{
			if target <= nums[high] && target >= nums[mid]{
				low = mid+1
			}else{
				high = mid-1
			}
		}
	}

	return -1
}
