#ifndef HEADER_H
#define HEADER_H

#include "predefine.h"

struct param
{
	vector<string> statement;
	vector <string> onebit;
	vector <string> secondbit;
	vector <string> thirdbit;
	map<char , string > reg;
	map<string, string >test;
	map<string,string > mapped1;
	string str77;
	string str78;
	string tempp;
	bool ACC,CYY,parityy,signn,zeros;


};

bool checkchar(char );
char convertchar(char );
string rec(string );
int to_int(char );
char to_char(int );
string to_hex(string );
string complement(string );
string addition(string , string , bool &, bool &);
string subtraction(string , string , bool &, bool &, bool );
string addprog(string , string );
string convert_upper(string );
bool valid_address(string );
bool valid_data(string );
string setFlags(string ,bool,bool);
string hex_bin(string );
bool func(string,param *);
string  func2(string,string);
bool newfun(char);
#endif


