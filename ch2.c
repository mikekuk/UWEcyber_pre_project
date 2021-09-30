#include <stdlib.h>
#include <stdio.h>

// Frequency Test – Write a C program that can generate 10,000 random numbers. Use an array to count the occurrence of each digit (0 through to 9). The final output should show that the occurrence of each digit is close to 10%.

int main(void) {
    int n = 10000;
    int array[n];
    int size_of_array = sizeof(array)/sizeof(int);
    
    // generate the array of randon intergers
    for (int i = 0; i < size_of_array; i++)
    {
        int random_number = (int) (10.0*rand()/(RAND_MAX + 1.0));
        array[i] = random_number;
    }

    // counts the occurance
    int occurances[10] = {0};
    for (int i = 0; i < size_of_array; i++)
    {
        int j = array[i];
        occurances[j]++;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%i - %i\n", i, occurances[i]);
    }
    return 0;
}