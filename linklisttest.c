#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int data;

	struct Node *next, *prev;
};

int main()
{

	struct Node *temp, *head, *temp1, *tail, *above, *below, *erase;

	//constructing the first node
	temp=(struct Node*)malloc(sizeof(struct Node));
	//(*temp).data=5;
	temp->data=5;
	temp->next=NULL;
	temp->prev=NULL;

	//placing head

	head=temp;

	//constructing the second node
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=1;
	temp->next=NULL;
	temp->prev=NULL;

	//connecting the first and the second nodes
	head->next=temp;
	temp->prev=head;

	//constructing the third node
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=3;
	temp->next=NULL;
	temp->prev=NULL;

	//connecting the second and the third node
	head->next->next=temp;
	temp->prev=head->next;

	//constructing the fourth node
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=2;
	temp->next=NULL;
	temp->prev=NULL;

	head->next->next->next=temp;
	temp->prev=head->next->next;






	//printing list forward
printf("Here is our list printed forward \n");
for(temp=head; temp!=NULL; temp=temp->next){
	  printf("%d \n", temp->data);
    }

 //write a loop to place pointer tail to point to the last node

for(tail=head; tail->next!=NULL; tail=tail->next){
         
    }
 // write a loop to print a linked list backward
printf("Here is our list printed backward \n");
for(temp=tail; temp!=NULL; temp=temp->prev){
          printf("%d \n", temp->data);
     }
 //delete a node with 3 and print the resulting list

for(temp=head; temp!=NULL; temp=temp->next){
    if(temp->data==3){
       
	temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        temp->prev=NULL;
        temp->next=NULL;
       }
    }
printf("Here is our list printed forward \n");
for(temp=head; temp!=NULL; temp=temp->next){
	  printf("%d \n", temp->data);
    }
 //delete the last node of the list and print the resulting list backwards

for(temp=head; temp!=NULL; temp=temp->next){
   if(temp == tail){
      tail=temp->prev;
      free(temp);
      tail->next=NULL;
      }
   }
printf("Here is our list printed forward \n");
for(temp=head; temp!=NULL; temp=temp->next){
	  printf("%d \n", temp->data);
    }




	return 0;

}
