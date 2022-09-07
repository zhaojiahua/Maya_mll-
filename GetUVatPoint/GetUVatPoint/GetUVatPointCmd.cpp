#include <maya/MSimple.h>
#include <maya/MGlobal.h>
#include <maya/MFnTransform.h>
#include <maya/MFnMesh.h>
#include <maya/MPoint.h>
#include <maya/MSelectionList.h>
#include <maya/MDagPath.h>
#include <maya/MVector.h>
#include <maya/MStringArray.h>
#include <maya/MDoubleArray.h>

DeclareSimpleCommand( GetUVatPoint, "zhaoJiaHua", "2018");

//��ѡ��һ��transform�ڵ���ѡ��һ��mesh��,Ȼ���������᷵��mesh���������Transform�ڵ������UV��ֵ

MStatus GetUVatPoint::doIt( const MArgList& args )
{
	MStatus stat = MS::kSuccess;

	MSelectionList slections;
	MGlobal::getActiveSelectionList(slections, false);
	MDagPath path1, path2;
	slections.getDagPath(0, path1);
	slections.getDagPath(1, path2);
	MFnTransform transform1(path1);
	MVector translation1 = transform1.getTranslation(MSpace::kWorld);
	MPoint point1(translation1);
	MFnMesh fnMesh2(path2);
	MStringArray uvnames;
	fnMesh2.getUVSetNames(uvnames);
	float2 uvValue;
	int polygonID;
	fnMesh2.getUVAtPoint(point1, uvValue, MSpace::kObject, &uvnames[0], &polygonID);

	MDoubleArray returnData;
	returnData.append(uvValue[0]);
	returnData.append(uvValue[1]);
	returnData.append(polygonID);

	setResult(returnData);

	return stat;
}
