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

// Contact_node **Csave;
// Phone_node **Psave;
// string col[]={"\033[0m","\033[31m","\033[33m","\033[32m","\033[34m"};

bool isDigit(string a);

bool Check_phone(string phone);

void menu();//print menu and switch functions

void Add_contact();

Contact_node *Read_contacts_name(Contact_node *first);

Contact_node *Add_first_node_contact(Contact_node *Cfirst, string Id, string FirstName, string LastName,Phone_node *Pfirst = NULL);

Contact_node *Add_first_node_phone(Contact_node *first , string Id, string PhoneNumber);

void Print_list_contacts(Contact_node *Cfirst, Phone_node *Pfirst=NULL);

void Read_phone(Phone_node *first);

Contact_node *Search_id(Contact_node *first, string Get_id);

// ? functions 
// ? -----------------------------------------------------------------------------

int main(){
    
    // cout<<"------------------------\n";
    Contact_node *CFirst =NULL;
    // Csave = &first;

    CFirst = Read_contacts_name(CFirst);

    Contact_node *search =Search_id(CFirst,"5");
    
    if(search == CFirst) cout<<"not find\n";
    else
        cout<< search ->id <<"\t"<<search ->fname <<"\t"<< search->lname <<"\t"<< search->pnode <<"\t"<< search->next<<endl;
    
    Print_list_contacts(CFirst);
    return 0;
}

// ? functions 
// ? -----------------------------------------------------------------------------

// TODO : read phone from fille 
// ? OK
void Read_phone(Phone_node *first){
    
    int count=0;
    ifstream Phonefille("Contact_name.txt");
    if(!Phonefille) {cout<<"error! :can not open file partner\n"; return ;}
    while (Phonefille)
        count++;
    
    string *Id = new string[count];
    string *Phone = new string[count];

    count=0;
    while (Phonefille>>Id[count]>>Phone[count]) {
        count++;
    }//get info from partner fille
    
    Phonefille.close();
}

// TODO : search id in linked list contact and mearge linked list phone 
// ? OK 
Contact_node *Search_id(Contact_node *first, string Get_id){

    Contact_node *Current = first;
    
    if (!first) return first;

    while (Current){
        if (Current ->id == Get_id)
            return Current;
        else Current = Current ->next;
    }
    return first;// dont find

}

// TODO : add contact
void Add_contact(){



}

bool Check_phone(string phone){
    bool check;
    int phonelength = phone.length();
    if (phone[0] != '+'){ 
        if  ( phonelength != 11){
            cout<<"error! :phone number must 11 length \n";
            return false;
        } 
        if (isDigit(phone))
            if (phone[0] == '0' && phone[1] == '9')
                return true;
            else {
                cout<<"error! :woring phone number\n"; 
                return false;
            }
        else{
            cout <<"error! : your phone number must be 0-9\n";
            return false;
        }
    }else{
        
        string text =phone.substr(1,phonelength);
        if( !(11 < phonelength && phonelength < 15) ){
            cout <<"error! : woring number \n";
            return false;
        }
        else if (isDigit(text)){
            return true;
        }else{
            cout<<"error! : your phone number must be 0-9\n";
            return false;
        } 
    }       
}

Contact_node *Add_first_node_contact(Contact_node *Cfirst , string Id, string FirstName, string LastName, Phone_node *Pfirst ){

    Contact_node *New_node =new Contact_node;
    
    New_node ->id =Id;
    New_node ->fname=FirstName;
    New_node ->lname =LastName;
    New_node ->next = Cfirst;
    New_node ->pnode =Pfirst;
	
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
        cout<<"0) exit\n";
        cout<<"1) add contact\n";
        cout<<"2) showe all contacts\n";
        cout<<"3) edite contact\n";
        cout<<"4) delete contact\n";
        cout<<"5) add phone number to contact\n";
        cout<<"6) delte phone number from contact\n";
        cout<<"7) delete duplicate phone number contact\n";
        cout<<"8) advanced search\n";
        cout<<"9) sorted\n";

        cout<<"-Enter menu code:";
        cin>>menu;

        switch (menu)
        {
        case '0':
            
            break;    
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

void Print_list_contacts(Contact_node *Cfirst, Phone_node *Pfirst){
    int Count=0;
    // cout<<"Id\t First Name\t Last Name\n";
    while (Cfirst)
    {
        Count++;
        cout<<Cfirst<<"\t"<<Cfirst ->id<<" )\t"<<Cfirst->fname<<"\t "<<Cfirst->lname<<endl;
        Cfirst = Cfirst->next;
    }
}//print linked list contacts

bool isDigit(string x){   
    //check to be digit sentence
    x = x + '.';
    int i=0;
    do
    {
        if(!isdigit(x[i]))
            return false;

        i++;
    }while(x[i] != '.');
    return true;
}









