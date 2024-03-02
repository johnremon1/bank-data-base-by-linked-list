
#ifndef FUNCTIONS.H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    unsigned char name[20];
    unsigned int id ;
    double cash ;
    unsigned char type[7];
    struct node *next;

} customer ;

void take_cutomer_data (customer *temp ,customer *head);
void creat_a_new_customer(customer **head_ptr , customer *head);
void print_the_list(customer *head);//this function print all the bank customers
void edit_customer_data(customer *head );// this function is for editing the customer id
void print_customer_data (customer * head,unsigned int id ) ;// this function is for printing the customer all data
void delete_cutomer_data (customer **head_ptr,customer *head , unsigned int id);//this function is for deleting any customer data by only knowing the id of the customer
void cash_transfer (customer *head);//this function is for cash transfer




char check_for_the_id (customer *head ,unsigned int id);
/*
this function is for making sure that the id is used only for one time
and this id is unique and did not used before
*/




#endif // FUNCTION
