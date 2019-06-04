#pragma once
#include "WebSite.h"

class Like {
	int IDpost, IdUser;
public:
	void setID(int IDpost) { this->IDpost = IDpost; }
	void setNum(int IdUser) { this->IdUser = IdUser; }

	int getID() { return IDpost; }
	int getNumLike() { return IdUser; }

};