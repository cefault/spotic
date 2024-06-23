#include <iostream>
#include <Windows.h>
using namespace std;

int art_logo() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Console output color
	cout <<"    .dMMMb   dMMMMb   .aMMMb  dMMMMMMP  dMP  .aMMMb" << endl;
	cout <<"   dMP\" VP  dMP.dMP  dMP\"dMP    dMP    amr  dMP\"VMP" << endl;
	cout <<"   VMMMb   dMMMMP\"  dMP dMP    dMP    dMP  dMP" << endl;
	cout <<" dP .dMP  dMP      dMP.aMP    dMP    dMP  dMP.aMP" << endl;
	cout <<" VMMMP\"  dMP       VMMMP\"    dMP    dMP   VMMMP\"";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Console output color reset
	return 0;
}

int art_logo_arial() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "\n	 .d8888b.                    888    d8b				\n"
			"	d88P  Y88b                   888    Y8P				\n"
			"	Y88b.                        888						\n"
			"	 \"Y888b.   88888b.   .d88b.  888888 888  .d8888b			\n"
			"	    \"Y88b. 888 \"88b d88\"\"88b 888    888 d88P\" d8		\n"
			"	      \"888 888  888 888  888 888    888 888			\n"
			"	Y88b  d88P 888 d88P Y88..88P Y88b.  888 Y88b.			\n"
			"	 \"Y8888P\"  88888P\"   \"Y88P\"   \"Y888 888  \"Y8888P\n"
			"	           888											\n"
			"	           888											\n"
			"	           888											";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return 0;
}