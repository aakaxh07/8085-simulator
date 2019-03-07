
#include "header.h"


class onebitclass{



public:
    void method2(param* para,string &newstr,string &word){


      string temp;
        if(newstr=="MOV"&&word.size()==8)
        {

          if(word[3]==' '&&word[5]==','&&checkchar(word[4])&&checkchar(word[7]))
          {
              if(word[7]=='M')
              {
                  string address=para->reg['H']+para->reg['L'];
                  para->reg[word[4]]=para->mapped1[address];

              }
              else{
            para->reg[word[4]]=para->reg[word[7]];
              }
           para->mapped1[ para->str77]=word;
           para->str77=addprog( para->str77,"0001");


          }


        }

        if(newstr=="ADD"&&word.size()==5)
          {
                string temp;
                bool AC=0, CY=0;
              if(word[4]=='M'&&word[3]==' '){

                 temp=para->reg['H']+para->reg['L'];
                para->reg['A']=addition( para->reg['A'],para->mapped1[temp],AC,CY);

              }
              else if(word[3]==' '&&checkchar(word[4]))
              {

                 temp=addition( para->reg['A'],para->reg[word[4]],AC,CY);
                 para->reg['A']=temp;
                }
               para->mapped1[ para->str77]=word;
              para->str77=addprog( para->str77,"0001");
             para->reg['F']=setFlags( para->reg['A'],AC,CY);
          }
          if(newstr=="SUB"&&word.size()==5)
          {
              string temp;
                bool AC=0, CY=0;
           if(word[3]==' '&&word[4]=='M')
           {

            temp=para->reg['H']+para->reg['L'];
             para->reg['A']=subtraction( para->reg['A'],para->mapped1[temp], AC, CY,false);
           }
             else if(word[3]==' '&&checkchar(word[4]))
              {

             para->reg['A']=subtraction( para->reg['A'], para->reg[word[4]], AC, CY,false);

              }
              para->mapped1[ para->str77]=word;
             para->str77=addprog( para->str77,"0001");
             para->reg['F']=setFlags(para->reg['A'],AC,CY);
          }
          if(newstr=="STAX"&&word.size()==6)
          {
              if(word[4]==' ' &&checkchar(word[5]))
              {
                  if(word[5]=='M')
                  {
                  bool AC=0,CY=0;
                  string temp= para->reg['H']+ para->reg['L'];
                  para->mapped1[temp]=para->reg['A'];

                  }
                  else{
                     bool AC=0,CY=0;
                  string temp= para->reg[word[5]]+ para->reg[convertchar(word[5])];
                  para->mapped1[temp]=para->reg['A'];

                  }
                      para->mapped1[ para->str77]=word;
                  para->str77=addprog( para->str77,"0001");

              }
          }

            if(newstr=="LDAX"&&word.size()==6)
          {
              if(word[4]==' ' &&checkchar(word[5]))
              {
                            string address;
                            if(word[5] == 'B')
                                {
                                address = para->reg['B'] + para->reg['C'];
                                }
                                else if(word[5] == 'D'){
                                address = para->reg['D'] + para->reg['E'];
                                }
                                else if(word[5] == 'H'){
                                address = para->reg['H'] + para->reg['L'];
                                }

                                para->reg['A']=para->mapped1[address];
                                para->mapped1[ para->str77]=word;
                                para->str77=addprog( para->str77,"0001");



              }
          }
           if(newstr=="XCHG"&&word.size()==4)
          {
               temp= para->reg['H'];
                para->reg['H']= para->reg['D'];
                para->reg['D']=temp;
               temp= para->reg['L'];
                para->reg['L']= para->reg['E'];
                para->reg['E']=temp;
                 para->mapped1[ para->str77]=word;
                 para->str77=addprog( para->str77,"0001");
                cout<< para->str77<<endl;
                cout<< para->mapped1[ para->str77]<<endl;

          }
            if(newstr=="INR"&&word.size()==5)
          {
              if(word[3]==' ' &&checkchar(word[4]))
              {


                  if(word[4]=='M')
                  {
                   bool AC=0,CY=0;
                   string temp=para->reg['H']+para->reg['L'];
                   para->mapped1[temp]=addition( para->mapped1[temp],"01", AC, CY);
                   para->reg['F']=(para->mapped1[temp],AC,CY);
                  }
                  else {
                    bool AC=0,CY=0;
                     para->reg[word[4]]=addition( para->reg[word[4]],"01", AC, CY);
                     para->reg['F']=(para->reg[word[4]],AC,CY);
                  }
                para->mapped1[ para->str77]=word;
                para->str77=addprog( para->str77,"0001");



              }
          }
           if(newstr=="DCR"&&word.size()==5)
          {
              if(word[3]==' ' &&checkchar(word[4]))
              {

                  if(word[4]=='M')
                  {
                    bool AC=0,CY=0;
                    string temp=para->reg['H']+para->reg['L'];
                    para->mapped1[temp]=subtraction(para->mapped1[temp],"01",AC,CY,false);
                    CY=!CY;
                    para->reg['F']=setFlags(para->mapped1[temp],AC,CY);

                  }
                  else{
                 bool AC=0,CY=0;
                para->reg[word[4]]=subtraction( para->reg[word[4]],"01", AC, CY,false);
                CY=!CY;
                para->reg['F']=setFlags(para->reg[word[4]],AC,CY);
                  }

                 para->mapped1[ para->str77]=word;
                para->str77=addprog( para->str77,"0001");


              }
          }
             if(newstr=="DCX"&&word.size()==5)
          {
              if(word[3]==' ' &&checkchar(word[4]))
              {
                  if(word[4]=='M')
                  {
                  bool AC=0,CY=0;
               string data =  para->reg['H']+ para->reg['L'];
               data=subtraction(data,"0001", AC, CY,true);
                para->reg['H']=data.substr(0,2);
                para->reg['L']=data.substr(2,2);
                 para->mapped1[ para->str77]=word;

                 para->str77=addprog( para->str77,"0001");

                  }
                  else{
                     bool AC=0,CY=0;
               string data =  para->reg[word[4]]+ para->reg[convertchar(word[4])];
               data=subtraction(data,"0001", AC, CY,true);
                para->reg[word[4]]=data.substr(0,2);
                para->reg[convertchar(word[4])]=data.substr(2,2);
                 para->mapped1[ para->str77]=word;

                 para->str77=addprog( para->str77,"0001");
                  }
              }
          }
             if(newstr=="INX"&&word.size()==5)
          {
              if(word[3]==' ' &&checkchar(word[4]))
              {
                  if(word[4]=='M'){
               bool AC=0,CY=0;
               string data =  para->reg['H']+ para->reg['L'];
               data=addition(data,"0001", AC, CY);
                para->reg['H']=data.substr(0,2);
                para->reg['L']=data.substr(2,2);
                 para->mapped1[ para->str77]=word;
                para->str77=addprog( para->str77,"0001");


              }
              else{
               bool AC=0,CY=0;
               string data =  para->reg[word[4]]+ para->reg[convertchar(word[4])];
               data=addition(data,"0001", AC, CY);
                para->reg[word[4]]=data.substr(0,2);
                para->reg[convertchar(word[4])]=data.substr(2,2);
                 para->mapped1[ para->str77]=word;
                para->str77=addprog( para->str77,"0001");
                cout<< para->str77<<endl;
                cout<< para->mapped1[ para->str77]<<endl;

              }
          }
          }

           if(newstr=="CMA"&&word.size()==3)
          {
         para->reg['A'] = complement(para->reg['A']);
	     para->mapped1[ para->str77]=word;
         para->str77=addprog( para->str77,"0001");




          }
             if(newstr=="CMP"&&word.size()==5)
          {

           if(word[3]==' '&&checkchar(word[4]))
           {
               string hex;
                bool AC=0,CY=0;
               if(word[3]=='M')
               {

                   string address=para->reg['H']+para->reg['L'];
                   hex=subtraction(para->reg['A'],para->mapped1[address],AC,CY,false);
               }
               else{
                hex=subtraction(para->reg['A'],para->reg[word[4]],AC,CY,false);
               }
               CY=!CY;
               para->reg['F']=setFlags(hex,AC,CY);
                 para->mapped1[ para->str77]=word;
                para->str77=addprog( para->str77,"0001");

           }
          }

           if(newstr=="DAD"&&word.size()==5)
           {
               if(word[3]==' ')
               {
               bool AC,CY;
               string hex1=para->reg['H']+para->reg['L'],hex2;
               if(word[4]=='B')
               {
                hex2=para->reg['B']+para->reg['C'];
                }
                else if(word[4]=='D')
               {
                hex2=para->reg['D']+para->reg['E'];
                }
                else if(word[4]=='H'||word[4]=='M')
               {
                hex2=para->reg['H']+para->reg['L'];
                }
                hex1=addition(hex1,hex2,AC,CY);
                para->reg['H']=hex1.substr(0,2);
                para->reg['L']=hex1.substr(2,2);
                para->reg['F']=setFlags(para->reg['H']+para->reg['L'],AC,CY);
                para->mapped1[para->str77]=word;
                para->str77=addprog(para->str77,"0001");
               }
           }


    }
};

