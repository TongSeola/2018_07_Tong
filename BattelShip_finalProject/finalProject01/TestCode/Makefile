CC = g++ -std=c++11
TARGET = TestBattleShipGame
SOURCES = BattleShip_main.cpp \
	GameManager.cpp \
	Ship.cpp \
	Map.cpp \
	Player.cpp 
	
LDFLAGS = -lncurses
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf*.o $(TARGET)
	


	
