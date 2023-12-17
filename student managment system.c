#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>

#define MAX_SGPA 8
#define MAX_NAME 100
#define MAX_DEPT 50
#define DB_FILE "db.txt"
#define PASSWORD_FILE "Password.txt"

#define Student struct Stud

void add(FILE *fp);
void modify(FILE *fp);
void display(FILE *fp);
void individual(FILE *fp);
void password();
FILE *del(FILE *fp);
void printChar(char ch, int n);
void title();
void gotoxy(int x, int y);

struct pass
{
    char pass[25];
} pa;

struct Stud
{
    char name[MAX_NAME];
    char dept[MAX_DEPT];
    int roll;
    float sgpa[MAX_SGPA];
    float cgpa;
};

int main()
{
    int option;
    char pas[50];

    SetConsoleTitle("Student Management System | DIU");

    FILE *fp;
    Student s;

    int k = 0, i;

    if ((fp = fopen(DB_FILE, "rb+")) == NULL)
    {
        if ((fp = fopen(DB_FILE, "wb+")) == NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }

    system("color 1E");

    gotoxy(42, 8);
    printf("\t\t *LOGIN*\n\t\t\t\t\t  (If it's the first login,press ENTER)");
    gotoxy(42, 10);
    printf("____________________________________");
    gotoxy(42, 11);
    printf("|\tEnter password :             |");
    gotoxy(42, 12);
    printf("|__________________________________|");
    gotoxy(65, 11);

    while (k < 10)
    {
        pas[k] = getch();
        char s = pas[k];
        if (s == 13)
            break;
        else
            printf("*");
        k++;
    }
    pas[k] = '\0';

    FILE *tp;
    tp = fopen(PASSWORD_FILE, "r+");
    fgets(pa.pass, 25, tp);

    if (strcmp(pas, pa.pass) == 0)
    {system("cls");
		gotoxy(10,3);
		for(i=0; i<3; i++)
        {
            printf(" \t(*_*)");
            Sleep(500);
        }

		printf("\t<<<< Loading Please Wait >>>>");
		for(i=0; i<3; i++)
        {
            printf("\t(*_*)");
            Sleep(500);
        }
        printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *       Welcome      *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
		getch();

    title();
    printf("\n\n\t\t\t  1ST SEMESTER C LANGUAGE PROJECT");
    printf("\n\n\t\t\t\t       B9 Team");
    printf("\n\n\t\t\t      KLE INSITUTE OF TECHNOLOGY \n\t\t\t");
    printChar('=',38);
    printf("\n\n\n\t\t\t       press any key to Enter");
    getch();

    while(1)
    {
        title();
        printf("\n\t");
        printChar('*',64);

        printf("\n\n\t\t\t\t1. Add Student");
        printf("\n\n\t\t\t\t2. Modify Student");
        printf("\n\n\t\t\t\t3. Show All Student");
        printf("\n\n\t\t\t\t4. Individual View");
        printf("\n\n\t\t\t\t5. Remove Student");
        printf("\n\n\t\t\t\t6. Change Password");
        printf("\n\n\t\t\t\t7. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                add(fp);
                break;
            case 2:
                modify(fp);
                break;
            case 3:
                display(fp);
                break;
            case 4:
                Individual(fp);
                break;
            case 5:
                fp=del(fp);
                break;
            case 6:
                    system("cls");
				    system("color 1F");
			        password();
                break;
            case 7:
                return 1;
                break;
            default:
                printf("\n\t\tNo Action Detected");
                printf("\n\t\tPress Any Key\n\n\n");
                getch();
                system("pause");
        }
    }
     }
    else
    {
        printf("\t\tWrong Password. Get Out");
        getch();
    }

    return 1;
}
void gotoxy(int x, int y)
{
    COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void password()
{
    char c;
    FILE *tp;

    printf("\n\nEnter new password: ");
    fflush(stdin);
    gets(pa.pass);

    printf("\nSave password (y/n): ");
    fflush(stdin);
    scanf("%c", &c);

    if (c == 'y' || c == 'Y')
    {
        tp = fopen(PASSWORD_FILE, "w+");
        if (tp == NULL)
        {
            printf("Error opening password file.\n");
            return;
        }

        fwrite(&pa, sizeof(pa), 1, tp);
        fclose(tp);

        printf("\nPassword Saved\n");
    }
    else
    {
        printf("Password not saved.\n");
        printf("Press any key to continue >>>");
        getch();
    }
}

void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}
void title()
{
    system("cls");
    system("COLOR 03");
    printf("\n\n\t");
    printChar('=',19);
    printf(" Student Management System ");
    printChar('=',19);
    printf("\n");
}
void add(FILE * fp)
{
    title();

    char another='y';
    Student s;
    int i;
    float cgpa;

    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {

        printf("\n\n\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\tEnter Department Name: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\tEnter the Roll number: ");
        scanf("%d",&s.roll);

        printf("\n\n\tEnter SGPA for 8 semesters\n");
        for(i=0,cgpa=0; i<8; i++)
        {
            scanf("%f",&s.sgpa[i]);
            cgpa+=s.sgpa[i];

        }

        cgpa/=8.0;
        s.cgpa=cgpa;

        fwrite(&s,sizeof(s),1,fp);

        printf("\n\n\t\tAdd another student?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}
FILE * del(FILE * fp)
{
    title();

    Student s;
    int flag=0,tempRoll,siz=sizeof(s);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter the Roll number of Student to Delete the Record");
    printf("\n\n\t\t\tRoll No. : ");
    scanf("%d",&tempRoll);

    rewind(fp);


    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.dept,s.roll);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }
    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt","db.txt");

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        printf("ERROR");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\tNO STUDENT FOUND WITH THE INFORMATION\n\t");

    printChar('-',65);
    printf("\n\t");
    system("pause");
    return fp;
}


void modify(FILE * fp)
{
    title();

    Student s;
    int i,flag=0,tempRoll,siz=sizeof(s);
    float cgpa;

    printf("\n\n\tEnter the Roll Number of Student to MODIFY the Record : ");
    scanf("%d",&tempRoll);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\t\t\tRecord Found\n\t\t\t");
        printChar('=',38);
        printf("\n\n\t\t\tStudent Name: %s",s.name);
        printf("\n\n\t\t\tStudent Roll: %d\n\t\t\t",s.roll);
        printChar('=',38);
        printf("\n\n\t\t\tEnter New Data for the student");

        printf("\n\n\t\t\tEnter the Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\t\tEnter Department: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\t\tEnter the Roll number: ");
        scanf("%d",&s.roll);


        printf("\n\n\t\tEnter the SGPA for 8 semesters\n");
        for(i=0,cgpa=0; i<8; i++)
        {
            scanf("%f",&s.sgpa[i]);
            cgpa+=s.sgpa[i];

        }
        cgpa=cgpa/8.0;


        fwrite(&s,sizeof(s),1,fp);
    }

    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    system("pause");

}

void display(FILE * fp)
{
    title();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tDepartment : %s",s.dept);
        printf("\n\n\t\tROLL : %d",s.roll);
        printf("\n\n\tSGPA: ");

        for(i=0; i<8; i++)
            printf("| %.2f |",s.sgpa[i]);
        printf("\n\n\t\tCGPA : %.2f\n\t",s.cgpa);
        printChar('-',65);
    }
    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

void Individual(FILE *fp)
{
    title();

    int tempRoll, flag, siz, i;
    Student s;
    char another = 'y';

    siz = sizeof(s);

    while (another == 'y' || another == 'Y')
    {
        printf("\n\n\tEnter Roll Number: ");
        scanf("%d", &tempRoll);

        rewind(fp);
        flag = 0;

        while ((fread(&s, siz, 1, fp)) == 1)
        {
            if (s.roll == tempRoll)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            printf("\n\t\tNAME : %s", s.name);
            printf("\n\n\t\tDepartment : %s", s.dept);
            printf("\n\n\t\tROLL : %d", s.roll);
            printf("\n\n\tSGPA: ");

            for (i = 0; i < 8; i++)
                printf("| %.2f |", s.sgpa[i]);

            printf("\n\n\t\tCGPA : %.2f\n\t", s.cgpa);
            printChar('-', 65);
        }
        else
        {
            printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");
        }

        printf("\n\n\t\tShow another student information? (Y/N)?");
        fflush(stdin);
        another = getchar();
    }
}

