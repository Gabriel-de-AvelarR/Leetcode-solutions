class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;
        int middle = 0;

        while(head <= tail){
            middle = head + (tail - head) / 2;
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] < target)
                head = middle + 1;
            else if(nums[middle] > target)
                tail = middle - 1;
        }

        return head;
    }
};