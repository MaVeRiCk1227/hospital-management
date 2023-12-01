#ifndef MED_MANAGE
#define MED_MANAGE
using namespace std;

#include "./patient.hh"
#include "./doctor.hh"
#include "./medicine.hh"

class medicine
{
private:
    int id;
    string name;
    string userfor;
    friend class patient;
    friend class doctor;
    friend class prescription;
    //friend class hospital;
public:
    medicine();
    ~medicine();
    void fillMap();
    void saveMap();
    void printDetails();
};
#endif // !BED_MANAGE
