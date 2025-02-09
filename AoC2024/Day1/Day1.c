//
//  Day1.c
//  AoC2024
//
//  Created by Scott Dean on 12/15/24.
//

#include "Day1.h"

// Define a structure to hold each part of numbers (representing a row)
int col1[1000];
int col2[1000];
int similarity_score;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);
    
    // Compare by the first column (col1)
    if (int_a < int_b) {
        return -1;
    } else if (int_a > int_b) {
        return 1;
    } else {
        return 0; // If first columns are equal, keep their order unchanged
    }
}
void Day1(void) {
    int i = 0, sum = 0;
    
    // Open the input file
    FILE *infile = FileOpen("/Users/scott/Documents/AoC2024/AoC2024/Day1/day1_input.txt", "r");
        
    // Read the file line by line, and sum the numbers
    while (fscanf(infile, "%d %d", &col1[i], &col2[i]) != EOF) {
        i++;
    }
    
    // Close the file
    fclose(infile);
    int n = sizeof(col1) / sizeof(col1[0]);
    
    // Sort the array based on teh first column using qsort
    qsort(col1, n, sizeof(int), compare);
    qsort(col2, n, sizeof(int), compare);

    // Output the result
    size_t Length = sizeof(col1) / sizeof(col1[0]);
    
    // FILE *outfile = FileOpen("/Users/scott/Documents/AoC2024/AoC2024/output.txt", "w");
    for (i=0; i < Length; i++) {
        // fprintf(outfile, "%d %d\n", col1[i], col2[i]);
        sum += abs(col1[i]-col2[i]);
    }
    int appears = 0, totals = 0;
    for (i=0; i<Length; i++) {
        appears = 0;
        for(int y=0; y<Length; y++){
            if (col1[i]==col2[y]) {
                appears++;
            }
            totals = col1[i] * appears;
        }
        similarity_score += totals;
    }
    // fclose(outfile);
    printf("The total distance between the lists are:%d\n", sum);
    printf("The similarity score is:%d\n", similarity_score);
    return;
}
