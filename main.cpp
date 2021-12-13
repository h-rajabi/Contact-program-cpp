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

Contact_node *Delete_contact(Contact_node *Cfirst);

void Delete_node(Contact_node **Cfirst, Contact_node *GetCaddress, Phone_node **Pfirst=NULL, Phone_node *GetPaddress=NULL);

void Add_phone_to_contact(Contact_node *first);

void Delete_phone(Contact_node *first);

void Delete_duplicate_number(Contact_node *Cfirst);

void Sorting(Contact_node *Cfirst);

int Length_phone(Phone_node *Pfirt);

bool Check_phone_exict(Contact_node *Cfirst, string getId, string getNumber);
// ? functions 
// ? -----------------------------------------------------------------------------

int main(){

    menu();

    return 0;//TODO debug error
}

// ? functions 
// ? -----------------------------------------------------------------------------
bool Check_phone_exict(Contact_node *Cfirst, string getId, string getNumber){

    Contact_node *Ccurrent =Cfirst;

    while (Ccurrent){
        Phone_node *Pcurrent = Ccurrent->pnode;
        if(getId != Ccurrent->id){
            while (Pcurrent){
                string phone =Pcurrent->number;
                int len1 =getNumber.length(),len2= phone.length();
                if(getNumber[0] == '+' && phone[0] == '+'){
                    if( ( getNumber.substr(len1-10,len1) == phone.substr(len2-10,len2) ) && getNumber.substr(1,3) == phone.substr(1,3)){ 
                        cout<<"error! : this number exict \n";
                        return false;
                    }    
                }else  {
                    if(getNumber.substr(len1-10,len1) == phone.substr(len2-10,len2)){
                        cout<<"error! : this number exict \n";
                        return false;
                    } 
                }
                Pcurrent = Pcurrent->next;    
            }
        }
        Ccurrent = Ccurrent->next;
    }
    return true;
}

int Length_phone(Phone_node *Pfirt){

    Phone_node *current =Pfirt;
    int count =0;
    while (current){
        count++;
        current = current->next;
    }
    return count;
}

void Sorting(Contact_node *Cfirst){   
	Contact_node *current = Cfirst;
    char menu;
    bool loop=true;
    while (loop){
        cout<<"0: Back\n";
        cout<<"1: First Name(A-Z) \n";
        cout<<"2: First Name(Z-A) \n";
        cout<<"3: Last Name(A-Z) \n";
        cout<<"4: Last Name(Z-A) \n";
        cout<<"5: count phone number( more to less ) \n";
        cout<<"6: count phone number( less to more )\n";
        cout<<"-Enter code menu :";
        cin>>menu;
        switch (menu)
        {
        case '0':
            loop =false;
            break;
        case '1':
            while (current) {
            Contact_node *temp = current;

            while (temp) {
                if (tolower(current->fname[0]) > tolower(temp->fname[0])) {
                    string currentId,currentFn,currentLn;
                    Phone_node *currentPn;

                    currentId = current->id;
                    current->id = temp->id;
                    temp->id = currentId;

                    currentFn = current->fname;
                    current->fname = temp->fname;
                    temp->fname = currentFn;

                    currentLn = current->lname;
                    current->lname = temp->lname;
                    temp->lname = currentLn;

                    currentPn = current->pnode;
                    current->pnode = temp->pnode;
                    temp->pnode = currentPn;
                }

                temp = temp->next;
            }
            current = current->next;
        }
        current = Cfirst;
            break;
        case '2':
            while (current ) {
                Contact_node *temp = current;

                while (temp ) {
                    if (tolower(current->fname[0]) < tolower(temp->fname[0])) {
                        string currentId,currentFn,currentLn;
                        Phone_node *currentPn;

                        currentId = current->id;
                        current->id = temp->id;
                        temp->id = currentId;

                        currentFn = current->fname;
                        current->fname = temp->fname;
                        temp->fname = currentFn;

                        currentLn = current->lname;
                        current->lname = temp->lname;
                        temp->lname = currentLn;

                        currentPn = current->pnode;
                        current->pnode = temp->pnode;
                        temp->pnode = currentPn;
                    }

                    temp = temp->next;
                }
                current = current->next;
            }
            current = Cfirst;
            break;
        case '3':
            while (current) {
                Contact_node *temp = current;

                while (temp ) {
                    if (tolower(current->lname[0]) > tolower(temp->lname[0])) {
                        string currentId,currentFn,currentLn;
                        Phone_node *currentPn;

                        currentId = current->id;
                        current->id = temp->id;
                        temp->id = currentId;

                        currentFn = current->fname;
                        current->fname = temp->fname;
                        temp->fname = currentFn;

                        currentLn = current->lname;
                        current->lname = temp->lname;
                        temp->lname = currentLn;

                        currentPn = current->pnode;
                        current->pnode = temp->pnode;
                        temp->pnode = currentPn;
                    }

                    temp = temp->next;
                }
                current = current->next;
            }
            current = Cfirst;
            break;    
        case '4':
            while (current ) {
                Contact_node *temp = current;

                while (temp ) {
                    if (tolower(current->lname[0]) < tolower(temp->lname[0])) {
                        string currentId,currentFn,currentLn;
                        Phone_node *currentPn;

                        currentId = current->id;
                        current->id = temp->id;
                        temp->id = currentId;

                        currentFn = current->fname;
                        current->fname = temp->fname;
                        temp->fname = currentFn;

                        currentLn = current->lname;
                        current->lname = temp->lname;
                        temp->lname = currentLn;

                        currentPn = current->pnode;
                        current->pnode = temp->pnode;
                        temp->pnode = currentPn;
                    }

                    temp = temp->next;
                }
                current = current->next;
            }
            current = Cfirst;
            break;   
        case '5':
            while (current ) {
                Contact_node *temp = current;

                while (temp ) {
                    if ( Length_phone(current->pnode) < Length_phone(temp->pnode) ) {
                        string currentId,currentFn,currentLn;
                        Phone_node *currentPn;

                        currentId = current->id;
                        current->id = temp->id;
                        temp->id = currentId;

                        currentFn = current->fname;
                        current->fname = temp->fname;
                        temp->fname = currentFn;

                        currentLn = current->lname;
                        current->lname = temp->lname;
                        temp->lname = currentLn;

                        currentPn = current->pnode;
                        current->pnode = temp->pnode;
                        temp->pnode = currentPn;
                    }

                    temp = temp->next;
                }
                current = current->next;
            }
            current = Cfirst;
            break;
        case '6':
            while (current ) {
                Contact_node *temp = current;

                while (temp ) {
                    if ( Length_phone(current->pnode) > Length_phone(temp->pnode) ) {
                        string currentId,currentFn,currentLn;
                        Phone_node *currentPn;

                        currentId = current->id;
                        current->id = temp->id;
                        temp->id = currentId;

                        currentFn = current->fname;
                        current->fname = temp->fname;
                        temp->fname = currentFn;

                        currentLn = current->lname;
                        current->lname = temp->lname;
                        temp->lname = currentLn;

                        currentPn = current->pnode;
                        current->pnode = temp->pnode;
                        temp->pnode = currentPn;
                    }

                    temp = temp->next;
                }
                current = current->next;
            }
            current = Cfirst;
            break;                    
        default:
            cout<<"error! : not match code \n";
            break;
        }
        system("cls");
        Print_list_contacts(Cfirst);    
    }
}

void Delete_duplicate_number(Contact_node *Cfirst){

    Contact_node *Ccurrent=Cfirst;
    Phone_node *Pcurrent=NULL, *duplicate=NULL, *search=NULL;
    int count =0;
    while (Ccurrent){
        Pcurrent = Ccurrent->pnode;
        while (Pcurrent){
            duplicate = Pcurrent;
            search=duplicate->next;
            while (search){
                if(search->number == duplicate->number) {
                    Delete_node(NULL,NULL,&(Ccurrent->pnode),search);
                    cout<<"contact :"<<Ccurrent->fname<<" "<<Ccurrent->lname<<" deleted depulicate number :["<<duplicate->number<<"]\n";
                }
                search = search->next;
            }
            Pcurrent = Pcurrent->next;
        }
        Ccurrent = Ccurrent->next;
    }
    delete Ccurrent,Pcurrent,duplicate,search;
    Write_phones_fille(Cfirst);
}

void Delete_phone(Contact_node *Cfirst){

    Contact_node *Search=NULL;
    char sure;
    int count, pmenu;
    Search = Search_result(Cfirst);
    
    while (true){
        cout<<"contact :"<<Search->fname<<"\t"<<Search->lname<<endl;
        Print_list_phone(Search, count);
        cout<<"-Enter code phone for delete (0: back) :";
        cin>>pmenu;
        if(pmenu == 0) break;
        else if(pmenu > count) cout<<"error! :not match code\n";
        else {
            Phone_node *first = Search->pnode;
            for (int i = 1; i < pmenu; i++){
                first = first->next;
            }
            cout<<"\n are you sure deleted "<< first->number <<" (y/n):";
            cin>>sure;
            if(sure == 'y' || sure == 'Y'){
                Delete_node(NULL,NULL,&(Search->pnode),first);
                Write_phones_fille(Cfirst);
                cout<<"The number was successfully deleted!!\n";
            }else if(sure != 'n' || sure != 'N') cout<<"error! :not match code\n";
        }
    }
}

void Add_phone_to_contact(Contact_node *first){

    Contact_node *Search =NULL;
    Phone_node *Pfirst = NULL;
    string *Phonelist= new string[20];
    bool loop = true;
    string phone ;
    int count2=0;
    char sure; 

    Search =Search_result(first);
    cout<<"\t Add phone \n";
    cout<<"contact :"<<Search->fname<<"\t"<<Search->lname<<endl;
    while (true){
        cout<<"-Enter Phone Number(0 : done):";
        cin>>phone;
        if(phone=="0") break;
        else if (count2 == 20) {
            cout <<"error! : you just can add 20 number\n";
            break;
        }
        else if(Check_phone(phone)) {
            if(Check_phone_exict(first,Search->id,phone)){
                cout << "- Are you sure add "<<phone<<" to contact (y/n)?";
                cin>>sure;
                if(sure == 'y'){
                    Phonelist[count2]=phone;
                    Pfirst = Add_first_node_phone(Search->pnode, Search->id, phone);
                    Search->pnode = Pfirst;
                    count2++;
                }
                else if (sure != 'n') cout << "enter y : YES or n :NO\n"; 
            }
        }
    }
    cout<<"count 2:"<<count2;
    Write_new_phone_fille(Search->id, Phonelist, count2);
    delete Phonelist;
    

}

void Delete_node(Contact_node **Cfirst, Contact_node *GetCaddress, Phone_node **Pfirst, Phone_node *GetPaddress){
    
    if(!Cfirst){
        Phone_node *Current = *Pfirst;
        if(Current == GetPaddress){
            *Pfirst=GetPaddress->next;
            delete GetPaddress;
            return ;
        }
        while (Current->next != GetPaddress){
            Current = Current->next;
        }
        Current ->next = GetPaddress->next;
        delete GetPaddress;
        return ;
    }else{
        Contact_node *Current = *Cfirst;
        if(Current == GetCaddress){
            *Cfirst=GetCaddress->next;
            delete GetCaddress;
            return;
        }
        while (Current->next != GetCaddress){
            Current = Current->next;
        }
        Current ->next = GetCaddress->next;
        delete GetCaddress;
        return ;
    }

}

Contact_node *Delete_contact(Contact_node *Cfirst){

    Contact_node *Search =NULL;
    Search =Search_result(Cfirst);
    char sure;
    cout<<"contact :"<<Search->fname<<"\t"<<Search->lname<<endl;
    cout<<"are you sure delete contact (y/n) :";
    cin>>sure;
    if(sure == 'y'){
        Delete_node(&Cfirst,Search);
        Write_contacts_fille(Cfirst);
        Write_phones_fille(Cfirst);
        return Cfirst;
    }
    else 
        return Cfirst;
}

void Write_contacts_fille(Contact_node *first){
    Contact_node *Current = first;
    ofstream ContactFille("Contact_name.txt");
    if(!ContactFille) cout<<"error! :can not open file \n";
    while (Current){
        ContactFille<<Current->id<<"\t"<<Current->fname<<"\t"<<Current->lname<<endl;
        Current = Current ->next;
    }
    ContactFille.close();
    cout<<"Successfully changed"<<endl;

}

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
    
    cout<<"Successfully changed fille"<<endl;
}

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
        else if (count == 1) return search[0]; 
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
                        if (Check_phone_exict(Cfirst,Search->id,Details_edete)){
                            cout<<"\n are you sure "<< first->number <<" to "<<Details_edete<<" (y/n):";
                            cin>>sure;
                            if(sure == 'y'){
                                first ->number = Details_edete;
                                Write_phones_fille(Cfirst);
                            }
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
    }
    Contactsfille.close();
    cout<<"your Phone addede to file\n";
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
                if(Check_phone_exict(Cfirst,to_string(count+1),phone)){
                    Phonelist[count2]=phone;
                    count2++;
                }
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
            delete sure;
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
    while (Pfirst){
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

    Contact_node *CFirst =NULL;
    int count = 0;
    CFirst = Read_contacts_name(CFirst,count);
    Read_phone(CFirst);

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
            clear_list(CFirst);
            exit(1);
            break;    
        case '1':
            CFirst=Add_contact(CFirst,count);
            break;
        case '2':
            Print_list_contacts(CFirst);
            break;
        case '3':
            Edete_contact(CFirst);
            break;
        case '4':
            CFirst=Delete_contact(CFirst);
            break;
        case '5':
            Add_phone_to_contact(CFirst);
            break;
        case '6':
            Delete_phone(CFirst);
            break;
        case '7':
            Delete_duplicate_number(CFirst);
            break;
        case '8':
            Contact_node *search;
            int count ;
            search = Search_result(CFirst);
            cout<<"contact : "<<search->fname<<"\t"<<search->lname<<endl;
            Print_list_phone(CFirst,count);
            break;
        case '9':
            Sorting(CFirst);
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

