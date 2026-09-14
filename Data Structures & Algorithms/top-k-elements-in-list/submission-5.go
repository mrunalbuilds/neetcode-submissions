func topKFrequent(nums []int, k int) []int {
    freq := make(map[int]int)
    maxcount := 0

    for _,num := range nums {
        freq[num]++;
        if freq[num] > maxcount {
            maxcount = freq[num]
        }
    }

    type Pair struct {
        Num int
        Count int
    }

    arr := make([]Pair, 0, len(freq))
    for num, count := range freq {
        arr = append(arr, Pair{Num: num, Count: count})
    }

    sort.Slice(arr, func(i, j int) bool {
		return arr[i].Count > arr[j].Count
	})

    result := make([]int, 0, k)
    for i:=0;i<k;i++ {
        result = append(result, arr[i].Num)
    }

    return result

}
