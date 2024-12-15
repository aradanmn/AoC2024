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
    
    // Open the input file
    FILE *infile = FileOpen("/Users/scott/Documents/AoC2024/AoC2024/Day2/day2_input.txt", "r");
    if (infile == NULL) return;
    // Read file and add in levels and create reports
    // Read the file line by line
    int buf;
    int ReportCnt = 0;
    initArray(&reports[ReportCnt], 2);
    char ch;
    while ((ch = fgetc(infile)) != EOF)  // while (fscanf(infile, "%d", &buf) != EOF)
    {
        if (ch == '\n')
        {
            ReportCnt++;
            initArray(&reports[ReportCnt], 2);
        } else if (ch == ' ')
        {
        } else
        {
            addElement(&reports[ReportCnt], ch);
        }
    }
    // print out the reports *this is a test*
    printf("Dynamic array elements:\n");
    for (int row = 0; row < ReportCnt; row++)
    {
        printf("Report %d: ",row+1);
        for (int col = 0; col < reports[row].size; col++)
        {
            printf("%c", reports[row].data[col]);
        }
        printf("\n");
    }
    
    
    for (int row = 0; row < ReportCnt; row++)
    {
        freeArray(&reports[ReportCnt]);
    }
    fclose(infile);
    return;
}
    
