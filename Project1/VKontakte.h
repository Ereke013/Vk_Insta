#pragma once
#include "WebSite.h"


class VKontakte :public WebSite {
public:
	VKontakte(){}
	VKontakte(string name) :WebSite(name) {}

	void homePage() {
		cout << "********************************" << endl;
		cout << "*     |/k      VKontakte       *" << endl;
		cout << "********************************" << endl;
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
			cout << "1) News" << "(" << posts.size() << ")" << endl;
			cout << "2) My posts" << "(" << postNum(posts, ID) << ")" << endl;
			cout << "3) My data" << endl;
			cout << "4) Write post" << endl;
			cout << "5) My friends" << "(" <<  ")" << endl;
			cout << "0) Exit" << endl;
			cin >> sel;
			if (sel == 1) {
				for (int i = 0; i < posts.size(); i++) {
					system("cls");
					homePage();
					cout << "***************************************" << endl;
					cout << "Post owner: " << nameUser(users, posts.at(i).getID_owner()) << endl;
					cout << posts.at(i).getText() << endl << endl;
					if(posts[i].getImage() != 0) showImage(posts[i].getImage());
					cout << "Like: " << numLike(i) << endl;
					cout << posts[i].getTime() << endl;
					cout << "***************************************";
					getTextComment(i, comments, users);
					cout << endl << "***************************************" << endl;
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
				int cnt = 0;
				for (int i = 0; i < posts.size(); i++) {
					system("cls");
					homePage();
					if (ID == posts[i].getID_owner()) {
						cout << endl << "***************************************" << endl;
						cout << users[ID].getName() << ": " << posts[i].getText() << endl << endl;
						showImage(posts[i].getImage());
						cout << "Like: " << numLike(i) << endl;
						cout << "  " << posts[i].getTime() << endl;
						cout << endl << "***************************************";
						getTextComment(i, comments, users);
						cout << endl << "***************************************" << endl;
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
				
			}
			else if (sel == 3) {
				system("cls");
				cout << "ID: " << users[ID].getId() << endl;
				cout << "Name: " << users[ID].getName() << endl;
				cout << "Login: " << users[ID].getLogin() << endl;
				cout << "Role: " << users[ID].getRole() << endl;
				cout << "Date of registration:" << users[ID].getTime() << endl;
				cout << "Exit: ";
				cin >> sel;
			}
			else if (sel == 4) {	
				while (true){
					system("cls");
					string text, g = "'", time;
					int imageNum = 0;
					homePage();
					cout << "Write post!" << endl;
					cin.ignore(); getline(cin, text);
					text += "'";
					g += text;
					cout << "add a photo?" << endl;
					cout << "1) Yes" << endl; 
					cout << "0) No" << endl;
					cin >> sel;
					if (sel == 1) {
						imageNum = choseImage();
					}
					cout << "Post: "<< g << endl;
					if (sel == 1) {
						showImage(imageNum);
					}
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