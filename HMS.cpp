#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// Global Variables
const int max_patients = 100;
const int max_doctors = 100;
string patient_name[max_patients];
int patient_age[max_patients], patient_id[max_patients], patient_roomno[max_patients], patient_status[max_patients];
int patientcount = 0;
string doctor_name[max_doctors];
int doctor_age[max_doctors], doctor_id[max_doctors], doctor_roomno[max_doctors];
int doctorcount = 0;

const int MAX = 100;
string docNames[MAX], docPasswords[MAX];
string adminNames[MAX], adminPasswords[MAX];

int docIndex = 0;
int adminIndex = 0;

void readAdminData();
void adminSignIn();
void readdocData();
void docSignIn();
void docSignUp();
void writedocData();
string getCredentials(string record, int field);

// Function declarations
void admin();
void doctor();
void logout();
void header();
void add_patient();
void view_patient();
void discharge_patient_menu();
void update_patient();
void view_all_patients_menu();
int admin_menu();
void display_menu_for_admin();
void admit_patient();
void discharge_patient();
void view_patient_details();
void update_patient_details();
void view_all_patients();
string get_field(string record, int field);
void read_patient_data();
void add_doctor_header();
void view_doctor_header();
void update_doctor_header();
void remove_doctor_header();
void view_all_doctors_header();
void add_doctor();
void view_doctor_details();
void update_doctor_details();
void remove_doctor();
void view_all_doctors();
void read_doctor_data();
void display_menu_for_doctor();



int main()
{
    system("color 80");
    header();
    read_doctor_data();
    read_patient_data();
    
    int select;
    cout << "1--> Admin\n";
    cout << "2--> Doctor\n";
    cout << "Choose option from 1 to 2 " << endl;
    cout << "Enter your option = ";
    cin >> select;
    if (select == 1)
    {
        adminSignIn();
    }
    else if (select == 2)
    {
        doctor(); 
    }

    return 0;
}

void doctor()
{
    system("cls");
    header();
	  int select;
    cout << "1--> Sign In\n";
    cout << "2--> SIgn Up\n";
    cout << "Choose option from 1 to 2 " << endl;
    cout << "Enter your option = ";
    cin >> select;
     if (select == 1)
    {
        docSignIn();
    }
    else if (select == 2)
    {
        docSignUp();
    }
}

void logout()
{
    system("cls");
    header();
    int select;
    cout << "1--> Admin\n";
    cout << "2--> Doctor\n";
    cout << "Choose option from 1 to 2 " << endl;
    cout << "Enter your option = ";
    cin >> select;
    if (select == 1)
    {
        adminSignIn();
    }
    else if (select == 2)
    {
        doctor();
    }
}

void header()
{
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^                              Hospital Management System (HMS)                                     ^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
}

void add_patient()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                  ---- Admit Patient ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void view_patient()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                             ---- View Patient Details ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void discharge_patient_menu()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                             ---- Discharge Patient ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void update_patient()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                           ---- Update Patient Details ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void view_all_patients_menu()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                         ---- View All Patients ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

int admin_menu()
{
    system("cls");
    int choice;
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                             ---- Admin Menu ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
    cout << "1--> Admit Patient \n";
    cout << "2--> Discharge Patient \n";
    cout << "3--> View Patient Details \n";
    cout << "4--> Update Patient Details \n";
    cout << "5--> View All Patients \n";
    cout << "6--> Logout \n";
    cout << "7--> Exit \n";
    cout << "_________________________________________________________________________________________________________\n";
    cout << "Choose option from 1 to 7 " << endl;
    cout << "Enter your option = ";
    cin >> choice;
    return choice;
}

void display_menu_for_admin()
{
    int a;
    system("cls");
    a = admin_menu();

    if (a == 1)
    {
        admit_patient();
    }
    else if (a == 2)
    {
        discharge_patient();
    }
    else if (a == 3)
    {
        view_patient_details();
    }
    else if (a == 4)
    {
        update_patient_details();
    }
    else if (a == 5)
    {
        view_all_patients();
    }
    else if (a == 6)
    {
        logout();
    }
    else if (a == 7)
    {
        exit(0);
    }
    else
    {
        cout << "Invalid option\n";
    }
}

void admit_patient()
{
    system("cls");
    add_patient();
    cin.ignore();
    cout << "Name of the patient = ";
    getline(cin, patient_name[patientcount]);
    cout << "Age of the patient = ";
    cin >> patient_age[patientcount];
    cout << "Patient ID = ";
    cin >> patient_id[patientcount];
    cout << "Room number = ";
    cin >> patient_roomno[patientcount];
    patient_status[patientcount] = 1; // 1 represents admitted
    patientcount++;

    fstream data("hms.txt", ios::app);
 
        data << patient_name[patientcount-1] << ',' << patient_age[patientcount-1] << ',' << patient_id[patientcount-1] << ',' << patient_roomno[patientcount-1] << ',' << patient_status[patientcount-1] << endl;
    

    data.close();
    
    read_patient_data();
    display_menu_for_admin();
}


void discharge_patient()
{
    system("cls");
    discharge_patient_menu();
    int patientID;
    cout << "Enter the Patient ID = ";
    cin >> patientID;
    bool recordFound = false;
    for (int i = 0; i < patientcount; i++)
    {
        if (patientID == patient_id[i])
        {
            if (patient_status[i] == 1) 
            {
                patient_status[i] = 0; 

                // Update data in the file
                fstream data("hms.txt", ios::out);
                for (int j = 0; j < patientcount; j++)
                {
                    data << patient_name[j] << ',' << patient_age[j] << ',' << patient_id[j] << ',' << patient_roomno[j] << ',' << patient_status[j] << endl;
                }
                data.close();

                cout << "Patient Discharged successfully!" << endl;
            }
            else
            {
                cout << "Patient is not currently admitted." << endl;
            }
            recordFound = true;
            break;
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered Patient ID." << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    display_menu_for_admin();
}

void view_patient_details()
{
    system("cls");
    view_patient();
    int patientID;
    bool recordFound = false;
    cout << "Enter the Patient ID = ";
    cin >> patientID;
    for (int i = 0; i < patientcount; i++)
    {
        if (patientID == patient_id[i])
        {
            cout << "Name of the patient = " << patient_name[i] << endl;
            cout << "Age of the patient = " << patient_age[i] << endl;
            cout << "Patient ID = " << patient_id[i] << endl;
            cout << "Room number = " << patient_roomno[i] << endl;
            cout << "Patient Status: " << (patient_status[i] == 1 ? "Admitted" : "Discharged") << endl;
            recordFound = true;
            break;
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered Patient ID." << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    display_menu_for_admin();
}


void update_patient_details()
{
    system("cls");
    update_patient();
    int patientID;
    cout << "Enter the Patient ID = ";
    cin >> patientID;
    bool recordFound = false;
    for (int i = 0; i < patientcount; i++)
    {
        if (patientID == patient_id[i])
        {
            cin.ignore();
            cout << "Name of the patient = ";
            getline(cin, patient_name[i]);

            cout << "Age of the patient = ";
            cin >> patient_age[i];
            cout << "Room number = ";
            cin >> patient_roomno[i];
            recordFound = true;

            // Update data in the file
            fstream data("hms.txt", ios::out);
            for (int j = 0; j < patientcount; j++)
            {
                data << patient_name[j] << ',' << patient_age[j] << ',' << patient_id[j] << ',' << patient_roomno[j] << ',' << patient_status[j] << endl;
            }
            data.close();
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered Patient ID." << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    display_menu_for_admin();
}

void view_all_patients()
{
    system("cls");
    view_all_patients_menu();
    for (int i = 0; i < patientcount; i++)
    {
    	cout << "---------------------------------------------\n";	
        cout << "Patient ID: " << patient_id[i] << endl;
        cout << "Name: " << patient_name[i] << endl;
        cout << "Age: " << patient_age[i] << endl;
        cout << "Room number: " << patient_roomno[i] <<endl;
		cout << "Status: ";
		if (patient_status[i] == 1) {
    	cout << "Admitted";
}		else {
    	cout << "Discharged";
}
	cout << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    display_menu_for_admin();
}

string get_field(string record, int field)
{
    string item;
    int comma = 1;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            comma = comma + 1;
        }
        else if (comma == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
string get_field2(string record2, int field2)
{
    string item;
    int comma = 1;
    for (int x = 0; x < record2.length(); x++)
    {
        if (record2[x] == ',')
        {
            comma = comma + 1;
        }
        else if (comma == field2)
        {
            item = item + record2[x];
        }
    }
    return item;
}


void read_patient_data() {
    string record;
    fstream data("hms.txt", ios::in);
    patientcount = 0; // Reset patient count before reading data
    while (getline(data, record)) {
        if (patientcount < max_patients) {
            patient_name[patientcount] = get_field(record, 1);
            patient_age[patientcount] = stoi(get_field(record, 2));
            patient_id[patientcount] = stoi(get_field(record, 3));
            patient_roomno[patientcount] = stoi(get_field(record, 4));
            patient_status[patientcount] = stoi(get_field(record, 5));
            patientcount++;
        } else {
            cout << "Max number of patients reached. Some data may be lost." << endl;
            break;
        }
    }
    data.close();
}

void read_doctor_data() {
    string record;
    fstream data("hms_doctors.txt", ios::in);
    doctorcount = 0; // Reset doctor count before reading data
    while (getline(data, record)) {
        if (doctorcount < max_doctors) {
            doctor_name[doctorcount] = get_field(record, 1);
            doctor_age[doctorcount] = stoi(get_field(record, 2));
            doctor_id[doctorcount] = stoi(get_field(record, 3));
            doctor_roomno[doctorcount] = stoi(get_field(record, 4));
            doctorcount++;
        }
    }
    data.close();
}

void add_doctor_header()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                                ---- Add Doctor ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void view_doctor_header()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                             ---- View Doctor Details ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void update_doctor_header()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                           ---- Update Doctor Details ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void remove_doctor_header()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                             ---- Remove Doctor ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void view_all_doctors_header()
{
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                         ---- View All Doctors ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
}

void add_doctor()
{
    system("cls");
    add_doctor_header();
    cin.ignore();
    cout << "Name of the doctor = ";
    getline(cin, doctor_name[doctorcount]);
    cout << "Age of the doctor = ";
    cin >> doctor_age[doctorcount];
    cout << "Doctor ID = ";
    cin >> doctor_id[doctorcount];
    cout << "Room number = ";
    cin >> doctor_roomno[doctorcount];
    doctorcount++;

    // Rewrite the entire data file
    fstream data2("hms_doctors.txt", ios::app);
   
        data2 << doctor_name[doctorcount-1] << ',' << doctor_age[doctorcount-1] << ',' << doctor_id[doctorcount-1] << ',' << doctor_roomno[doctorcount-1] << endl;
    
    data2.close();

    // Read and display data
    read_doctor_data();
    display_menu_for_doctor();
}


void view_doctor_details()
{
    system("cls");
    view_doctor_header();
    int doctorID;
    bool recordFound = false;
    cout << "Enter the Doctor ID = ";
    cin >> doctorID;
    for (int i = 0; i < doctorcount; i++)
    {
        if (doctorID == doctor_id[i])
        {
            cout << "Name of the doctor = " << doctor_name[i] << endl;
            cout << "Age of the doctor = " << doctor_age[i] << endl;
            cout << "Doctor ID = " << doctor_id[i] << endl;
            cout << "Room number = " << doctor_roomno[i] << endl;
            recordFound = true;
            break;
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered Doctor ID." << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    display_menu_for_doctor();
}


void update_doctor_details()
{
    system("cls");
    update_doctor_header();
    int doctorID;
    cout << "Enter the Doctor ID = ";
    cin >> doctorID;
    bool recordFound = false;
    for (int i = 0; i < doctorcount; i++)
    {
        if (doctorID == doctor_id[i])
        {
            cin.ignore();
            cout << "Name of the doctor = ";
            getline(cin, doctor_name[i]);

            cout << "Age of the doctor = ";
            cin >> doctor_age[i];
            cout << "Room number = ";
            cin >> doctor_roomno[i];
            recordFound = true;

            // Update data in the file
            fstream data2("hms_doctors.txt", ios::out);
            for (int j = 0; j < doctorcount; j++)
            {
                data2 << doctor_name[j] << ',' << doctor_age[j] << ',' << doctor_id[j] << ',' << doctor_roomno[j] << endl;
            }
            data2.close();
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered Doctor ID." << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    display_menu_for_doctor();
}

void remove_doctor()
{
    system("cls");
    remove_doctor_header();
    int doctorID;
    cout << "Enter the Doctor ID = ";
    cin >> doctorID;
    bool recordFound = false;
    for (int i = 0; i < doctorcount; i++)
    {
        if (doctorID == doctor_id[i])
        {
            recordFound = true;
            // Shift data in the arrays to overwrite the deleted record
            for (int j = i; j < doctorcount - 1; j++)
            {
                doctor_name[j] = doctor_name[j + 1];
                doctor_age[j] = doctor_age[j + 1];
                doctor_id[j] = doctor_id[j + 1];
                doctor_roomno[j] = doctor_roomno[j + 1];
            }
            // Decrement doctor count after deletion
            doctorcount--;
            fstream data2("hms_doctors.txt", ios::out);
            for (int j = 0; j < doctorcount; j++)
            {
                data2 << doctor_name[j] << ',' << doctor_age[j] << ',' << doctor_id[j] << ',' << doctor_roomno[j] << endl;
            }
            data2.close();

            cout << "Doctor Removed successfully!" << endl;
            break;
        }
    }
    if (!recordFound)
    {
        cout << "No record found for the entered Doctor ID." << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    display_menu_for_doctor();
}

void view_all_doctors()
{
    system("cls");
    view_all_doctors_header();
    for (int i = 0; i < doctorcount; i++)
    {
    	cout << "---------------------------------------------\n";
        cout << "Doctor ID: " << doctor_id[i] <<endl;
        cout << "Name: " << doctor_name[i] << endl;
        cout << "Age: " << doctor_age[i] << endl;
        cout << "Room number: " << doctor_roomno[i] << endl;
    }
    getch(); // Wait for a key press before returning to the menu
    display_menu_for_doctor();
}

int doctor_menu()
{
    system("cls");
    int choice;
    cout << "_________________________________________________________________________________________________________\n";
    cout << "                              ---- Doctor Menu ----                                      \n";
    cout << "_________________________________________________________________________________________________________\n";
    cout << "1--> Add Doctor Details \n";
    cout << "2--> Update Doctor Details \n";
    cout << "3--> View Doctor Details \n";
    cout << "4--> Remove Doctor \n";
    cout << "5--> View All Doctors \n";
    cout << "6--> Logout \n";
    cout << "7--> Exit \n";
    cout << "_________________________________________________________________________________________________________\n";
    cout << "Choose option from 1 to 6 " << endl;
    cout << "Enter your option = ";
    cin >> choice;
    return choice;
}

void display_menu_for_doctor()
{
    int a;
    system("cls");
    a = doctor_menu();

    if (a == 1)
    {
       add_doctor();
    }
     else if (a == 2)
    {
        update_doctor_details();
    }
    else if (a == 3)
    {
        view_doctor_details();
    }
    else if (a == 4)
    {
        remove_doctor();
    }
    else if (a == 5)
    {
        view_all_doctors();
    }
    else if (a == 6)
    {
        logout();
    }
    else if (a == 7)
    {
        exit(0);
    }
    else
    {
        cout << "Invalid option\n";
    }
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

void readdocData() {
    string record;
    fstream userData;
    userData.open("docCredentials.txt", ios::in);
    while (getline(userData, record)) {
        docNames[docIndex] = getCredentials(record, 1);
        docPasswords[docIndex] = getCredentials(record, 2);
        docIndex = docIndex + 1;
    }
}

void readAdminData() {
    string record;
    fstream adminData;
    adminData.open("adminCredentials(hms).txt", ios::in);
    while (getline(adminData, record)) {
        adminNames[adminIndex] = getCredentials(record, 1);
        adminPasswords[adminIndex] = getCredentials(record, 2);
        adminIndex = adminIndex + 1;
    }
    adminData.close();
}


void writedocData() {
    fstream docData;
    docData.open("docCredentials.txt", ios::app);
    docData << docNames[docIndex] << "," << docPasswords[docIndex] << ","<<endl;;
    docData.close();
}

void docSignUp() {
	system("cls");
	header();
    string name, password;
  	cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Password: ";
    getline(cin, password);

    docNames[docIndex] = name;
    docPasswords[docIndex] = password;

    writedocData();
	doctor();
    cout << "User Sign-up successful!" << endl;
}

void adminSignIn() {
	
    readAdminData();
    string name, password;
    cin.ignore(); 
	while(true)
	{
	system("cls");
	header();
    cout << "Enter Admin Name: ";
    getline(cin, name);

    cout << "Enter Admin Password: ";
    getline(cin, password);

    bool isAdminFound = false;

    for (int x = 0; x < adminIndex; x++) {
      
        if (name == adminNames[x] && password == adminPasswords[x]) {
        	 cout << "Sign-in successful!" << endl;
        	display_menu_for_admin();
           
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


void docSignIn() {
	
    readdocData();
    cin.ignore();
    string name, password;
	while(true)
	{
	system("cls");
	header();
    cout << "Enter User Name: ";
    getline(cin, name);
    cout << "Enter User Password: ";
    getline(cin, password);

    bool docFound = false;

    for (int x = 0; x < docIndex; x++) {
        if (name == docNames[x] && password == docPasswords[x]) {
        	display_menu_for_doctor();
            cout << "Sign-in successful!" << endl;
            docFound = true;
            break;
        }
    }

    if (!docFound) {
        cout << "Sign-in unsuccessful!" << endl;
          cout<<"Press any key to try again!";
        getch();
    }
}
}
