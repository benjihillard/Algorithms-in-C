#include <stdio.h>
void printArray(int size, int A[]);
void linear(int size, int A[]);
int rLin(int x, int size, int A[]);

//Variables
int main(){
int size,i,x;

//Create Array
printf("What is the desired size of your array \n");
scanf("%d",&size);

int A[size];

printf("What numbers do you want in your array \n");
for(i=0; i<size; i++)
   {
   scanf("%d", &x);
   A[i]=x;
   }
// Print Array
printArray(size,A);

//search Array

linear(size,A);



}
// function print your array
void printArray(int size, int A[]){
int i;
printf("Your array is: ");
for(i=0; i<size; i++)
   {
   printf(" %d ",A[i]);
   }
printf("\n");
}
// searchs array linearly
void linear(int size, int A[]){
int i,x,c=0;
printf("What is number are you looking for?: ");
scanf("%d",&x);
// set x to the number your looking for then compares and count the amount of that number in the array
for(i=0; i<size; i++)
   {
   if(A[i]==x)
     {
     c=c+1;
     }
   if(c==1 && A[i]==x)
     {
     printf("YES! your number %d exist \n",x);
     }

   }
if(c==0)
   {
   printf("Sorry you nubmber doesnt exist \n");
   }
if(c>1)
   {
   printf("In fact there are %d of them! \n",c);
   }

}

int rLin(int x, int size, int A[]){
if(A[size-1]==x)
  {
  printf("Yes that number exist");
  }
if(A[size]!=x)
  {
  size=size-1;
  }
if(size==-1)
  {
  return 0;
  }



}
