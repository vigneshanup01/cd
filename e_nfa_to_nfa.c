#include <stdio.h>                          // Standard input/output functions

#define MAX 10                               // Maximum number of states

int n, e[MAX][MAX], a[MAX][MAX], b[MAX][MAX]; // ε, a and b transition matrices

// Find ε-closure of a state
void closure(int s, int c[])
{
    c[s] = 1;                                // Add the current state to closure

    for(int i=0; i<n; i++)                  // Check all states
        if(e[s][i] && !c[i])                // If ε-transition exists and not visited
            closure(i, c);                  // Recursively find its ε-closure
}

// Find NFA transition for a given input symbol
void move(int s, int x[][MAX], int ans[])
{
    int c[MAX] = {0};                        // Array to store ε-closure

    closure(s, c);                           // Find ε-closure of current state

    for(int i=0; i<n; i++)                  // Check every state in closure
        if(c[i])                             // If state belongs to closure
            for(int j=0; j<n; j++)           // Check its input transitions
                if(x[i][j])                  // If transition exists
                    ans[j] = 1;              // Add destination to NFA result
}

int main()
{
    printf("Enter number of states: ");      // Ask for number of states
    scanf("%d",&n);                          // Read number of states

    printf("Enter epsilon matrix:\n");       // Read ε-transition matrix
    for(int i=0;i<n;i++)                     // For every row
        for(int j=0;j<n;j++)                 // For every column
            scanf("%d",&e[i][j]);            // Read ε-transition

    printf("Enter a matrix:\n");             // Read 'a' transition matrix
    for(int i=0;i<n;i++)                     // For every row
        for(int j=0;j<n;j++)                 // For every column
            scanf("%d",&a[i][j]);            // Read 'a' transition

    printf("Enter b matrix:\n");             // Read 'b' transition matrix
    for(int i=0;i<n;i++)                     // For every row
        for(int j=0;j<n;j++)                 // For every column
            scanf("%d",&b[i][j]);            // Read 'b' transition

    printf("\nNFA without epsilon:\n");       // Display final NFA

    for(int i=0;i<n;i++)                     // Process every state
    {
        int A[MAX]={0}, B[MAX]={0};          // Store results for a and b

        move(i,a,A);                         // Find transition on 'a'
        move(i,b,B);                         // Find transition on 'b'

        printf("q%d --a--> ",i);             // Print 'a' transition
        for(int j=0;j<n;j++)                 // Check all destination states
            if(A[j]) printf("q%d ",j);       // Print reachable states

        printf("\nq%d --b--> ",i);           // Print 'b' transition
        for(int j=0;j<n;j++)                 // Check all destination states
            if(B[j]) printf("q%d ",j);       // Print reachable states

        printf("\n");                        // Move to next state
    }

    return 0;                                // End program
}
