/* Vehicle parking program */
//THIS PROGRAM IS BROUGHT TO YOU BY CODE-PROJECTS//
//FOR MORE PROJECTS LOG ON TO : www.code-projects.org//

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define CAR 1
#define SCOOTER 2

struct vehicle
{
    int num ;
    int row ;
    int col ;
    int type ;
};

int parkinfo[4][10];
int vehcount;
int carcount;
int scootercount;

void display( );
void changecol ( struct vehicle * );
struct vehicle * add ( int, int, int, int );
void del ( struct vehicle * );
void getfreerowcol ( int, int * );
void getrcbyinfo ( int, int, int * );
void show( );

void changecol ( struct vehicle *v )
{
    v -> col = v -> col - 1 ;
}

struct vehicle * add ( int t, int num, int row, int col )
{
    struct vehicle *v ;

    v = ( struct vehicle * ) malloc ( sizeof ( struct vehicle ) ) ;

    v -> type = t ;
    v -> row = row ;
    v -> col = col ;

    if ( t == CAR )
        carcount++ ;
    else
        scootercount++ ;

    vehcount++ ;
    parkinfo[row][col] = num ;

    return v ;
}

void login()
{
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";

    do
    {
        printf("\n LOGIN FIRST ");
        printf(" \n\n ENTER USERNAME:-");
        scanf("%s", &uname);

        printf(" \n\n ENTER PASSWORD:-");

        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];

            if(c==13)
                break;
            else
                printf("*");

            i++;
        }

        pword[i]='\0';
        i=0;

        if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
        {
            printf("\n WELCOME !! YOUR LOGIN IS SUCCESSFUL");
            printf("\nPress any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n LOGIN UNSUCCESSFUL");
            a++;
            getch();
        }

    } while(a<=2);

    if (a>2)
    {
        printf("\nWrong username and password entered four times!!!");
        getch();
    }

    system("cls");
}

void del ( struct vehicle *v )
{
    int c ;

    for ( c = v -> col ; c < 9 ; c++ )
        parkinfo[v -> row][c] = parkinfo[v -> row][c+1] ;

    parkinfo[v -> row][c] = 0 ;

    if ( v -> type == CAR )
        carcount-- ;
    else
        scootercount-- ;

    vehcount-- ;
}

void getfreerowcol ( int type, int *arr )
{
    int r, c, fromrow = 0, torow = 2 ;

    if ( type == SCOOTER )
    {
        fromrow += 2 ;
        torow += 2 ;
    }

    for ( r = fromrow ; r < torow ; r++ )
    {
        for ( c = 0 ; c < 10 ; c++ )
        {
            if ( parkinfo[r][c] == 0 )
            {
                arr[0] = r ;
                arr[1] = c ;
                return ;
            }
        }
    }

    arr[0] = -1 ;
    arr[1] = -1 ;
}

void getrcbyinfo ( int type, int num, int *arr )
{
    int r, c, fromrow = 0, torow = 2 ;

    if ( type == SCOOTER )
    {
        fromrow += 2 ;
        torow += 2 ;
    }

    for ( r = fromrow ; r < torow ; r++ )
    {
        for ( c = 0 ; c < 10 ; c++ )
        {
            if ( parkinfo[r][c] == num )
            {
                arr[0] = r ;
                arr[1] = c ;
                return ;
            }
        }
    }

    arr[0] = -1 ;
    arr[1] = -1 ;
}

void display( )
{
    int r, c ;

    printf ( "Cars =>\n" ) ;

    for ( r = 0 ; r < 4 ; r++ )
    {
        if ( r == 2 )
            printf ( "Scooters =>\n" ) ;

        for ( c = 0 ; c < 10 ; c++ )
            printf ( "%d\t", parkinfo[r][c] ) ;

        printf ( "\n" ) ;
    }
}

int main( )
{
    int choice, type, number, row = 0, col = 0 ;
    int i, tarr[2] ;
    int finish = 1 ;

    struct vehicle *car[2][10] ;
    struct vehicle *scooter[2][10] ;

    system ( "cls" ) ;

    login();

    while ( finish )
    {
        system ( "cls" ) ;

        printf ( "\n VEHICLE PARKING \n" ) ;

        printf ( "\n1>> Arrival Of Vehicle\n" ) ;
        printf ( "\n2>> Total No. Of Vehicles Parked\n" ) ;
        printf ( "\n3>> Total No. Of Cars Parked\n" ) ;
        printf ( "\n4>> Total No. Of Scooters Parked\n" ) ;
        printf ( "\n5>> Display Vehicles Parked\n" ) ;
        printf ( "\n6>> Departure Of Vehicle\n" ) ;
        printf ( "\n7>> Exit\n" ) ;

        printf("Enter Choice:");
        scanf ( "%d", &choice ) ;

        switch ( choice )
        {

        case 1 :

            printf ( "Enter vehicle type (1 Car / 2 Scooter): " ) ;
            scanf ( "%d", &type ) ;

            printf ( "Enter vehicle number: " ) ;
            scanf ( "%d", &number ) ;

            getfreerowcol ( type, tarr ) ;

            if ( tarr[0] != -1 )
            {
                row = tarr[0] ;
                col = tarr[1] ;

                if ( type == CAR )
                    car[row][col] = add ( type, number, row, col ) ;
                else
                    scooter[row-2][col] = add ( type, number, row, col ) ;
            }
            else
            {
                printf ( "No parking slot free\n" ) ;
            }

            getch();
            break ;

        case 2 :
            printf ( "Total vehicles parked: %d\n", vehcount ) ;
            getch();
            break ;

        case 3 :
            printf ( "Total cars parked: %d\n", carcount ) ;
            getch();
            break ;

        case 4 :
            printf ( "Total scooters parked: %d\n", scootercount ) ;
            getch();
            break ;

        case 5 :
            display();
            getch();
            break ;

        case 6 :

            printf ( "Enter vehicle type (1 Car / 2 Scooter): " ) ;
            scanf ( "%d", &type ) ;

            printf ( "Enter number: " ) ;
            scanf ( "%d", &number ) ;

            getrcbyinfo ( type, number, tarr ) ;

            if ( tarr[0] != -1 )
            {
                col = tarr[1] ;

                if ( type == CAR )
                {
                    row = tarr[0] ;
                    del ( car[row][col] ) ;
                }
                else
                {
                    row = tarr[0] - 2 ;
                    del ( scooter[row][col] ) ;
                }
            }

            getch();
            break ;

        case 7 :
            finish = 0 ;
            break ;
        }
    }

    return 0 ;
}