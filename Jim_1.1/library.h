#ifndef __LIBRARY_H
#define __LIBRARY_H
#ifdef __DLL__
#define DLL_EI __declspec(dllexport)
#else
#define DLL_EI __declspec(dllimport)
#endif

extern char* DLL_EI __fastcall translate(char* convert);
extern int DLL_EI __fastcall binaryconvert(char bukva, int i);
extern char DLL_EI __fastcall dectohex (int covnum);
extern WideString DLL_EI __fastcall hexconvert(int gchar);
extern int DLL_EI __fastcall getlenght(char* database);
extern void DLL_EI __fastcall dir_p(int argc, char* argv, char* filename);
extern char* DLL_EI __fastcall crofilename(WideString S);
#endif;
