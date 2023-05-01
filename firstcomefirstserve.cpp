#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int pid; // process id
    int bt;  // burst time
    int at;  // arrival time
};

void fcfs(vector<Process>& processes) {
    int n = processes.size();
    int wt[n], tat[n], ct[n];
    wt[0] = 0;
    ct[0] = processes[0].bt;
    tat[0] = ct[0] - processes[0].at;
    for (int i = 1; i < n; i++) {
        wt[i] = ct[i-1] - processes[i].at;
        ct[i] = ct[i-1] + processes[i].bt;
        tat[i] = ct[i] - processes[i].at;
    }
    double avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t\t" << processes[i].bt << "\t\t" << processes[i].at << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }
    cout << "Average Waiting Time: " << avg_wt << "\n";
    cout << "Average Turnaround Time: " << avg_tat << "\n";
}

int main() {
    vector<Process> processes = {{1, 6, 0}, {2, 8, 1}, {3, 7, 2}, {4, 3, 3}};
    fcfs(processes);
    return 0;
}
