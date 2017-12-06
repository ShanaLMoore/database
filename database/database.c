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
    char zip[5];
    int age;
    char sex[1];
    int tenure;
    double salary;
} Employee;


// Declare function prototypes
int main(void);

// parse input data
void strsub(char buf[], char sub[], int start, int end);

// read file
/* int readInfo(Employee workers[]);
 
// output struct
void outputInfo;
 
// output firt and last name of all men
void outputMen;
 
// output first and last name of highest paid woman
void outputTopWoman;
 
// output avg salary
void outputAvgSalary;
 
// output first and last name of women earning less than avg salary
void outputBelowAvgWomen;
 
// output ratio of men above avg salary to men below avg
void outputAboveAvgMen;
 
// output first and last name of all employees who make more than 35k, worked for at least 5yrs, and are over 30
void outputQuery;
 
// give 10% raise to all who make less than 350/week, output first and last name and new salary of each who received a raise
void outputRaises; */

int main(void) {
    // Declare variables with appropriate data types
    Employee workers[MAX];

    int i = 0;
    char buf[MAX];
    
    // Open files
    fpOut = fopen("csis.txt", "w");

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
            strsub(buf, workers[i].street, 20, 35);
            strsub(buf, workers[i].city, 37, 46);
            strsub(buf, workers[i].state, 48, 49);
            strsub(buf, workers[i].zip, 51, 54);
            strsub(buf, workers[i].age, 56, 59);
            strsub(buf, workers[i].sex, 61, 61);
            strsub(buf, workers[i].tenure, 63, 66);
            strsub(buf, workers[i].salary, 68, 75);
        }
        puts(buf);
        //fprintf(fpOut, "%s\n %s\n %s\n", workers[i].first, workers[i].initial, workers[i].last);

    }
    

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

