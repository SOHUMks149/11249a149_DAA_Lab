#include <stdio.h>
#define MAX 100

void firstFit(int weight[], int n, int capacity) {
    int bin_rem[MAX];
    int binsUsed = 0;
    int i;
    for (i = 0; i < n; i++) {
        int placed = 0;
         int j;
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

    printf("Total bins used (First Fit) = %d\n", binsUsed);
}

int main() {
    int n, capacity;
    int weight[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item weights:\n");
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    firstFit(weight, n, capacity);

    return 0;
}
