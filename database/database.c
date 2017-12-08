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

// Declare constants
#define MAX 100

// Declare file pointers
FILE *fpIn;
FILE *fpOut;

// structure definition
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


// function prototypes
int readInfo(Employee workers[]);
void outputInfo(Employee workers[], int i);

// parse input data
//void strsub(char buf[], char sub[], int start, int end);


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
void outputRaises; */

int main(void) {
    // Declare & assign variables with appropriate data types
    Employee workers[MAX];
    int i = 0;
    
    i = readInfo(workers);
    outputInfo(workers, i);
    
    return 0;
}

int readInfo (Employee workers[]){
    FILE *fpIn;
    char *inputName = "payfile.txt";
    int i = 0;
    char mystring[MAX];
    char * pch;

    
    // Open files
    fpIn = fopen(inputName, "r");
    
    if(fpIn == NULL){
        printf("File cannot be opened\n");
    } else {
        while ( fgets (mystring , 100 , fpIn) != NULL )
            puts (mystring);
        pch = strtok (mystring, "\t");
        while (pch != NULL)
        {
            //handle each token here and insert into struct
            pch = strtok (NULL, "\t");
        }
        fclose (fpIn);
    }
    return 0;
}

void outputInfo(Employee workers[], int i){
    FILE *fpOut;
    char *outputName = "csis.txt";
    int j;
    
    fpOut = fopen(outputName, "w");
    
    /*for(j=0; j<i; j++){
        printf("%s\t%s\t%s\n", workers[i].first, workers[i].initial, workers[i].last );
        fprintf(fpOut, "%s\t%s\t%s\n", workers[i].first, workers[i].initial, workers[i].last );
    } fclose(fpOut); */
}
