#include <iostream>
#include <fstream>
using namespace std;

void Main_Menu();
    void Admin_Login();
        void Admin_Menu();
            void Check_Visitor_History();
            void Edit_Entry_Exit_Details();
            void Black_List_Customer();
            void Check_Parking_Availability();
    void Visitor_Login();
        bool Verify_Credentials(const string &filename, const string &id, const string &password);
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
        Admin_Login();
        break;
    case 2:
        Visitor_Login();
        break;
    case 0:
        cout << "Exiting the program..." << endl;
        exit(0);
    default:
        cout << "Invalid choice! Please TRY AGAIN" << endl;
    }

    } while(true);
    
}

void Admin_Login()
{
    cout << "\nADMIN LOGIN\n";
    string Admin_ID, Password;
    // Admin_ID = admin, Password = password
    cout << "Enter Admin ID: ";
    cin >> Admin_ID;
    cout << "Enter Password: ";
    cin >> Password;

    if (Admin_ID == "admin" && Password == "password"){
        Admin_Menu();
    }
    else
    {
        cout << "Invalid ID/Password, Try Again\n";
        Admin_Login();
    }
}

void Admin_Menu(){
    int choice;
    do {
        cout << "\nAdmin Menu\n";
        cout << "1. Check visitor history\n";
        cout << "2. Edit entry/exit details\n";
        cout << "3. Blacklist or remove a customer\n";
        cout << "4. Check parking lot availability\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Check_Visitor_History();
                break;
            case 2:
                // Edit_Entry_Exit_Details();
                break;
            case 3:
                // Black_List_Customer();
                break;
            case 4:
                // Check_Parking_Availability();
                break;
            case 5:
                Main_Menu();
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (true);
}

void Visitor_Login()
{
    string visitorID, password;
    cout << "Enter Visitor ID: ";
    cin >> visitorID;
    cout << "Enter Password: ";
    cin >> password;

    if (Verify_Credentials("visitor_data.txt", visitorID, password)) 
    {
        // Visitor_Menu();
    } else {
        cout << "Incorrect ID or Password.\n";
        char choice;
        cout << "Do you want to create a new visitor account? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            // createVisitorAccount();
        } else {
            Main_Menu();
        }
    }
}

bool Verify_Credentials(const string &filename, const string &id, const string &password) {}