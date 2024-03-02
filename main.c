/*
author :John Remon Maher
date   : 1/3/2024

features of the program
-this program will not allow two customers to have the same id
-this program is done using linked list so the only limit is the memory limit unlike if
 it was made using structure array that is have limit will writing the code which means that
 the adding is dynamic during the code
-this program can print the whole linked list or print a specific node
- can edit in a specific node without destroying the other nodes
-can delete any node even if it was the first node and the whole linked list will connect again
-the program can transfer cash between customers
-every function has a function description explain how the function work
*/

#include "functions.h"



int main()
{
    customer *head ; //this is the head pointer that will have always the first node address in it (this is a pointer to the structure node )
    head = NULL; //in the beginning that pointer must have null
    unsigned int choice = 0;
    unsigned char id = 0;
   printf ("please choose a choice : \n");
   printf ("1- create a new customer \n");
   printf ("2- edit customer data \n");
   printf ("3- print customer data \n");
   printf ("4- delete customer data \n");
   printf ("5- cash transfer \n");
   printf ("6- print the whole list \n\n\n");
   while (1)
   {
    choice = 0;
    printf ("your choice: ");
    scanf ("%i",&choice);
    fflush(stdin);

       switch (choice)
    {
     case 1 :
         creat_a_new_customer(&head,head);
     break ;
     case 2 :
         edit_customer_data( head );
     break ;
     case 3 :
         id = 0 ;
         printf ("please enter the id : ");
         scanf ("%d",&id);
         print_customer_data( head , id );
     break ;
     case 4 :
         id = 0 ;
         printf ("please enter the id : ");
         scanf ("%d",&id);
         delete_cutomer_data ( &head, head , id );

     break ;
     case 5 :
         cash_transfer (head);

     break ;
     case 6 :
         print_the_list( head );
     break ;
     default :
        printf ("wrong input please try again \n");

    }
   }


    return 0;
}





