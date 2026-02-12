#include <stdio.h>
#define MAX 100

int main() {
    int weight[MAX], bin_rem[MAX];
    int n, capacity;
    int i, j, binsUsed = 0, placed, temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item weights:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    /* Sort in decreasing order (simple bubble sort) */     
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (weight[j] < weight[j + 1]) {
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }

    /* First Fit logic */
    for (i = 0; i < n; i++) {
        placed = 0;

        for (j = 0; j < binsUsed; j++) {
            if (bin_rem[j] >= weight[i]) {
                bin_rem[j] -= weight[i];
                placed = 1;
                break;
            }
        }

        if (!placed) {
            bin_rem[binsUsed] = capacity - weight[i];
            binsUsed++;
        }
    }

    printf("Total bins used (First Fit Decreasing) = %d\n", binsUsed);
    return 0;
}
