#include <stdio.h>
#define SIZE 20

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int p[], int bt[], int n) {
    int i, j;
    for (i = 1; i <= n - 1; i++) {
        for (j = 1; j <= n - 1; j++) {
            if (bt[j+1] < bt[j]) {
                swap(&bt[j+1], &bt[j]);
                swap(&p[j+1], &p[j]);
            }
        }
    }
}

void main() {
    int i, n, P[SIZE], BT[SIZE], WT[SIZE], TAT[SIZE];
    float avgWaitTime = 0, avgTurnAroundTime = 0;
    printf("Number of processes: ");
    scanf("%d", &n);
    printf("Enter burst times: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &BT[i]);
        P[i] = i;
    }
    sort(P, BT, n);
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
    for (i = 1; i <= n; i++) printf("%d\t%d\t%d\t%d\n", P[i], BT[i], WT[i], TAT[i]);
    printf("Average Waiting Time: %0.2f\nAverage Turn Around Time: %0.2f", avgWaitTime, avgTurnAroundTime);
}