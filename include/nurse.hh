#ifndef NURSE
#define NURSE
using namespace std;
#include <string>

#include "./person.hh"
class bed;
class nurse : public person
{
private:
    string type;
    friend class bed;
    string password;
    friend class hospital;
public:
    nurse();
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void removePerson();
    void lookForBed();
};
#endif // !NURSE