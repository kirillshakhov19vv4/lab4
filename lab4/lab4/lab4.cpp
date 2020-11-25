﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int** a;
int* vis;
int ver;

void DFS(int s, int rows) {
    vis[s] = 1; printf(" %d", s);
    for (int i = 0; i < rows; i++) {
        if (a[s][i] == 1 && vis[i] == 0) {
            DFS(i, rows);
        }
    }

}

int main()
{
    int rows;
    int n = 0;
    int k = 0;
    system("cls");
    printf("rows:");
    scanf("%d", &rows);
    srand(time(NULL));
    a = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        a[i] = (int*)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            a[i][j] = rand() % 2;
            if (i == j) {
                a[i][j] = 0;
            }
            a[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    vis = (int*)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        vis[i] = 0;
    }
    printf("\n");
    printf("Vershina:");
    scanf("%d", &ver);
    printf("\n");
    DFS(ver, rows);
    for (int i = 0; i < rows; i++)
        free(a[i]);
    free(a);
    getchar();
    return 0;
}
