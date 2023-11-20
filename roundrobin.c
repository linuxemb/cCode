#include <stdio.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

void getStudnt(Student ** student) {
    *student = stu;
}

void roundRobinScheduler(struct Process processes[], int num_processes) {
    int time = 0;

    while (1) {
        int all_finished = 1;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                all_finished = 0;

                if (processes[i].remaining_time > TIME_QUANTUM) {
                    printf("Executing process %d for time quantum %d\n", processes[i].id, TIME_QUANTUM);
                    processes[i].remaining_time -= TIME_QUANTUM;
                    time += TIME_QUANTUM;
                } else {
                    printf("Executing process %d for remaining time %d\n", processes[i].id, processes[i].remaining_time);
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                }
            }
        }

        if (all_finished) {
            break;
        }
    }
}

int main() {

    struct Process processes[MAX_PROCESSES] = {
        {1, 8, 8},
        {2, 8, 9},
        {3, 5, 9},
        {4, 4, 4}
    };
    // Student student;
    // getStudnt(&student);
    student.print();
    int num_processes = 4;
    printf("Round-Robin Scheduler Simulation\n");
    roundRobinScheduler(processes, num_processes);

    return 0;
}
