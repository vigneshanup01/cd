#include <stdio.h>              // For printf() and scanf()

int main()
{
    int n;                      // Number of states
    int eps[10][10];            // ε-transition matrix
    int closure[10][10] = {0};  // Stores ε-closure

    printf("Enter number of states: "); // Ask for number of states
    scanf("%d", &n);                    // Read number of states

    printf("Enter epsilon transition matrix:\n"); // Ask for matrix

    for(int i = 0; i < n; i++)          // Loop through rows
        for(int j = 0; j < n; j++)      // Loop through columns
            scanf("%d", &eps[i][j]);    // Read each transition

    // Find ε-closure
    for(int i = 0; i < n; i++)          // For every state
    {
        closure[i][i] = 1;              // A state is always in its own closure

        for(int j = 0; j < n; j++)      // Check all states
            if(eps[i][j] == 1)          // If ε-transition exists
                closure[i][j] = 1;      // Add that state to closure
    }

    printf("\nEpsilon Closure:\n");      // Print heading

    for(int i = 0; i < n; i++)          // For every state
    {
        printf("State %d: ", i);        // Print current state

        for(int j = 0; j < n; j++)      // Check all states
            if(closure[i][j])           // If state is in closure
                printf("%d ", j);       // Print that state

        printf("\n");                   // Move to next line
    }

    return 0;                           // End program
}
