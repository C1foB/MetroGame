#pragma once

class Metro
{
private: int length_of_train;
private: int head_x;
private: int path;
private: double speed;
public: void move() {
	head_x = head_x + speed;
}
public: int is_it_train(int x, int y) {
	for (int i = 0; i < length_of_train; i++) {
		int juice = head_x - i;
		if (x == juice && y == path) {
			return 1;
		}
		else {
			return 0;
		}
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
};

