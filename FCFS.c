#include <stdio.h>

// Structure to represent a process
struct Process {
    int processID;
    int arrivalTime;
    int serviceTime;
    int completionTime;
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

    for (i = 0; i < n; i++) {
        int turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        printf("Process ID: %d, Turnaround Time: %d\n", processes[i].processID, turnaroundTime);
    }
}

// Function to calculate average turnaround time
float calculateAverageTurnaroundTime(struct Process processes[], int n) {
    int totalTurnaroundTime = 0;
    int i;

    for (i = 0; i < n; i++) {
        totalTurnaroundTime += processes[i].completionTime - processes[i].arrivalTime;
    }

    return (float)totalTurnaroundTime / n;
}

int main() {
    // Example processes (you can modify this according to your requirement)
    struct Process processes[] = {
        {1, 0, 5, 0},  // Process ID, Arrival Time, Service Time, Completion Time (initialized as 0)
        {2, 1, 3, 0},  // Modify this array to add more processes
        {3, 2, 8, 0},
        {4, 3, 6, 0},
        {5, 4, 2, 0}
    };

    int numProcesses = sizeof(processes) / sizeof(processes[0]);

    // Calculate completion time for each process
    calculateCompletionTime(processes, numProcesses);

    // Display turnaround time for each process
    printf("Turnaround times for each process:\n");
    calculateTurnaroundTime(processes, numProcesses);

    // Calculate average turnaround time
    float avgTurnaroundTime = calculateAverageTurnaroundTime(processes, numProcesses);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
