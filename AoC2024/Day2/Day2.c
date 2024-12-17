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
            diff = abs(report[i+1]-report[i-1]);
            if (diff < 1 || diff > 3) {
                return false;
            }
        }
        if (report[i] <= report[i - 1]) {
            if (report[i+1] >= report[i-1]) {
                increasing = true;
            } else {
                increasing = false;
            }
        }
        if (report[i] >= report[i - 1]) {
            if (report[i+1] <= report[i-1]) {
                decreasing = true;
            } else {
                decreasing = false;
            }
        }
    }

    return increasing || decreasing;
}

void Day2(void)
{
    // Create a pointer array to the DynamicArray struct
    DynamicArray *reports = (DynamicArray *)malloc(2 * sizeof(DynamicArray *));
    bool safe;
    int safeReports = 0 ;
    
    // Open the input file
    FILE *infile = FileOpen("/Users/scott/Documents/AoC2024/AoC2024/Day2/day2_input.txt", "r");
    if (infile == NULL) return;
    // Read file and add in levels and create reports
    // Read the file line by line
    int ReportCnt = 0;
    initArray(&reports[ReportCnt], 2);
    char ch;
    int number = 0;
    int inNumber = 0;
    while ((ch = fgetc(infile)) != EOF)
    {
        // converts > single digits into a single interger
        if (isdigit(ch))
        {
            number = number * 10 + (ch - '0');
            inNumber = 1;
        } else if (ch == '\n') // dectect newline and add any number to array
        {
            addElement(&reports[ReportCnt], number); //Add number to array
            if (inNumber)
            {
                number = 0; //reset number
                inNumber = 0; //reset is it a number?
            }
            ReportCnt++;
            initArray(&reports[ReportCnt], 2);
        } else if (ch == ' ') // dectect a space and add any number to the array
        {
            addElement(&reports[ReportCnt], number);
            if (inNumber)
            {
                number = 0;
                inNumber = 0;
            }
        } else
        {
        }
    }
    // print out the reports *this is a test*
    printf("Dynamic array elements:\n");
    // This section initially verified we've ingested the input correctly
    // i.e. the printf statements.
    for (int row = 0; row < ReportCnt; row++) // this loop is the "Reports"
    {
        safe = true;
        printf("Report %d: ",row+1);
        if (is_safe_report(reports[row].data, reports[row].size))
        {
            safeReports++;
        }else
        {
            safe = false;
        }
        for (int col = 0; col < (reports[row].size); col++) // this loop is the levels
        {
            printf("%d ", reports[row].data[col]);
        }
        if (safe == true)
        {
            printf(" Report is Safe\n");
        }
        else
        {
            printf(" Report is Unsafe\n");
        }
    }
    printf("Total Safe reports %d\n",safeReports);
    
    for (int row = 0; row < ReportCnt; row++)
    {
        freeArray(&reports[ReportCnt]);
    }
    fclose(infile);
    return;
}
    
