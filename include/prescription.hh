#ifndef PRE_MANAGE
#define PRE_MANAGE
using namespace std;

#include "./patient.hh"
#include "./doctor.hh"


class prescription
{
private:
    int id;
    patient P;
    doctor D;
    int pid;
    int did;
    int med_list[20];
    string using_method;
    friend class patient;
    friend class doctor;
   // friend class medicine;
    //friend class hospital;
public:
    prescription();
    ~prescription();
    void fillMap();
    void saveMap();
    void printDetails();
    void prescript();
};
#endif 
