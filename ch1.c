#include <stdlib.h>
#include <stdio.h>

// Mean Test – Write a C program that can generate 1000 random numbers and calculate the mean. The final output should give a result close to 4.5.

int main(void) {
    int n = 1000;
    int total = 0;
    float average;
    
    for (int i = 0; i < n; i++)
    {
        int random_number = (int) (10.0*rand()/(RAND_MAX + 1.0));
        total += random_number;
    }
    average = total/n;
    printf("%.1f\n", average);
    return 0;
}
