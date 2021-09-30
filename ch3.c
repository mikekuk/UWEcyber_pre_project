#include <stdlib.h>
#include <stdio.h>

// Odd-Even Test – As exercise 2, however this time divide the numbers into odd and even groups. The final output should show 50% in each group.

typedef struct linklist
{
    int val;
    struct linklist * next;
} linklist;


int main(void) {
    int n = 10000;
    int array[n];
    int length_of_array = sizeof(array)/sizeof(int);
    
    // generate the array of randon intergers
    for (int i = 0; i < length_of_array; i++)
    {
        int random_number = (int) (10.0*rand()/(RAND_MAX + 1.0));
        array[i] = random_number;
    }

    // Splits odds and evens into tow link links and counts them
    int odds = 0;
    int evens = 0;
    linklist * headEvens = NULL;
    linklist * headOdds = NULL;
    headEvens = (linklist *) malloc(sizeof(linklist));
    headEvens -> val = '\x0';
    headEvens -> next = NULL;
    headOdds = (linklist *) malloc(sizeof(linklist));
    headOdds -> val = '\x0';
    headOdds -> next = NULL;

    for (int i = 0; i < length_of_array; i++)
    {
        if ((array[i] % 2) == 0)
        {
            if (headEvens ==  NULL) {
                return 1;
            }
            linklist * currentEvens = headEvens;
            while (currentEvens -> next != NULL)
            {
                currentEvens = currentEvens -> next;
            }
            currentEvens -> next = (linklist *) malloc(sizeof(linklist));
            currentEvens -> next -> val = array[i];
            currentEvens -> next -> next = NULL;
            evens++;
        } else {
            if (headOdds ==  NULL) {
                return 1;
            }
            linklist * currentOdds = headOdds;
            while (currentOdds -> next != NULL)
            {
                currentOdds = currentOdds -> next;
            }
            currentOdds -> next = (linklist *) malloc(sizeof(linklist));
            currentOdds -> next -> val = array[i];
            currentOdds -> next -> next = NULL;
            odds++;
    
        }
    }
    
    // Copy link lists into arrays and free heap
    int evens_array[evens];
    int odds_array[odds];

    linklist * current = headEvens;
    for (int i = 0; i < evens; i++)
    {
        evens_array[i] = current -> val;
        linklist * last = current;
        current = current -> next;
        free(last);
    }
    current = headOdds;
    for (int i = 0; i < odds; i++)
    {
        odds_array[i] = current -> val;
        linklist * last = current;
        current = current -> next;
        free(last);
    }
    free(current);
    
    // Print arrays to confirm
    printf("\nEven numbers -");
    for (int i = 0; i < evens; i++)
    {
        printf(" %i,", evens_array[i]);
    }

    printf("\nOdd numbers -");
    for (int i = 0; i < odds; i++)
    {
        printf(" %i,", odds_array[i]);
    }
    
    // Print results summary
    printf("\nEvens = %i, Odds = %i\n", evens, odds);
    return 0;
}