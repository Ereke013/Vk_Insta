#pragma once
#include "User.h"
using namespace std;

class Post : public User {
	int ID_post, ID_owner, image;
	string text, time;
	vector<unsigned int> likedUserIDs;
public:
	void setID_post(int ID_post) { this->ID_post = ID_post; }
	void setID_owner(int ID_owner) { this->ID_owner = ID_owner; }
	void setImage(int image) { this->image = image; }
	void setText(string text) { this->text = text; }
	void setTime(string time) { this->time = time; }


	int getID_post() { return ID_post; }
	int getID_owner() { return ID_owner; }
	int getImage() { return image; }
	string getText() { return text; }
	string getTime() { return time; }
};