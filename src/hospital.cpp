using namespace std;
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/doctor.hh"
#include "./../include/patient.hh"
#include "./../include/nurse.hh"
#include "./../include/driver.hh"
#include "./../include/ambulance.hh"
#include "./../include/appointment.hh"
#include "./../include/hospital.hh"

//defining already declared static members in the global scope;

map<int, doctor> hospital::doctorsList;
map<int, patient> hospital::patientsList;
map<int, nurse> hospital::nursesList;
map<int, driver> hospital::driversList;
map<int, ambulance> hospital::ambulancesList;
map<int, appointment> hospital::appointmentsList;
map<int, appointment> hospital::online_appointmentsList;
map<int, bed> hospital::bedsList;

string hospital::admin_chief[3];
string hospital::admin_patient[3];
string hospital::admin_doctor[3];
string hospital::admin_nurse[3];
string hospital::admin_driver[3];
string hospital::admin_ambulance[3];
string hospital::admin_bed[3];

const int hospital::doctorsLimit = 30;
const int hospital::nursesLimit = 50;
const int hospital::driversLimit = 30;
const int hospital::ambulancesLimit = 30;
const int hospital::appointmentsLimit = 240; //per day;
// ummm, patients limit, ummm, no!
// appointments limit is kind of a patients limit;
// rest hospitalized patients limit must be equal to;
// number of available rooms, maybe I'll add this;
// feature some other day in the future;
// not feeling like doing it right now!

//defining already declared methods;

void hospital::printDoctors()
{
    string admin_name;
    string admin_pw;
    cout<<"Please get the admin root firstly.\n";
    cout<<"Enter admin name: \n";
    cin>>admin_name;
    cout<<"Enter admin password: \n";
    cin>>admin_pw;
    if(admin_name==hospital::admin_doctor[0]&&admin_pw==hospital::admin_doctor[1]){
        cout<<"Welcome to the admin_doctor root.\n";
        cout<<"Here are all the doctors:\n";
        for (auto i : doctorsList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else if(admin_name==hospital::admin_chief[0]&&admin_pw==hospital::admin_chief[1]){
        cout<<"Welcome to the admin root.\n";
        cout<<"Here are all the doctors:\n";
        for (auto i : doctorsList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else{
        cout<<"Wrong admin name or password.\n";
    }
    
}
void hospital::printPatients()
{
    string admin_name;
    string admin_pw;
    cout<<"Please get the admin root firstly.\n";
    cout<<"Enter admin name: \n";
    cin>>admin_name;
    cout<<"Enter admin password: \n";
    cin>>admin_pw;
    //cout<<hospital::admin_chief[0]<<hospital::admin_chief[1]<<endl;
    if(admin_name==hospital::admin_patient[0]&&admin_pw==hospital::admin_patient[1]){
        cout<<"Welcome to the admin_patient root.\n";
        cout<<"Here are all the patients:\n";
        for (auto i : patientsList)
            i.second.printDetails(), cout << "\n";
        return;
    }

    else if(admin_name==hospital::admin_chief[0]&&admin_pw==hospital::admin_chief[1]){
        cout<<"Welcome to the admin root.\n";
        cout<<"Here are all the patients:\n";
        for (auto i : patientsList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else{
        cout<<"Wrong admin name or password.\n";
    }
    
}
void hospital::printNurses()
{
    string admin_name;
    string admin_pw;
    cout<<"Please get the admin root firstly.\n";
    cout<<"Enter admin name: \n";
    cin>>admin_name;
    cout<<"Enter admin password: \n";
    cin>>admin_pw;
    if(admin_name==hospital::admin_nurse[0]&&admin_pw==hospital::admin_nurse[1]){
        cout<<"Welcome to the admin_nurse root.\n";
        cout<<"Here are all the nurses:\n";
        for (auto i : nursesList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else if(admin_name==hospital::admin_chief[0]&&admin_pw==hospital::admin_chief[1]){
        cout<<"Welcome to the admin root.\n";
        cout<<"Here are all the nurses:\n";
        for (auto i : nursesList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else{
        cout<<"Wrong admin name or password.\n";
    }
    
}
void hospital::printDrivers()
{
    string admin_name;
    string admin_pw;
    cout<<"Please get the admin root firstly.\n";
    cout<<"Enter admin name: \n";
    cin>>admin_name;
    cout<<"Enter admin password: \n";
    cin>>admin_pw;
    if(admin_name==hospital::admin_driver[0]&&admin_pw==hospital::admin_driver[1]){
        cout<<"Welcome to the admin_driver root.\n";
        cout<<"Here are all the drivers:\n";
        for (auto i : driversList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else if(admin_name==hospital::admin_chief[0]&&admin_pw==hospital::admin_chief[1]){
        cout<<"Welcome to the admin root.\n";
        cout<<"Here are all the drivers:\n";
        for (auto i : driversList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else{
        cout<<"Wrong admin name or password.\n";
    }
    
}
void hospital::printAmbulances()
{
    string admin_name;
    string admin_pw;
    cout<<"Please get the admin root firstly.\n";
    cout<<"Enter admin name: \n";
    cin>>admin_name;
    cout<<"Enter admin password: \n";
    cin>>admin_pw;
    if(admin_name==hospital::admin_ambulance[0]&&admin_pw==hospital::admin_ambulance[1]){
        cout<<"Welcome to the admin_ambulance root.\n";
        cout<<"Here are all the ambulances:\n";
        for (auto i : ambulancesList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else if(admin_name==hospital::admin_chief[0]&&admin_pw==hospital::admin_chief[1]){
        cout<<"Welcome to the admin root.\n";
        cout<<"Here are all the ambulances:\n";
        for (auto i : ambulancesList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else{
        cout<<"Wrong admin name or password.\n";
    }
    
}
void hospital::printAppointments()
{
    
    //cout<<"mmmmmmmmmm";
    string admin_name;
    string admin_pw;
    cout<<"Please get the admin root firstly.\n";
    cout<<"Enter admin name: \n";
    cin>>admin_name;
    cout<<"Enter admin password: \n";
    cin>>admin_pw;
    if(admin_name==hospital::admin_chief[0]&&admin_pw==hospital::admin_chief[1]){
        cout<<"Welcome to the admin root.\n";
        cout<<"Here are all the appointments:\n";
        for (auto i : appointmentsList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else{
        cout<<"Wrong admin name or password.\n";
    }
}
void hospital::printBeds()
{
    
    //cout<<"mmmmmmmmmm";
    string admin_name;
    string admin_pw;
    cout<<"Please get the admin root firstly.\n";
    cout<<"Enter admin name: \n";
    cin>>admin_name;
    cout<<"Enter admin password: \n";
    cin>>admin_pw;
    if(admin_name==hospital::admin_chief[0]&&admin_pw==hospital::admin_chief[1]){
        cout<<"Welcome to the admin root.\n";
        cout<<"Here are all the beds:\n";
        for (auto i : bedsList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else if(admin_name==hospital::admin_bed[0]&&admin_pw==hospital::admin_bed[1]){
        cout<<"Welcome to the admin_bed root.\n";
        cout<<"Here are all the beds:\n";
        for (auto i : bedsList)
            i.second.printDetails(), cout << "\n";
        return;
    }
    else{
        cout<<"Wrong admin name or password.\n";
    }
   
}
void hospital::fill_admin(){
    fstream f;
    f.open("./data/admin.csv", ios::in);
    string temp;
    getline(f >> ws,temp);
    int line_num=0;
    while(getline(f >> ws, temp)){
        stringstream s(temp);
        string s1,s2,s3;
        getline(s,s1,',');
        getline(s,s2,',');
        getline(s,s3,',');
        if(line_num==0){
            hospital::admin_chief[0]=s1;
            hospital::admin_chief[1]=s2;                                                                    
            hospital::admin_chief[2]=s3;
        }
        if(line_num==1){
            hospital::admin_patient[0]=s1;
            hospital::admin_patient[1]=s2;                                                                    
            hospital::admin_patient[2]=s3;
        }
        if(line_num==2){
            hospital::admin_doctor[0]=s1;
            hospital::admin_doctor[1]=s2;                                                                    
            hospital::admin_doctor[2]=s3;
        }
        if(line_num==3){
            hospital::admin_nurse[0]=s1;
            hospital::admin_nurse[1]=s2;                                                                    
            hospital::admin_nurse[2]=s3;
        }
        if(line_num==4){
            hospital::admin_driver[0]=s1;
            hospital::admin_driver[1]=s2;                                                                    
            hospital::admin_driver[2]=s3;
        }
        if(line_num==5){
            hospital::admin_ambulance[0]=s1;
            hospital::admin_ambulance[1]=s2;                                                                    
            hospital::admin_ambulance[2]=s3;
        }
        if(line_num==6){
            hospital::admin_bed[0]=s1;
            hospital::admin_bed[1]=s2;                                                                    
            hospital::admin_bed[2]=s3;
        }
        line_num++;
    }
    f.close();
}
void hospital::reset_passwords(){
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/RESET PASSWORDS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Reset patient password\n";
        cout << "[02] : Reset doctor password\n";
        cout << "[03] : Reset nurse password\n\n";
       // cout << "[04] : Forgot patient password\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            cout<<"Please enter the patient id.\n";
            int id;
            cin>>id;

            if(patientsList.find(id)==patientsList.end()){
                cout<<"No such patient.\n";
                return;
            }
            else{
                cout<<"If you forget your password, please contact the admin.(input Y|N)\n";
                string choice;
                cin>>choice;
                if(choice=="Y"||choice=="y"){
                    cout<<"Please enter the admin name.\n";
                    string admin_name;
                    cin>>admin_name;
                    if(admin_name==hospital::admin_patient[0]){
                        cout<<"Please enter the admin password.\n";
                        string admin_pw;
                        cin>>admin_pw;
                        if(admin_pw==hospital::admin_patient[1]){
                            cout<<"Please enter the new password.\n";
                            string new_pw;
                            cin>>new_pw;
                            patientsList[id].password=new_pw;
                            cout<<"Password reset successfully.\n";
                            return;
                        }
                        else{
                            cout<<"Wrong admin password.\n";
                            return;
                        }
                    }
                    else{
                        cout<<"Wrong admin name.\n";
                        return;
                    }
                }
                else{
                    cout<<"Please enter the old password.\n";
                    string old_pw;
                    cin>>old_pw;
                    if(old_pw!=patientsList[id].password){
                        cout<<"Wrong password.\n";
                        return;
                    }
                    string new_pw;
                    cout<<"Please enter the new password.\n";
                    cin>>new_pw;
                    patientsList[id].password=new_pw;
                    cout<<"Password reset successfully.\n";
                    return;
                }
                
            }
        }
        else if (purpose == 2)
        {
            cout<<"Please enter the doctor id.\n";
            int id;
            cin>>id;
            if(doctorsList.find(id)==doctorsList.end()){
                cout<<"No such doctor.\n";
                return;
            }
            else{
                cout<<"If you forget your password, please contact the admin.(input Y|N)\n";
                string choice;
                cin>>choice;
                if(choice=="Y"||choice=="y"){
                    cout<<"Please enter the admin name.\n";
                    string admin_name;
                    cin>>admin_name;
                    if(admin_name==hospital::admin_doctor[0]){
                        cout<<"Please enter the admin password.\n";
                        string admin_pw;
                        cin>>admin_pw;
                        if(admin_pw==hospital::admin_doctor[1]){
                            cout<<"Please enter the new password.\n";
                            string new_pw;
                            cin>>new_pw;
                            doctorsList[id].password=new_pw;
                            cout<<"Password reset successfully.\n";
                            return;
                        }
                        else{
                            cout<<"Wrong admin password.\n";
                            return;
                        }
                    }
                    else{
                        cout<<"Wrong admin name.\n";
                        return;
                    }
                }
                string old_pw;
                cout<<"Please enter the old password.\n";
                cin>>old_pw;
                if(old_pw!=doctorsList[id].password){
                    cout<<"Wrong password.\n";
                    return;
                }
                string new_pw;
                cout<<"Please enter the new password.\n";
                cin>>new_pw;
                doctorsList[id].password=new_pw;
                cout<<"Password reset successfully.\n";
                return;
            }
        }
        else if (purpose == 3)
        {
           cout<<"Please enter the nurse id.\n";
            int id;
            cin>>id;
            if(nursesList.find(id)==nursesList.end()){
                cout<<"No such nurse.\n";
                return;
            }
            else{
                cout<<"If you forget your password, please contact the admin.(input Y|N)\n";
                string choice;
                cin>>choice;
                if(choice=="Y"||choice=="y"){
                    cout<<"Please enter the admin name.\n";
                    string admin_name;
                    cin>>admin_name;
                    if(admin_name==hospital::admin_nurse[0]){
                        cout<<"Please enter the admin password.\n";
                        string admin_pw;
                        cin>>admin_pw;
                        if(admin_pw==hospital::admin_nurse[1]){
                            cout<<"Please enter the new password.\n";
                            string new_pw;
                            cin>>new_pw;
                            nursesList[id].password=new_pw;
                            cout<<"Password reset successfully.\n";
                            return;
                        }
                        else{
                            cout<<"Wrong admin password.\n";
                            return;
                        }
                    }
                    else{
                        cout<<"Wrong admin name.\n";
                        return;
                    }
                }
                string old_pw;
                cout<<"Please enter the old password.\n";
                cin>>old_pw;
                if(old_pw!=nursesList[id].password){
                    cout<<"Wrong password.\n";
                    return;
                }
                string new_pw;
                cout<<"Please enter the new password.\n";
                cin>>new_pw;
                nursesList[id].password=new_pw;
                cout<<"Password reset successfully.\n";
                return;
            }
        }
        
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;

}