#include <stdio.h>
int selection(int A[],int x);
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

selection(A,x);

}

int selection(int A[],int x){

int *m;
int *p;
int *r;
for(int i=0; i<x; i++){
   p = &A[i]; 
   m = p;
   for(int j=i; j<x; j++){
      r = &A[j];
      if(*m>*r){
             m = r;
             }
      }
   swap(p,m);
   }
   for(int k=0; k<x; k++){
   printf(" %d",A[k]);

   }
   printf("\n");
}
void swap(int* a, int* b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}


