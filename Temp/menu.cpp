#include "menu.hpp"
#include "menuItem.hpp"
#include "shoppingCart.hpp"

vector<menu> menu::getMenu(const string& menuFile)
{
    vector<menu> Menu;
    ifstream file(menuFile);

    if (!file.is_open())
    {
        cout << "Error Opening menu.csv!" << endl;
        return Menu;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string idStr, name, priceStr;
        
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');

        menu item;
        item.id = stoi(idStr);
        item.itemName = name;
        item.price = stof(priceStr);
        Menu.push_back(item);

    }
    file.close();
    return Menu;

}

void menu::displayItem(const vector<menu>& menu)
{
    cout << "Menu:" << endl;
    cout << "id\tName\t\tPrice" << endl;
    cout << "_________________________________"<< endl;

    for (const auto& item : menu)
    {
        cout << item.id << "\t" << item.itemName << "\t\t$" << item.price << endl;
    }
}

std::vector<std::tuple<int, std::string, int>> menu::menuSelect(const vector<menu>& menu)
{
    
    int choice;
    int quantity;
    std::string more;
    bool More = false;
    //shoppingCart cart;
    bool found = false;

    menuItem mess;

    // Shian's variables
    /*string name;

    // Adding some stuff -Shian
    cout << "Enter your name: ";
    cin >> name;
    shoppingCart cart(name);*/
    std::vector<std::tuple<int, std::string, int>> idk;


    do 
    {
        cout << "What would you like to order? (Input id): ";
        cin >> choice;
        found = false;
        more = " ";
        for (const auto& item : menu)
        {
            if (item.id == choice)
            {
                cout << "how many would you like? " << endl;
                cin >> quantity;

                cout << "You selected: " << quantity << " " << item.itemName << " - $" << item.price << endl;
                found = true;

                menuItem it(choice, item.itemName, quantity, (item.price*quantity));
                mess = it;
                this->mCart.addToCart(it);
                
                // Changing stuff -Shian
                std::tuple<int, std::string, int> p = mess.convertToTuple();
                idk.push_back(p);
                while (more != "yes" && more != "y" && more != "n" && more != "no")
                {
                    cout << "Would you like anything else? (yes or no) " << endl;
                    cin >> more;

                    if (more == "yes" || more == "y")
                    {
                        More = true;
                    }
                    else if (more == "no" || more == "n")
                    {
                        More = false;
                    }
                    else 
                    {
                        cout << "not an answer." << endl;
                    }
                }
                break;
                
            }
        }

        if (!found)
        {
            cout << "INVALID ID" << endl;
            displayItem(menu);
        }
    } while (More == true || found == false);
    
    //cart.displayCart();
    //cart.verifyPayment();
    /* std::tuple<int, std::string, int> p = mess.convertToTuple();
    std::vector<std::tuple<int, std::string, int>> idk;
    idk.push_back(p); */
    return idk;
}

shoppingCart menu::getCart()
{
    return this->mCart;
}
