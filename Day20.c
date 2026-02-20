/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int max_so_far = nums[0];
    int current_max = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > current_max + nums[i]) {
            current_max = nums[i];
        } else {
            current_max = current_max + nums[i];
        }

        if (current_max > max_so_far) {
            max_so_far = current_max;
        }
    }

    return max_so_far;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = maxSubArray(nums, size);
    printf("Maximum Subarray Sum: %d\n", result);

    return 0;
}