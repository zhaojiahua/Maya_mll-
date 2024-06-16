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
	Z5Vector operator* (Z5Vector inVec);//�������˷�
	Z5Vector operator* (Z5Matrix inMat);

	//��ӡ����(����Debug)
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
	//ʹ�þ����ɵ�λ����
	void MakeIdentity();
	//���ظþ����ת�þ���
	Z5Matrix Transpose();
	//����ָ��Ԫ��������Ӿ���(���ص���mateData����)
	static double* SubMatrix(double* indata, int index_r, int index_c);

	Z5Matrix operator*(Z5Matrix in5mat);
	Z5Vector operator*(Z5Vector in5vec);
	Z5Matrix operator*(double inval);

	//����2X2���������ʽ��ֵ
	static double M2X2_Det(double* invalues);
	//����3X3���������ʽ��ֵ
	static double M3X3_Det(double* invalues);
	//����4X4���������ʽ��ֵ
	static double M4X4_Det(double* invalues);
	//���ظþ��������ʽ��ֵ
	double Determinant();
	//���ظþ���İ������
	Z5Matrix AdjointMatrix();
	//���ظþ���������
	Z5Matrix InverseMatrix();
	
	//��ӡ����(����Debug)
	void Print();
};