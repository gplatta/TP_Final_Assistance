:: Compilo el Binario
cd src
g++ -Wall -std=c++11 -c Course.cpp
g++ -Wall -std=c++11 -c Student.cpp 
g++ -Wall -std=c++11 -c CourseMapper.cpp 
g++ -Wall -std=c++11 -c StudentMapper.cpp
g++ -Wall -std=c++11 -c StudentXCourseManager.cpp
g++ -Wall -std=c++11 -c AssistanceManager.cpp
cd ..
g++ -Wall -std=c++11 -c main.cpp 
g++ ./src/Course.o ./src/Student.o ./src/CourseMapper.o ./src/StudentMapper.o ./src/StudentXCourseManager.o ./src/AssistanceManager.o main.o -o Assistance.exe

echo "Programa compilado"
pause

:: Limpio los códigos objeto
DEL .\*.o
