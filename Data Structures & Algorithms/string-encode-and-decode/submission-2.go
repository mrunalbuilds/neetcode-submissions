type Solution struct{}

func (s *Solution) Encode(strs []string) string {
	//easier way, just add length and # before string
    //strings.Builder is Go's efficient way to build a string by appending pieces to it. It's similar to C++'s std::ostringstream or using a std::string with repeated +=, but optimized to avoid creating many intermediate strings.
    var res strings.Builder
    for _, str := range strs {
        res.WriteString(strconv.Itoa(len(str)))
        res.WriteByte('#')
        res.WriteString(str)
    }

    return res.String();
}

func (s *Solution) Decode(encoded string) []string {
    res := []string{};
    i := 0

    for i<len(encoded){
        j := i
        for encoded[j] != '#' {
            j++
        }

        length, _ := strconv.Atoi(encoded[i:j])
        i = j+1
        res = append(res, encoded[i:i+length])
        i += length
    }

    return res;
}
