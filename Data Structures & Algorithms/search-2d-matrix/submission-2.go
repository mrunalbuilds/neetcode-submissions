func searchMatrix(matrix [][]int, target int) bool {
	//instead of each row we can check first and last value in row
	//if target is greater just go to next row and do the binary search

	m := len(matrix)
	n := len(matrix[0])

	low := 0
	high := m*n -1 //imagine it as flattened array

	for low <= high {
		mid := low + (high-low)/2

		row := mid/n // n tells the number of elements (no.of columns)
		col := mid%n // 

		if(matrix[row][col] < target){
			low = mid+1
		}else if(matrix[row][col] > target){
			high = mid-1
		}else if(matrix[row][col] == target){
			return true
		}
	}

	return false
}
