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

Phone_node *Add_first_node_phone(Phone_node *first , string Id, string PhoneNumber);

void Print_list_contacts(Contact_node *Cfirst);

void Read_phone(Contact_node *Cfirst);

Contact_node *Search_by_id(Contact_node *first, string Get_id);

void Print_list_phone(Contact_node *Cfirst);

// ? functions 
// ? -----------------------------------------------------------------------------

int main(){
    
    // cout<<"------------------------\n";
    Contact_node *CFirst =NULL;
   
    CFirst = Read_contacts_name(CFirst);
    Read_phone(CFirst);
    Print_list_contacts(CFirst);
    
    return 0;//TODO debug error
}

// ? functions 
// ? -----------------------------------------------------------------------------

// TODO : print list phone with addres contact

void Print_list_phone(Contact_node *Cfirst){
    Phone_node *Pfirst=Cfirst ->pnode;
    // cout<<"Id\t First Name\t Last Name\n";
    while (Pfirst)
    {
        cout<<Pfirst->number<<"\t";
        Pfirst = Pfirst->next;
    }
    cout<<endl;
}

// TODO : read phone from fille 
void Read_phone(Contact_node *Cfirst){
    string h;
    int count=0;
    ifstream f("Contact_phone.txt");
    if(!f) {cout<<"error! :can not open file partner\n"; return ;}
    
    while (getline(f,h)) count++;//get number phone in fille
    f.close();
    
    Contact_node *Current = Cfirst;
    string *Id= new string[count];
    string *Phone = new string[count];

    ifstream Phonefille("Contact_phone.txt");
    count=0;
    // ? error in using heap  
    while (Phonefille>>Id[count]>>Phone[count]) {
        count ++;   
    }//get info from partner fille
    
    for (int i = 0; i < count; i++)
    {
        Current=Search_by_id(Cfirst,Id[i]);
        Phone_node *Pfirst =NULL;
        for (int j = i; j < count; j++)
        {
            if(Id[i]==Id[j] && Id[i] !="0"){
                Pfirst = Add_first_node_phone(Current ->pnode ,Id[i],Phone[j]);
                Current ->pnode = Pfirst;
                Id[j] = "0";
            }
        }
    }
    
    delete Id,Phone;
    Phonefille.close();
}

// TODO : search id in linked list contact and mearge linked list phone 
// ? OK 
Contact_node *Search_by_id(Contact_node *first, string Get_id){

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

void Print_list_contacts(Contact_node *Cfirst){
    int Count=0;
    // cout<<"Id\t First Name\t Last Name\n";
    while (Cfirst)
    {
        cout<<Cfirst<<"\t"<<Cfirst ->id<<" )\t"<<Cfirst->fname<<"\t "<<Cfirst->lname<<endl;
        cout<<"numbers is :";
        Print_list_phone(Cfirst);
        cout<<endl;
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









