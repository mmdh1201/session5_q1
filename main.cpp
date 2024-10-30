#include <iostream>
#include "Massage.h"
using namespace std;

int main(){
    int status;
    string ID;
    string username;
    cout << "name: "<<endl;
    cin>>username;
    cout << "ID: "<<endl;
    cin>>ID;
    int sentdate;
    cout<<"enter the date: ";
    cin>>sentdate;
    cout << endl;
    User user1 = User(username,ID);
    BaseMessage** list = new BaseMessage*[10];
    for (int i=0;i<10;i++){

        list[i] = nullptr;
    }   

    cout<<"select operation:\n";
    cout<<"1.simple message"<<endl;
    cout<<"2.post message"<<endl;
    cout<<"3.vote message"<<endl;
    cout<<"4.quiz"<<endl;
    cout<<"5.print messages"<<endl;
    cout<<"0.exite"<<endl;
    cin>>status;
    int index = 0;
    while(status!=0){
        if(status==1){
            string msg;
            cout<<"print your message: ";
            cin>>msg;
            cout<<endl;
            SimpleMessage* s = new SimpleMessage(msg,user1,sentdate);
            
            list[index] = s;
            index ++;
        }
        if(status == 2){
            string URL;
            cout << "insert URL: ";
            cin>>URL;
            cout << endl;
            PostMessage* p = new PostMessage(URL , user1, sentdate);
            list[index] = p;
            index ++;
        }
        if(status == 3){
            string Options[10];
            cout<<"enter your options: "<<endl;
            for (int i=0;i<10;i++){
                cin>>Options[i];
            }
            string vtitle;
            cout << "enter title: ";
            cin>>vtitle;
            cout << endl;
            VoteMessage* v = new VoteMessage(vtitle,Options , user1,sentdate);
            list[index] = v;
            index++;
        }
        if(status == 4){
            string Options[10];
            cout<<"enter your options: "<<endl;
            for (int i=0;i<10;i++){
                cin>>Options[i];
            }
            string vtitle;
            cout << "enter title: ";
            cin>>vtitle;
            cout << endl;
            int an;
            cout<<"enter the right option: ";
            cin >>an;
            quiz* q = new quiz(an,user1,sentdate);
            q->set_attr(vtitle,an,Options);
            q->print_op();
            list[index] = q;
            index++;
        }
        if (status == 5){
            int i=0;
            for(i;;i++){
                if (list[i]==nullptr){
                    break;
                }
                list[i]->printinfo();
            }
        }
        cout<<"select operation:\n";
        cout<<"1.simple message"<<endl;
        cout<<"2.post message"<<endl;
        cout<<"3.vote message"<<endl;
        cout<<"4.quiz"<<endl;
        cout<<"5.print messages"<<endl;
        cout<<"0.exite"<<endl;
        cin>>status;
    }
}