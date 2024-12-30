
#ifndef CONNEXIOBD2_H
#define CONNEXIOBD2_H

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <string>
#include <fstream>
using namespace std;

class ConnexioBD2 {
private:
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;

	ConnexioBD2() {	
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep08", "xubaasha8Shei6");
		con->setSchema("inep08");
	}

public:
	static ConnexioBD2& getInstance() {
		static ConnexioBD2 instance;
		return instance;
	}

	~ConnexioBD2();

	void exec(const string query);

	sql::ResultSet* consulta(const string query);
};

#endif
