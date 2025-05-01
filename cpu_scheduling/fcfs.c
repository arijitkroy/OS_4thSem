#include <stdio.h>
#define SIZE 20

void main() {
    int i, n, BT[SIZE], WT[SIZE], TAT[SIZE];
    float avgWaitTime = 0, avgTurnAroundTime = 0;
    printf("Number of processes:");
    scanf("%d", &n);
    printf("Enter burst times: ");
    for (i = 1; i <= n; i++) scanf("%d", &BT[i]);
    WT[1] = 0;
    for (i = 2; i <= n; i++) {
        WT[i] = WT[i-1] + BT[i-1];
        avgWaitTime += WT[i];
    }
    avgWaitTime /= 1.0 * n;
    for (i = 1; i <= n; i++) {
        TAT[i] = WT[i] + BT[i];
        avgTurnAroundTime += TAT[i];
    }
    avgTurnAroundTime /= 1.0 * n;
    printf("PID\tBurstT\tWaitT\tTurnAroundT\n");
    for (i = 1; i <= n; i++) printf("%d\t%d\t%d\t%d\n", i, BT[i], WT[i], TAT[i]);
    printf("Average Waiting Time: %0.2f\nAverage Turn Around Time: %0.2f", avgWaitTime, avgTurnAroundTime);
}