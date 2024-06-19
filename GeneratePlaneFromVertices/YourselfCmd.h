#pragma once
#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MSelectionList.h>
#include <maya/MItSelectionList.h>
#include <maya/MStringArray.h>
#include <maya/MString.h>
#include <maya/MDagPath.h>
#include <maya/MArgList.h>
#include <maya/MObject.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnMesh.h>
#include <maya/MPoint.h>
#include <maya/MPointArray.h>
#include <maya/MSyntax.h>
#include <maya/MArgParser.h>
#include <maya/MFnNurbsCurve.h>
#include <maya/MFnTransform.h>

#include "ZClasses.h"

//Maya��������
class YourselfCommand :public MPxCommand
{
public:
	YourselfCommand();
	virtual		~YourselfCommand();

	MStatus		doIt(const MArgList&);
	MStatus		redoIt();
	MStatus		undoIt();
	bool		isUndoable() const;

	static		void* creator();

private:// Store the data you will need to undo the command here
	
	MSelectionList selections;
	unsigned int crvptnum = 10;
	double bextend = 0.05;

	//������ѡ���Mesh,���᷵�ظ�Mesh������������(0��x��,1��y��,2��z��),��ӳ�䵽��Ӧ������ƽ���϶�ά��,�Լ��ڸ������ϵĿ��(���ֵ����Сֵ֮��)
	MStatus Get2DPoints(const MDagPath& inobj, unsigned int&, MDoubleArray&, MDoubleArray&);
	//����һ��ֵ,�����ֵ���մ�С���������˳�򰲲嵽��Ӧ��λ��
	MStatus SortedAppend(double invalue, MDoubleArray& darray);
	//����һ�Ѷ�ά���ȡ���������
	MStatus GetAugmentedMatrix(MDoubleArray inpts, Z5Matrix& oMat, Z5Vector& oVec);
	//��һ��MDoubleArray�۰��ֳ�����MDoubleArray
	MStatus HalfSplit(MDoubleArray inpts12, MDoubleArray& inpts1, MDoubleArray& inpts2);
	//�������ʽϵ��(����ƽ��ռ�),��չ����,��չ����ȡֵ��Χ,�ͷֱ���,�������ߵ�EP������
	MStatus GenerateCrvEPs(Z5Vector inc1, Z5Vector inc2, unsigned int spreadAxies, const MDoubleArray& mmv, unsigned int epnum, MPointArray& oPoints);
};