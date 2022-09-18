#ifndef __LIBRARY_H
#define __LIBRARY_H
#ifdef __DLL__
#define DLL_EI __declspec(dllexport)
#else
#define DLL_EI __declspec(dllimport)
#endif

//#include "id3/globals.h"
//#include "id3/tag.h"

//ID3_Tag* m_id3tag = new ID3_Tag;

TStringList* SongList = new TStringList;

struct TAG
{
unsigned char   tag     [ 03 ];
unsigned char   title   [ 30 ];
unsigned char   artist  [ 30 ];
unsigned char   album   [ 30 ];
unsigned char   year    [ 04 ];
unsigned char   comment [ 28 ];
unsigned char   sep     [ 01 ];
unsigned char   track   [ 01 ];
unsigned char   genre   [ 01 ];
};


//extern char* DLL_EI __fastcall translate(char* convert);
//extern int DLL_EI __fastcall binaryconvert(char bukva, int i);
//extern char DLL_EI __fastcall dectohex (int covnum);
//extern WideString DLL_EI __fastcall hexconvert(int gchar);
extern int DLL_EI __fastcall getlenght(char* database);
//extern void DLL_EI __fastcall dir_p(int argc, char* argv, char* filename);
extern char* DLL_EI __fastcall crofilename(WideString S);
extern char* DLL_EI __fastcall GetMp3Tag_DLL ( char fName[] , int callparam );
extern TStringList* DLL_EI __fastcall FindDir(char* path,char* mask);
// ID3v2 Block
extern char* DLL_EI __fastcall get_channel_mode(int channelmode);
extern char* DLL_EI __fastcall get_mpeg_version(int version);
extern char* DLL_EI __fastcall get_layer(int layer);
extern char* DLL_EI __fastcall get_bitrate(int nCbrBitRate,int nVbrBitRate);

#endif;
