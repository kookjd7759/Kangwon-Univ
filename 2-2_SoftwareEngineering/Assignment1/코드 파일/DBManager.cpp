#include "DBManager.h"

int Code[2] = { 1,2 };

pair<string, string> LoadROOTInFo() {
	pair<string, string> ROOTInFo;

	ifstream file("Login.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			string word;

			file >> word;
			ROOTInFo.first = Decoding(word);

			file >> word;
			ROOTInFo.second = Decoding(word);
		}
		file.close();
	}
	else {
		ofstream File("Login.txt");
		File << Encoding("root") << " " << Encoding("0000") << endl;

		ROOTInFo.first = "root";
		ROOTInFo.second = "0000";
	}

	return ROOTInFo;
}

string Encoding(string st) {
	string codest;

	for (int i = 0, a = 0; i < st.size(); i++, a++) {
		if (a == 2)
			a = 0;
		codest.push_back(st.at(i) + Code[a]);
	}

	return codest;
}

string Decoding(string st) {
	string codest;

	for (int i = 0, a = 0; i < st.size(); i++, a++) {
		if (a == 2)
			a = 0;
		codest.push_back(st.at(i) - Code[a]);
	}

	return codest;
}

void Video_Load(vector<Video>& vec_video) {
	cout << "Video_Source.txt를 불러오는 중 입니다.. \n";

	Video video;

	ifstream file("Video_Source.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			string word;

			file >> word;
			video.name = word;

			file >> word;
			video.Customer_ID = Decoding(word);

			if (word != "")
				vec_video.push_back(video);
		}
		file.close();
	}
	else 
		ofstream File("Video_Source.txt");

	system("cls");
}

void Customer_Load(vector<Customer>& vec_customer) {
	cout << "Customer_Source.txt를 불러오는 중 입니다.. \n";

	Customer customer;

	ifstream file("Customer_Source.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			string word;

			file >> word;
			customer.name = word;

			file >> word;
			customer.ID = Decoding(word);

			file >> word;
			customer.Password = Decoding(word);

			if (word != "")
				vec_customer.push_back(customer);
		}
		file.close();
	}
	else
		ofstream File("Customer_Source.txt");

	system("cls");
}

void Save_Video(vector<Video>& vec_video) {
	ofstream File("Video_Source.txt");

	for (int i = 0; i < vec_video.size(); i++) {
		File << vec_video.at(i).name << " " << Encoding(vec_video.at(i).Customer_ID) << endl;
	}
}

void Save_Customer(vector<Customer>& vec_customer) {
	ofstream File("Customer_Source.txt");

	for (int i = 0; i < vec_customer.size(); i++) {
		File << vec_customer.at(i).name << " " << Encoding(vec_customer.at(i).ID) << " " << Encoding(vec_customer.at(i).Password) << endl;
	}
}

bool VideoComp(const Video x, const Video y) {
	return x.name < y.name;
}

bool CustomerComp(const Customer x, const Customer y) {
	return x.name < y.name;
}

void SortVector(vector<Video>& vec_video, vector<Customer>& vec_customer, bool IsVideoSort) {
	if (IsVideoSort)
		sort(vec_video.begin(), vec_video.end(), VideoComp);
	else
		sort(vec_customer.begin(), vec_customer.end(), CustomerComp);
}