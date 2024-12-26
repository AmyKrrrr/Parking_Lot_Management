#include <iostream>
using namespace std;

void Main_Menu();
void Admin_Login();
    void Admin_Menu();
        void Check_Visitor_History();
        void Edit_Entry_Exit_Details();
        void Black_List_Customer();
        void Edit_Parking_Availability();
void Visitor_Login();
void createVisitorAccount();
    void Visitor_Menu();
        void Check_Empty_Parking_Lots();
        void Book_Parking_Lot();
        void Input_Entry_Exit_Time();
        void Check_Past_Visits();

int main()
{
    Main_Menu();
    return 0;
}

void Main_Menu()
{
    int option;
    do
    {
    cout << "PARKING LOT MANAGEMENT" << endl;
    cout << "Login as:" << endl
         << "1. Admin" << endl
         << "2. Visitor" << endl
         << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
        // Admin_Login();
        break;
    case 2:
        // Visitor_Login();
        break;
    case 0:
        cout << "Exiting the program..." << endl;
        exit(0);
    default:
        cout << "Invalid choice! Please TRY AGAIN" << endl;
    }

    } while(true);
    
}