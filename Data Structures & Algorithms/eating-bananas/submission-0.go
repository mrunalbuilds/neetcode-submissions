func minEatingSpeed(piles []int, h int) int {
	//find max number in array
	//the rate will be between 1 to maxnumber
	// we will use binary search to find the minimum k 
	//in each serch we will calculate the hrs

	max := 0

	for i := 0; i < len(piles); i++ {
        if piles[i] > max {
            max = piles[i]
        }
    } 

	low := 1
	high := max

	answer := max

	for low <= high {
		mid := (high+low)/2

		total := 0
		for _, pile := range piles {
			total += (pile + mid - 1) / mid
		}

		//if mid works, we ned to try even smaller rate
		if total <= h {
        	answer = mid
        	high = mid - 1
    	} else {
        	low = mid + 1
    	}
	}

	return answer
}
