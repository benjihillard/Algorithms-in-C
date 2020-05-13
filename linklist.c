#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next, *prev;

};

struct Node* build_node();

struct Node* build_list();
struct Node* place_tail(struct Node* head);
void print_list(struct Node* head, struct Node* tail);
struct Node* delete_firstnode(struct Node* head, struct Node* tail);

int main()
{
	struct Node *head, *temp, *tail;
	int number_of_nodes, i;




	
	 head=build_list();
	 tail=place_tail(head);
	 print_list(head, tail);

	 head=delete_firstnode(head, tail);

	
	
return 0;
	

}

struct Node* build_node()
{

	struct Node *temp;

	temp=(struct Node*)malloc(sizeof(struct Node));
	scanf( "%d", &temp->data);
	
	temp->next=NULL;
	temp->prev=NULL;
	
	
	return temp;
}

struct Node* build_list()
{
	struct Node *head, *temp, *tail;
	int number_of_nodes, i;
	printf("How many numbers do you want to accommodate in a list?  \n");

	scanf("%d", &number_of_nodes);


	printf("Enter %d numbers for the list \n", number_of_nodes);


	for(i=0; i< number_of_nodes; i++)
	{
	
		temp=build_node();
		if(i==0)
			{
				head=temp;
				tail=temp;
			}
		else
		{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		}

	}

	return head;
}

struct Node* place_tail(struct Node* head)
{
	struct Node *temp;
	for(temp=head; temp->next!=NULL; temp=temp->next);

	return temp;

}
 
void print_list(struct Node* head, struct Node* tail)
{
	struct Node *temp;
	
	printf("Printing the list forward \n");
	for(temp=head; temp!=NULL; temp=temp->next)
		printf("%d \n", temp->data);
	printf("\n\n");

	printf("Printing the list backwards\n");
	for(temp=tail; temp!=NULL; temp=temp->prev)
		printf("%d \n", temp->data);
	printf("\n\n");


}

struct Node* delete_firstnode(struct Node* head, struct Node* tail)
{
	int x;
        printf("which node do you want to delete: ");
        scanf("%d",&x);
        struct Node* temp;

	
        for(temp=head; temp!=NULL; temp=temp->next){
            if(temp->data == x){
                 if(temp == head){
                    head=head->next;
	            free(temp);
	            head->prev=NULL;
                    }
                 if(temp == tail){
                    tail=tail->prev;
                    free(temp);
                    tail->next = NULL;
                    }
                 else{
                     temp->prev->next = temp->next;
                     temp->next->prev = temp->prev;
                     free(temp);
                     temp->next=NULL;
                     temp->prev=NULL;
                    }
               }
            }

	printf("Displaying the list after the node is deleted \n");
	 print_list(head, tail);



	 return head;


}
