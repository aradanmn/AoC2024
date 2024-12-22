//
//  Day2.c
//  AoC2024
//
//  Created by Scott Dean on 12/15/24.
//

#include "Day2.h"

bool is_safe_report(int *report, int size) {
    bool increasing = true, decreasing = true;

    for (int i = 1; i < size; i++) {
        int diff = abs(report[i] - report[i - 1]);
        if (diff < 1 || diff > 3) {
                return false;
            }
        if (report[i] <= report[i - 1]) {
                increasing = false;
            }
        if (report[i] >= report[i - 1]) {
                decreasing = false;
            }
        }

    return increasing || decreasing;
}

int main (int argc, char** argv) {
    
    int TotalReports = 0;
    int Levels = 0;
    // Create a dynamic array to hold the reports
    int **reports = (int **)malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++) {
        reports[i] = (int *)malloc(2 * sizeof(int));
    }
    
    // Open the file of input
    FILE *file = fopen("/Users/scott/Documents/AoC2024/AoC2024/Day2/day2_input.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return -1;
    }
    
    char *line = NULL;  // Pointer for storing the line
    size_t len = 0;     // Size of the line buffer
    ssize_t nread;      // Number of characters read
    
    char *saveptr;      // Store context between calls
    
    // Loop through file and report number of lines read and number of characters read
    while ((nread = getline(&line, &len, file)) != -1) {
        
        // Print the line read from the file
        printf("Retrieved line (%zd chars): %s", nread, line);
        
        // delimiters to break the line up into parts
        const char *delimiters = " \n";
        
        // Break the line into parts based on the delimiter
        char *token = strtok_r(line, delimiters, &saveptr);
        
        // Loop through all the tokens
        while (token != NULL) {
//            printf("Token: %s\n", token);
            if (token == NULL || *token == '\0') {
                // Empty or NULL string
                return -1;
            }
            char *endptr;
        
            // Convert to long in base 10
            long num = strtol(token, &endptr, 10);
            if ((*endptr != '\0') && (*endptr != '\n')) {
                double num = strtod(token, &endptr);
                if ((*endptr != '\0') && (*endptr != '\n')){
                    printf("Unknown type\n");
                } else {
                    // printf("'%f' is a floating porint number.\n", num);
                    reports[TotalReports][Levels]=(int)num;
                    Levels++;
                    reports[TotalReports] = (int *)realloc(reports[TotalReports], Levels * sizeof(int));
                }
            } else {
//                printf("'%ld' is a integer number.\n", num);
                Levels++;
                reports[TotalReports] = (int *)realloc(reports[TotalReports], Levels * sizeof(int));
                reports[TotalReports][Levels]=(int)num;
            }
            // Next token
            token = strtok_r(NULL, delimiters, &saveptr);
        }
        Levels = 0;
        TotalReports++;
        reports = (int **)realloc(reports, TotalReports * sizeof(int *));
        reports[TotalReports] = (int *)malloc(2 * sizeof(int));
    }
    
    // Close the file
    fclose(file);
    
    // Free the dynamically allocated Line memory
    free(line);
    
    for (int i = 0; i <= TotalReports; i++) {
        for (int j = 0; j <= 5; j++) {
            printf(" %d",reports[i][j]);
        }
        printf("\n");
    }
    
    
    // Free memory
    for (int i = 0; i < TotalReports; i++) {
        free(reports[i]);
    }
    free(reports);
    
    // Terminate program report success to STDIN
    return 0;
}
    
