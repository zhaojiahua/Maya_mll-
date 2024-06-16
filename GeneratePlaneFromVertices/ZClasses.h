#pragma once
#include <maya/MGlobal.h>

using namespace std;

class Z5Matrix;

class Z5Vector
{
	double mateData[5];
public:
	Z5Vector();
	Z5Vector(double* in5list);

	void SetElements(double* in5list);
	void SetElement(int index, double invalue);
	double GetElement(int index);
	double* GetMateData();

	Z5Vector operator+ (Z5Vector inVec);
	Z5Vector operator* (double inS);
	Z5Vector operator* (Z5Vector inVec);//非向量乘法
	Z5Vector operator* (Z5Matrix inMat);

	//打印函数(方便Debug)
	void Print();
};

class Z5Matrix
{
	double mateData[25];
public:
	Z5Matrix();
	Z5Matrix(double* in25list);
	Z5Matrix(Z5Vector* in5vects);

	void SetElementsAll(double* in25list);
	void SetElement(int index_r, int index_c, double value);
	void SetElementsByZ5Vector(int index, Z5Vector in5vec);
	Z5Vector GetElementsByZ5Vector(int index);
	double GetElement(int index_r, int index_c);
	//使该矩阵变成单位矩阵
	void MakeIdentity();
	//返回该矩阵的转置矩阵
	Z5Matrix Transpose();
	//返回指定元素坐标的子矩阵(返回的是mateData数组)
	static double* SubMatrix(double* indata, int index_r, int index_c);

	Z5Matrix operator*(Z5Matrix in5mat);
	Z5Vector operator*(Z5Vector in5vec);
	Z5Matrix operator*(double inval);

	//返回2X2矩阵的行列式的值
	static double M2X2_Det(double* invalues);
	//返回3X3矩阵的行列式的值
	static double M3X3_Det(double* invalues);
	//返回4X4矩阵的行列式的值
	static double M4X4_Det(double* invalues);
	//返回该矩阵的行列式的值
	double Determinant();
	//返回该矩阵的伴随矩阵
	Z5Matrix AdjointMatrix();
	//返回该矩阵的逆矩阵
	Z5Matrix InverseMatrix();
	
	//打印函数(方便Debug)
	void Print();
};