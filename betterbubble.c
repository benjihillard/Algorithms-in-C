#include <stdio.h>
void swap ()
void main ()
{
int list[] = {5,4,3,2,1};
int i, j;
while(list[1]>list[2]>list[3]>list[4]>list[5]){
   for (i = 0; i < 5; i++){

      if(list[i] > list[i+1]){
         swap(list[i], list[i + 1])
      }

   }
printf("%d",list[0]);
printf("%d",list[1]);
printf("%d",list[2]);
printf("%d",list[3]);
printf("%d",list[4]);
printf("\n");
}
}
swap(int x, int y)
{
int temp;
temp = x;
x = y;
y = temp;
}
