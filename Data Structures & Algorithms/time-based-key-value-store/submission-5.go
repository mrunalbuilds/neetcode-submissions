type Entry struct {
    time int
    value string
}

type TimeMap struct {
    data map[string][]Entry
}

func Constructor() TimeMap {
    return TimeMap {
        data: make(map[string][]Entry),
    }
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
    this.data[key] = append(this.data[key], Entry{
        time: timestamp,
        value: value,
    })
}

func (this *TimeMap) Get(key string, timestamp int) string {
    entries, exists := this.data[key] //entries refer to that founded key
    if !exists {
        return ""
    }

    low := 0
    high := len(entries) - 1

    for low <= high{
        mid := (low+high)/2

        if entries[mid].time <= timestamp{
            low = mid+1
        }else{
            high = mid-1
        }
    }

    if high == -1 {
        return ""
    }

    return entries[high].value
}
