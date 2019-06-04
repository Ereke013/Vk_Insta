#include "Instagram.h"
#include "Vkontakte.h"
using namespace std;

class Browser {
	WebSite *website;
public:
	Browser() {}
	void authorization(string name) {
		if (name == "vk") {
			website = new VKontakte(name);
			website->home();
		}
		else {
			website = new Instagram(name);
			website->home();
		}

	}
	~Browser() {
		delete website;
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	Browser br;
	int sel;
	while (true){
		system("cls");
		cout << "\tW E L C O M E   M Y   W E B S I T E (*_*)" << endl;
		cout << "1) www.vk.com" << endl;
		cout << "2) www.instagram.com" << endl;
		cout << "0) Exit" << endl;
		cout << "Выбирайте:";
		cin >> sel;
		if (sel == 1) {
			br.authorization("vk");
		}
		else if (sel == 2) {
			br.authorization("insta");
		}
		else if (sel == 0) {
			break;
		}
	}

	system("pause");
	return 0;
}