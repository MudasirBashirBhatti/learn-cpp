#include <iostream>
using namespace std;


// ****************** Example 1 *******************
void getName(){
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Welcome back " << name << " !" << endl;
}

// ****************** Example 2 *******************
void getAge() {
    int age;
    cout << "Please enter your age: ";

    if (cin >> age) {
        cout << "You are " << age << " years old";
    } else {
        cout << "Invalid input";
    }
}

int main(){
    getName();
    getAge();
    return 0;
}
