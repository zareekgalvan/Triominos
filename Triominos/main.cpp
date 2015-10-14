//
//  main.cpp
//  Triominos
//
//  Created by Zareek Galvan on 9/4/15.
//  Copyright (c) 2015 Trisquel Labs. All rights reserved.
//
//  César Armando Galván Valles
//  A00814038


#include <iostream>
#include <cmath>

using namespace std;

//=======================================================================================================================

//Matriz hasta 2^6
const int intSizeN=64;
int matriz[intSizeN][intSizeN];
int intTriominosN = 1;

//=======================================================================================================================
//Encontrar cuadrante
int encuentraCuadrante(int intR, int intC, int intSize)
{
    int intCuadrante = 1;
    
    if (intC < intSize/2)
    {
        intCuadrante++;
    }
    if (intR < intSize/2)
    {
        if (intCuadrante == 1)
        {
            intCuadrante = 1;
        }
        else
        {
            intCuadrante = 2;
        }
    }
    else
    {
        if (intCuadrante == 1)
        {
            intCuadrante = 4;
        }
        else
        {
            intCuadrante = 3;
        }
    }
    return intCuadrante;
}

//=======================================================================================================================
//Poner triominos en matriz
void triominos(int intRI, int intCI, int intRF, int intCF, int intSize)
{
    if (intSize >= 2)
    {
        int intCuadrante = encuentraCuadrante(intRI-intRF, intCI-intCF, intSize);
        
        int intRengInf, intRengSup, intColDer, intColIzq;
        intRengSup = intColIzq = (intSize-1) / 2;
        intRengInf = intColDer = intRengSup + 1;
        intRengInf += intRF;
        intRengSup += intRF;
        intColDer += intCF;
        intColIzq += intCF;
        
        if (intCuadrante == 1)
        {
            matriz[intRengSup][intColIzq] = intTriominosN;
            matriz[intRengInf][intColIzq] = intTriominosN;
            matriz[intRengInf][intColDer] = intTriominosN;
            intTriominosN++;
            triominos(intRI, intCI, intRengSup - (intSize - 1)/2, intColDer, intSize/2);
            triominos(intRengSup, intColIzq, intRengSup - (intSize - 1)/2, intColIzq - (intSize - 1)/2, intSize/2);
            triominos(intRengInf, intColIzq, intRengInf, intColIzq - (intSize - 1)/2, intSize/2);
            triominos(intRengInf, intColDer, intRengInf, intColDer, intSize/2);
        }
        
        if (intCuadrante == 2)
        {
            matriz[intRengSup][intColDer] = intTriominosN;
            matriz[intRengInf][intColDer] = intTriominosN;
            matriz[intRengInf][intColIzq] = intTriominosN;
            intTriominosN++;
            triominos(intRI, intCI, intRengSup - (intSize - 1)/2, intColIzq - (intSize - 1)/2, intSize/2);
            triominos(intRengSup, intColDer, intRengSup - (intSize - 1)/2, intColDer, intSize/2);
            triominos(intRengInf, intColDer, intRengInf, intColDer, intSize/2);
            triominos(intRengInf, intColIzq, intRengInf, intColIzq - (intSize - 1)/2, intSize/2);
            
        }
        
        if (intCuadrante == 3)
        {
            matriz[intRengInf][intColDer] = intTriominosN;
            matriz[intRengSup][intColDer] = intTriominosN;
            matriz[intRengSup][intColIzq] = intTriominosN;
            intTriominosN++;
            triominos(intRI, intCI, intRengInf, intColIzq - (intSize - 1)/2, intSize/2);
            triominos(intRengInf, intColDer, intRengInf, intColDer, intSize/2);
            triominos(intRengSup, intColDer, intRengSup - (intSize - 1)/2, intColDer, intSize/2);
            triominos(intRengSup, intColIzq, intRengSup - (intSize - 1)/2, intColIzq - (intSize - 1)/2, intSize/2);
        }
        
        if (intCuadrante == 4)
        {
            matriz[intRengInf][intColIzq] = intTriominosN;
            matriz[intRengSup][intColIzq] = intTriominosN;
            matriz[intRengSup][intColDer] = intTriominosN;
            intTriominosN++;
            triominos(intRI, intCI, intRengInf, intColDer, intSize/2);
            triominos(intRengInf, intColIzq, intRengInf, intColIzq - (intSize - 1)/2, intSize/2);
            triominos(intRengSup, intColIzq, intRengSup - (intSize - 1)/2, intColIzq - (intSize - 1)/2, intSize/2);
            triominos(intRengSup, intColDer, intRengSup - (intSize - 1)/2, intColDer, intSize/2);
        }
    }
}

//=======================================================================================================================
//Imprimir matriz
void printMatriz(int intSize)
{
    for (int intI = 0; intI < intSize; intI++)
    {
        for (int intJ = 0; intJ < intSize; intJ++)
        {
            cout << matriz[intI][intJ] << "\t";
        }
        cout << endl;
    }
}

//=======================================================================================================================
int main()
{
    int potencia, intReng, intCol;
    cin >> potencia >> intReng >> intCol;
    potencia = pow(2, potencia);
    triominos(intReng, intCol, 0, 0, potencia);
    printMatriz(potencia);
}