/*Archive a program that allows the user to
  sort through a music libary by artist, album,
  and year. also allows adding and removing albums */
    // By Benji Hillard
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//Defining libarys needed  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//Defines the structure Node 
struct Node
{
	char name[25];
	char title[25];
	int year;
	struct Node *next;
	struct Node *prev;
		
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//Defines the structure Node type BoxP
typedef struct Node* BoxP;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

//defining functions
BoxP build_node(FILE *inputp);
void print_list(struct Node* head, struct Node* temp,  struct Node* tail,FILE *outputp);
void sortbyartist(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp);
void sortbyalbum(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp);
void sortbyyear(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp);
char swap(char *a);
struct Node* wipe(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp);
struct Node* gift(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp);
void menu(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp);
void menu2(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//main
int main(){
	
	 
	BoxP head,temp,tail;    //defines a head tail and temp pointer
	FILE *inputp, *outputp; //defines input and output files
	int i;
        int number_of_cd = 5;   //defines the amount of list iteams/cds
        char choice;
        char choice2;              
        inputp = fopen("input.txt", "r");
	outputp=fopen("output.txt", "w");
        //define head and tail of list structure
	head=build_node(inputp);
	tail=head;
	//builds body of stucture / organizes albums
	for(i=0; i< number_of_cd-1; i++)
	{
	temp=build_node(inputp);
        temp->next=head;
	temp->next->prev=temp;
        head=temp;
	}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// main menu
while(choice!='q' || choice2!='q'){
printf("      _________________________\n");
printf("     |                         |\n");
printf("     |    a) Sort albums       |\n");
printf("     |    b) Add and album     |\n");
printf("     |    c) Remove an album   |\n");
printf("     |    d) Show Albums       |\n");
printf("     |_________________________|\n");
printf(" please choose what you want to do? : ");
scanf("%s",&choice);
printf("\n");
switch(choice){
   case 'a':
      printf("      _________________________\n");
      printf("     |                         |\n");
      printf("     |    a) Sort by Artist    |\n");
      printf("     |    b) Sort by Album     |\n");
      printf("     |    c) Sort by Year      |\n");
      printf("     |_________________________|\n");
      printf(" please choose what you want to do? : ");
      scanf("%s",&choice2);
      printf("\n");
      switch(choice2){
            case 'a':
            sortbyartist(head,temp,tail,outputp);
            
            break;
            case 'b':
            sortbyalbum(head,temp,tail,outputp);
            
            break;
            case 'c':
            sortbyyear(head,temp,tail,outputp);
            
            break;
           }
      break;
   case 'b':
      head = gift(head,temp,tail,outputp);
      
      break;
   case 'c':
      head = wipe(head,temp,tail,outputp);
      
      break;
   case 'd':
      print_list(head,temp,tail,outputp);
      
       }

}
	return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// function scans info from input.txt and creates pointers of each album it into BoxP structure
BoxP build_node(FILE *inputp){

	BoxP temp=NULL;

	temp=(BoxP)malloc(sizeof(struct Node));
	fscanf(inputp, "%s", temp->name);
	fscanf(inputp, "%s",  temp->title);
	fscanf(inputp, " %d", &temp->year);
	temp->next=NULL;
	temp->prev=NULL;
	
	
	return temp;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// function prints all the information in the order it is stored in structure
void print_list(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp){

printf("Printing the list  \n");
for(temp=head; temp!=NULL; temp=temp->next){
     swap(temp->name);
     swap(temp->title);
     printf( "%s, %s, %d \n", temp->name, temp->title, temp->year);
     fprintf(outputp, "%s, %s, %d \n", temp->name, temp->title, temp->year);
    }
printf("\n\n Check the output file output.txt \n\n");




}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// sorting by artist
void sortbyartist(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp){
int i;
BoxP storage;

for(i=0; i<4; i++){
    for(temp=head; temp->next!=NULL; temp=temp->next){
	if(strcmp(temp->name, temp->next->name)>0){
           storage=(BoxP)malloc(sizeof(struct Node));
           strcpy(storage->name,temp->name);
           strcpy(storage->title,temp->title);
           storage->year=temp->year;

           strcpy(temp->name,temp->next->name);
           strcpy(temp->title, temp->next->title);
           temp->year=temp->next->year;

           strcpy(temp->next->name, storage->name);
           strcpy(temp->next->title, storage->title);
           temp->next->year= storage->year;
           }
	}			
}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// sort by album 
void sortbyalbum(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp){
int i;
BoxP storage;

for(i=0; i<4; i++){
    for(temp=head; temp->next!=NULL; temp=temp->next){
	if(strcmp(temp->title, temp->next->title)>0){
           storage=(BoxP)malloc(sizeof(struct Node));
           strcpy(storage->name,temp->name);
           strcpy(storage->title,temp->title);
           storage->year=temp->year;

           strcpy(temp->name,temp->next->name);
           strcpy(temp->title, temp->next->title);
           temp->year=temp->next->year;

           strcpy(temp->next->name, storage->name);
           strcpy(temp->next->title, storage->title);
           temp->next->year= storage->year;
           }
	}			
    }

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// sort by release year
void sortbyyear(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp){
int i;
BoxP storage;

for(i=0; i<4; i++){
    for(temp=head; temp->next!=NULL; temp=temp->next){
	if(temp->year > temp->next->year){
           storage=(BoxP)malloc(sizeof(struct Node));
           strcpy(storage->name,temp->name);
           strcpy(storage->title,temp->title);
           storage->year=temp->year;

           strcpy(temp->name,temp->next->name);
           strcpy(temp->title, temp->next->title);
           temp->year=temp->next->year;

           strcpy(temp->next->name, storage->name);
           strcpy(temp->next->title, storage->title);
           temp->next->year= storage->year;
           }
	}			
    }

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// swap removes underscores from charater arrays
char swap(char *a){

char s = ' ';
char u = '_';
int l = strlen(a);
int i;
for(i=0; i<=l; i++){
   
   if(a[i] == u){
     a[i]= s;
     }
   }
return *a;

}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// delete allows you to remove an album from your libary
struct Node* wipe(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp){
int x = 0;
int y = 0;
int rip;
for(temp=head; temp!=NULL; temp=temp->next){
    x=x+1;
    printf("%d), %s, %s, %d \n",x,temp->name,temp->title,temp->year);
    }
printf("What would you like to remove? :");
scanf("%d",&rip);
printf("\n");
for(temp=head; temp!=NULL; temp=temp->next){
   y=y+1;
   if(rip==1 & y == 1){

             head=head->next;
             head->prev=NULL;
             
             }
   if(rip==x & y == x){
              tail=temp->prev;
              free(temp);
              tail->next=NULL;
             }
   if(rip==y & rip!=1 & rip!=x){
           temp->prev->next=temp->next;
           temp->next->prev=temp->prev;
           free(temp);
           temp->prev=NULL;
           temp->next=NULL;
           } 
    }     
return head;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// gift allows you to add an album to the libary
struct Node* gift(struct Node* head, struct Node* temp, struct Node* tail,FILE *outputp){
char artist[25];
char album[25];
int ryear;
printf("What is the name of the artist? : ");
scanf("%s",artist);
printf("\nWhat is the name of the album? : ");
scanf("%s",album);
printf("\nWhat year was it released? : ");
scanf("%d",&ryear);
temp=(BoxP)malloc(sizeof(struct Node));
strcpy(temp->name,artist);
strcpy(temp->title,album);
temp->year=ryear;
temp->prev=NULL;
temp->next=NULL;
temp->next=head;
head->prev=temp;
head=temp;
return head;
}


