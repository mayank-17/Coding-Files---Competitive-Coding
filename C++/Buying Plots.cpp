#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int smallestSubWithSum(int arr[], int n, int x) {
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n + 1;

    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n) {

        // Keep adding array elements while current sum is smaller than x

        while (curr_sum <= x && end < n) {

            // Ignore subarrays with negative sum if x is positive.
            if (curr_sum <= 0 && x > 0) {
                start = end;
                curr_sum = 0;
            }

            curr_sum += arr[end++];
        }
        
        // If current sum becomes greater than x.
        while (curr_sum > x && start < n) {

            // Update minimum length if needed
            if (end - start < min_len) {
                min_len = end - start;
            }

            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = arr[0], MIN = 0;
    int i = 0, j = 0;
    while(i != n) {
        if(sum == k) {
            MIN = min(MIN, j - i + 1);
            sum -= arr[i];
            i++;
        }
        if(sum < k) {
            j++;
            sum += arr[j];
        }
        if(sum > k) {
            sum -= arr[i];
            i++;
        }
    }
    printf("%d", MIN);
    return 0;
}