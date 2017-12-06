//
//  database.c
//  database
//
//  Created by Shana Moore on 12/6/17.
//  Copyright © 2017 Shana Moore. All rights reserved.

//  Goal: Retrive and manipulate company's payroll database.


#include <stdio.h>

// Declare file pointers
FILE *fpIn;
FILE *fpOut;

#define MAX 100

typedef struct {
    char first[7];
    char initial[1];
    char last[9];
    char street[16];
    char city[11];
    char state[2];
    int age;
    char sex[1];
    int tenure;
    double salary;
} Employee;


// Declare function prototypes
int main(void);
void strsub(char buf[], char sub[], int start, int end);
/* int readInfo(Employee workers[]);
void outputInfo;
void outputMen;
void outputTopWoman;
void outputAvgSalary;
void outputBelowAvgWomen;
void outputAboveAvgMen;
void outputQuery;
void outputRaises; */

int main(void) {
    // Declare variables with appropriate data types
    Employee workers[MAX];

    int i = 0;
    char buf[MAX];
    
    // Open files
    if (!(fpIn = fopen("payfile.txt", "r"))){
        printf("payfile.txt could not be opened for input.");
        return(1);
    } else {
        //readInfo(&workers[EMPLOYEE_COUNT]);
        while(!feof(fpIn)){
            fgets(buf, MAX, fpIn);
            strsub(buf, workers[i].first, 0, 6);
            strsub(buf, workers[i].initial, 8, 8);
            strsub(buf, workers[i].last, 10, 18);
            i++;
        }
        
        printf("%s\n %s\n %s\n", workers[i].first, workers[i].initial, workers[i].last);
        fprintf(fpOut, "%s\n %s\n %s\n", workers[i].first, workers[i].initial, workers[i].last);

    }
    
    fpOut = fopen("csis.txt", "w");

    // Perform functions
    
    // Close files
    fclose(fpIn);
    fclose(fpOut);

    return 0;
}

int readInfo(Employee workers[]){
    // Read file into an array of structs
   /* while(!feof(fpIn)){
        fgets(buf, MAX, fpIn);
        strsub(buf, workers[i].first, 0, 6);
        strsub(buf, workers[i].initial, 8, 8);
        strsub(buf, workers[i].last, 10, 18);
        
    } */
    
    /* while(!feof(fpIn)){
        fscanf(fpIn, "%[^\t]",  &workers[i].first,
                                &workers[i].initial,
                                &workers[i].last);
        i++;
    }
    for (i=0; i< 3; ++i){
        printf("%s %s %s", workers[i].first, workers[i].initial, workers[i].last);
    } */
    return 0;
}

// fx to grab substring, sub, from a string, buf, given the start and end index within the string
void strsub(char buf[], char sub[], int start, int end){
    int i, j;
    
    for(j=0, i=start; i<=end; i++, j++){
        sub[j] = buf[i];
    }
    sub[j] = '\0';
}

