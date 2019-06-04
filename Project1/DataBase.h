#pragma once
#include <fstream>
#include "Like.h"
using namespace std;
int pos, com, usr, lik;

bool voity(string log, string pass, vector<User> &users, int &ID) {
	
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getLogin() == log && users[i].getPassword() == pass) {
			ID = i;
			return true;
		}
	}

	return false;
}

void showImage(int num) {
	string avatar;
	if (num == 1) avatar = "IT University.txt";
	else if (num == 2) avatar = "777KZ17.txt";
	else if (num == 3) avatar = "VK.txt";
	else if (num == 4) avatar = "Avatar_mercedes.txt";
	else if (num == 5) avatar = "c++.txt";
	else if (num == 6) avatar = "INSTAGRAMM.txt";
	else if (num == 7) avatar = "13ÐÅÃÈÎÍ.txt";
//	else if (num == 8) avatar = "KZ.txt";
	ifstream fin;
	fin.open(avatar);

	if (fin.is_open()) {
		string str;
		while (!fin.eof()) {
			getline(fin, str);
			cout << str << endl;
		}
	}
	else {
		cout << "Error open file!" << endl;
		system("pause");
		return;
	}
	fin.close();
}

void IFstream(string name, vector<User>& users, vector<Post>&posts, vector<Comment>&comments, vector<Like>&likes) {
	ifstream user, post, comment, like;

	if (name == "vk") {
		user.open("UsersVK.txt");
		post.open("PostsVK.txt");
		comment.open("CommentsVK.txt");
		like.open("LikeVK.txt");
	}
	else {
		user.open("UsersINST.txt");
		post.open("PostsINST.txt");
		comment.open("CommentsINST.txt");
		like.open("LikeINST.txt");
	}

	if (user.is_open() && post.is_open() && comment.is_open() && like.is_open()) {
		string str, time;
		User u;
		Post p;
		Comment c;
		Like l;
		int id;
		while (!user.eof()) {
			user >> str;
			if (str == "") {
				return;
			}
			id = stoi(str,nullptr,10);
			u.setId(id);
			user >> str;
			u.setName(str);
			user >> str;
			u.setLogin(str);
			user >> str;
			u.setPassword(str);
			user >> str;
			u.setRole(str);
			getline(user, str);
			u.setTime(str);
			users.push_back(u);
		}
		usr = users.size();
		str = "";
		while (!post.eof()) {
			post >> str;
			if (str == "") {
				return;
			}
			
			id = stoi(str, nullptr, 10); p.setID_post(id);
			post >> str; id = stoi(str, nullptr, 10); p.setID_owner(id);
			post >> str; id = stoi(str, nullptr, 10); p.setImage(id);
			post >> time; time += " "; post >> str;
			time += str += " "; post >> str;
			time += str += " "; post >> str;
			time += str += " "; post >> str;
			time += str; p.setTime(time);
			getline(post, str); p.setText(str);
			posts.push_back(p);
		}
		pos = posts.size();
		str = "";
		while (!comment.eof()) {
			comment >> str;
			if (str == "") {
				return;
			}
			id = stoi(str, nullptr, 10); 
			c.setID(id);
			comment >> str; 
			id = stoi(str, nullptr, 10); 
			c.setID_post(id);
			comment >> str; 
			id = stoi(str, nullptr, 10); 
			c.setID_commenter(id);
			comment >> time; time += " "; comment >> str;
			time += str += " "; 
			comment >> str;
			time += str += " ";
			comment >> str;
			time += str += " ";
			comment >> str;
			time += str;
			c.setTime(time);
			getline(comment, str);
			c.setText(str);
			comments.push_back(c);
		}
		com = comments.size();
		str = "";
		while (!like.eof()) {
			like >> str;
			if (str == "") return;
			id = stoi(str, nullptr, 10);
			l.setID(id);
			like >> id;
			l.setNum(id);
			likes.push_back(l);
		}
		lik = likes.size();

	}
	else {
		cout << "Error open file!" << endl;
		system("pause");
		return;
	}
	user.close(); post.close(); comment.close();
	system("cls");
}

void OFstream(string name, vector<User> &users, vector<Post> & posts, vector<Comment> &comments, vector<Like> &likes) {
	ofstream user, post, comment, like;
	if (name == "vk") {
		user.open("UsersVK.txt"); post.open("PostsVK.txt"); comment.open("CommentsVK.txt"); like.open("LikeVK.txt"); 
	}
	else {
		user.open("UsersINST.txt"); post.open("PostsINST.txt"); comment.open("CommentsINST.txt"); like.open("LikeINST.txt"); 
	}

	if (user.is_open() && post.is_open() && comment.is_open() && like.is_open()) {
		string str;
		int id;
		for (int i = 0; i < users.size(); i++) {
			str = "";
			str = to_string(users.at(i).getId()) + " ";
			user << str;
			str = users.at(i).getName() + " ";
			user << str;
			str = users.at(i).getLogin() + " ";
			user << str;
			str = users.at(i).getPassword() + " ";
			user << str;
			str = users.at(i).getRole();
			if (i >= usr) str += " ";
			user << str;
			str = users[i].getTime();
			user << str;
			if (i < users.size() - 1) {
				user << endl;
			}
		}
		for (int i = 0; i < posts.size(); i++) {
			str = "";
			str = to_string(posts[i].getID_post()) + " ";
			post << str;
			str = to_string(posts[i].getID_owner()) + " ";
			post << str;
			str = to_string(posts[i].getImage()) + " ";
			post << str;
			str = posts[i].getTime();
			if (i >= pos) str += " ";
			post << str;
			str = posts[i].getText();
			post << str;
			if (i < posts.size() - 1) {
				post << endl;
			}
		}
		for (int i = 0; i < comments.size(); i++) {
			str = "";
			str = to_string(comments[i].getID()) + " ";
			comment << str;
			str = to_string(comments[i].getID_post()) + " ";
			comment << str;
			str = to_string(comments[i].getID_commenter()) + " ";
			comment << str;
			str = comments[i].getTime();
			if (i >= com) str += " ";
			comment << str;
			str = comments[i].getText();
			comment << str;
			if (i < comments.size() - 1) {
				comment << endl;
			}
		}
		for (int i = 0; i < likes.size(); i++) {
			id = likes[i].getID();
			like << id << " ";
			id = likes[i].getNumLike();
			like << id;
			if (i < likes.size() - 1) {
				like << endl;
			}
		}
		}
	else {
		cout << "Error open file!" << endl;
		system("pause");
		return;
	}
	user.close(); post.close(); comment.close();
}