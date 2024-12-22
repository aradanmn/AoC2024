//
//  Day2.c
//  AoC2024
//
//  Created by Scott Dean on 12/15/24.
//

#include "Day2.h"

struct Report {
    int level[20];
    int numlevels;
};

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
    
    struct Report curReport;
    int SafeReports= 0;
    
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
        
        // Initialize structure report with zeros
        memset(curReport.level, 0, sizeof(curReport.numlevels));
        curReport.numlevels=0;
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
            // Convert string to Integer
            int num = atoi(token);
            // Add number to Report
            curReport.level[curReport.numlevels]=num;
            ++curReport.numlevels;
            // Next token
            token = strtok_r(NULL, delimiters, &saveptr);
        }
        // Determine if the report is safe or not
        if (is_safe_report(curReport.level, curReport.numlevels)) {
            printf("Report is safe\n");
            ++SafeReports;
        } else {
            printf("Report is not safe\n");
        }
    }
    printf("The total number of safe repots is %d\n",SafeReports);
    // Close the file
    fclose(file);
    
    // Free the dynamically allocated Line memory
    free(line);
       
    // Terminate program report success to STDIN
    return 0;
}
    
