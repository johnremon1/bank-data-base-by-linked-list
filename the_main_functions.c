

#include "functions.h"





void print_the_list(customer *head )
{
    unsigned char counter = 0 ;
  if ( head == NULL )
  {
      printf ("the linked list is empty \n");
  }
  else
  {
      while ( head != NULL )
      {
           counter++;
           printf("******************************\n");
           printf ("customer %i \n",counter);
           printf("name : %s \n", head->name);
           printf("id   : %d \n", head->id);
           printf("cash : %0.2f \n", head->cash);
           printf("type : %s \n", head->type);
           printf("******************************\n");
           head = head->next;
      }
  }
}




void creat_a_new_customer(customer **head_ptr , customer *head)
{
    customer *temp ;
    temp =  (customer*) malloc (sizeof(customer));
    if ( temp != NULL)
    {
      take_cutomer_data(temp , head);
      if ( head == NULL )// this condition is only for making the first and only the first customer as it will be the only condition that head will have null in it
      {
        *head_ptr = temp;
        temp->next = NULL ;
      }
      else
      {
            while ( (head->next) != NULL)
            {
                 head = head->next ;
            }
            head->next = temp ;
            head->next->next = NULL ;
      }

    }
    else
    {
        printf ("there is no space for a new customer \n");
    }

}



void edit_customer_data(customer *head )
{
    unsigned int id = 0;
    if ( head == NULL)
    {
        printf ("the linked list is empty \n");
    }
    else
    {
      unsigned char flag = 0 ; //this flag for knowing that we found id or the while loop just ended (the while loop ended or the break happened )
      printf ("customer id :");
      scanf ("%d",&id);
      while ( head != NULL)
      {
         if ( id == (head->id))
         {
             flag = 1 ;
             break;
         }
         else
         {
             head = head->next ;
         }
      }
      if (flag == 1)
      {
          printf ("please enter the following data :\n");
          printf ("customer name :");
          fflush (stdin);
          gets(head->name);
    positive_cash1:
          printf ("customer cash :");
          scanf ("%lf", &(head->cash));
          if (head->cash < 0)
          {
              printf ("you entered a negative number please reenter a positive number \n");
              goto positive_cash1 ;
          }
    right_input1:
          printf ("the type of the account (debit or credit) : ");
          fflush(stdin);
          gets (head->type);
           if (!(!(strcmp(head->type,"debit"))||(!(strcmp(head->type,"credit")))))
          {
              printf ("you enter a wrong input please try again \n");
              goto right_input1 ;
          }
          printf ("\n\n\n\n");

         printf ("the customer new data \n");
         print_customer_data( head , head->id);
      }



    }
}


void print_customer_data (customer * head,unsigned int id )
{
    unsigned char flag = 0 ;//this flag for knowing that we found id or the while loop just ended (the while loop ended or the break happened )
    if ( head == NULL)
    {
       printf("the linked list is empty \n");
    }
    while ( head != NULL)
    {
        if ( id == head->id)
        {
            flag = 1 ;
            break ;
        }
        else
        {
            head = head->next;
        }
    }
    if (flag == 1 )
    {
           printf("******************************\n");
           printf("name : %s \n", head->name);
           printf("id   : %d \n", head->id);
           printf("cash : %0.2f \n", head->cash);
           printf("type : %s \n", head->type);
           printf("******************************\n");
    }
    else
    {
        printf ("you entered a wrong input /n");
    }
}



void delete_cutomer_data (customer **head_ptr,customer *head , unsigned int id)
{
    unsigned char flag = 0 ;//this flag for knowing that we found id or the while loop just ended (the while loop ended or the break happened )
    if (head == NULL)
    {
        printf ("the linked list is empty \n");
    }
    else if ( head->next == NULL)
    {
        printf("*** i entered here \n") ;
        free(head);
        *head_ptr= NULL ;
    }
    else if (id == head->id )//this condition only to let us can delete the first element without it the first element will not be deleted
    {
        *head_ptr = head->next;
        free (head);

    }
    else
    {
        while (  head != NULL)
        {
            if ( id == head->next->id)
            {
                flag = 1 ;
                break ;
            }
            else
            {
                head = head->next;
            }
        }
        if (flag == 1)
        {
            customer *temp ;
            temp = head->next;
            head->next=head->next->next;
            free(temp);
        }

    }

}




void cash_transfer (customer *head)
{
    double sender_cash = 0 ;
    double receiver_cash = 0 ;
    customer *sender_address;
    customer *receiver_address;
    customer *head_temp = head ;
    customer *head_temp1 = head ;
    unsigned int sender_id = 0;
    unsigned int receiver_id = 0;
    double cash = 0 ;
    unsigned char flag = 0;

  right_id1:
    printf ("the sender id : ");
    scanf ("%d",&sender_id);
    if (sender_id == 0)
    {
        return 0 ;
    }
    if (check_for_the_id(head,sender_id) == 1 )
    {
        printf ("the id was not found try again \n");
        printf ("if you want to go to the main menu enter the id = 0 \n\n");
        goto right_id1 ;
    }
  right_id2:
    printf ("the receiver id : ");
    scanf ("%d",&receiver_id);
    if (check_for_the_id(head,receiver_id) == 1 )
    {
        printf ("the id was not found try again \n");
        goto right_id2 ;
    }

    while ( head != NULL )
    {
      if (sender_id == head->id)
      {
          flag = 1 ;
          break ;
      }
      else
      {
          head=head->next;
      }
    }
    if (flag == 1 )
    {
        flag = 0 ;
        sender_address = head ;
        sender_cash = head->cash ;
    }
    else
    {
        printf ("error happened no cash transfered in the sender id \n");
        return 0;
    }
    while ( head_temp != NULL )
    {
      if (receiver_id == head_temp->id)
      {
          flag = 1 ;
          break ;
      }
      else
      {
          head_temp=head_temp->next;
      }
    }
    if (flag == 1 )
    {
        flag = 0 ;
         receiver_address = head_temp ;
         receiver_cash = head_temp->cash ;
    }
    else
    {
        printf ("error happed no cash transfered in receiving the receiver id \n");
        return 0;
    }

    printf("the cash to be transfered : ");
    scanf ("%lf",&cash);

    if (cash < 0 )
    {
       printf("you can write a negative number \n");
       return 0 ;
    }
    if ( cash > (sender_cash))
    {
        printf("there is not enough in the sender account \n");
        return 0 ;
    }
    sender_address->cash = sender_cash - cash ;
    receiver_address->cash = receiver_cash + cash ;
    printf ("operation done successfully \n\n");
    printf ("the accounts after modification  \n\n");
    print_customer_data( head_temp1 ,sender_id);
    print_customer_data( head_temp1 ,receiver_id);

}
