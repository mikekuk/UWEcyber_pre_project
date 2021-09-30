#include <stdlib.h>
#include <stdio.h>

// Serial Test - Write a C program that can generate 10,000 pairs of random numbers (e.g., 02, 14). Use an array to count the occurrence of pairs of digits (00 through to 99). The final output should show that the occurrence of each pair is close to 1%.

int random_number(void);

int main(void) {
    // Produce matrix of two interger arrays
    int n = 100000;
    int ** matrix = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        int random1 = random_number();
        int random2 = random_number();

        int * pair = malloc(sizeof(int) * 2);
        *pair = random1;
        *(pair + 1) = random2;
        
        matrix[i] = pair;
    }

    // Produce array for comparison
    int sizeOfCompArray = 20000;
    int comparison_array[sizeOfCompArray];
    int j = 0;
    int k = 0;
    for (int i = 0; i < sizeOfCompArray; i ++)
    {
        k = k % 100;
        if (i % 2) {
            comparison_array[i] = j;
            if (k == 0) {
                j++;
            }
        } else {
            comparison_array[i] = k;
            k++;
        }

    }

    int sizeOfCountAray = 10000;
    int count[sizeOfCompArray];

    //    Count matches
    for (int i = 0; i < sizeOfCompArray; i += 2) {

        for (int j = 0; j < n; j++)
        {
            if (comparison_array[i] == matrix[j][0] && comparison_array[i+1] == matrix[j][1]) {
                count[i/2]++;
            }
        }
        
    }

    // Find mean number of matches
    int sum = 0;
    for (int i = 0; i < sizeOfCountAray; i++)
    {       
        sum += count[i];
    }
    float average = sum/sizeOfCountAray;

    // Find and print percent of matrix for mean
    float percent = (average/n) * 100;
    printf("%0.4f percent is the average for each pair.\n", percent);


    // Free matrix
    for (int i = 0; i < n; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

int random_number(void) {
            return (int) (100.0*rand()/(RAND_MAX + 1.0));
        }