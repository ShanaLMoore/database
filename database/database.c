//
//  database.c
//  database
//
//  Created by Shana Moore on 12/6/17.
//  Copyright © 2017 Shana Moore. All rights reserved.

//  Goal: Retrive and manipulate company's payroll database.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare file pointers
FILE *fpIn;
FILE *fpOut;

#define MAX 100

typedef struct {
    char first[8];
    char initial[2];
    char last[10];
    char street[17];
    char city[12];
    char state[3];
    char zip[6];
    int age;
    char sex[2];
    int tenure;
    double salary;
} Employee;


// Declare function prototypes
int main(void);

// parse input data
void strsub(char buf[], char sub[], int start, int end);

// read file
int parseWorkerDatabaseFile(FILE * fpIn, Employee workers[]);

void copyWorkerLineToStruct(char* buf, Employee* worker);


// output struct
void saveDatabase(FILE * fpOut, int employeeCount, Employee workers[]);
void outputWorker(FILE * fpOut, Employee workers[]);
void printMaleWorkers(FILE * fpOut, int employeeCount, Employee workers[]);


/*
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
void outputRaises;
*/

int main(void) {
    // Declare & assign variables with appropriate data types
    Employee workers[MAX];
    fpIn = NULL;
    fpOut = NULL;
    int workerCount = 0;
    
    // Open files
    fpOut = fopen("csis.txt", "w");
    
    if (!(fpIn = fopen("payfile.txt", "r"))){
        printf("payfile.txt could not be opened for input.");
        return(1);
    }
    
    // Perform functions
    workerCount = parseWorkerDatabaseFile(fpIn, workers);
    saveDatabase(fpOut, workerCount, workers);
    printMaleWorkers(fpOut, workerCount, workers);

    // Close files
    fclose(fpIn);
    fclose(fpOut);

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

int parseWorkerDatabaseFile(FILE* fpIn, Employee workers[]){
    char buf[MAX];
    int line = 0;
    // Read file into an array of structs
    for( ; !feof(fpIn) && fgets(buf, MAX, fpIn); ++line) {
        copyWorkerLineToStruct(buf, workers + line);
    }
    return line;

}

void copyWorkerLineToStruct(char* buf, Employee* worker) {
    char temp[MAX];
    
    strsub(buf, worker->first, 0, 6);
    strsub(buf, worker->initial, 8, 8);
    strsub(buf, worker->last, 10, 18);
    strsub(buf, worker->street, 20, 35);
    strsub(buf, worker->city, 37, 47);
    strsub(buf, worker->state, 49, 50);
    strsub(buf, worker->zip, 52, 56);
    
    strsub(buf, temp, 58, 59);
    worker->age = atoi(temp);
    
    strsub(buf, worker->sex, 61, 61);
    
    strsub(buf, temp, 63, 63);
    worker->tenure = atoi(temp);
    
    strsub(buf, temp, 65, 70);
    worker->salary = (double) atof(temp);
    
    return;
}

void saveDatabase(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("=== SECTION A: %d WORKERS IMPORTED ===\n", employeeCount);

    printf("\n\n=== SECTION B: ALL WORKERS ===\n\n");

    for(int i = 0; i < employeeCount; ++i) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t%.2lf\n", workers[i].first, workers[i].initial, workers[i].last, workers[i].street, workers[i].city, workers[i].state, workers[i].zip, workers[i].age, workers[i].sex, workers[i].tenure, workers[i].salary);
        fprintf(fpOut, "%s\t%s\t%s\n", workers[i].first, workers[i].initial, workers[i].last);
    }
    return;
}

void printMaleWorkers(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("\n\n=== SECTION C: MALE WORKERS ===\n\n");
    fprintf(fpOut, "\n\n=== SECTION C: MALE WORKERS ===\n\n");

    for(int i = 0; i < employeeCount; ++i) {

        if(workers[i].sex[0] == 'M'){
            printf("%s\t%s\n", workers[i].first, workers[i].last);
            fprintf(fpOut, "%s\t%s\n", workers[i].first, workers[i].last);
        }
    }
    return;
}

/*void outputWorkerName(FILE * fpOut, Employee* worker){
    printf("\n\n=== SECTION B: MALE WORKERS ===\n\n");
    
    //  fprint(fpOut, "", ...)
    printf("%s %s\n", worker->first, worker->last);
    fprintf(fpOut, "%s %s\n", worker->first, worker->last);
    return;
}*/

