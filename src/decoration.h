#pragma once
# include <iostream>

using namespace std;

class decoration
{

public:
	void bannerMontage();
	void select();
	void title();
	void input();
	void info();
	void success();
	void danger();
	void defaultCOLOR();

	// Admin Design
	void adminCOLOR();
	void adminStatic();
	void adminTableHeader();
	void adminTableData();
	void adminInput();

	// Staff Design
	void staffCOLOR();
	void staffStatic();
	void staffTableHeader();
	void staffTableData();
	void staffInput();
};

