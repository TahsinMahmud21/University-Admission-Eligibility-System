#include <bits/stdc++.h>
using namespace std;

int n, i;
FILE *nfile;
struct varsityInfo
{
    char name[80];
    float gpa[3];
    int fee;
    int seat;
};
struct User
{
    char name[40];
    float gpa[3];
};



int VarsityCount(int x)
{

    if (x == 1)
    {
        nfile = fopen("Database1.txt", "r");
    }
    else if (x == 2)
    {
        nfile = fopen("Database2.txt", "r");
    }

    char ch;
    int count = 0;
    while (!feof(nfile))
    {
        ch = fgetc(nfile);
        if (ch == '\n')
        {
            count++;
        }
    }
    fclose(nfile);

    n = (count + 1) / 4;
    return n;
}



void EligibilityCheck(varsityInfo varsity[], User user)
{
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        if (strcasecmp(user.name, varsity[i].name) == 0)
        {
            if ((user.gpa[0] >= varsity[i].gpa[0]) && (user.gpa[1] >= varsity[i].gpa[1]) && (user.gpa[2] >= varsity[i].gpa[2]))
            {
                printf("\n\t\t\t\t\t\t\t\t\t<<<<<<<< You are Eligible >>>>>>>>\n\n");
            }

            else
            {
                printf("\n\t\t\t\t\t\t\t\t\t<<<<<<<< You are Not Eligible >>>>>>>>\n\n");
            }
            printf("Varsity Name: %-95s\t ", varsity[i].name);
            printf("SSC(min): %.2f;\t HSC(min): %.2f;\t Minimum Total GPA: %.2f\n", varsity[i].gpa[0], varsity[i].gpa[1], varsity[i].gpa[2]);

            flag = 1;
        }
        if (flag == 1)
            break;
    }

    if (flag == 0)
        printf("This Varsity is not in Database\n");
}



void eligibleList(varsityInfo varsity[], User user)
{
    int flag = 0;
    printf("\n\t\t\t\t\t\t\t\tList of Eligible Varsity\n\n");
    for (i = 0; i < n; i++)
    {
        if ((user.gpa[0] >= varsity[i].gpa[0]) && (user.gpa[1] >= varsity[i].gpa[1]) && (user.gpa[2] >= varsity[i].gpa[2]))
        {
            printf("Varsity Name: %-80s\t ", varsity[i].name);
            printf("SSC(min): %.2f;\t HSC(min): %.2f;\t Minimum Total GPA: %.2f\n", varsity[i].gpa[0], varsity[i].gpa[1], varsity[i].gpa[2]);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("\nSorry! You are not Eligible\n");
}



void gpaRequirement(varsityInfo varsity[])
{
    int k;
    varsityInfo temp;
    printf("\t\t\t\t\t\tMinimum Total GPA Requirement\n\n");
    for (i = 1; i < n; i++)
    {
        temp = varsity[i];
        k = i - 1;
        while (k >= 0 && varsity[k].gpa[2] > temp.gpa[2])
        {
            varsity[k + 1] = varsity[k];
            k = k - 1;
        }
        varsity[k + 1] = temp;
    }

    for (i = 0; i < n; i++)
    {
        printf("%02d. Varsity Name: %-80s    ", i + 1, varsity[i].name);
        printf("Minimum Total GPA: %0.2f\n", varsity[i].gpa[2]);
    }
}



void admissionFee(varsityInfo varsity[])
{
    int k;
    varsityInfo temp;
    printf("\t\t\t\t\t\tList of Varsity Admission Form Fee\n\n");
    for (i = 1; i < n; i++)
    {
        temp = varsity[i];
        k = i - 1;
        while (k >= 0 && varsity[k].fee > temp.fee)
        {
            varsity[k + 1] = varsity[k];
            k = k - 1;
        }
        varsity[k + 1] = temp;
    }

    for (i = 0; i < n; i++)
    {
        printf("%02d. Varsity Name: %-80s    ", i + 1, varsity[i].name);
        printf("Admission Form Fee: %d\n", varsity[i].fee);
    }
}



void seat(varsityInfo varsity[])
{
    int k;
    varsityInfo temp;
    printf("\t\t\t\t\t\tNumber of Seats of All Varsities\n\n");
    for (i = 1; i < n; i++)
    {
        temp = varsity[i];
        k = i - 1;
        while (k >= 0 && varsity[k].seat > temp.seat)
        {
            varsity[k + 1] = varsity[k];
            k = k - 1;
        }
        varsity[k + 1] = temp;
    }

    for (i = 0; i < n; i++)
    {
        printf("%02d. Varsity Name: %-80s    ", i + 1, varsity[i].name);
        printf("Total Seats: %d\n", varsity[i].seat);
    }
}



void display()
{
    varsityInfo varsity;
    int t = 1;
    printf("\t\t\t\t\t\t\t\t\t<<<<<<<< Science Group >>>>>>>>\n\n");
    nfile = fopen("Database1.txt", "r");
    while (!feof(nfile))
    {
        fscanf(nfile, " %[^\n]%f%f%f%d%d", &varsity.name, &varsity.gpa[0], &varsity.gpa[1], &varsity.gpa[2], &varsity.fee, &varsity.seat);
        printf("%02d. Varsity Name: %-75s\t SSC(min): %.2f\t HSC(min): %.2f\t ", t++, varsity.name, varsity.gpa[0], varsity.gpa[1]);
        printf("Total Min GPA: %.2f\t Form Fee: %d\t Total Seats: %d\n", varsity.gpa[2], varsity.fee, varsity.seat);
    }
    fclose(nfile);
    t = 1;
    printf("\n\n\t\t\t\t\t\t\t\t\t<<<<<<< Commerce Group >>>>>>>\n\n");
    nfile = fopen("Database2.txt", "r");
    while (!feof(nfile))
    {
        fscanf(nfile, " %[^\n]%f%f%f%d%d", &varsity.name, &varsity.gpa[0], &varsity.gpa[1], &varsity.gpa[2], &varsity.fee, &varsity.seat);
        printf("%02d. Varsity Name: %-75s\t SSC(min): %.2f\t HSC(min): %.2f\t ", t++, varsity.name, varsity.gpa[0], varsity.gpa[1]);
        printf("Total Min GPA: %.2f\t Form Fee: %d\t Total Seats: %d\n", varsity.gpa[2], varsity.fee, varsity.seat);
    }
    fclose(nfile);
}



void admin()
{
    int num, pass, j = 1, x;
    varsityInfo temp;
    while (j != 0)
    {

        printf("\nInput the password[4 Digits]: ");
        scanf("%d", &pass);
        if (pass == 0000)
        {
            printf("Correct password");
            j = 0;
        }
        else
        {
            printf("Wrong password, try another");
        }
        printf("\n\n\n");
    }

    printf("Choose The Group:\n");
    printf("\t\t     Press 1 for Science\n");
    printf("\t\t     Press 2 for Business Studies\n");
    printf("Enter your choice:");
    scanf("%d", &x);

    n = VarsityCount(x);

    printf("Enter How Many Varsities You Want to Add[%d]: ", n);
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("Enter Varsity Name: ");
        scanf(" %[^\n]s", temp.name);
        printf("SSC(min) GPA: ");
        scanf("%f", &temp.gpa[0]);
        printf("HSC(min) GPA: ");
        scanf("%f", &temp.gpa[1]);
        printf("Total Minimum GPA: ");
        scanf("%f", &temp.gpa[2]);
        printf("Admission Form Fee: ");
        scanf("%d", &temp.fee);
        printf("Number of Seats: ");
        scanf("%d", &temp.seat);

        if (x == 1)
        {
            nfile = fopen("Database1.txt", "a");
        }
        else if (x == 2)
        {
            nfile = fopen("Database2.txt", "a");
        }
        fprintf(nfile, "\n%s\n%.2f %.2f %.2f\n%d\n%d", temp.name, temp.gpa[0], temp.gpa[1], temp.gpa[2], temp.fee, temp.seat);
        printf("\n");
        n++;
    }
    fclose(nfile);
    printf("Current Varsities in the Database: %d\n", n);
}




int main()
{
    int x, option;

    while (x != 1 && x != 2)
    {
        printf("\n\t\t\t\t\t\t\t Enter 0 to Go to the Admin Panel\n\n");
        printf("Choose Your Group:\n");
        printf("\t\t     Press 1 for Science\n");
        printf("\t\t     Press 2 for Business Studies\n");
        printf("Enter your choice:");
        scanf("%d", &x);
        if (x == 0)
        {
            admin();
            continue;
        }
        if (x != 1 && x != 2)
            printf("\nWrong Entry!! Please re-enter correct option\n\n");
    }

    n = VarsityCount(x);

    varsityInfo varsity[n];
    User user;

    if (x == 1)
    {
        nfile = fopen("Database1.txt", "r");
    }
    else if (x == 2)
    {
        nfile = fopen("Database2.txt", "r");
    }
    for (i = 0; i < n; i++)
    {
        fscanf(nfile, " %[^\n]%f%f%f%d%d", &varsity[i].name, &varsity[i].gpa[0], &varsity[i].gpa[1], &varsity[i].gpa[2], &varsity[i].fee, &varsity[i].seat);
    }
    fclose(nfile);

    printf("\nEnter Your GPA of SSC: ");
    scanf("%f", &user.gpa[0]);
    printf("Enter Your GPA of HSC: ");
    scanf("%f", &user.gpa[1]);
    user.gpa[2] = user.gpa[0] + user.gpa[1];

    while (1)
    {
        printf("\n\n\n");
        printf("\t\t\t\t<<<<<<<<<-  MENU  ->>>>>>>>>>\n\n");
        printf("\t\tEnter 1 to Check Specific Varsity Eligibility\n");
        printf("\t\tEnter 2 to Find All Eligible Varsity List\n");
        printf("\t\tEnter 3 to See the List of Total GPA Requirement\n");
        printf("\t\tEnter 4 to See the List of Admission Form Fee\n");
        printf("\t\tEnter 5 to See the Number of Seats of the Varsities\n");
        printf("\t\tEnter 6 to Display the List of All Varsities [Science & Business Studies]\n");
        printf("\t\tEnter 7 to Exit the menu\n");
        printf("\t\tEnter 0 to Exit Program\n");
        printf("\n\t\tEnter your choice:");
        scanf("%d", &option);

        switch (option)
        {

        case 1:
        {
            printf("\nEnter A Varsity Name: ");
            scanf(" %[^\n]s", user.name);
            EligibilityCheck(varsity, user);
            break;
        }
        case 2:
            eligibleList(varsity, user);
            break;

        case 3:
            gpaRequirement(varsity);
            break;

        case 4:
            admissionFee(varsity);
            break;

        case 5:
            seat(varsity);
            break;

        case 6:
            display();
            break;

        case 7:
            return main();
            break;

        case 0:
            return 0;
            break;

        default:
            printf("\aWrong Entry!!Please re-entered correct option\n\n");
        }
    }
}
