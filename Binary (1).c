#include<stdio.h>
/* Guessing Game, Benjamin Hillard */ 
void guess();
void main() // Main Program 
{
 
    guess(); // Guessing game function
  
}
 
void guess()
{
    int exit = 0; // defines a value to exit the program
    int low = 0; // defines the lowest number that can be guessed
    int high =0; // defines the highest number that can be guessed
    int middle = 0; // defines the varing middle between the highest and lowest
    int counter = 0; // counts how many guess have been made
    char input = '0'; // records weather s,S (smaller) or l,L(Larger) has been entered
    int  search_space = 0; //defines the range of numbers to be searched
    int number_of_partitions = 1; // defines the maximum amount of guess that should be maid (+1 one to add leave way for hiccups just in case)
 
 
    printf("Please pick a lower bound.\n");//grabs lowest value
    scanf("%d", &low);
    printf("Please pick an upper bound greater by more than four than lower bound.\n");//grabs highest value
    scanf("%d", &high);
    printf("Your number must be between %d and %d .\n", low, high);
    search_space = high; // searchspace high because the amount of guess should be equal to the amount of 
                            //times the highest value needs to be devided by to 2 to hit less than 1
    exit = high + 1;    // exit needs to be one higher than the highest number
while(search_space >  1)
{
 search_space = (search_space)/2; // divdes by to
 number_of_partitions++;
// cut here your searchspace by half and increment the number of partitions
}
printf("I will find out your number with maximum %d questions\n", number_of_partitions);
 
    while(low<=high)
    {
        middle= (high+low)/2; // binary search algorithm
        counter++;
        printf("Question #%d\n", counter);
       
        printf("Enter E if your number is equal to %2d \n", middle);
  printf("Enter L if your number is larger then %2d \n", middle);
  printf("Enter S if your number is smaller then %2d \n", middle);
        scanf(" %c", &input);
        if(input=='E' || input=='e' ){
            printf("OK, told you so!\n");
            printf("I did it with %d questions \n", counter);
            low = exit;
        }
 
  if(input=='L' || input=='l' )
  low = middle;
 
  if(input=='S' || input=='s' )
  high = middle; 

 
  if(input=='L' || input=='l' && counter == number_of_partitions ){
  printf("Your a cheater!!!! \n");
  low = exit;
  }
  if(input=='S' || input=='s' && counter == number_of_partitions ){
  printf("Your a cheater!!!! \n");
  low = exit;
  }
}
                 
   
    printf("Goodbye!\n");
 
}

