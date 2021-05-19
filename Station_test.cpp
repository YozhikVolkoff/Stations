#include<cassert>
#include"System.h"

void test_Platforms() {

    System S;
    S.create_station("A");
    S.create_station("B");
    S.create_station("C");
    S.create_platform("D");
    S.create_platform("E");
    S.create_platform("F");

    S.create_railway("A", "C", 20, 40);
    S.create_railway("C", "D", 20, 40);
    S.create_railway("E", "D", 20, 40);
    S.create_railway("F", "D", 20, 40);
    S.create_railway("F", "E", 20, 40);
    S.create_railway("A", "B", 20, 40);

    S.create_train(true, 9, "A", "B");
    S.create_train(true, 10, "E", "A");
    S.create_train(true, 5, "A", "B");
    S.create_train(false, 39, "B", "C");
    S.create_train(false, 39, "B", "C");
    S.trains_go();
}

int main() {
  test_Platforms();
  return 0;
}
