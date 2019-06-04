#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
	int id;
	string name, login, password, role, time;

public:
	void setId(int id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setLogin(string login) { this->login = login; }
	void setPassword(string password) { this->password = password; }
	void setRole(string role) { this->role = role; }
	void setTime(string time) { this->time = time; }
		
	
	int getId() { return id; }
	string getName() { return name; }
	string getLogin() { return login; }
	string getPassword() { return password; }
	string getRole() { return role; }
	string getTime() { return time; }
};

