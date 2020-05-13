#include <stdio.h>
int insertion(int A[],int x);
void swap(int *a, int *b);


int main(){

int x;
int y;
printf("Please input the size of your array: \n" );
scanf("%d",&x);
int A[x];
for(int i=0; i<x; i++){
   scanf("%d",&y);
   A[i]=y;
   
   }

insertion(A,x);

}
//---------------------------------------------------------
int insertion(int A[],int x){
int i,j;
int divider;
for(i=0; i<x; i++){
   divider = A[i];
   j=i-1;
   while(j>=0 && A[j]>divider){
        A[j+1]=A[j];
        j--;
        }
   A[j+1]=divider;
   
   }
for(int k=0; k<x; k++){
   printf(" %d",A[k]);

   }
   printf("\n");
}


//--------------------------------------------------------
void swap(int* a, int* b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}


