class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> complements_map;
        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];

            if(complements_map.find(current) != complements_map.end()){
                return {complements_map[current], i};
            }
            complements_map[target - current] = i; 
        }

        return{};
    }



    //solucao O(n^2)
    vector<int> twoSumPiorVersao(vector<int>& nums, int target) {
        vector <int> positions;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target)
                    positions = {i, j};
            }
        }

        return positions;
    }
};