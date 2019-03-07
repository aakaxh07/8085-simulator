#include "header.h"

int to_int(char ch)
{
	static map<char, int> lookup;
	static bool isFirst = true;
	if(isFirst)
	{
		for(int i = 0; i < 16; ++i)
			lookup["0123456789ABCDEF"[i]] = i;
		isFirst = false;
	}
	return lookup[ch];
}

char to_char(int num)
{
	static map<int, char> lookup;
	static bool isFirst = true;
	if(isFirst)
	{
		for(int i = 0; i < 16; ++i)
			lookup[i] = "0123456789ABCDEF"[i];
		isFirst = false;
	}
	return lookup[num];
}


string to_hex(string bin)
{
	string hex = "";
	int tmp = 0;
	for(int i = 0; i < 4; ++i)
		tmp += (bin[3-i] - '0') * pow(2, i);
	// cout<<to_char(tmp)<<":";
	hex += to_char(tmp);
	tmp = 0;
	for(int i = 0; i < 4; ++i)
		tmp += (bin[7-i] - '0') * pow(2, i);
	// cout<<tmp<<":";
	hex += to_char(tmp);
	return hex;
}

string complement(string hex)
{
	string comp = "";
	for(int i = 0; i < hex.length(); ++i)
		comp += to_char(15 - to_int(hex[i]));
	return comp;
}


 string addition(string hex1, string hex2, bool &AC, bool &CY)
{

	int carry = 0;
	string sum = " ";
	for(int i = 0; i < hex2.length(); ++i)
		sum += " ";
	for(int i = hex2.length() - 1; i > -1; --i)
	{
		int sumDigit = to_int(hex1[i]) + to_int(hex2[i]) + carry;

		if(sumDigit >= 16)
		{
			carry = 1;
			sumDigit -= 16;
		}
		else
			carry = 0;
		sum[i] = to_char(sumDigit);

		if(i == 2)
			AC = (carry == 1)?true:false;
	}
	CY = (carry == 1)?true:false;
	return (sum);
}


string subtraction(string hex1, string hex2, bool &AC, bool &CY, bool sixteen)
{
	bool tmp;
	if(sixteen)
		return (addition(hex1, addition(complement(hex2), "0001", tmp, tmp), AC, CY));
	return (addition(hex1, addition(complement(hex2), "01", tmp, tmp), AC, CY));
}


	 string addprog(string hex1, string hex2)
{
	int carry = 0;
	string sum = "";
	for(int i = 0; i < hex1.length(); ++i)
		sum += " ";
	for(int i = hex1.length() - 1; i > -1; --i)
	{
		int sumDigit = to_int(hex1[i]) + to_int(hex2[i]) + carry;
		if(sumDigit >= 16)
		{
			carry = 1;
			sumDigit -= 16;
		}
		else
			carry = 0;
		sum[i] = to_char(sumDigit);


	}

	return (sum);
}

