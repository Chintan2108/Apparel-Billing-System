#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

struct bill
{
    int pid;
    string pname;
    int pcost;
};

struct clothes
{
    string colour;
    int stock;

    void fetch()
    {
        cout << "Enter product color : ";
        cin >> colour;
        cout << "Enter Stock         : ";
        cin >> stock;
    }

};

class apparel
{
    protected:
        //clothes *head, *tail;
        int pprice, id;
        string ap, apd;
        const char *apname;

public:
    virtual void show() = 0;
    apparel() {//head = NULL;
               //tail = NULL;
               }

    ~apparel() {}

    void forashow()
    {
        cout << "\n\n";
        cout << "Product Name    : " << apd << '\n';
        cout << "Product ID      : " << id << '\n';
        cout << "Available Sizes : S,M,L\n";
        cout << "Product Cost    : " << pprice << '\n';
    }

    void flinsert(clothes *item)
        {
            int q = item->stock;
            string color = item->colour;
            int c[5], i=0;
            ifstream fin;
            fin.open(apname, ios::in);
            while(fin >> c[i])
            {
                i++;
            }
            fin.close();

            if(q)
            {
                if(color.compare("RED")==0)
                    c[0] = c[0] + q;
                else if(color.compare("GREEN")==0)
                    c[1] = c[1] + q;
                else if(color.compare("BLUE")==0)
                    c[2] = c[2] + q;
                else if(color.compare("BLACK")==0)
                    c[3] = c[3] + q;
                else if(color.compare("WHITE")==0)
                    c[4] =c [4] + q;
                else
                {
                    //do nothing
                }
                cout << "\nApparel(s) added successfully\n";
            }
            else
            {
                if(color.compare("RED")==0)
                    c[0] = 0;
                else if(color.compare("GREEN")==0)
                    c[1] = 0;
                else if(color.compare("BLUE")==0)
                    c[2] = 0;
                else if(color.compare("BLACK")==0)
                    c[3] = 0;
                else if(color.compare("WHITE")==0)
                    c[4] = 0;
                else
                {
                    //do nothing
                }
                cout << "\nApparel(s) deleted successfully\n";
            }

            ofstream fout;
            fout.open(apname, ios::out);
            for(int j=0; j<5; j++)
            {
                fout << c[j] << '\n';
            }
            fout.close();
        }

    int display()
    {

        int ps[5], i=0;
        cout << "\n\n" << apd << "\n***********\n";
        ifstream sin;
        sin.open(apname, ios::in);
        while(sin >> ps[i])
        {
            i++;
        }
        sin.close();
        cout << "COLOR\tSTOCK\n";
        cout << "-----\t-----\n\n";
        cout << "  RED\t" << ps[0] << '\n';
        cout << "GREEN\t" << ps[1] << '\n';
        cout << " BLUE\t" << ps[2] << '\n';
        cout << "BLACK\t" << ps[3] << '\n';
        cout << "WHITE\t" << ps[4] << '\n';

        if(!(ps[0] + ps[1] + ps[2] + ps[3] + ps[4]))
        {
            cout << "\n\n---OUT OF STOCK---\n";
            return 0;
        }
        else
            return 1;

        cout << "\n\n";
    }

    void addkart(bill *&done, int &total, string color, int q=1)
    {
        int c[5], i=0;
        ifstream sin;
        sin.open(apname, ios::in);
        while(sin >> c[i])
        {
            i++;
        }
        sin.close();

        if(color.compare("RED")==0)
        {
            if((c[0]-q)>=0)
            {
                done->pcost = pprice;
                done->pid = id;
                done->pname = apd;
                total = total + q*pprice;
                c[0] = c[0] - q;
            }
            else
            {
                cout << "\n---OUT OF STOCK---\nPlease enter proper quantity - Either equal or less than the no of items in stock\n";
            }
        }

        else if(color.compare("GREEN")==0)
        {
            if((c[1]-q)>=0)
            {
                done->pcost = pprice;
                done->pid = id;
                done->pname = apd;
                total = total + q*pprice;
                c[1] = c[1] - q;
            }
            else
            {
                cout << "\n---OUT OF STOCK---\nPlease enter proper quantity - Either equal or less than the no of items in stock\n";
            }
        }
        else if(color.compare("BLUE")==0)
        {
            if((c[2]-q)>=0)
            {
                done->pcost = pprice;
                done->pid = id;
                done->pname = apd;
                total = total + q*pprice;
                c[2] = c[2] - q;
            }
            else
            {
                cout << "\n---OUT OF STOCK---\nPlease enter proper quantity - Either equal or less than the no of items in stock\n";
            }
        }
        else if(color.compare("BLACK")==0)
        {
            if((c[3]-q)>=0)
            {
                done->pcost = pprice;
                done->pid = id;
                done->pname = apd;
                total = total + q*pprice;
                c[3] = c[3] - q;
            }
            else
            {
                cout << "\n---OUT OF STOCK---\nPlease enter proper quantity - Either equal or less than the no of items in stock\n";
            }
        }
        else if(color.compare("WHITE")==0)
        {
            if((c[4]-q)>=0)
            {
                done->pcost = pprice;
                done->pid = id;
                done->pname = apd;
                total = total + q*pprice;
                c[4] = c[4] - q;
            }
            else
            {
                cout << "\n---OUT OF STOCK---\nPlease enter proper quantity - Either equal or less than the no of items in stock\n";
            }
        }
        else
        {
            //do nothing
        }

            ofstream fout;
            fout.open(apname, ios::out);
            for(int j=0; j<5; j++)
            {
                fout << c[j] << '\n';
            }
            fout.close();
    }

};

class shirt : public apparel
{
    public:
        void show() {}
        shirt() {//head = NULL;
               //tail = NULL;
               pprice = 800;
               id = 1;
               ap = "SHIRTS";
               apd = ap;
               ap = "C:\\Apparel Billing System\\Stock\\" + ap + ".txt";
               apname = ap.c_str();}

        ~shirt() {}
};

class trouser : public apparel
{
    public:
        void show() {}
        trouser() {//head = NULL;
               //tail = NULL;
               pprice = 1200;
               id = 2;
               ap = "TROUSERS";
               apd = ap;
               ap = "C:\\Apparel Billing System\\Stock\\" + ap + ".txt";
               apname = ap.c_str();}

        ~trouser() {}

};

class jeans : public apparel
{
    public:
        void show() {}
        jeans() {//head = NULL;
               //tail = NULL;
               pprice = 1000;
               id = 3;
               ap = "JEANS";
               apd = ap;
               ap = "C:\\Apparel Billing System\\Stock\\" + ap + ".txt";
               apname = ap.c_str();}

        ~jeans() {}
};

class kurta : public apparel
{
    public:
        void show() {}
        kurta() {//head = NULL;
               //tail = NULL;
               pprice = 1000;
               id = 4;
               ap = "KURTA";
               apd = ap;
               ap = "C:\\Apparel Billing System\\Stock\\" + ap + ".txt";
               apname = ap.c_str();}

        ~kurta() {}
};

class traditional : public apparel
{
    public:
        void show() {}
        traditional() {//head = NULL;
               //tail = NULL;
               pprice = 2500;
               id = 5;
               ap = "TRADITIONAL";
               apd = ap;
               ap = "C:\\Apparel Billing System\\Stock\\" + ap + ".txt";
               apname = ap.c_str();}

        ~traditional() {}
};

class partywear : public apparel
{
    public:
        void show() {}
        partywear() {//head = NULL;
               //tail = NULL;
               pprice = 4000;
               id = 6;
               ap = "PARTYWEAR";
               apd = ap;
               ap = "C:\\Apparel Billing System\\Stock\\" + ap + ".txt";
               apname = ap.c_str();}

        ~partywear() {}
};



