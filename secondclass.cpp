#include  "header.h"
#include "onebitss.cpp"
#include "secondbitss.cpp"
#include "thirdbitss.cpp"


class secondmethod
{
     onebitclass obj2;
     secondtype obj3;
      thirdtype obj4;
public:
    void method(param *para){

    string newstr,word;
    bool atf;
    newstr.clear();
   for(int i=0;i<para->statement.size();i++)
    {

      newstr=para->statement[i];
        word=newstr;
        newstr= rec(newstr);
        word=word.substr(0,word.size()-1);
        para->test[para->str78]=word;
        atf=func(newstr,para);
        cout<<para->str78<<endl;


    }
       for(auto it = para->test.cbegin(); it != para->test.cend(); ++it)
{
    cout << it->first << " " << it->second  << "\n";
}
    bool av;
   para->tempp=para->str78;
  cout<<para->tempp<<endl;
  para->str78=para->str77;
   while(para->str78!=para->tempp)
   {
     newstr=para->test[para->str78];
      word=newstr;
    newstr= rec(newstr);

     cout<<para->test[para->str78]<<endl;
     cout<<para->str78<<endl;
     av=func(newstr,para);

          for(int i=0;i<para->onebit.size();i++)
          {

             if(newstr==para->onebit[i])
             {

                obj2.method2(para,newstr,word);

             }

          }
          for(int i=0;i<para->secondbit.size();i++)
          {
             if(newstr==para->secondbit[i])
             {

            obj3.method5(para,newstr,word);
             }

          }
          for(int i=0;i<para->thirdbit.size();i++)
          {

             if(newstr==para->thirdbit[i])
             {


                 obj4.method7(para,newstr,word);
             }
          }
          if(newstr=="HLT"&&word.size()==3)
          {
               para->mapped1[ para->str77]=word;
               break;

          }
   }






    cout<<"\nRegisters:\n";
	cout<<"A: "<<para->reg['A']<<"\t";
	cout<<"B: "<<para->reg['B']<<"\t";
	cout<<"C: "<<para->reg['C']<<"\n";
	cout<<"D: "<<para->reg['D']<<"\t";
	cout<<"E: "<<para->reg['E']<<"\n";
	cout<<"H: "<<para->reg['H']<<"\t";
	cout<<"L: "<<para->reg['L']<<"\n";
	cout<<"\n Flag: \n";
    cout<<"F: "<<para->reg['F']<<"\n";
	string temp;
	temp=hex_bin(para->reg['F']);
	para->signn=newfun(temp[0]);
	para->CYY=newfun(temp[7]);
	para->ACC=newfun(temp[3]);
	para->parityy=newfun(temp[5]);
	para->zeros=newfun(temp[1]);
    cout<<"Sign Flag: "<<para->signn<<"\t";
	cout<<"Zero Flag: "<<para->zeros<<"\n";
	cout<<"AC Flag: "<<para->ACC<<"\t";
	cout<<"parity Flag: "<<para->parityy<<"\n";
	cout<<"Carry Flag: "<<para->CYY<<"\t";




	cout<<"\nMemory:\n";
    for(auto it = para->mapped1.cbegin(); it != para->mapped1.cend(); ++it)
{
    cout << it->first << " " << it->second  << "\n";
}

    }
};


