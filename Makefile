CC=g++ -std=c++17
CCFLAGS= -c -Wall -Wextra -Wpedantic -Weffc++ -Wold-style-cast
LIBS:=-lsfml-graphics -lsfml-window -lsfml-system


MAIN=main
FILE1=menu_state
FILE2=game_state
FILE3=map
FILE4=game_object
FILE5=hud
FILE6=player
FILE7=missile
FILE8=power_up
FILE9=Helicopter
FILE10=static_object
FILE11=standard_missile
FILE12=shower_missile
FILE13=repair
FILE14=Shield


OBJS= $(MAIN).o $(FILE1).o $(FILE2).o $(FILE3).o $(FILE4).o $(FILE9).o $(FILE14).o 

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

#$(FILE5).o: $(FILE5).cc
#	$(CC) $(CCFLAGS) $(FILE5).cc

#$(FILE6).o: $(FILE6).cc
#	$(CC) $(CCFLAGS) $(FILE6).cc

#$(FILE7).o: $(FILE7).cc
#	$(CC) $(CCFLAGS) $(FILE7).cc

#$(FILE8).o: $(FILE8).cc
#	$(CC) $(CCFLAGS) $(FILE8).cc

$(FILE9).o: $(FILE9).cc
	$(CC) $(CCFLAGS) $(FILE9).cc $(LIBS)

#$(FILE10).o: $(FILE9).cc
#	$(CC) $(CCFLAGS) $(FILE9).cc

#$(FILE11).o: $(FILE9).cc
#	$(CC) $(CCFLAGS) $(FILE9).cc

#$(FILE12).o: $(FILE9).cc
#	$(CC) $(CCFLAGS) $(FILE9).cc

#$(FILE13).o: $(FILE9).cc
#	$(CC) $(CCFLAGS) $(FILE9).cc

$(FILE14).o: $(FILE14).cc
	$(CC) $(CCFLAGS) $(FILE14).cc $(LIBS)

clean:
	rm *.o a.out

