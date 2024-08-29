#include "../src/list.h"
#include <assert.h>
#include <string.h>

void testAddCar() {
    CarList list;
    initList(&list);

    Car car = {"Toyota", "Corolla", 2020, 20000.0, NULL};
    addCar(&list, car);

    assert(list.head != NULL);
    assert(strcmp(list.head->brand, "Toyota") == 0);

    freeList(&list);
}

void testRemoveCar() {
    CarList list;
    initList(&list);

    Car car1 = {"Toyota", "Corolla", 2020, 20000.0, NULL};
    Car car2 = {"Honda", "Civic", 2019, 18000.0, NULL};
    addCar(&list, car1);
    addCar(&list, car2);

    removeCar(&list, 0);

    assert(list.head != NULL);
    assert(strcmp(list.head->brand, "Honda") == 0);

    freeList(&list);
}

void testSortListByPrice() {
    CarList list;
    initList(&list);

    Car car1 = {"Toyota", "Corolla", 2020, 20000.0, NULL};
    Car car2 = {"Honda", "Civic", 2019, 18000.0, NULL};
    addCar(&list, car1);
    addCar(&list, car2);

    sortListByPrice(&list);

    assert(list.head != NULL);
    assert(strcmp(list.head->brand, "Honda") == 0);

    freeList(&list);
}

int main() {
    testAddCar();
    testRemoveCar();
    testSortListByPrice();
    printf("All tests passed!\n");
    return 0;
}

