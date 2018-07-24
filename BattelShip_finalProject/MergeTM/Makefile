g++ -c BattleShip_main.cpp GameManager.cpp Pane.cpp StatPane.cpp InputPane.cpp Ship.cpp Map.cpp Player.cpp AirCraft.cpp BattleShip.cpp Cruiser.cpp Destroyer.cpp

CC = g++ -std=c++11
TARGET = battle
SOURCES = BattleShip_main.cpp \
	GameManager.cpp \
	Pane.cpp \
	StatPane.cpp \
	InputPane.cpp \
	Ship.cpp \
	Map.cpp \
	Player.cpp \
	AirCraft.cpp \
	BattleShip.cpp \
	Cruiser.cpp \
	Destroyer.cpp
	
LDFLAGS = -Incurses
all:
	g++ -std=c++11 hello Helloworld.cpp -lncursesw
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf*.o $(TARGET)
	