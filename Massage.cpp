#include <iostream>
#include "Massage.h"
#include<string>
using namespace std;
User::User():name(" "),ID(" "){};
User::User(string name , string ID): name(name),ID(ID){}
User::~User(){}

Date::Date():day(0),month(0),year(0){}
Date::Date(int date){
    day = date%100;
    date/=100;
    month = date%100;
    date/=100;
    year = date;
}
Date::~Date(){}

BaseMessage::BaseMessage(){}
BaseMessage::BaseMessage(int D, User U):d(Date(D)),user(U){}
BaseMessage::~BaseMessage(){};

SimpleMessage::SimpleMessage(){}
SimpleMessage::SimpleMessage(string msg, User u, int date):msg(msg){this->setBaseAttr(u,date);}
SimpleMessage::~SimpleMessage(){};

PostMessage::PostMessage(){}
PostMessage::PostMessage(string URL , User u, int date):imgPath(URL){
    this->setBaseAttr(u,date);

}
PostMessage::~PostMessage(){}

VoteMessage::VoteMessage(){}
VoteMessage::VoteMessage(string vtitle, string* opt , User u , int date):Title(vtitle){
    opt = new string[10];
    for (int i=0;i<10;i++){
        opt[i] = options[i];
    }
    this->setBaseAttr(u , date);
}
VoteMessage::~VoteMessage(){}

quiz::quiz(int ans, User u, int date):Ans(ans){this->setBaseAttr(u,date);}
quiz::~quiz(){}


ostream& operator<< (ostream& out, const Date& d){
    out<< d.day <<"/"<<d.month<<"/"<<d.year;
    return out;
}
ostream& operator<< (ostream& out, const User& u){
    out<< u.name <<"\n"<<u.ID<<endl;
    return out;
}

void BaseMessage::printinfo(){
    cout<<d<<endl;
    cout<<user<<endl;
}

void SimpleMessage::setBaseAttr(User u , int date){
    this->d = Date(date);
    this->user = u;
}
void VoteMessage::setBaseAttr(User u , int date){
    this->d = Date(date);
    this->user = u;
}

void User::set_Id(int Id){
    ID = Id;
}
string User::get_Id(){
    return ID;
}
string BaseMessage::get_Id(){
    return user.get_Id();
}

string quiz::answer(int in){
    if (Ans==in){
        return "True";
    }else{
        return "False";
    }
}

void VoteMessage::print_op(){
    for (int i=0; i<10;i++){
        cout << options[i] << endl;
    }
}

void quiz::set_optios(string* Options){
    for (int i=0 ; i<10;i++){
        this->options[i] = Options[i];
    }
}

void quiz::set_attr(string t,int a,string* o){
    this->Ans = a;
    this->Title = t;
    for (int i=0; i<10;i++){
        options[i] = o[i];
    }
}

void SimpleMessage::printinfo(){
    cout << this->msg << endl;
    cout<<d<<endl;
    cout<<user<<endl;
    cout << "---------------------------"<<endl;
}
void PostMessage::printinfo(){
    cout << this->imgPath<<endl;
    cout<<d<<endl;
    cout<<user<<endl;
    cout << "---------------------------"<<endl;
}
void VoteMessage::printinfo(){
    cout << this->Title<<endl;
    for (int i=0;;i++){
        if (this->options[i]!=""){
            cout<<options[i]<<endl;
        }
    }
    cout<<d<<endl;
    cout<<user<<endl;
    cout << "---------------------------"<<endl;
}
void quiz::printinfo(){
    cout << this->Title<<endl;
    for (int i=0;i<10;i++){
        cout<<1<<") "<<options[i]<<endl;
    }
    cout << "The answer is:"<< Ans<<")"<<this->options[this->Ans-1]<<endl;
    // cout<<d<<endl;
    // cout<<user<<endl;
    cout << "---------------------------"<<endl;
}
