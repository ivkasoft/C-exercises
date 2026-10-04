#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <limits>

#include "Product.h"
#include "Cart.h"
#include "Order.h"
#include "Payment.h"
#include "CardPayment.h"

using namespace std;

/* ---------- helpers ---------- */
string today() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return to_string(now->tm_year + 1900) + "-" +
           to_string(now->tm_mon + 1) + "-" +
           to_string(now->tm_mday);
}

vector<Product> loadProducts() {
    vector<Product> products;
    ifstream f("products.txt");
    string line;

    while (getline(f, line)) {
        stringstream ss(line);
        string id, name, cat, price, qty;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, cat, ',');
        getline(ss, price, ',');
        getline(ss, qty, ',');

        products.push_back(Product(
            stoi(id), name, cat, stod(price), stoi(qty)
        ));
    }
    return products;
}

void saveProducts(const vector<Product>& products) {
    ofstream f("products.txt");
    for (const auto& p : products) {
        f << p.toFileString() << "\n";
    }
}

void saveOrder(const string& date, const string& name, const string& email, double total, double id) {
    ofstream f("orders.txt", ios::app);
    f << id << "," << date << "," << name << "," << email << "," << total << "\n";
}

int loadLastOrderId() {
    ifstream f("orders.txt");
    string line;
    int count = 0;
    while (getline(f, line)) count++;
    return count + 1;
}

/* ---------- USER MENU ---------- */
void userMenu() {
    Cart cart;
    vector<Product> products = loadProducts();
    int choice;
    static int orderIdCounter = loadLastOrderId();

    do {
        cout << "\n--- USER MENU ---\n";
        cout << "1. List products\n";
        cout << "2. Add product to cart\n";
        cout << "3. Checkout\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            for (const auto& p : products) {
                cout << p.getId() << " | "
                     << p.getName() << " | "
                     << p.getPrice() << " | Qty: "
                     << p.getQuantity() << endl;
            }
        }

        else if (choice == 2) {
            int id;
            cout << "Product ID: ";
            cin >> id;

            bool found = false;
            for (auto& p : products) {
                if (p.getId() == id && p.getQuantity() > 0) {
                    cart.addToCart(p);
                    p.setQuantity(p.getQuantity() - 1); //  НАМАЛЯВАМЕ БРОЙКАТА
                    saveProducts(products);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Product not available!\n";
        }

        else if (choice == 3) {
            if (cart.isEmpty()) {
                cout << "Cart is empty!\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string name, email;
            cout << "Name: ";
            getline(cin, name);
            cout << "Email: ";
            getline(cin, email);

            double total = cart.calculateTotal();
            
            Payment* payment = new CardPayment();
            if (payment->pay(total)) {
                Order order(
                    orderIdCounter,
                    cart.getItems(),
                    name,
                    email,
                    "Card",
                    total
                );
                saveOrder(today(), name, email, total,orderIdCounter-1);

                cout << "\n--- ORDER DETAILS ---\n";
                order.displayOrder();     
                cout << "---------------------\n";

                cart.clear();
                cout << "Order successful!\n";
            }
        }

    } while (choice != 0);
}
/* ---------- ADMIN MENU ---------- */
void adminMenu() { 
    int ch; 
    do { 
        cout << "\nADMIN\n1.View products\n2.Add product\n3.Delete product\n4.Revenue by date\n5.Search orders by email\n6.Edit product quantity\n0.Back\nChoice: "; 
        cin >> ch; auto products = loadProducts(); 
        if (ch == 1) { 
            for (auto &p : products) cout << p.getId() << " " << p.getName() << " (" << p.getQuantity() << ") "<< p.getPrice()<<"\n"; 
        } 
        else if (ch == 2) { 
            int id, q; 
            double pr; 
            string n, c; 

            cout << "ID: "; 
            cin >> id; 
            cin.ignore(); 
            cout << "Name: "; 
            getline(cin, n); 
            cout << "Category: "; 
            getline(cin, c); 
            cout << "Price: "; 
            cin >> pr; 
            cout << "Qty: "; 
            cin >> q; 

            products.push_back(Product(id,n,c,pr,q)); 
            saveProducts(products); 
            cout << "Added.\n";
        } 
        else if (ch == 3) { 
            int id; cout << "ID: "; 
            cin >> id; 
            products.erase(remove_if(products.begin(), products.end(), [&](Product&p){
                return p.getId()==id;
            }), products.end()); 
            saveProducts(products); 
            cout << "Deleted.\n";
        } 
        else if (ch == 4) { 
            string d; 
            double sum=0; 
            cout << "Date (YYYY-M-D): "; 
            cin >> d; 
            ifstream f("orders.txt"); 
            string line; 
            while (getline(f,line)) { 
                if (line.find(d)==0) { 
                    sum += stod(line.substr(line.find_last_of(',')+1)); 
                } 
            } 
            cout << "Revenue: " << sum << endl; 
        } 
        else if (ch == 5) { 
            string email;
            cout << "Enter email to search: ";
            cin >> email;

            ifstream f("orders.txt");
            string line;
            while (getline(f, line)) {
                if (line.find(email) != string::npos) {
                    cout << line << endl;
                }
            }
                }
        else if (ch == 6) {
            int id, newQty;
            cout << "Enter product ID: ";
            cin >> id;

            bool found = false;

            for (auto &p : products) {
                if (p.getId() == id) {
                    cout << "Current quantity: " << p.getQuantity() << endl;
                    cout << "Enter new quantity: ";
                    cin >> newQty;

                    p.setQuantity(newQty);
                    found = true;
                    break;
                }
            }

            if (found) {
                saveProducts(products);
                cout << "Quantity updated successfully.\n";
            } else {
                cout << "Product not found.\n";
            }
        }
    } 
    while (ch != 0); }

/* ---------- MAIN ---------- */
int main() {
    int choice;
    string user, pass;
    do {
        cout << "\n--- E-SHOP ---\n";
        cout << "1. User\n";
        cout << "2. Admin\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            userMenu();
        if (choice == 2) {
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;
            if (user == "admin" && pass == "admin123"){
                adminMenu();
            } else {
                cout << "Invalid credentials!\n";
            }     
        }

    } while (choice != 0);

    return 0;
}
