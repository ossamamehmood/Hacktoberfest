#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int process_id;
  int arrival_time;
  int burst_time;
  int completion_time;
  int waiting_time;
  int turnaround_time;
} Process;

void sort_processes_by_arrival_time(Process *processes, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (processes[i].arrival_time > processes[j].arrival_time) {
        Process temp = processes[i];
        processes[i] = processes[j];
        processes[j] = temp;
      }
    }
  }
}

void schedule_processes_fcfs(Process *processes, int n) {
  int current_time = 0;
  for (int i = 0; i < n; i++) {
    if (processes[i].arrival_time <= current_time) {
      processes[i].completion_time = current_time + processes[i].burst_time;
      processes[i].waiting_time = processes[i].completion_time - processes[i].arrival_time - processes[i].burst_time;
      processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
      current_time += processes[i].burst_time;
    }
  }
}

void print_process_schedule(Process *processes, int n) {
  printf("Process ID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time\n");
  printf("----------|--------------|------------|----------------|-------------|----------------\n");
  for (int i = 0; i < n; i++) {
    printf("%10d | %12d | %10d | %14d | %12d | %14d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
  }
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  Process *processes = (Process *)malloc(n * sizeof(Process));
  for (int i = 0; i < n; i++) {
    printf("Enter the process ID, arrival time, and burst time of process %d: ", i + 1);
    scanf("%d %d %d", &processes[i].process_id, &processes[i].arrival_time, &processes[i].burst_time);
  }

  sort_processes_by_arrival_time(processes, n);
  schedule_processes_fcfs(processes, n);

  print_process_schedule(processes, n);

  free(processes);

  return 0;
}
