#pragma once
#include <string>

/* SQL Lib */
#include <cppconn/driver.h>
#include <cppconn/connection.h>

using namespace std;

class UserController
{
public:
	void newUserUpdate(sql::Connection* conn, string userName);
	void testLogin(sql::Connection* conn, string userName);
	void makeComplaint(sql::Connection * conn, string userName);
	void viewMyStatus(sql::Connection* conn, string userName);
	void viewProfile(sql::Connection* conn, string userName);
	void updateProfile(sql::Connection* conn, string userName);
	void changePassword(sql::Connection* conn, string userName);
};

