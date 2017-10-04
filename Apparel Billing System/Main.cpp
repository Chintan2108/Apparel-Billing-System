#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Welcome.cpp"
#include "Inventory.cpp"
using namespace std;


int main()
{
    cout << "***********************************************\n";
    cout << "\t\tAPPAREL BILLING SYSTEM";
    cout << "\n***********************************************\n";
    ofstream fout;
    int menu;
    clothes *p = new clothes;
    shirt s1;
    trouser t1;
    jeans j1;
    kurta k1;
    traditional td1;
    partywear p1;
    char s;
    system("COLOR 1b");
    do
    {
    cout << "Press 1 for Administrator Menu\n";
    cout << "Press 2 for   Customer    Menu\n";
    cin >> menu;

    switch(menu)
    {
    case 1:
        {
            int log = login();
            if(log)
            {
                system("CLS");
                system("COLOR 1d");
                cout << "\nLogin Successful\n";
                if(log == 1)
                    cout << "\n\nWelcome TEJAS !\n\n";
                else if(log == 2)
                    cout << "\n\nWelcome CHINTAN !\n\n";
                else
                    cout << "\n\nWelcome VASHISHTHA !\n\n";
                //services
                char ad;
                do
                {
                system("CLS");
                if(log == 1)
                    cout << "\n\nWelcome TEJAS !\n\n";
                else if(log == 2)
                    cout << "\n\nWelcome CHINTAN !\n\n";
                else
                    cout << "\n\nWelcome VASHISHTHA !\n\n";
                cout << "Press 1 to view stock\n";
                cout << "Press 2 to add a new item or remove items from inventory\nNote : To remove an item enter its quantity as \'0\'\n";

                char c;
                cin >> c;

                switch(c)
                {
                case '1':
                    {
                        s1.display();
                        t1.display();
                        j1.display();
                        k1.display();
                        td1.display();
                        p1.display();

                        cout << "\nPress y to go again\n\n";
                        cin >> ad;
                        break;

                    }
                case '2':
                    {
                        cout << "Press s for shirt\n";
                        cout << "Press r for trouser\n";
                        cout << "Press j for jeans\n";
                        cout << "Press k for kurta\n";
                        cout << "Press t for traditional\n";
                        cout << "Press p for partywear\n";
                        char ch;
                        fflush(stdin);
                        cin >> ch;

                        switch(ch)
                        {
                        case 's':
                            {
                                cout << "\nSHIRT\n";
                                s1.forashow();
                                p->fetch();
                                s1.flinsert(p);
                                break;
                            }
                        case 'r':
                            {
                                cout << "\nTROUSER\n";
                                t1.forashow();
                                p->fetch();
                                t1.flinsert(p);
                                break;
                            }
                        case 'j':
                            {
                                cout << "\nJEANS\n";
                                j1.forashow();
                                p->fetch();
                                j1.flinsert(p);
                                break;
                            }
                        case 'k':
                            {
                                cout << "\nKURTA\n";
                                k1.forashow();
                                p->fetch();
                                k1.flinsert(p);
                                break;
                            }
                        case 't':
                            {
                                cout << "\nTRADITIONAL\n";
                                td1.forashow();
                                p->fetch();
                                td1.flinsert(p);
                                break;
                            }
                        case 'p':
                            {
                                cout << "\nPARTYWEAR\n";
                                p1.forashow();
                                p->fetch();
                                p1.flinsert(p);
                                break;
                            }
                        }

                        cout << "\nPress y to go again\nPress any other key to exit administrator mode\n\n";
                        cin >> ad;
                        break;
                    }

                    default:
                        {
                            c = 'n';
                            break;
                        }
                }
                }
                while(ad == 'y' || ad == 'Y');

            }
            else
            {
                system("CLS");
                system("COLOR 1c");
                cout << "\n\nUser ID / Password combination not identified!\n";
                exit(0);
            }
            cout << "\nPress y to switch to customer mode\n\n";
            cin >> s;
            break;


        }


    case 2:
        {
            system("CLS");
            system("COLOR 2b");
            int total = 0;
            cout << "Welcome User!\n";
            //do
            cout << "\nEnter your name       : ";
            string uname, contactno, email;
            cin >> uname;
            cout << "\nEnter your contact no : ";
            cin >> contactno;
            cout << "\nEnter your email      : ";
            cin >> email;

            string f = "Invoice_", no;
            int i_no;

            ifstream cfin;
            cfin.open("C:\\Apparel Billing System\\count.txt", ios::in);
            while(!cfin.eof())
                cfin >> no;
            cfin.close();

            f = "C:\\Apparel Billing System\\Invoices\\" + f + no + ".txt";
            const char *invoice = f.c_str();

            cfin.open("C:\\Apparel Billing System\\count.txt", ios::in);
            while(!cfin.eof())
                cfin >> i_no;
            cfin.close();
            ofstream cfout;
            cfout.open("C:\\Apparel Billing System\\count.txt",ios::out);
            cfout << ++i_no;
            cfout.close();

            fout.open(invoice,ios::out);
            fout << "\t\t\t\tAPPAREL BILLING SYSTEM\n\n\n";
            fout << "Customer Name : " << uname << "\t\t\t";
            fout << "Contact No : " << contactno << '\n';
            fout << "E-Mail : " << email << '\n';
            fout << "--------------------------------------------------------------------------------\n";
            fout << "\n\t\t\t********************INVOICE********************\n\n";
			fout << "Sr No\tProduct ID\t\tProduct Name\t\tRate\t\tQuantity\t\tPrice\n";
            fout << "-----\t----------\t\t------------\t\t----\t\t--------\t\t-----\n\n";
            fout.close();
            static int srno = 1;
            char go;
            do
            {
            cout << "Press s to buy SHIRT\n";
            cout << "Press r to buy TROUSER\n";
            cout << "Press j to buy JEANS\n";
            cout << "Press k to buy KURTA\n";
            cout << "Press t to buy TRADITIONAL\n";
            cout << "Press p to buy PARTYWEAR\n";
            char uch;
            cin >> uch;

            switch(uch)
            {
            case 's':
                {
                    system("CLS");
                    system("COLOR 9F");
                    cout << "\t\t\tWelcome " << uname << "\n";
                    if(s1.display() == 1)
                    {
                    s1.forashow();
                    cout << "\n\nEnter product ID to add to CKART : ";
                    int id, q;
                    string color;
                    char sz;
                    cin >> id;
                    cout << "Enter quantity :\n";
                    cin >> q;
                    cout << "Enter color (In uppercase) :\n";
                    cin >> color;
                    cout << "Enter size (S, M, L) :\n";
                    cin >> sz;
                    bill *done = new bill;
                    s1.addkart(done, total, color, q);
                    //copy to file
                    fout.open(invoice, ios::app);
                    //fout << "Sr No\tProduct ID\t\tProduct Name\t\tRate\t\tQuantity\t\tPrice\n";
                    fout << setw(5) << setfill(' ') << srno;
                    fout << "\t";
                    fout << setw(10) << setfill(' ') << done->pid;
                    fout << "\t\t";
                    fout << setw(12) << setfill(' ') << done->pname;
                    fout << "\t\t";
                    fout << setw(4) << setfill(' ') << done->pcost;
                    fout << "\t\t";
                    fout << setw(8) << setfill(' ') << q;
                    fout << "\t\t";
                    fout << setw(5) << setfill(' ') << q*(done->pcost);
                    fout << "\n";
                    }
                    char z;
                    cout << "\nPress z to conclude order\nPress any other key to shop further\n\n";
                    cin >> z;
                    if(z == 'z' || z == 'Z')
                    {
                        cout << "\n***********THANK YOU FOR SHOPPING**********\n";
			system("PAUSE");
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "TOTAL PAYABLE AMOUNT : ";
                        fout << setw(5) << setfill(' ') << double(total);
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "\n***********THANK YOU FOR SHOPPING**********\n";
                        fout.close();
                        exit(0);
                    }
                    else
                    {
                        fout.close();
                        srno++;
                    }

                    //copy to file
                    cout << "Press y to go again\n";
                    cin >> go;
                    break;
                }

            case 'r':
                {
                    system("CLS");
                    system("COLOR 8F");
                    cout << "\t\t\tWelcome " << uname << "\n";
                    if(t1.display() == 1)
                    {
                    t1.forashow();
                    cout << "\n\nEnter product ID to add to CKART : ";
                    int id, q;
                    string color;
                    char sz;
                    cin >> id;
                    cout << "Enter quantity :\n";
                    cin >> q;
                    cout << "Enter color (In uppercase) :\n";
                    cin >> color;
                    cout << "Enter size (S, M, L) :\n";
                    cin >> sz;
                    bill *done = new bill;
                    t1.addkart(done, total, color, q);
                    //copy to file
                    fout.open(invoice, ios::app);
                    //fout << "Sr No\tProduct ID\t\tProduct Name\t\tRate\t\tQuantity\t\tPrice\n";
                    fout << setw(5) << setfill(' ') << srno;
                    fout << "\t";
                    fout << setw(10) << setfill(' ') << done->pid;
                    fout << "\t\t";
                    fout << setw(12) << setfill(' ') << done->pname;
                    fout << "\t\t";
                    fout << setw(4) << setfill(' ') << done->pcost;
                    fout << "\t\t";
                    fout << setw(8) << setfill(' ') << q;
                    fout << "\t\t";
                    fout << setw(5) << setfill(' ') << q*(done->pcost);
                    fout << "\n";
                    }
                    char z;
                    cout << "\nPress z to conclude order\nPress any other key to shop further\n\n";
                    cin >> z;
                    if(z == 'z' || z == 'Z')
                    {
                        cout << "\n***********THANK YOU FOR SHOPPING**********\n";
			system("PAUSE");
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "TOTAL PAYABLE AMOUNT : ";
                        fout << setw(5) << setfill(' ') << double(total);
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "\n***********THANK YOU FOR SHOPPING**********\n";
                        fout.close();
                        exit(0);
                    }
                    else
                    {
                        fout.close();
                        srno++;
                    }
                    //copy to file

                    cout << "Press y to go again\n";
                    cin >> go;
                    break;
                }

            case 'j':
                {
                    system("CLS");
                    system("COLOR 5B");
                    cout << "\t\t\tWelcome " << uname << "\n";
                    //cout << "\nJEANS\n";
                    //jeans j1;
                    if(j1.display() == 1)
                    {
                    j1.forashow();
                    cout << "\n\nEnter product ID to add to CKART : ";
                    int id, q;
                    string color;
                    char sz;
                    cin >> id;
                    cout << "Enter quantity :\n";
                    cin >> q;
                    cout << "Enter color (In uppercase) :\n";
                    cin >> color;
                    cout << "Enter size (S, M, L) :\n";
                    cin >> sz;
                    bill *done = new bill;
                    j1.addkart(done, total, color, q);
                    //copy to file
                    fout.open(invoice, ios::app);
                    //fout << "Sr No\tProduct ID\t\tProduct Name\t\tRate\t\tQuantity\t\tPrice\n";
                    fout << setw(5) << setfill(' ') << srno;
                    fout << "\t";
                    fout << setw(10) << setfill(' ') << done->pid;
                    fout << "\t\t";
                    fout << setw(12) << setfill(' ') << done->pname;
                    fout << "\t\t";
                    fout << setw(4) << setfill(' ') << done->pcost;
                    fout << "\t\t";
                    fout << setw(8) << setfill(' ') << q;
                    fout << "\t\t";
                    fout << setw(5) << setfill(' ') << q*(done->pcost);
                    fout << "\n";
                    }
                    char z;
                    cout << "\nPress z to conclude order\nPress any other key to shop further\n\n";
                    cin >> z;
                    if(z == 'z' || z == 'Z')
                    {
                        cout << "\n***********THANK YOU FOR SHOPPING**********\n";
			system("PAUSE");
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "TOTAL PAYABLE AMOUNT : ";
                        fout << setw(5) << setfill(' ') << double(total);
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "\n***********THANK YOU FOR SHOPPING**********\n";
                        fout.close();
                        exit(0);
                    }
                    else
                    {
                        fout.close();
                        srno++;
                    }
                    //copy to file

                    cout << "Press y to go again\n";
                    cin >> go;
                    break;
                }

            case 'k':
                {
                    system("CLS");
                    system("COLOR CF");
                    cout << "\t\t\tWelcome " << uname << "\n";
                    //cout << "\nKURTA\n";
                    //kurta k1;
                    if(k1.display() == 1)
                    {
                    k1.forashow();
                    cout << "\n\nEnter product ID to add to CKART : ";
                    int id, q;
                    string color;
                    char sz;
                    cin >> id;
                    cout << "Enter quantity :\n";
                    cin >> q;
                    cout << "Enter color (In uppercase) :\n";
                    cin >> color;
                    cout << "Enter size (S, M, L) :\n";
                    cin >> sz;
                    bill *done = new bill;
                    k1.addkart(done, total, color, q);
                    //copy to file
                    fout.open(invoice, ios::app);
                    //fout << "Sr No\tProduct ID\t\tProduct Name\t\tRate\t\tQuantity\t\tPrice\n";
                    fout << setw(5) << setfill(' ') << srno;
                    fout << "\t";
                    fout << setw(10) << setfill(' ') << done->pid;
                    fout << "\t\t";
                    fout << setw(12) << setfill(' ') << done->pname;
                    fout << "\t\t";
                    fout << setw(4) << setfill(' ') << done->pcost;
                    fout << "\t\t";
                    fout << setw(8) << setfill(' ') << q;
                    fout << "\t\t";
                    fout << setw(5) << setfill(' ') << q*(done->pcost);
                    fout << "\n";
                    }
                    char z;
                    cout << "\nPress z to conclude order\nPress any other key to shop further\n\n";
                    cin >> z;
                    if(z == 'z' || z == 'Z')
                    {
                        cout << "\n***********THANK YOU FOR SHOPPING**********\n";
			system("PAUSE");
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "TOTAL PAYABLE AMOUNT : ";
                        fout << setw(5) << setfill(' ') << double(total);
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "\n***********THANK YOU FOR SHOPPING**********\n";
                        fout.close();
                        exit(0);
                    }
                    else
                    {
                        fout.close();
                        srno++;
                    }
                    //copy to file

                    cout << "Press y to go again\n";
                    cin >> go;
                    break;
                }

            case 't':
                {
                    system("CLS");
                    system("COLOR 4F");
                    cout << "\t\t\tWelcome " << uname << "\n";
                    //cout << "\nTRADITIONAL\n";
                    //traditional td1;
                    if(td1.display() == 1)
                    {
                    td1.forashow();
                    cout << "\n\nEnter product ID to add to CKART : ";
                    int id, q;
                    string color;
                    char sz;
                    cin >> id;
                    cout << "Enter quantity :\n";
                    cin >> q;
                    cout << "Enter color (In uppercase) :\n";
                    cin >> color;
                    cout << "Enter size (S, M, L) :\n";
                    cin >> sz;
                    bill *done = new bill;
                    td1.addkart(done, total, color, q);
                    //copy to file
                    fout.open(invoice, ios::app);
                    //fout << "Sr No\tProduct ID\t\tProduct Name\t\tRate\t\tQuantity\t\tPrice\n";
                    fout << setw(5) << setfill(' ') << srno;
                    fout << "\t";
                    fout << setw(10) << setfill(' ') << done->pid;
                    fout << "\t\t";
                    fout << setw(12) << setfill(' ') << done->pname;
                    fout << "\t\t";
                    fout << setw(4) << setfill(' ') << done->pcost;
                    fout << "\t\t";
                    fout << setw(8) << setfill(' ') << q;
                    fout << "\t\t";
                    fout << setw(5) << setfill(' ') << q*(done->pcost);
                    fout << "\n";
                    }
                    char z;
                    cout << "\nPress z to conclude order\nPress any other key to shop further\n\n";
                    cin >> z;
                    if(z == 'z' || z == 'Z')
                    {
                        cout << "\n***********THANK YOU FOR SHOPPING**********\n";
			system("PAUSE");
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "TOTAL PAYABLE AMOUNT : ";
                        fout << setw(5) << setfill(' ') << double(total);
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "\n***********THANK YOU FOR SHOPPING**********\n";
                        fout.close();
                        exit(0);
                    }
                    else
                    {
                        fout.close();
                        srno++;
                    }
                    //copy to file

                    cout << "Press y to go again\n";
                    cin >> go;
                    break;
                }

            case 'p':
                {
                    system("CLS");
                    system("COLOR A5");
                    cout << "\t\t\tWelcome " << uname << "\n";
                    //cout << "\nPARTYWEAR\n";
                    //partywear p1;
                    if(p1.display() == 1)
                    {
                    p1.forashow();
                    cout << "\n\nEnter product ID to add to CKART : ";
                    int id, q;
                    string color;
                    char sz;
                    cin >> id;
                    cout << "Enter quantity :\n";
                    cin >> q;
                    cout << "Enter color (In uppercase) :\n";
                    cin >> color;
                    cout << "Enter size (S, M, L) :\n";
                    cin >> sz;
                    bill *done = new bill;
                    p1.addkart(done, total, color, q);
                    //copy to file
                    fout.open(invoice, ios::app);
                    //fout << "Sr No\tProduct ID\t\tProduct Name\t\tRate\t\tQuantity\t\tPrice\n";
                    fout << setw(5) << setfill(' ') << srno;
                    fout << "\t";
                    fout << setw(10) << setfill(' ') << done->pid;
                    fout << "\t\t";
                    fout << setw(12) << setfill(' ') << done->pname;
                    fout << "\t\t";
                    fout << setw(4) << setfill(' ') << done->pcost;
                    fout << "\t\t";
                    fout << setw(8) << setfill(' ') << q;
                    fout << "\t\t";
                    fout << setw(5) << setfill(' ') << q*(done->pcost);
                    fout << "\n";
                    }
                    char z;
                    cout << "\nPress z to conclude order\nPress any other key to shop further\n\n";
                    cin >> z;
                    if(z == 'z' || z == 'Z')
                    {
                        cout << "\n***********THANK YOU FOR SHOPPING**********\n";
			system("PAUSE");
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "TOTAL PAYABLE AMOUNT : ";
                        fout << setw(5) << setfill(' ') << double(total);
                        fout << "\n--------------------------------------------------------------------------------\n";
                        fout << "\n***********THANK YOU FOR SHOPPING**********\n";
                        fout.close();
                        exit(0);
                    }
                    else
                    {
                        fout.close();
                        srno++;
                    }
                    //copy to file

                    cout << "Press y to go again\n";
                    cin >> go;
                    break;
                }
            }
            }
            while(go == 'y' || go == 'Y');

        }
    }
    }
    while(s == 'y' || s == 'Y');

    return 0;
}


