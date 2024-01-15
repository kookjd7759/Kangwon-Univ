#include <iomanip>
#include <windows.h>
#include <conio.h>

#include "DBManager.h"

using namespace std;

int NowSeletedContact = 1;
int Who; // -1 = 관리자, (Who > 0) = 고객 index
bool IsOn = true;

void gotoxy(int x, int y) { //x, y 좌표로 커서 이동
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
		cout << "\n Find_Customer 오류. ver에 알맞은 text가 입력되지 않음. \n";

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
		cout << "\n Find_Video 오류. ver에 알맞은 text가 입력되지 않음. \n";
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
	string Menu[5] = { "[관리자 로그인]", "[사용자 로그인]", "[회원가입]", "[회원탈퇴]", "[종료]"};

	pair<string, string> ROOTInFo;
	ROOTInFo = LoadROOTInFo();

	while (true) {
		cout << " - 비디오 대여 프로그램 - [202024029 국동균] " << "\n\n";
		ShowMenuList(Menu, 5, num);

		ans = _getch();
		
		if (ans == 224) { // 화살표 방향중 하나를 눌렀을때
			ans = _getch();
			switch (ans) {
				case 75: { // 왼쪽
					if (num > 1)
						num--;
					break;
				}
				case 77: { // 오른쪽
					if (num < 5)
						num++;
					break;
				}
				default: break;
			}
		}
		else if (ans == 13) { // 엔터 눌렀을때
			switch (num) {
				case 1: { // [관리자 로그인]
					{
						cout << "┌───────────────────────────┐ \n";
						cout << "│ ID :                      │ \n";
						cout << "└───────────────────────────┘ \n";
						cout << "┌───────────────────────────┐ \n";
						cout << "│ PassWord :                │ \n";
						cout << "└───────────────────────────┘ \n";
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
						cout << "\n 아이디 또는 비밀번호가 올바르지 않습니다. \n";
						Sleep(1500);
					}
					break;
				}
				case 2: { // [사용자 로그인]
					{
						cout << "┌───────────────────────────┐ \n";
						cout << "│ ID :                      │ \n";
						cout << "└───────────────────────────┘ \n";
						cout << "┌───────────────────────────┐ \n";
						cout << "│ PassWord :                │ \n";
						cout << "└───────────────────────────┘ \n";
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
						cout << "\n 아이디 또는 비밀번호가 올바르지 않습니다. \n";
						Sleep(1500);
					}
					break;
				}
				case 3: { // [회원가입]
					system("cls");
					Customer customer;
					cout << " - 회원가입 - [202024029 국동균] " << "\n\n";
					cout << " 이름 : "; cin >> customer.name;
					cout << " ID : "; string ID; cin >> ID;
					if (Find_Customer(vec_customer, ID, "ID") == -1) {
						customer.ID = ID;
						cout << " PassWord : "; cin >> customer.Password;
						vec_customer.push_back(customer);
						cout << " 회원가입이 완료되었습니다. \n";
					}
					else 
						cout << " 이미 존재하는 아이디입니다. \n";
					Sleep(1500);
					break;
				}
				case 4: { // [회원탈퇴]
					system("cls");
					int index;
					string name;
					cout << " - 회원탈퇴 - [202024029 국동균] " << "\n\n";
					cout << " 이름 : "; cin >> name;
					index = Find_Customer(vec_customer, name, "name");
					if (index == -1) 
						cout << " 입력하신 이름을 가진 고객을 찾지 못했습니다. \n";
					else {
						cout << " ID와 PassWord를 입력하시오. \n";
						cout << " ID : ";
						string ID; cin >> ID;
						cout << " PassWord : ";
						string Pass; cin >> Pass;
						bool OnIt = false;
						for (int i = index; i < vec_customer.size(); i++) {
							if (vec_customer.at(i).name == name && vec_customer.at(i).ID == ID && vec_customer.at(i).Password == Pass) {
								if (Find_Video(vec_video, vec_customer.at(i).ID, "ID") == -1) {
									vec_customer.erase(vec_customer.begin() + i);
									cout << " 회원탈퇴 처리가 완료되었습니다. \n";
								}
								else
									cout << " 대여중인 비디오가 있어 탈퇴가 불가능 합니다. \n";
								OnIt = true;
								break;
							}
						}

						if (!OnIt) 
							cout << " ID 또는 PassWord를 잘못 입력하셨습니다. 회원 탈퇴 처리가 취소됩니다. ";
							
					}
					Sleep(1500);
					break;
				}
				case 5: { // [종료]
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
	string menu[6] = { "[전체 비디오]", "[대여 가능한 비디오]", "[고객]", "[비디오 입고]", "[비디오 폐기]", "[로그아웃]" };
	int ans, temp = 1;
	bool IsSearch = false;

	while (true) {
		if (NowSeletedContact != -1)
			temp = NowSeletedContact;

		system("cls");
		cout << " - 비디오 대여 프로그램 [관리자 _ root] - [202024029 국동균] \n\n";

		ShowMenuList(menu, 6, temp);

		if (NowSeletedContact >= -1 && NowSeletedContact <= 3) { // 검색이 필요한 메뉴에 커서가 가 있을때
			if (NowSeletedContact == -1)
				SeletedContactColor(true);

			cout << "\n[ 검색 ]";

			if (NowSeletedContact == -1)
				SeletedContactColor(false);
		}

		switch (NowSeletedContact) { // 목록 출력 [전체 비디오], [대여 가능한 비디오], [고객]
			case 1: { // [전체 비디오]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|" <<
					left << setw(14) << "대여 가능 유무" << " |\n";

				for (int i = 0; i < vec_video.size(); i++) {
					cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_video.at(i).name << "|";

					if (vec_video.at(i).Customer_ID == "(None)")
						cout << left << setw(14) << "대여 가능" << " |\n";
					else {
						cout << left << setw(14) << "대여 불가" << " | ";
						cout << vec_customer.at(Find_Customer(vec_customer, vec_video.at(i).Customer_ID, "ID")).name << "(이)가 대여 중" << "\n";
					}
				}

				break;
			}
			case 2: { // [대여 가능한 비디오]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|\n";
				
				for (int i = 0; i < vec_video.size(); i++)
					if (vec_video.at(i).Customer_ID == "(None)")
						cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_video.at(i).name << "|\n";

				break;
			}
			case 3: { // [고객]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "고객 이름" << "|"
					<< left << setw(14) << "아이디" << " |" << left << setw(15) << "비밀번호" << " |\n";

				for (int i = 0; i < vec_customer.size(); i++)
					cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_customer.at(i).name << "|"
					<< left << setw(14) << vec_customer.at(i).ID << " |" << left << setw(15) << vec_customer.at(i).Password << " |\n";

				break;
			}
			default:
				break;
		}

		ans = _getch();

		if (ans == 224) { // 화살표 방향중 하나를 눌렀을때
			ans = _getch();
			switch (ans) {
				case 72: { // 위쪽
					if (NowSeletedContact == -1)
						NowSeletedContact = temp;
					break;
				}
				case 80: { // 아래쪽
					if (NowSeletedContact >= 1 && NowSeletedContact <= 3)
						NowSeletedContact = -1;
					break;
				}
				case 75: { // 왼쪽
					if (NowSeletedContact > 1 && NowSeletedContact != -1)
						NowSeletedContact--;
					break;
				}
				case 77: { // 오른쪽
					if (NowSeletedContact < 6 && NowSeletedContact != -1)
						NowSeletedContact++;
					break;
				}
				default: break;
			}
		}
		else if (ans == 13) { // 엔터
			if (NowSeletedContact == 4) { // [비디오 입고]
				system("cls");
				cout << " - 비디오 입고 - [202024029 국동균] \n\n";
				cout << " 비디오 이름 : "; Video st; cin >> st.name; st.Customer_ID = "(None)";
				int index = Find_Video(vec_video, st.name, "name");
				if (index == -1) {
					vec_video.push_back(st);
					cout << " 비디오 입고를 완료하였습니다.";
					SortVector(vec_video, vec_customer, true); // 비디오 정렬
				}
				else 
					cout << " 이미 존재하는 비디오 입니다.";

				Sleep(1500);
			}
			else if (NowSeletedContact == 5) { // [비디오 폐기]
				system("cls");
				cout << " - 비디오 폐기 - [202024029 국동균] \n\n";
				cout << " 비디오 이름 : "; string st; cin >> st;
				int index = Find_Video(vec_video, st, "name");
				if (index != -1) {
					if (vec_video.at(index).Customer_ID == "(None)") {
						vec_video.erase(vec_video.begin() + index);
						cout << " 비디오 폐기를 완료하였습니다.";
					}
					else
						cout << vec_customer.at(Find_Customer(vec_customer, vec_video.at(index).Customer_ID, "ID")).name << "(이)가 대여중인 비디오입니다. \n";
				}
				else
					cout << " 존재하지 않는 비디오 입니다.";

				Sleep(1500);
			}
			else if (NowSeletedContact == 6) { // [로그아웃]
				Who = NULL;
				system("cls");
				return;
			}
			else if (NowSeletedContact == -1) // [검색]
				IsSearch = true;
		}

		if (IsSearch) { // 검색
			bool find = true;
			int findindex;
			gotoxy(0, 4);
			cout << "[ 검색 :                           ]";
			gotoxy(9, 4);
			string st; cin >> st;
			
			switch (temp) {
				case 1: { // [전체 비디오] 
					findindex = Find_Video(vec_video, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|" <<
						left << setw(14) << "대여 가능 유무" << " |\n";

					if (findindex != -1) {
						cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(findindex).name << "|";

						if (vec_video.at(findindex).Customer_ID == "(None)")
							cout << left << setw(14) << "대여 가능" << " |\n";
						else {
							cout << left << setw(14) << "대여 불가" << " | ";
							cout << vec_customer.at(Find_Customer(vec_customer, vec_video.at(findindex).Customer_ID, "ID")).name << "(이)가 대여 중" << "\n";
						}
					}
					else 
						cout << "( 검색된 비디오를 찾을 수 없습니다. ) \n";

					break;
				}
				case 2: { // [대여 가능한 비디오]
					findindex = Find_Video(vec_video, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|\n";

					if (findindex == -1)
						cout << "( 검색된 비디오를 찾을 수 없습니다. ) \n";
					else if (vec_video.at(findindex).Customer_ID == "(None)")
						cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(findindex).name << "|\n";
					else
						cout << vec_customer.at(Find_Customer(vec_customer, vec_video.at(findindex).Customer_ID, "ID")).name <<
							"(이)가 대여중인 비디오입니다. \n";

					break;
				}
				case 3: { // [고객]
					findindex = Find_Customer(vec_customer, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "고객 이름" << "|"
						<< left << setw(14) << "아이디" << " |" << left << setw(15) << "비밀번호" << " |\n";

					if (findindex == -1) {
						cout << "( 검색된 고객을 찾을 수 없습니다. ) \n";
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
			cout << "\n[확인]";
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
	string menu[6] = { "[전체 비디오]", "[대여 가능한 비디오]", "[고객]", "[비디오 대여]", "[비디오 반납]", "[로그아웃]" };
	int ans, temp = 1;
	bool IsSearch = false;

	while (true) {
		if (NowSeletedContact != -1)
			temp = NowSeletedContact;

		system("cls");
		cout << " - 비디오 대여 프로그램 [사용자 _ " << vec_customer.at(Who).name << "] - [202024029 국동균] \n\n";

		ShowMenuList(menu, 6, temp);

		if ((NowSeletedContact >= -1 && NowSeletedContact <= 3) || NowSeletedContact == 5) { // 검색이 필요한 메뉴에 커서가 가 있을때
			if (NowSeletedContact == -1)
				SeletedContactColor(true);

			if (temp == 5)
				cout << "\n[ 선택 ]";
			else
				cout << "\n[ 검색 ]";

			if (NowSeletedContact == -1)
				SeletedContactColor(false);
		}

		switch (NowSeletedContact) { // 목록 출력 [전체 비디오], [대여 가능한 비디오], [고객], [비디오 반납]
			case 1: { // [전체 비디오]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|" <<
					left << setw(14) << "대여 가능 유무" << " |\n";

				for (int i = 0; i < vec_video.size(); i++) {
					cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_video.at(i).name << "|";

					if (vec_video.at(i).Customer_ID == "(None)")
						cout << left << setw(14) << "대여 가능" << " |\n";
					else {
						cout << left << setw(14) << "대여 불가" << " |\n";
					}
				}

				break;
			}
			case 2: { // [대여 가능한 비디오]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|\n";

				for (int i = 0; i < vec_video.size(); i++)
					if (vec_video.at(i).Customer_ID == "(None)")
						cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_video.at(i).name << "|\n";

				break;
			}
			case 3: { // [고객]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "고객 이름" << "|"
					<< left << setw(14) << "아이디" << " |" << left << setw(15) << "비밀번호" << " |\n";

				for (int i = 0; i < vec_customer.size(); i++)
					cout << left << setw(3) << i + 1 << "|" << left << setw(15) << vec_customer.at(i).name << "|"
					<< left << setw(14) << "(접근 제한)" << " |" << left << setw(15) << "(접근 제한)" << " |\n";

				break;
			}
			case 5: { // [비디오 반납]
				cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|\n";
				int index = Find_Video(vec_video, vec_customer.at(Who).ID, "ID");
				int count = 0;
				if (index == -1)
					cout << " (대여중인 비디오가 없습니다.)";
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

		if (ans == 224) { // 화살표 방향중 하나를 눌렀을때
			ans = _getch();
			switch (ans) {
				case 72: { // 위쪽
					if (NowSeletedContact == -1)
						NowSeletedContact = temp;
					break;
				}
				case 80: { // 아래쪽
					if ((NowSeletedContact >= 1 && NowSeletedContact <= 3) || NowSeletedContact == 5)
						NowSeletedContact = -1;
					break;
				}
				case 75: { // 왼쪽
					if (NowSeletedContact > 1 && NowSeletedContact != -1)
						NowSeletedContact--;
					break;
				}
				case 77: { // 오른쪽
					if (NowSeletedContact < 6 && NowSeletedContact != -1)
						NowSeletedContact++;
					break;
				}
				default: break;
			}
		}
		else if (ans == 13) { // 엔터
			if (NowSeletedContact == 4) { // [비디오 대여]
				system("cls");
				cout << " - 비디오 대여 - [202024029 국동균] \n\n";
				cout << " 비디오 이름 : "; string st; cin >> st;
				int index = Find_Video(vec_video, st, "name");
				if (index != -1) {
					if (vec_video.at(index).Customer_ID == "(None)") {
						vec_video.at(index).Customer_ID = vec_customer.at(Who).ID;
						cout << " 대여를 완료했습니다.";
					}
					else 
						cout << " 다른 사람이 대여중으로, 대여가 불가능한 비디오 입니다.";
				}
				else
					cout << " 존재하지 않는 비디오 입니다.";

				Sleep(1500);
			}
			else if (NowSeletedContact == 6) { // [로그아웃]
				Who = NULL;
				system("cls");
				return;
			}
			else if (NowSeletedContact == -1) // [검색]
				IsSearch = true;
		}

		if (IsSearch) {
			bool find = false;
			int findindex;
			gotoxy(0, 4);

			if (temp == 5)
				cout << "[ 선택 :                           ]";
			else
				cout << "[ 검색 :                           ]";

			gotoxy(9, 4);
			string st; cin >> st;

			switch (temp) {
				case 1: { // [전체 비디오] 
					findindex = Find_Video(vec_video, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|" <<
						left << setw(14) << "대여 가능 유무" << " |\n";

					if (findindex != -1) {
						cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(findindex).name << "|";

						if (vec_video.at(findindex).Customer_ID == "(None)")
							cout << left << setw(14) << "대여 가능" << " |\n";
						else 
							cout << left << setw(14) << "대여 불가" << " | ";
					}
					else
						cout << "( 검색된 비디오를 찾을 수 없습니다. ) \n";

					break;
				}
				case 2: { // [대여 가능한 비디오]
					findindex = Find_Video(vec_video, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|\n";

					if (findindex == -1)
						cout << "( 검색된 비디오를 찾을 수 없습니다. ) \n";
					else if (vec_video.at(findindex).Customer_ID == "(None)")
						cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(findindex).name << "|\n";
					else
						cout << "( 다른 고객이 대여중인 비디오입니다. )\n";

					break;
				}
				case 3: { // [고객]
					findindex = Find_Customer(vec_customer, st, "name");
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "고객 이름" << "|"
						<< left << setw(14) << "아이디" << " |" << left << setw(15) << "비밀번호" << " |\n";

					if (findindex == -1) {
						cout << "( 검색된 고객을 찾을 수 없습니다. ) \n";
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
				case 5: { // [비디오 반납]
					cout << "\n" << left << setw(3) << "-" << "|" << left << setw(15) << "비디오 이름" << "|\n";

					int index = Find_Video(vec_video, st, "name");
					if (index != -1) {
						if (vec_video.at(index).Customer_ID == vec_customer.at(Who).ID) {
							cout << left << setw(3) << "-" << "|" << left << setw(15) << vec_video.at(index).name << "|\n";
							vec_video.at(index).Customer_ID = "(None)";
							find = true;
						}
						else
							cout << "( 대여하지 않은 비디오 입니다. ) \n";
					}
					else
						cout << "( 검색한 비디오를 목록에서 찾을 수 없습니다. ) \n";
				}
				default:
					break;
			}

			SeletedContactColor(true);
			cout << "\n[확인]";
			SeletedContactColor(false);

			bool On = true;
			while (On) {
				ans = _getch();
				switch (ans) {
				case 13: {
					On = false;

					if (temp == 5 && find) {
						cout << "\n비디오 반납을 완료하였습니다.";
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
			cout << "\n 변경된 데이터를 저장하는 중 입니다 . . . \n\n";
			break;
		}
	}
	
	Save_Video(vec_video);
	Save_Customer(vec_customer);

	cout << "\n 데이터 저장을 성공적으로 완료하고 프로그램을 종료합니다. \n\n";

	return 0;
}