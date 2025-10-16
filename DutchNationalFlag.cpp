// Purpose: Sort an array containing only 0s, 1s, and 2s in-place using the Dutch National Flag algorithm.
// Time Complexity: O(n) – each element is processed at most once.
// Space Complexity: O(1) – sorting is done in-place without extra space.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;
        while(i <= k){
            if(nums[i] == 0) {
                swap(nums[i], nums[j]);
                j++;
                i++;
            } else if(nums[i] == 2) {
                swap(nums[i], nums[k]);
                k--;
            } else {
                i++;
            }
        }
    }
};
