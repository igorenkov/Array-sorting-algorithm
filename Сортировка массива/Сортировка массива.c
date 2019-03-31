#include <stdio.h>
#include <string.h>

//Функция сравнения по возрастанию
int compareInc(int a, int b) {
	if (a > b) {
		return 1;
	}
	else {
		return 0;
	}
}
//Функция сравнения по убыванию
int compareDesc(int a, int b) {
	if (a > b) {
		return 0;
	}
	else {
		return 1;
	}
}
//Функция сравнения по абсолютному значению
int compareAbs(int a, int b) {
	if (a * a > b * b) {
		return 1;
	}
	else {
		return 0;
	}
}

//Функция перестановки двух элементов
void replace(int *a, int *b) {
	int c;

	c = *b;
	*b = *a;
	*a = c;
}

int main() {
	char ch;

	do {
		int len, check;
		int* parr;
		int(*compare) (int, int);
		char type;
		printf("Input length: ");
		scanf_s("%d", &len);

		//Выделение памяти
		parr = malloc((sizeof(int))*(len));
		if (parr == NULL) {
			printf("Can't allocate the memory. ");
			return 0;
		}

		//Инициализация массива
		printf("Input array: ");
		for (int i = 0; i < len; i++) {
			scanf_s("%d", &parr[i]);
		}

		//Выбор вида сортировки: вводится число - номер сортировки
		printf("Input sort type(Inc - I/Desc - D/Abs - A): ");
		getchar();
		scanf_s("%c", &type);
		if (type == 'I' || type == 'i') {
			compare = compareInc;
		}
		else if (type == 'D' || type == 'd') {
			compare = compareDesc;
		}
		else if (type == 'A' || type == 'a') {
			compare = compareAbs;
		}
		else {
			printf("You've made a mistake, sweetheart :)");
			return 0;
		}

		//Выполнение математической модели сортировки
		for (int i = 0; i < (len - 1); i++) {
			check = 1;
			for (int j = 0; j < (len - 1); j++) {
				if (compare(parr[j], parr[j + 1])) {
					replace(&parr[j], &parr[j + 1]);
					check = 0;
				}
			}
			//Проверка на отсортированность массива
			if (check) {
				break;
			}
		}

		//Вывод массива
		for (int i = 0; i < len; i++) {
			printf("%d ", parr[i]);
		}

		free(parr);

		//Повтор программы
		printf("\nDo you wish to restart program? (y/n)\n");
		getchar();
		scanf_s("%c", &ch);
	} while (ch == 'y' || ch == 'Y');

	return 0;
}