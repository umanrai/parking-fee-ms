#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <fstream>

using namespace std;

void parkingfee(){

    int types, names, fee, cost, ref;
    string no;
    float in, exit, duration;

    cout<<" Transportation type    : "; cin>>types;
    cout<<" Plate number           : "; cin>>no;
    cout<<" Arrival time           : "; cin>>in;
    cout<<" Departure time         : "; cin>>exit;

    if (exit >= in)
        duration = exit - in;
    else
        duration = (12 - in) + exit;

    cout<<" Parking Duration         : "<<duration<<"Hour"<<endl;
    if (duration >=2 && types==1){
        fee=(duration-0)*100*1;
        cout<<" Parking fee        :Rs"<<fee<<endl;
    }
    else if (duration >=2 && types==2){
        fee=(duration-0)*250*1;

        cout<<" Parking fee        :Rs"<<fee<<endl;
    }
    else if (duration >=2 && types==3){
        fee=(duration-0)*500*1;
        cout<<" Parking fee        :Rs"<<fee<<endl;
    }
    else if (duration >=2 && types==1){
        fee=100;
        cout<<" Parking fee        :Rs"<<fee<<endl;
    }
    else if (duration >=2 && types==2){
        fee=250;
        cout<<" Parking fee        :Rs"<<fee<<endl;
    }
    else if (duration >=2 && types==3){
        fee=500;
        cout<<" Parking fee        :Rs"<<fee<<endl;
    }

    cout<<endl<<endl;
    cout<<"Enter the cost          :Rs"; cin>>cost;
    ref=cost-fee;
    cout<<"Refund                 :Rs"<<ref;
    cout<<endl<<endl;
    cout<<"printing struct........."<<endl;

    // open a file in write mode.
    ofstream outfile;
    outfile.open("afile.dat");

    // write billing data into the file.
    outfile << types << endl;
    outfile <<  no << endl;
    outfile <<  duration << endl;
    outfile << fee << endl;
    outfile.close();

    goto print;

    print :
        cout<<endl<<endl;
        cout<<"..............................................................."<<endl;
        cout<<"|  Type                             : "<<types<<endl;
        cout<<"|  Plate number                     : "<<no<<endl;
        cout<<"|  Parking Duration                 : "<<duration<<"Hour"<<endl;
        cout<<"|  Parking Fee                      : Rs "<<fee<<endl;
        cout<<"                           ---- Paid ---                       "<<endl;
        cout<<"..............................................................."<<endl;
        cout<<"                  THANKY YOU                       "<<endl;
        cout<<"..............................................................."<<endl;
        cout<<endl<<endl;
}

void readBills()
{
    char data[400];

    system("cls");
    // open a file in read mode.
   ifstream infile;
   infile.open("afile.dat");

   cout << "Reading from the file" << endl;
   infile >> data;

   // write the data at the screen.
   cout<<" Transportation type     : " << data <<endl;

   // again read the data from the file and display it.
   infile >> data;
   cout<<" Plate number            : " << data <<endl;

   // again read the data from the file and display it.
   infile >> data;
   cout<<" Arrival time            : " << data <<endl;

   // again read the data from the file and display it.
   infile >> data;
   cout<<" Departure time         :  " << data <<endl;

   // close the opened file.
   infile.close();

   system("pause");
}


int main() {
    FILE *fp, *ft;
    char another, choice;

    fp=fopen("users.txt","rb+");

    if (fp == NULL) {
        fp = fopen("users.txt","wb+");

        if (fp == NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }

    while(1) {
         system("cls");
         start:
         cout << "\t\t\t\t\t\t====== PARKING SYSTEM ======";
         cout <<"\n\n                                          ";
         cout << "\n\n";
         cout << "\n \t\t\t 1. Press 1 for Transportation type.";
         cout << "\n \t\t\t 2. Press 2 to show the details.";
         cout << "\n \t\t\t 3. Exit   Program";
         cout << "\n\n";
         cout << "\t\t\t Select Your Choice :=> ";
         fflush(stdin);
         choice = getche();
         switch(choice)
         {
          case '1' :
                fseek(fp,0,SEEK_END);
                another ='Y';
                while(another == 'Y' || another == 'y')
                {
                      system("cls");

                   char a;
        parking:
            cout<<"..............................................................."<<endl;
            cout<<"           PARKING FEE (MOTORCYCLE/CAR)           "<<endl;
            cout<<"                  CIVIL MALL                      "<<endl;
            cout<<"               KATHMANDU, NEPAL                   "<<endl;
            cout<<"..............................................................."<<endl;
            cout<<"|             -- Transportation type --           "<<endl;
            cout<<"|  Motorcycle : 1                                 "<<endl;
            cout<<"|  Car        : 2                                 "<<endl;
            cout<<"|  Minibus    : 3                                 "<<endl;
            cout<<"..............................................................."<<endl;

        parkingfee();

        cout<<"Count again ? (y/n) "; cin>>a;
        cout<<endl;
        while (a=='y' || a=='Y')
            goto parking;
            goto start;
                }

                break;
       case '2':
                system("cls");
                readBills();
                break;
        case '3':
                  fclose(fp);
                  cout << "\n\n";
                  cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
                  cout << "\n\n";
                  exit(0);
              }
         }


    system("pause");
    return 0;
}
