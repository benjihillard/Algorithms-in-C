#include<stdio.h> 
#include<stdlib.h>
#include<string.h>


struct family 
{
     char relation[25];
     char fname[25];
     char lname[25];
     
     struct family *child1, *child2, *child3, *married *mother *father;

};

int main(){

    struct family *temp, *root1;
    temp=(struct family* )malloc((sizeof(struct family)));

    // Clancy Bouvier
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Grand Father");
    strcpy(temp->relation,("Grand Father"));
    strcpy(temp->fname,"Clancy");
    strcpy(temp->lname,"Bouvier");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;
    temp->married= NULL;

    root2=temp;

    // Jackeline Bouvier
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Grand Mother");
    strcpy(temp->relation,("Grand Mother"));
    strcpy(temp->fname,"Jackeline");
    strcpy(temp->lname,"Bouvier");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;
    temp->married= NULL;

    root2->married=temp;    
    // Abraham Simpsons
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Grand Father");
    strcpy(temp->relation,("Grand Father"));
    strcpy(temp->fname,"Abraham");
    strcpy(temp->lname,"Simpson");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;
    temp->married= NULL;

    root1 = temp;

    // Mona Simpson
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Grand Mother");
    strcpy(temp->relation,("Grand Monter"));
    strcpy(temp->fname,"Mona");
    strcpy(temp->lname,"Simpson");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;
    temp->married= NULL;

    root1->married= temp;

    //Homer Simpson
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Father");
    strcpy(temp->relation,("Father"));
    strcpy(temp->fname,"Homer");
    strcpy(temp->lname,"Simpson");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;

    root1->child1=temp;

    // Marge Simpson

    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Mother");
    strcpy(temp->relation,("Mother"));
    strcpy(temp->fname,"Marge");
    strcpy(temp->lname,"Simpson");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;
    temp->married= NULL;

    root1->child1->married= temp;

    // Patty Bouvier
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Aunt");
    strcpy(temp->relation,("Aunt"));
    strcpy(temp->fname,"Patty");
    strcpy(temp->lname,"Bouvier");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;
    temp->married= NULL;

    root2->child1=temp;

    // Selma Bouvier
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Aunt");
    strcpy(temp->relation,("Aunt"));
    strcpy(temp->fname,"Selma");
    strcpy(temp->lname,"Bouvier");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;
    temp->married= NULL;

    root2->child2=temp;

    //uncle Herb Simpson
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Uncle");
    strcpy(temp->relation,("Uncle"));
    strcpy(temp->fname,"Herb");
    strcpy(temp->lname,"Simpson");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;

    root1->child2= temp;

    //lisa Simpson
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Sister");
    strcpy(temp->relation,("Sister"));
    strcpy(temp->fname,"Lisa");
    strcpy(temp->lname,"Simpson");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;

    root1->child1->child1=temp;

    //Bart Simpson
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Myself");
    strcpy(temp->relation,("Myself"));
    strcpy(temp->fname,"Bart");
    strcpy(temp->lname,"Simpsons");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;

    root1->child1->child2=temp;

    //Maggie Simpson
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Sister");
    strcpy(temp->relation,("Sister"));
    strcpy(temp->fname,"Maggie");
    strcpy(temp->lname,"Simpson");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;

    root1->child1->child3=temp;

    // Ling Bouvier
    temp=(struct family* )malloc((sizeof(struct family)));
    temp->relation,("Cousin");
    strcpy(temp->relation,("Cousin"));
    strcpy(temp->fname,"Ling");
    strcpy(temp->lname,"Bouvier");
    temp->child1= NULL;
    temp->child2= NULL;
    temp->child3= NULL;
    temp->married= NULL;

    root1->child1->child1=temp;

    printf("%3s,%3s,%3s \n",root1->child1->married->relation,root1->child1->married->fname,root1->child1->married->lname);
    printf("%3s,%3s,%3s \n",root1->child1->child2->relation,root1->child1->child2->fname,root1->child1->child2->lname);




}



 int *x;
        int c = 0;
        printf("Please input the number your looking for: ");
        scanf("%d",x);



                if(*x == temp->data){
                   c = c + 1;   
                   }
                
            }
         if(c>0){
            printf("Yes there are %d number %d is part of the list",c,*x); 
           }
         else{
             printf("Sorry that number is not in the list");
             }
