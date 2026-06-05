class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
            brute: all k windows o(n * k)

            trick use deque + sliding window

            maintain monotonic decreasing while adding at front and evict from back
            when window moves
            
            1 2 1 3
            4 3
            
            2 3
            2 1 
        */
        vector<int> windowMaximums;
        deque<int> dq;
        int n = nums.size();
        for (int i = 0;i < n;i++) {
            // evict stale entries
            while (!dq.empty() && (i - dq.front()) >= k) 
                dq.pop_front();
            // push in monotonically decreasing
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if (i >= (k - 1))
                windowMaximums.push_back(nums[dq.front()]);
        }
        return windowMaximums;
    }
};
