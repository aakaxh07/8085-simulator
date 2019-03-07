#include "header.h"

class thirdtype{


public:
    void method7(param* para,string newstr,string word){

  if(newstr=="LXI"&&word.size()==10)
      {
          if(word[3]==' '&&word[5]==' '&& checkchar(word[4]))
          {
              if(word[4]=='M'){
                para->reg['H']=word.substr(6,2);
              para->reg['L']=word.substr(8,2);
                para->mapped1[para->str77]=word.substr(0,5);
                para->str77=addprog( para->str77,"0001");
                 para->mapped1[ para->str77]=word.substr(8,2);
                para->str77=addprog( para->str77,"0001");
                para->mapped1[ para->str77]=word.substr(6,2);
                para->str77=addprog( para->str77,"0001");

              }
              else{
              para->reg[word[4]]=word.substr(6,2);
              para->reg[convertchar(word[4])]=word.substr(8,2);
                para->mapped1[para->str77]=word.substr(0,5);
                para->str77=addprog( para->str77,"0001");
                 para->mapped1[ para->str77]=word.substr(8,2);
                para->str77=addprog( para->str77,"0001");
                para->mapped1[ para->str77]=word.substr(6,2);
                para->str77=addprog( para->str77,"0001");

              }
          }
      }
   if(newstr=="LDA"&&word.size()==8)
   {
       if(word[3]==' ')
       {
           string address;
           address=word.substr(4,4);
           para->reg['A']=para->mapped1[address];
           para->mapped1[para->str77]=word.substr(0,3);
            para->str77=addprog( para->str77,"0001");
            para->mapped1[ para->str77]=word.substr(6,2);
            para->str77=addprog( para->str77,"0001");
            para->mapped1[ para->str77]=word.substr(4,2);
            para->str77=addprog( para->str77,"0001");

       }
   }
   if(newstr=="STA"&&word.size()==8)
   {
       if(word[3]==' ')
       {
           string address;
           address=word.substr(4,4);
           para->mapped1[address]=para->reg['A'];
           para->mapped1[para->str77]=word.substr(0,3);
            para->str77=addprog( para->str77,"0001");
            para->mapped1[ para->str77]=word.substr(6,2);
            para->str77=addprog( para->str77,"0001");
            para->mapped1[ para->str77]=word.substr(4,2);
            para->str77=addprog( para->str77,"0001");

       }
   }
   if(newstr=="LHLD"&&word.size()==9)
   {
     if(word[4]==' ')
     {
      string address;
      para->mapped1[para->str77]=word.substr(0,4);
      para->str77=addprog( para->str77,"0001");
      address=word.substr(5,4);
      para->mapped1[para->str77]=address;
      para->str77=addprog( para->str77,"0001");
      para->reg['L']=para->mapped1[address];
      address=addprog(address,"0001");
      para->mapped1[para->str77]=address;
      para->str77=addprog( para->str77,"0001");
      para->reg['H']=para->mapped1[address];


     }
   }

    if(newstr=="SHLD"&&word.size()==9)
   {
     if(word[4]==' ')
     {
      string address;
      para->mapped1[para->str77]=word.substr(0,4);
      para->str77=addprog( para->str77,"0001");
      address=word.substr(5,4);
      para->mapped1[para->str77]=address;
      para->str77=addprog( para->str77,"0001");
      para->mapped1[address]=para->reg['L'];
      address=addprog(address,"0001");
      para->mapped1[para->str77]=address;
      para->str77=addprog( para->str77,"0001");
     para->mapped1[address]= para->reg['H'];


     }
   }
    if(newstr=="JC"&&word.size()==7)
    {
        if(word[2]==' ')
        {
            string address;
            address=hex_bin(para->reg['F']);
           if(address[7]==1)
           {

               para->mapped1[para->str77]=word;
               para->str77=addprog( para->str77,"0003");
               para->str78=word.substr(3,4);
               para->str77=word.substr(3,4);



           }
           else{
             para->mapped1[para->str77]=newstr;
            para->str77=addprog(para->str77,"0003");
           }

        }
    }
        if(newstr=="JNC"&&word.size()==8)
    {
        if(word[3]==' ')
        {
            string address;
            address=hex_bin(para->reg['F']);

           if(address[7]=='0')
           {
               para->mapped1[para->str77]=word;
               para->str77=addprog( para->str77,"0003");
             para->str78=word.substr(4,4);
             para->str77=word.substr(4,4);

              }
           else{

             para->mapped1[para->str77]=newstr;
            para->str77=addprog(para->str77,"0003");
           }

        }
    }

     if(newstr=="JMP"&&word.size()==8)
     {
         if(word[3]==' ')
         {
            para->mapped1[para->str77]=word;
            para->str77=addprog( para->str77,"0003");
             para->str78=word.substr(4,4);
             para->str77=word.substr(4,4);

         }
     }
     if(newstr=="JNZ"&&word.size()==8)
     {
         if(word[3]==' ')
         {
            string address;
            address=hex_bin(para->reg['F']);
            bool t;
            if(address[1]=='0')
            {
            para->mapped1[para->str77]=word;
            para->str77=addprog( para->str77,"0003");
             para->str78=word.substr(4,4);
             para->str77=word.substr(4,4);

            }
            else{

             para->mapped1[para->str77]=newstr;
            para->str77=addprog(para->str77,"0003");
            }

         }

     }
          if(newstr=="JZ"&&word.size()==7)
     {
         if(word[2]==' ')
         {
            string address;
            address=hex_bin(para->reg['F']);

            if(address[1]=='1')
            {
            para->mapped1[para->str77]=word;
            para->str77=addprog( para->str77,"0003");
             para->str78=word.substr(3,4);
             para->str77=word.substr(3,4);

            }
            else{

             para->mapped1[para->str77]=newstr;
            para->str77=addprog(para->str77,"0003");
            }

         }
    }
    }
};

