#pragma once
#include "WebSite.h"

class Instagram :public WebSite {

public:
	Instagram(){}
	Instagram(string name) :WebSite(name) {}
	
	void homePage() {
		cout << "**********_*********************" << endl;
		cout << "*        |_| INSTAGRAM   (*_*) *" << endl;
		cout << "********************************" << endl;
	}
	void data(vector<User> &users, int ID) {
		setlocale(LC_ALL, "ru");
		cout << "Buisness page :)" << endl;
		cout << "ID: " << users[ID].getId() << endl;
		cout << "Name: " << users[ID].getName() << endl;
		cout << "Login: " << users[ID].getLogin() << endl;
		cout << "Role: " << users[ID].getRole() << endl;
		cout << "Date of registration:" << users[ID].getTime() << endl;
	}
	void home() {
		system("cls");
		homePage();
		WebSite::home();
	}

	void menu(vector<User>& users, vector<Post>& posts, vector<Comment> &comments,  int ID) {
		int sel;
		while (true) {
			system("cls");
			homePage();
			cout << "1) News feed" << "(" << posts.size() << ")" << endl;
			cout << "2) Home" << "(" << postNum(posts, ID) << ")" << endl;
			cout << "3) Add post" << endl;
			cout << "4) My subscribers" << "(" << ")" << endl;
			cout << "5) My subscriptions" << "(" << ")" << endl;
			cout << "0) Exit" << endl;
			cin >> sel;
			if (sel == 1) {
				for (int i = 0; i < posts.size(); i++) {
					system("cls");
					homePage();
					cout << "*********************************************************************" << endl;
					cout << "Post owner: " << nameUser(users, posts.at(i).getID_owner()) << endl;
					cout << posts.at(i).getText() << endl << endl;
					if (posts[i].getImage() != 0) showImage(posts[i].getImage());
					cout << "Like: " << numLike(i) << endl;
					cout << "  " << posts[i].getTime() << endl;
					cout << "*********************************************************************";
					getTextComment(i, comments, users);
					cout << endl << "*************************************************************" << endl;
					cout << "1) Next post" << endl;
					cout << "2) Write comment" << endl;
					cout << "3) Like" << endl;
					cout << "0) Exit" << endl;
					cin >> sel;
					if (sel == 0) {
						break;
					}
					else if (sel == 2) {
						writeComment(comments, ID, i);
						i--;
					}
					else if (sel == 3) {
						like(i, ID);
						i--;
					}
				}
			}
			else if (sel == 2) {
				int cnt = 1;
				bool t = false;
				system("cls");
				data(users, ID);
				for (int i = 0; i < posts.size(); i++) {
					t = true;
					system("cls");
					homePage();
					data(users, ID);
					if (ID == posts[i].getID_owner()) {
						cout << endl << "*************************************************************************" << endl;
						cout << cnt << ") " << posts[i].getText() << endl << endl;
						showImage(posts[i].getImage()); 
						cout << "Like: " << numLike(i) << endl;                        
						cout << "  " << posts[i].getTime() << endl;
						cout << endl << "**************************************************************************";
						getTextComment(i, comments, users);
						cout << endl << "**************************************************************************" << endl;
						cout << "1) Next post" << endl;
						cout << "2) Write comment" << endl;
						cout << "3) Like" << endl;
						cout << "0) Exit" << endl;
						cin >> sel;
						if (sel == 1) {
							cnt++;
						}
						else if (sel == 2) {
							writeComment(comments, ID, i);
							i--;
						}
						else if (sel == 3) {
							like(i, ID);
							i--;
						}
						else return;
					}
				}
				system("pause");
			}
			else if (sel == 3) {
				while (true) {
					system("cls");
					string text, g = "'", time;
					int imageNum = 0;
					homePage();
					cout << "Write post!" << endl;
					cin.ignore();
					getline(cin, text);
					text += "'";
					g += text;
					imageNum = choseImage();
					system("cls");
					cout << "Post: " << g << endl;
					showImage(imageNum);
	
					cout << "Check correctness of datas" << endl;
					cout << "1) All right" << endl;
					cout << "0) Change" << endl;
					cin >> sel;
					if (sel == 1) {
						time = showTime();
						Post p;
						p.setID_post(posts.size());
						p.setID_owner(ID);
						p.setImage(imageNum);
						p.setTime(time);
						p.setText(g);
						posts.push_back(p);
						break;
					}
				}
			}
			else return;
		}
	}
};