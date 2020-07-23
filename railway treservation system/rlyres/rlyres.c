#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#include"conio2.h"
#include"rlyres.h"
int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(25,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=69;i++)
        printf("-");
          printf("\nSelect an option\n1- view Train\n2- Book Ticket\n3- View Ticket\n4- Search Ticket no\n5- View All Bookings\n6- View Train Bookings\n");
          printf("7- Cancel Ticket\n8- Cancel Train\n9- Quit\n");
          printf("\nEnter choice:");
          scanf("%d",&choice);
          return choice;
}
void add_trains()
{
    FILE *fp=fopen("D:\\Myproject\\alltrains.dat","rb");
    if(fp==NULL)
    {
       Train alltrains[4]={
       {"123","BPL","GWA",2100,1500},
       {"546","BPL","DEL",3500,2240},
       {"345","HBJ","AGR",1560,1135},
       {"896","HBJ","MUM",4500,3360}
       };
       fp=fopen("D:\\myproject\\alltrains.dat","wb");
       fwrite(alltrains,4*sizeof(Train),1,fp);
       fclose(fp);
    }
    else
    {
        fclose(fp);

    }
}
void view_trains()
{
    int i;
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FAIR\tSECOND AC FAIR\n");
    for(i=0;i<=68;i++)
        printf("-");
     FILE*fp=fopen("D:\\Myproject\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
        printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
        printf("\n\n\n\n");
        fclose(fp);
}
int check_train_no(char *trainno)
{
    FILE *fp;
    fp=fopen("D:\\Myproject\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
Passenger*get_passenger_details()
{
    clrscr();
    gotoxy(55,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(LIGHTCYAN);
    printf("Enter Passenger Name:");
    static Passenger psn;
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled!");
        _getch();
        textcolor(LIGHTRED);
        return NULL;
    }
    int valid;
    printf("Enter Gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled!");
            _getch();
            textcolor(LIGHTCYAN);
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            valid=0;
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Gender should be M or F(in uppercase)");
            _getch();
            gotoxy(19,2);
            printf(" \b");
            textcolor(LIGHTCYAN);
        }}while(valid==0);
        printf("Enter Train Number:");
        do
        {
            fflush(stdin);
            scanf("%s",psn.train_no);
            if(strcmp(psn.train_no,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                _getch();
                textcolor(LIGHTCYAN);
                return NULL;
            }
            valid=check_train_no(psn.train_no);
            if(valid==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,20);
                printf("Error! Invalid Train No");
                _getch();
                gotoxy(20,3);
                printf("\t\t\t\t\t\t");
                gotoxy(20,3);
                textcolor(LIGHTCYAN);
            }
            }while(valid==0);
            printf("Enter travelling class(First AC-F,Sexcond AC-S):");
            do
            {
                valid=1;
                fflush(stdin);
                scanf("%c",&psn.p_class);
                if(psn.p_class=='0')
                {
                    textcolor(LIGHTRED);
                    gotoxy(1,25);
                    printf("\t\t\t\t\t\t\t");
                    gotoxy(1,25);
                    printf("Reservation Cancelled!");
                    getch();
                    textcolor(LIGHTCYAN);
                    return NULL;
                }
                if(psn.p_class!='F'&&psn.p_class!='S')
                {
                    textcolor(LIGHTRED);
                    gotoxy(1,25);
                    printf("Error! Reservation class should be F and S(in uppercase)");
                    valid=0;
                    _getch();
                    gotoxy(48,4);
                    printf("\b");
                    textcolor(LIGHTCYAN);
                }}while(valid==0);
                printf("Enter Address:");
                fflush(stdin);
                fgets(psn.address,30,stdin);
                pos=strchr(psn.address,'\n');
                *pos='\0';
                if(strcmp(psn.address,"0")==0)
                {
                    textcolor(LIGHTRED);
                    gotoxy(1,25);
                    printf("\t\t\t\t\t\t\t");
                    gotoxy(1,25);
                    printf("Reservation Cancelled!");
                    _getch();
                    textcolor(LIGHTCYAN);
                    return NULL;
                }
                printf("Enter Age:");
                do
                {
                    valid=1;
                    fflush(stdin);
                    scanf("%d",&psn.age);
                    if(psn.age==0)
                    {
                        gotoxy(1,20);
                        textcolor(LIGHTRED);
                        printf("Reservation Cancelled!");
                        _getch();
                        textcolor(LIGHTCYAN);
                        return NULL;
                    }
                    if(psn.age<=0)
                    {
                        valid=0;
                        gotoxy(1,20);
                        textcolor(LIGHTRED);
                        printf("Error! Age should be positive");
                        _getch();
                        gotoxy(11,6);
                        printf("\t\t\t\t\t\t\t");
                        gotoxy(11,6);
                        textcolor(LIGHTCYAN);
                    }}while(valid==0);
                    printf("Enter Mobile No:");
                    do
                    {
                        fflush(stdin);
                        fgets(psn.mob_no,12,stdin);
                        pos=strchr(psn.mob_no,'\n');
                        if(pos!=NULL)
                         *pos='\0';
                        if(strcmp(psn.mob_no,"0")==0)
                        {
                            gotoxy(1,25);
                            printf("\t\t\t\t\t\t\t");
                            textcolor(LIGHTRED);
                            gotoxy(1,25);
                            printf("Reservation Cancelled!");
                            _getch();
                            textcolor(LIGHTCYAN);
                            return NULL;
                        }

                    valid=check_mob_no(psn.mob_no);
                    if(valid==0)
                           {
                               gotoxy(1,20);
                               textcolor(LIGHTRED);
                               printf("Error! Invalid mobile no");
                               _getch();
                               gotoxy(17,7);
                               printf("\t\t\t\t\t\t\t");
                               gotoxy(17,7);
                               textcolor(LIGHTCYAN);
                           }


                    }while(valid==0);
                    return &psn;
}
int check_mob_no(char *p_mob)
{
   if(strlen(p_mob)!=10)
        return 0;
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
            p_mob++;
    }
    return 1;
}
int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp;
    Passenger pr;
    int count=0;
    fp=fopen("D:\\Myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
        {
            ++count;
        }
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    FILE*fp;
    Passenger pr;
    fp=fopen("D:\\Myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticket_no;
}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==5)
    {
        textcolor(LIGHTRED);
        printf("All seats full in train no:%s in class:%c!\n",p.train_no,p.p_class);
        return -1;

    }
        int ticket_no=last_ticket_no()+1;
        p.ticket_no=ticket_no;
    FILE *fp;
    fp=fopen("D:\\Myproject\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! File cannot be opened");
        return -1;
    }
        fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}


int accept_ticket_no()
{
    printf("Enter ticket number");
    int valid;
    int ticket_no;
    do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,20);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,20);
            printf("Cancelling Input....!");
        }
        if(ticket_no<0)
        {

            textcolor(LIGHTRED);
            gotoxy(1,20);
            printf("Error!Ticket number should be positive");
            valid=0;
            getch();
            gotoxy(11,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(11,1);
            textcolor(YELLOW);
        }
        }while(valid==0);
        return ticket_no;
}
void view_ticket(int ticket_no)
{
    FILE *fp=fopen("D:\\Myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNO booking done yet");
        return;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticket_no==ticket_no)
        {
            textcolor(LIGHTCYAN);
            printf("\nNAME:%s\nGENDER:%c\nTRAIN NO:%s\nCLASS:%c\nADDRRESS:%s\nAGE:%d\nMOBILE NO:%s\nTICKET NO:%d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticket_no);
            printf("\n\n");
            fclose(fp);
            return;
        }
    }
    textcolor(LIGHTRED);
    printf("\nNO details of ticket no%d found",ticket_no);
    fclose(fp);
}
int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("D:\\Myproject\\allbookings.dat","rb+");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNO booking done yet");
        return -1;
    }
    FILE *fp2=fopen("D:\\Myproject\\temp.dat","wb+");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticket_no!=ticket_no)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
     fclose(fp1);
     fclose(fp2);
     if(found==0)
     {
        remove("%D:\\Myproject\\temp.dat");
     }
     else
      {
         remove("D:\\Myproject\\allbookings.dat");
         rename("D:\\Myproject\\temp.dat","F:\\myproject\\allbookings.dat");
      }
       return found;
}
char*accept_mob_no()
{
    static char mob_no[11];
    int valid;
    char *pos;
    printf("Enter mobile number:");
    do
    {
        fflush(stdin);
        fgets(mob_no,11,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling input...!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!invalid Mobile no");
            getch();
            gotoxy(21,1);
            textcolor(YELLOW);
        }
       }while(valid==0);
     clrscr();
     return mob_no;
}
int*get_ticket_no(char*p_mob_no)
{
    int count=0;
    FILE *fp=fopen("D:\\Myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        ++count;
    }
        if(count==0)
        {
            fclose(fp);
            return NULL;
        }
        rewind (fp);
        int *p=(int*)malloc((count+1)*sizeof(int));
        int i=0;
        while(fread(&pr,sizeof(pr),1,fp)==1)
        {
            if(strcmp(pr.mob_no,p_mob_no)==0)
            {
                *(p+i)=pr.ticket_no;
                i++;
            }
        }
        *(p+i)=-1;
        fclose(fp);
        return p;

}
void view_all_tickets(char*pmob_no,int*pticket_no)
    {
       if(pticket_no==NULL)
       {
           textcolor(LIGHTRED);
           printf("Sorry!No tickets booked against mobile no %s",pmob_no);
           textcolor(WHITE);
           printf("\n\nPress any key to go back to the main screen");
           textcolor(YELLOW);
           getch();
           return;
       }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTicket No\n");
    printf("--------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the the main screen");
        textcolor(YELLOW);
        free(pticket_no);
        getch();

}

char*accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(55,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
      textcolor(LIGHTCYAN);
      printf("Enter Train Number:");
        do
        {
            fflush(stdin);
            scanf("%s",train_no);
            if(strcmp(train_no,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                _getch();
                textcolor(LIGHTCYAN);
                return NULL;
            }

      valid=check_train_no(train_no);
            if(valid==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,20);
                printf("Error! Invalid Train No");
                _getch();
                gotoxy(20,3);
                printf("\t\t\t\t\t\t");
                gotoxy(20,3);
                textcolor(LIGHTCYAN);
            }
            }while(valid==0);
    clrscr();
    return train_no;
}

void view_booking(char*train_no)
{

    int found=0,i;
    FILE *fp=fopen("D:\\Myproject\\allbookings.dat","rb");
    Passenger pr;
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(i=1;i<=69;i++)
        printf("-");
    int row=3;
    gotoxy(1,3);
    while(fread(&pr,sizeof(pr),1,fp)==1)
          {
              if(strcmp(pr.train_no,train_no)==0)
            {
                printf("%d\t\t%c\t%s",pr.ticket_no,pr.p_class,pr.p_name);
                gotoxy(41,row++);
                printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
                found=1;
            }
          }
          if(!found)
          {
              clrscr();
              textcolor(LIGHTRED);
              printf("\n No details of given train no %s found!",train_no);
          }
          textcolor(WHITE);
          printf("\n\nPress any key to go back to the main screen");
          textcolor(YELLOW);
          getch();
          fclose(fp);
}
void view_all_bookings()
{
    int i;
    FILE *fp=fopen("D:\\Myproject\\allbookings.dat","rb");
    clrscr();
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("NO bookings done yet!");
        return;
    }
    Passenger pr;
    textcolor(WHITE);
    printf("TRAIN NO\tTICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(i=0;i<=90;i++)
    {
        printf("-");
    }
    textcolor(LIGHTCYAN);
    int row=3;
    gotoxy(1,3);
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        printf("%s\t\t%d\t\t%c\t%s\n",pr.train_no,pr.ticket_no,pr.p_class,pr.p_name);
        gotoxy(57,row++);;
        printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
    }
}
int cancel_train(char*train_no)
{
    FILE *fp=fopen("D:\\Myproject\\allbookings.dat","rb+");
    int res;
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0){
            res=cancel_ticket(pr.ticket_no);
            printf("%d",res);
        }
    }
    getch();
}
