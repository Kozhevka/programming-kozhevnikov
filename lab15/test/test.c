#include <stdio.h>
#include <string.h>
#include "../src/list.h"

void test() {
    CarList list;
    initList(&list);

    Car car1 = {"Toyota", "Camry", 2010, 15000.00};
    Car car2 = {"Ford", "Focus", 2012, 12000.00};
    Car car3 = {"Honda", "Civic", 2015, 18000.00};
    Car car4 = {"Toyota", "Corolla", 2011, 14000.00};
    Car car5 = {"Ford", "Mustang", 2018, 30000.00};

    addCar(&list, car1);
    addCar(&list, car2);
    addCar(&list, car3);
    addCar(&list, car4);
    addCar(&list, car5);

    printf("Test list:\n");
    printList(&list);

    printf("\nRemoving index 2 (Honda Civic):\n");
    removeCar(&list, 2);
    printList(&list);

    printf("\nSorting by price:\n");
    sortListByPrice(&list);
    printList(&list);

    printf("\nSearching for brand 'Ford':\n");
    searchByBrand(&list, "Ford");

    freeList(&list);
}

int main() {
    test();
    return 0;
}
