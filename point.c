#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
	int x, y;
} Point;

void example1() {
	Point p1 = { 4, 5 };
	Point p2 = { 200, 900 };
	printf("p1: %d, %d\tp2: %d %d\n", p1.x, p1.y, p2.x, p2.y);

	Point p3 = p2;
	p3.x = 777;
	printf("p2: %d, %d\tp3: %d %d\n", p2.x, p2.y, p3.x, p3.y);
}


Point make_Point(int x, int y) {
	Point p = { x, y };
	return p;
}
void example2() {
	Point p1 = make_Point(4, 5);
	Point p2 = make_Point(200, 900);
	printf("p1: %d, %d\tp2: %d %d\n", p1.x, p1.y, p2.x, p2.y);
}


void update_X(Point p, int x) {
	p.x = x;
}
void example3() {
	Point p1 = { 4, 5 };
	update_X(p1, 333);
	printf("p1.x: %d\n", p1.x);
}














void update_X_ptr(Point* p, int x) {
	p->x = x;
}
void example4() {
	Point p1 = { 4, 5 };
	update_X_ptr(&p1, 444);
	printf("p1.x: %d\n", p1.x);
}
void example5() {
	printf("sizeof(Point): %ld\n", sizeof(Point));
	Point* p = malloc(sizeof(Point));
	*p = make_Point(4, 5);
	update_X_ptr(p, 555);
	printf("p->x: %d\n", p->x);

	Point* p2 = p;
	update_X_ptr(p2, 888);
	printf("p->x: %d, p2->x: %d\n", p->x, p2->x);
}





int main() {
//	example1();
//	example2();
//	example3();
//	example4();
	example5();
}
