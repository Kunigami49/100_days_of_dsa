/*Implement linear search to find key k in an 
array. Count and display the number of 
comparisons performed.*/

#include <stdio.h>

int main() {
    int n, i, k, found = 0, comparisons = 0;
    int arr[100];

    // Input array size
    scanf("%d", &n);

    // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = 1;
            break;
        }
    }

    // Output result
    if (found)
        printf("Found at index %d\n", i);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);

    return 0;
}