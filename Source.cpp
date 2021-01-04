#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;


class Kulinary {
protected:
	int howManuSugar;
	int weight;
public:
	Kulinary() {
		howManuSugar = 0;
		weight = 0;
	};
	Kulinary(int w, int w1) {
		howManuSugar = w;
		weight = w1;
	}
	void showData() {
		cout << " ���-�� ������: " << howManuSugar << endl;
		cout << " ���: " << weight << endl;
	}
	void changeSugar(int ptr) {
		howManuSugar = ptr;
	}
	void changeWeight(int ptr) {
		weight = ptr;
	}
	int getSugar() {
		return howManuSugar;
	}
	int getWeight() {
		return weight;
	}
};

class Spec :virtual public Kulinary {
protected:
	string name;
	string type;
public:
	Spec(string ptr1, string ptr2, int w, int w1) :Kulinary(w, w1) {
		name = ptr1;
		type = ptr2;
	}
	Spec() {

	};
	void showData() {
		cout << " ��������: " << name << endl;
		cout << " ���: " << type << endl;
	}
	void changeName(string ptr) {
		name = ptr;
	}
	void changeType(string ptr) {
		type = ptr;
	}
	string getName() {
		return name;
	}
	string getType() {
		return type;
	}
};

class form :virtual public Kulinary {
protected:
	int bornDate;
	int srok;
public:
	form() {
		bornDate = 0;
		srok = 0;
	};
	form(int ptr1, int ptr2, int w, int w1) :Kulinary(w, w1) {
		bornDate = ptr1;
		srok = ptr2;
	}
	void showData() {
		cout << " ���� ������������: " << bornDate << endl;
		cout << " ���-�� ���� ��������: " << srok << endl;
	}
	void changeDate(int ptr) {
		bornDate = ptr;
	}
	void changeSrok(int ptr) {
		srok = ptr;
	}
	int getDate() {
		return bornDate;
	}
	int getSrok() {
		return srok;
	}
};

class Object :public Spec, public form {
private:
	string country;
public:
	Object() {};
	Object(string c, string p, string p1, int ptr1, int ptr2, string ptr3, string ptr4, int w1, int w2) :form(ptr1, ptr2, w1, w2), Spec(ptr3, ptr4, w1, w2), Kulinary(w1, w2) {
		country = c;
	}
	void showDataInf() {
		cout << "	������: " << country << endl;
		Kulinary::showData();
		Spec::showData();
		form::showData();
	}
	void changeCountry(string ptr) {
		country = ptr;
	}
	string getcountry() {
		return country;
	}
};

int chooseMenu();
string writeWords();
int writeNumbers();
int chooseWhoRed(Object*&, int);
int chooseWhatRed(Object*&, int);

int main() {
	setlocale(0, "rus");
	int nObj = 0;
	Object* sweets = new Object[nObj];
	while (true) {
		int choose = chooseMenu();
		if (choose == 1) {
			if (nObj != 0) {
				while (true) {
					int choose1 = chooseWhoRed(sweets, nObj);
					if (choose1 == nObj) break;
					while (true) {
						int choose2 = chooseWhatRed(sweets, choose1);
						if (choose2 == 8) break;
						if (choose2 == 0) {
							cout << "������� ���-�� ������: ";
							int ptr = writeNumbers();
							sweets[choose1].changeSugar(ptr);
							system("cls");
						}
						else
							if (choose2 == 1) {
								cout << "������� ���: ";
								int ptr = writeNumbers();
								sweets[choose1].changeWeight(ptr);
								system("cls");
							}
							else
								if (choose2 == 2) {
									cout << "������� ��������: ";
									string ptr = writeWords();
									sweets[choose1].changeName(ptr);
									system("cls");
								}
								else
									if (choose2 == 3) {
										cout << "������� ���: ";
										string ptr = writeWords();
										sweets[choose1].changeType(ptr);
										system("cls");
									}
									else
										if (choose2 == 4) {
											cout << "������� ��� �������������: ";
											int ptr = writeNumbers();
											sweets[choose1].changeDate(ptr);
											system("cls");
										}
										else
											if (choose2 == 5) {
												cout << "������� ���� ��������: ";
												int ptr = writeNumbers();
												sweets[choose1].changeSrok(ptr);
												system("cls");
											}
											else break;
					}
				}
			}
			else {
				cout << "�� ��� �� �������� ���������" << endl;
				system("pause");
				system("cls");
			}
		}
		else
			if (choose == 0) {
				Object sum;
				cout << "������� ������: ";
				string ptr1 = writeWords();
				sum.changeCountry(ptr1);
				system("cls");
				cout << "������� ���-�� ������: ";
				int ptr = writeNumbers();
				sum.changeSugar(ptr);
				system("cls");
				cout << "������� ���: ";
				ptr = writeNumbers();
				sum.changeWeight(ptr);
				system("cls");
				cout << "������� ��������: ";
				ptr1 = writeWords();
				sum.changeName(ptr1);
				system("cls");
				cout << "������� ���: ";
				ptr1 = writeWords();
				sum.changeType(ptr1);
				system("cls");
				cout << "������� ��� ��������: ";
				ptr = writeNumbers();
				sum.changeDate(ptr);
				system("cls");
				cout << "������� ���� ��������: ";
				ptr = writeNumbers();
				sum.changeSrok(ptr);
				system("cls");
				nObj++;
				Object* ptrr = new Object[nObj];
				for (int i = 0; i < nObj - 1; i++)
					ptrr[i] = sweets[i];
				sweets = ptrr;
				ptrr = NULL;
				delete[]ptrr;
				sweets[nObj - 1] = sum;
			}
			else
				if (choose == 2) {
					for (int i = 0; i < nObj; i++) {
						sweets[i].showDataInf();
						sweets[i].Spec::showData();
						cout << endl;
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) break;
	}
	return 0;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ����� ����: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> �������� ���������" << endl; }
		else { cout << " �������� ���������" << endl; }

		if (choose_menu == 1) { cout << " -> ������������� ���������" << endl; }
		else { cout << " ������������� ���������" << endl; }

		if (choose_menu == 2) { cout << " -> �������� �����" << endl; }
		else { cout << " �������� �����" << endl; }

		if (choose_menu == 3) { cout << " -> ��������� ���������" << endl; }
		else { cout << " ��������� ���������" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseWhoRed(Object*& sweets, int nObj) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ����� ����" << endl;
		choose_menu = (choose_menu + (nObj + 1)) % (nObj + 1);

		for (int i = 0; i < nObj; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << sweets[i].getName() << endl; }
			else { cout << " " << i + 1 << " - " << sweets[i].getName() << endl; }

		if (choose_menu == nObj) { cout << " -> ����� � ������" << endl; }
		else cout << " ����� � ������" << endl;

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int chooseWhatRed(Object*& sweets, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ����� ����" << endl;
		choose_menu = (choose_menu + 7) % 7;

		if (choose_menu == 0) { cout << " -> ���-�� ������: " << sweets[choose].getSugar() << endl; }
		else cout << " ���-�� ������: " << sweets[choose].getSugar() << endl;

		if (choose_menu == 1) { cout << " -> ���: " << sweets[choose].getWeight() << endl; }
		else cout << " ���: " << sweets[choose].getWeight() << endl;

		if (choose_menu == 2) { cout << " -> ��������: " << sweets[choose].getName() << endl; }
		else cout << " ��������: " << sweets[choose].getName() << endl;

		if (choose_menu == 3) { cout << " -> ���: " << sweets[choose].getType() << endl; }
		else cout << " ���: " << sweets[choose].getType() << endl;

		if (choose_menu == 4) { cout << " -> ��� ������������: " << sweets[choose].getDate() << endl; }
		else cout << " ��� ������������: " << sweets[choose].getDate() << endl;

		if (choose_menu == 5) { cout << " -> ���� ��������: " << sweets[choose].getSrok() << endl; }
		else cout << " ���� ��������: " << sweets[choose].getSrok() << endl;

		if (choose_menu == 6) { cout << " -> ����� � ���� ������" << endl; }
		else cout << " ����� � ���� ������" << endl;


		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}
