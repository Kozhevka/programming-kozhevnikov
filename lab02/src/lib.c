/**
 * @file lib.c
 * @brief Файл з реалізацією функцій оперування тваринами
 *
 * @author Davydov V.
 * @date 14-apr-2020
 * @version 1.3
 */

#include "lib.h"

const char *get_animal_type_name(enum animal_type type)
{
	const char *result;
	switch (type) {
	case CAT:
		result = "Cat";
		break;
	case DOG:
		result = "Dog";
		break;
	case COW:
		result = "Cow";
		break;
	case PIG:
		result = "Pig";
		break;
	case HUMAN:
		result = "Human";
		break;
	default:
		result = "N/A";
	}
	return result;
}

void generate_animal(struct animal *entity, unsigned int index_in_enum)
{
	entity->height = (unsigned int)random() % INT8_MAX;
	entity->weight = (unsigned int)random() % INT8_MAX;
	entity->type = (unsigned int)index_in_enum;
}

void show_animals(struct animal animals[], unsigned int count)
{
	for (unsigned int i = 0; i < count; i++) {
		printf("Information about animal №%02u: ", i + 1);
		printf("%s: height = %u cm, mass = %u g. \n", get_animal_type_name(animals[i].type), animals[i].height, animals[i].weight);
	}
}
