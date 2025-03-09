#include <omp.h>
#include <stdio.h>

#define N 1000000  

int main() {
    int arr[N];

   
    for (int i = 0; i < N; i++) {
        arr[i] = (i % 988) + 1;  
    }

    int maxVal;

    
    maxVal = arr[0];
    double start_time_static = omp_get_wtime();

    
    for (int i = 0; i < N; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    double end_time_static = omp_get_wtime();
    double static_time_taken = end_time_static - start_time_static;

   
    maxVal = arr[0];
    double start_time_dynamic = omp_get_wtime();

    
    #pragma omp parallel for reduction(max:maxVal)
    for (int i = 0; i < N; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    double end_time_dynamic = omp_get_wtime();
    double dynamic_time_taken = end_time_dynamic - start_time_dynamic;

 
    printf("Maximum Value: %d\n", maxVal);
    printf("Static Execution Time(parallel): %f seconds\n", static_time_taken);
    printf("Dynamic Execution Time (Parallel): %f seconds\n", dynamic_time_taken);

    return 0;
}
