#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// Global Variables
const int maxstudents = 100;
string name[maxstudents];
int matric_marks[maxstudents], fsc_marks[maxstudents], ecat_marks[maxstudents], rollno[maxstudents], aggregate[maxstudents];
int studentcount = 0;

const int MAX_USERS = 100;
string userNames[MAX_USERS], userPasswords[MAX_USERS];
string adminNames[MAX_USERS], adminPasswords[MAX_USERS];

int userIndex = 0;
int adminIndex = 0;
// Function Declarations
void admin();
void user();
void logout();
void studentrecord();
void viewrecord();
void updaterecord();
void deleterecord();
void aggregatecalculator();
void eligibility();
void viewallrecords();      
void vieweligibilitylist();  
void displaymenuforadmin();
void displaymenuforuser();
int adminmenu();
int usermenu();
void Header(); 
void addstd();
void viewstd();
void delstd();
void updatestd();
void aggregatestd();
void eligibilitystd();
void readdata();
string getfield(string record, int field);

void readAdminData();
void adminSignIn();
void readUserData();
void userSignIn();
void userSignUp();
void writeUserData();
string getCredentials(string record, int field);

int main()
{
    system("color 80");
    Header();
    readdata();
    int select;
    cout << "1--> Admin\n";
    cout << "2--> User\n";
    cout << "Choose option from 1 to 2 " << endl;
    cout << "Enter your option = ";
    cin >> select;
    if (select == 1)
    {
        adminSignIn();
    }
    else if (select == 2)
    {
        user();
    }

    return 0;
}

void viewallrecords()
{
    system("cls");
    viewstd();
    for (int i = 0; i < studentcount; i++)
    {
        cout << "---------------------------------------------\n";
        cout << "Roll No: " << rollno[i] << endl;
        cout << "Name: " << name[i] << endl;
        cout << "Matric Marks: " << matric_marks[i] << endl;
        cout << "FSC Marks: " << fsc_marks[i] << endl;
        cout << "Ecat Marks: " << ecat_marks[i] << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    displaymenuforadmin();
}

void vieweligibilitylist()
{
    system("cls");
    eligibilitystd();
    cout << "Eligibility List:\n";
    for (int i = 0; i < studentcount; i++)
    {
        cout << "---------------------------------------------\n";
        cout << "Roll No: " << rollno[i] << endl;
        cout << "Name: " << name[i] << endl;
        cout << "Aggregate: " << aggregate[i] << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    displaymenuforuser();
}

void user()
{
    system("cls");
    Header();
	  int select;
    cout << "1--> Sign In\n";
    cout << "2--> SIgn Up\n";
    cout << "Choose option from 1 to 2 " << endl;
    cout << "Enter your option = ";
    cin >> select;
     if (select == 1)
    {
        userSignIn();
    }
    else if (select == 2)
    {
        userSignUp();
    }
}

void logout()
{
    system("cls");
    Header();
    int select;
    cout << "1--> Admin\n";
    cout << "2--> User\n";
    cout << "Choose option from 1 to 2 " << endl;
    cout << "Enter your option = ";
    cin >> select;
    if (select == 1)
    {
        adminSignIn();
    }
    else if (select == 2)
    {
        user();
    }
}

void Header()
{
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^                          University Admission Management System (UAMS)                               ^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
}

void addstd()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                        ---- Add Student Record ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void viewstd()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                        ---- View Student Record ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void delstd()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                        ---- Delete Student Record ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void updatestd()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                        ---- Update Student Record ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void aggregatestd()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                             ---- Aggregate ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void eligibilitystd()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                            ---- Eligibility ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

int adminmenu()
{
    system("cls");
    int choice;
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                            ---- Admin Menu----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
    cout << "1--> Add Student \n";
    cout << "2--> Update Record of a student \n";
    cout << "3--> Delete Record of a student \n";
    cout << "4--> Logout \n";
    cout << "5--> All records \n";
    cout << "6--> Exit \n";
    cout << "_________________________________________________________________________________________________________\n";
    cout << "Choose option from 1 to 5 " << endl;
    cout << "Enter your option = ";
    cin >> choice;
    return choice;
}

void displaymenuforadmin()
{
    int a;
    system("cls");
    a = adminmenu();

    if (a == 1)
    {
        studentrecord();
    }
    else if (a == 2)
    {
        updaterecord();
    }
    else if (a == 3)
    {
        deleterecord();
    }
    else if (a == 4)
    {
        logout();
    }
    else if (a == 5)
    {
        viewallrecords();
    }
    else if (a == 6)
    {
        exit(0);
    }
   
    else
    {
        cout << "Invalid option\n";
    }
}

int usermenu()
{
    system("cls");
    int choice;
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                            ---- User Menu----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
    cout << "1--> View Record of a student \n";
    cout << "2--> Calculate Aggregate \n";
    cout << "3--> Eligibility for Admission \n";
    cout << "4--> Logout \n";
    cout << "5--> Eligibility list \n";
    cout << "6--> Exit \n";
    cout << "_________________________________________________________________________________________________________\n";
    cout << "Choose option from 1 to 5 " << endl;
    cout << "Enter your option = ";
    cin >> choice;
    return choice;
}

void displaymenuforuser()
{
    int a;
    system("cls");
    a = usermenu();

    if (a == 1)
    {
        viewrecord();
    }
    else if (a == 2)
    {
        aggregatecalculator();
    }
    else if (a == 3)
    {
        eligibility();
    }
    else if (a == 4)
    {
        logout();
    }
    else if (a == 5)
    {
        vieweligibilitylist();
    }
    else if (a == 6)
    {
        exit(0);
    }
    else
    {
        cout << "Invalid option\n";
    }
}

void studentrecord()
{
    system("cls");
    addstd();
    cin.ignore();
    cout << "name of the student = ";
    getline(cin, name[studentcount]);
    cout << "roll no of the student = ";
    cin >> rollno[studentcount];
    cout << "Matric marks of the student = ";
    cin >> matric_marks[studentcount];
    cout << "fsc marks of the student = ";
    cin >> fsc_marks[studentcount];
    cout << "Ecat marks of the student = ";
    cin >> ecat_marks[studentcount];
    studentcount++;

    // Append data to file
    fstream data("uams.txt", ios::app);
    data << name[studentcount - 1] << ',' << rollno[studentcount - 1] << ',' << matric_marks[studentcount - 1] << ',' << fsc_marks[studentcount - 1] << ',' << ecat_marks[studentcount - 1] << endl;
    data.close();

    // Read and display data
    readdata();
    displaymenuforadmin();
}


void viewrecord()
{
    system("cls");
    viewstd();
    int rollNumber;
    bool recordFound = false;
    cout << "Enter the roll number from the existing dataset: ";
    cin >> rollNumber;
    for (int i = 0; i < studentcount; i++)
    {
        if (rollNumber == rollno[i])
        {
            cout << "Name of the student: " << name[i] << endl;
            cout << "Matric marks of the student: " << matric_marks[i] << endl;
            cout << "FSC marks of the student: " << fsc_marks[i] << endl;
            cout << "Ecat marks of the student: " << ecat_marks[i] << endl;
            recordFound = true;
            break;
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered roll number." << endl;
    }
    getch();    // Wait for a key press before returning to the menu
    displaymenuforuser();
}


void updaterecord()
{
    system("cls");
    updatestd();
    int rollNumber;
    cout << "Enter the roll number = ";
    cin >> rollNumber;
    bool recordfound = false;
    for (int i = 0; i < studentcount; i++)
    {
        if (rollNumber == rollno[i])
        {
            cin.ignore();
            cout << "name of the student = ";
            getline(cin, name[i]);

            cout << "Matric marks of the student = ";
            cin >> matric_marks[i];
            cout << "fsc marks of the student = ";
            cin >> fsc_marks[i];
            cout << "Ecat marks of the student = ";
            cin >> ecat_marks[i];
            recordfound = true;

            // Update data in the file
            fstream data("uams.txt", ios::out);
            for (int j = 0; j < studentcount; j++)
            {
                data << name[j] << ',' << rollno[j] << ',' << matric_marks[j] << ',' << fsc_marks[j] << ',' << ecat_marks[j] << endl;
            }
            data.close();
        }
    }
    if (!recordfound)
    {
        cout << "No record found for the entered roll number." << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    displaymenuforadmin();
}


void deleterecord()
{
    system("cls");
    delstd();
    int rollNumber;
    cout << "Enter the roll number = ";
    cin >> rollNumber;
    bool recordFound = false;
    for (int i = 0; i < studentcount; i++)
    {
        if (rollNumber == rollno[i])
        {
            recordFound = true;

            // Shift data in the arrays to overwrite the deleted record
            for (int j = i; j < studentcount - 1; j++)
            {
                name[j] = name[j + 1];
                matric_marks[j] = matric_marks[j + 1];
                fsc_marks[j] = fsc_marks[j + 1];
                ecat_marks[j] = ecat_marks[j + 1];
                rollno[j] = rollno[j + 1];
            }

            // Decrement student count after deletion
            studentcount--;

            // Update data in the file
            fstream data("uams.txt", ios::out);
            for (int j = 0; j < studentcount; j++)
            {
                data << name[j] << ',' << rollno[j] << ',' << matric_marks[j] << ',' << fsc_marks[j] << ',' << ecat_marks[j] << endl;
            }
            data.close();

            cout << "Record Deleted successfully!" << endl;
            break;
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered roll number." << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    displaymenuforadmin();
}

void aggregatecalculator()
{
    system("cls");
    aggregatestd();
    int rollNumber;
    bool recordFound = false;
    cout << "Enter the roll number = ";
    cin >> rollNumber;
    for (int i = 0; i < studentcount; i++)
    {
        if (rollNumber == rollno[i])
        {
            aggregate[i] = (25 * matric_marks[i] / 1100) + (45 * fsc_marks[i] / 1100) + (30 * ecat_marks[i] / 400);
            cout << "Aggregate of Roll No " << i + 1 << " is " << aggregate[i];
            recordFound = true;
            break;
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered roll number." << endl;
    }
    getch();    // Wait for a key press before returning to the menu
    displaymenuforuser();
}

void eligibility()
{
    system("cls");
    eligibilitystd();
    int rollNumber;
    cout << "Enter the roll number = ";
    cin >> rollNumber;
	bool recordfound=false;
    for (int i = 0; i < studentcount; i++)
    {
        if (rollNumber == rollno[i])
        {
            if (aggregate[i] > 80)
            {
                cout << "Congratulations! You are eligible for admission in Computer Science!" << endl;
            }
            else if (aggregate[i] > 70 && aggregate[i] <= 80)
            {
                cout << "Congratulations! You are eligible for admission in Mechanical Engineering!" << endl;
            }
            else if (aggregate[i] > 60 && aggregate[i] <= 70)
            {
                cout << "Congratulations! You are eligible for admission in Chemical Engineering!" << endl;
            }
            else if (aggregate[i] > 50 && aggregate[i] <= 60)
            {
                cout << "Congratulations! You are eligible for admission in Electrical Engineering!" << endl;
            }
            else
            {
                cout << "Sorry, you are not eligible for admission in any of the Programs." << endl;
            }
            recordfound=true;
        }
    }
    if (!recordfound)
    {
        cout << "No record found for the entered roll number." << endl;
    }
    getch();    // Wait for a key press before returning to the menu
    displaymenuforuser();
}

string getfield(string record, int field) {
    string item;
    int comma = 1;
    for (int x = 0; x < record.length(); x++) {
    	 if (record[x] == ',') {
            comma = comma + 1;
        }
        else if (comma == field) {
            item = item + record[x];
        }
       
    }
    return item;
}

void readdata()
{
    string record;
    fstream data("uams.txt", ios::in);
    studentcount = 0; // Reset student count before reading data
    while (getline(data, record))
    {
        name[studentcount] = getfield(record, 1);
        rollno[studentcount] = stoi(getfield(record, 2));
        matric_marks[studentcount] = stoi(getfield(record, 3));
        fsc_marks[studentcount] = stoi(getfield(record, 4));
        ecat_marks[studentcount] = stoi(getfield(record, 5));
        studentcount++;
    }
    data.close();
}

string getCredentials(string record, int field) {
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++) {
        if (record[x] == ',') {
            commaCount = commaCount + 1;
        } else if (commaCount == field) {
            item = item + record[x];
        }
    }
    return item;
}

void readUserData() {
    string record;
    fstream userData;
    userData.open("userCredentials.txt", ios::in);
    while (getline(userData, record)) {
        userNames[userIndex] = getCredentials(record, 1);
        userPasswords[userIndex] = getCredentials(record, 2);
        userIndex = userIndex + 1;
    }
}

void readAdminData() {
    string record;
    fstream adminData;
    adminData.open("adminCredentials.txt", ios::in);
    while (getline(adminData, record)) {
        adminNames[adminIndex] = getCredentials(record, 1);
        adminPasswords[adminIndex] = getCredentials(record, 2);
        adminIndex = adminIndex + 1;
    }
    adminData.close();
}


void writeUserData() {
    ofstream userData;
    userData.open("userCredentials.txt", ios::app);
    userData << userNames[userIndex] << "," << userPasswords[userIndex] << ","<<endl;;
    userData.close();
}

void userSignUp() {
	system("cls");
	Header();
    string name, password;
  	cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Password: ";
    getline(cin, password);

    userNames[userIndex] = name;
    userPasswords[userIndex] = password;

    writeUserData();
	user();
    cout << "User Sign-up successful!" << endl;
}

void adminSignIn() {
	
    readAdminData();
    string name, password;

    cin.ignore(); 
	while(true){
	system("cls");
	Header();
    cout << "Enter Admin Name: ";
    getline(cin, name);

    cout << "Enter Admin Password: ";
    getline(cin, password);

    bool isAdminFound = false;

    for (int x = 0; x < adminIndex; x++) {
      
        if (name == adminNames[x] && password == adminPasswords[x]) {
        	 cout << "Sign-in successful!" << endl;
        	displaymenuforadmin();
           
            isAdminFound = true;
            
        }
    }
    if (!isAdminFound) {
        cout << "Sign-in unsuccessful!" << endl;
        cout<<"Press any key to try again!";
        getch();
    }
}
}


void userSignIn() {
	
    readUserData();
    cin.ignore();
    string name, password;
	while(true){
	system("cls");
	Header();
    cout << "Enter User Name: ";
    getline(cin, name);
    cout << "Enter User Password: ";
    getline(cin, password);

    bool isUserFound = false;

    for (int x = 0; x < userIndex; x++) {
        if (name == userNames[x] && password == userPasswords[x]) {
        	displaymenuforuser();
            cout << "Sign-in successful!" << endl;
            isUserFound = true;
            break;
        }
    }

    if (!isUserFound) {
        cout << "Sign-in unsuccessful!" << endl;
        cout<<"Press any key to try again!";
        getch();
    }
}
}

