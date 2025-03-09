#include <stdio.h>
#include <time.h>

#define N 1000000  

int main() {
    int arr[N];

    
    for (int i = 0; i < N; i++) {
        arr[i] = (i % 988) + 1;  
    }

    int  maximumval = arr[0];

    
    clock_t start = clock();

    
    for (int i = 1; i < N; i++) {
        if (arr[i] >  maximumval) {
            maximumval = arr[i];
        }
    }

    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sequential Maximum Value: %d\n",  maximumval);
    printf("Execution Time: %f seconds\n", time_taken);

    return 0;
}