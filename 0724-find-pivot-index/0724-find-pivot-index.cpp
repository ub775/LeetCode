class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = sum;

        int pastPivotNum = 0;
        for (int idx = 0; idx < nums.size(); idx++) {
            int num = nums[idx];
            rightSum -= num;
            leftSum += pastPivotNum;
            if (leftSum == rightSum) {
                return idx;
            }
            pastPivotNum = num;
        }

        return -1;
    }
};