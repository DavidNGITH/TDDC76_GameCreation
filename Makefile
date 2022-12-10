CC=g++ -std=c++17 -g
CCFLAGS= -c -Wall -Wextra -Wpedantic -Weffc++ -Wold-style-cast
LIBS:= -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp


MAIN=main
FILE1=menu_state
FILE2=game_state
FILE3=map
FILE4=game_object
FILE5=hud
FILE6=player
FILE7=missile
FILE8=powerup
FILE9=Helicopter
FILE10=static_object
FILE11=standard_missile
FILE12=shower_missile
FILE13=Mine
FILE14=split_missile
FILE15=end_state
FILE16=test_main
FILE17=test_case



OBJS= $(MAIN).o $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o $(FILE5).o $(FILE6).o $(FILE7).o $(FILE9).o $(FILE10).o $(FILE8).o $(FILE11).o $(FILE12).o $(FILE13).o $(FILE14).o $(FILE15).o
OBJS1= $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o $(FILE5).o $(FILE6).o $(FILE7).o $(FILE9).o $(FILE10).o $(FILE8).o $(FILE11).o $(FILE12).o $(FILE13).o $(FILE14).o $(FILE15).o






output: $(OBJS)
	$(CC) $(OBJS) -o a.out $(LIBS)

$(MAIN).o: $(MAIN).cc
	$(CC) $(CCFLAGS) $(MAIN).cc $(LIBS)

$(FILE1).o: $(FILE1).cc
	$(CC) $(CCFLAGS) $(FILE1).cc $(LIBS)

$(FILE2).o: $(FILE2).cc
	$(CC) $(CCFLAGS) $(FILE2).cc $(LIBS)

$(FILE3).o: $(FILE3).cc
	$(CC) $(CCFLAGS) $(FILE3).cc $(LIBS)

$(FILE4).o: $(FILE4).cc
	$(CC) $(CCFLAGS) $(FILE4).cc $(LIBS)

$(FILE5).o: $(FILE5).cc
	$(CC) $(CCFLAGS) $(FILE5).cc $(LIBS)

$(FILE6).o: $(FILE6).cc
	$(CC) $(CCFLAGS) $(FILE6).cc $(LIBS)

$(FILE7).o: $(FILE7).cc
	$(CC) $(CCFLAGS) $(FILE7).cc $(LIBS)

$(FILE8).o: $(FILE8).cc
	$(CC) $(CCFLAGS) $(FILE8).cc $(LIBS)

$(FILE9).o: $(FILE9).cc
	$(CC) $(CCFLAGS) $(FILE9).cc $(LIBS)

$(FILE10).o: $(FILE10).cc
	$(CC) $(CCFLAGS) $(FILE10).cc $(LIBS)

$(FILE11).o: $(FILE11).cc
	$(CC) $(CCFLAGS) $(FILE11).cc $(LIBS)

$(FILE12).o: $(FILE12).cc
	$(CC) $(CCFLAGS) $(FILE12).cc $(LIBS)

$(FILE13).o: $(FILE13).cc
	$(CC) $(CCFLAGS) $(FILE13).cc $(LIBS)
	
$(FILE14).o: $(FILE14).cc
	$(CC) $(CCFLAGS) $(FILE14).cc $(LIBS)

$(FILE15).o: $(FILE15).cc
	$(CC) $(CCFLAGS) $(FILE15).cc $(LIBS)

$(FILE16).o: $(FILE16).cc
	$(CC) $(CCFLAGS) $(FILE16).cc $(LIBS)

$(FILE17).o: $(FILE17).cc
	$(CC) $(CCFLAGS) $(FILE17).cc $(LIBS)
clean:
	rm *.o a.out

test: $(FILE16).o $(FILE17).o $(OBJS1)
	$(CC) $(FILE16).o $(FILE17).o $(OBJS1) -o test.out $(LIBS)


