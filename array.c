// Array Function Program By Benjamin Hillard
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// declare functions
void printArray(int volume, int *x);
void playForwardRecursivly(int x, int *a, int z);
void playBackRecursivly(int x,int *a, int z);
int max(int x, int *a);
int secondMax(int x, int *a);
int min(int x, int *a);
int secondMin(int x, int *a);
void counter(int x, int *a);
void sort(int x,int *a,int low);
void linearSearch(int x, int *a);
void binarySearch(int x, int *a, int low);
void reset(int x, int *a, int *b);
void countingsort(int x, int *a);

main(){
// declare varables
int x,i,j;
char flag; 
int low = 0;      
int high; 
//building array
printf(" please enter how many numbers are in your array: ");
scanf("%d",&x);
high = x-1;
int* a = (int*) malloc(sizeof(int)*x); //allocating memory 
int* b = (int*) malloc(sizeof(int)*x); //allocating memory
printf("please print the numbers you would like in your array: ");
for(i = 0; i < x; i++){
    scanf("%d", &a[i]);
   }
for(j = 0; j < x; j++){
    b[j] = a[j];
   }


// the menu

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
while(flag != 'q'){ 
printf(" __________________________________________________\n|                                                  |\n|   What would you like to do with your array?     |\n|                                                  |\n|  Press 1 for playforward                         |\n|  Press 2 for playback                            |\n|  press 3 for the maximum number                  |\n|  press 4 for the minimum number                  |\n|  press 5 to find the amount of each number       |\n|  press 6 to sort the array in numerical order    |\n|  press 7 for linear search                       |\n|  press 8 for binary search                       |\n|  press 9 to do counting sort                     |\n|  press 0 to reset                                |\n|__________________________________________________|\n");
   printf("            Select option here: ");
   scanf(" %c", &flag);

// here lyes all the option behind the menu

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

switch(flag){
   case '1':
      playForwardRecursivly(x,a,low);
      break;
      
   case '2':
      playBackRecursivly(x,a,high);
      break;
   case '3':
      printf("The maximum number in the array is: %d \n",max(x,a));
      printf("The second maximum number in the array is: %d \n",secondMax(x,a));
      break;
   case '4':
      printf("The minimum number in the array is: %d \n",min(x,a));
      printf("The second minimum number in the array is: %d \n",secondMin(x,a));
      break; 
   case '5':
      counter(x,a);
      break; 
   case '6':
      sort(x,a,low);
      break;
   case '7':
      linearSearch(x,a);
      break; 
   case '8':
      binarySearch(x,a,low);
      break;
   case '9':
      countingsort(x,a);
      break;
   case '0':
      reset(x,a,b);
      break;
    default:
            printf("Sorry thats not one of the option.");
       
   }


  }


}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/* #0 printing array non recursivly
      by looping through the array 
      and stoping at every item and 
      printing it */ 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void printArray(int volume, int *x){

    int i;
    printf("Your array is  ");
    for(i = 0; i < volume; i++){
    printf("%d  ", x[i]);

    }
    printf("\n");
}
/* #1 prints the array forward by printing
      an array item defined by the user in this 
      case the first item and then adding one that 
      number. then the function calls on itself
      to repeat the process until limit in the fuction
      is triggered and the task is killed */
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void playForwardRecursivly(int x, int *a, int z){
printf(" %d ",a[z]);
if(z == x-1){
  printf("\n");
  return; 
  }
else{
    playForwardRecursivly(x,a,(z+1));
    }
}


/* #2 prints the array backwards by printing
      an array item defined by the user in this 
      case the last item and then substracting that 
      number by one. then the function calls on itself
      to repeat the process until limit in the fuction
      is triggered and the task is killed */
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void playBackRecursivly(int x,int *a, int z){
printf(" %d ",a[z]);
if(z == 0){
   printf("\n");
   return;
   }
else{
    playBackRecursivly(x,a,(z-1));
    }
}

/* #3 returns the largest number in the array
      by setting max to zero then running through
      the loop comparing max to each item and assuming
      the value of any item larger than itself */ 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int max(int x, int *a){
int i;
int max = 0;
for(i = 0; i < x; i++){
    if(max < a[i]){
       max = a[i];
       }
    }
return max;
}
/* returns the second largest number in
   the array by grabing the max from an
   outside function. then running through
   the loop setting the first item of the
   array as the second max as long as it 
   is not larger than the max. and then 
   continues in search of larger numbers. */
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int secondMax(int x, int *a){
int i;
int secMax = 0;
int v = max(x,a);
for(i = 0; i < x; i++){
    if(secMax < a[i] && a[i] < v){
       secMax = a[i];
       }
   }
return secMax;
}

/* #3  returns the minimum number of the
       array by grabing the max from an 
       outside function. seting the max 
       as the minimum nubmber then loops 
       throught the array to find smaller 
       numbers. each time setting the smallest
       number as the minimum. */  
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int min(int x, int *a){
int i;
int v = max(x,a);
int min = v;
for(i = 0; i < x; i++){
    if(min > a[i]){
       min = a[i];
       }
    }
return min;
}

/*  returns second minimum value
    by grabing the max and min values
    from other functions then running 
    through the array comparing the 
    current item of the array to the min
    and max. if the current value is smaller
    than the max and but greater than the 
    min it becomes the second min and the 
    loop moves on to the next number in search
    of smaller numbers that fit the criteria */ 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int secondMin(int x, int *a){
int i;
int secMin = max(x,a);
int v = min(x,a);
for(i = 0; i < x; i++){
    if(secMin > a[i] && a[i] > v){
      secMin = a[i];
      }
   }
return secMin;
}

/* #5 counts how many of each number there are
      in the array by setting a pointer to the
      first number in the array, then running
      through the array counting every number 
      eqaul to the pointer. at the end of the 
      array that number in deleted from the array
      and the pointer moves to the next item of 
      the array. */
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void counter(int x, int *a){
int i,j;
int *p;
int *q;
int c = 0;
for(i = 0; i < x; i++){
    p = &a[i];
    for(j = 0; j < x; j++){
        q = &a[j];
        if(*p == *q && p != q){
           c = c + 1;
           *q = 0;
           }
        if(*p == *q && p == q){
           c = c + 1;
           }
        }
    if(*p != 0){
    printf("there are %d amount of %d's \n",c , *p);
    }
    c = 0;
    *p = 0;
    }

}

/*#6 sorts the array into numerical order
     By running through the array comparing
     the current number to the number after
     it. if the number after it is greater 
     than the current number then the numbers
     swap. the loop continues this until the 
     array is ran through with no swaps. */
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void sort(int x,int *a,int low){
int i,j;
int *p;
int *q;
int temp = 0;
int c = 0;
for(i = 0; i < x; i++){

    for(j = 0; j < x; j++){
        p = &a[j];
        q = &a[j + 1];
        if(*p > *q){
           temp = *p;
           *p = *q;
           *q = temp;
            }
         else{
             c = c + 1;
             }
           
        }
    playForwardRecursivly(x,a,low);
    if(c == x){
       i = x;
       }
    c = 0;  
    }

}

/* #7 linear search you tell it a number
   and it checks to see if its in the array
   It does this by running through the array 
   item by item comparing it to the number 
   being searched for if it gets to the end 
   without finding the searched for number 
   then the number does not exist */
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void linearSearch(int x, int *a){
int searchNumber, i, c;
printf("What number are you looking for?: ");
scanf("%d", &searchNumber);
for(i = 0; i < x; i++){
    if(a[i] == searchNumber){
      i = x;
      c = 1;
      printf("YES! %d exist in your array.\n",searchNumber);
      }
      
    }
    if(c != 1){
       printf("Sorry! %d does NOT exist in your array.\n",searchNumber);
       }

}

/* #8 binary search you tell it a number and
      it checks to see if its in the array.
      binary search works placing the array 
      in order then cutting in half based on 
      the number being searched for being higher
      or lower than the current mid point of the 
      array. this contiunes until the only number
      left if either the number being searched for 
      or the place the number would b if the number 
      existed */ 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void binarySearch(int x, int *a, int low){
int searchNumber;
int flag = 0;
int mark = x/2;
int min1 = min(x,a);
int max1 = max(x,a);
printf("What number are you looking for?: ");
scanf("%d", &searchNumber);
sort(x,a, low);
while(flag != 1){
      if(searchNumber > max1 || searchNumber < min1){
          printf("Sorry! %d does NOT exist in your array.\n",searchNumber);
          flag = 1;
          }
      if(searchNumber == a[mark]){
         printf("YES! %d exist in your array.\n",searchNumber);
         flag = 1;
         
        }
      if(searchNumber < a[mark]){
         mark = (mark/2);
         
        }
      if(searchNumber > a[mark]){
         mark = mark + (mark/2);
         
        }
      
     }
}

/* #0 reset sets the array back to zero 
      by replacing the current array with 
      a copy of the array you started with */ 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------        
void reset(int x, int *a, int *b){
int i;
for(i = 0; i < x; i++){
    a[i] = b[i];
   }

}

/*#9 counting sort sorts the numbers in an array 
     by first counting the numbers in an array 
     then finding the position the last of each
     number would go then distributes them backward
     incrimenting down each time until nothing is left
     to distribute*/

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void countingsort(int x, int *a){

int *c;
int *b;
int c_size= max(x,a)+1;
int i,j;
c = (int*)calloc(c_size, sizeof(int)); 	
b = (int*)calloc(x, sizeof(int));
//count 	
for(i=0; i<x; i++){
    c[a[i]]=c[a[i]]+1;
    }
//position
j=-1;
for(i=0; i<c_size; i++){
    if(c[i]!=0){
       j=j+c[i];
       c[i]= j;
       }
    }
//distribute
for(i=x; i>-1; i--){
    b[c[a[i]]]=a[i];
    c[a[i]]=c[a[i]]-1;
    }
printArray(x,b);
}

