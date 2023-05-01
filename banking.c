#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user {
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main()
{
    struct user usr,usr1;
    float pbalance;
    FILE *fp;
    char filename[50],phone[50],pword[50],pass[50];
    int opt,choice;
    char cont = 'y';
    float amount;
    first:
        printf("\nWhat do you want to do?");
        printf("\n\n 1. Register an account");
        printf("\n 2. Login to an account");

        printf("\n\nYour choice:\t");
        scanf("%d",&opt);

    if(opt == 1)
        {
             system("CLS");
            again1:
                {
            printf("Enter your account number:\t");
            scanf("%s",usr.ac);
            if(strlen(usr.ac)!=12)
            {
                system("CLS");
                printf("invalid account number!!!\n");
                goto again1;

            }
            else
            {
                again3:

                printf("Enter your phone number:\t");
                scanf("%s",usr.phone);
                if(strlen(usr.phone)!=10)
                {

                  printf("invalid phone number!!!\n");
                  goto again3;

                }

                else
                    {
                printf("Enter your new password:\t");
                scanf("%s",usr.password);
                usr.balance = 0;
                strcpy(filename,usr.phone);
                fp = fopen(strcat(filename,".dat"),"w");
                fwrite(&usr,sizeof(struct user),1,fp);
                if(fwrite != 0)
                {
                    printf("\n\nAccount succesfully registered\n");
                }
                else
                {
                    printf("\n\nSomething went wrong please try again\n\n\n");

                }
                    }
            }

        fclose(fp);
        }
        goto again2;
        }
    else if (opt == 2)
        {
             system("CLS");
            again2:
                {

        printf("You are in login page\n");
        printf("\nPhone number:\t");
        scanf("%s",phone);

        wrong2:
        printf("Password:\t");
        scanf("%s",pword);
        strcpy(filename,phone);
        fp = fopen(strcat(filename,".dat"),"r");
        if(fp == NULL)
        {
            printf("\nAccount number not registered\n\n");
            goto first;
        }
        else
        {
        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);
        if(!strcmp(pword,usr.password))
            {
            printf("\n\t\tWelcome %s",usr.phone);


            while(cont == 'y'){
                system("CLS");
                printf("\n\nPress 1 for balance inquiry");
                printf("\nPress 2 for depositing cash");
                printf("\nPress 3 for cash withdrawl");
                printf("\nPress 4 for online transfer");
                printf("\nPress 5 for password change");



                printf("\n\nYour choice:\t");
                scanf("%d",&choice);



                switch(choice)
                {
                    case 1:
                        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                        printf("|\t\t\t\t\t\t\t\t\t\n");
                        printf("| ABC bank\t\t\t\t\t\t\t\t\n");
                        printf("|\t\t\t BALANCE INQUERY \t\t\t\t\n");
                        printf("|\t\t\t\t\t\t\t\t\t\n");
                        printf("| A/C:%s\t\t\t\t\n",usr.ac);
                        printf("| Remaining balance:Rs.%.2f",usr.balance);
                        printf("|\t\t\t\t\t\t\t\t\t\n");
                        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

                        break;

                    case 2:
                        printf("\nEnter the amount:\t");
                        pbalance = usr.balance;
                        scanf("%f",&amount);
                        usr.balance += amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);

                        if(fwrite != NULL)
                            {
                            printf("\nSuccesfully deposited.\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("|\t\t\t\t\t\t\t\t\t\n");
                            printf("| ABC bank\t\t\t\t\t\t\t\t\n");
                            printf("|\t\t\t CASH DEPOSIT RECIPT \t\t\t\t\n");
                            printf("|\t\t\t\t\t\t\t\t\t\n");
                            printf("| A/C:%s\t\t\t\t\t\t\t\n",usr.ac);
                            printf("| Previous balance:Rs.%.2f\n",pbalance);
                            printf("| Deposit amount:Rs.%.2f\n",amount);
                            printf("| New balance:Rs.%.2f\n",usr.balance);
                            printf("|\t\t\t\t\t\t\t\t\t\n");
                            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

                        }
                        fclose(fp);
                        break;


                    case 3:
                        again4:
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                        pbalance = usr.balance;
                        if(amount>pbalance)
                        {
                           printf("\nInsufficient balance");
                           goto again4;
                        }
                        usr.balance -= amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL)
                        {
                            printf("\nYou have withdrawn Rs.%.2f\n",amount);
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("|\t\t\t\t\t\t\t\t\t\n");
                            printf("| ABC bank\t\t\t\t\t\t\t\t\n");
                            printf("|\t\t\t CASH WITHDRAW RECIPT \t\t\t\t\n");
                            printf("|\t\t\t\t\t\t\t\t\t\n");
                            printf("| A/C:%s\t\t\t\t\t\t\t\n",usr.ac);
                            printf("| Previous balance:Rs.%.2f\n",pbalance);
                            printf("| withdral amount:Rs.%.2f",amount);
                            printf("| New balance:Rs.%.2f",usr.balance);
                            printf("|\t\t\t\t\t\t\t\t\t\n");
                            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

                        }
                        fclose(fp);

                        break;

                    case 4:
                        printf("\nPlease enter the phone number to transfer the balance:\t");
                        scanf("%s",phone);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f",&amount);
                        strcpy(filename,phone);
                        fp = fopen(strcat(filename,".dat"),"r");
                        if(fp == NULL)
                            printf("\nAccount number not registered");
                        else
                            {
                            fread(&usr1,sizeof(struct user),1,fp);

                        fclose(fp);
                        if(amount > usr.balance)
                            printf("\nInsufficient balance");
                        else
                            {

                            fp = fopen(filename,"w");
                            usr1.balance += amount;
                            fwrite(&usr1,sizeof(struct user),1,fp);

                            fclose(fp);
                            if(fwrite != NULL)
                                {
                                printf("\nYou have succesfully transfered Rs.%.2f to %s\n",amount,phone);
                                strcpy(filename,usr.phone);
                                fp = fopen(strcat(filename,".dat"),"w");
                                usr.balance -= amount;
                                printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                                printf("|\t\t\t\t\t\t\t\t\t\n");
                                printf("| ABC bank\t\t\t\t\t\t\t\t\n");
                                printf("|\t\t\t MONEY TRANSFER \t\t\t\t\n");
                                printf("|\t\t\t\t\t\t\t\t\t\n");
                                printf("| A/C:\t\t\t\t\t\t\t\n");
                                printf("| From:%s\n",usr.phone);
                                printf("| To:%s\n",phone);
                                printf("| Total amount transfered:\n ",amount);
                                printf("| Previous balance:Rs.%.2f\n",pbalance);
                                printf("| New balance:Rs.%.2f\n",usr.balance);
                                printf("|\t\t\t\t\t\t\t\t\t\n");
                                printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");



                                fwrite(&usr,sizeof(struct user),1,fp);
                                fclose(fp);
                            }


                        }
                            }
                        break;

                 case 5:
                        wrong:
                            {
                        printf("Enter previous password:");
                        scanf("%s",&pass);
                        if(strcmp(pass,usr.password)==0)
                            goto new;
                         else
                         {

                             printf("Wrong password\n");
                             goto wrong;
                         }
                        new:
                        {


                        printf("\nPlease enter your new password:\t");
                        scanf("%s",pword);
                        fp = fopen(filename,"w");
                        strcpy(usr.password,pword);
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL)
                        printf("\nPassword succesfully changed");
                        }
                            }

                    break;


                default:
                    printf("\nInvalid option");

                }


                printf("\nDo you want to continue the transaction [y/n]\t");
                scanf("%s",&cont);

            }

        }
        else
        {
            printf("\nInvalid password");
            goto wrong2;
        }
        }
                }

    }
    else
    {
         printf("invalid option");
        goto first;
    }


    return 0;
}



