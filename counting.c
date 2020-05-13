#include <stdio.h>
void printArray(int size, int A[]);
void countingSort(int size, int* A);
void swap(int *x, int *y);
int max(int size, int A[]);

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
countingSort(size,A);

printArray(size,A);

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

void swap(int *x, int *y){
int temp;
temp=*x;
*x=*y;
*y=temp;
}

void countingSort(int size, int A[]){
int sizeb = max(size,A)+1;
int i;
int B[sizeb];
for(i=0;i<sizeb;i++)
   {
   B[i]=0;
   }
int C[size];

for(i=0;i<size;i++)
   {
   B[A[i]]= B[A[i]]+1;
   }
for(i=0;i<sizeb;i++)
   {
   if(i==0)
    {
    B[i]=B[i];
    }
    else
      {
      B[i]=B[i]+B[i-1];
      }
   }
for(i=0;i<size;i++)
  {
  C[(B[A[i]])-1]=A[i];
  B[A[i]]=B[A[i]]-1;
  }


for(i=0;i<size;i++)
   {
   A[i]=C[i];
   }
}
int max(int size, int A[]){
int i;
int x=0;
for(i=0;i<size;i++)
   {
   if(A[i]>x)
    { 
    x=A[i];
    }
   }

return x;
}
