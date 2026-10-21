/* 
 * LeetCode 70: Climbing Stairs (Easy)
 * Approach: Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(1) 
 */
class Solution {
public:
    int climbStairs(int n) {
        // using 1D DP Basics
        // TC:O(n)
        // SC:O(1)
        if (n == 1)
            return 1;
        int first = 1;
        int sec = 2;
        for (int i = 3; i <= n; i++) {
            int curr = first + sec;
            first = sec;
            sec = curr;
        }
        return sec;
    }
}; 
//DRY RUN
// n==1 (1) return 1
// n==2 (1+1,2) return 2
// n==3 (1+1+1,1+2,2+1) return 1+2
// n==4 (1+1+1+1,1+2+1,2+1+1,1+1+2,2+2) -> (first=2,sec=3) -> (first=3,sec=5)  return 5
