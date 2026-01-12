Missing Number – LeetCode Solution (Multiple Approaches)

This repository contains multiple efficient approaches to solve the “Missing Number” problem from LeetCode.

🧩 Problem Statement

You are given an array nums containing n distinct numbers taken from the range [0, n].
Your task is to find the one number that is missing from the array.

🚀 Approaches Implemented

We solve this problem using three optimized methods, each showcasing a different algorithmic idea.

1️⃣ Sum Formula Approach


	​


Subtract every element of the array from this expected sum — the remainder is the missing number.

Time Complexity: O(n)
Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};

2️⃣ XOR Bit Manipulation Approach

Idea:
XOR has special properties:

a ^ a = 0

a ^ 0 = a

By XORing all indices and all array elements, all numbers cancel out except the missing one.

Time Complexity: O(n)
Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;
        for (int i = 0; i < n; i++) {
            result ^= i;
            result ^= nums[i];
        }
        return result;
    }
};

3️⃣ Binary Search (After Sorting)

Idea:
After sorting, every number should match its index.
If nums[mid] > mid, the missing number is on the left side.

Time Complexity: O(n log n)
Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = n;
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > mid) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};

📊 Comparison
Approach	Time Complexity	Space Complexity	Best Use
Sum Formula	O(n)	O(1)	Simple & fast
XOR	O(n)	O(1)	Avoids overflow
Binary Search	O(n log n)	O(1)	Conceptual practice
🏁 Conclusion

The Sum and XOR approaches are optimal for this problem.
The XOR method is especially powerful when integer overflow is a concern.

This repository demonstrates how the same problem can be solved using mathematics, bit manipulation, and binary search — making it great for interviews and DSA practice.
