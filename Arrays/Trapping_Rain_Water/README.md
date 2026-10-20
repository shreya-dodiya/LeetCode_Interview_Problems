# 42. Trapping Rain Water (Hard)

## 🔊 Problem Statement
Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

---

## 💡 Core Intuition
Water can only be trapped on top of a single bar if there are taller bars on **both its left and right sides**. 

The height of the water trapped on top of any bar at index `i` is determined by the shortest of the two tallest boundaries surrounding it, minus the height of the bar itself:
\[\text{Water trapped at } i = \min(\text{Max Left Height}, \text{Max Right Height}) - \text{Height}[i]\]

An array with fewer than 3 bars cannot trap any water at all.

---

## 🚀 Algorithmic Approach: Prefix & Suffix Max Arrays
To avoid recalculating the maximum heights repeatedly, we precompute the boundaries using two auxiliary arrays:

1. **Prefix Max Array (`mleft`):** We scan from left to right. `mleft[i]` stores the height of the tallest bar encountered from index `0` up to `i`.
2. **Suffix Max Array (`mright`):** We scan from right to left. `mright[i]` stores the height of the tallest bar encountered from index `n-1` down to `i`.
3. **Water Calculation:** We loop through the array from index `1` to `n-2` (since the absolute ends cannot hold water), apply the intuition formula, and accumulate the total trapped water.

---

## 📊 Complexity Analysis

| Resource | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | **O(n)** | We pass through the array exactly 3 times (once for `mleft`, once for `mright`, and once to calculate the water). |
| **Space Complexity** | **O(n)** | We dynamically allocate two extra memory arrays (`mleft` and `mright`) of size n to store the boundary boundaries. |

---

## 🛠️ Implementation Details
* **Memory Management:** The C-style implementation explicitly uses `malloc()` to allocate memory dynamically based on the exact size of the input array, and executes `free()` at the end of the execution block to prevent memory leaks.
