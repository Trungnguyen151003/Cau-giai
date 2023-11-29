#include<bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    string ID;
    string GPA;
    double average;
}info ;
stack<Student> students;
string deleteTemp, zero = "0";

void readCSVFile();

void add();
void add2();

void addID();
void addGPA();


void readCSVFile() {
    ifstream file;
    file.open("Book1.csv", ios::in);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student e;
        if(!ss){
            continue;
        }
        getline(ss, e.ID, ',');
        getline(ss, e.GPA, ',');
        getline(ss, e.name, ',');
        students.push(e);
    }
    file.close();
}


void insertAtBottom(std::stack<Student> &stack, Student item) {
    // Base case: stack is empty, insert the item
    if (stack.empty()) {
        stack.push(item);
        return;
    }

    // Recursive case: remove the top element and insert at bottom
    Student temp = stack.top();
    stack.pop();
    insertAtBottom(stack, item);
    stack.push(temp);
}

void reverseStackRecursively(std::stack<Student> &stack) {
    // Base case: stack is not empty
    if (!stack.empty()) {
        // Remove the top element
        Student temp = stack.top();
        stack.pop();

        // Reverse the remaining stack
        reverseStackRecursively(stack);

        // Insert the removed element at the bottom
        insertAtBottom(stack, temp);
    }
}

void addID(){
    cin.ignore();
    cout << "ID: ";
    getline(cin, info.ID);
}

void addID(Student& std) {
    cout << "ID: ";
    getline(cin, std.ID);
}

void add(){
    fstream fout;

    fout.open("Book1.csv", ios::out | ios::app);
    string exit = " ";
    cout << "Adding element: \n(Enter *Blankspace* to exit)" << endl;
    
    addID();
    students.push(info);
    fout << info.ID << endl;
    fout.close();
}

void displayAllStudentsDetails() {
    reverseStackRecursively(students);
    stack<Student> tempStack = students;
    if (tempStack.empty()) {
        cout << "No student in the system!\n";
    } else {
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|    ID       |          Name             |    GPA    |" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;

        while (!tempStack.empty()) {
            Student temp = tempStack.top();
            tempStack.pop();
            cout << "| " << left << setw(11) << temp.ID << " | " << setw(25) << temp.name << " | " << setw(9) << temp.GPA << " |" << endl; 
        }
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    }
}




void add2() {
    fstream fout;

    fout.open("Book1.csv", ios::out | ios::app);
    cin.ignore();
    addID(info);
    // Check if the ID already exists in the system
    stack<Student> tempStack = students;
    bool idExists = false;
    while (!tempStack.empty()) {
        Student temp = tempStack.top();
        tempStack.pop();
        if (info.ID == temp.ID) {
            idExists = true;
            break;
        }
    }

    if (idExists) {
        cout << "ID already exists. Updating GPA and name...\n";

        for (int i = 1; i <= 5; i++) {
            cout << "Mon " << i << ": "; 
            getline(cin, info.name);
            cout << "Point: ";
            getline(cin, info.GPA);
            students.push(info);
            fout << "," <<  info.GPA << "," << info.name << endl;
        }
    } 
    else {
        cout << "ID doesn't exist";
    }
    fout.close();
}




int main()
{
    readCSVFile();
    int n; cin >>n;
    if(n==1)
    {
        add();
        
    }
    else if(n==2)
    {
        displayAllStudentsDetails();
    }
    else if(n==3)
    {
        add2();
    }
    else{
        cout << "no";
    }
}