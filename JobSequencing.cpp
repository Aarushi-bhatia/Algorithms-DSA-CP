class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> v;
        int jobs = 0, maxi = 0;
        for(int i = 0; i < n; i++){
            v.push_back({deadline[i], profit[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int idx = n - 1;
        for(int i = v[n-1].first; i >= 1; i--){
            while(idx >= 0 && i==v[idx].first){
                pq.push(v[idx].second);
                idx--;
            }
            if(!pq.empty()){
                jobs++;
                maxi += pq.top();
                pq.pop();
            }
        }
        return {jobs, maxi};
    }
};
