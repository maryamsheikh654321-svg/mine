#include<iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int m_employees=100;
const int m_namelenghth=100;
char *names[m_employees];
int *ids= new int[m_employees];
int *presentdays=new int[m_employees];
int *absentdays=new int[m_employees];
int employeecount=0;
// Add employee function
void addemployee(){
    if(employeecount<m_employees){
        names[employeecount]=new char[m_namelenghth];
        cout<<"Enter employee name: ";
        cin>>names[employeecount];
        cout<<"Enter employee ID: ";
        cin>>ids[employeecount];
        presentdays[employeecount]=0;
        absentdays[employeecount]=0;
        employeecount++;
        cout<<"Employee added successfully!"<<endl;
    }else{
        cout<<"Maximum employee limit reached!"<<endl;
    }
}
// Mark attendance function
void markattendance(){
    int id;
    cout<<"Enter employee ID: ";
    cin>>id;
    for(int i=0;i<employeecount;i++){
        if(ids[i]==id){
            char status;
            cout<<"Enter attendance status (P for present, A for absent): ";
            cin>>status;
            if(status=='P'||status=='p'){
                presentdays[i]++;
                cout<<"Attendance marked as present!"<<endl;
            }else if(status=='A'||status=='a'){
                absentdays[i]++;
                cout<<"Attendance marked as absent!"<<endl;
            }else{
                cout <<"Invalid input.Please enter P for present or A for absent."<<endl;
            }
            return;
        }
    }
    cout<<"Employee not found!"<<endl;
}
// Save to file function
void savetofile(){
    ofstream file("employee_data.txt");
    if (file.is_open()){
        for(int i=0;i<employeecount;i++){
            file<<setw(20)<<"Employee Name: "<<names[i]<<endl;
            file<<setw(20)<<"Employee ID: "<<ids[i]<<endl;
            file<<setw(20)<<"Days Present:"<<presentdays[i]<<endl;
            file<<setw(20)<<"Days Absent: "<<absentdays[i]<<endl;
            if(presentdays[i]+absentdays[i]>0){
                file<<setw(20)<<"Attendance Percentage: "<<(float)presentdays[i]/(presentdays[i]+absentdays[i])* 100<<"%"<<endl;
            }else{
                file<<setw(20)<<"Attendance Percentage: N/A"<<endl;
            }
            file<<endl;
        }
        file.close();
        cout<<"Data saved to file successfully!"<<endl;
    }else{
        cout<<"Unable to open file!"<<endl;
    }
}
// Attendance report function
void attendancereport(){
    cout<<setw(20)<<"Employee Name"<<setw(20)<<"Employee ID"<<setw(20)<<"Days Present"<<setw(20)<<"Days Absent"<<setw(20)<<"Attendance Percentage"<<endl;
    for(int i=0;i<employeecount;i++){
        float attendancepercentage=0.0;
        if(presentdays[i]+absentdays[i]>0){
        attendancepercentage=(float)presentdays[i]/(presentdays[i]+absentdays[i])*100;
        }
        cout<<setw(20)<<names[i]<<setw(20)<<ids[i]<<setw(20)<<presentdays[i]<<setw(20)<<absentdays[i]<<setw(20)<<attendancepercentage<<"%"<<endl;
    }
}
// Employee Search function
void searchemployee(){
    int id;
    cout<<"Enter employee ID: ";
    cin>>id;
    for(int i=0;i<employeecount;i++){
        if(*(ids+i)==id){
            cout<<setw(20)<<"Employee Name: "<<*(names+i)<<endl;
            cout<<setw(20)<<"Employee ID: "<<*(ids+i)<<endl;
            cout<<setw(20)<<"Days Present: "<<*(presentdays+i)<<endl;
            cout<<setw(20)<<"Days Absent: "<<*(absentdays+i)<<endl;
            return;
        }
    }
    cout << "Employee not found!" << endl;
}
// Employee Update function
void updateemployee(){
    int id;
    cout<<"Enter employee ID: ";
    cin>>id;
    for(int i=0;i<employeecount;i++){
        if(*(ids+i)==id){
            cout<<"Enter new employee name: ";
            cin>>*(names+i);
            cout<<"Employee updated successfully!"<<endl;
            return;
        }
    }
    cout<<"Employee not found!"<<endl;
}
// Employee Delete function
void deleteemployee(){
    int id;
    cout<<"Enter employee ID: ";
    cin>>id;
    for(int i=0;i<employeecount;i++){
        if(*(ids+i)==id){
            delete[] names[i];
            for(int j=i;j<employeecount-1;j++){
                *(names+j)=*(names+j+1);
                *(ids+j)=*(ids+j+1);
                *(presentdays+j)=*(presentdays+j+1);
                *(absentdays+j)=*(absentdays+j+1);
            }
            employeecount--;
            cout<<"Employee deleted successfully!"<<endl;
            return;
        }
    }
    cout<<"Employee not found!"<<endl;
}
int main(){
    int choice;
    do{
        cout<<"Employee Attendance Tracker"<<endl;
        cout<<"1. Add Employee"<<endl;
        cout<<"2. Mark Attendance"<<endl;
        cout<<"3. Attendance Report"<<endl;
        cout<<"4. Delete Employee"<<endl;
        cout<<"5. Save to File"<<endl;
        cout<<"6. Search Employee"<<endl;
        cout<<"7. Update Employee"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                addemployee();
                break;
            case 2:
                markattendance();
                break;
            case 3:
                attendancereport();
                break;
            case 4:
                deleteemployee();
                break;
            case 5:
                savetofile();
                break;
            case 6:
                searchemployee();
                break;
            case 7:
                updateemployee();
                break;
            case 8:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice.Please choose a valid option."<<endl;
        }
    }while(choice!=8);
    return 0;
}