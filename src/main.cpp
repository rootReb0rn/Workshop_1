
#include "decoration.h"

/* Default Lib */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* Add-On Lib */
#include <Windows.h>
#include <ctime>
#include <string.h>
#include <cstdlib>
#include <limits>

	/* SQL LIB */
	#include <cppconn/driver.h>
	#include <cppconn/exception.h>
	#include <cppconn/resultset.h>
	#include <cppconn/statement.h>
	#include <cppconn/prepared_statement.h>
	/* Header File */
	#include "login.h"
	#include "AdminController.h"
#include <iomanip>
using namespace std;
using namespace sql;


Driver* driver;
Connection* conn;

/* Project Core */
int main() {
	/*
	int choice;
	
	// INFINTIE LOOP
	for (;;) {

		cout << endl << endl;
		cout << "\t\t\t\t Welcome Admin [ NAME ]" << endl << endl;
		cout << "1.\t Manage User " << endl;
		cout << "2.\t Manage Staff " << endl;
		cout << "3.\t Manage Complaint " << endl;
		cout << "4.\t Generate Report" << endl;
		cout << "5.\t Exit " << endl << endl;
		cout << "Enter your choice\t: " << flush;
		cin >> choice;
		
		// Choice Path
		switch (choice)
		{
		case 1:
			int userC;
			cout << endl;
			cout << " ** U S E R **" << endl << endl;
			cout << "1.\t Add User " << endl;
			cout << "2.\t Update User " << endl;
			cout << "3.\t Delete User " << endl;
			cout << "4.\t View User " << endl;
			cout << "5.\t Exit " << endl << endl;
			cout << "Enter your choice\t: " << flush;
			cin >> userC;

			switch (userC)
			{
			case 1: 
				cout << "Add User" << endl;
				Sleep(3000);
				break;
			
			case 2: 
				cout << "Update User" << endl;
				Sleep(3000);
				break;
			
			case 3: 
				cout << "Delete User" << endl;
				Sleep(3000);
				break;
			
			case 4: 
				cout << "View User" << endl;
				Sleep(3000);
				break;
			
			case 5: 
				exit(0);
				Sleep(3000);
				break;
			
			default:
				cout << "Wrong option,  please retry";
			}

		break;

		case 2:
			int staffC;
			cout << endl;
			cout << " ** S T A F F **" << endl << endl;
			cout << "1.\t Add Staff " << endl;
			cout << "2.\t Update Staff " << endl;
			cout << "3.\t Delete Staff " << endl;
			cout << "4.\t View Staff " << endl;
			cout << "5.\t Exit " << endl << endl;
			cout << "Enter your choice\t: " << flush;
			cin >> staffC;

			switch (staffC)
			{
			case 1:
				cout << "Add Staff" << endl;
				Sleep(3000);
				break;

			case 2:
				cout << "Update Staff" << endl;
				Sleep(3000);
				break;

			case 3:
				cout << "Delete Staff" << endl;
				Sleep(3000);
				break;

			case 4:
				cout << "View Staff" << endl;
				Sleep(3000);
				break;

			case 5:
				exit(0);
				Sleep(3000);
				break;

			default:
				cout << "Wrong option,  please retry";
			}

		break;

		case 3:
			int complaintC;
			cout << endl;
			cout << " ** C O M P L A I N T **" << endl << endl;
			cout << "1.\t Add Complaint " << endl;
			cout << "2.\t Update Complaint " << endl;
			cout << "3.\t Delete Complaint " << endl;
			cout << "4.\t View Complaint " << endl;
			cout << "5.\t Exit " << endl << endl;
			cout << "Enter your choice\t: " << flush;
			cin >> complaintC;

			switch (complaintC)
			{
			case 1:
				cout << "Add Complaint" << endl;
				Sleep(3000);
				break;

			case 2:
				cout << "Update Complaint" << endl;
				Sleep(3000);
				break;

			case 3:
				cout << "Delete Complaint" << endl;
				Sleep(3000);
				break;

			case 4:
				cout << "View Complaint" << endl;
				Sleep(3000);
				break;

			case 5:
				exit(0);
				Sleep(3000);
				break;

			default:
				cout << "Wrong option,  please retry";
			}

		break;

		case 4:
			cout << " Generating Report " << endl;
			Sleep(3000);
			break;

		case 5: exit(0);
			break;

		default:
			cout << "Wrong Entry, Please re-try";
		}
	}
	// End
	*/
	
	try{
		
		/* Create a Connection */
		driver = get_driver_instance();
		conn = driver->connect("tcp://127.0.0.1:3306", "root", "");

		/* Connet to the MySQL database */
		conn->setSchema("db_ftmk_maintenance");

		/* System Run */
		
		int key;
		login login1;
		AdminController admin;
		decoration d;
		d.bannerMontage();
		system("COLOR 0F");
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		for (;;) {
			/*
			cout << endl << endl;
			d.title();
			cout <<"( Welcome to FTMK Maintenance System )" << endl;
			d.defaultCOLOR();
			cout << "--------------------------------------" << endl;
			cout << "|\t\t\t\t     |" << endl;
			cout << "|\t" << "      [1] Login" << "\t\t     |" << endl;
			cout << "|\t" << "      [2] Register" << "\t     |" << endl;
			cout << "|\t" << "      [3] Exit" << "\t\t     |" << endl;
			cout << "|\t\t\t\t     |" << endl;
			cout << "--------------------------------------" << endl << endl << endl;

			d.select();
			cout << "Select any option\t: " << flush;
			cin >> key;
			*/
			

				cout << endl << endl;
				d.title();
				cout << "( Welcome to FTMK Maintenance System )" << endl;
				d.defaultCOLOR();
				cout << "--------------------------------------" << endl;
				cout << "|\t\t\t\t     |" << endl;
				cout << "|\t" << "      [1] Login" << "\t\t     |" << endl;
				cout << "|\t" << "      [2] Register" << "\t     |" << endl;
				cout << "|\t" << "      [3] Exit" << "\t\t     |" << endl;
				cout << "|\t\t\t\t     |" << endl;
				cout << "--------------------------------------" << endl << endl << endl;

				d.select();
				cout << "Select any option\t: " << flush;
				cin >> key;

				if (cin.fail()) {

					cin.clear();
					cin.ignore();
					d.danger();
					system("cls");
					
				}

			Beep(600, 500);
			SetConsoleTextAttribute(color, 15);
			switch (key)
			{
			case 1:
				system("cls");			
				login1.loginController(conn);
				break;
			case 2:
				login1.registerUser(conn);
				break;
			case 3:
				exit(0);
				break;
			case 4:
				cout << "Testing Unit" << endl;
				Sleep(2000);
				system("cls");

				// Testing Code
				admin.displayGraph(conn);

				system("pause");
				break;
			default:
				d.danger();
				cout << endl;
				cout << "Wrong Input, Retry";
				Sleep(3000);
				system("cls");

			}
		}

	}
	catch (SQLException & e) {

		/* Declaration of the Error */
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << " ERR : " << e.what();
		cout << " (MySQL error code : " << e.getErrorCode();
		cout << ", SQLState : " << e.getSQLState() << " )" << endl;
	}


	return 0;
}