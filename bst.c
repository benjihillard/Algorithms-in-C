#include <stdio.h>
#include <stdlib.h>
void printArray(int size, int A[]);
typedef struct tree_tag
      {
      int data;
      struct tree_tag* left;
      struct tree_tag* right;
      }tree;


void addNode(tree **rt,int data){

tree *temp;

if(*rt == NULL)
  {
    temp = (tree *)malloc(sizeof(tree));
    temp->data = data;
    *rt=temp;
  }
else
   {
   if(data > (*rt)->data)
     {
     addNode(&(*rt)->right,data);
     }
   else
     {
     addNode(&(*rt)->left, data);
     }
   }


}

void printNode(tree *rt){

if(rt->left != NULL)
  {
  printNode(rt->left);
  }
  rt->lef
  
if(rt->right !=NULL)
  {
  printNode(rt->right);
  }


}
void deleteNode(tree *rt, int x){

if(rt->left != NULL || rt->data != x)
  {
  printNode(rt->left);
  }
  
  
if(rt->right !=NULL)
  {
  printNode(rt->right || rt->data != x);
  }

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




int main(){
int size,i,x;
tree* rt = NULL;
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

for(i=0;i<size;i++)
  {
  addNode(&rt,A[i]);
  }

printNode(rt);


printf("what node would you like to add: ");
scanf("%d",&x);
addNode(&rt,x);
printNode(rt);

printf("What node would you like to delete: ");
scanf("%d",&x);
deleteNode();

}








