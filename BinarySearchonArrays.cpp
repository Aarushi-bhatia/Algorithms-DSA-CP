// Purpose: Finds the k-th smallest element in the union of two sorted arrays using binary search.
// Time & Space Complexity: Runs in O(log min(n, m)) time and O(1) extra space, where n and m are the sizes of the two arrays.

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        if(n > m) return kthElement(b, a, k);
        
        int low = max(0, k-m), high = min(n, k);
      
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = k - cut1;
            int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : a[cut1];
            int r2 = cut2 == m ? INT_MAX : b[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1, l2);
            } else if(l1 > r2){
                high = cut1 - 1;
            } else{
                low = cut1 + 1;
            }
        }
        return 1;
    }
};
