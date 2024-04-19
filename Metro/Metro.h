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
public: void pausing() {
	speed = speed - ((speed / 100) * 93);
}
public: void SetHeadX_SetLengthOfTrain_SetPath(int setheadx,int setlengthoftrain,int setpath){
	head_x = setheadx;
	length_of_train = setlengthoftrain;
	path = setpath;
}
public: void starttrain() {
	speed = speed + (1 * 0.5);
}

public: void inorout() {
	int dewfj;
	dewfj = rand() % people;
	people = people - dewfj;
	people = people + rand();
}
};

