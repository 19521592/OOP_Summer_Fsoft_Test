#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <vector>
#include <memory>
using namespace std;
enum JobTitle {
    DEVELOPER,
    MANAGER,
    TESTER
};
class Employee {
public:
    Employee(int id = 0, string name = "None", JobTitle jobTitle = DEVELOPER) {
        this->id = id;
        this->name = name;
        this->jobTitle = jobTitle;
    }
    int getId() {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    string getJobTitle() {
        if (jobTitle == DEVELOPER) {
            return "Developer";
        }
        if (jobTitle == MANAGER) {
            return "Manager";
        }
        if (jobTitle == TESTER) {
            return "Tester";
        }
    }
    void setJobTitle(JobTitle jobTitle) {
        this->jobTitle = jobTitle;
    }
    virtual void ShowInformation() = 0;
private:
    int id;
    string name;
    JobTitle jobTitle;
    virtual void DisplayDailyWork() = 0;
};

class Developer : public Employee {
private:
    string recentProject;
public:
    Developer(int id = 0, string name = "None", JobTitle jobTitle = DEVELOPER, string recentProject = "None") : Employee(id, name, jobTitle){
        this->recentProject = recentProject;
    }
    string getRecentProject() {
        return recentProject;
    }
    string setRecentProject(string recentProject) {
        this->recentProject = recentProject;
    }
    void ShowInformation() {
        cout << "Ma So Nhan Vien: " << getId() << endl;
        cout << "Ho Va Ten: " << getName() << endl;
        cout << "Ten Bo Phan: " << getJobTitle() << endl;
        cout << "Ten Du An Dang Lam: " << getRecentProject() << endl;
    }

    void DisplayDailyWork() {
    }
};

class Manager : public Employee {
private:
    string recentCustomer;
public:
    Manager(int id = 0, string name = "None", JobTitle jobTitle = MANAGER, string recentCustomer = "None") : Employee(id, name, jobTitle) {
        this->recentCustomer = recentCustomer;
    }
    string getRecentCustomer() {
        return recentCustomer;
    }
    string setRecentCustomer(string recentCustomer) {
        this->recentCustomer = recentCustomer;
    }
    void ShowInformation() {
        cout << "Ma So Nhan Vien: " << getId() << endl;
        cout << "Ho Va Ten: " << getName() << endl;
        cout << "Ten Bo Phan: " << getJobTitle() << endl;
        cout << "Ten Khach Hang Dang Quan Ly: " << getRecentCustomer() << endl;
    }

    void DisplayDailyWork(){
    }
};

class Tester : public Employee {
public:

    Tester(int id = 0, string name = "None", JobTitle jobTitle = TESTER) : Employee(id, name, jobTitle) {
    }

    void ShowInformation() {
        cout << "Ma So Nhan Vien: " << getId() << endl;
        cout << "Ho Va Ten: " << getName() << endl;
        cout << "Ten Bo Phan: " << getJobTitle() << endl;
    }
    void DisplayDailyWork() {
    }
};

class Company {
private:
    vector<unique_ptr<Employee>> employeeList;
    vector<string> employeeNameList;
public: 
    unique_ptr<Employee> add(string name = "None") {
        int choice;
        int id;
        string recent;
        if (name == "None") {
            cout << "Nhap ten nhan vien: ";
            cin.ignore();
            getline(cin, name);
        }
        else cout << "Nhan vien " << name << ": " << endl;
        cout << "Nhap loai nhan vien (0. Developer | 1. Manager | 2. Tester): ";
        cin >> choice;
        cout << "Nhap ma so nhan vien: ";
        cin >> id;
        unique_ptr<Employee> tempp;
        switch (choice) {
        case 0:
            cout << "Nhap ten du an dang lam: ";
            cin.ignore();
            getline(cin, recent);
            tempp = make_unique<Developer>(id, name, DEVELOPER, recent);
            break;
        case 1:
            cout << "Nhap ten khach hang đang quan ly: ";
            cin.ignore();
            getline(cin, recent);
            tempp = make_unique<Manager>(id, name, MANAGER, recent);
            break;
        case 2:
            tempp = make_unique<Tester>(id, name, TESTER);
            break;
        default:
            break;
        }
        return tempp;
    }

    int deleteFromEmployeeList() {
        int deleteId;
        cout << "Nhap ma so nhan vien can xoa: ";
        cin >> deleteId;
        int n = employeeList.size();
        int i;
        for (i = 0; i < n; i++) {
            if (employeeList[i]->getId() == deleteId) {
                employeeList.erase(employeeList.begin() + i);
                cout << "Da xoa thanh cong nhan vien " << deleteId << " !\n";
                cout << "Ban co muon xoa them nhan vien khong? (1. Co | 2. Khong): ";
                break;
            }
        }
        if (i==n) cout << "Khong co nhan vien nay!\n (Nhap lai: 1 | Quay lai: 2): ";
        int choose;
        cin >> choose;
        if (choose == 1) return 1;
        return 0;
    }

    void idSort() {
        int n = employeeList.size();
        for (int i = 1; i < n; i++) {
            int temp = employeeList[i]->getId();
            int j = i - 1;
            unique_ptr<Employee> tempp = move(employeeList[i]);
            while (j >= 0 && temp <= employeeList[j]->getId()) {
                employeeList[j + 1] = move(employeeList[j]);
                j--;
            }
            employeeList[j+1] = move(tempp);
        }
    }

    void ShowInformationList() {
        for (vector<unique_ptr<Employee>>::iterator it = employeeList.begin(); it != employeeList.end(); ++it)
            (*it)->ShowInformation();
    }

    void nameSort() {
        int n = employeeNameList.size();
        for (int i = 1; i < n; i++) {
            string temp = employeeNameList[i];
            int j = i - 1;
            while (j >= 0 && temp.substr((int)temp.rfind(" ") + 1, temp.length() - (int)temp.rfind(" ") - 1) <=
                employeeNameList[j].substr((int)employeeNameList[j].rfind(" ") + 1, employeeNameList[j].length() - (int)employeeNameList[j].rfind(" ") - 1)) {
                employeeNameList[j + 1] = employeeNameList[j];
                j--;
            }
            employeeNameList[j + 1] = temp;
        }
    }

    void displayEmployeeName() {
        int n = employeeNameList.size();;
        for (int i = 0; i < n; i++) {
            cout << employeeNameList[i] << endl;
        }
    }

    void setEmployeeNameList(vector<string> employeeNameList) {
        this->employeeNameList = employeeNameList;
    }

    void setEmployeeList() {
        for (vector<string>::iterator it = employeeNameList.begin(); it != employeeNameList.end(); ++it) {
            employeeList.push_back(add(*it));
        }
        cout << "Da them danh sach nhan vien!" << endl;
    }
    void setEmployee() {
        employeeList.push_back(add());
    }
    void searchEmployeeWithId() {
        int id;
        cout << "Nhap ma so nhan vien can tim: ";
        cin >> id;
        for (vector<unique_ptr<Employee>>::iterator it = employeeList.begin(); it != employeeList.end(); ++it)
            if ((*it)->getId() == id) {
                cout << "Da tim thay nhan vien " << id << "!\n";
                (*it)->ShowInformation();
                return;
            }
        cout << "Khong tim thay nhan vien!\n";
    }
};

vector<string> readFromFile(FILE* file) {
    vector<string> employeeNameList;
    std::ifstream fileInput(file);

    while (!fileInput.eof())
    {
        char name[255];
        fileInput.getline(name, 255);
        employeeNameList.push_back((string)(name));
    }
    return employeeNameList;
}

int main()
{
    cout << "____MANAGE EMPLOYEE APPLICATION BY NGUYEN DUC HUONG____\n";
    Company Fsoft;
    const char* filePath = "D:/employee_list.txt";
    FILE* file;
    file = fopen(filePath, "r");
    if (!file)
        std::cout << "Can not open this file" << std::endl;
    else
        std::cout << "File is opened" << std::endl;
    Fsoft.idSort();
    
    cout << "Cac chuc nang cua chuong trinh:\n";
    cout << "1. Nhap danh sach ten nhan vien tu file txt (D:/employee_list.txt)\n";
    cout << "2. Nhap them thong tin cho danh sach ten nhan vien.\n";
    cout << "3. Sap xep ten nhan vien.\n";
    cout << "4. In danh sach ten nhan vien.\n";
    cout << "5. Sap xep nhan vien theo ma so nhan vien.\n";
    cout << "6. In thong tin day du danh sach nhan vien.\n";
    cout << "7. Them nhan vien vao danh sach.\n";
    cout << "8. Xoa nhan vien khoi danh sach.\n";
    cout << "9. Tim kiem nhan vien.\n";
    cout << "0. Thoat chuong trinh.\n";
    int choice;
    char choosePrint;
    do {
        cout << "Chon chuc nang: ";
        cin >> choice;
        switch (choice) {
        case 1:
            Fsoft.setEmployeeNameList(readFromFile(file));
            cout << "Da nhap danh sach ten nhan vien thanh cong!\n";
            break;

        case 2:
            Fsoft.setEmployeeList();
            break;
        case 3:
            Fsoft.nameSort();
            cout << "Da sap xep danh sach ten nhan vien. Ban co muon xem khong? (y: Xem/n: Quay lai): ";
            cin >> choosePrint;
            if (choosePrint == 'y') Fsoft.displayEmployeeName();
            break;
        case 4:
            Fsoft.displayEmployeeName();
            break;
        case 5:
            Fsoft.idSort();
            cout << "Da sap xep danh sach nhan vien theo ma so. Ban co muon xem khong? (y: Xem/n: Quay lai): ";
            cin >> choosePrint;
            if (choosePrint == 'y') Fsoft.ShowInformationList();
            break;
        case 6:
            Fsoft.ShowInformationList();
            break;
        case 7:
            int num;
            cout << "Nhap so luong nhan vien can them: "; cin >> num;
            for (int i = 0; i < num; i++) Fsoft.setEmployee();
            cout << "Da them " << num << " nhan vien vao danh sach!\n";
            break;
        case 8:
            int choose;
            do choose = Fsoft.deleteFromEmployeeList();
            while (choose == 1);
            break;
        case 9:
            char chooseSearch;
            do {
                Fsoft.searchEmployeeWithId();
                cout << "Ban co muon tim kiem them nhan vien khong? (y: Tim/n: Quay lai): ";
                cin >> chooseSearch;
            } while (chooseSearch == 'y');
            break;
        default:
            break;
        }
    } while (choice != 0);
    fclose(file);
    return 0;
}
