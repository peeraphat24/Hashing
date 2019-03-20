//
//  main.cpp
//  Hashing
//
//  Created by Peeraphat Komolruchinonth on 20/3/19.
//  Copyright © 2019 Peeraphat Komolruchinonth. All rights reserved.
//

#include "hash.h"
#include<iostream>
#include<string>
int nextPrime(int size);
using namespace std;
int main(){
    HashTable<int> a(-999);
    string choice;
    bool exit = true;
    bool create =false;
    
    do{
        system("clear");
        cout<<"\t Hashing Open Addressing \n\n";
        cout<<"\t1.) CREATE HASH TABLE\n\t2.) INSERT\n\t3.) PRINT\n\t4.) FIND\n\t5.) REMOVE\n\t6.) EXIT\n\n\tEnter Choice : ";
        cin>>choice;
        switch (choice[0])
        {
                int x;
            case '1' :
                system("clear");
                if(!create)
                {
                    int cell;
                    cout<<"\tCREATE TABLE\n\n\tHow many cell : ";
                    cin>>cell;
                    if(cell < nextPrime(30))
                    {
                        cout<<"\n\tNEXT PRIME OF "<<cell<<" IS "<<nextPrime(cell)<<"\n\tSIZE OF HASH TABLE IS "<<nextPrime(cell)<<endl<<endl;
    
                        a.create(nextPrime(cell));
                        create =!create;
                    }
                    else
                    {
                        cout << "IT OVER ARRAY SIZE 30 !"<<endl;
                    }
                    
                    
                    system("pause");
                }
                else
                {
                    cout<<"\nCREATED ALL MODE AVAILABLE\n\n";
                    system("pause");
                }
                
                break;
            case '2' :
                system("clear");
                if(create)
                {
                    cout<<"\tINSERT\n\n\tEnter Element to Insert : ";
                    cin>>x;
                    if(a.find(x) == -999){
                        a.insert(x);
                        cout<<"\n\tINSERT ELEMENT SUCCESSFULL\n";
                    }
                    else cout<<"\n\tHASH TABLE HAVE SAME ELEMEMT PLEASE TRY AGAIN\n";
                    cout<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"\nMUST CREATE TABLE BEFORE INSERT ELEMENT\n\n";
                    system("pause");
                }
                break;
            case '3' :
                system("clear");
                if(create)
                {
                    cout<<"\tPRINT MODE\n\n";
                    a.print();
                    cout<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"\nMUST CREATE TABLE BEFORE PRINT HASH TABLE\n\n";
                    system("pause");
                }
                break;
                
                
            case '4' :
                system("clear");
                if(create)
                {
                    cout<<"\tFIND MODE\n\n\tEnter Element to Find : ";
                    cin>>x;
                    if(a.findarray(x)==-999)
                        cout<<"\n\tFIND ELEMENT NOT FOUND\n";
                    cout<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"\nMUST CREATE TABLE BEFORE FIND ELEMENT\n\n";
                    system("pause");
                }
                break;
            case '5' :
                system("clear");
                if(create)
                {
                    cout<<"\tREMOVE MODE\n\n\tEnter Element to Remove : ";
                    cin>>x;
                    if(a.find(x)!=-999){
                        a.remove(x);
                        cout<<"\n\tREMOVE ELEMENT SUCCESSFULL\n";
                    }
                    else cout<<"\n\tHASH TABLE HAVEN'T ELEMEMT PLEASE TRY AGAIN\n";
                    cout<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"\nMUST CREATE TABLE BEFORE REMOVE ELEMENT\n\n";
                    system("pause");
                }
                break;
                
            case '6' :
                exit = false;
                break;
            default : break;
        }
    }
    while(exit);
}


int nextPrime(int size)
{
    int i = 2;
    if (size==1)
    {
        return 1;
    }
        while(size%i!=0)
        {
            i++;
        }
            if(i==size)
            {
                return i;
            }
    else
    {
        i=size+1;
        bool check=false;
        while(true)
        {
            for(int j=2;j<=i;j++)
            {
                if(i%j==0&&j<i) break;
                else if(i%j==0&&j==i) check = true;
            }
                if(check) break;
                i++;
        }
        return i;
    }
}

