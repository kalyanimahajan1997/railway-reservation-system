#include <stdio.h>
#include <stdlib.h>
#include"rlyres.h"
#include"conio2.h"
int main()
{

    int choice,ticket_no,result;
    Passenger *ptr;
    add_trains();
    char* ptrain_no,train_num;
    int*pticket_no;
    char*pmob_no;
    while(1)
    {
      choice= enterchoice();
      if(choice==9)
       {
          exit(0);
       }
       switch(choice)
       {
         case 1:
             clrscr();
             view_trains();
             textcolor(WHITE);
             printf("\nPress any key to go back to the main screen");
             getch();
             clrscr();
             break;
         case 2:
             ptr=get_passenger_details();
             clrscr();
             if(ptr!=NULL)
             {
                 ticket_no=book_ticket(*ptr);
                 if(ticket_no==-1)
                 {
                     textcolor(LIGHTRED);
                     printf("Booking Failed!");
                 }
                 else
                    {
                        textcolor(LIGHTGREEN);
                        printf("Ticket sucessfully Booked!\n Your ticket no is %d",ticket_no);
                    }

                 textcolor(WHITE);
                 printf("\nPress any key to go back to the main screen");
                 _getch();
                 clrscr();
             }
                 break;
        case 3:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            view_ticket(ticket_no);
            textcolor(WHITE);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
        case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();
            break;
       case 5:
           clrscr();
           view_all_bookings();
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();

           break;
      case 6:
          clrscr();
           ptrain_no=accept_train_no();
           if(ptrain_no!=NULL)
           {
            view_booking(ptrain_no);
           }
             printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();

           break;
     case 7:
         clrscr();
         ticket_no=accept_ticket_no();
         if(ticket_no!=0)
         {
             result=cancel_ticket(ticket_no);
             if(result==0)
             {
                 textcolor(LIGHTRED);
                 printf("Sorry!No ticket book against ticket no %d",ticket_no);
             }
             else if(result==1)
             {
                textcolor(LIGHTGREEN);
                printf("Ticket no %d sucessfully cancelled!",ticket_no);
             }
             textcolor(WHITE);
             printf("\n\nPress any key to go back the main screen");
         }
         getch();
         clrscr();
         break;
     case 8:
        clrscr();
        train_num=accept_train_no();
        if(train_num!=NULL)
        {
            result=cancel_train(train_num);
            if(result==0)
            {
                textcolor(LIGHTRED);
                printf("Sorry! No train run against train no %s ",train_num);
            }
            else if(result==1)
            {
                textcolor(LIGHTGREEN);
                printf("Train no is sucessfully cancelled",train_num);
            }
        }
        /*cancel_ticket_with_train_no(train_num);*/
        getch();
        clrscr();
         break;
    default:
        textcolor(LIGHTRED);
        printf("Wrong choice!Try again\n");
        getch();
        clrscr();

     }
    }
    return 0;
}

