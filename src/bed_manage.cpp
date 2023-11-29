using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/bed_manage.hh"
#include "./../include/hospital.hh"

bed::bed()
{
    id = -1;
    P.id = 0;
    N.id = 0;
    occupied = false;
}

bed::~bed()
{
    id = -1;
    P.id = 0;
    N.id = 0;
    occupied = false;
    return;
}

void bed::fillMap()
{
    fstream f;
    f.open("./data/bed_manage.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    //int line_num = 1;
    while (getline(f >> ws, temp))
    {
        bed b;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s2, s3, s4;
        //reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, s2, ',');
        getline(s, s3, ',');
        getline(s, s4, ',');
        b.id = strToNum(s1);
        b.P = hospital::patientsList[strToNum(s2)];
        b.N = hospital::nursesList[strToNum(s3)];
        b.pid=strToNum(s2);
        b.nid=strToNum(s3);
        b.occupied = strToNum(s4);
        hospital::bedsList[b.id] = b;
    }
    f.close();
    return;
}

void bed::saveMap()
{
    fstream f;
    f.open("./data/bed_manage.csv", ios::out);
    f << "id,patient_id,nurse_id,occupied\n";
    for (auto i : hospital::bedsList)
    {
        f << i.first << "," << i.second.pid << "," << i.second.nid << "," << i.second.occupied << "\n";
    }
    f.close();
    return;
}
void bed::printDetails()
{
    if(id==-1)return;
    cout << "Bed ID: " << id << "\n";
    cout << "Patient ID: " << pid << "\n";
    cout << "Nurse ID: " << nid << "\n";
    cout << "Occupied: " << occupied << "\n";
    return;
}
void bed::book()
{
    //int id;
    
    
    for(auto i:hospital::bedsList){
        
        if(i.second.occupied==0){
            id=i.first;
            break;
        }
        
        
    }
    
    if (id>10)
        return void(cout << "Sorry, the beds is full.\n");
    cout << "Enter patient ID: \n";
    int pid;
    cin >> pid;
    if (hospital::patientsList.find(pid) == hospital::patientsList.end())
        return void(cout << "Sorry, no such patient exists.\n");
    P = hospital::patientsList[pid];
    cout << "Enter nurse ID: \n";
    int nid;
    cin >> nid;
    if (hospital::nursesList.find(nid) == hospital::nursesList.end())
        return void(cout << "Sorry, no such nurse exists.\n");
    N = hospital::nursesList[nid];
    occupied = true;
    hospital::bedsList[id] = *this;
    cout<<"Bed booked successfully.\n";
    cout<<"Bed ID: "<<id<<"\n";
    return;
}

void bed::unhospitalize()
{
   cout<<"Enter bed ID: \n";
    int id;
    cin>>id;
    if(hospital::bedsList.find(id)==hospital::bedsList.end()){
        cout<<"No such bed exists.\n";
        return;        
    }
    else if(!hospital::bedsList[id].occupied){
        hospital::bedsList[id].occupied=0;
        hospital::bedsList[id].P.id=-1;
        hospital::bedsList[id].N.id=-1;
    }
    cout<<"Patient unhospitalized successfully.\n";
    return;
}
void bed::getDetails()
{
    
    cout << "Enter bed ID: \n";
    cin >> id;
    if (hospital::bedsList.find(id) == hospital::bedsList.end())
        return void(cout << "Sorry, no such bed exists.\n");
    hospital::bedsList.find(id)->second.printDetails();
}

