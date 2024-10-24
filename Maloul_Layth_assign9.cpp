// Maloul_Layth_assign9.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


class StockStatRecord {
public:
    string ticker;
    string company_name;
    string price;

    StockStatRecord(string ticker, string company_name, string price) {
        this->ticker = ticker;
        this->company_name = company_name;
        this->price = price;
    }
   
    
  friend ostream& operator <<(ostream& tempobj, const StockStatRecord& get ) {
     tempobj <<  "StockStatRecord(" << get.ticker<<", " << get.company_name <<"$price "<< get.price<<")";
     return tempobj;
    }
  
};

class StocksReader {
public:
    vector<vector<string>> vectorOfLineVectors;
    fstream inputFile;
    string word;
    string filename;
    vector<StockStatRecord> recordVectors;
public:
    StocksReader(string filename) {
        this->filename = filename;
    }
   
    void load() {
       
        inputFile.open(filename);
        if (!inputFile.is_open()) {
            cout << "error";
        }
        getline(inputFile, word);

        while (!inputFile.eof()) {
           getline(inputFile,word);
           rowToVector(word);
         
        }

    }
    void rowToVector(string str) {
        stringstream ss(str);
        string item;
        char delimeter = ',';
        vector<string> stringholder;

        while (getline(ss, item, delimeter)) {
            stringholder.push_back(item);
        }
        vectorOfLineVectors.push_back(stringholder);
    }
   

    void createRecords(){
        string ticker;
        string company_name;
        string price;

        for (int i = 0; i < vectorOfLineVectors.size(); i++) {

    	for (int j = 0; j < vectorOfLineVectors[i].size(); j++) {
    	
            if (j == 0) {
                ticker = vectorOfLineVectors[i][j];
                continue;
            }
            else if (j == 2) {
                company_name = vectorOfLineVectors[i][j];
                continue;
            }
            else if (j == 3) {
                price = vectorOfLineVectors[i][j];
                StockStatRecord temp(ticker, company_name, price);
                recordVectors.push_back(temp);
                break;
            }
    	}
    }

    }
    void printRecords() {
        for (int i = 0; i < recordVectors.size(); i++) {
            cout << recordVectors[i] << endl;
        }
    }

};
int main()
{
    string filename = "StockValuations.csv";

    StocksReader x(filename);
    
    x.load();
    x.createRecords();
    x.printRecords();
}

