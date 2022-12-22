//Выполнили студенты группы 21ВВ3: Тюкалов В.Е. и Чинов Д.Д.
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>

typedef struct Node {
	int data = 0;
	Node* next = NULL;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int total = 0, v = 0, count = 1, countPerv = -1, countV = 1, clearV = 0;

	printf("Введите размер матрицы: ");
	scanf_s("%d", &total);
	int* numG = (int*)malloc(total * sizeof(int));
	int* vPerv = (int*)malloc(total * sizeof(int));
	for (int i = 0; i < total; i++) {
		vPerv[i] = NULL;
	}
	int** G = (int**)malloc(total * sizeof(int*));
	for (int i = 0; i < total; i++) {
		G[i] = (int*)malloc(total * sizeof(int));
		numG[i] = 1;
	}

	srand(time(NULL));
	for (int i = 0; i < total; i++) {
		for (int j = i; j < total; j++) {
			if (i == j) {
				G[i][j] = 0;
			}
			else {
				G[i][j] = rand() % 2;
				G[j][i] = G[i][j];
			}
		}
	}

	printf("\n Матрица смежности \n");
	printf("\n   ");
	for (int i = 0; i < total; i++) {
		printf("  %c", (i + 97));
	}
	printf("\n    ");
	for (int i = 0; i < total * 3; i++) {
		printf("_");
	}
	printf("\n");
	for (int i = 0; i < total; i++) {
		printf(" %c | ", (i + 97));
		for (int j = 0; j < total; j++) {
			printf("%d  ", G[i][j]);
		}
		printf("\n");
	}

	while (count == 1 && countV == 1) {
		for (int i = 0; i < total; i++) {
			if (G[v][i] == 1 && numG[i] == 1) {
				if(numG[v] == 1) printf("%d ", (v + 1));
				numG[v] = 0;
				countPerv++;
				vPerv[countPerv] = v;
				v = i;
				break;
			}
			if (i == total - 1) {
				if (numG[v] == 1 && countPerv != -1) {
					printf("%d ", (v + 1));
					numG[v] = 0;
				}
				if(countPerv == -1) v++;
				if (countPerv >= 0) {
					v = vPerv[countPerv];
					countPerv--;
					if (countPerv == -1) clearV = 1;
					break;
				}
				if (clearV == 1) countV = 0;
			}
		}
		count = 0;
		for (int i = 0; i < total; i++) {
			if (numG[i] == 1) count = 1;
		}
	}
}