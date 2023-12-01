using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/prescription.hh"
#include "./../include/hospital.hh"

prescription::prescription()
{
    id = -1;
    D.id = 0;
    P.id = 0;
    for(int i=0;i<20;i++)med_list[i]=0;
    using_method = "";

}
prescription::~prescription()
{
    id = -1;
    D.id = 0;
    P.id = 0;
    for(int i=0;i<20;i++)med_list[i]=0;
    using_method = "";
    return;
}
void prescription::fillMap()
{
    fstream f;
    f.open("./data/prescription.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        prescription p;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s2, s3, s4, s5;
        //reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, s2, ',');
        getline(s, s3, ',');
        getline(s, s5, ',');
        getline(s, s4, ',');
        p.id = strToNum(s1);
        p.D = hospital::doctorsList[strToNum(s2)];
        p.P = hospital::patientsList[strToNum(s3)];
        p.pid=strToNum(s3);
        p.did=strToNum(s2);
        p.using_method = s4;
        int i=0;
        stringstream ss(s5);
        string temp1;
        while(getline(ss,temp1,'.'))
        {
            p.med_list[i]=strToNum(temp1);
            i++;
        }
        hospital::prescriptionsList[p.id] = p;
    }
    f.close();
    return;
}
void prescription::saveMap()
{
    fstream f;
    f.open("./data/prescription.csv", ios::out);
    f << "id,doctor_id,patient_id,med_list,using_method\n";
    for (auto i : hospital::prescriptionsList)
    {
        f << i.second.id << "," << i.second.D.id << "," << i.second.P.id <<",";
        for(int j=0;j<20;j++)
        {
            if(i.second.med_list[j]!=0)
            {
                f<<i.second.med_list[j]<<".";
            }
        }
        f<<","<<i.second.using_method;
        f<<"\n";
    }
    f.close();
    return;
}
void prescription::printDetails()
{
    if(id<1){
        cout<<"Enter prescription ID: ";
        cin>>id;
        if(id<1||hospital::prescriptionsList.find(id)==hospital::prescriptionsList.end())
        {
            cout<<"Prescription ID not found!\n";
            return;
        }
        *this=hospital::prescriptionsList[id];
    }
    
    cout << "Prescription ID: " << id << "\n";
    cout << "Doctor ID: " << D.id << "\n";
    cout << "Patient ID: " << P.id << "\n";
    cout << "Medicine List: ";
    for(int i=0;i<20;i++)
    {
        if(med_list[i]!=0)
        {
            cout<<med_list[i]<<",";
        }
    }
    cout<<"\n";
    cout << "Using Method: " << using_method << "\n";
    return;
}

void prescription::prescript()
{
    int pid, did;
    cout << "Enter Patient ID: ";
    cin >> pid;
    cout << "Enter Doctor ID: ";
    cin >> did;
    if (pid<=0||hospital::patientsList.find(pid) == hospital::patientsList.end())
    {
        cout << "Patient ID not found!\n";
        return;
    }
    if (did<=0||hospital::doctorsList.find(did) == hospital::doctorsList.end())
    {
        cout << "Doctor ID not found!\n";
        return;
    }
    string password;
    cout<<"Entet doctor password: ";
    cin>>password;
    if(password!=hospital::doctorsList[did].password)
    {
        cout<<"Wrong password!\n";
        return;
    }
    cout<<"Correct password!\n";
    prescription p;
    p.id = hospital::prescriptionsList.size() + 1;
    p.P = hospital::patientsList[pid];
    p.D = hospital::doctorsList[did];
    p.pid=pid;
    p.did=did;
    cout << "Enter Medicine List (Enter 0 to stop): ";
    int i = 0;
    while (1)
    {
        cin >> p.med_list[i];
        if (p.med_list[i] == 0)
            break;
        i++;
    }
    cout << "Enter Using Method: ";
    cin >> p.using_method;
    hospital::prescriptionsList[p.id] = p;
    cout << "Prescription ID: " << p.id << "\n";
    return;
}