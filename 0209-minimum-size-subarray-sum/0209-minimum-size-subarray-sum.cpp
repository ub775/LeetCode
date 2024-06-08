class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int subSize = 0;
        int begin = 0;
        int end = 0;
        int subSum = 0;

        for (end=0; end < nums.size(); end++) {
            subSum += nums[end];
            while (subSum - nums[begin] >= target && begin <= end) {
                subSum -= nums[begin];
                begin++;
            }
            if (target <= subSum) {
                if (subSize == 0 || subSize > (end - begin + 1))
                    subSize = (end - begin + 1);
            }
        }

        return subSize;
    }
};