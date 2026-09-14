func topKFrequent(nums []int, k int) []int {
	freq := make(map[int]int)

    for _,num := range nums {
        freq[num]++;
    }

	count := make([][]int,len(nums)+1)
	for num, cnt := range freq {
		count[cnt] = append(count[cnt],num)
	}

	res := []int{}
	for i := len(count)-1; i>0; i-- {
		for _, num := range count[i] {
			res = append(res,num)
			if len(res) == k {
				return res
			}
		}
	}

	return res
}
