#include <stdio.h>
void printArray(int size, int A[]);
void binary(int size, int* A);
void bubble(int size, int* A);
void swap(int *x, int *y);
void rb(int A[], int x, int high, int low);

//Variables
int main(){
int size,i,x,s;

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

bubble(size,A);
printf("What number are you looking for: \n");
scanf("%d",&s);
rb(A,s,size,0);


}

void printArray(int size, int A[]){
int i;
printf("Your array is: ");
for(i=0; i<size; i++)
   {
   printf(" %d ",A[i]);
   }
printf("\n");
}

void rb(int A[], int x, int high, int low){

int mid=((high+low)/2);
if(low>=high-1)
  {
  printf("sorry fam %d dont exist\n",x);
  return;
  }
if(A[mid]==x)
  {
  printf("rest assured %d is there fam\n",x);
  return;
  }
if(A[mid]>x)
  {
  high=mid;
  rb(A,x,high,low);
  }
if(A[mid]<x)
  {
  low=mid;
  rb(A,x,high,low);
  }

}

void bubble(int size, int* A){
int i,j,temp;
for(i=0; i<size; i++)
   {
   for(j=0; j<size; j++)
      {
      if(A[i]<A[j])
        {
        swap(&A[i],&A[j]);
        }
      }
   }

}

void swap(int *x, int *y){
int temp;
temp=*x;
*x=*y;
*y=temp;
}
