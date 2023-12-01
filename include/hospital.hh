#ifndef HOSPITAL
#define HOSPITAL
using namespace std;
#include <string>
#include <vector>
#include <map>

#include "./doctor.hh"
#include "./patient.hh"
#include "./nurse.hh"
#include "./driver.hh"
#include "./ambulance.hh"
#include "./appointment.hh"
#include "./bed_manage.hh"
#include "./medicine.hh"
#include "./prescription.hh"

class hospital
{
private:
    //map<id, object>
    static map<int, doctor> doctorsList;
    static map<int, patient> patientsList;
    static map<int, nurse> nursesList;
    static map<int, driver> driversList;
    static map<int, ambulance> ambulancesList;
    static map<int, appointment> appointmentsList;
    static map<int, appointment> online_appointmentsList;
    static map<int, bed> bedsList;
    static map<int, medicine> medicinesList;
    static map<int, prescription> prescriptionsList;

    static string admin_chief[3];
    static string admin_patient[3];
    static string admin_doctor[3];
    static string admin_nurse[3];
    static string admin_driver[3];
    static string admin_ambulance[3];
    static string admin_bed[3];


    static const int doctorsLimit;
    static const int nursesLimit;
    static const int driversLimit;
    static const int ambulancesLimit;
    static const int appointmentsLimit;

    friend class doctor;
    friend class patient;
    friend class nurse;
    friend class driver;
    friend class ambulance;
    friend class appointment;
    friend class bed;
    friend class medicine;
    friend class prescription;

public:
    static void printDoctors();
    static void printPatients();
    static void printNurses();
    static void printDrivers();
    static void printAmbulances();
    static void printAppointments();
    static void printBeds();
    static void fill_admin();
    static void reset_passwords();
    static void printMedicine();
    static void printPrescription();
};

#endif // !HOSPITAL