/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/

#include <stdio.h>

int main() {
    int m, n;
    
    // Read dimensions: m (rows) and n (columns)
    if (scanf("%d %d", &m, &n) != 2) {
        return 0;
    }

    long long diag_sum = 0;
    int current_value;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Read each element one by one
            if (scanf("%d", &current_value) != 1) break;

            // Add to sum only if row index == column index
            if (i == j) {
                diag_sum += current_value;
            }
        }
    }

    printf("%lld\n", diag_sum);

    return 0;
}