#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    /*best solution utilizing a map data structure to store the complements*/ 
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> complements_map;
        int index = 0; //manual counter for index
        for(auto it:nums){
            int complement = target - it;
            if(complements_map.find(complement)!=complements_map.end())
                return{complements_map[complement], index};       
            complements_map[it]=index;
            index++;
        }
        return{};
    }

    //another possibility would be to invert the logic
    //complements_map.find(it) != complements_map.end();
    //return{complements_map[it], index};
    //complements_map[complement]=index;
    //ie map's key are complements instead of vector's values

    /* Brute Force Solution: O(n²) Complexity */
    vector<int> twoSumA(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};



