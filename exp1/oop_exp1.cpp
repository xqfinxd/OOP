#include <iostream>
#include <cstdint>
#include <cstdio>

unsigned int MaxNum(unsigned int i, unsigned int j, unsigned int x = 0) {
	unsigned int c = 0;
	if(i > j) {
		c = i;
	} else {
		c = j;
	}
	if(c > x) {
		return c;
	} else {
		return x;
	}
}

void SortRef(int& a, int& b, int& c) {
	int tmp;
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if(b > c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
}

void Sort(int& a, int& b, int& c) {
	int tmp;
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if(b > c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
}

void Sort(float& a, float& b, float& c) {
	float tmp;
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if(b > c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
}

template<typename T>
void SortT(T& a, T& b, T& c) {
	T tmp;
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if(b > c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
}

class Date {
public:
	int year, month, day;
	void getDate() {
		printf("The Date is ???:\n");
		scanf("%d %d %d",&(this->year), &(this->month), &(this->day)); 
	}
	void showDate();
};
void Date::showDate() {
	printf("Date is: %d-%d-%d\n",this->year, this->month, this->day);
}

class Circle {
public:
	const float pi;
	float radius;
	Circle(float r) : pi(3.1415926f) {
		radius = r;
	}
	float getArea() {
		return (pi*radius*radius);
	}
};

class ThreeCube {
public:
	int length[3], width[3], height[3];
	int result[3];
	void getParament() {
		printf("First Cube(l, w, h):\n");
		scanf("%d %d %d",&(this->length[0]), &(this->width[0]), &(this->height[0]));
		printf("Second Cube(l, w, h):\n");
		scanf("%d %d %d",&(this->length[1]), &(this->width[1]), &(this->height[1]));
		printf("Third Cube(l, w, h):\n");
		scanf("%d %d %d",&(this->length[2]), &(this->width[2]), &(this->height[2]));
	}
	void Compute() {
		result[0] = length[0]*width[0]*height[0];
		result[1] = length[1]*width[1]*height[1];
		result[2] = length[2]*width[2]*height[2];
	}
	void showCubes() {
		printf("First cube: %d\n",result[0]);
		printf("Second cube: %d\n",result[1]);
		printf("Third cube: %d\n",result[2]);
	}
};

int main() {
	//1st
	printf(">>1st\n");
	printf("Max in 12, 22 and 21 is: %d\n", MaxNum(12, 22, 21));
	printf("Max in 12 and 92 is: %d\n", MaxNum(12, 92));
	//2nd
	printf(">>2nd\n");
	int a = 10, b = 20, c = 15;
	SortRef(a, b, c);
	printf("Sort 10, 20 and 15 will get: %d, %d, %d\n", a, b, c);
	//3rd
	printf(">>3rd\n");
	a = 7, b = 20, c = 15;
	Sort(a, b, c);
	printf("Sort 7, 20 and 15 will get: %d, %d, %d\n", a, b, c);
	float af = 10.6f, bf = 10.3f, cf = 15.9f;
	Sort(af, bf, cf);
	printf("Sort 10.6, 10.3 and 15.9 will get: %f, %f, %f\n", af, bf, cf);
	//4th
	printf(">>4th\n");
	a = 10, b = 20, c = 15;
	SortT(a, b, c);
	printf("Sort 10, 20 and 15 will get: %d, %d, %d\n", a, b, c);
	af = 10.6f, bf = 10.3f, cf = 15.9f;
	SortT(af, bf, cf);
	printf("Sort 10.6, 10.3 and 15.9 will get: %f, %f, %f\n", af, bf, cf);
	//5th
	printf(">>5th\n");
	Date date;
	date.getDate();
	date.showDate();
	//6th
	printf(">>6th\n");
	Circle circle(2.0f);
	printf("The area of circle( radius is 2.0 ) is: %f\n", circle.getArea());
	//7th
	printf(">>7th\n");
	ThreeCube cubes;
	cubes.getParament();
	cubes.Compute();
	cubes.showCubes();
    return 0;
}
