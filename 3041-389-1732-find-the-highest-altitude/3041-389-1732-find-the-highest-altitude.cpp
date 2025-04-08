class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestValue = 0;
        int currentHeight = 0;
        for(int i = 0; i< gain.size(); i++){
            currentHeight = currentHeight + gain[i];
            if(currentHeight > highestValue)
                highestValue = currentHeight;
        }

        return highestValue;
    }
};