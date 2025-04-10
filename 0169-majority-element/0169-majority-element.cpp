class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elementsOcurrences;
        
        for(auto it : nums){
            if(elementsOcurrences.find(it) != elementsOcurrences.end())
                elementsOcurrences[it]++;            
            else 
                elementsOcurrences[it] = 1;
 
            if(elementsOcurrences[it] > nums.size() / 2)
                return it;
        }

        return 0;
    }
};