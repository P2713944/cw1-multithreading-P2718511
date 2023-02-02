#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Variables that hold the final results, integer data type for simplicity
int avgNum;
int minNum;
int maxNum;

int count =0;
int avg =0;
int len;



// Functions' declaration. Definition is at the bottom
void *avgfunc(void *param);
void *minfunc(void *param);
void *maxfunc(void *param);

int main(int argc, char* argv[])
{
 
 /* Create thread IDs */
pthread_t avg1;
pthread_t min1;
pthread_t max1;


/* Create thread attributes */
pthread_attr_t attravg;
pthread_attr_t attrmin;
pthread_attr_t attrmax;

/* Initialize thread attributes */

pthread_attr_init(&attravg);
pthread_attr_init(&attrmin);
pthread_attr_init(&attrmax);

/* Create threads */
pthread_create(&avg1, &attravg, avgfunc, argv);
pthread_create(&min1, &attrmin, minfunc, argv);
pthread_create(&max1, &attrmax, maxfunc, argv);

/* Wait for threads to exit */
pthread_join(avg1,NULL);
pthread_join(min1,NULL);
pthread_join(max1,NULL);


printf("%d %d %d", avgNum, minNum, maxNum);
}

void *avgfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                        // increment the pointer to point to the first number passed

    // To get a number from args array, use atoi(*args)
       while (*args != NULL) {
        avg = avg + atoi(*args); 
        args++; 
        count++;
       }
    avg = avg / count;
    avgNum = avg;
    return 0;
            
    // to increment the pointer to point to the next number: *args++
        
    /* Write the code to calculate the average value and store it in avgNum variable */
 

}
 
void *minfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                        // increment the pointer to point to the first number passed
 
    // To get a number from args array, use atoi(*args)
        int *numbers = (int *) param;
        minNum=numbers[0];   //storing numbers which is 0 into min num!
        for (int i=1; i<len; i++)  //this is for loop which wiil compare valuse interms 
        {
            if(numbers[i]<minNum) //if the element is less then whats stored...
            {
              minNum=numbers[i]; //element that is the min numbers stored will be the min value
            }
        }
        
    // to increment the pointer to point to the next number: *args++
    
    /* Write the code to calculate the minimum value and store it in minNum variable */

 }

void *maxfunc(void *param)
{
    // The following two lines help you to access the arguments (list of numbers) passed to the program
    char** args = (char**) param;   // args is a pointer to array of pointers to main func arguments argv
    args++;                        // increment the pointer to point to the first number passed
  
    // To get a number from args array, use atoi(*args)
        int *numbers = (int *) param;
        maxNum=numbers[0];  //stores element in max num

        for (int i=1; i<len; i++)  //this is for  a loop that looks at differences between max and min
         {
            if(numbers[i]>maxNum) //if its greater it gets stored
          
            {
                maxNum=numbers[i]; //what ever is great will be stores and that will be the nam num
            }
         }
    // to increment the pointer to point to the next number: *args++
    
    /* Write the code to calculate the maximum value and store it in maxNum variable */
 
 

}
