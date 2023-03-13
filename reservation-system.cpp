#include <bits/stdc++.h>

using namespace std;
#define MAX 20

int divi = 0;
string date;

pair<int,string> arr[24] = {
    // pune-mumbai

    {500,"1000010110001"},
    {500,"10000000001"},

    // pune-delhi

    {700,"10000010001"},
    {700,"100010001001"},

    // pune-chennai

    {980,"10000100011"},
    {980,"1010000000101"},

    // mumbai-pune

    {500,"100100101100101"},
    {500,"10010110001"},

    // mumbai-delhi

    {750,"100000110001"},
    {750,"10100100101"},

    // mumbai-chennai

    {1050,"100101010001"},
    {1050,"10010001001"},

    // delhi-pune

    {700,"1011010110001"},
    {700,"10100001001"},

    // delhi-mumbai

    {750,"1010101010001"},
    {750,"100100100101"},

    // delhi-chennai

    {1360,"10011000110001"},
    {1360,"100101010101"},

    // chennai-pune

        {980,"101001010101"},
        {980,"10001010101"},

    // chennai-mumbai

       {1050, "1100010110111"},
        {1050,"00000000000"},

    // chennai-delhi

        {1360,"11001010100101"},
        {1360,"1001010010101"},

};


struct Buses
{
    int i1;
    string seats;
};

// Store the permamnent bus data use only once
void store_data_buses(ofstream &write)
{
    for (int i = 0; i < 24; i++)
    {
        write << i << endl;
        write << arr[i].second << endl;
    }
}

// read data
Buses get_data(ifstream &read)
{
    Buses obj;
    read >> obj.i1;
    read >> obj.seats;

    return obj;
}

void update_buses(int select[], int n_seats, ifstream &read, int flag)
{
    ofstream write("temp.txt");
    Buses b;
    b = get_data(read);
    while (!read.eof())
    {
        if (divi == b.i1)
        {
            for (int i = 0; i < n_seats; i++)
            {
                int ch = select[i];
                if (flag)
                    b.seats[ch - 1] = '1';
                else
                    b.seats[ch - 1] = '0';
            }

            write << b.i1 << endl;
            write << b.seats << endl;
        }
        else
        {

            write << b.i1 << endl;
            write << b.seats << endl;
        }
        b = get_data(read);
    }
    write.close();
    read.close();
    remove("buses.txt");
    rename("temp.txt", "buses.txt");
}

int find_index(char div[100], char des[100], int t)
{

    if (strcmp(div, "pune") == 0 and strcmp(des, "mumbai") == 0 and t == 1)
        divi = 0;
    else if (strcmp(div, "pune") == 0 and strcmp(des, "mumbai") == 0 and t == 2)
        divi = 1;

    else if (strcmp(div, "pune") == 0 and strcmp(des, "delhi") == 0 and t == 1)
        divi = 2;
    else if (strcmp(div, "pune") == 0 and strcmp(des, "delhi") == 0 and t == 2)
        divi = 3;

    else if (strcmp(div, "pune") == 0 and strcmp(des, "chennai") == 0 and t == 1)
        divi = 4;
    else if (strcmp(div, "pune") == 0 and strcmp(des, "chennai") == 0 and t == 2)
        divi = 5;

    else if (strcmp(div, "mumbai") == 0 and strcmp(des, "pune") == 0 and t == 1)
        divi = 6;
    else if (strcmp(div, "mumbai") == 0 and strcmp(des, "pune") == 0 and t == 2)
        divi = 7;

    else if (strcmp(div, "mumbai") == 0 and strcmp(des, "delhi") == 0 and t == 1)
        divi = 8;
    else if (strcmp(div, "mumbai") == 0 and strcmp(des, "delhi") == 0 and t == 2)
        divi = 9;

    else if (strcmp(div, "mumbai") == 0 and strcmp(des, "chennai") == 0 and t == 1)
        divi = 10;
    else if (strcmp(div, "mumbai") == 0 and strcmp(des, "chennai") == 0 and t == 2)
        divi = 11;

    else if (strcmp(div, "chennai") == 0 and strcmp(des, "pune") == 0 and t == 1)
        divi = 12;
    else if (strcmp(div, "chennai") == 0 and strcmp(des, "pune") == 0 and t == 2)
        divi = 13;

    else if (strcmp(div, "chennai") == 0 and strcmp(des, "mumbai") == 0 and t == 1)
        divi = 14;
    else if (strcmp(div, "chennai") == 0 and strcmp(des, "mumbai") == 0 and t == 2)
        divi = 15;

    else if (strcmp(div, "chennai") == 0 and strcmp(des, "delhi") == 0 and t == 1)
        divi = 16;
    else if (strcmp(div, "chennai") == 0 and strcmp(des, "delhi") == 0 and t == 2)
        divi = 17;

    else if (strcmp(div, "delhi") == 0 and strcmp(des, "pune") == 0 and t == 1)
        divi = 18;
    else if (strcmp(div, "delhi") == 0 and strcmp(des, "pune") == 0 and t == 2)
        divi = 19;

    else if (strcmp(div, "delhi") == 0 and strcmp(des, "mumbai") == 0 and t == 1)
        divi = 20;
    else if (strcmp(div, "delhi") == 0 and strcmp(des, "mumbai") == 0 and t == 2)
        divi = 21;

    else if (strcmp(div, "delhi") == 0 and strcmp(des, "chennai") == 0 and t == 1)
        divi = 22;

    else if (strcmp(div, "delhi") == 0 and strcmp(des, "chennai") == 0 and t == 2)
        divi = 23;
        return divi;
}

void show_available_seats()
{
    ifstream read("buses.txt", ios::in);
    string temp;

    Buses b = get_data(read);
    while (!read.eof())
    {
        if (divi == b.i1)
        {
            temp = b.seats;
            break;
        }
        b = get_data(read);
    }

    cout << "\n\t\t\t\t\t\t\tseat  availablity\n";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << "\t\t\t\t\t\t\t" << i + 1 << "      " << temp[i] << endl;
    }
    cout<<"\n\t\t\t\t\t\t\t1-Seat already occupied.\t0-Seat is vacant."<<endl;
}

class Reservation
{
private:
    char div[MAX];
    char destination[MAX];
    int t;
    int n_seats;
    int age;
    char fname[MAX];
    char lname[MAX];
    long long int number;
    char aadhar[MAX];
    int seats[MAX];
    int fare;

public:
    long long int getnumber()
    {
        return number;
    }
    friend void store_data();

    void reservation();
    void update();
    void display();
    void cancellation();
    void updat()
    {
        int ch, b;
        while (1)
        {
            cout << "\n\t\t\t\t\t\t\tWhat info you want to change?\n\n\t\t\t\t\t\t\t1.Name.\n\n\t\t\t\t\t\t\t2.Time of journey.\n\n\t\t\t\t\t\t\t3.The seats reserved.\n\n\t\t\t\t\t\t\t4.Age.\n\n\t\t\t\t\t\t\t5.Go Back.\n\n";
            cout << "\t\t\t\t\t\t\tEnter your choice ::";
            cin >> ch;
            if (ch == 1)
            {
                cout << "\n\t\t\t\t\t\t\tPrevious name entered was ::" << fname << " " << lname;
                cout << "\n\t\t\t\t\t\t\tRe-enter first name             :";
                cin >> fname;
                fname[0]=toupper(fname[0]);
                cout << "\n\t\t\t\t\t\t\tRe-enter last name             :";
                cin >> lname;
                lname[0]=toupper(lname[0]);
                cout << "\n\t\t\t\t\t\t\tName changed successfully!!!";
            }
            else if (ch == 2)
            {
                cout << "\n\t\t\t\t\t\t\tPrevious Time slot was :" << t;
                cout << "\n\t\t\t\t\t\t\tReEnter your time slot of journey\n\t\t\t\t\t\t\t1.8 : 00 AM\n\t\t\t\t\t\t\t2.9 : 00 PM ";
                cout << "\n\t\t\t\t\t\t\tEnter your choice : ";
                cin >> b;
                if (t == b)
                {
                    cout << "\n\t\t\t\t\t\t\tAlready the same time you have selected..." << endl;
                }
                else
                {
                    t = b;
                    cout << "\n\t\t\t\t\t\t\tTime of journey has been changed successfully!!!";
                }
            }
            else if (ch == 3)
            {
                cout << "\t\t\t\t\t\t\tThe number  of seats you reserved were : " << n_seats;
                cout << " and the seats are : ";
                for (int i = 0; i < n_seats; i++)
                    cout << seats[i] << " ";

                int op,x;
                while (1)
                {
                    cout << "\n\n\t\t\t\t\t\t\t 1.Add seat\n\n\t\t\t\t\t\t\t 2.Delete a seat\n\n\t\t\t\t\t\t\t 3.Go Back"<<endl;
                    cout<<"\n\t\t\t\t\t\t\tSelect your option : ";
                    cin >> op;
                    if (op == 1)
                    {
                        n_seats++;
                        show_available_seats();
                        cout << "\n\t\t\t\t\t\t\tSelect your seat : ";
                        int seat;
                        cin >> seat;
                        seats[n_seats - 1] = seat;
                         x= find_index(div, destination, t);
                        fare=(n_seats)*arr[x].first;
                        ifstream read("buses.txt", ios::in);
                        update_buses(seats, n_seats, read,1);
                        read.close();
                    }
                    else if (op == 2)
                    {
                        cout<<"\n\t\t\t\t\t\t\tYour selected seats are : ";
                        for (int i = 0; i < n_seats; i++)
                        {
                            cout<<seats[i]<<" ";
                        }
                        int num;
                        cout<<"\n\t\t\t\t\t\t\tEnter the  seat number you want to cancel : ";
                        cin>>num;
                         x= find_index(div, destination, t);
                        fare=arr[x].first*(n_seats-1);
                        int i;
                        for (i = 0; i < n_seats; i++)
                            if (seats[i] == num)
                                break;
                        if (i < n_seats)
                        {
                           
                            n_seats--;
                            for (int j = i; j < n_seats; j++)
                                seats[j] = seats[j + 1];
                        }
                        int deleted_seat[1]={num};
                        ifstream read("buses.txt", ios::in);
                        update_buses(deleted_seat,1,read,0);
                        read.close();
                    }
                    else if (op == 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\t\tPlease Enter a valid input\n";
                    }
                }
            }
            else if (ch == 4)
            {
                cout << "\n\t\t\t\t\t\t\tAge entered before was : "<<age<<endl;
                cout << "\n\t\t\t\t\t\t\t        Enter new age :: ";
                cin >> age;
                cout << "\n\t\t\t\t\t\t\tAge changed successfully!!!";
            }
            else
            {
                break;
            }
        }
    }
    
    void show_data()
    {   cout<<"\n\t\t\t\t\t\t\tBooking Date and Time : "<<date<<endl;
        cout << "\n\t\t\t\t\t\t\tDIV            : " << div<<endl;
        cout << "\n\t\t\t\t\t\t\tDestination    : " << destination<<endl;
        if (t == 1)
        {
            cout << "\n\t\t\t\t\t\t\tTime slot      : "
                 << "8:00 AM"<<endl;
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\tTime slot  : "
                 << " 9:00 PM"<<endl;
        }
        cout << "\n\t\t\t\t\t\t\tSeats          : " << n_seats;
        cout << "\n\t\t\t\t\t\t\tThe seats are  : ";
        for (int i = 0; i < n_seats; i++)
        {
            cout << seats[i] << " ";
        }
        cout << "\n\t\t\t\t\t\t\tFirst Name     : " << fname<<endl;
        cout << "\n\t\t\t\t\t\t\tLast Name      : " << lname<<endl;
        cout << "\n\t\t\t\t\t\t\tAge            : " << age<<endl;
        cout << "\n\t\t\t\t\t\t\tPhone number   : " << number<<endl;
        cout << "\n\t\t\t\t\t\t\tAadhar number  : " << aadhar;
        cout<<  "\n\n\t\t\t\t\t\t\tYour journey fare is : Rs."<<fare;
        cout << endl;
    }
} r;

void Reservation::reservation()
{

    cout << "\t\t\t\t\t\t\tThere are 4 divisions available\n"
         << endl;
    cout << "\t\t\t\t\t\t\t* PUNE\n\t\t\t\t\t\t\t* MUMBAI\n\t\t\t\t\t\t\t* DELHI\n\t\t\t\t\t\t\t* CHENNAI\n\t\t\t\t\t\t\t\n";
    cout << "\n\t\t\t\t\t\t\tEnter your Division(starting point) : ";
    cin >> div;
    for (int i = 0; i < strlen(div); i++)
    {
        div[i] = tolower(div[i]);
    }
    if (!strcmp(div, "pune"))
    {
        cout << "\t\t\t\t\t\t\tThere are 3 destinations available\n";
        cout << "\t\t\t\t\t\t\t* MUMBAI\n\t\t\t\t\t\t\t* DELHI\n\t\t\t\t\t\t\t* CHENNAI\n\t\t\t\t\t\t\t\n";
        cout << "\n\t\t\t\t\t\t\tEnter where you want to go---->";
        cin >> destination;
        for (int i = 0; i < strlen(destination); i++)
        {
            destination[i] = tolower(destination[i]);
        }
    }
    else if (!strcmp(div, "mumbai"))
    {
        cout << "\t\t\t\t\t\t\tThere are 3 destinations available\n";
        cout << "\t\t\t\t\t\t\t* PUNE\n\t\t\t\t\t\t\t* DELHI\n\t\t\t\t\t\t\t* CHENNAI";
        cout << "\n\t\t\t\t\t\t\tEnter where you want to go---->";
        cin >> destination;
    }
    else if (!strcmp(div, "delhi"))
    {
        cout << "\t\t\t\t\t\t\tThere are 3 destinations available\n";
        cout << "\t\t\t\t\t\t\t* PUNE\t\t\t\t\t\t\t* MUMBAI\n\t\t\t\t\t\t\t* CHENNAI";
        cout << "\n\t\t\t\t\t\t\tEnter where you want to go----> ";
        cin >> destination;
    }
    else if (!strcmp(div, "chennai"))
    {
        cout << "\t\t\t\t\t\t\tThere are 3 destinations available\n";
        cout << "\t\t\t\t\t\t\t* PUNE\n\t\t\t\t\t\t\t* MUMBAI\n\t\t\t\t\t\t\t* DELHI";
        cout << "\n\t\t\t\t\t\t\tEnter where you want to go----> ";
        cin >> destination;
    }

    cout << "\t\t\t\t\t\t\tSelect from the below timings\n";
    cout << "\t\t\t\t\t\t\t1.8:00 AM";
    cout << "\n\t\t\t\t\t\t\t2.9:00 PM";
    cout << "\n\t\t\t\t\t\t\tEnter your choice :";
    cin >> t;

   int x= find_index(div, destination, t);
    cout << "\n\t\t\t\t\t\t\t*SEATS BOOKING*\n";
    cout << "\n\t\t\t\t\t\t\tThe available seats are: ";
    show_available_seats();

    cout << "\n\t\t\t\t\t\t\tHow many seats you want to reserve : ";
    cin >> n_seats;
     fare=(arr[x].first)*n_seats;
    cout << "\n\t\t\t\t\t\t\tSelect your seats\n";
    for (int i = 0; i < n_seats; i++)
    {
        int seat;
        cout << "\t\t\t\t\t\t\tSelect seat " << i + 1 << " : ";
        cin >> seat;
        seats[i] = seat;
    }
    ifstream read("buses.txt", ios::in);
    update_buses(seats, n_seats, read, 1);
    read.close();

    cout << "\n\t\t\t\t\t\t\tEnter your first name : ";
    cin >> fname;
    fname[0] = toupper(fname[0]);

    cout << "\t\t\t\t\t\t\tEnter your last name : ";
    cin >> lname;
    lname[0] = toupper(lname[0]);

    cout << "\t\t\t\t\t\t\tEnter your age : ";
    cin >> age;

    int valid = 1;
    do
    {
        valid = 1;
        cout << "\t\t\t\t\t\t\tEnter your number : ";
        cin >> number;

        string temp = to_string(number);
        if (temp.size() != 10)
        {
            valid = 0;
            cout << "\n\t\t\t\t\t\t\tPlease enter a valid phone number" << endl;
        }
        else
        {
            for (int i = 0; i < 10; i++)
                if (isalpha(temp[i]))
                    valid = 0;
        }

    } while (!valid);

    cout << "\t\t\t\t\t\t\tEnter your Aadhar Number : ";
    cin >> aadhar;

    time_t t;   
    time(&t);
    date=ctime(&t);

    return;
}

void Reservation::update()
{
    cout << "\n\t\t\t\t\t\t\t*UPDATE WINDOW OPENED*\n";
    long long int no;
    bool flag = false;
    int ch, c = 1, b;
    cout << "\n\t\t\t\t\t\t\tEnter contact number of passenger whose deatails are to be changed :";
    cin >> no;
    fstream f("user_info.dat", ios::in | ios::out | ios::binary);
    while (f.read((char *)&r, sizeof(r)))
    {
        if (flag)
            break;
        if (r.getnumber() == no)
        {
            r.updat();
            f.seekp(-sizeof(r), ios::cur);
            f.write((char *)&r, sizeof(r));
            flag = true;
        }
    }
    if (!flag)
    {
        cout << "\n\t\t\t\t\t\t\tNo passenger has such contact number....";
    }
    f.close();
}

void Reservation::display()
{
    // Reservation r;
    long long int no;
    bool flag = false;
    cout << "\n\t\t\t\t\t\t\tEnter contact number to fetch details :";
    cin >> no;
    ifstream f("user_info.dat", ios::binary);
    while (f.read((char *)&r, sizeof(r)))
    {
        // cout<<r.getnumber();
        if (r.getnumber() == no)
        {
            r.show_data();
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "\t\t\t\t\t\t\tNo passenger available with this contact number\n";
    }
    f.close();
}

void Reservation::cancellation()
{
    long long int no;
    bool flag = false;
    cout << "\t\t\t\t\t\t\tEnter your phone number : ";
    cin >> no;
    ifstream fin("user_info.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);
    while (fin.read((char *)&r, sizeof(r)))
    {
        if (r.getnumber() != no)
            fout.write((char *)&r, sizeof(r));
        else{
            flag = true;
            cout<<"\n\t\t\t\t\t\t\tAmount of Rs."<<r.fare<<" has been successfully refunded to your bank account."<<endl;
        }
    }
    fin.close();
    fout.close();
    if (!flag)
    {
        cout << "\t\t\t\t\t\t\tNo passenger available with this contact number\n";
    }
    else
    {
        remove("user_info.dat");
        rename("temp.dat", "user_info.dat");
        cout << "\n\t\t\t\t\t\t\tData deleted successfully!!!";
        cout<<endl;
    }
}

void store_data()
{
    fstream f("user_info.dat", ios::in | ios::out | ios::app | ios::binary);
    f.write((char *)&r, sizeof(r));

    f.close();
}

int main()
{
    ofstream write("buses.txt", ios::in | ios::app | ios::out);
    store_data_buses(write);
    write.close();
    
    while (1)
    {

        cout<<endl;
        cout<<"\t\t\t\t\t\t\t  -------WELCOME TO BUS RESERVATION SYSTEM--------\n";
        cout << "\n\t\t\t\t\t\t\t====================================================================\n";
        cout << "\n                      \t\t\t\t\t\t\t       RESERVATION SYSTEM\n";
        cout << "\n\t\t\t\t\t\t\t=====================================================================\n";
        cout << "\n\t\t\t\t\t\t\t1. Make a Reservation\n";
        cout << "\n\t\t\t\t\t\t\t2. Update your Reservation\n";
        cout << "\n\t\t\t\t\t\t\t3. Display your Info\n";
        cout << "\n\t\t\t\t\t\t\t4. Cancel your Reservation\n";
        cout << "\n\t\t\t\t\t\t\t5. Exit\n";
        cout << "\t\t\t\t\t\t\t=======================================================================\n";
        cout << "\n\t\t\t\t\t\t\tEnter your choice:";

        int ch;
        cin >> ch;
        cout << endl;
        switch (ch)
        {

        case 1:
            r.reservation();
            store_data();
            break;
            cout << "\t\t\t\t\t\t\t=======================================================================\n";
        case 2:
            r.update();
            break;
            cout << "\t\t\t\t\t\t\t=======================================================================\n";
        case 3:
            r.display();
            break;
            cout << "\t\t\t\t\t\t\t=======================================================================\n";
        case 4:
            r.cancellation();
            break;
            cout << "\t\t\t\t\t\t\t=======================================================================\n";
        case 5:
           cout<<"\t\t\t\t\t\t\t THANK YOU FOR USING OUR RESERVATION SYSTEM"<<endl;
            return 0;
        default:
            cout << "\t\t\t\t\t\t\tInvalid Choice.Please Enter a Valid Choice!!!";
            break;
            cout << "\t\t\t\t\t\t\t=======================================================================\n";
        }
    }
    return 0;
}
