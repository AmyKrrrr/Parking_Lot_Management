#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void Main_Menu();
    void Admin_Login();
        void Admin_Menu();
            void Check_Visitor_History();
            void Edit_Entry_Exit_Details();
            void Black_List_Customer();
            void Check_Parking_Availability(const string& filename);
    void Visitor_Login();
        bool Verify_Credentials(const string &filename, const string &id, const string &password);
        void Create_Visitor_Account();
        void Save_Data_To_File(const string &filename, const vector<string> &data);
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
    cout << "---------------------------------\n";
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
    cout << "---------------------------------\n";
    cout << "ADMIN LOGIN\n";
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
        cout << "---------------------------------\n";
        cout << "Admin Menu\n";
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
                Check_Parking_Availability("Parking_status.txt");
                break;
            case 5:
                Main_Menu();
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (true);
}

void Check_Parking_Availability(const string& filename){
    cout << "---------------------------------";
    ifstream file(filename);
    if (!file) {
        cerr << "\nError: Unable to open the file." << endl;
        return;
    }

    string line;
    cout << "\nParking Lot Availability:" << endl;
    // cout << "---------------------------------" << endl;

    while (getline(file, line)) {
        stringstream ss(line);
        string lot;
        int status;

        ss >> lot >> status;

        if (status == 0) {
            cout << lot << " is available." << endl;
        } else {
            cout << lot << " is occupied by visitor ID: " << status << endl;
        }
    }
    file.close();
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
        Visitor_Menu();
    } else {
        cout << "Incorrect ID or Password.\n";
        char choice;
        cout << "Do you want to create a new visitor account? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            Create_Visitor_Account();
        } else {
            Main_Menu();
        }
    }
}

bool Verify_Credentials(const string &filename, const string &id, const string &password){
        ifstream file(filename);
    string fileID, filePassword;

    while (file >> fileID >> filePassword) {
        if (fileID == id && filePassword == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void Create_Visitor_Account(){
    string visitorID, password;
    cout << "Enter new Visitor ID: ";
    cin >> visitorID;
    cout << "Enter new Password: ";
    cin >> password;

    vector<string> newVisitor = {visitorID, password};
    Save_Data_To_File("visitor_data.txt", newVisitor);
    cout << "Visitor account created successfully.\n";
    Main_Menu();
}

void Save_Data_To_File(const string &filename, const vector<string> &data){
    ofstream file(filename, ios::app);
    for (const string &d : data) {
        file << d << " ";
    }
    file << endl;
    file.close();
}

void Visitor_Menu(){
    int choice;
        do {
            cout << "\nVisitor Menu\n";
            cout << "1. Check empty parking lots\n";
            cout << "2. Book a parking lot\n";
            cout << "3. Input entry/exit time\n";
            cout << "4. Check past visits\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    // Check_Empty_Parking_Lots();
                    break;
                case 2:
                    // Book_Parking_Lot();
                    break;
                case 3:
                    // Input_Entry_Exit_Time();
                    break;
                case 4:
                    // Check_Past_Visits();
                    break;
                case 5:
                    Main_Menu();
                    return;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (true);
}