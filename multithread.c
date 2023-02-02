#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Variables that hold the final results, integer data type for simplicity
int avgNum;
int minNum;
int maxNum;

// Functions' declaration. Definition is at the bottom
void *avgfunc(void *param);
void *minfunc(void *param);
void *maxfunc(void *param);

int main(int argc, char *argv[])
{
 //printf("start");
 /* Create thread IDs */
    pthread_t aNum, miNum, maNum; /*this creates the values i would like to use to then be able to reference them in the coding for each string*/

/* Create thread attributes */
    pthread_attr_t(attr); /*with this i am allowed to initialise the thread attributes later on as "attr" is shortened from attributes*/

/* Initialize thread attributes */
    pthread_attr_init(&attr); /*This piece of code gets the process started and prepared for multithreading*/

/* Create threads */
//pthread_t tid;                                        /*this creates the thread of strings that are beign used*/
    pthread_create(&aNum, &attr, *avgfunc, argv);
    pthread_create(&miNum, &attr, *minfunc, argv);        /* In this i am giving the strings different functions to follow to be able to carry out their required tasks*/
    pthread_create(&maNum, &attr, *maxfunc, argv);

/* Wait for threads to exit */

    pthread_join(aNum, NULL);
    pthread_join(miNum, NULL);                         /*This is the waiting process for the threads to get a signal to start wokring and multithreading ofr each individual function created*/
    pthread_join(maNum, NULL);

    printf("%d %d %d", avgNum, minNum, maxNum);
}

void *avgfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                          // increment the pointer to point to the first number passed

    int count = 0;
    //int Num = 0;
    int total = 0;

    while(*args != NULL){
        count++;
        total = total + atoi(*args);
    }
    //printf("avg successful");
    // To get a number from args array, use atoi(*args)
    // to increment the pointer to point to the next number: *args++
 
    /* Write the code to calculate the average value and store it in avgNum variable */
   avgNum =total/count;
    pthread_exit(0);


}

void *minfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                        // increment the pointer to point to the first number passed
 
    //int Num, *i, minNum, count=0, sum=0 ;              /*Initialising the values used in the code further on*/
    while(*args!= NULL)
    {
    if(minNum > atoi(*args)){                        /* Number being bigger then the maxNum meaning that this will end up being the highest value*/
        minNum=atoi(*args);}                            /* Saying that the maxNum is the number that is bigger, therefore making this the highest value*/
     //printf("minNum= %d", minNum);                      /*prints the max number value*/;
    }
    //printf("min successful");

 pthread_exit(0);
    // To get a number from args array, use atoi(*args)
    // to increment the pointer to point to the next number: *args++
   
    /* Write the code to calculate the minimum value and store it in minNum variable */
}

void *maxfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                        // increment the pointer to point to the first number passed

//int Num, *i, maxNum, count=0, sum=0;               /*Initialising the values used in the code further on*/
 while(*args != NULL)
 {
    maxNum=atoi(*args); //makes first array the biggest by default

    if(maxNum < atoi(*args))                         /* Number being bigger then the maxNum meaning that this will end up being the highest value*/
    maxNum= atoi(*args);                            /* Saying that the maxNum is the number that is bigger, therefore making this the highest value*/

 //printf("maxNum= %d", maxNum);
 //printf("max successful");                      /*prints the max number value*/
 pthread_exit(0);
 }





    // To get a number from args array, use atoi(*args)
    // to increment the pointer to point to the next number: *args++
   
    /* Write the code to calculate the maximum value and store it in maxNum variable */
 
 

}
