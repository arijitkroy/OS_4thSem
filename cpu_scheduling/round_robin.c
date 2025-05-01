#include <stdio.h>
#define SIZE 20

void main() {
    int i, n, time = 0, timeQuantum, remainingProcesses, BT[SIZE], RT[SIZE], WT[SIZE], TAT[SIZE];
    float avgWaitTime = 0, avgTurnAroundTime = 0;
    printf("Number of processes: ");
    scanf("%d", &n);
    printf("Enter burst times: ");
    for (i = 1; i <= n; i++) scanf("%d", &BT[i]), RT[i] = BT[i];
    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);
    remainingProcesses = n;
    while (remainingProcesses > 0) {
        for (i = 1; i <= n; i++) {
            if (RT[i] > 0) {
                if (RT[i] > timeQuantum) {
                    time += timeQuantum;
                    RT[i] -= timeQuantum;
                }
                else {
                    time += RT[i];
                    WT[i] = time - BT[i];
                    RT[i] = 0;
                    remainingProcesses--;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        TAT[i] = BT[i] + WT[i];
        avgWaitTime += WT[i];
        avgTurnAroundTime += TAT[i];
    }
    avgTurnAroundTime /= 1.0 * n;
    avgWaitTime /= 1.0 * n;
    printf("PID\tBurstT\tWaitT\tTurnAroundT\n");
    for (i = 1; i <= n; i++) printf("%d\t%d\t%d\t%d\n", i, BT[i], WT[i], TAT[i]);
    printf("Average Waiting Time: %0.2f\nAverage Turn Around Time: %0.2f", avgWaitTime, avgTurnAroundTime);
}