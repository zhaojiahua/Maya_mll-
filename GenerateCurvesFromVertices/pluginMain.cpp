#include "YourselfCmd.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj, "Zjh", "2022", "Any");//ָ���ò�������� �汾 ��ʹ�õ�API
	status = plugin.registerCommand("GeneratePlaneFromVertices", YourselfCommand::creator);//������Mayaע������,�ṩ���ø�������ַ�������
	if (!status) {
		status.perror("registerCommand");
		return status;
	}

	return status;
}
MStatus uninitializePlugin(MObject obj)
{
	MStatus   status;
	MFnPlugin plugin(obj);

	status = plugin.deregisterCommand("GeneratePlaneFromVertices");
	if (!status) {
		status.perror("deregisterCommand");
		return status;
	}

	return status;
}