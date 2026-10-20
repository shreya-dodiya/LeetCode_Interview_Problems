#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n); // Allocates memory automatically safely
        
        int start = 0;
        int end = n - 1;
        
        // Fill result from back to front
        for (int i = n - 1; i >= 0; i--) {
            int startSquare = nums[start] * nums[start];
            int endSquare = nums[end] * nums[end];
            
            if (startSquare > endSquare) {
                result[i] = startSquare;
                start++;
            } else {
                result[i] = endSquare;
                end--;
            }
        }
        return result;
    }
};
