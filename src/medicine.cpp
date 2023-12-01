using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/medicine.hh"
#include "./../include/hospital.hh"

medicine::medicine()
{
    id = -1;
    name = "";
}

medicine::~medicine()
{
    id = -1;
    name = "";
    return;
}

void medicine::fillMap()
{
    fstream f;
    f.open("./data/medicine.csv", ios::in);
    string temp;
    
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        medicine m;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s2, s3;
        //reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, s2, ',');
        getline(s, s3, ',');
        m.id = strToNum(s1);
        m.name = s2;
        m.userfor = s3;
        hospital::medicinesList[m.id] = m;
    }
    f.close();
    return;
}

void medicine::saveMap()
{
    fstream f;
    f.open("./data/medicine.csv", ios::out);
    f << "id,name,userfor\n";
    for (auto i : hospital::medicinesList)
    {
        f << i.second.id << "," << i.second.name << "," << i.second.userfor << "\n";
    }
    f.close();
    return;
}

void medicine::printDetails()
{
    cout << "id: " << id << "\n";
    cout << "name: " << name << "\n";
    cout << "userfor: " << userfor << "\n";
    return;
}