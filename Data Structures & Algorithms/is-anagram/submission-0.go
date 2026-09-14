func isAnagram(s string, t string) bool {

	if len(s) != len(t){
		return false
	}

	count := make(map[rune]int)
	for _, char := range s {
		count[char]++;
	}

	for _, char := range t {
		//check if char is present in count,
		//if yes then decrese the count
		// if not then return false
		if count[char] == 0 {
			return false
		}
		count[char]--
	}

	return true
}
