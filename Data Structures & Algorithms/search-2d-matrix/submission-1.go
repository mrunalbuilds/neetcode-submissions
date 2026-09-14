func searchMatrix(matrix [][]int, target int) bool {
	//do binary search in each row
	//instead of each row we can check first and last value in row
	//if target is greater just go to next row and do the binary search
	for _, row := range matrix {
		if target > row[len(row)-1] {
            continue
        }

        if target < row[0] {
            return false
        }
		low := 0
		high := len(row) - 1

		for low <= high {
    		mid := low + (high-low)/2

    		if row[mid] == target {
        		return true
    		} else if row[mid] < target {
        		low = mid + 1
    		} else {
        		high = mid - 1
    		}
		}		
	}

	return false
}
