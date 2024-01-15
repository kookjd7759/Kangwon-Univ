#include <iomanip>
#include <windows.h>
#include <conio.h>

#include "DBManager.h"

using namespace std;

int NowSeletedContact = 1;
int Who; // -1 = ������, (Who > 0) = �� index
bool IsOn = true;

void gotoxy(int x, int y) { //x, y ��ǥ�� Ŀ�� �̵�
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SeletedContactColor(bool IsOn) {
	if (IsOn)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int Find_Customer(vector<Customer>& vec_customer, string st, string ver) {
	int index = -1;
	if (ver == "name") {
		for (int i = 0; i < vec_customer.size(); i++) {
			if (vec_customer.at(i).name == st) {
				index = i;
				break;
			}
		}
	}
	else if (ver == "ID") {
		for (int i = 0; i < vec_customer.size(); i++) {
			if (vec_customer.at(i).ID == st) {
				index = i;
				break;
			}
		}
	}
	else if (ver == "Pass") {
		for (int i = 0; i < vec_customer.size(); i++) {
			if (vec_customer.at(i).Password == st) {
				index = i;
				break;
			}
		}
	}
	else 
		cout << "\n Find_Customer ����. ver�� �˸��� text�� �Էµ��� ����. \n";

	return index;
}

int Find_Video(vector<Video>& vec_video, string st, string ver) {
	int index = -1;
	if (ver == "name") {
		for (int i = 0; i < vec_video.size(); i++) {
			if (vec_video.at(i).name == st) {
				index = i;
				break;
			}
		}
	}
	else if (ver == "ID"){
		for (int i = 0; i < vec_video.size(); i++) {
			if (vec_video.at(i).Customer_ID == st) {
				index = i;
				break;
			}
		}
	}
	else {
		cout << "\n Find_Video ����. ver�� �˸��� text�� �Էµ��� ����. \n";
	}

	return index;
}

void ShowMenuList(string List[], int ArraySize, int SelectedMenu) {
	for (int i = 0; i < ArraySize; i++) {
		if (SelectedMenu == i + 1)
			SeletedContactColor(true);

		cout << List[i];

		if (SelectedMenu == i + 1)
			SeletedContactColor(false);

		cout << " ";
	}

	cout << "\n";
}

void LogIn(vector<Video>& vec_video, vector<Customer>& vec_customer) {
	int ans, num = 1;
	bool IsFirst = true;
	string Menu[5] = { "[������ �α���]", "[����� �α���]", "[ȸ������]", "[ȸ��Ż��]", "[����]"};

	pair<string, string> ROOTInFo;
	ROOTInFo = LoadROOTInFo();

	while (true) {
		cout << " - ���� �뿩 ���α׷� - [202024029 ������] " << "\n\n";
		ShowMenuList(Menu, 5, num);

		ans = _getch();
		
		if (ans == 224) { // ȭ��ǥ ������ �ϳ��� ��������
			ans = _getch();
			switch (ans) {
				case 75: { // ����
					if (num > 1)
						num--;
					break;
				}
				case 77: { // ������
					if (num < 5)
						num++;
					break;
				}
				default: break;
			}
		}
		else if (ans == 13) { // ���� ��������
			switch (num) {
				case 1: { // [������ �α���]
					{
						cout << "���������������������������������������������������������� \n";
						cout << "�� ID :                      �� \n";
						cout << "���������������������������������������������������������� \n";
						cout << "���������������������������������������������������������� \n";
						cout << "�� PassWord :                �� \n";
						cout << "���������������������������������������������������������� \n";
					}
					gotoxy(7, 4);
					string ID; cin >> ID;
					gotoxy(13, 7);
					string Pass; cin >> Pass;

					if (ID == ROOTInFo.first && Pass == ROOTInFo.second) {
						Who = -1;
						return;
					}
					else {
						cout << "\n ���̵� �Ǵ� ��й�ȣ�� �ùٸ��� �ʽ��ϴ�. \n";
						Sleep(1500);
					}
					break;
				}
				case 2: { // [����� �α���]
					{
						cout << "���������������������������������������������������������� \n";
						cout << "�� ID :                      �� \n";
						cout << "���������������������������������������������������������� \n";
						cout << "���������������������������������������������������������� \n";
						cout << "�� PassWord :                �� \n";
						cout << "���������������������������������������������������������� \n";
					}
					gotoxy(7, 4);
					string ID; cin >> ID;
					gotoxy(13, 7);
					string Pass; cin >> Pass;

					int who = Find_Customer(vec_customer, ID, "ID");
					if (who == Find_Customer(vec_customer, Pass, "Pass") && who != -1) {
						Who = who;
						return;
					}
					else {
						cout << "\n ���̵� �Ǵ� ��й�ȣ�� �ùٸ��� �ʽ��ϴ�. \n";
						Sleep(1500);
					}
					break;
				}
				case 3: { // [ȸ������]
					system("cls");
					Customer customer;
					cout << " - ȸ������ - [202024029 ������] " << "\n\n";
					cout << " �̸� : "; cin >> customer.name;
					cout << " ID : "; string ID; cin >> ID;
					if (Find_Customer(vec_customer, ID, "ID") == -1) {
						customer.ID = ID;
						cout << " PassWord : "; cin >> customer.Password;
						vec_customer.push_back(customer);
						cout << " ȸ�������� �Ϸ�Ǿ����ϴ�. \n";
					}
					else 
						cout << " �̹� �����ϴ� ���̵��Դϴ�. \n";
					Sleep(1500);
					break;
				}
				case 4: { // [ȸ��Ż��]
					system("cls");
					int index;
					string name;
					cout << " - ȸ��Ż�� - [202024029 ������] " << "\n\n";
					cout << " �̸� : "; cin >> name;
					index = Find_Customer(vec_customer, name, "name");
					if (index == -1) 
						cout << " �Է��Ͻ� �̸��� ���� ���� ã�� ���߽��ϴ�. \n";
					else {
						cout << " ID�� PassWord�� �Է��Ͻÿ�. \n";
						cout << " ID : ";
						string ID; cin >> ID;
						cout << " PassWord : ";
						string Pass; cin >> Pass;
						bool OnIt = false;
						for (int i = index; i < vec_customer.size(); i++) {
							if (vec_customer.at(i).name == name && vec_customer.at(i).ID == ID && vec_customer.at(i).Password == Pass) {
								if (Find_Video(vec_video, vec_customer.at(i).ID, "ID") == -1) {
									vec_customer.erase(vec_customer.begin() + i);
									cout << " ȸ��Ż�� ó���� �Ϸ�Ǿ����ϴ�. \n";
								}
								else
									cout << " �뿩���� ������ �־� Ż�� �Ұ��� �մϴ�. \n";
								OnIt = true;
								break;
							}
						}

						if (!OnIt) 
							cout << " ID �Ǵ� PassWord�� �߸� �Է��ϼ̽��ϴ�. ȸ�� Ż�� ó���� ��ҵ˴ϴ�. ";
							
					}
					Sleep(1500);
					break;
				}
				case 5: { // [����]
					IsOn = false;
					return;
				}
				default: break;
			}
		}
		system("cls");
	}
}

void ROOT_MainMenu(vector<Video>& vec_video, vector<Customer>& vec_customer) {
	string menu[6] = { "[��ü ����]", "[�뿩 ������ ����]", "[��]", "[���� �԰�]", "[���� ���]", "[�α׾ƿ�]" };
	int ans, temp = 1;
	bool IsSearch = false;

	while (true) {
		if (NowSeletedContact != -1)
			temp = NowSeletedContact;

		system("cls");
		cout << " - ���� �뿩 ���α׷� [������ _ root] - [202024029 ������] \n\n";

		ShowMenuList(menu, 6, temp);

		if (NowSeletedContact >= -1 && NowSeletedContact <= 3) { // �˻��� �ʿ��� �޴��� Ŀ���� �� ������
			if (NowSeletedContact == -1)
				SeletedContactColor(true);

			cout << "\n[ �˻� ]";

			if (NowSeletedContact == -1)
				SeletedContactColor(false);
		}

		switch (NowSeletedContact) { // ��� ��� [��ü ����], [�뿩 ������ ����], [��]
			case 1: { // [��ü ����]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|" <<
					left << setw(14) << "�뿩 ���� ����" << " |\n";

				for (int i = 0; i < vec_video.size(); i++) {
					cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_video.at(i).name << "|";

					if (vec_video.at(i).Customer_ID == "(None)")
						cout << left << setw(14) << "�뿩 ����" << " |\n";
					else {
						cout << left << setw(14) << "�뿩 �Ұ�" << " | ";
						cout << vec_customer.at(Find_Customer(vec_customer, vec_video.at(i).Customer_ID, "ID")).name << "(��)�� �뿩 ��" << "\n";
					}
				}

				break;
			}
			case 2: { // [�뿩 ������ ����]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|\n";
				
				for (int i = 0; i < vec_video.size(); i++)
					if (vec_video.at(i).Customer_ID == "(None)")
						cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_video.at(i).name << "|\n";

				break;
			}
			case 3: { // [��]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "�� �̸�" << "|"
					<< left << setw(14) << "���̵�" << " |" << left << setw(15) << "��й�ȣ" << " |\n";

				for (int i = 0; i < vec_customer.size(); i++)
					cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_customer.at(i).name << "|"
					<< left << setw(14) << vec_customer.at(i).ID << " |" << left << setw(15) << vec_customer.at(i).Password << " |\n";

				break;
			}
			default:
				break;
		}

		ans = _getch();

		if (ans == 224) { // ȭ��ǥ ������ �ϳ��� ��������
			ans = _getch();
			switch (ans) {
				case 72: { // ����
					if (NowSeletedContact == -1)
						NowSeletedContact = temp;
					break;
				}
				case 80: { // �Ʒ���
					if (NowSeletedContact >= 1 && NowSeletedContact <= 3)
						NowSeletedContact = -1;
					break;
				}
				case 75: { // ����
					if (NowSeletedContact > 1 && NowSeletedContact != -1)
						NowSeletedContact--;
					break;
				}
				case 77: { // ������
					if (NowSeletedContact < 6 && NowSeletedContact != -1)
						NowSeletedContact++;
					break;
				}
				default: break;
			}
		}
		else if (ans == 13) { // ����
			if (NowSeletedContact == 4) { // [���� �԰�]
				system("cls");
				cout << " - ���� �԰� - [202024029 ������] \n\n";
				cout << " ���� �̸� : "; Video st; cin >> st.name; st.Customer_ID = "(None)";
				int index = Find_Video(vec_video, st.name, "name");
				if (index == -1) {
					vec_video.push_back(st);
					cout << " ���� �԰� �Ϸ��Ͽ����ϴ�.";
					SortVector(vec_video, vec_customer, true); // ���� ����
				}
				else 
					cout << " �̹� �����ϴ� ���� �Դϴ�.";

				Sleep(1500);
			}
			else if (NowSeletedContact == 5) { // [���� ���]
				system("cls");
				cout << " - ���� ��� - [202024029 ������] \n\n";
				cout << " ���� �̸� : "; string st; cin >> st;
				int index = Find_Video(vec_video, st, "name");
				if (index != -1) {
					if (vec_video.at(index).Customer_ID == "(None)") {
						vec_video.erase(vec_video.begin() + index);
						cout << " ���� ��⸦ �Ϸ��Ͽ����ϴ�.";
					}
					else
						cout << vec_customer.at(Find_Customer(vec_customer, vec_video.at(index).Customer_ID, "ID")).name << "(��)�� �뿩���� �����Դϴ�. \n";
				}
				else
					cout << " �������� �ʴ� ���� �Դϴ�.";

				Sleep(1500);
			}
			else if (NowSeletedContact == 6) { // [�α׾ƿ�]
				Who = NULL;
				system("cls");
				return;
			}
			else if (NowSeletedContact == -1) // [�˻�]
				IsSearch = true;
		}

		if (IsSearch) { // �˻�
			bool find = true;
			int findindex;
			gotoxy(0, 4);
			cout << "[ �˻� :                           ]";
			gotoxy(9, 4);
			string st; cin >> st;
			
			switch (temp) {
				case 1: { // [��ü ����] 
					findindex = Find_Video(vec_video, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|" <<
						left << setw(14) << "�뿩 ���� ����" << " |\n";

					if (findindex != -1) {
						cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(findindex).name << "|";

						if (vec_video.at(findindex).Customer_ID == "(None)")
							cout << left << setw(14) << "�뿩 ����" << " |\n";
						else {
							cout << left << setw(14) << "�뿩 �Ұ�" << " | ";
							cout << vec_customer.at(Find_Customer(vec_customer, vec_video.at(findindex).Customer_ID, "ID")).name << "(��)�� �뿩 ��" << "\n";
						}
					}
					else 
						cout << "( �˻��� ������ ã�� �� �����ϴ�. ) \n";

					break;
				}
				case 2: { // [�뿩 ������ ����]
					findindex = Find_Video(vec_video, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|\n";

					if (findindex == -1)
						cout << "( �˻��� ������ ã�� �� �����ϴ�. ) \n";
					else if (vec_video.at(findindex).Customer_ID == "(None)")
						cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(findindex).name << "|\n";
					else
						cout << vec_customer.at(Find_Customer(vec_customer, vec_video.at(findindex).Customer_ID, "ID")).name <<
							"(��)�� �뿩���� �����Դϴ�. \n";

					break;
				}
				case 3: { // [��]
					findindex = Find_Customer(vec_customer, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "�� �̸�" << "|"
						<< left << setw(14) << "���̵�" << " |" << left << setw(15) << "��й�ȣ" << " |\n";

					if (findindex == -1) {
						cout << "( �˻��� ���� ã�� �� �����ϴ�. ) \n";
					}
					else {
						for (int i = 0; i < vec_customer.size(); i++) {
							if (vec_customer.at(i).name == st)
								cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_customer.at(i).name << "|"
									<< left << setw(14) << vec_customer.at(i).ID << " |" << left << setw(15) << vec_customer.at(i).Password << " |\n";
						}
					}

					break;
				}
				default:
					break;
			}

			SeletedContactColor(true);
			cout << "\n[Ȯ��]";
			SeletedContactColor(false);

			bool On = true;
			while (On) {
				ans = _getch();
				switch (ans) {
					case 13: {
						On = false;
						break;
					}
					default:
						break;
				}
			}
			IsSearch = false;
		}

		system("cls");
	}
}

void Customer_MainMenu(vector<Video>& vec_video, vector<Customer>& vec_customer) {
	string menu[6] = { "[��ü ����]", "[�뿩 ������ ����]", "[��]", "[���� �뿩]", "[���� �ݳ�]", "[�α׾ƿ�]" };
	int ans, temp = 1;
	bool IsSearch = false;

	while (true) {
		if (NowSeletedContact != -1)
			temp = NowSeletedContact;

		system("cls");
		cout << " - ���� �뿩 ���α׷� [����� _ " << vec_customer.at(Who).name << "] - [202024029 ������] \n\n";

		ShowMenuList(menu, 6, temp);

		if ((NowSeletedContact >= -1 && NowSeletedContact <= 3) || NowSeletedContact == 5) { // �˻��� �ʿ��� �޴��� Ŀ���� �� ������
			if (NowSeletedContact == -1)
				SeletedContactColor(true);

			if (temp == 5)
				cout << "\n[ ���� ]";
			else
				cout << "\n[ �˻� ]";

			if (NowSeletedContact == -1)
				SeletedContactColor(false);
		}

		switch (NowSeletedContact) { // ��� ��� [��ü ����], [�뿩 ������ ����], [��], [���� �ݳ�]
			case 1: { // [��ü ����]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|" <<
					left << setw(14) << "�뿩 ���� ����" << " |\n";

				for (int i = 0; i < vec_video.size(); i++) {
					cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_video.at(i).name << "|";

					if (vec_video.at(i).Customer_ID == "(None)")
						cout << left << setw(14) << "�뿩 ����" << " |\n";
					else {
						cout << left << setw(14) << "�뿩 �Ұ�" << " |\n";
					}
				}

				break;
			}
			case 2: { // [�뿩 ������ ����]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|\n";

				for (int i = 0; i < vec_video.size(); i++)
					if (vec_video.at(i).Customer_ID == "(None)")
						cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_video.at(i).name << "|\n";

				break;
			}
			case 3: { // [��]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "�� �̸�" << "|"
					<< left << setw(14) << "���̵�" << " |" << left << setw(15) << "��й�ȣ" << " |\n";

				for (int i = 0; i < vec_customer.size(); i++)
					cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_customer.at(i).name << "|"
					<< left << setw(14) << "(���� ����)" << " |" << left << setw(15) << "(���� ����)" << " |\n";

				break;
			}
			case 5: { // [���� �ݳ�]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|\n";
				int index = Find_Video(vec_video, vec_customer.at(Who).ID, "ID");
				int count = 0;
				if (index == -1)
					cout << " (�뿩���� ������ �����ϴ�.)";
				else {
					for (int i = 0; i < vec_video.size(); i++)
						if (vec_video.at(i).Customer_ID == vec_customer.at(Who).ID) {
							count++;
							cout << left << setw(3) << count << "|" << left << setw(15) << vec_video.at(i).name << "|\n";
						}
				}
			}
			default:
				break;
		}

		ans = _getch();

		if (ans == 224) { // ȭ��ǥ ������ �ϳ��� ��������
			ans = _getch();
			switch (ans) {
				case 72: { // ����
					if (NowSeletedContact == -1)
						NowSeletedContact = temp;
					break;
				}
				case 80: { // �Ʒ���
					if ((NowSeletedContact >= 1 && NowSeletedContact <= 3) || NowSeletedContact == 5)
						NowSeletedContact = -1;
					break;
				}
				case 75: { // ����
					if (NowSeletedContact > 1 && NowSeletedContact != -1)
						NowSeletedContact--;
					break;
				}
				case 77: { // ������
					if (NowSeletedContact < 6 && NowSeletedContact != -1)
						NowSeletedContact++;
					break;
				}
				default: break;
			}
		}
		else if (ans == 13) { // ����
			if (NowSeletedContact == 4) { // [���� �뿩]
				system("cls");
				cout << " - ���� �뿩 - [202024029 ������] \n\n";
				cout << " ���� �̸� : "; string st; cin >> st;
				int index = Find_Video(vec_video, st, "name");
				if (index != -1) {
					if (vec_video.at(index).Customer_ID == "(None)") {
						vec_video.at(index).Customer_ID = vec_customer.at(Who).ID;
						cout << " �뿩�� �Ϸ��߽��ϴ�.";
					}
					else 
						cout << " �ٸ� ����� �뿩������, �뿩�� �Ұ����� ���� �Դϴ�.";
				}
				else
					cout << " �������� �ʴ� ���� �Դϴ�.";

				Sleep(1500);
			}
			else if (NowSeletedContact == 6) { // [�α׾ƿ�]
				Who = NULL;
				system("cls");
				return;
			}
			else if (NowSeletedContact == -1) // [�˻�]
				IsSearch = true;
		}

		if (IsSearch) {
			bool find = false;
			int findindex;
			gotoxy(0, 4);

			if (temp == 5)
				cout << "[ ���� :                           ]";
			else
				cout << "[ �˻� :                           ]";

			gotoxy(9, 4);
			string st; cin >> st;

			switch (temp) {
				case 1: { // [��ü ����] 
					findindex = Find_Video(vec_video, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|" <<
						left << setw(14) << "�뿩 ���� ����" << " |\n";

					if (findindex != -1) {
						cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(findindex).name << "|";

						if (vec_video.at(findindex).Customer_ID == "(None)")
							cout << left << setw(14) << "�뿩 ����" << " |\n";
						else 
							cout << left << setw(14) << "�뿩 �Ұ�" << " | ";
					}
					else
						cout << "( �˻��� ������ ã�� �� �����ϴ�. ) \n";

					break;
				}
				case 2: { // [�뿩 ������ ����]
					findindex = Find_Video(vec_video, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|\n";

					if (findindex == -1)
						cout << "( �˻��� ������ ã�� �� �����ϴ�. ) \n";
					else if (vec_video.at(findindex).Customer_ID == "(None)")
						cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(findindex).name << "|\n";
					else
						cout << "( �ٸ� ���� �뿩���� �����Դϴ�. )\n";

					break;
				}
				case 3: { // [��]
					findindex = Find_Customer(vec_customer, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "�� �̸�" << "|"
						<< left << setw(14) << "���̵�" << " |" << left << setw(15) << "��й�ȣ" << " |\n";

					if (findindex == -1) {
						cout << "( �˻��� ���� ã�� �� �����ϴ�. ) \n";
					}
					else {
						for (int i = 0; i < vec_customer.size(); i++) {
							if (vec_customer.at(i).name == st)
								cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_customer.at(i).name << "|"
								<< left << setw(14) << vec_customer.at(i).ID << " |" << left << setw(15) << vec_customer.at(i).Password << " |\n";
						}
					}

					break;
				}
				case 5: { // [���� �ݳ�]
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "���� �̸�" << "|\n";

					int index = Find_Video(vec_video, st, "name");
					if (index != -1) {
						if (vec_video.at(index).Customer_ID == vec_customer.at(Who).ID) {
							cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(index).name << "|\n";
							vec_video.at(index).Customer_ID = "(None)";
							find = true;
						}
						else
							cout << "( �뿩���� ���� ���� �Դϴ�. ) \n";
					}
					else
						cout << "( �˻��� ������ ��Ͽ��� ã�� �� �����ϴ�. ) \n";
				}
				default:
					break;
			}

			SeletedContactColor(true);
			cout << "\n[Ȯ��]";
			SeletedContactColor(false);

			bool On = true;
			while (On) {
				ans = _getch();
				switch (ans) {
				case 13: {
					On = false;

					if (temp == 5 && find) {
						cout << "\n���� �ݳ��� �Ϸ��Ͽ����ϴ�.";
						Sleep(1500);
					}
						
					break;
				}
				default:
					break;
				}
			}
			IsSearch = false;
		}

		system("cls");
	}
}

int main() {
	vector<Video> vec_video;
	vector<Customer> vec_customer;
	
	Customer_Load(vec_customer);
	Video_Load(vec_video);
	
	SortVector(vec_video, vec_customer, true); 
	SortVector(vec_video, vec_customer, false);

	while (true) {
		LogIn(vec_video, vec_customer);
		
		if (IsOn) {
			if(Who == -1)
				ROOT_MainMenu(vec_video, vec_customer);
			else
				Customer_MainMenu(vec_video, vec_customer);

			NowSeletedContact = 1;
		}
		else {
			cout << "\n ����� �����͸� �����ϴ� �� �Դϴ� . . . \n\n";
			break;
		}
	}
	
	Save_Video(vec_video);
	Save_Customer(vec_customer);

	cout << "\n ������ ������ ���������� �Ϸ��ϰ� ���α׷��� �����մϴ�. \n\n";

	return 0;
}