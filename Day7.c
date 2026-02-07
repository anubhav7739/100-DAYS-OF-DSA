/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6*/

#include <stdio.h>

int main() {
    int n, k, found = 0, comparisons = 0;

    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (scanf("%d", &k) != 1) return 0;

    for (int i = 0; i < n; i++) {
        comparisons++;
        
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    
    if (!found) {
        printf("Not Found\n");
    }

   
    printf("Comparisons = %d\n", comparisons);

    return 0;
}