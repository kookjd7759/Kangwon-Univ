#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Customer {
	string name;
	string ID;
	string Password;
};

struct Video {
	string name;
	string Customer_ID = "(None)";
};

string Encoding(string st);
string Decoding(string st);
pair<string, string> LoadROOTInFo();
void Video_Load(vector<Video>& vec_video);
void Customer_Load(vector<Customer>& vec_customer);
void Save_Video(vector<Video>& vec_video);
void Save_Customer(vector<Customer>& vec_customer);
bool VideoComp(const Video x, const Video y);
bool CustomerComp(const Customer x, const Customer y);
void SortVector(vector<Video>& vec_video, vector<Customer>& vec_customer, bool IsVideoSort);