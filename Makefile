all: main.cpp ./src/global.cpp ./src/hospital.cpp ./src/address.cpp ./src/person.cpp ./src/doctor.cpp ./src/patient.cpp ./src/appointment.cpp ./src/nurse.cpp ./src/driver.cpp ./src/ambulance.cpp ./src/bed_manage.cpp ./src/medicine.cpp ./src/prescription.cpp
	g++ -o "./build/hms" main.cpp ./src/global.cpp ./src/hospital.cpp ./src/address.cpp ./src/person.cpp ./src/doctor.cpp ./src/patient.cpp ./src/appointment.cpp ./src/nurse.cpp ./src/driver.cpp ./src/ambulance.cpp ./src/bed_manage.cpp ./src/medicine.cpp ./src/prescription.cpp

run:
	./build/hms

clean:
	rm -f ./build/*

clean(win):
	del /f build\*

headers: ./include/address.hh ./include/ambulance.hh ./include/appointment.hh ./include/doctor.hh ./include/driver.hh ./include/global.hh ./include/hospital.hh ./include/nurse.hh ./include/patient.hh ./include/person.hh ./include/bed_manage.hh ./include/medicine.hh ./include/prescription.hh
	g++ ./include/address.hh ./include/ambulance.hh ./include/appointment.hh ./include/doctor.hh ./include/driver.hh ./include/global.hh ./include/hospital.hh ./include/nurse.hh ./include/patient.hh ./include/person.hh ./include/bed_manage.hh ./include/medicine.hh ./include/prescription.hh