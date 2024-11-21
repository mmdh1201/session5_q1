#ifndef MASSAGE_H
#define MASSAGE_H
#include <iostream>
#include<iostream>
using namespace std;

class User{
    private:
        string name;
        string ID;
    public:
        friend ostream& operator<<(ostream&, const User&);
        string get_Id();
        void set_Id(int ID);
        User();
        User(string , string);
        ~User();
};


class Date{
    private:
        int day;
        int month;
        int year;
    public:
        friend ostream& operator<<(ostream&, const Date&);
        Date();
        Date(int);
        ~Date();
};


class BaseMessage
{
    protected:
        Date d;
        User user; 
    public:
        string get_Id();
        BaseMessage();
        BaseMessage(int , User);
        ~BaseMessage();
        virtual void printinfo();
};

class SimpleMessage : public BaseMessage
{
    protected:
    string msg;
    public:
    void setBaseAttr(User , int);
    void printinfo();
    SimpleMessage();
    SimpleMessage(string , User, int);
    ~SimpleMessage();
};

class PostMessage : public SimpleMessage
{
    private:
    string imgPath;
    public:
    PostMessage();
    PostMessage(string , User, int);
    void printinfo();
    ~PostMessage();
};

class VoteMessage : public BaseMessage
{
    protected: 
    string Title;
    string options[10];
    public:
    void setBaseAttr(User , int);
    void print_op();
    void printinfo();
    VoteMessage();
    VoteMessage(string , string* , User, int);
    ~VoteMessage();
};

class quiz:public VoteMessage
{
    private:
        int Ans;
    public:
        quiz(int , User, int);
        ~quiz();
        void set_attr(string,int,string*);
        void set_optios(string*);
        void printinfo();
        string answer(int);
};

#endif