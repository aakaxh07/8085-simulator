 #include "header.h"
 #include "secondclass.cpp"
 int main(int argc, char **argv)
 {
 secondmethod obj1;
//for storing 1bit instruction
param para;
string word;
int c1=0;
ifstream add;
add.open("C:\\Users\\im_aakash07\\Desktop\\abc\\onebit\\onebits.txt");
if(!add)
    {
        cout<<"Unable to open the file \n";
    }
while(add >> word)
    {

        para.onebit.push_back(word);

        word='\0';
        c1++;

    }

// for 2-bits instruction

string word1;
int c2=0;
ifstream add1;
add1.open("C:\\Users\\im_aakash07\\Desktop\\abc\\twobit\\twobits.txt");
if(!add1)
    {
        cout<<"Unable to open the file \n";
    }
while(add1 >> word1)
    {

        para.secondbit.push_back(word1);

        word1='\0';
        c2++;

    }
// for 3-bit instruction

string word2;
int c3=0;
ifstream add2;
add2.open("C:\\Users\\im_aakash07\\Desktop\\abc\\threebit\\threebits.txt");
if(!add2)
    {
        cout<<"Unable to open the file \n";
    }
while(add2 >> word2)
    {

       para.thirdbit.push_back(word2);

        word2='\0';
        c3++;

    }
//for mapping the register

para.reg['A']="00";
para.reg['B']="00";
para.reg['C']="00";
para.reg['D']="00";
para.reg['E']="00";
para.reg['H']="00";
para.reg['L']="00";
para.reg['F']="00";

//for memory map

bool f3;
 cout<<"enter the starting address "<<endl;
   cin>>para.str77;
   para.str78=para.str77;


   f3=valid_address(para.str77);
   if(f3==false)
   {

       cout<<"INVALID ADDRESS:===>"<<endl;
       exit(0);
   }


//for flag variable
bool sign,zero,AC,parity,CY;


// for input program
ifstream input;
input.open("C:\\Users\\im_aakash07\\Desktop\\abc\\Input\\input2.txt");
if(!input)
    {
        cout<<"Unable to open the file \n";
    }
char str1;
string str2;
str2.clear();




while(!input.eof())
    {
        str1=input.get();
          str2=str2+str1;
         if( (str1==EOF||str1=='\n') )
                     {

                       para.statement.push_back(str2);

                        str2.clear();

                     }


    }


    cout<<"ENTER ADDRESS AND DATA TO BE SET BEFORE EXECUTION: \n";
    while(1){
        string temp,temp2;
        bool f1,f2;
        cout<<"PLEASE ENTER THE ADDRESS OF THE DATA: \n";
        cin>>temp;
        f2=valid_address(temp);
        if(f2==false)
        {
            cout<<"INVALID ADDRESS:==>"<<endl;
        }

        if(temp.length()==4)
        {
            cout<<"PLEASE ENTER THE DATA: \n";
            cin>>temp2;
            temp2=convert_upper(temp2);
            f1=valid_data(temp2);
            if(f1==false)
            {
                cout<<"INVALID DATA:===>"<<endl;
                exit(0);

            }
            para.mapped1[convert_upper(temp)]=convert_upper(temp2);
            temp.clear();
            temp2.clear();

        }
        else if(temp=="./"&&temp.length()==2)
        {
            break;
        }
    }



obj1.method(&para );


return (0);

}






