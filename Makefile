
output: Item.o Space.o Game.o Player.o SupplyCloset.o MessHall.o EngineRoom.o SickBay.o TransporterRoom.o Safety.o main.o menu.o getInteger.o readFile.o
	g++ -std=c++11 Item.o Space.o Game.o Player.o SupplyCloset.o MessHall.o EngineRoom.o SickBay.o TransporterRoom.o Safety.o main.o menu.o getInteger.o readFile.o -o output

Item.o: Item.cpp Item.hpp
	g++ -std=c++11 -c Item.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

Player.o: Player.cpp Player.hpp
	g++ -std=c++11 -c Player.cpp

SupplyCloset.o: SupplyCloset.cpp SupplyCloset.hpp
	g++ -std=c++11 -c SupplyCloset.cpp

MessHall.o: MessHall.cpp MessHall.hpp
	g++ -std=c++11 -c MessHall.cpp

EngineRoom.o: EngineRoom.cpp EngineRoom.hpp
	g++ -std=c++11 -c EngineRoom.cpp

SickBay.o: SickBay.cpp SickBay.hpp
	g++ -std=c++11 -c SickBay.cpp

TransporterRoom.o: TransporterRoom.cpp TransporterRoom.hpp
	g++ -std=c++11 -c TransporterRoom.cpp

Safety.o: Safety.cpp Safety.hpp
	g++ -std=c++11 -c Safety.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

getInteger.o: getInteger.cpp getInteger.hpp
	g++ -std=c++11 -c getInteger.cpp

readFile.o: readFile.cpp readFile.hpp
	g++ -std=c++11 -c readFile.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o output
