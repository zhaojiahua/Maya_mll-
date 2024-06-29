#pragma once
#include <maya/MGlobal.h>
#include <maya/MDoubleArray.h>
#include <maya/MRandom.h>
#include <maya/MPointArray.h>
#include <maya/MPoint.h>
#include <maya/MIntArray.h>

using namespace std;

class Z5Matrix;

class Z5Vector
{
	MDoubleArray mateData;
public:
	Z5Vector();
	Z5Vector(double* in5list);
	Z5Vector(MDoubleArray inarry);

	void SetElements(double* in5list);
	void SetElements(MDoubleArray inarry);
	void SetElement(int index, double invalue);
	double GetElement(int index);
	MDoubleArray GetMateData();

	Z5Vector operator+ (Z5Vector inVec);
	Z5Vector operator* (double inS);
	Z5Vector operator* (Z5Vector inVec);//�������˷�
	Z5Vector operator* (Z5Matrix inMat);

	//��ӡ����(����Debug)
	void Print();
};

class Z5Matrix
{
	MDoubleArray mateData;
public:
	Z5Matrix();
	Z5Matrix(double* in25list);
	Z5Matrix(MDoubleArray in25array);
	Z5Matrix(Z5Vector* in5vects);

	~Z5Matrix();

	void SetElementsAll(double* in25list);
	void SetElementsAll(MDoubleArray in25array);
	void SetElement(int index_r, int index_c, double value);
	void SetElementsByZ5Vector(int index, Z5Vector in5vec);
	Z5Vector GetElementsByZ5Vector(int index);
	MDoubleArray GetMateData();
	double GetElement(int index_r, int index_c);
	//ʹ�þ����ɵ�λ����
	void MakeIdentity();
	//���ظþ����ת�þ���
	Z5Matrix Transpose();
	//����ָ��Ԫ��������Ӿ���(ȥ�����и��к�õ���matsize-1�׾���)(���ص���mateData����)(Ҫ����ԭʼ���ݺͷ���Ĵ�С)
	static MDoubleArray SubMatrix(MDoubleArray inmat, int index_r, int index_c);

	Z5Matrix operator*(Z5Matrix in5mat);
	Z5Vector operator*(Z5Vector in5vec);
	Z5Matrix operator*(double inval);

	//���ش˾��������ʽ��ֵ
	double Determinant();
	//���뷽�󷵻ظþ��������ʽ��ֵ
	static double Determinant(MDoubleArray inmate);
	//���ظþ���İ������
	Z5Matrix AdjointMatrix();
	//���ظþ���������
	Z5Matrix InverseMatrix();

	//��ӡ����(����Debug)
	void Print();
	//��ӡmatedata����(��Ҫָ������Ĵ�С)
	static void PrintMateDatas(MDoubleArray indatas);
	static void PrintMateDatas(double indata);
};

Z5Matrix operator*(double, Z5Matrix);

MDoubleArray operator+(MDoubleArray a1, MDoubleArray a2);

struct ZGenMeshParam
{
	int numVertices;
	int numPolygons;
	MPointArray vertexArray;
	MIntArray polygonCounts;
	MIntArray polygonConnects;
	MObject parentOrOwner;
	MStatus* ReturnStatus;

	ZGenMeshParam();
};