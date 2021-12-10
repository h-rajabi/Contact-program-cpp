#include <iostream>
#include "string.h"
#include <fstream>
// #include <string>

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

Contact_node *Add_contact(Contact_node *Cfirst, int &count);

Contact_node *Read_contacts_name(Contact_node *first, int &count);

Contact_node *Add_first_node_contact(Contact_node *Cfirst, string Id, string FirstName, string LastName,Phone_node *Pfirst = NULL);

Phone_node *Add_first_node_phone(Phone_node *first , string Id, string PhoneNumber);

Contact_node *Add_last_node_contact(Contact_node *Cfirst , string getId, string getFirstName, string getLastName, Phone_node *getPfirst=NULL );

Phone_node *Add_last_node_phone(Phone_node *Pfirst , string getId, string getPhoneNumber);

void Print_list_contacts(Contact_node *Cfirst);

void Read_phone(Contact_node *Cfirst);

Contact_node *Search_by_id(Contact_node *first, string Get_id);

void Print_list_phone(Contact_node *Cfirst, int &count);

void merge_phone_contact(Contact_node *Cfirst, string Id, string PhoneNumber[], int count);

void Write_new_contact_fille(string Id, string Fname, string Lname);

void Write_new_phone_fille(string Id, string Phone[], int count);

Contact_node **Advancedsearch(Contact_node *Cfirst ,string GetText, int &count);

Contact_node *Search_result(Contact_node *Cfirst);

void clear_list(Contact_node *first);

void Write_contacts_fille(Contact_node *first);

void Write_phones_fille(Contact_node *first);

void Edete_contact(Contact_node *first);

// ? functions 
// ? -----------------------------------------------------------------------------

int main(){
    
    Contact_node *CFirst =NULL;
    Phone_node * PFirst = NULL;
    int count = 0;

    CFirst = Read_contacts_name(CFirst,count);
    Read_phone(CFirst);
    Edete_contact(CFirst);
// ? -------------------------------------

    // Print_list_contacts(CFirst);
    // int count2=0 ;
    // Contact_node **search; 
    // search = Advancedsearch(CFirst,"ssein",count2);
    // // ! error in returned arr of struct 
    // cout<<"----------------------------\n";
    // if(!search) cout << "NOT Find\n"; 
    // else 
    //     for (int i = 0; i < 10; i++){
    //         cout<<search[i]->id <<"\t"<<search[i]->fname<<endl;
    //         // cout<<i+1<<") "<<search[i]->fname <<"\t"<<search[i]->lname<<endl;
    //         // Print_list_phone(search[i]);
    //     }
    // clear_list(CFirst);
    
    /*
    Print_list_contacts(CFirst);
    cout<<"------------------------\n";
    CFirst=Add_contact(CFirst , count);
    cout<<"------------------------\n";
    Print_list_contacts(CFirst);
    */
    return 0;//TODO debug error
}

// ? functions 
// ? -----------------------------------------------------------------------------
// TODO : check  
void Write_contacts_fille(Contact_node *first){
    Contact_node *Current = first;
    ofstream ContactFille("Contact_name.txt");
    if(!ContactFille) cout<<"error! :can not open file \n";
    while (Current){
        ContactFille<<Current->id<<"\t"<<Current->fname<<"\t"<<Current->lname<<endl;
        Current = Current ->next;
    }
    ContactFille.close();
    system("cls");
    cout<<"Successfully changed"<<endl;

}

// TODO : check
void Write_phones_fille(Contact_node *first){
    ofstream PhoneFille("contact_phone.txt");
    if(!PhoneFille) {cout<<"error! :can not open file \n"; return ;}
    Contact_node *Ccurrent=first;
    while (Ccurrent){
        Phone_node *Pcurrent = Ccurrent->pnode;
        while (Pcurrent){
            PhoneFille<<Pcurrent->id<<"\t"<<Pcurrent->number<<endl;
            Pcurrent = Pcurrent ->next;
        }
        Ccurrent = Ccurrent ->next;
    }
    PhoneFille.close();
    system("cls");
    cout<<"Successfully changed"<<endl;
}

// TODO : search in contact and print result 
Contact_node *Search_result(Contact_node *Cfirst){

    Contact_node **search;
    bool loop=true;
    string details; 
    while (loop){
        cout<<"-Enter details for search (0 : back):";
        cin>>details;
        if(details == "0") break;
        int count=0;
        search = Advancedsearch(Cfirst,details,count);
        if(!search) cout << "NOT Find\n"; 
        else{
            int menu;
            cout <<"\t Result \n";
            cout<<"Number\t FirstName\t LastName\n"; 
            for (int i = 0; i < count; i++){
                cout<<i+1<<")\t "<<search[i]->fname <<"\t"<<search[i]->lname<<endl;
            }
            while (true)
            {
                cout << "-Enter number contact(0 : back):";
                cin>>menu;
                if(menu == 0) break;
                else if (menu > count) cout<<"error! : not match code menu \n";
                else return search[menu-1];
            }
        }    
    }
    return NULL;
}

void Edete_contact(Contact_node *Cfirst){

    Contact_node *Search = NULL; 
    string Details_edete;
    bool loop = true;
    Search=Search_result(Cfirst);
    if(!Search) loop =false;
    while (loop){
        system("cls");
        char menu,sure;
        cout<<"contact :"<<Search->fname<<"\t"<<Search->lname<<endl;
        cout<<"0 ) back \n";
        cout<<"1 ) first name \n";
        cout<<"2 ) last name \n";
        cout<<"3 ) phone \n";
        cout<<"chosse menu for edete :";
        cin>>menu;
        switch (menu)
        {
        case '0':
            loop = false; 
            break;
        case '1':
            cout<<"-Enter new fist name :";
            cin>>Details_edete;
            cout<<"\n are you sure "<<Search->fname <<" to "<<Details_edete<<" (y/n):";
            cin>>sure;
            if(sure == 'y'){
                Search->fname = Details_edete;
                Write_contacts_fille(Cfirst);
            }
            break;
        case '2':
            cout<<"-Enter new last name :";
            cin>>Details_edete;
            cout<<"\n are you sure "<<Search->lname <<" to "<<Details_edete<<" (y/n):";
            cin>>sure;
            if(sure == 'y'){
                Search->lname = Details_edete;
                Write_contacts_fille(Cfirst);
            }
            break;
        case '3':
            system("cls");
            int count;
            int pmenu;
            while (true){
                
                cout<<"contact :"<<Search->fname<<"\t"<<Search->lname<<endl;
                Print_list_phone(Search, count);
                cout<<"-Enter code phone for edete (0: back) :";
                cin>>pmenu;
                if(pmenu == 0) break;
                else if(pmenu > count) cout<<"error! :not match code\n";
                else {
                    Phone_node *first = Search->pnode;
                    for (int i = 1; i < pmenu; i++){
                        first = first->next;
                    }
                    cout<<"-Enter new phone :";
                    cin>>Details_edete;
                    if(Check_phone(Details_edete)){ 
                        cout<<"\n are you sure "<< first->number <<" to "<<Details_edete<<" (y/n):";
                        cin>>sure;
                        if(sure == 'y'){
                            first ->number = Details_edete;
                            Write_phones_fille(Cfirst);
                        }
                    }
                }
            }
            break;        
        default:
            cout<<"error! : not match code\n";
            break;
        }

    }
}

void clear_list(Contact_node *first)
{
    Contact_node *current = first;
    while (current != NULL)
    {
        Contact_node *temp = current;
        current = current->next;
        delete temp;
    }
}

Contact_node **Advancedsearch(Contact_node *Cfirst ,string GetText, int &count){

    Contact_node **searched = new Contact_node*[100] ;
    string:: size_type pos , fpos, lpos;
    Contact_node *Ccurrent = Cfirst;
    Phone_node *Pcurrent = NULL;

    count =0;
    bool loop=true;

    if (isDigit(GetText)){
        while (Ccurrent){
            Pcurrent = Ccurrent ->pnode;
            while (!Pcurrent){
                pos = Pcurrent->number.find(GetText);
                if (pos != std::string::npos){
                    searched[count] = Ccurrent;// ? get address node searched text
                    count++;
                    break;
                }
                Pcurrent = Pcurrent ->next;
            }
            Ccurrent = Ccurrent->next;
        }
        if(count == 0) {
            return NULL;
        }
        return searched;
    }else{

        while (Ccurrent)
        {

            fpos = (Ccurrent ->fname).find(GetText);
            lpos = (Ccurrent ->lname).find(GetText);
            if (fpos != string::npos || lpos != string::npos){
                searched[count] = Ccurrent;// ? get address node searched text
                count++;
            }
            Ccurrent = Ccurrent ->next;
        }
        if(count == 0) {
            return NULL;
        }
        return searched;
    }

}

void Write_new_contact_fille(string Id, string Fname, string Lname){

    ofstream Contactsfille("Contact_name.txt",ios::app);
    if(!Contactsfille) cout<<"error! :can not open fille contact\n";

    Contactsfille<<Id<<"\t"<<Fname<<"\t"<<Lname<<"\n";//added to fille partner 
    cout<<"your Contact addede to file\n";
    Contactsfille.close();

}

void Write_new_phone_fille(string Id, string Phone[],int count){

    ofstream Contactsfille("contact_phone.txt",ios::app);
    if(!Contactsfille) cout<<"error! :can not open fille contact\n";
    for (int i = 0; i < count; i++)
    {
        Contactsfille<<Id<<"\t"<<Phone[i]<<"\n";//added to fille partner 
        cout<<"your Phone addede to file\n";
        Contactsfille.close();
    }
}

Contact_node *Add_contact(Contact_node *Cfirst, int &count){

    string Fname,Lname,phone,Phonelist[20];
    int count2 =0;
    bool loop = true;
    
    while (loop)
    {
        cout<<"-Enter First Name :";
        cin>>Fname;
        cout<<"-Enter Last Name :";
        cin>>Lname;
        count2 =0;
        while (true){
            
            cout<<"-Enter Phone Number(0 : done):";
            cin>>phone;
            if(phone=="0") break;
            else if (count2 == 20) {
                cout <<"error! : you just can add 20 number\n";
                break;
            }
            else if(Check_phone(phone)) {
               Phonelist[count2]=phone;
               count2++;
            }
        }
        
        while (true)
        {
            char *sure = new char;
            cout<<"first name \t last name \n"<< Fname<<" \t "<<Lname<<"\n"<<"Phones :\n";
            for (int i = 0; i < count2; i++)
            {
                cout<<i+1<<") "<<Phonelist[i]<<endl;
            }
            cout<<"are you sure about contact details (y , n) :";
            cin>>sure;
            if(*sure == 'n') break;
            else if (*sure == 'y')
            {   
                count++;
                loop = false;
                break;
            }
            else cout<<"error! : enter (y : YES )or (n : NO) \n";
        }   
    }

    Write_new_contact_fille(to_string(count),Fname,Lname);
    Cfirst=Add_last_node_contact(Cfirst, to_string(count), Fname, Lname);

    Write_new_phone_fille(to_string(count), Phonelist, count2);
    merge_phone_contact(Cfirst, to_string(count), Phonelist, count2);
    
    return Cfirst;
}

void merge_phone_contact(Contact_node *Cfirst, string Id, string PhoneNumber[], int count){

    Contact_node *Current = Cfirst;
    for (int i = 0; i < count; i++)
    {
        Current = Search_by_id(Cfirst, Id);
        Current ->pnode = Add_first_node_phone(Current ->pnode, Id, PhoneNumber[i]);
    }
}

void Print_list_phone(Contact_node *Cfirst, int &count){
    Phone_node *Pfirst=Cfirst ->pnode;
    // cout<<"Id\t First Name\t Last Name\n";
    count =0;
    while (Pfirst)
    {
        cout<<count+1<<") "<<Pfirst->number<<"\t";
        Pfirst = Pfirst->next;
        count++;
    }
    cout<<endl;
}

void Read_phone(Contact_node *Cfirst){
    
    ifstream f("Contact_phone.txt");
    if(!f) {cout<<"error! :can not open file phone contact\n"; return ;}
    
    Contact_node *Current = Cfirst;
    string *Id= new string;
    string *Phone = new string;

    ifstream Phonefille("Contact_phone.txt");
    
    // ? error in using heap  
    while (Phonefille>> *Id>> *Phone) {
        merge_phone_contact(Cfirst, *Id, Phone,1); 
    }//get info from partner fille
    
    Phonefille.close();
    delete Id,Phone;
}
  
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

Contact_node *Add_last_node_contact(Contact_node *Cfirst , string getId, string getFirstName, string getLastName, Phone_node *getPfirst ){

    Contact_node *New_node =new Contact_node;
    
    New_node ->id = getId;
    New_node ->fname = getFirstName;
    New_node ->lname = getLastName;
    New_node ->pnode = getPfirst;
    New_node ->next = NULL;    

    if (!Cfirst)
        return New_node;
    
    Contact_node *Last = Cfirst;
    while (Last->next != NULL)
    {
        Last = Last->next;
    }
    Last->next = New_node;
    
    return Cfirst;
}

Phone_node *Add_last_node_phone(Phone_node *Pfirst , string getId, string getPhoneNumber){

    Phone_node *New_node =new Phone_node;
    
    
    New_node ->id = getId;
    New_node ->number = getPhoneNumber;
    New_node ->next = NULL;    
    if (!Pfirst)
        return New_node;
    
    Phone_node *Last = Pfirst;
    while (Last->next != NULL)
    {
        Last = Last->next;
    }
    Last->next = New_node;
    
    return Pfirst;
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

Contact_node *Read_contacts_name(Contact_node *first, int &count){
    string Id, FirstName, LastName;
    ifstream Contactfille("Contact_name.txt");
    if(!Contactfille) {cout<<"error! :can not open file partner\n"; return NULL;}

    while (Contactfille>>Id>>FirstName>>LastName) {
        first=Add_last_node_contact(first,Id,FirstName,LastName);
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
        Print_list_phone(Cfirst,Count);
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









