func trap(height []int) int {
    //we need to trap the water
    // so there should be boundaries
    // have left array with max number till i
    // and also right array with max number till i
    // eg: left - 0,2,2,3,3,3,3,3,3,3 right - 3,3,3,3,3,3,3,3,2,1
    // we need to trap is left > [i] and right > [i] (boundaries)

    left := make([]int, 0, len(height))
    right := make([]int, len(height))
    leftmax := 0

    // left
    for i := 0; i < len(height); i++ {
        if height[i] >= leftmax {
            leftmax = height[i]
        }

        left = append(left, leftmax)
    }

    rightmax := 0
    for i := len(height) - 1; i >= 0; i-- {
        if height[i] >= rightmax {
            rightmax = height[i]
        }

        right[i] = rightmax
    }

    trap := 0
    for i := 0; i < len(height); i++ {
        waterLevel := min(left[i],right[i])
        trap += waterLevel - height[i]
    }

    return trap;
}
