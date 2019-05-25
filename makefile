CXX = g++ 
CXXFLAGS = -std=c++0x 

SRCS = Space.cpp GamePlay.cpp BedroomOne.cpp BedroomTwo.cpp Den.cpp DiningRoom.cpp Kitchen.cpp FamilyRoom.cpp 
HEADERS = Space.hpp GamePlay.hpp BedroomOne.hpp BedroomTwo.hpp Den.hpp DiningRoom.hpp Kitchen.hpp FamilyRoom.hpp 
TEXT = IntroDisplay.txt YouWin.txt 

MAKE = makefile 

PDF = fileprojectreflection.pdf 

finalproject: ${SRCS}${HEADERS}${TEXT}
	${CXX}${CXXFLAGS}${SRCS}-o finalproject

clean:
	rm *finalproject

zip:
	zip -D FinalProject_Solbrack_Matthew.zip ${SRCS}${HEADERS}${MAKE}${TEXT}${PDF} 



  
