#pragma once

class Metro
{

public: int length_of_train;
public: int head_x;
public: int path;
public: double speed;
public: int people;
public: int station;
public: int* stations = new int[station];
public: int HyjHAIA_nEpEMEHHAIA = 1;
public: void move() {
	head_x = head_x + speed;
}

public: int is_it_train(int x, int y) {
	int dsa = head_x - length_of_train;
	int hgt;
	
	for (int iy = 0; iy <= station; iy++) {
		hgt = stations[iy] - length_of_train;
		if (x <= stations[iy] && x >= hgt) {
			if (y == (path - 1)) {
				return 2;
			}
		}
	}
	if (x < head_x && x>dsa) {
		if (y == path) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

public:int isStation() {
	int ix;
	int null;
	int gess;
	for (int u = 0; u <= station; u++) {
		ix = stations[u];
		gess = stations[u] - length_of_train;
		if (head_x >= gess && head_x <= ix) {
			return 1;
		}
		else {
			null = 0;
		}
	}
}



public: void inorout() {
	int dewfj;
	dewfj = rand() % people;
	people = people - dewfj;
	people = people + (rand()% 70);
}

};

