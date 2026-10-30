#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    string productName;
    double price;
    int quantityInStock;

public:
    Product(); // default constructor
    void setProduct(string nm, double pr, int qty); // setter
    string getProductName(); // getters
    double getPrice();
    int getQuantityInStock();
};

Product::Product()
{
    productName = "";
    price = 0;
    quantityInStock = 0;
}

void Product::setProduct(string nm, double pr, int qty)
{
    // product name cannot be an empty string
    if (nm == "")
        productName = "Unknown";
    else
        productName = nm;

    // price must not be negative
    if (pr >= 0)
        price = pr;
    else
        price = 0;

    // quantity in stock must not be negative
    if (qty >= 0)
        quantityInStock = qty;
    else
        quantityInStock = 0;
}

string Product::getProductName() { return productName; }
double Product::getPrice() { return price; }
int Product::getQuantityInStock() { return quantityInStock; }

int main()
{
    Product bread; // default constructor runs
    bread.setProduct("White bread 700 g", 18.99, 10);

    cout << bread.getProductName() << ", R" << bread.getPrice()
         << ", " << bread.getQuantityInStock() << " in stock" << endl;

    // test validation - negative values are rejected
    bread.setProduct("", -5, -2);
    cout << bread.getProductName() << ", R" << bread.getPrice()
         << ", " << bread.getQuantityInStock() << " in stock" << endl;

    return 0;
}
