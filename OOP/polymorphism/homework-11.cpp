#include <iostream>
#include <string>

using namespace std;

class User {
protected:
    string username;
public:
    User(string uname) : username(uname) {}

    virtual void login() {
        cout << username << " logged in." << endl;
    }

    virtual void logout() {
        cout << username << " logged out." << endl;
    }

    virtual void viewProfile() {
        cout << "Viewing the profile of " << username << "." << endl;
    }

    virtual void performAction() = 0; // ✅ Pure virtual

    virtual ~User() {}
};

class SiteUser : public User {
public:
    SiteUser(string uname) : User(uname) {}

    void performAction() override {
        cout << username << " is browsing the site.11111111111111111" << endl;
    }

    virtual void postComment() {
        cout << "Comment posted by " << username << "." << endl;
    }
};

class AdminUser : public User {
public:
    AdminUser(string uname) : User(uname) {}

    void performAction() override {
        cout << username << " is managing site content." << endl;
    }
};

class ModeratorUser : public AdminUser {
public:
    ModeratorUser(string uname) : AdminUser(uname) {}

    virtual void moderateContent()  {
        cout << "Content moderated by " << username << "." << endl;
    }
};

class ManagerUser : public AdminUser {
public:
    ManagerUser(string uname) : AdminUser(uname) {}

    virtual void manageUsers()  {
        cout << "Users managed by " << username << "." << endl;
    }
};

int main() {

    User* user1 = new ModeratorUser("ModUser123");
    User* user2 = new ManagerUser("ManagerUser456");

    user1->login();
    user1->performAction();
    user1->viewProfile();
    user1->logout();

    user2->login();
    user2->performAction();
    user2->viewProfile();
    user2->logout();

    if (auto modUser = dynamic_cast<ModeratorUser*>(user1)) {
        modUser->moderateContent();
    }

    if (auto managerUser = dynamic_cast<ManagerUser*>(user2)) {
        managerUser->manageUsers();
    }

    delete user1;
    delete user2;
}
