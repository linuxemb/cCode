#include <stdio.h>
#include <string.h>
// Define FSM states
typedef enum {
    STATE_INITIAL,
    STATE_SECOND,
    STATE_FINAL,
    NUM_STATES
} State;

// Define FSM data structure
typedef struct {
    State currentState;
    // Add any additional data needed for the FSM
    // For simplicity, we'll just use a counter as an example.
    int counter;
} FSMData;

// Function prototypes for state functions
void initialState(FSMData *data);
void secondState(FSMData *data);
void finalState(FSMData *data);

// Array of state function pointers
void (*stateFunctions[NUM_STATES])(FSMData *data) = {
    initialState,
    secondState,
    finalState
};

// State transition function
void transitionToState(FSMData *data, State nextState) {
    data->currentState = nextState;
}

// State functions
void initialState(FSMData *data) {
    printf("Initial State\n");
    data->counter++;
    if (data->counter >= 3) {
        transitionToState(data, STATE_SECOND);
    }
}

void secondState(FSMData *data) {
    printf("Second State\n");
    data->counter++;
    if (data->counter >= 7) {
        transitionToState(data, STATE_FINAL);
    }
}

void finalState(FSMData *data) {
    printf("Final State\n");
    // Final state logic
}
 
 struct emp {
        
        unsigned den   :1;
        unsigned coll  :2;
        char fname[20];
    };
 struct emp worker[20];
int main() {
  
 worker[0].den = 1;    
 worker[0].coll =3;
  strcpy(worker[0].fname, "liha");  // 24 
  //printf("sizeof work0 %d \n", sizeof(worker[0]));
  printf("sizeof emp  %d \n", sizeof(struct emp));
  printf("%d\n", worker[0].coll);
    // Initialize FSM data
    FSMData fsmData;
    fsmData.currentState = STATE_INITIAL;
    fsmData.counter = 0;

    // Main loop
    while (fsmData.currentState != STATE_FINAL) {
        // Execute the current state function
        stateFunctions[fsmData.currentState](&fsmData);
    }

    return 0;
}
