func productExceptSelf(nums []int) []int {
	prefix := 1
	prefixArr := make([]int, len(nums))

	for i:=0;i<len(nums);i++ {
		prefixArr[i] = prefix
		prefix *= nums[i]
	}

	suffix := 1
	suffixArr := make([]int, len(nums))

	for i:= len(nums)-1; i>=0; i-- {
		suffixArr[i] = suffix
		suffix *= nums[i]
	}

	result := make([]int, len(nums))
	for i:=0; i<len(nums); i++ {
		result[i] = prefixArr[i]*suffixArr[i]
	}

	return result
}
