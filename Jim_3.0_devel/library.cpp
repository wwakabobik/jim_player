//---------------------------------------------------------------------------

#include <vcl.h>
#include <errno.h>
#include <windows.h>
#include "library.h"
#include <SysUtils.hpp>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <dir.h>
//#include <assert.h>
//#include "id3/tag.h"
//#include "id3/globals.h"
//#pragma comment(lib, "id3lib.lib")
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
        return 1;
}

//---------------------------------------------------------------------------

int __fastcall getlenght(char* database)
{
int param=0;
char temp[1024];
fstream e;
e.open(database);
if (e)
{
//ShowMessage("Unable to open temp file "+AnsiString(database));
while (!e.eof())
{
e.getline(temp,1024);
param++;
}
e.close();
return(param-1);
}
else
return 0;
}

/*char* __fastcall translate(char* convert)
{
try
{
AnsiString input = AnsiString(convert);
if (input=="Afrikaans") return("Ek het jou liefe");
if (input=="Albanian") return("Te dua");
if (input=="Portugal") return("Gosto De Ti, Porra!");
if (input=="Alsacien") return("Ich hoan dich gear");
if (input=="Amharic") return("Afekrishalehou");
if (input=="Arabic") return("Ana Behibek");
if (input=="Assamese") return("Moi tomak bhal pau");
if (input=="Basc") return("Nere Maitea");
if (input=="Batak") return("Holong rohangku di ho");
if (input=="Bavarian") return("I mog di narrisch gern");
if (input=="Bengali") return("Ami tomAy bhAlobAshi");
if (input=="Berber") return("Lakh tirikh");
if (input=="Bicol") return("Namumutan ta ka");
if (input=="Bolivian") return("Quechua qanta munani");
if (input=="Bulgarian") return("Obicham te");
if (input=="Burmese") return("Chit pa de");
if (input=="Cambodian") return("Bon sro lanh oon");
if (input=="Cantonese") return("Moi oiy neya");
if (input=="Catalan") return("T'estim");
if (input=="Cebuano") return("Gihigugma ko ikaw");
if (input=="Chickasaw") return("Chiholloli");
if (input=="Corsican") return("Ti tengu cara");
if (input=="Croatian") return("LJUBim te");
if (input=="Czech") return("Miluji te");
if (input=="Danish") return("Jeg elsker dig");
if (input=="Dutch") return("Ik hou van jou");
if (input=="Ecuador") return("Quechua canda munani");
if (input=="English") return("I love you");
if (input=="Esperanto") return("Mi amas vin");
if (input=="Estonian") return("Mina armastan sind");
if (input=="Farsi") return("Tora dust midaram");
if (input=="Filipino") return("Mahal kita");
if (input=="Finnish") return("Mina rakastan sinua");
if (input=="Flemish") return("Ik zie oe geerne");
if (input=="French") return("Je t'aime");
if (input=="Friesian") return("Ik hald fan dei");
if (input=="Gaelic") return("Ta gra agam ort");
if (input=="German") return("Ich liebe Dich");
if (input=="Georgian") return("Mikvarkhar");
if (input=="Greek") return("s'ayapo");
if (input=="Greek (old)") return("(Ego) philo su");
if (input=="Greenlandic") return("Asavakit");
if (input=="Gujrati") return("Hoon tane pyar karoochhoon");
if (input=="Hausa") return("Ina sonki");
if (input=="Hawaiian") return("Aloha I'a Au Oe");
if (input=="Hebrew") return("Ani ohev otach");
if (input=="Hindi") return("Mai tumase pyar karata hun");
if (input=="Hokkien") return("Wa ai lu");
if (input=="Hopi") return("Nu' umi unangwa'ta");
if (input=="Hungarian") return("Szeretlek");
if (input=="Icelandic") return("Eg elska thig");
if (input=="Indi") return("Mai Tujhe Pyaar Kartha Ho");
if (input=="Indonesian") return("Saya cinta padamu");
if (input=="Iranian") return("Mahn doostaht doh-rahm");
if (input=="Irish") return("Taim i' ngra leat");
if (input=="Italian") return("Ti amo");
if (input=="Japanese") return("Kimi o ai shiteru");
if (input=="Javanese") return("Kulo tresno");
if (input=="Kabardinian") return("Sa wa fuwa uzohyau");
if (input=="Kanada") return("Naanu Ninnanu Preethisuthene");
if (input=="Kiswahili") return("Nakupenda");
if (input=="Klingon") return("Qabang");
if (input=="Korean") return("No-rul sarang hae");
if (input=="Lao") return("Koi muk jao");
if (input=="Latin") return("Te amo");
if (input=="Latin (old)") return("(Ego) amo te");
if (input=="Latvian") return("Es milu tevi");
if (input=="Lebanese") return("Bahibak");
if (input=="Lingala") return("Nalingi yo");
if (input=="Lisbon") return("Lingo gramo-te bue, chavalinha");
if (input=="Lithuanian") return("Ta-ve mee-lyu");
if (input=="Lojban") return("Mi do prami");
if (input=="Luo") return("Aheri");
if (input=="Macedonian") return("SAKAM TE!");
if (input=="Madrid lingo") return("Me molas, tronca");
if (input=="Malay") return("Saya cintakan mu");
if (input=="Malayalam") return("Njyaan Ninne' Preetikyunnu");
if (input=="Malaysian") return("Saya Cintamu");
if (input=="Mandarin") return("Wo ai ni");
if (input=="Marathi") return("Me tujhashi prem karto");
if (input=="Mohawk") return("Konoronhkwa");
if (input=="Navaho") return("Ayor anosh'ni");
if (input=="Ndebele") return("Niyakutanda");
if (input=="Norwegian") return("Eg elskar deg");
if (input=="Op Op") return("Lopveop Yopuop");
if (input=="Osetian") return("Aez dae warzyn");
if (input=="Pakistani") return("Mujhe Tumse Muhabbat Hai");
if (input=="Persian") return("Tora dost daram");
if (input=="Pig Latin") return("Ie Ovele Ouye");
if (input=="Polish") return("Kocham Cie");
if (input=="Portuguese") return("Amo-te");
if (input=="Portuguese (Brazilian)") return("Eu te amo");
if (input=="Punjabi") return("Mai taunu pyar karda");
if (input=="Quenya") return("Tye-mela'ne");
if (input=="Romanian") return("Te Ador");
if (input=="Russian") return("Я тебя люблю");
if (input=="Scot Gaelic") return("Tha gradh agam ort");
if (input=="Serbian") return("ljubim te");
if (input=="Spanish") return("ly'ish (Te amo)");
if (input=="Serbocroatian") return("Volim te");
if (input=="Shona") return("Ndinokuda");
if (input=="Sinhalese") return("Mama oyata adarei");
if (input=="Sioux") return("Techihhila");
if (input=="Slovak") return("Lubim ta");
if (input=="Slovene") return("Ljubim te");
if (input=="Srilankan") return("Mama Oyata Arderyi");
if (input=="Swahili") return("Naku penda");
if (input=="Swedish") return("Jag a'lskar dig");
if (input=="Swiss-German") return("Ch'ha di ga'rn");
if (input=="Syrian/Lebanese") return("BHEBBEK");
if (input=="Tagalog") return("Mahal kita");
if (input=="Tahitian") return("Ua Here Vau Ia Oe");
if (input=="Tamil") return("n'An unnaik kAthalikkinREn");
if (input=="Tatar") return("Min sine jaratam");
if (input=="Tcheque") return("MILUJI TE");
if (input=="Telugu") return("Neenu ninnu pra'mistu'nnanu");
if (input=="Thai") return("Khao Raak Thoe");
if (input=="Tunisian") return("Ha eh bak");
if (input=="Turkish") return("Seni seviyorum");
if (input=="Ukrainian") return("Я тебе кохаю");
if (input=="Urdu") return("Mujhe tumse mohabbat hai");
if (input=="Uzbekski") return("Men senga sevaman");
if (input=="Vietnamese") return("Anh ye'u em");
if (input=="Vlaams") return("Ik hue van ye");
if (input=="Vulcan") return("Wani ra yana ro aisha");
if (input=="Welsh") return("'Rwy'n dy garu di");
if (input=="Yiddish") return("Ich libe dich");
if (input=="Yugoslavian") return("Ya te volim");
if (input=="Zazi") return("Ezhele hezdege");
if (input=="Zulu") return("Mena Tanda Wena");
if (input=="Zuni") return("Tom ho' ichema");
}
catch ( EInvalidPointer& ) {}
}

int __fastcall binaryconvert(char bukva, int i)
{
int x=bukva, z;
z = (x>>i&1);
return z;
}

char __fastcall dectohex (int covnum)
{
if (covnum ==0) return '0';
else if (covnum ==1) return '1';
else if (covnum == 2) return '2';
else if (covnum == 3) return '3';
else if (covnum == 4) return '4';
else if (covnum == 5) return '5';
else if (covnum == 6) return '6';
else if (covnum == 7) return '7';
else if (covnum == 8) return '8';
else if (covnum == 9) return '9';
else if (covnum == 10) return 'A';
else if (covnum == 11) return 'B';
else if (covnum == 12) return 'C';
else if (covnum == 13) return 'D';
else if (covnum == 14) return 'E';
else if (covnum == 15) return 'F';
}

WideString __fastcall hexconvert(int gchar)
{
WideString returnme="000";
int i=3,tempnum;
while (i!=0)
{
tempnum=gchar%16;
gchar/=16;
returnme[i]=dectohex(tempnum);
i--;
}
return returnme;
}

void __fastcall dir_p(int argc, char* argv, char* filename)
{
        struct ffblk fb;
        unsigned char wildCard[1024] = "*.*";
        int done;
        if (argc > 1)
        strncpy(wildCard,argv,12);
        done = findfirst(wildCard, &fb, FA_DIREC);
        ofstream f;
        f.open(filename);
        while (!done)
        {
        //puts(fb.ff_name);
        if (fb.ff_name[0]!='.')
        f << fb.ff_name << endl;
        done = findnext(&fb);
        }
        f.close();
} */

char* __fastcall crofilename(WideString S)
{
int i=0;
char tempword[1024];
while (S[i]!='.')
i++;
while (S[i]!='\\')
i--;
i++;
int j=0;
for (;;)
{
tempword[j]=S[i];
j++; i++;
if ((S[i]=='.' && S[i+1]=='m' && S[i+2]=='p' && S[i+3]=='3'))
break;
}
tempword[j]='\0';
return tempword;
}


char* __fastcall GetMp3Tag_DLL ( char fName[] , int callparam )
{
	HANDLE          hFile;
	DWORD           dwFileSize;
	DWORD           dwBytesRead;
	DWORD           dwTagSize;
	DWORD           dwStartPos;
	TAG             tMp3;
    char			c[31];

	hFile = CreateFile ( fName, GENERIC_READ, 0, NULL, OPEN_EXISTING,
    	FILE_ATTRIBUTE_NORMAL, NULL );
	if ( hFile != INVALID_HANDLE_VALUE )
    {
    	dwFileSize = GetFileSize ( hFile, NULL );
        dwTagSize = sizeof ( TAG );
        dwStartPos = dwFileSize - dwTagSize;
    	SetFilePointer ( hFile, dwStartPos, NULL, FILE_BEGIN );
        ReadFile ( hFile, &tMp3, dwTagSize, &dwBytesRead, NULL );
    }
	CloseHandle ( hFile );
    memmove( c, tMp3.tag, 30 ); c[30] = 0;
    if (callparam==0)
    return c;
    memmove( c, tMp3.title, 30 ); c[30] = 0;
    if (callparam==1)
    return c;
    memmove( c, tMp3.artist, 30 ); c[30] = 0;
    if (callparam==2)
    return c;
    memmove( c, tMp3.album, 30 ); c[30] = 0;
    if (callparam==3)
    return c;
    memmove( c, tMp3.year, 4 ); c[4] = 0;
    if (callparam==4)
    return c;
    memmove( c, tMp3.comment, 28 ); c[28] = 0;
    if (callparam==5)
    return c;
}



TStringList* __fastcall FindDir(char* path,char* mask)
{
//    const int MAX_PATH_TO_FILE = 16384; //260
    WIN32_FIND_DATA wfd;
    HANDLE hfound;
    /*char newpath[MAX_PATH_TO_FILE];
    char fpath[MAX_PATH_TO_FILE];
    char pathifile[MAX_PATH_TO_FILE]; //полный путь до файла
    char delpath[MAX_PATH_TO_FILE]; */
    AnsiString pathifile;
    AnsiString delpath;
    AnsiString newpath;
    AnsiString fpath;
    //char myTMP[MAX_PATH];
    /*
    strcpy(fpath,path);
    strcat(fpath,"\\");
    strcpy(delpath,fpath);
    strcat(fpath,mask);
    */
    fpath=AnsiString(path)+"\\";
    delpath=fpath;
    fpath=fpath+AnsiString(mask);


    if((hfound=FindFirstFile(fpath.c_str(),&wfd))!=INVALID_HANDLE_VALUE)
        {
        if(!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&strcmp(wfd.cFileName,"..")&&strcmp(wfd.cFileName,"."))
            {
            //нашли первый файл в папке path
                                  SongList->Add(AnsiString(path)+"\\"+AnsiString(wfd.cFileName));
            }
        while(FindNextFile(hfound,&wfd))
            {
            if(!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&strcmp(wfd.cFileName,"..")&&strcmp(wfd.cFileName,"."))
                {
                // файл в папке path
                // delpath - папка, с которой начинается реккурсия
                // wfd.cFileName - имя найденного файла

                // копируем строку delpath в pathifile
                //strcpy(pathifile, delpath);
                pathifile=delpath;
                // прибавляем к строке pathifile значение
                // переменной wfd.cFileName - имя файла
                //strcat(pathifile, wfd.cFileName);
                pathifile=pathifile+AnsiString(wfd.cFileName);
                // делаем что-либо с найденным файлом
                            SongList->Add(pathifile);
                }
            }
        }

    FindClose(hfound);
    //поиск файлов закончили, теперь ищем подпапки
    //strcpy(fpath,path);
    //strcat(fpath,"\\*.*");
    fpath=AnsiString(path)+"\\*.*";

    if((hfound=FindFirstFile(fpath.c_str(),&wfd))!=INVALID_HANDLE_VALUE)
        {
        if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&strcmp(wfd.cFileName,"..")&&strcmp(wfd.cFileName,"."))
            {
            //strcpy(newpath,path);
            //strcat(newpath,"\\");
            //strcat(newpath,wfd.cFileName);
            newpath=AnsiString(path)+"\\"+AnsiString(wfd.cFileName);
            FindDir(newpath.c_str(),mask); //Рекурсивный вызов
            }

        while(FindNextFile(hfound,&wfd))
            {
            if((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)&&strcmp(wfd.cFileName,"..")&&strcmp(wfd.cFileName,"."))
                {
                //strcpy(newpath,path);
                //strcat(newpath,"\\");
                //strcat(newpath,wfd.cFileName);
                newpath=AnsiString(path)+"\\"+AnsiString(wfd.cFileName);
                FindDir(newpath.c_str(),mask); //Рекурсивный вызов
                }
            }
        }
        return SongList;
    }

// --- ID3v2 Block

char* __fastcall get_bitrate(int nCbrBitRate,int nVbrBitRate)
{
    if(nVbrBitRate>0)
      return (AnsiString((int)nVbrBitRate/1024)+"kbit/s (VBR)").c_str();
    else
      return (AnsiString((int)nCbrBitRate/1024)+"kbit/s ").c_str();
}

char* __fastcall get_layer(int layer)
{
    switch((int)layer)
     {
      case 0:            return "UNDEFINED";
      case 1:            return "Layer III";
      case 2:            return "Layer II";
      case 3:            return "Layer I";
      default:           return "0";
     }
}

char* __fastcall get_mpeg_version(int version)
{
    switch((int)version)
     {
      case 3:   return "MPEG 2.5";
      case 2:   return "MPEG 2";
      case 0:   return "MPEG 1";
      default:  return "0";
     }
}

char* __fastcall get_channel_mode(int channelmode)
{
    switch((int)channelmode)
     {
      case 1:   return "Stereo";
      case 2:   return "Joint Stereo";
      case 3:   return "Dual Channel";
      case 4:   return "Mono";
      default:  return "0";
     }
}

