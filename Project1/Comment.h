#pragma once
#include "Post.h"
using namespace std;

class Comment :public Post {
	int ID, ID_post, ID_commenter;
	string text, time;

public:
	void setID(int ID) { this->ID = ID; }
	void setID_post(int ID_post) { this->ID_post = ID_post; }
	void setID_commenter(int ID_commenter) { this->ID_commenter = ID_commenter; }
	void setText(string text) { this->text = text; }
	void setTime(string time) { this->time = time; }


	int getID() { return ID; }
	int getID_post() {return ID_post;}
	int getID_commenter() { return ID_commenter; }
	string getText() { return text; }
	string getTime() { return time; }
};