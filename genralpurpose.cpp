#include "header.h"
    bool checkchar(char ch){
        switch(ch)
        {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'H':
        case 'L':
        case 'M':
            return true;
            break;
        default:
            cout<<"error"<<endl;
            return false;
        }
    }


     char convertchar(char ch){
     switch(ch)
     {
        case 'A':
            {

                 cout<<"error"<<endl;
                   exit(0);
            }
         case 'B':
            {
                return(ch+1);
            }
         case 'C':
        {
            cout<<"error"<<endl;
            exit(0);
        }
     case 'D':
        {

            return(ch+1);
        }
     case 'E':
        {

           cout<<"error"<<endl;
           exit(0);
        }
     case 'H':
        {

            return('L');
        }
     case 'L':
        {
          cout<<"error"<<endl;
          exit(0);

        }


     }




}

string rec(string newstr)
{
    string word;
    int c=0;
 for(auto x : newstr)
 {
     if(x==EOF)
     {
         break;

     }
     else if(x=='\n')
     {
        break;

     }
     else if(x==' ')
     {
        break;
     }
     word=word+x;
 }

return(word);
}


string convert_upper(string str)
{
	for(int i = 0; i < str.length(); ++i)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
	}
	return str;
}

bool valid_data(string data)
{
	//	Checking on the basis of length
	if(data.length() != 2)
		return false;

	//	Checking the digits of the data
	for(int i = 0; i < 2; ++i)
	{
		switch(data[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				break;
			default:
				return false;
		}
	}
	return true;
}



bool valid_address(string addr)
{
	//	Checking on the basis of length
	if(addr.length() != 4)
		return false;

	//	Checking the digits of the address
	for(int i = 0; i < 4; ++i)
	{
		switch(addr[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				break;
			default:
				return false;
		}
	}
	return true;
}

string setFlags(string hex, bool AC, bool CY)
{
	string bin = "00000000";

	//	Sign flag
	if((hex[0] >= '8' && hex[0] <= '9') || (hex[0] >= 'A' && hex[0] <= 'F'))
		bin[0] = '1';

	//	Zero flag
	if(hex.compare("00") == 0)
		bin[1] = '1';

	//	Auxilary carry flag
	bin[3] = AC?'1':'0';

	//	Parity flag
	for(int i = 0; i < 2; ++i)
	{
		switch(hex[i])
		{
			case '1':
			case '2':
			case '4':
			case '7':
			case '8':
			case 'B':
			case 'D':
			case 'E':
				if(bin[5] == '0')
					bin[5] = '1';
				else if(bin[5] == '1')
					bin[5] = '0';
		}
	}

	//	Carry flag
	bin[7] = CY?'1':'0';

	return to_hex(bin);
}

string hex_bin(string hex)
{
	string bin = "";
	int tmp = to_int(hex[1]), i = 4;
	while(i--)
	{
		bin = to_char(tmp%2) + bin;
		// cout<<bin<<" ";
		tmp /= 2;
	}
	tmp = to_int(hex[0]);
	i = 4;
	while(i--)
	{
		bin = to_char(tmp%2) + bin;
		tmp /= 2;
		// cout<<bin<<" ";
	}
	return bin;
}

bool func(string newstr,param* para)
{
    if(newstr=="MOV")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
    if(newstr=="LXI")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
    if(newstr=="LDA")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="STA")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="LHLD")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="SHLD")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="JMP")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="JC")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="JNC")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="JZ")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="JNZ")
    {
    para->str78=addprog(para->str78,"0003");
     return(true);
    }
     if(newstr=="STAX")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="LDAX")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="XCHG")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="ADD")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="SUB")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="INR")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="INX")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="DCR")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="DCX")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="DAD")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="CMA")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="CMP")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="DAA")
    {
    para->str78=addprog(para->str78,"0001");
     return(true);
    }
     if(newstr=="MVI")
    {
    para->str78=addprog(para->str78,"0002");
     return(true);
    }

}

string func2(string newstr,string temp)
{

    if(newstr=="MOV")
    {
   temp=addprog(temp,"0001");
     return(temp);
    }
    if(newstr=="LXI")
    {
    temp=addprog(temp,"0003");
     return(temp);
    }
    if(newstr=="LDA")
    {
    temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="STA")
    {
    temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="LHLD")
    {
   temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="SHLD")
    {
  temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="JMP")
    {
temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="JC")
    {
   temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="JNC")
    {
   temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="JZ")
    {
   temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="JNZ")
    {
    temp=addprog(temp,"0003");
     return(temp);
    }
     if(newstr=="STAX")
    {
   temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="LDAX")
    {
    temp=addprog(temp,"0001");
    cout<<temp<<endl;
     return(temp);
    }
     if(newstr=="XCHG")
    {
   temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="ADD")
    {
    temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="SUB")
    {
    temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="INR")
    {
  temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="INX")
    {
    temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="DCR")
    {
   temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="DCX")
    {
   temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="DAD")
    {
    temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="CMA")
    {
   temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="CMP")
    {
    temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="DAA")
    {
   temp=addprog(temp,"0001");
     return(temp);
    }
     if(newstr=="MVI")
    {
    temp=addprog(temp,"0002");
     return(temp);
    }

}
bool newfun(char temp)
{
  if(temp=='1')
  {
      return(true);
  }
  else
  {

      return(false);
  }

}

