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

	//������ѡ���Mesh,���᷵�ظ�Mesh������������(0��x��,1��y��,2��z��),��ӳ�䵽��Ӧ������ƽ���϶�ά��,�Լ��ڸ������ϵĿ��(���ֵ����Сֵ֮��)
	MStatus Get2DPoints(const MDagPath& inobj, int&, MDoubleArray&, double&);

};