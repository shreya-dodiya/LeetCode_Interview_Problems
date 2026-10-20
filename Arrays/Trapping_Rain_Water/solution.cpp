#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;

        // Modern C++ vectors handle memory automatically (no free() needed!)
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
                water += currwater;
            }
        }

        return water;
    }
};
