#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

#define Sector_Size 32
#define OneMB_per_BlockNumber 64

enum {
	None_Data = -1,
	EmptyBlock = 0,
	NotEmptyBlock = 1,
	GarbageBlock = 2,
	EmptySector = 0,
	NotEmptySector = 1,
	GarbageSector = 2
};

struct Block { // 1Block = Sector_Size * 512 byte = 16KB
	int Spare = EmptyBlock; // false = Data, true = NULL Data
	char Sector[Sector_Size] = "";
};

struct Sector {
	int Spare = EmptySector; // false = Data, true = NULL Data
	char Data = 0;
};

bool Version; // true = Sector, false = Block
Block* Blockmapping_FlashMemory;
Sector* Sectormapping_FlashMemory;
int* Blockmapping_Table;
int* Sectormapping_Table;
int EmptyBlock_index = 0;
int EmptySector_index = 0;
int MB_Size, WriteCount = 0, ReadCount = 0, EraseCount = 0;

void Print_table() {
	cout << "==== Mapping_Table ==== \n";
	if (Version) // Sector
		for (int i = 0; i < MB_Size * OneMB_per_BlockNumber * Sector_Size; i++)
			cout << i << " " << Sectormapping_Table[i] << "\n";
	else // Block
		for (int i = 0; i < MB_Size * OneMB_per_BlockNumber; i++)
			cout << i << " " << Blockmapping_Table[i] << "\n";

	cout << "======================= \n";
}

void ShowVector() {
	cout << "==== Flash Memory ==== \n";
	if (Version) // Sector
		for (int i = 0; i < MB_Size * OneMB_per_BlockNumber * Sector_Size; i++) {
			cout << "Sector : " << i << "\n";

			if (Sectormapping_FlashMemory[i].Data == 0)
				cout << "0 ";
			else
				cout << Sectormapping_FlashMemory[i].Data << " ";

			cout << "Spare : " << Sectormapping_FlashMemory[i].Spare << "\n";
		}
	else // Block
		for (int i = 0; i < MB_Size * OneMB_per_BlockNumber; i++) {
			cout << "Block : " << i << "\n";
			for (int j = 0; j < Sector_Size; j++) {
				if (Blockmapping_FlashMemory[i].Sector[j] == 0)
					cout << "0 ";
				else
					cout << Blockmapping_FlashMemory[i].Sector[j] << " ";
			}

			cout << " Spare : " << Blockmapping_FlashMemory[i].Spare << "\n";
		}
}

pair<int, int> ConvertToPSN(int LBN) {
	pair<int, int> Block_Ofset = { LBN / Sector_Size, LBN % Sector_Size };
	return Block_Ofset;
}

// Block Function
void Block_ChangeLBN(int LBN);
void Block_Flash_erase();
int Block_Read_Check(int LBN);
int Block_Write_Check(int LBN, int Ofset);
void Block_Flash_read(int LSN);
void Block_Flash_write(int LSN, char data);
void Block_init();

//Sector Function
void Sector_ChangeLSN(int LSN);
void Sector_Flash_erase();
int Sector_Read_Check(int LBN);
int Sector_Write_Check(int LBN);
void Sector_Flash_read(int LSN);
void Sector_Flash_write(int LSN, char data);
void Sector_init();

void InputLoadInFile() {
	cout << "Loading Input.txt \n";

	ifstream file("Input.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			string st = ""; file >> st;

			if (st == "exit") {
				cout << "=== Program Ended, Result === \n";
				cout << "WriteCount : " << WriteCount << "\n";
				cout << "ReadCount : " << ReadCount << "\n";
				cout << "EraseCount : " << EraseCount << "\n";
				break;
			}
			else if (st == "read" || st == "r") {
				int LSN; file >> LSN;
				if (Version)
					Sector_Flash_read(LSN);
				else
					Block_Flash_read(LSN);
			}
			else if (st == "write" || st == "w") {
				int LSN; file >> LSN;
				char Data; file >> Data;
				if (Version)
					Sector_Flash_write(LSN, Data);
				else
					Block_Flash_write(LSN, Data);
			}
			else if (st == "show") {
				ShowVector();
				Print_table();
			}
			else
				cout << "error :: Func() :: string st is invalid. \n";
		}

		file.close();
	}
	else {
		cout << "I can not found File \"Input.txt\" \n";
		exit(0);
	}
}

int main() {
	while (true) {
		cout << "[1] Sector_mapping [2] Block_mapping \n";
		string st; cin >> st;
		if (st == "1") {
			cout << "Sector_mapping Selected. \n";
			Version = true; break;
		}
		else if (st == "2") {
			cout << "Block_mapping Selected. \n";
			Version = false; break;
		}
		else
			cout << "error :: Plz Enter 1 or 2 \n";
	}

	while (true) {
		string st = ""; cin >> st;
		if (st == "init") {
			cin >> MB_Size;

			if (Version)
				Sector_init();
			else
				Block_init();

			break;
		}
		else
			cout << "error :: There are No Blockmapping_FlashMemory, You have to call init Function first. \n";
	}

	clock_t start, end;
	start = clock();
	InputLoadInFile();
	end = clock();
	cout << "Run-Time : " << (clock_t)(end - start) << "ms \n";
	cout << "(위 Run-Time 값은 콘솔창의 텍스트 출력 시간을 포함한다.) \n";

	return 0;
}

// Block Function
void Block_init() {
	int BlockSize = OneMB_per_BlockNumber * MB_Size;
	Blockmapping_FlashMemory = new Block[BlockSize];
	Blockmapping_Table = new int[BlockSize];
	for (int i = 0; i < BlockSize; i++) // Blockmapping_Table 초기화 과정
		Blockmapping_Table[i] = None_Data;

	cout << MB_Size << " megabytes flash memory \;\n";
}

void Block_ChangeLBN(int LBN) {
	Blockmapping_Table[LBN] = EmptyBlock_index;

	int Start_index = EmptyBlock_index;
	bool CallErase = false;
	while (true) {
		EmptyBlock_index++;
		EmptyBlock_index %= OneMB_per_BlockNumber * MB_Size;
		ReadCount++;

		if (Blockmapping_FlashMemory[EmptyBlock_index].Spare == EmptyBlock) {
			if (CallErase)
				Blockmapping_Table[LBN] = EmptyBlock_index;

			break;
		}
		else if (Start_index == EmptyBlock_index) {
			Block_Flash_erase();
			CallErase = true;
		}
	}

	// cout << "EmptyBlock_index : " << EmptyBlock_index << "\n";
}

void Block_Flash_erase() {
	int size = OneMB_per_BlockNumber * MB_Size;
	for (int i = 0; i < size; i++) {
		ReadCount++;

		if (Blockmapping_FlashMemory[i].Spare == GarbageBlock) {
			Blockmapping_FlashMemory[i].Spare = EmptyBlock;

			for (int j = 0; j < Sector_Size; j++)
				Blockmapping_FlashMemory[i].Sector[j] = 0;

			EraseCount++;
		}
	}
}

int Block_Read_Check(int LBN) {
	if (Blockmapping_Table[LBN] == None_Data) // 해당 table에 대한 첫 호출일때
		Block_ChangeLBN(LBN);

	return Blockmapping_Table[LBN];
}

int Block_Write_Check(int LBN, int Ofset) {
	if (Blockmapping_Table[LBN] == None_Data) // 해당 table에 대한 첫 호출일때
		Block_ChangeLBN(LBN);
	else if (Blockmapping_FlashMemory[Blockmapping_Table[LBN]].Sector[Ofset] != 0) {
		Blockmapping_FlashMemory[Blockmapping_Table[LBN]].Spare = GarbageBlock;
		for (int i = 0; i < Sector_Size; i++) { // 다른 EmptyBlock으로 데이터를 옮기는 과정
			if (i != Ofset && Blockmapping_FlashMemory[Blockmapping_Table[LBN]].Sector[i] != 0) {
				Blockmapping_FlashMemory[EmptyBlock_index].Sector[i] = Blockmapping_FlashMemory[Blockmapping_Table[LBN]].Sector[i];
				WriteCount++;
			}
			else
				Blockmapping_FlashMemory[EmptyBlock_index].Sector[i] = 0;
		}

		Block_ChangeLBN(LBN);
	}

	if (Blockmapping_Table[LBN] != None_Data)
		ReadCount++;

	return Blockmapping_Table[LBN];
}

void Block_Flash_read(int LSN) {
	if (ConvertToPSN(LSN).first >= OneMB_per_BlockNumber * MB_Size)
		cout << "error :: That is Inaccessible memory. \n";
	else {
		pair<int, int> Block_Ofset = ConvertToPSN(LSN);
		int LBN = Block_Ofset.first;
		int Ofset = Block_Ofset.second;
		int PBN = Block_Read_Check(LBN);
		char Data = Blockmapping_FlashMemory[PBN].Sector[Ofset];

		if (Data == 0)
			cout << ((PBN * Sector_Size) + Ofset) << " :: There are No Data. \n";
		else
			cout << ((PBN * Sector_Size) + Ofset) << " 의 " << Data << " return. \n";

		ReadCount++;
	}
}

void Block_Flash_write(int LSN, char data) {
	if (ConvertToPSN(LSN).first >= OneMB_per_BlockNumber * MB_Size)
		cout << "error :: That is Inaccessible memory. \n";
	else {
		pair<int, int> Block_Ofset = ConvertToPSN(LSN);
		int LBN = Block_Ofset.first;
		int Ofset = Block_Ofset.second;
		int PBN = Block_Write_Check(LBN, Ofset);

		Blockmapping_FlashMemory[PBN].Sector[Ofset] = data;
		Blockmapping_FlashMemory[PBN].Spare = NotEmptyBlock;
		cout << ((PBN * Sector_Size) + Ofset) << " 에 " << data << " 삽입. \n";

		WriteCount++;
	}
}

// Sector Function
void Sector_init() {
	int SectorSize = OneMB_per_BlockNumber * MB_Size * Sector_Size;
	Sectormapping_FlashMemory = new Sector[SectorSize];
	Sectormapping_Table = new int[SectorSize];
	for (int i = 0; i < SectorSize; i++) // Sectormapping_Table 초기화 과정
		Sectormapping_Table[i] = None_Data;

	cout << MB_Size << " megabytes flash memory ;\n";
}

void Sector_ChangeLSN(int LSN) {
	Sectormapping_Table[LSN] = EmptySector_index;

	int Start_index = EmptySector_index;
	int CallErase = false;
	while (true) {
		EmptySector_index++;
		EmptySector_index %= OneMB_per_BlockNumber * MB_Size * Sector_Size;
		ReadCount++;

		if (Sectormapping_FlashMemory[EmptySector_index].Spare == EmptySector) {
			if (CallErase)
				Sectormapping_Table[LSN] = EmptySector_index;

			break;
		}
		else if (Start_index == EmptySector_index) {
			Sector_Flash_erase();
			CallErase = true;
		}
	}

	// cout << "EmptySector_index : " << EmptySector_index << "\n";
}

void Sector_Flash_erase() {
	int size = OneMB_per_BlockNumber * MB_Size * Sector_Size;
	for (int i = 0; i < size; i++) {
		ReadCount++;
		if (Sectormapping_FlashMemory[i].Spare == GarbageSector) {
			int FirstSectorIndexInBlock = i - (i % Sector_Size);
			for (int j = FirstSectorIndexInBlock; j < FirstSectorIndexInBlock + 32; j++) {
				if (Sectormapping_FlashMemory[i].Spare == GarbageSector) {
					Sectormapping_FlashMemory[i].Spare = EmptySector;
					Sectormapping_FlashMemory[i].Data = 0;
				}
			}

			EraseCount++;
		}
	}
}

int Sector_Read_Check(int LSN) {
	if (Sectormapping_Table[LSN] == None_Data) // 해당 table에 대한 첫 호출일때
		Sector_ChangeLSN(LSN);

	return Sectormapping_Table[LSN];
}

int Sector_Write_Check(int LSN) {
	if (Sectormapping_Table[LSN] == None_Data) // 해당 table에 대한 첫 호출일때
		Sector_ChangeLSN(LSN);
	else if (Sectormapping_FlashMemory[Sectormapping_Table[LSN]].Data != 0) { // 데이터가 이미 존재할때
		Sectormapping_FlashMemory[Sectormapping_Table[LSN]].Spare = GarbageSector;
		Sector_ChangeLSN(LSN);
	}

	if (Sectormapping_Table[LSN] != None_Data)
		ReadCount++;

	return Sectormapping_Table[LSN];
}

void Sector_Flash_read(int LSN) {
	if (LSN >= OneMB_per_BlockNumber * MB_Size * Sector_Size)
		cout << "error :: That is Inaccessible memory. \n";
	else {
		int PSN = Sector_Read_Check(LSN);
		char Data = Sectormapping_FlashMemory[PSN].Data;

		if (Data == 0)
			cout << PSN << " :: There are No Data. \n";
		else
			cout << PSN << " 의 " << Data << " return. \n";

		ReadCount++;
	}
}

void Sector_Flash_write(int LSN, char data) {
	if (LSN >= OneMB_per_BlockNumber * MB_Size * Sector_Size)
		cout << "error :: That is Inaccessible memory. \n";
	else {
		int PSN = Sector_Write_Check(LSN);

		Sectormapping_FlashMemory[PSN].Data = data;
		Sectormapping_FlashMemory[PSN].Spare = NotEmptySector;
		cout << PSN << " 에 " << data << " 삽입. \n";

		WriteCount++;
	}
}