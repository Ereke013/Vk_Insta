#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Comment.h"
#include "DataBase.h"
//#include <chrono>
#include <ctime>
using namespace std;

string showTime() {
	time_t t = time(NULL);
	tm* timeinfo = localtime(&t);
	string date = asctime(timeinfo);
	date.pop_back();
	return date;
}

void signUp(vector<User>& users) {
	User u;
	int id, sel;
	string name, log, pass, role, time;
	while (true) {
		system("cls");
		id = users.size();
		cout << "Enter name:"; cin >> name;
		if (name == "0") return;
		cout << "Enter login or tel.num:"; cin >> log;
		if (log == "0") return;
		cout << "Enter password:"; cin >> pass;
		if (pass == "0") return;
		role = "3";
		time = showTime();
		cout << "*************************" << endl;
		cout << "Check correctness of datas" << endl;
		cout << "1) All right" << endl;
		cout << "0) Change" << endl;
		cin >> sel;
		if (sel == 1) {
			u.setId(id);
			u.setName(name);
			u.setLogin(log);
			u.setPassword(pass);
			u.setRole(role);
			u.setTime(time);
			users.push_back(u);
			break;
		}
	}
}

class WebSite {
	vector<User> users;
	vector<Post> posts;
	vector<Comment> comments;
	vector<Like> likes;
	string name;
	int ID;
public:
	WebSite() {}
	WebSite(string name) {
		setName(name);
		IFstream(name, users, posts, comments,  likes);
	}

	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}

	virtual void homePage() = 0;
	virtual void home() {
		while (true) {
			system("cls");
			int sel;
			homePage();
			cout << "1) Sign in" << endl;
			cout << "2) Sign up" << endl;
			cout << "0) Exit" << endl;
			cin >> sel;
			if (sel == 1) {
				string log, pass;
				while (true) {
					system("cls");
					homePage();
					cout << "Enter login or tel.num:";
					cin >> log;
					if (log == "0") break;
					cout << "Enter password:";
					cin >> pass;
					if (pass == "0") break;
					if (voity(log, pass, users, ID) == true) {
						menu(users, posts, comments, ID);
						break;
					}
				}
			}
			else if (sel == 2) {
				signUp(users);
			}
			else {
				break;
			}
		}
	}
	virtual void menu(vector<User>& users, vector<Post>& posts, vector<Comment> &comments,  int ID) = 0;

	int postNum(vector<Post>& posts, int id) {
		int cnt = 0;
		for (int i = 0; i < posts.size(); i++) {
			if (id == posts[i].getID_owner()) {
				cnt++;
			}
		}
		return cnt;
	}
	string nameUser(vector<User>& users, int id) {
		string name = "";
		for (int i = 0; i < users.size(); i++) {
			if (id == i) {
				return users[i].getName();
			}
		}
		return name;
	}
	void getTextComment(int i, vector<Comment>& comments, vector<User>& users) {
		int cnt = 0;
		for (int j = 0; j < comments.size(); j++) {
			if (i == comments[j].getID_post()) {
				cout << endl << ++cnt << ")" << "Comment owner: " << nameUser(users, comments[j].getID_commenter()) << endl;
				cout << "  " << comments[j].getText() << endl;
				cout << "  " << comments[j].getTime();
			}
		}
	}
	void writeComment(vector<Comment> &comments, int ID, int i) {
		Comment c;
		string comm = "'", co, time;
		cin.ignore(); getline(cin, co);
		comm += co;
		comm += "'";
		time = showTime();
		c.setID(comments.size());
		c.setID_post(i);
		c.setID_commenter(ID);
		c.setTime(time);
		c.setText(comm);
		comments.push_back(c);
	}
	int choseImage() {
		int sel;
		while (true) {
			system("cls");
			homePage();
			cout << "\tChose a image!" << endl;
			cout << "1) IT University" << endl << "2) 777KZ17" << endl << "3) VK" << endl;
			cout << "4) Mercedes" << endl << "5) c++" << endl << "6) INSTAGRAMM" << endl;
			cout << "7) 13 Region " << endl;
			cin >> sel;
			if (sel >= 1 && sel <= 7) {
				for (int i = 1; i <= 7; i++) {
					if (sel == i) return i;
				}
			}
		}
	}
	int numLike(int nl) {
		int cnt = 0;
		for (int i = 0; i < likes.size(); i++) {
			if (likes[i].getID() == nl) {
				cnt++;
			}
		}
		return cnt;
	}
	void like(int idPost, int idOwner) {
		bool t = false;
		for (int i = 0; i < likes.size(); i++) {
			if (likes[i].getID() == idPost && likes[i].getNumLike() == idOwner) {
				t = true;
				break;
			}
		}
		if (t == false) {
			Like l;
			l.setID(idPost);
			l.setNum(idOwner);
			likes.push_back(l);
		}
	}
	~WebSite() {
		OFstream(name, users, posts, comments, likes);
	}
};