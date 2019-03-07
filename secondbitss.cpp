#include "header.h"
class secondtype{


public:
    void method5(param* para,string newstr,string word){

     if(newstr=="MVI"&&word.size()==8)
     {
         if(word[3]==' '&&word[5]==' '&& checkchar(word[4]))
         {

                     para->reg[word[4]]=word.substr(6,2);
                      para->mapped1[para->str77]=word.substr(0,5);
                       para->str77=addprog( para->str77,"0001");
                       cout<< para->str77<<endl;
                       cout<< para->mapped1[ para->str77]<<endl;
                         para->mapped1[ para->str77]=word.substr(6,2);
                         para->str77=addprog( para->str77,"0001");
                        cout<< para->str77<<endl;
                        cout<< para->mapped1[ para->str77]<<endl;


         }
     }

    if(newstr=="ADI"&&word.size()==6)
    {
        if(word[3]==' ')
        {
            string address;
            bool AC=0,CY=0;
            address=word.substr(4,2);
            para->mapped1[para->str77]=word.substr(0,3);
            para->str77=addprog( para->str77,"0001");
            para->reg['A']=addition(para->reg['A'],address,AC,CY);
             para->mapped1[para->str77]=word.substr(4,2);
             para->str77=addprog( para->str77,"0001");
             para->reg['F']=setFlags(para->reg['A'],AC,CY);


        }

    }


    if(newstr=="SUI"&&word.size()==6)
    {
        if(word[3]==' ')
        {
            string address;
            bool AC=0,CY=0;
            address=word.substr(4,2);
            para->mapped1[para->str77]=word.substr(0,3);
            para->str77=addprog( para->str77,"0001");
            para->reg['A']=subtraction(para->reg['A'],address,AC,CY,false);
            CY =!CY;
             para->mapped1[para->str77]=word.substr(4,2);
             para->str77=addprog( para->str77,"0001");
             para->reg['F']=setFlags(para->reg['A'],AC,CY);


        }

    }


    }

};


