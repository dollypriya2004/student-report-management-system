
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
private:
    struct student
    {
        string registrationNumber, name, section, branch;
        float maths, cpp, daa, ises, iscp, percent;
    };
    vector<student> students;

public:
    void addStudent()
    {
        fstream f, t;
        f.open("students.txt", ios::app);
        t.open("temp.txt", ios::app);
        float sum = 0, ans = 0;
        student stud;
        cout << "--------Enter a students details--------" << endl;
        cout << "        Registration Number: ";
        cin >> stud.registrationNumber;
        cout << "        Name: ";
        cin >> stud.name;
        cout << "        Branch: ";
        cin >> stud.branch;
        cout << "        Section: ";
        cin >> stud.section;
        cout << "***Enter marks of " << stud.registrationNumber << "***" << endl;
        cout << "        Maths: ";
        cin >> stud.maths;
        cout << "        C++: ";
        cin >> stud.cpp;
        cout << "        DAA: ";
        cin >> stud.daa;
        cout << "        ISES: ";
        cin >> stud.ises;
        cout << "        ISCP: ";
        cin >> stud.iscp;
        sum += (stud.maths + stud.cpp + stud.daa + stud.ises + stud.iscp);
        stud.percent = sum / 5;
        for (int i = 0; i < students.size(); i++)
        {
            if (stud.registrationNumber == students[i].registrationNumber)
            {
                ans = 1;
                break;
            }
        }
        if (ans == 0)
        {
            students.push_back(stud);
            f << "[\nRegistration Number: " << stud.registrationNumber << "," << endl;
            f << "Name: " << stud.name << "," << endl;
            f << "Branch: " << stud.branch << "," << endl;
            f << "Section: " << stud.section << "," << endl;
            f << "Maths: " << stud.maths << "," << endl;
            f << "C++: " << stud.cpp << "," << endl;
            f << "DAA: " << stud.daa << "," << endl;
            f << "ISES: " << stud.ises << "," << endl;
            f << "ISCP: " << stud.iscp << "," << endl;
            f << "percentage: " << stud.percent << "%," << endl;
            f << "]," << endl;
            t << stud.registrationNumber << " " << stud.name << " " << stud.branch << " " << stud.section << " " << stud.maths << " " << stud.cpp;
            t << " " << stud.daa << " " << stud.ises << " " << stud.iscp << " " << stud.percent << endl;
            f.close();
            t.close();
        }
        else
        {
            cout << endl
                 << "A Student with Registration Number - " << stud.registrationNumber << " Already Exists." << endl;
        }
    }
    void displayAStudent()
    {
        int ans = 0;
        if (students.size() == 0)
        {
            cout << "No students in the database To Display." << endl;
            return;
        }
        string reg;
        cout << "Enter Registration Number of student you want to Look At: ";
        cin >> reg;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].registrationNumber == reg)
            {
                cout << "[\n     Registration Number: " << students[i].registrationNumber << ", " << endl;
                cout << "     Name: " << students[i].name << ", " << endl;
                cout << "     Branch: " << students[i].branch << ", " << endl;
                cout << "     Section: " << students[i].section << ", " << endl;
                cout << "     Maths: " << students[i].maths << ", " << endl;
                cout << "     C++: " << students[i].cpp << ", " << endl;
                cout << "     DAA: " << students[i].daa << ", " << endl;
                cout << "     ISES: " << students[i].ises << ", " << endl;
                cout << "     ISCP: " << students[i].iscp << ", " << endl;
                cout << "     percentage: " << students[i].percent << "%," << endl;
                cout << "]" << endl;
                ans = 1;
                break;
            }
        }
        if (ans == 0)
        {
            cout << "The student with Registration number " << reg << " is Not In the Database" << endl;
        }
    }
    void ModifyAStudent()
    {
        int sum = 0, x = 1;
        if (students.size() == 0)
        {
            cout << "No Students in The Database to Modify." << endl;
            return;
        }
        string reg;
        cout << "Enter Registration Number of student you want to Modify: ";
        cin >> reg;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].registrationNumber == reg)
            {
                x = 2;
                cout << "--------Enter the Updated details of " << reg << "--------" << endl;
                cout << "        Name: ";
                cin >> students[i].name;
                cout << "        Branch: ";
                cin >> students[i].branch;
                cout << "        Section: ";
                cin >> students[i].section;
                cout << "***Enter marks of " << students[i].registrationNumber << "***" << endl;
                cout << "        Maths: ";
                cin >> students[i].maths;
                cout << "        C++: ";
                cin >> students[i].cpp;
                cout << "        DAA: ";
                cin >> students[i].daa;
                cout << "        ISES: ";
                cin >> students[i].ises;
                cout << "        ISCP: ";
                cin >> students[i].iscp;
                sum += (students[i].maths + students[i].cpp + students[i].daa + students[i].ises + students[i].iscp);
                students[i].percent = sum / 5;
                cout << endl
                     << "The details of " << reg << " are now Modified." << endl;
                this->printToFile();
                break;
            }
        }
        if (x == 1)
        {
            cout << endl
                 << "No Record of " << reg << " found" << endl;
        }
    }
    void deleteIt()
    {
        int ans = 0;
        if (students.size() == 0)
        {
            cout << "No students in the Database to Delete." << endl;
            return;
        }
        string reg;
        cout << "Enter Registration Number of student you want to Delete: ";
        cin >> reg;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].registrationNumber == reg)
            {
                ans = -1;
                students.erase(students.begin() + i);
                cout << endl
                     << "The Details of " << reg << " are now Deleted." << endl;
                this->printToFile();
                break;
            }
        }
        if (ans == 0)
        {
            cout << endl
                 << "No Record of " << reg << " Found." << endl;
        }
    }
    void print()
    {
        if (students.size() == 0)
        {
            cout << "No students In the DataBase." << endl;
        }
        else
        {
            for (int j = 0; j < students.size(); j++)
            {
                cout << "[\n     Registration Number: " << students[j].registrationNumber << ", " << endl;
                cout << "     Name: " << students[j].name << ", " << endl;
                cout << "     Branch: " << students[j].branch << ", " << endl;
                cout << "     Section: " << students[j].section << ", " << endl;
                cout << "     Maths: " << students[j].maths << ", " << endl;
                cout << "     C++: " << students[j].cpp << ", " << endl;
                cout << "     DAA: " << students[j].daa << ", " << endl;
                cout << "     ISES: " << students[j].ises << ", " << endl;
                cout << "     ISCP: " << students[j].iscp << ", " << endl;
                cout << "     percentage: " << students[j].percent << "%," << endl;
                cout << "]," << endl;
            }
        }
    }
    void printToFile()
    {
        fstream f, t;
        f.open("students.txt", ios::out);
        t.open("temp.txt", ios::out);
        if (students.size() == 0)
        {
            f << "_____Students List_____" << endl;
        }
        else
        {
            f << "_____Students List_____" << endl;
            for (int i = 0; i < students.size(); i++)
            {
                f << "[\nRegistration Number: " << students[i].registrationNumber << "," << endl;
                f << "Name: " << students[i].name << "," << endl;
                f << "Branch: " << students[i].branch << "," << endl;
                f << "Section: " << students[i].section << "," << endl;
                f << "Maths: " << students[i].maths << "," << endl;
                f << "c++: " << students[i].cpp << "," << endl;
                f << "DAA: " << students[i].daa << "," << endl;
                f << "ISES: " << students[i].ises << "," << endl;
                f << "ISCP: " << students[i].iscp << "," << endl;
                f << "percentage: " << students[i].percent << "%," << endl;
                f << "]," << endl;
                t << students[i].registrationNumber << " " << students[i].name << " " << students[i].branch << " " << students[i].section << " " << students[i].maths << " " << students[i].cpp;
                t << " " << students[i].daa << " " << students[i].ises << " " << students[i].iscp << " " << students[i].percent << endl;
            }
        }
        f.close();
        t.close();
    }
    void printToppers()
    {
        vector<float> toppers;
        int num;
        for (int i = 0; i < students.size(); i++)
        {
            toppers.push_back(students[i].percent);
        }
        if (toppers.size() >= 3)
        {
            num = 3;
        }
        else
        {
            num = toppers.size();
        }
        sort(toppers.begin(), toppers.end(), greater<float>());
        if (num == 0)
        {
            cout << "No Students in the Database." << endl;
            return;
        }
        cout << "Top " << num << " of the class: " << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int k = 0; k < students.size(); k++)
            {
                if (toppers[i] == students[k].percent)
                    cout << "Rank - " << i + 1 << " : " << students[k].name << " (" << students[k].registrationNumber << ")" << endl;
            }
        }
        toppers.clear();
    }
    void getDataAndStore()
    {
        student stud;
        fstream f;
        string reg, n, b, s;
        float m, c, d, i, ip, p;
        f.open("temp.txt", ios::in);
        while (f >> reg >> n >> b >> s >> m >> c >> d >> i >> ip >> p)
        {
            stud.registrationNumber = reg;
            stud.name = n;
            stud.branch = b;
            stud.section = s;
            stud.maths = m;
            stud.cpp = c;
            stud.daa = d;
            stud.ises = i;
            stud.iscp = ip;
            stud.percent = p;
            students.push_back(stud);
        }
        f.close();
    }
};

class employee
{
protected:
    string usr, pass, name, dept, dob, mn;

public:
    // employee();
    // employee{};
    void reg();
    void login();
    void forgot();
    
};
class admin : public employee
{
public:
    void addStaff();
    void removeStaff();
};
void employee ::reg()
{
    int opt;
    cout << "Enter Your Name          : ";
    cin >> name;
    cout << "Enter Your Dept.         : ";
    cin >> dept;
    cout << "Enter Your DOB in dd-mm-yy           : ";
    cin >> dob;
    cout << "Enter Your Password: ";
    cin >> mn;
    pass = mn;
    string usr = (name.substr(0, 6)) + (dob.substr(0, 2)) + "@srmap.edu.in";
    cout << "Your Username is  " << usr << endl;
    cout << "Registered Successfully" << endl;
    ofstream file; // ofstream creates a file
    file.open(usr + ".txt");
    file << usr << endl
         << pass << endl
         << dob;
    file.close();
    cout << "Press 1 to login : ";
    cin >> opt;
    if (opt == 1)
        login();
}
void employee ::login()
{
    string usrnm, passd;
    cout << "Enter Username : ";
    cin >> usrnm;
    // usr = usrnm;
    cout << "Enter Password : ";
    cin >> passd;
    ifstream read(usrnm + ".txt"); // ifstream reads a file
    getline(read, usr);            // reads the username
    getline(read, pass);           // reads the password
    if (usr == usrnm && pass == passd)
    {
        cout << "Login Successfully" << endl;
        cout << "Welcome to SRM" << endl;
       
        Student o1;
        fstream f, t;
        int n;
        o1.getDataAndStore();
        f.open("students.txt", ios::out);
        t.open("temp.txt", ios::out);
        o1.printToFile();
        while (1)
        {
            cout << endl
                 << "1 - Add A Student" << endl
                 << "2 - Modify A Student Record" << endl
                 << "3 - Delete A Student Record" << endl
                 << "4 - Display A Student Record" << endl
                 << "5 - Display ALL Student Records" << endl
                 << "6 - Display Toppers" << endl
                 << "0 - EXIT" << endl;
            cout << "Enter a number: ";
            cin >> n;
            cout << endl;
            switch (n)
            {
            case 1:
                o1.addStudent();
                break;
            case 2:
                o1.ModifyAStudent();
                break;
            case 3:
                o1.deleteIt();
                break;
            case 4:
                o1.displayAStudent();
                break;
            case 5:
                o1.print();
                break;
            case 6:
                o1.printToppers();
                break;
            case 0:
                exit(0);
            default:
                cout << "Enter a valid number." << endl;
            }
        }
        f.close();
        t.close();
    }
    else
    {
        int opt;
        cout << "Login Failed" << endl;
        cout << " If Forgot Password Press 1 : ";
        cin >> opt;
        if (opt == 1)
        {
            forgot();
        }
    }
}
void employee ::forgot()
{
    string sname, sdob;
    cout << " Enter Username ";
    cin >> sname;
    cout << "Enter DOB : ";
    cin >> sdob;
    ifstream read(usr + ".txt");
    getline(read, usr);
    getline(read, pass);
    getline(read, dob);
    if (usr == sname && dob == sdob)
    {
        getline(read, pass);
        cout << "Your Password is : " << pass << endl;
    }
    else
    {
        cout << "Invalid Input, Please try again " << endl;
    }
}


int main()
{
    int opt;
    employee sam;
   
    while (1)
    {
        cout << "\n\n__________MENU__________\n"
             << endl;
        cout << "1.Staff" << endl;
       
        cout << "Enter Option 1 to Enter: ";
        cin >> opt;

        if (opt == 1)
        {
            int o1;
            cout << "1.Register" << endl;
            cout << "2.Login" << endl;
            cout << "Enter Your Option : ";
            cin >> o1;
            switch (o1)
            {
            case 1:
                sam.reg();
                break;
            case 2:
                sam.login();
                break;
           
            default:
                cout << "Invalid Input" << endl;
                break;
            }
        }
       
    }
    return 0;
}