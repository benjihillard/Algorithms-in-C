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
    int m1 = 0; // defines the varing middle between the highest and lowest
    int m2 = 0; // defines the varing middle between the highest and lowest
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
 search_space = (search_space)/3; // divdes by to
 number_of_partitions++; // add one for every question that will have to asked
// cut here your searchspace by half and increment the number of partitions
}
printf("I will find out your number with maximum %d questions\n", number_of_partitions);
 
    while(low<=high)
    {
        m1= low + ((high-low)/3);
        m2= (m1 + ((high-low)/3));
        counter++; // add one for evey question asked
        printf("Question #%d\n", counter);
       
  printf("Enter E if your number is equal to %2d", m1);
  printf(" OR %2d \n", m2);    
  printf("Enter L if your number is larger then %2d \n", m2);
  printf("Enter S if your number is smaller then %2d \n", m1);
  printf("Enter I if your number is inbetween %2d", m1);
  printf(" and  %2d \n", m2);
        scanf(" %c", &input);
        if(input=='E' || input=='e' ){
            printf("OK, told you so!\n");
            printf("I did it with %d questions \n", counter);
            low = exit;
        }
 
  if(input=='L' || input=='l' )
  low = m2;
 
  if(input=='S' || input=='s' )
  high = m1;

  if(input=='I' || input=='i'){
  low = m1;
  high = m2; 
  }
 
  if(input=='L' || input=='l' && counter == number_of_partitions ){
  printf("Your a cheater!!!! \n"); // if the number of questions asked is more than predicted (which is mathmatically imposible) so they are cheating
  low = exit;
  }
  if(input=='S' || input=='s' && counter == number_of_partitions ){
  printf("Your a cheater!!!! \n");  // if the number of questions asked is more than predicted (which is mathmatically imposible) so they are cheating
  low = exit;
  }
  if(input=='I' || input=='i' && counter == number_of_partitions ){
  printf("Your a cheater!!!! \n");  // if the number of questions asked is more than predicted (which is mathmatically imposible) so they are cheating
  low = exit;
  }
}
                 
   
    printf("Goodbye!\n");
 
}
