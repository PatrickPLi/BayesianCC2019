cc: cc.cpp
	g++ -std=c++11 cc.cpp -o cc

run:
	./cc < data2.txt

clean:
	rm -f cc
