// Purpose: To find the maximum sum of any contiguous subarray within a 1D array.

// A brute force approach would check all subarrays (O(N²)), but Kadane’s Algorithm does it in O(N) by using the idea of Dynamic Programming.

int kadane(vector<int>& nums) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int x : nums) {
        currentSum += x;
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
            currentSum = 0;  
    }
    return maxSum;
}
