#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define pp pair<string, int>
unordered_map<string, pp> opTab;
unordered_map<string, int> regTab;

void initializeregTab(){
	regTab["AREG"] = 1;
	regTab["BREG"] = 2;
	regTab["CREG"] = 3;
	regTab["DREG"] = 4;
}

void initializeopTab(){
	opTab["START"] = {"AD", 01};
	opTab["END"] = {"AD", 02};
	opTab["LTORG"] = {"AD", 03};
	opTab["ORIGIN"] = {"AD", 04};
	opTab["EQU"] = {"AD", 05};
	opTab["ADD"] = {"IS", 01};
	opTab["SUB"] = {"IS", 02};
	opTab["MUL"] = {"IS", 03};
	opTab["DIV"] = {"IS", 04};
	opTab["MOVER"] = {"IS", 05};
	opTab["MOVEM"] = {"IS", 06};
	opTab["DS"] = {"DL", 01};
	opTab["DC"] = {"DL", 02};
}

int main() {
	int lc = 0;
	int sym_tab_ptr = 0;
	int lit_tab_ptr = 0;
	int pool_tb_ptr = 0;
	unordered_map<int, pair<int, int>> symTab;
	unordered_map<int, pair<string, int>> litTab;
	initializeopTab();
	initializeregTab();
	string line;
	ifstream inputFile("input.txt");
	ofstream outFile("intermediate_code.txt");
	if (!inputFile.is_open()) {
		cerr << "Error opening file." << endl;
		return 1;
	}
	while(getline(inputFile, line)){
		stringstream ss(line);
		string token;
		vector<string> tokens;
		while(ss >> token) {
			tokens.push_back(token);
		}
		if(tokens.empty()) continue;
		for(string token : tokens){
			auto it = opTab.find(token);
			if (it != opTab.end()) {
				outFile << it->second.first << " " << it->second.second << endl;
			}
			
		}
		if(tokens[0] == "START") {
			if(tokens[1].empty()) lc = 0;
			else lc = stoi(tokens[1]);
		}
	}
	return 0;
}
