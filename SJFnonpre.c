#include <stdio.h>

struct Process {
    int processID;
    int burstTime;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void findWaitingTime(struct Process processes[], int n, int waitingTime[]) {
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
    }
}

void findTurnAroundTime(struct Process processes[], int n, int waitingTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void findAverageTime(struct Process processes[], int n) {
    int waitingTime[n], turnAroundTime[n];
    float totalWaitingTime = 0, totalTurnAroundTime = 0;

    sortProcesses(processes, n);

    findWaitingTime(processes, n, waitingTime);

    findTurnAroundTime(processes, n, waitingTime, turnAroundTime);

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];

        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime,
               waitingTime[i], turnAroundTime[i]);
    }

    printf("Average waiting time: %.2f\n", totalWaitingTime / n);
    printf("Average turnaround time: %.2f\n", totalTurnAroundTime / n);
}

int main() {
    struct Process processes[] = { {1, 6}, {2, 8}, {3, 7}, {4, 3} };
    int n = sizeof(processes) / sizeof(processes[0]);

    findAverageTime(processes, n);

    return 0;
}
