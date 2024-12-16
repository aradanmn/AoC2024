//
//  Day2.c
//  AoC2024
//
//  Created by Scott Dean on 12/15/24.
//

#include "Day2.h"

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
    while ((ch = fgetc(infile)) != EOF)  // while (fscanf(infile, "%d", &buf) != EOF)
    {
        if (isdigit(ch))
        {
            number = number * 10 + (ch - '0');
            inNumber = 1;
        } else if (ch == '\n')
        {
            addElement(&reports[ReportCnt], number);
            if (inNumber)
            {
                number = 0;
                inNumber = 0;
            }
            ReportCnt++;
            initArray(&reports[ReportCnt], 2);
        } else if (ch == ' ')
        {
            addElement(&reports[ReportCnt], number);
            if (inNumber)
            {
                number = 0;
                inNumber = 0;
            }
        } else
        {
            /*if (inNumber)
            {
                number = 0;
                inNumber = 0;
            } */
        }
    }
    // print out the reports *this is a test*
    printf("Dynamic array elements:\n");
    for (int row = 0; row < ReportCnt; row++) // this loop is the "Reports"
    {
        safe = true;
        printf("Report %d: ",row+1);
        for (int col = 0; col < (reports[row].size-1); col++) // this loop is the levels
        {
            int x = reports[row].data[col];
            int y = reports[row].data[(col+1)];
            if (abs(x - y) >=4)
            {
                safe = false;
            }
            if (abs(x - y) == 0)
            {
                safe = false;
            }
            printf("%d ", x);
        }
        if (safe == true)
        {
            safeReports++;
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
    
