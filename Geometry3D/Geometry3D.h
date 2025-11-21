
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GEOMETRY3D_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GEOMETRY3D_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GEOMETRY3D_EXPORTS
#define GEOMETRY3D_API __declspec(dllexport)
#else
#define GEOMETRY3D_API __declspec(dllimport)
#endif
// This class is exported from the dll
class GEOMETRY3D_API CGeometry3D {
public:
	CGeometry3D(void);
	// TODO: add your methods here.
};

extern GEOMETRY3D_API int nGeometry3D;

GEOMETRY3D_API int fnGeometry3D(void);
