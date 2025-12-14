#include <iostream>
#include <string>

using namespace std;


/*
    Inheritance and Polymorphism with Static members
*/

/*
    Exercise: Create a library management program with C++ that models different types of items 
    (books and DVDs) and their late fee calculations. 
    Implement the missing parts of the code and complete the tasks below.

    Tasks:

    1. Implement the missing parts of the code, including the calculateLateFee method for both the Book and DVD classes.
    2. Initialize and update the totalItems static member in the LibraryItem class when a new item is created.
    3. In the main function, create instances of both Book and DVD, display their information, and calculate late fees for them.
    4. Finally, display the total number of library items using the totalItems static member.
*/

class LibraryItem {
    public:
        LibraryItem(const string& title) : title(title) {}

        virtual double calculateLateFee(int daysLate) const = 0;

        virtual void displayInfo() const {
            cout << "Title: " << title << endl;
        }

        // Add a static member to keep track of the total library items
        static int totalItems;
       
    protected:
        string title;
};

// Define the static member totalItems for the LibraryItem class here
 int LibraryItem::totalItems = 0;
// Initialize it to 0.

class Book : public LibraryItem {
    public:
        Book(const string& title, const string& author) : LibraryItem(title), author(author) {
            totalItems++;
            // Increment the totalItems count for each book added.
            // Hint: Use the static member of the LibraryItem class.
        }

        double calculateLateFee(int daysLate) const override {
            // Implement the late fee calculation for books.
            return daysLate * 0.5; // Example late fee calculation for books
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Author: " << author << std::endl;
        }

    private:
        string author;
};

class DVD : public LibraryItem {
    public:
        DVD(const string& title, int duration) : LibraryItem(title), duration(duration) {
            // Increment the totalItems count for each DVD added.
                       totalItems++;
            // Hint: Use the static member of the LibraryItem class.
        }

        double calculateLateFee(int daysLate) const override {
            // Implement the late fee calculation for DVDs.
            return daysLate * 1.5; // Example late fee calculation for DVDs
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Duration: " << duration << " minutes" << endl;
        }

    private:
        int duration;
};


int main() {
    // Create instances of Book and DVD and test their functionality.
    Book book1("The Great Gatsby", "F. Scott Fitzgerald");
    DVD dvd1("Inception", 148);
        Book book2("The Great Gatsby", "F. Scott Fitzgerald");
    DVD dvd2("Inception", 148);
        Book book3("The Great Gatsby", "F. Scott Fitzgerald");
    DVD dvd3("Inception", 148);
        Book book4("The Great Gatsby", "F. Scott Fitzgerald");
    DVD dvd4("Inception", 148);
    book1.displayInfo();
    cout << "Late Fee for 3 days: $" << book1.calculateLateFee(3) << endl;
    dvd1.displayInfo();
    cout << "Late Fee for 3 days: $" << dvd1.calculateLateFee(3) << endl;
    cout << "Total Library Items: " << LibraryItem::totalItems << endl;
    // Hint: Create Book and DVD objects, display their information, and calculate late fees.

    // Display the total number of library items using the static member totalItems.
    // Hint: Access the totalItems static member from the LibraryItem class.

    return 0;
}