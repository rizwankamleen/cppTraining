#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main()
{
    // Inventory management 

    int menu;
    int option;
    char repeat = 'y';
    
    struct Details {
        string Name;
        int quantity;
        long price;
    };
    
    vector<Details> Inventory = {};

    while (repeat == 'y') {
        cout << "Press 1 for Menu" << endl;
        cin >> menu;
        if (menu == 1) {
            cout << "Welcome to Inventory management" << endl;
            cout << "Press 2 to add inventory" << endl;
            cout << "Press 3 to search for an inventory" << endl;
            cout << "Press 4 to delete an inventory" << endl;
            cin >> option;
        }
        if (option == 2) {
            string inv_name;
            string name;
            int quantity;
            long price;
            Details tmpDetail;    

            cout << "Enter the name for inventory: " << endl;
            cin >> inv_name;
            cout << "Write the name of the product: " << endl;
            cin >> name;
            cout << "Enter the price of the product: " << endl;
            cin >> price;
            cout << "Enter the quantity of the product: " << endl;
            cin >> quantity;

            tmpDetail.Name = name;
            tmpDetail.quantity = quantity;
            tmpDetail.price = price;

            Inventory.push_back(tmpDetail);
        }
        if (option == 3) {
            string sch_name;
            cout << "Write the name of product: " << endl;
            cin >> sch_name;
            bool found = false;
            for (size_t i = 0; i < Inventory.size(); i++) {
                if (Inventory[i].Name == sch_name) {
                    cout << "Product Name: " << Inventory[i].Name << endl;
                    cout << "Product Price: " << Inventory[i].price << endl;
                    cout << "Product Quantity: " << Inventory[i].quantity << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Product not found!" << endl;
            }
        }

        if (option == 4) {
            string sch_name;
            cout << "Write the name of product: " << endl;
            cin >> sch_name;
            bool found = false;
            for (size_t i = 0; i < Inventory.size(); i++) {
                if (Inventory[i].Name == sch_name) {
                    Inventory.erase(Inventory.begin() + i);
                    cout << "Product removed!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Product not found!" << endl;
            }
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> repeat;
    }


    return 0;
}
