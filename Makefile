OPT = -g -Wall

a3: main.o Student.o Course.o Registration.o CourseArray.o StuArray.o RegList.o School.o Control.o View.o
	g++ -o a3 main.o Student.o Course.o Registration.o CourseArray.o StuArray.o RegList.o School.o Control.o View.o

main.o: main.cc Control.h
	g++ $(OPT) -c main.cc

Student.o: Student.cc Student.h
	g++ $(OPT) -c Student.cc

Course.o: Course.cc Course.h 
	g++ $(OPT) -c Course.cc

Registration.o: Registration.cc Registration.h
	g++ $(OPT) -c Registration.cc

CourseArray.o: CourseArray.cc CourseArray.h
	g++ $(OPT) -c CourseArray.cc 

StuArray.o: StuArray.cc StuArray.h
	g++ $(OPT) -c StuArray.cc

RegList.o: RegList.cc RegList.h 
	g++ $(OPT) -c RegList.cc

School.o: School.cc School.h
	g++ $(OPT) -c School.cc

Control.o: Control.cc Control.h
	g++ $(OPT) -c Control.cc

View.o: View.cc View.h
	g++ $(OPT) -c View.cc

clean: 
	rm -f *.o a3