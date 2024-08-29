#include "menu.h"
#include <stdio.h>

void displayMenu() {
    printf("1. Add car\n");
    printf("2. Remove car\n");
    printf("3. Print list\n");
    printf("4. Sort list by price\n");
    printf("5. Search by brand\n");
    printf("6. Read from file\n");
    printf("7. Write to file\n");
    printf("8. Exit\n");
}

void handleUserInput(CarList *list) {
    int choice;
    char filename[100];
    Car car;
    size_t index;
    char brand[50];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter brand, model, year, and price: ");
                scanf("%49s %49s %d %lf", car.brand, car.model, &car.year, &car.price);
                addCar(list, car);
                break;
            case 2:
                printf("Enter index of car to remove: ");
                scanf("%zu", &index);
                removeCar(list, index);
                break;
            case 3:
                printList(list);
                break;
            case 4:
                sortListByPrice(list);
                break;
            case 5:
                printf("Enter brand to search: ");
                scanf("%49s", brand);
                searchByBrand(list, brand);
                break;
            case 6:
                printf("Enter filename to read from: ");
                scanf("%99s", filename);
                readFromFile(list, filename);
                break;
            case 7:
                printf("Enter filename to write to: ");
                scanf("%99s", filename);
                writeToFile(list, filename);
                break;
            case 8:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}
