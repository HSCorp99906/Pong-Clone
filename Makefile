default:
	g++ -o ../bin/main *.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network && clear

run:
	clear && ../bin/main
