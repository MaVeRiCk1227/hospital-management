#ifndef BED_MANAGE
#define BED_MANAGE
using namespace std;

#include "./patient.hh"
#include "./nurse.hh"

class bed
{
private:
    int id;
    patient P;
    nurse N;
    int pid;
    int nid;
    bool occupied;
    friend class patient;
    friend class nurse;
public:
    bed();
    ~bed();
    void fillMap();
    void saveMap();
    void printDetails();
    void book();
    void unhospitalize();
    void fillDetails();
    void getDetails();
};
#endif // !BED_MANAGE
