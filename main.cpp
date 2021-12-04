#include <iostream>
#include "string.h"
#include <fstream>

using namespace std;

struct Phone_node{
    string id;
    string number;
    Phone_node *next;
};

struct Contact_node{
    string id;
    string fname, lname;
    Phone_node *pnode;
    Contact_node *next;
};

string col[]={"\033[0m","\033[31m","\033[33m","\033[32m","\033[34m"};

void menu();//print menu and switch functions

Contact_node *Read_contacts_name(Contact_node *first);

Contact_node *Add_first_node_contact(Contact_node *first , string Id, string FirstName, string LastName);

Contact_node *Add_first_node_phone(Contact_node *first , string Id, string PhoneNumber);
void Print_list(Contact_node *first);

int main(){

    
    
    // cout<<"------------------------\n";
    Contact_node *first =NULL;
    first = Read_contacts_name(first);
    Print_list(first);
    return 0;
};
Contact_node *Add_first_node_contact(Contact_node *first , string Id, string FirstName, string LastName){

    Contact_node *New_node =new Contact_node;
    
    New_node ->id =Id;
    New_node ->fname=FirstName;
    New_node ->lname =LastName;
    New_node ->next = first;
	
    return New_node;
}

Phone_node *Add_first_node_phone(Phone_node *first , string Id, string PhoneNumber){

    Phone_node *New_node =new Phone_node;
    
    New_node ->id =Id;
    New_node ->number=PhoneNumber;
    New_node ->next = first;
	
    return New_node;
}

void menu(){
    char menu;
    while (true)
    {    
        cout<<"\tMenu\n";
        cout<<"1) add contact\n";
        cout<<"1) showe all contacts\n";
        cout<<"1) edite contact\n";
        cout<<"1) delete contact\n";
        cout<<"1) add phone number to contact\n";
        cout<<"1) delte phone number from contact\n";
        cout<<"1) delete duplicate phone number contact\n";
        cout<<"1) advanced search\n";
        cout<<"1) sorted\n";

        cout<<"-Enter menu code:";
        cin>>menu;

        switch (menu)
        {
        case '1':
            
            break;
        case '2':
            
            break;
        case '3':
            
            break;
        case '4':
            
            break;
        case '5':
            
            break;
        case '6':
            
            break;
        case '7':
            
            break;
        case '8':
            
            break;
        case '9':
            
            break;
                                        
        default:
            cout<<"error !: dont match code menu\n";
            break;
        }
    }
}

Contact_node *Read_contacts_name(Contact_node *first){
    string Id, FirstName, LastName;
    int count=0;
    ifstream Contactfille("Contact_name.txt");
    if(!Contactfille) {cout<<"error! :can not open file partner\n"; return 0;}

    while (Contactfille>>Id>>FirstName>>LastName) {
        first=Add_first_node_contact(first,Id,FirstName,LastName);
        count++;
    }//get info from partner fille
    
    Contactfille.close();
    return first;
}

void Print_list(Contact_node *first){
    int Count=0;
    cout<<"Id\t First Name\t Last Name\n";
    while (first)
    {
        Count++;
        cout<<first ->id<<" )\t"<<first->fname<<"\t "<<first->lname<<endl;
        first = first->next;
    }
}//print linked list










