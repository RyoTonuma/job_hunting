#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <fstream>
using namespace std;

inline void InitRand()
{
    srand((unsigned int)time(NULL));
}

inline int Dice()
{
    return rand() % 1000 + 1;
}

int main(){
    int i, label, num;
	double x, y, maxx, minx, maxy, miny;
	maxx = 750;
	minx = 100;
	maxy = 500;
	miny = 40;
	num = 2397;
	//10%:148
	//1%:2397

    InitRand();
	ofstream ofs;
	ofs.open( "test.txt" );
    for(i = 0; i < num; i++){
		x = Dice();
		y = Dice();
		if(x <= maxx && x >= minx && y <= maxy && y >= miny) label = 1;
		else label = 0;
		ofs << x << " " << y << " " << label << endl;
	}
	ofs << -1 << " " << -1 << " " << -1 << endl;
	ofs.close();
	getchar();
    return 0;
}