#include <iostream>
#include <string>
#include <limits>

class Product {
private:
    std::string productName;
    double price;
    int quantityInStock;

public:
    // Public default constructor
    Product() {
        productName = "";
        price = 0.0;
        quantityInStock = 0;
    }

    // Public setter method to set and validate all data members
    bool setProductDetails(std::string name, double p, int qty) {
        if (name.empty()) {
            std::cout << "Error: Product name cannot be empty.\n";
            return false;
        }
        if (p < 0.0) {
            std::cout << "Error: Price cannot be negative.\n";
            return false;
        }
        if (qty < 0) {
            std::cout << "Error: Quantity in stock cannot be negative.\n";
            return false;
        }

        productName = name;
        price = p;
        quantityInStock = qty;
        return true;
    }

    // Getter methods
    std::string getProductName() const { return productName; }
    double getPrice() const { return price; }
    int getQuantityInStock() const { return quantityInStock; }

    // 1. GetProductData: Prompts the user for inputs and validates them using a loop
    void GetProductData() {
        std::string name;
        double p;
        int qty;
        bool isValid = false;

        while (!isValid) {
            std::cout << "Enter Product Name: ";
            std::getline(std::cin >> std::ws, name); // std::ws clears leading whitespace

            std::cout << "Enter Product Price (R): ";
            while (!(std::cin >> p)) {
                std::cout << "Invalid input. Please enter a valid number for price: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cout << "Enter Quantity in Stock: ";
            while (!(std::cin >> qty)) {
                std::cout << "Invalid input. Please enter a valid whole number for quantity: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            // Attempt to assign and validate using the setter
            isValid = setProductDetails(name, p, qty);
            if (!isValid) {
                std::cout << "Please re-enter the correct product details.\n\n";
            }
        }
        std::cout << "Product data successfully saved!\n\n";
    }

    // 2. DisplayProduct: Prints out the product details neatly
    void DisplayProduct() const {
        std::cout << "-----------------------------------\n";
        std::cout << "Product Name : " << (productName.empty() ? "[Empty]" : productName) << "\n";
        std::cout << "Price        : R" << price << "\n";
        std::cout << "Stock Level  : " << quantityInStock << " units\n";
        std::cout << "-----------------------------------\n";
    }

    // 3. prodCompare: Compares this product's price with another product object
    void prodCompare(const Product& otherProduct) const {
        std::cout << "=== Price Comparison ===\n";
        if (this->price > otherProduct.getPrice()) {
            std::cout << this->productName << " (R" << this->price
                      << ") is MORE expensive than " << otherProduct.getProductName()
                      << " (R" << otherProduct.getPrice() << ").\n";
        }
        else if (this->price < otherProduct.getPrice()) {
            std::cout << this->productName << " (R" << this->price
                      << ") is CHEAPER than " << otherProduct.getProductName()
                      << " (R" << otherProduct.getPrice() << ").\n";
        }
        else {
            std::cout << "Both " << this->productName << " and " << otherProduct.getProductName()
                      << " have the EXACT SAME price (R" << this->price << ").\n";
        }
        std::cout << "========================\n\n";
    }
};

int main() {
    // Instantiate two product objects
    Product p1;
    Product p2;

    std::cout << "=== Entering Data for Product 1 ===\n";
    p1.GetProductData();

    std::cout << "=== Entering Data for Product 2 ===\n";
    p2.GetProductData();

    // Display both products
    std::cout << "\n=== Displaying Product 1 ===\n";
    p1.DisplayProduct();

    std::cout << "\n=== Displaying Product 2 ===\n";
    p2.DisplayProduct();

    // Compare the two products
    p1.prodCompare(p2);

    return 0;
}
