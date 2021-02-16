#include "StaffController.h"
#include "AdminController.h"

/* Default Lib */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* Add_On Lib */
#include <string>
#include <Windows.h>
#include <iomanip>
#include <typeinfo>
#include "PromptBox.h"
#include "TextTable.h"
	/* SQL LIB */
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

// Completed 23/04/2020 
int StaffController::addUser(sql::Connection* conn, string staffName) {

	//User user;
	int success = -1;
	sql::PreparedStatement* pstmt;

	// Local Variable
	string fullname;
	string password = "abc123";
	string email;
	string contact;
	string department;
	string status = "USER";
	string address = "N/A";
	string state = "N/A";
	string country = "N/A";
	string pincode = "N/A";
	// End of Local Variable

	cout << "\nAdd User" << endl;
	cout << "@Staff\n" << endl;
	cout << "Fullname\t: " << flush;
	cin >> fullname;
	cout << "Email\t\t: " << flush;
	cin >> email;
	cout << "Contact\t\t: " << flush;
	cin >> contact;
	cout << "Department\t: " << flush;
	cin >> department;

	/* Get Staff Detalis*/
	sql::PreparedStatement* pstmtStaff;
	sql::ResultSet* resStaff;
	int staffID = 0;

	pstmtStaff = conn->prepareStatement("Select StaffID from staff where fullname = ?");
	pstmtStaff->setString(1, staffName);
	resStaff = pstmtStaff->executeQuery();
	if (resStaff->next()) {

		staffID = resStaff->getInt(1);
	}
	/* End Staff Detalis*/

	/* Start Process to Adding User */

	string addSQL = "insert into users (AdminID,fullname,password,email,contact,department,status,address,state,country,pincode) values (?,?,?,?,?,?,?,?,?,?,?)";
	pstmt = conn->prepareStatement(addSQL);
	pstmt->setInt(1, staffID);
	pstmt->setString(2, fullname);
	pstmt->setString(3, password);
	pstmt->setString(4, email);
	pstmt->setString(5, contact);
	pstmt->setString(6, department);
	pstmt->setString(7, status);
	pstmt->setString(8, address);
	pstmt->setString(9, state);
	pstmt->setString(10, country);
	pstmt->setString(11, pincode);
	success = pstmt->execute();

	/* End Process to Adding User */

	PromptBox::successAdd();
	delete pstmt;
	delete pstmtStaff;
	delete resStaff;
	return success;

}

// Completed 14/04/2020 
int StaffController::updateUser(sql::Connection* conn, string staffName) {

	int success = -1;
	sql::PreparedStatement* pstmt;

	// Local Variable
	int uID;
	int sel;

	string fullname;
	string password;
	string email;
	string contact;
	string department;
	string status;
	string address;
	string state;
	string country;
	string pincode;
	// End of Local Variable



	cout << "\nUpdate User" << endl;
	cout << "@Staff\n" << endl;

	cout << "C U R R E N T   U S E R" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "ID" << "\t\t\t" << "Full Name" << endl;
	cout << "------------------------------------------------------" << endl;
	Sleep(2000);
	/* LIST USER */
	sql::PreparedStatement* pstmtUser;
	sql::ResultSet* resUser;

	pstmtUser = conn->prepareStatement("Select UID,fullname from users");
	resUser = pstmtUser->executeQuery();
	while (resUser->next()) {

		cout << "[ " << resUser->getInt(1) << " ]" << "\t\t\t" << resUser->getString(2) << endl;
	}
	cout << "------------------------------------------------------" << endl;

	cout << "Select User ID\t: " << flush;
	cin >> uID;


	/* Selection */
	sql::PreparedStatement* pstmtUser1;
	sql::ResultSet* resUser1;

	pstmtUser1 = conn->prepareStatement("Select * from users where UID = ?");
	pstmtUser1->setInt(1, uID);
	resUser1 = pstmtUser1->executeQuery();


	if (resUser1->next()) {

		system("cls");
		cout << "\nUpdate User" << endl;
		cout << "@Admin\n" << endl;

		cout << " Existing " << resUser1->getString("fullname") << " Data" << endl;
		cout << "------------------------------------------------------" << endl;

		cout << "[1]\tEmail\t\t: " << resUser1->getString("email") << endl;
		cout << "[2]\tContact\t\t: " << resUser1->getString("contact") << endl;
		cout << "[3]\tDepartment\t: " << resUser1->getString("department") << endl;
		cout << "[4]\tAddress\t\t: " << resUser1->getString("address") << endl;
		cout << "[5]\tState\t\t: " << resUser1->getString("state") << endl;
		cout << "[6]\tCountry\t\t: " << resUser1->getString("country") << endl;
		cout << "[7]\tPincode\t\t: " << resUser1->getString("pincode") << endl;
		cout << "[8]\tChange All" << endl;
		cout << "------------------------------------------------------\n" << endl;
		cout << "Select\t: " << flush;
		cin >> sel;
		cout << endl << endl;



		switch (sel)
		{
		case 1:
			cout << "Email\t\t: " << flush;
			cin >> email;
			pstmt = conn->prepareStatement("update users set email = ? where UID = ?");
			pstmt->setString(1, email);
			pstmt->setInt(2, uID);
			success = pstmt->executeUpdate();
			delete pstmt;
			break;
		case 2:
			cout << "Contact\t\t: " << flush;
			cin >> contact;
			pstmt = conn->prepareStatement("update users set contact = ? where UID = ?");
			pstmt->setString(1, contact);
			pstmt->setInt(2, uID);
			success = pstmt->executeUpdate();
			delete pstmt;
			break;
		case 3:
			cout << "Department\t: " << flush;
			cin >> department;
			pstmt = conn->prepareStatement("update users set department = ? where UID = ?");
			pstmt->setString(1, department);
			pstmt->setInt(2, uID);
			success = pstmt->executeUpdate();
			delete pstmt;
			break;
		case 4:
			cout << "Address\t\t: " << flush;
			getline(cin.ignore(), address);
			pstmt = conn->prepareStatement("update users set address = ? where UID = ?");
			pstmt->setString(1, address);
			pstmt->setInt(2, uID);
			success = pstmt->executeUpdate();
			delete pstmt;
			break;
		case 5:
			cout << "State\t\t: " << flush;
			cin >> state;
			pstmt = conn->prepareStatement("update users set state = ? where UID = ?");
			pstmt->setString(1, state);
			pstmt->setInt(2, uID);
			success = pstmt->executeUpdate();
			delete pstmt;
			break;
		case 6:
			cout << "Country\t\t: " << flush;
			cin >> country;
			pstmt = conn->prepareStatement("update users set country = ? where UID = ?");
			pstmt->setString(1, country);
			pstmt->setInt(2, uID);
			success = pstmt->executeUpdate();
			delete pstmt;
			break;
		case 7:
			cout << "Pincode\t\t: " << flush;
			cin >> pincode;
			pstmt = conn->prepareStatement("update users set pincode = ? where UID = ?");
			pstmt->setString(1, pincode);
			pstmt->setInt(2, uID);
			success = pstmt->executeUpdate();
			delete pstmt;
			break;
		case 8:
			cout << "Email\t\t: " << flush;
			cin >> email;
			cout << "Contact\t\t: " << flush;
			cin >> contact;
			cout << "Department\t: " << flush;
			cin >> department;
			cout << "Address\t\t: " << flush;
			cin >> address;
			cout << "State\t\t: " << flush;
			cin >> state;
			cout << "Country\t\t: " << flush;
			cin >> country;
			cout << "Pincode\t\t: " << flush;
			cin >> pincode;

			pstmt = conn->prepareStatement("update users set email = ?,contact = ?,department = ?,address = ?,state = ?,country = ?,pincode = ? where UID = ?");

			pstmt->setString(1, email);
			pstmt->setString(2, contact);
			pstmt->setString(3, department);
			pstmt->setString(4, address);
			pstmt->setString(5, state);
			pstmt->setString(6, country);
			pstmt->setString(7, pincode);
			pstmt->setInt(8, uID);
			success = pstmt->executeUpdate();
			delete pstmt;
			break;
		default:
			cout << "Wrong Input" << endl;
		}

		PromptBox::successUpdate();
	}
	delete pstmtUser;
	delete resUser;
	delete pstmtUser1;
	delete resUser1;
	return success;
}

// Completed 14/04/2020 
void StaffController::deleteUser(sql::Connection* conn) {

	sql::PreparedStatement* pstmt;
	int uID;
	string decision;

	cout << "\nDelete User" << endl;
	cout << "@Admin\n" << endl;

	cout << "C U R R E N T   U S E R" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "ID" << setw(20) << "Full Name" << endl;
	cout << "------------------------------------------------------" << endl;
	Sleep(2000);
	/* LIST USER */
	sql::PreparedStatement* pstmtUser;
	sql::ResultSet* resUser;

	pstmtUser = conn->prepareStatement("Select UID,fullname from users");
	resUser = pstmtUser->executeQuery();
	while (resUser->next()) {

		cout << "[ " << resUser->getInt(1) << " ]" << setw(20) << resUser->getString(2) << endl;
	}
	cout << "------------------------------------------------------" << endl;

	cout << "Select User ID\t: " << flush;
	cin >> uID;
	cout << endl;
	cout << "Area you sure to delete ID " << uID << " ? \n[ Y / N ] = " << flush;
	cin >> decision;
	if (decision == "Y") {

		string deleteSQL = "delete from users where UID = ?";

		pstmt = conn->prepareStatement(deleteSQL);
		pstmt->setInt(1, uID);
		pstmt->executeUpdate();

		delete pstmt;
		PromptBox::successDelete();
	}

	delete pstmtUser;
	delete resUser;
}

// Completed 14/04/2020
void StaffController::viewUser(sql::Connection* conn) {

	string sql = "select * from users";
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;
	int i = 0;

	pstmt = conn->prepareStatement(sql);
	res = pstmt->executeQuery();

	cout << "\nView User" << endl;
	cout << "@Admin\n" << endl;
	cout << " U S E R S   D A T A" << endl;
	//cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	//cout << "Full Name" << setw(15) << "Email" << setw(15) << "Contact" << setw(15) << "Address" << setw(15) << "State" << setw(15) << "Country" << setw(15) << "Pin Code" << setw(15) << "Register Date" << endl;
	//cout << "------------------------------------------------------------------------------------------------------------------" << endl;

	TextTable t(' .', '|', '+');
	t.add("Fullname");
	t.add("Email");
	t.add("Contact");
	t.add("Address");
	t.add("State");
	t.add("Country");
	t.add("Pin Code");
	t.add("Register Date");
	t.endOfRow();


	Sleep(2000);
	while (res->next()) {

		//cout << res->getString(4) << setw(15) << res->getString(6) << setw(15) << res->getString(7) << setw(15) << res->getString(10) << setw(15) << res->getString(11) << setw(15) << res->getString(12) << setw(15) << res->getString(13) << setw(15) << res->getString(14) << endl;
		t.add(res->getString(4));
		t.add(res->getString(6));
		t.add(res->getString(7));
		t.add(res->getString(10));
		t.add(res->getString(11));
		t.add(res->getString(12));
		t.add(res->getString(13));
		t.add(res->getString(14));
		t.endOfRow();
		i++;
	}

	t.setAlignment(2, TextTable::Alignment::RIGHT);
	cout << t;
	cout << endl;
	cout << "Total Users\t: " << i << endl;
	system("pause");
	delete pstmt;
	delete res;

}

void StaffController::resetPassword(sql::Connection* conn) {

	int uID;
	string sel;
	sql::PreparedStatement* pstmt;

	cout << "\nReset Password" << endl;
	cout << "@Staff\n" << endl;

	cout << "C U R R E N T   U S E R" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "ID" << "\t\t\t" << "Full Name" << endl;
	cout << "------------------------------------------------------" << endl;
	Sleep(2000);

	/* LIST USER */
	sql::PreparedStatement* pstmtUser;
	sql::ResultSet* resUser;

	pstmtUser = conn->prepareStatement("Select UID,fullname from users");
	resUser = pstmtUser->executeQuery();
	while (resUser->next()) {

		cout << "[ " << resUser->getInt(1) << " ]" << "\t\t\t" << resUser->getString(2) << endl;
	}
	cout << "------------------------------------------------------" << endl;

	cout << "Select User ID\t: " << flush;
	cin >> uID;


	/* Selection */
	sql::PreparedStatement* pstmtUser1;
	sql::ResultSet* resUser1;

	pstmtUser1 = conn->prepareStatement("Select * from users where UID = ?");
	pstmtUser1->setInt(1, uID);
	resUser1 = pstmtUser1->executeQuery();

	if (resUser1->next()) {

		system("cls");
		cout << "\nReset Password" << endl;
		cout << "@Staff\n" << endl;

		cout << " Existing " << resUser1->getString("fullname") << " Data" << endl;
		cout << "------------------------------------------------------" << endl;

		cout << "\tEmail\t\t: " << resUser1->getString("email") << endl;
		cout << "\tContact\t\t: " << resUser1->getString("contact") << endl;
		cout << "\tDepartment\t: " << resUser1->getString("department") << endl;
		cout << "\tAddress\t\t: " << resUser1->getString("address") << endl;
		cout << "\tState\t\t: " << resUser1->getString("state") << endl;
		cout << "\tCountry\t\t: " << resUser1->getString("country") << endl;
		cout << "\tPincode\t\t: " << resUser1->getString("pincode") << endl;
		cout << "------------------------------------------------------\n" << endl;

		cout << "Are you sure to reset " << resUser1->getString("fullname") << " password ? " << endl;
		cout << " YES\t= Y \n NO\t=N" << endl;
		cout << "Select Option\t: " << flush;
		cin >> sel;

		if (sel == "Y") {

			pstmt = conn->prepareStatement("update users set password = ? where UID = ?");
			pstmt->setString(1, "abc123");
			pstmt->setInt(2, uID);
			pstmt->executeUpdate();
			delete pstmt;
			PromptBox::successUpdate();

		}else if(sel == "N"){}
	}
}

void StaffController::viewComplaint(sql::Connection* conn, string staffName) {


	int cID;
	int sel;
	char cstr[19];
	AdminController ac;

	string sql = "select * from complaint where StaffID = ? and respond='NOT PROCESS' ";
	sql::PreparedStatement* pstmt;
	sql::ResultSet* res;
	int i = 0;

	/* Get Staff Detalis*/
	sql::PreparedStatement* pstmtStaff;
	sql::ResultSet* resStaff;
	int staffID = 0;

	pstmtStaff = conn->prepareStatement("Select StaffID from staff where fullname = ?");
	pstmtStaff->setString(1, staffName);
	resStaff = pstmtStaff->executeQuery();
	if (resStaff->next()) {

		staffID = resStaff->getInt(1);
	}
	/* End Staff Detalis*/


	pstmt = conn->prepareStatement(sql);
	pstmt->setInt(1,staffID);
	res = pstmt->executeQuery();

	cout << "\nRespond Complaint" << endl;
	cout << "@Admin\n" << endl;
	cout << " C O M P L A I N T   D A T A\n" << endl;

	cout << "ID\t\t" << "Model\t\t" << "Serial Number\t\t" << "Respond\t\t" << "Total Days" << endl;
	cout << "\n-----------------------------------------------------------------------------------------\n" << endl;
	Sleep(2000);
	while (res->next()) {

		string newDetalis = res->getString(9);
		strcpy_s(cstr, sizeof newDetalis, newDetalis.c_str());
		cout << res->getString(1) << "\t\t" << res->getString(5) << "\t\t" << res->getString(6) << "\t\t\t" << res->getString(8) << "\t" << ac.masterCountDays(cstr) << endl;
		i++;
	}

	cout << "\n-----------------------------------------------------------------------------------------\n" << endl;
	cout << "Total Not Process Complaint\t: " << i << endl;

	cout << endl;
	cout << "Select Complaint\t: " << flush;
	cin >> cID;


	system("cls");
	cout << "\nRespond Complaint" << endl;
	cout << "@Staff\n" << endl;

	cout << "Complaint Detalis" << endl;
	cout << "------------------------------------------------------" << endl;
	Sleep(2000);

	/* LIST COMPLAINT DETALIS */
	sql::PreparedStatement* pstmtComp;
	sql::ResultSet* resComp;
	sql::PreparedStatement* pstmtPlace;
	sql::ResultSet* resPlace;

	pstmtComp = conn->prepareStatement("Select * from complaint where CompID = ? ");
	pstmtComp->setInt(1, cID);
	resComp = pstmtComp->executeQuery();

	pstmtPlace = conn->prepareStatement("Select Lab from place where PlaceID = ?");
	if (resComp->next()) {

		pstmtPlace->setInt(1, resComp->getInt("PlaceID"));
		resPlace = pstmtPlace->executeQuery();
		if (resPlace->next()) {
			cout << "Place\t: " << resPlace->getString("Lab") << endl;
		}

		cout << "Model\t: " << resComp->getString("model")<<endl;
		cout << "No.Serial\t: " << resComp->getString("noSerial")<<endl;
		cout << "Respond\t: " << resComp->getString("respond") << endl;
		cout << "Complaint Date\t: " << resComp->getString("compDate") << endl;
		cout << "Detalis\t: " << resComp->getString("details");

	}
	cout << "------------------------------------------------------" << endl;

	sql::PreparedStatement* pstmtProceed;

	cout << "[1] To Proceed this Complaint" << endl;
	cout << "[2] Ignore this Complaint for now" << endl << endl;
	int sel1;
	cout << "Select the option\t: " << flush;
	cin >> sel1;
	if (sel1 == 1) {

		pstmtProceed = conn->prepareStatement("update complaint set respond = ? where CompID = ?");
		pstmtProceed->setString(1, "IN PROCESS");
		pstmtProceed->setInt(2, cID);
		pstmtProceed->executeQuery();
		delete pstmtProceed;
	}


	PromptBox::successAdd();
	delete pstmt;
	delete res;
}

void StaffController::viewComplaint(sql::Connection* conn, string staffName, int staffID , string typeComplaint, string status) {

	sql::PreparedStatement* pstmtView;
	sql::ResultSet* resView;
	char cstr[19]; 
	AdminController ac;
	string viewSQL = "Select * from complaint where StaffID = ? and  respond = ?";
	pstmtView = conn->prepareStatement(viewSQL);
	pstmtView->setInt(1, staffID);
	pstmtView->setString(2, status);
	resView = pstmtView->executeQuery();

	cout << typeComplaint << " Complaint" << endl;
	cout << "@Staff\n" << endl;
	cout << "Status\t: " << status << endl;

	cout << "Complainted Data" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << setw(5) <<"ID" << setw(20) << "Model" << setw(20) << "Serial Number" << setw(20) << "Status" << setw(20) << "Date" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;

	while (resView->next())
	{
		string newDetalis = resView->getString(9);
		strcpy_s(cstr, sizeof newDetalis, newDetalis.c_str());
		cout << setw(5) << resView->getInt(1) << setw(20) << resView->getString(5) << setw(20) << resView->getString(6) << setw(20) << resView->getString(8) << setw(20) << ac.masterCountDays(cstr) << endl;

	}
	cout << "---------------------------------------------------------------------------------------------------" << endl;

}

void StaffController::selectedComplaintDetails(sql::Connection* conn, int staffID, int CompID) {

	// Local Variable
	int UID;
	int PlaceID;
	string model, noSerial, details, status;

	// Complaint Details SQL
	sql::PreparedStatement* pstmtComplaint;
	sql::ResultSet* resComplaint;
	string ComplaintSQL = "Select * from complaint where CompID = ?";
	pstmtComplaint = conn->prepareStatement(ComplaintSQL);
	pstmtComplaint->setInt(1, CompID);
	resComplaint = pstmtComplaint->executeQuery();
	if (resComplaint->next()) {

		UID = resComplaint->getInt(2);
		PlaceID = resComplaint->getInt(3);
		model = resComplaint->getString(5);
		noSerial = resComplaint->getString(6);
		details = resComplaint->getString(7);
		status = resComplaint->getString(8);
		
	}

	// End of Complaint Details SQL


	// Complainer Detalils SQL
	sql::PreparedStatement* pstmtUser;
	sql::ResultSet* resUser;
	string userSQL = "Select * from users where UID = ?";
	pstmtUser = conn->prepareStatement(userSQL);
	pstmtUser->setInt(1, UID);
	resUser = pstmtUser->executeQuery();
	// End Complainer Detalils SQL

	// Place Details
	sql::PreparedStatement* pstmtPlace;
	sql::ResultSet* resPlace;
	string placeSQL = "Select * from place where PlaceID = ?";
	pstmtPlace = conn->prepareStatement(placeSQL);
	pstmtPlace->setInt(1, PlaceID);
	resPlace = pstmtPlace->executeQuery();

	// End of Place Details 


	// Complaint User
	cout << "------------------------------------------------" << endl;
	cout << "Complainer Details" << endl;
	cout << "------------------------------------------------" << endl;
	if (resUser->next()) {

		cout << "Full Name\t: " << resUser->getString(4) << endl;
		cout << "Email\t\t: " << resUser->getString(6) << endl;
		cout << "Contact\t\t: " << resUser->getString(7) << endl;
		cout << "Department\t: " << resUser->getString(8) << endl;
	}
	// End of Complaint User

	cout << endl << endl;

	// Complaint Details
	cout << "------------------------------------------------" << endl;
	cout << "Complaint Details" << endl;
	cout << "------------------------------------------------" << endl;

		cout << "Model\t\t: " << model << endl;
		cout << "Number Serial\t: " << noSerial << endl;
		cout << "Details\t\t: " << details << endl;
		cout << "Status\t\t: " << status << endl;

	// End of Complaint Detalis

	cout << endl << endl;

	// Place Details
	cout << "------------------------------------------------" << endl;
	cout << "Place Details" << endl;
	cout << "------------------------------------------------" << endl;
	if (resPlace->next()) {

		cout << "Wing\t\t: " << resPlace->getString(2) << endl;
		cout << "Floor\t\t: " << resPlace->getString(3) << endl;
		cout << "Lab\t\t: " << resPlace->getString(4) << endl;
	}

	// End of Place Details 
	//system("pause");
}

void StaffController::receivedComplaint(sql::Connection* conn, string staffName, int staffID) {

	int sel;
	int action;
	string alertSel;

	viewComplaint(conn, staffName, staffID, "Received", "NOT PROCESS");
	cout << "Select Complaint\t: " << flush;
	cin >> sel;
	system("cls");
	selectedComplaintDetails(conn,staffID,sel);

	cout << "[1] Start Work on this Complaint" << endl;
	cout << "[2] Back to Main Menu" << endl << endl;
	cout << "Select\t : " << endl;
	cin >> action;

	switch (action)
	{
	case 1:
		cout << "Are you sure to proceed it ? [Y/N]  = " << flush;
		cin >> alertSel;

		if (alertSel == "Y") {

			sql::PreparedStatement* pstmt;
			string SQL = "update complaint set respond = 'IN PROCESS' where CompID = ?";
			pstmt = conn->prepareStatement(SQL);
			pstmt->setInt(1, sel);
			pstmt->executeUpdate();
			PromptBox::successUpdate();
		}

		if (alertSel == "y") {

			sql::PreparedStatement* pstmt;
			string SQL = "update complaint set respond = 'IN PROCESS' where CompID = ?";
			pstmt = conn->prepareStatement(SQL);
			pstmt->setInt(1, sel);
			pstmt->executeUpdate();
			PromptBox::successUpdate();
		}

		break;
	case 2:
		break;
	default:
		cout << "Wrong Input" << endl;
	}




}

void StaffController::pendingComplaint(sql::Connection* conn, string staffName, int staffID) {

	int sel;
	int action;
	string alertSel;

	viewComplaint(conn, staffName, staffID, "Pending", "IN PROCESS");
	cout << "Select Complaint\t: " << flush;
	cin >> sel;
	system("cls");
	selectedComplaintDetails(conn,staffID,sel);

	cout << "[1] Complaint Solved" << endl;
	cout << "[2] Back to Main Menu" << endl << endl;
	cout << "Select\t : " << endl;
	cin >> action;

	switch (action)
	{
	case 1:
		cout << "Are you sure to proceed it ? [Y/N]  = " << flush;
		cin >> alertSel;

		if (alertSel == "Y") {

			sql::PreparedStatement* pstmt;
			string SQL = "update complaint set respond = 'SOLVED' where CompID = ?";
			pstmt = conn->prepareStatement(SQL);
			pstmt->setInt(1, sel);
			pstmt->executeUpdate();
			PromptBox::successUpdate();
		}

		if (alertSel == "y") {

			sql::PreparedStatement* pstmt;
			string SQL = "update complaint set respond = 'SOLVED' where CompID = ?";
			pstmt = conn->prepareStatement(SQL);
			pstmt->setInt(1, sel);
			pstmt->executeUpdate();
			PromptBox::successUpdate();
		}

		break;
	case 2:
		break;
	default:
		cout << "Wrong Input" << endl;
	}




}

void StaffController::solvedComplaint(sql::Connection* conn, string staffName, int staffID) {

	int sel;
	int action;
	string alertSel;

	viewComplaint(conn, staffName, staffID, "Pending", "SOLVED");
	cout << "Select Complaint\t: " << flush;
	cin >> sel;
	system("cls");
	selectedComplaintDetails(conn,staffID,sel);

	cout << endl;

	system("pause");




}