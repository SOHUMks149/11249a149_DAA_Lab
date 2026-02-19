#include <stdio.h>

int main() {
    int i,j,n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];
    float ratio[n];

    // Step 1: Input and compute ratio
    for(i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &profit[i], &weight[i]);
        ratio[i] = (float)profit[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // Step 2: Sort items by decreasing ratio
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                // Swap ratio
                float tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                // Swap profit
                int tempP = profit[i];
                profit[i] = profit[j];
                profit[j] = tempP;

                // Swap weight
                int tempW = weight[i];
                weight[i] = weight[j];
                weight[j] = tempW;
            }
        }
    }

    // Step 3: Initialize totalProfit
    float totalProfit = 0;

    // Step 4: Select items
    for(i = 0; i < n; i++) {
        if(weight[i] <= W) {
            totalProfit += profit[i];
            W -= weight[i];
        } else {
            float fraction = (float)W / weight[i];
            totalProfit += profit[i] * fraction;
            break;
        }
    }

    // Step 5: Print result
    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}
