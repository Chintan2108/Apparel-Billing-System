#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;

int login()
{
    string user, pass;
    cout << "\t\t\t**********  L O G I N   P A G E  **********\n";
    cout << "\n\nUser ID  : ";
    cin >> user;
    fflush(stdin);
    cout << "\nPassword : ";
    char c[20], t;
    int i=0;
    while((t=getch())!='\n')
    {
        c[i]=t;
        i++;
        cout << "*";
    }
    c[i]='\0';
    pass=c;

    if(user=="Tejas" && pass=="tejas123")
        return 1;

    else if(user=="Chintan" && pass=="chintan123")
        return 2;

    else if(user=="Vashishtha" && pass=="vashishtha123")
        return 3;

    else
        return 0;


    getch();
}
