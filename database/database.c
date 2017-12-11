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

// parse file
void copyWorkerLineToStruct(char* buf, Employee* worker);

// output array of structs
void saveDatabase(FILE * fpOut, int employeeCount, Employee workers[]);

// output all workers + details
void outputWorker(FILE * fpOut, Employee workers[]);

// output first and last name of all men
void printMaleWorkers(FILE * fpOut, int employeeCount, Employee workers[]);
 
// output first and last name of highest paid woman
void printHighestPaidFemale(FILE * fpOut, int employeeCount, Employee workers[]);

// output first and last name of lowest paid man
void printLowestPaidMale(FILE * fpOut, int employeeCount, Employee workers[]);

// output average salary
void printAverageSalary(FILE * fpOut, int employeeCount, Employee workers[]);

// output women earning less than average salary
void printLessThanAvgFemales(FILE * fpOut, int employeeCount, Employee workers[]);

// output ratio of men above/below avg salary
void printAvgSalaryMaleRatio(FILE * fpOut, int employeeCount, Employee workers[]);
 
// output first and last name of all employees who make more than 35k, worked for at least 5yrs, and are over 30
void printQuery(FILE * fpOut, int employeeCount, Employee workers[]);

// give 10% raise to all who make less than 350/week, output first and last name and new salary of each who received a raise
void printRaises(FILE * fpOut, int employeeCount, Employee workers[]);


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
    printHighestPaidFemale(fpOut, workerCount, workers);
    printLowestPaidMale(fpOut, workerCount, workers);
    printAverageSalary(fpOut, workerCount, workers);
    printLessThanAvgFemales(fpOut, workerCount, workers);
    printAvgSalaryMaleRatio(fpOut, workerCount, workers);
    printQuery(fpOut, workerCount, workers);
    printRaises(fpOut, workerCount, workers);

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


// SECTION A
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

//SECTION B
void saveDatabase(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("=== SECTION A: %d WORKERS IMPORTED ===\n", employeeCount);
    fprintf(fpOut,"=== SECTION A: %d WORKERS IMPORTED ===\n", employeeCount);

    printf("\n\n=== SECTION B: EMPLOYEE DATABASE ===\n\n");
    fprintf(fpOut,"\n\n=== SECTION B: EMPLOYEE DATABASE ===\n\n");

    for(int i = 0; i < employeeCount; ++i) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t$%.2lf\n", workers[i].first, workers[i].initial, workers[i].last, workers[i].street, workers[i].city, workers[i].state, workers[i].zip, workers[i].age, workers[i].sex, workers[i].tenure, workers[i].salary);
        fprintf(fpOut, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t$%.2lf\n", workers[i].first, workers[i].initial, workers[i].last, workers[i].street, workers[i].city, workers[i].state, workers[i].zip, workers[i].age, workers[i].sex, workers[i].tenure, workers[i].salary);
    }
    return;
}

// SECTION C
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

// SECTION D
void printHighestPaidFemale(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("\n\n=== SECTION D: HIGHEST PAID WOMAN  ===\n\n");
    fprintf(fpOut, "\n\n=== SECTION D: HIGHEST PAID WOMAN ===\n\n");
    double largest = workers[0].salary;
    
    for(int i = 1; i < employeeCount; ++i){
        
        if(workers[i].sex[0] == 'F' && largest < workers[i].salary){
            largest = workers[i].salary;
        }
    }

   for(int i = 0; i < employeeCount; ++i) {

        if(workers[i].salary == largest){
            printf("%s\t%s\n", workers[i].first, workers[i].last);
            fprintf(fpOut, "%s\t%s\n", workers[i].first, workers[i].last);
        }
    }
    return;
}

// SECTION E
void printLowestPaidMale(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("\n\n=== SECTION E: LOWEST PAID MAN  ===\n\n");
    fprintf(fpOut, "\n\n=== SECTION E: LOWEST PAID MAN ===\n\n");
    double lowest = workers[0].salary;
    
    for(int i = 1; i < employeeCount; ++i){
        
        if(workers[i].sex[0] == 'M' && lowest > workers[i].salary){
            lowest = workers[i].salary;
        }
    }
    
    for(int i = 0; i < employeeCount; ++i) {
        
        if(workers[i].salary == lowest){
            printf("%s\t%s\n", workers[i].first, workers[i].last);
            fprintf(fpOut, "%s\t%s\n", workers[i].first, workers[i].last);
        }
    }
    return;
}

// SECTION F
void printAverageSalary(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("\n\n=== SECTION F: AVERAGE EMPLOYEE SALARY  ===\n\n");
    fprintf(fpOut, "\n\n=== SECTION F: AVERAGE EMPLOYEE SALARY ===\n\n");
    double sum = 0;
    
    for(int i = 0; i < employeeCount; ++i) {
        sum += workers[i].salary;
    }
    
    printf("$%.2lf\n", sum/employeeCount);
    fprintf(fpOut, "$%.2lf\n", sum/employeeCount);
    return;
}

// SECTION G
void printLessThanAvgFemales(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("\n\n=== SECTION G: WOMEN EARNING < AVG SALARY  ===\n\n");
    fprintf(fpOut, "\n\n=== SECTION G: WOMEN EARNING < AVG SALARY ===\n\n");
    double sum = 0;
    double avgSalary = 0;
    
    for(int i = 0; i < employeeCount; ++i) {
        sum += workers[i].salary;
    }
    
    avgSalary = sum/employeeCount;
    
    for(int i = 0; i < employeeCount; ++i) {
        
        if(workers[i].sex[0] == 'F' && workers[i].salary < avgSalary){
            printf("%s\t%s\n", workers[i].first, workers[i].last);
            fprintf(fpOut, "%s\t%s\n", workers[i].first, workers[i].last);
        }
    }
    
    return;
}

// SECTION H
void printAvgSalaryMaleRatio(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("\n\n=== SECTION H: RATIO OF MEN EARNING ABOVE/BELOW AVG SALARY  ===\n\n");
    fprintf(fpOut, "\n\n=== SECTION H: RATIO OF MEN EARNING ABOVE/BELOW AVG SALARY ===\n\n");
    double sum = 0;
    double avgSalary = 0;
    float belowAvg = 0;
    float aboveAvg = 0;
    
    for(int i = 0; i < employeeCount; ++i) {
        sum += workers[i].salary;
    }
    
    avgSalary = sum/employeeCount;
    
    for(int i = 0; i < employeeCount; ++i) {
        if(workers[i].sex[0] == 'M' && workers[i].salary < avgSalary){
            belowAvg += 1;
        }
        if(workers[i].sex[0] == 'M' && workers[i].salary > avgSalary){
            aboveAvg += 1;
        }
    }
    
    printf("%.3f : %.3f\n", aboveAvg, belowAvg);
    fprintf(fpOut, "%.3f : %.3f\n", aboveAvg, belowAvg);
    
    return;
}

// SECTION I
void printQuery(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("\n\n=== SECTION I: EMPLOYEES W/ SALARY > $35000/yr, TENURE >= 5yrs, AND AGE > 30  ===\n\n");
    fprintf(fpOut, "\n\n=== SECTION I: EMPLOYEES W/ SALARY > $35000/yr, TENURE <= 5yrs, AND AGE > 30 ===\n\n");
   
    for(int i = 0; i < employeeCount; ++i) {
        
        if(((workers[i].salary * 52) > 35000) && (workers[i].tenure >= 5) && (workers[i].age > 30) ){
            printf("%s\t%s\n", workers[i].first, workers[i].last);
            fprintf(fpOut, "%s\t%s\n", workers[i].first, workers[i].last);
        }
    }
    return;
}

// SECTION J
void printRaises(FILE * fpOut, int employeeCount, Employee* workers) {
    printf("\n\n=== SECTION J: GIVE 10 PERCENT RAISES TO THOSE EARNING < $350 ===\n\n");
    fprintf(fpOut, "\n\n=== SECTION J: GIVE 10 PERCENT RAISES TO THOSE EARNING < $350 ===\n\n");
    
    for(int i = 0; i < employeeCount; ++i) {
        
        if(workers[i].salary < 350){
            workers[i].salary += workers[i].salary * .1;
            
            printf("%s\t%s\t$%.2lf\n", workers[i].first, workers[i].last, workers[i].salary);
            fprintf(fpOut, "%s\t%s\t$%.2lf\n", workers[i].first, workers[i].last, workers[i].salary);
        }
    }
    return;
}
