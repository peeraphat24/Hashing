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
        cout<<"\t====== Hashing ======\n\n";
        cout<<"\t1.) Create hash table\n\t2.) Insert\n\t3.) Print\n\t4.) Find\n\t5.) Remove\n\t6.) Exit\n\n\tEnter Choice : ";
        cin>>choice;
        switch (choice[0])
        {
                int x;
                ////////////////////////////////////CreateHashTable////////////////////////////////////////////////////////////////////////
            case '1' :
                system("clear");
                if(!create){
                    int cell;
                    cout<<"\t====== Create hash table ======\n\n\tEnter size of hash table : ";
                    cin>>cell;
                    if(cell<=30){
                        cout<<"\n\tNext prime of "<<cell<<" is "<<nextPrime(cell)<<"\n\tSize of hash table is "<<nextPrime(cell)<<endl<<endl;
                        
                        a.create(nextPrime(cell));
                        create =!create;
                        
                        system("pause");
                    }
                    else{
                        cout<<"Over 30 please Re Enter size of Hash table"<<endl;
                        system("pause");
                    }
                }
                else
                {
                    cout<<"\n!!!CREATED ALL MODE AVAILABLE!!!\n\n";
                    system("pause");
                }
                
                break;
                ////////////////////////////////////INSERT////////////////////////////////////////////////////////////////////////
            case '2' :
                system("clear");
                if(create)
                {
                    cout<<"\t====== Insert ======\n\n\tEnter element to Insert : ";
                    cin>>x;
                    if(a.find(x)==-999){
                        a.insert(x);
                        cout<<"\n\t!!! INSERT ELEMENT SUCCESSFULL !!!\n";
                    }
                    else cout<<"\n\t!!! Hash table have same element please try again !!!\n";
                    cout<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"\n!!!MUST CREATE TABLE BEFORE INSERT ELEMENT!!!\n\n";
                    system("pause");
                }
                break;
                ////////////////////////////////////PRINT////////////////////////////////////////////////////////////////////////
            case '3' :
                system("clear");
                if(create)
                {
                    cout<<"\t====== Print ======\n\n";
                    a.print();
                    cout<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"\n!!!MUST CREATE TABLE BEFORE PRINT HASH TABLE!!!\n\n";
                    system("pause");
                }
                break;
                
                ////////////////////////////////////FIND////////////////////////////////////////////////////////////////////////
            case '4' :
               system("clear");
                if(create)
                {
                    cout<<"\t====== Find ======\n\n\tEnter Element to Find : ";
                    cin>>x;
                    if(a.findarray(x)==-999)
                        cout<<"\n\t!!! FIND ELEMENT NOT FOUND !!!\n";
                    cout<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"\n!!!MUST CREATE TABLE BEFORE FIND ELEMENT!!!\n\n";
                    system("pause");
                }
                break;
                ////////////////////////////////////REMOVE////////////////////////////////////////////////////////////////////////
            case '5' :
                system("clear");
                if(create)
                {
                    cout<<"\t====== Remove ======\n\n\tEnter Element to Remove : ";
                    cin>>x;
                    if(a.find(x)!=-999){
                        a.remove(x);
                        cout<<"\n\t!!! REMOVE ELEMENT SUCCESSFULL !!!\n";
                    }
                    else cout<<"\n\t!!! HASH TABLE HAVEN'T ELEMEMT PLEASE TRY AGAIN !!!\n";
                    cout<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"\n!!!MUST CREATE TABLE BEFORE REMOVE ELEMENT!!!\n\n";
                    system("pause");
                }
                break;
                
            case '6' :
                exit = false;
                break;
            default : break;
        }
    }while(exit);
    
}


int nextPrime(int size)
{
    int i=2;
    if (size==1) return 1;
    while(size%i!=0) i++;
    
    if(i==size) return i;
    else{
        i=size+1;
        bool check=false;
        while(true){
            for(int j=2;j<=i;j++){
                if(i%j==0&&j<i) break;
                else if(i%j==0&&j==i) check = true;
            }
            if(check) break;
            i++;
        }
        return i;
    }
}
