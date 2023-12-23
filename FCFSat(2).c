#include <stdio.h>

// Structure to represent a process
struct Process {
    int processID;
    int arrivalTime;
    int serviceTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Function to calculate completion time for each process using FCFS algorithm
void calculateCompletionTime(struct Process processes[], int n) {
    int currentTime = 0; // Initialize current time as 0 for the start
    int i;

    for (i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;

        processes[i].completionTime = currentTime + processes[i].serviceTime;
        currentTime = processes[i].completionTime;
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(struct Process processes[], int n) {
    int i;

    printf("Turnaround times for each process:\n");
    for (i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        printf("Process ID: %d, Turnaround Time: %d\n", processes[i].processID, processes[i].turnaroundTime);
    }
}

// Function to calculate waiting time for each process
void calculateWaitingTime(struct Process processes[], int n) {
    int i;

    printf("Waiting times for each process:\n");
    for (i = 0; i < n; i++) {
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].serviceTime;
        printf("Process ID: %d, Waiting Time: %d\n", processes[i].processID, processes[i].waitingTime);
    }
}

// Function to calculate average turnaround time
float calculateAverageTurnaroundTime(struct Process processes[], int n) {
    int totalTurnaroundTime = 0;
    int i;

    for (i = 0; i < n; i++) {
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    return (float)totalTurnaroundTime / n;
}

// Function to calculate average waiting time
float calculateAverageWaitingTime(struct Process processes[], int n) {
    int totalWaitingTime = 0;
    int i;

    for (i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
    }

    return (float)totalWaitingTime / n;
}

// Function to display Gantt chart for process execution
void displayGanttChart(struct Process processes[], int n) {
    printf("\nGantt Chart:\n");
    printf("-----------\n");

    int i, j;
    // Print process IDs
    for (i = 0; i < n; i++) {
        printf("| P%d ", processes[i].processID);
    }
    printf("|\n");

    // Print time intervals
    printf("0");
    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].serviceTime; j++) {
            printf(" ");
        }
        printf("%d", processes[i].completionTime);
    }
    printf("\n");
}

int main() {
    // Example processes with arrival time 0 milliseconds
    struct Process processes[] = {
        {1, 0, 5, 0, 0, 0},  // Process ID, Arrival Time, Service Time, Completion Time, Turnaround Time, Waiting Time (initialized as 0)
        {2, 0, 3, 0, 0, 0},  // Modify this array to add more processes
        {3, 0, 8, 0, 0, 0},
        {4, 0, 6, 0, 0, 0},
        {5, 0, 2, 0, 0, 0}
    };

    int numProcesses = sizeof(processes) / sizeof(processes[0]);

    // Calculate completion time for each process
    calculateCompletionTime(processes, numProcesses);

    // Display turnaround time for each process
    calculateTurnaroundTime(processes, numProcesses);

    // Display waiting time for each process
    calculateWaitingTime(processes, numProcesses);

    // Calculate average turnaround time
    float avgTurnaroundTime = calculateAverageTurnaroundTime(processes, numProcesses);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    // Calculate average waiting time
    float avgWaitingTime = calculateAverageWaitingTime(processes, numProcesses);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    // Display Gantt chart for process execution
    displayGanttChart(processes, numProcesses);

    return 0;
}
