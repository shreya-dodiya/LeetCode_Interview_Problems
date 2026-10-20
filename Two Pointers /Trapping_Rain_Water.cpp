/* 
 * LeetCode 42: Trapping Rain Water (Hard)
 * Approach: Two-Pointer technique scanning from both ends inward.
 * Time Complexity: O(n)+O(n)+O(n) = O(3n) = O(n)
 * Space Complexity: O(n) 
 */
#include <vector>
#include <cmath>

class Solution { 
public:
    int trap(std::vector<int>& height) {
         // An array with fewer than 3 bars cannot trap any water with (1 or 2) bars
        int n = height.size();
        if (n < 3) return 0;

       
        // Dynamically allocate arrays to match heightSize exactly
        std::vector<int> mleft(n);
        std::vector<int> mright(n);

        mleft[0] = height[0];
        for (int i = 1; i < n; i++) {
            mleft[i] = std::max(mleft[i-1], height[i]);
        }

        mright[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            mright[i] = std::max(mright[i+1], height[i]);
        }

        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            int currwater = std::min(mleft[i], mright[i]) - height[i];
            if (currwater > 0) {
                water = water + currwater;
            }
        }
        // Modern C++ vectors handle memory automatically (no free() needed!)
        return water;
    }
};
