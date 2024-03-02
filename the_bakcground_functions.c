
#include "functions.h"



/*
this function a background function to be used in the create new customer function
takes the address of the main head and the address of the temporary structure that
have been made to make sure the data is right before adding to the linked list
*/
void take_cutomer_data ( customer *temp, customer *head )
{
        printf ("please enter the following data :\n");
        printf ("customer name :");
        fflush (stdin);
        gets(temp->name);
    right_id:
        printf ("customer id   :");
        scanf ("%d", &(temp->id));
        if (check_for_the_id ( head ,temp->id)==0)
        {
            printf ("you entered a wrong id please re enter the id \n");
            goto right_id ;

        }
    positive_cash:
        printf ("customer cash :");
        scanf ("%lf", &(temp->cash));
        if (temp->cash < 0)
        {
            printf ("you entered a negative number please reenter a positive number \n");
            goto positive_cash ;
        }
    right_input:
        printf ("the type of the account (debit or credit) : ");
        fflush(stdin);
        gets (temp->type);
         if (!(!(strcmp(temp->type,"debit"))||(!(strcmp(temp->type,"credit")))))
        {
            printf ("you enter a wrong input please try again \n");
            goto right_input ;
        }
        printf ("\n\n");
}



/*
this function is for making sure that the id is used only for one time
and this id is unique and did not used before
this function a background function to be used in the create new customer
to make sure that the id that the user entered was not used before
and also used in edit the user data to make sure that the user entered a
real id not any number
*/
char check_for_the_id (customer *head ,unsigned int id)
{
    if ( head == NULL)
    {
        return 1 ;
    }
    else
    {
        while (head != NULL)
        {
            if (id == head->id)
            {
                return 0;
            }
            head = head->next ;
        }
        return 1 ;
    }

}



