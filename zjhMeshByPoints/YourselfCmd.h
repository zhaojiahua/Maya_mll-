#pragma once
#include <maya/MPxCommand.h>
#include <maya/MSelectionList.h>
#include <vector>
#include <maya/MDagPathArray.h>

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

private:
	//for debug
	MString tempStr;
	MSelectionList selectionList;
	//���ݸ����ĸ��ڵ�,������ȡ���µ������ӽڵ�(���ĳ�����ڵ����ж���ӽڵ�,��ôֻ�з��ڵ�һλ���ӽڵ����Ч)
	MStatus GetAllChildrenPosition(const MDagPath& rootPath, MVectorArray& outArray);
	std::vector<MVectorArray> rootPoss;
	MDagPathArray jntsPaths;
	MObject outMesh;
};