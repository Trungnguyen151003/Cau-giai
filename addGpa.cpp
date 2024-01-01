#include<bits/stdc++.h>
using namespace std;

struct Student
{
    string gender;
    string email;
    string name;
    string subjects;
    string phoneNo;
    string ID;
    string score;
    string credit;
    string gpa;
}info ;
stack<Student> students;
stack<Student> point;
string deleteTemp, zero = "0";
void predisplay();
void readCSVFile();
void readCSVFile2();
bool check_email();
void validEmailCheck();
bool caseCheck(int n);
void addPhoneNo();
bool checkValidIntegerArray(string n);
bool checkIDDuplicate(string id);
bool checkPNDuplicate(string pn);

void displayStudents();
void searchStudent();
void deleteStudent(string id);

void addID();
void addScore();
int partition(vector<int>& arr1, vector<int>& arr2, int low, int high);
void quicksort(vector<int>& arr1, vector<int>& arr2, int low, int high);
void sortData();

void add();
void add2();


void predisplay(){
	cout << "                                _____ _______ __   __ _______ _____  ______ _   _ _______   " << endl;
	cout << "                               / ____|__   __|  | |  |__   __|  _  \\|  ____| \\ | |__   __|" << endl;
	cout << "                              | (___    | |  |  | |  |  | |  | | \\  | |__  |  \\| |  | |   " << endl;
	cout << "                               \\___ \\   | |  |  | |  |  | |  | |  | |  __| | . ` |  | |   " << endl;
	cout << "                               ____) |  | |  |  \\_/  |  | |  | |_/  | |____| |\\  |  | |   " << endl;
	cout << "                              |_____/   |_|   \\_____/   |_|  |_____/|______|_| \\_|  |_|   " << endl;
	
    cout << " __  __          _   _          _____ ______ __  __ ______ _   _ _______    _______     _______ _______ ______ __  __ " << endl;
    cout << "|  \\/  |   /\\   | \\ | |   /\\   / ____|  ____|  \\/  |  ____| \\ | |__   __|  / ____\\ \\   / / ____|__   __|  ____|  \\/  |" << endl;
    cout << "| \\  / |  /  \\  |  \\| |  /  \\ | |  __| |__  | \\  / | |__  |  \\| |  | |    | (___  \\ \\_/ / (___    | |  | |__  | \\  / |" << endl;
    cout << "| |\\/| | / /\\ \\ | . ` | / /\\ \\| | |_ |  __| | |\\/| |  __| | . ` |  | |     \\___ \\  \\   / \\___ \\   | |  |  __| | |\\/| |" << endl;
    cout << "| |  | |/ ____ \\| |\\  |/ ____ \\ |__| | |____| |  | | |____| |\\  |  | |     ____) |  | |  ____) |  | |  | |____| |  | |" << endl;
    cout << "|_|  |_/_/    \\_\\_| \\_/_/    \\_\\_____|______|_|  |_|______|_| \\_|  |_|    |_____/   |_| |_____/   |_|  |______|_|  |_|" << endl;

}

void readCSVFile() {
    ifstream file;
    file.open("Book2.csv", ios::in);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student e;
        if(!ss){
            continue;
        }
        getline(ss, e.name, ',');
        getline(ss, e.gender, ',');
        getline(ss, e.email, ',');
        getline(ss, e.ID, ',');
        getline(ss, e.phoneNo, ',');
        students.push(e);
    }
    file.close();
}

void readCSVFile2() {
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
        getline(ss, e.subjects, ',');
        getline(ss, e.credit, ',');
        getline(ss, e.score, ',');
        getline(ss, e.gpa, ',');
        point.push(e);
    }
    file.close();
}

void addGender(){
    bool parse_correct;
    do{
        parse_correct = true;
        cout << "Gender: \nMale(1)\tFemale(2)\tHomo(3)\nYour choice: " ;
        int gender;
        cin >> gender;
        switch (gender)
        {
        case 1:
            info.gender = "Male";
            break;
        case 2:
            info.gender = "Female";
            break;
        case 3:
            info.gender = "Homo";
            
            break;
        
        default:
            cout << "Invalid input!";
            parse_correct = false;
            break;
        }
    } while(!parse_correct);
}

bool check_email(){
    int i, j, k = 0, count = 0;
    bool atFlag = true;
    bool dotFlag = true;
    char two_words[3] = "@.";
    getline(cin, info.email);

    while (info.email[k] != '\0')
    {
        if(info.email[k] == ' '){
            count++;
        }
        k++;
    }
    
    if (count > 0){
        return false;
    }
    for(i = 0; i < info.email.length(); i++){
        if(info.email[i] == '@'){
            atFlag = false;
        }
        for (j = 0; j < info.email.length(); j++)
        {
            if(info.email[j] == '.'){
                dotFlag = false;
            }
        }
    }

    
    //if (info.email.compare(two_words) != NULL) return false;
    if (atFlag == false && dotFlag == false) return true;
    if (atFlag == true && dotFlag == true) return false;
}

void validEmailCheck() {
    bool x = true;
    do
    {
        printf("Email: ");
        x = check_email();
        if (x == false) printf("Invalid email!\n");
    } while (x == false); 
    //return 0;
}

bool caseCheck(int n){
    if(n < 1 || n > 6){
        return false;
    }
    return true;
}

void addPhoneNo(){
    bool parse_correct = true;
    int addPhoneNoTemp;
    do{
        cout << "Phone number: ";
        getline(cin, info.phoneNo);
        //addPhoneNoTemp = stoi(info.phoneNo);
        if(info.phoneNo.length() != 10){
            parse_correct = false;
            cout << "Phone number must have 10 digits!\n";
            continue;
        } else if(!checkValidIntegerArray(info.phoneNo) || !checkPNDuplicate(info.phoneNo)){
            parse_correct = false;
        } else {
            parse_correct = true;
        }

    } while(!parse_correct);
}

void addID(){
    cout << "ID: ";
    getline(cin, info.ID);
}

void addID(Student& std) {
    cout << "ID: ";
    getline(cin, std.ID);
}

bool checkValidIntegerArray(string n){
    for(auto i : n){
        if(!isdigit(i)){
            cout << "Invalid Input!";
            return false;
        }
    }
    return true;
}

bool checkPNDuplicate(string pn){
    stack<Student> tempStack = students;
    bool found = false;
    while (!tempStack.empty()) {
        Student temp = tempStack.top();
        tempStack.pop();
        if ((temp.phoneNo == pn) == 1) {
            cout << "Phone number already appeared in the database! Please check again\n";
            return false;
        }
    }

    return true;
}

void add(){
    fstream fout;

    fout.open("Book2.csv", ios::out | ios::app);
    string exit = " ";

    cout << "Adding element: \n(Enter *Blankspace* to exit)" << endl;
    getline(cin, info.name);            //dunno why but it works ?!
    cout << "Name: ";
    getline(cin, info.name);
    int checkIfExit = info.name.compare(exit);
    if(checkIfExit == 0){
        return;

    }

    addGender();
    cin.ignore();

    validEmailCheck();

    addID();

    addPhoneNo();
    
    students.push(info);
    fout << info.name << "," << info.gender << "," << info.email << "," << info.ID << "," << info.phoneNo << "," << endl;
    fout.close();
}

void displayStudents(){
    system("cls");
    stack<Student> tempStack = students;
    if (tempStack.empty()) {
        cout << "No student in the system!\n";
    } else {
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                               LIST OF STUDENTS                                               |" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|    ID     |            Name          |  Gender |           Email          |" 
                << "     Phone Number     |" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;

        while(!tempStack.empty()){
            Student temp = tempStack.top();
            tempStack.pop();
            cout << "| " << left << setw(9) << temp.ID << " | " << setw(24) << temp.name << " | " << setw(7) 
                         << temp.gender << " | " << setw(24) << temp.email << " | " << setw(20) 
                         << temp.phoneNo << " | "  << endl; 
            }
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void displayAllStudentsDetails() {
    stack<Student> tempStack = point;
    if (tempStack.empty()) {
        cout << "No student in the system!\n";
    } else {
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|    ID       |          Subject             |    Credit    |    Score    |    GPA    |" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;

        while (!tempStack.empty()) {
            Student temp = tempStack.top();
            tempStack.pop();
            cout << "| " << left << setw(11) << temp.ID << " | " << setw(28) << temp.subjects << " | " << setw(12) << temp.credit << " | " << setw(11) << temp.score << " |" << 
            setw(11) <<fixed<<setprecision(2)<< temp.gpa<<"|" << endl;
        }
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    }
}
    

void add2() {
    fstream fout;
    fout.open("Book1.csv", ios::out | ios::app);
    cin.ignore();
    stack<Student> tempStack = students;
    bool found = false;
    string id;
    cout << "Enter the ID of the student you want to find: ";
    cin >> id;
    cin.ignore();
    // Check if the ID already exists in the system
    while (!tempStack.empty()) {
        Student temp = tempStack.top();
        tempStack.pop();
        if(id == temp.ID)
        {
            point.push(temp);
            fout << temp.ID;
            found = true;
            break;
        }
    }
    if (found == true) {
        double totalScore = 0.0;
        double totalCredit = 0.0;
        double mult = 0.0;
        for (int i = 1; i <= 5; i++) {
            cout << "Mon " << i << ": "; 
            getline(cin, info.subjects);
            cout << "Point: ";
            getline(cin, info.score);
            cout << "Credit: ";
            getline(cin, info.credit);
            totalCredit += stod(info.credit);
            mult = stod(info.score) * stod(info.credit);
            totalScore += mult;
            point.push(info);
            fout << "," <<  info.subjects << "," << info.credit << "," << info.score<< endl;
        }
        double averageScore = totalScore / totalCredit;
        cout << "Average Score: " << averageScore << endl;

        // Push the average score into the point stack
        Student averageInfo;
        averageInfo.gpa = to_string(averageScore);
        point.push(averageInfo);
        fout << "," << ","<< "," <<","<< averageInfo.gpa << endl;
    }
    if(found == false)
    {
        cout << "ID not found " << endl;
    }

    fout.close();
}


void searchStudent() {
    stack<Student> tempStack = students;
    bool found = false;
    string id;
    cout << "Enter the ID of the student you want to find: ";
    cin >> id;
    cin.ignore();
    //cout << id << endl;

    //cout << id << "  " << id.size() << endl;
    while (!tempStack.empty()) {
        Student temp = tempStack.top();
        tempStack.pop();
        //cout << id << endl;

        //cout << temp.ID << "  " << (id == temp.ID)<< endl;

        if ((id == temp.ID) == 1) {
            cout << "Student Found!\n";
            cout << "ID: " << temp.ID << endl;
            cout << "Name: " << temp.name << endl;
            cout << "Gender: " << temp.gender << endl;
            cout << "Phone number: " << temp.phoneNo << endl;
            cout << "Email: " << temp.email << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!\n";
    }
}

void addGender(Student& std) {
    bool parse_correct;
    do {
        parse_correct = true;
        cout << "Gender:\n";
        cout << "Male(1)\t\tFemale(2)\t\tHomo(3)\n";
        cout << "Your choice: ";
        int gender;
        cin >> gender;
        switch (gender) {
            case 1:
                std.gender = "Male";
                break;
            case 2:
                std.gender = "Female";
                break;
            case 3:
                std.gender = "Homo";
                break;
            default:
                cout << "Invalid input!" << endl;
                parse_correct = false;
                break;
        }
    } while (!parse_correct);
}

void addPhoneNo(Student& std) {
    bool parse_correct = true;
    string addPhoneNoTemp;
    do {
        cout << "Phone number: ";
        cin >> std.phoneNo;
        addPhoneNoTemp = std.phoneNo;
        if (std.phoneNo.length() != 10) {
            parse_correct = false;
            cout << "Phone number must have 10 digits!" << endl;
        } else if (!checkValidIntegerArray(std.phoneNo) || !checkPNDuplicate(addPhoneNoTemp)) {
            parse_correct = false;
        } else {
            parse_correct = true;
        }
    } while (!parse_correct);
}

bool check_email_update(Student& std){
    int i, j, k = 0, count = 0;
    bool atFlag = true;
    bool dotFlag = true;
    char two_words[3] = "@.";
    getline(cin, std.email);

    while (std.email[k] != '\0')
    {
        if(std.email[k] == ' '){
            count++;
        }
        k++;
    }
    
    if (count > 0){
        return false;
    }
    for(i = 0; i < std.email.length(); i++){
        if(std.email[i] == '@'){
            atFlag = false;
        }
        for (j = 0; j < std.email.length(); j++)
        {
            if(std.email[j] == '.'){
                dotFlag = false;
            }
        }
    }

    
    //if (info.email.compare(two_words) != NULL) return false;
    if (atFlag == false && dotFlag == false) return true;
    if (atFlag == true && dotFlag == true) return false;
}

void validEmailCheck_update(Student& std) {
    bool x = true;
    do
    {
        printf("Email: ");
        x = check_email_update(std);
        if (x == false) printf("Invalid email!\n");
    } while (x == false); 
    //return 0;
}

void addEmail(Student& std) {
    bool valid = true;
    do {
        validEmailCheck_update(std);
        if (!valid) {
            cout << "Invalid email!" << endl;
        }
    } while (!valid);
}

void updateStudents() {
    stack<Student> tempStack, tempStack1, tempStack2 = students;
    Student temp1, temp2;
    string id;
    char change;
    bool found = false;
    fstream fin("Book2.csv", ios::in | ios::out);
    cout << "Enter student's ID to update: ";
    cin >> id;
    cin.ignore();

    while (!tempStack2.empty()) {
        Student emp = tempStack2.top();
        tempStack2.pop();

        if ((emp.ID == id) == 1) {
            found = true;

            cout << "Do you want to change the name? (Y/N): "; 
            cin >> change;
            if (change == 'Y' || change == 'y'){
                cin.ignore();
                cout << "Name: ";
                getline(cin, temp1.name);
            }else{
                temp1.name = emp.name;
            }
             
            cout << "Do you want to change the gender? (Y/N): ";
            cin >> change;
            if (change == 'Y' || change == 'y') {
                addGender(temp1);
            } else {
                temp1.gender = emp.gender;  
            }
            
            cout << "Do you want to change the email? (Y/N): ";
            cin >> change;
            cin.ignore();
            if (change == 'Y' || change == 'y') {
                addEmail(temp1);
            } else {
                temp1.email = emp.email;  
            }
        
            cout << "Do you want to change the ID? (Y/N): ";
            cin >> change;
            if (change == 'Y' || change == 'y') {
                addID(temp1);
            } else {
                temp1.ID = emp.ID;  
            }
            
            cout << "Do you want to change the phone number? (Y/N): ";
            cin >> change;
            cin.ignore();
            if (change == 'Y' || change == 'y') {
                addPhoneNo(temp1);
            } else {
                temp1.phoneNo = emp.phoneNo;  
            }
        
            tempStack.push(temp1);
            break;
        } else {
            tempStack.push(emp);
        }
    }
    
    while (!tempStack.empty()) {
        tempStack2.push(tempStack.top());
        tempStack.pop();
    }    
    students = tempStack2;
    if (found) {
        fin.close();
        ofstream fout("Book2.csv", ios::trunc); // Open the file in truncate mode to clear the existing data

        while (!tempStack2.empty()) {
            Student temp2 = tempStack2.top();
            temp2.phoneNo.insert(0, " '");
            fout << temp2.name << "," << temp2.gender << ","
                 << temp2.email << "," << temp2.ID << "," << temp2.phoneNo << ","
                 << endl;

            tempStack2.pop();
        }

        fout.close();
        cout << "Employee updated successfully!\n";
    } else {
        cout << "Employee not found!\n";
    }
}


void deleteStudent(string id) {
    stack<Student> tempStack, tempStack2;
    Student temp;
    bool found = false;
    fstream fin("Book2.csv", ios::in | ios::out);
    while (!students.empty()) {
        Student temp = students.top();
        students.pop();

        if ((temp.ID == id) == 1) {
            found = true;
            break;
        }
        tempStack.push(temp);
    }
    while (!tempStack.empty()) {
        students.push(tempStack.top());
        tempStack.pop();
    }
    tempStack2 = students;



    if (found) {
        cout << "Student with ID " << id << " has been deleted!\n";
        fin.seekg(0, ios::beg);
        while(!tempStack2.empty()){
            fin << tempStack2.top().name << ","<< tempStack2.top().gender << ","<< tempStack2.top().email << ","<< tempStack2.top().ID << ","<< tempStack2.top().phoneNo << "," << endl; 
            tempStack2.pop();
        }

    } else {
        cout << "Student not found!\n";
    }
    fin.close();
}

int main(){
    readCSVFile();
    readCSVFile2();
    main:
    system("cls");
    predisplay();
    int yn, choice;
    string temp2, temp3, temp4;
    bool parsed_correct = true;
    do{
        cout << ("\n\n========== MENU ==========\n\n");
        cout << "1. Add a new info\n"; 
        cout << "2. Update an existing info\n";
        cout << "3. Search for a info\n";   
        cout << "4. Remove a info\n";
        cout << "5. List all datas\n";
        cout << "6. Sort datas\n";
        cout << "7. List all point\n";
        cout << "8. Add point\n";
        cout << "9. Exit\n\n";
        cout << "==========================\n\n";
        cout << "Your option: ";

        cin >> choice;

        if(!caseCheck(choice) || choice == 0){
            parsed_correct = false;
            break;
        }
    } while(!parsed_correct);
    switch (choice){
        case 1:

            add();

            break;
        
        case 2:
            cout << "Enter the ID of the student you want to update: ";

            updateStudents();
            break;
        
        case 3:


            searchStudent();
            break;
        
        case 4:
            //int temp4;
            
            cout << "Enter the ID of the student you want to delete: ";
            cin >> temp4;
            

            deleteStudent(temp4);
            break;
        
        case 5:
            displayStudents();
            break;
        
        case 6:

            //sortData();
            displayStudents();

            break;

        case 7:
            displayAllStudentsDetails();
            break;

        case 8:
            add2();
            break;

        case 9:
        
            cout << "Are you sure you want to exit?\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
            break;
    }    
    cout << "Press (1) to return to the main menu!\nPress any other key to exit the program!\n";
    cin >> yn;
    switch (yn)
    {
    case 1:
        goto main;
        break;
    

    default:

        cout << "Exitting the program!";
        break;
    }
    
}
