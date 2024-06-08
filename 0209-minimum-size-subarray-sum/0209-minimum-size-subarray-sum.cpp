class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int begin = 0, subSum = 0, subSize = nums.size() + 1;

        for (int end = 0; end < nums.size(); end++) {
            subSum += nums[end];
            while (subSum >= target) {
                subSize = min(subSize, (end - begin + 1));
                subSum -= nums[begin];
                begin++;
            }
        }

        return subSize == nums.size() + 1 ? 0 : subSize;
    }
};