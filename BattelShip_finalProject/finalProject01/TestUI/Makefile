CC = g++ -std=c++11
TARGET = TestBattleShipGame
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
	
LDFLAGS = -lncursesw
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf*.o $(TARGET)
	


	
