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
		else {
			int dkhfs = 1;
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
	int null;
	for (int u = 0; u <= station; u++) {
		if (stations[u] == head_x) {
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

