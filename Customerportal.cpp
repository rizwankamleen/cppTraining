#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include<sstream>


using namespace std;

class Customer {
 int    ID;
 string Name;
 string Address;
 long   Phone;
 string Email;
 vector <string> Accounts = {};
 
public:

 void AddCustomer(){
    int     id;
    string name; 
    string address;
    long   phone;
    string email;
    
    cout<<"Please enter the ID: "<<endl;
    cin>> id;
    cout<<"Please enter the complete Name: "<<endl;
    cin>> name;
    cout<<"Please enter the complete Address: "<<endl;
    cin>> address;
    cout<<"Please enter the phone number: "<<endl;
    cin>> phone;
    cout<<"Please enter the E-mail: "<<endl;
    cin>> email;
    
    ID = id;
    Name = name;
    Address = address;
    Phone = phone;
    Email = email;
    
    cout<<"Customer has been added."<<endl;
 }
 
 int getID() {
    return ID; 
 }
 string getName() {
    return Name; 
 }
 string getAddress() {
    return Address; 
 }
 long getPhone() {
    return Phone; 
 }
 string getEmail() {
    return Email; 
 }
 
 void DisplayCustomer() {
    cout<<"ID:  "<<ID<<endl;
    cout<<"Name:    "<<Name<<endl;
    cout<<"Address:     "<<Address<<endl;
    cout<<"Phone:   "<<Phone<<endl;
    cout<<"Email:   "<<Email<<endl;
 }
 
 
};
    
int main()
{
  int choice;
  vector <Customer> CustomerList = {};
  bool repeat = true;
  
 while(repeat) {
    cout<<" ********Welcome to Customer Portal******** "<<endl;
    cout<<"Press 1: Add Customer "<<endl;
    cout<<"Press 2: Search Customer "<<endl;
    cout<<"Press 3: To Exit"<<endl;
    cout<<"Please enter the respective key: "<<endl;
    cin>> choice;
  
    if(choice == 1) {
        Customer custdetail;
        custdetail.AddCustomer();
        CustomerList.push_back(custdetail);
    }  
    else if (choice == 2) {
        int custID;
        cout<<"Please enter the Customer ID: "<<endl;
        cin>>custID;
        
        if(CustomerList.size()>=0) {
            int checkID;
            for (int i=0; i<CustomerList.size(); i++) {
                checkID = CustomerList[i].getID();
                if(custID == checkID) {
                    CustomerList[i].DisplayCustomer();
                }
                else cout<<"Customer ID not found!"<<endl;
            }
        }
        else cout<<"No Customer Lists available."<<endl;
    }
    cout<<"Want to continue: (1/0)";
    cin>>repeat;
 }
 
  
  
    return 0;
}
