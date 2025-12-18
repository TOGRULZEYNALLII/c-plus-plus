#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Polymorphism

    15. Abstract Classes as Interfaces
*/


/*
    Exercise: E-Commerce System Design

    Instructions:

    1. Define Product Management Interface:
        Create an interface named ProductManager with a virtual function displayProductDetails that takes an int productId as a parameter.
    2. Implement Abstract Cart Class:
        Create an abstract class named AbstractCart that extends the ProductManager interface.
        Provide common functionality for managing a shopping cart, including adding to the cart, 
        removing from the cart, displaying the cart, and an abstract method checkout.
    3. Implement Concrete Online Store Class:
        Create a concrete class named OnlineStore that implements both the ProductManager interface and extends the AbstractCart abstract class.
        Implement the displayProductDetails method for an online store-specific product details display.
        Implement the checkout method for online store-specific checkout logic.
    4. Implement Concrete Mobile App Class:
        Create a concrete class named MobileApp that implements both the ProductManager interface and extends the AbstractCart abstract class.
        Implement the displayProductDetails method for a mobile app-specific product details display.
        Implement the checkout method for mobile app-specific checkout logic.

    Tips:
        Tip 1: Think about the functionalities that are common to both the online store and mobile app, and those that are specific to each.
        Tip 2: Ensure that the abstract class provides a common structure for shopping cart management.
        Tip 3: Implement the virtual functions in the derived classes with specific details related to the online store and mobile app.
        Tip 4: Use virtual destructors in the interface and abstract class for proper cleanup.
        Tip 5: Test your implementations by creating instances of the classes and 
        performing operations like displaying product details, adding/removing items from the cart, and checking out.
*/


#include <vector>

// TODO: Define ProductManager interface
class ProductManager {
public:
    virtual void displayProductDetails(int productId) = 0; // Pure virtual
    virtual ~ProductManager() {} // Virtual destructor
};
// TODO: Define AbstractCart abstract class
class AbstractCart : public ProductManager {
public:
    void addToCart(int productId) {
        cart_.push_back(productId);
        cout << "Product " << productId << " added to cart." << endl;
    }   
    void removeFromCart(int productId) {
        cart_.erase(remove(cart_.begin(), cart_.end(), productId), cart_.end());
        cout << "Product " << productId << " removed from cart." << endl;
    }
    void displayCart() {
        cout << "Cart contents: ";
        for (int id : cart_) {
            cout << id << " ";
        }
        cout << endl;
    }
    virtual void checkout() = 0; // Pure virtual
    virtual ~AbstractCart() {} // Virtual destructor
protected:
    vector<int> cart_;
};
// TODO: Implement OnlineStore class
class OnlineStore : public AbstractCart {
public:
    void displayProductDetails(int productId) override {
        cout << "Online Store - Displaying details for product ID: " << productId << endl;
    }
    void checkout() override {
        cout << "Online Store - Proceeding to checkout with " << cart_.size() << " items." << endl;
    }
};
// TODO: Implement MobileApp class
class MobileApp : public AbstractCart {
public:
    void displayProductDetails(int productId) override {
        cout << "Mobile App - Displaying details for product ID: " << productId << endl;
    }
    void checkout() override {
        cout << "Mobile App - Proceeding to checkout with " << cart_.size() << " items." << endl;
    }
};

int main() {

    // Step 4: Demonstrate the use of both the interface and abstract class

    OnlineStore onlineStore;
    onlineStore.displayProductDetails(101);
    onlineStore.addToCart(101);
    onlineStore.addToCart(102);
    onlineStore.displayCart();
    onlineStore.checkout();

    MobileApp mobileApp;
    mobileApp.displayProductDetails(201);
    mobileApp.addToCart(201);
    mobileApp.removeFromCart(202);
    mobileApp.displayCart();
    mobileApp.checkout();

}