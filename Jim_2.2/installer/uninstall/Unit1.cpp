//---------------------------------------------------------------------------
#include <iostream.h>
#include <Sysutils.hpp>
#include <conio.h>
#include "Registry.hpp"

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
char answer;
for(;;)
{
cout << "\nDelete Jim 2.2? (y/n) ";
answer=getchar();
if (answer!='y' || answer!='Y' || answer!='n' || answer!='N') break;
}
if (answer=='n' || answer=='N') return 0;
else
{
DeleteFile("C:\\Program Files\\TDSV\\Jim\\Jim.exe");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\Джим.pdf");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\jim.ini");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\library.dll");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\Uninstall.exe");
AnsiString ENV;
char buf[512];
GetEnvironmentVariable(LPCSTR("HOMEDRIVE"),buf,512);
ENV=AnsiString(buf);
GetEnvironmentVariable(LPCSTR("HOMEPATH"),buf,512);
ENV=ENV+AnsiString(buf)+"\\Desktop\\";
DeleteFile(ENV+"Джим.lnk");
GetEnvironmentVariable(LPCSTR("HOMEDRIVE"),buf,512);
ENV=AnsiString(buf);
GetEnvironmentVariable(LPCSTR("HOMEPATH"),buf,512);
ENV=ENV+AnsiString(buf)+"\\Рабочий Стол\\";
DeleteFile(ENV+"Джим.lnk");
GetEnvironmentVariable(LPCSTR("HOMEDRIVE"),buf,512);
ENV=AnsiString(buf);
GetEnvironmentVariable(LPCSTR("HOMEPATH"),buf,512);
ENV=ENV+AnsiString(buf)+"\\Start Menu\\Programs\\";
DeleteFile(ENV+"Jim Player\\"+"Джим.lnk");
DeleteFile(ENV+"Jim Player\\"+"Manual.lnk");
DeleteFile(ENV+"Jim Player\\"+"Uninstall.lnk");
RmDir(ENV+"Jim Player");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\animation\\0.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\animation\\2.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\animation\\3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\animation\\4.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\animation\\5.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\animation\\split.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\animation\\wall.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\mus\\hello.mp3");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\0.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\1.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\2.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\3.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\4.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\5.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\6.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\7.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\8.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\9.jpl");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\mp3.db");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\mp3init.db");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\pic.db");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\statistic.db");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\db\\statistic.VAL");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\addmp3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\remmp3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\rewind.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\forward.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\play.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\pause.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\pausepic.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\savelist.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\pref.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\openpic.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\sort.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\jim.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\default\\default.jsf");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\addmp3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\remmp3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\rewind.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\forward.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\play.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\pause.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\pausepic.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\savelist.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\pref.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\openpic.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\sort.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\margo.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\margo\\margo.jsf");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\addmp3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\remmp3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\rewind.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\forward.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\play.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\pause.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\pausepic.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\savelist.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\pref.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\openpic.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\sort.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\jim.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\jim\\jim.jsf");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\addmp3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\remmp3.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\rewind.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\forward.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\play.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\pause.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\pausepic.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\savelist.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\pref.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\openpic.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\sort.jpg");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\darkeyes.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\darkeyes.jsf");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\addmp3.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\remmp3.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\rewind.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\forward.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\play.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\pause.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\pausepic.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\savelist.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\pref.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\openpic.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\sort.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\ro_angel.bmp");
DeleteFile("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\ro_angel.jsf");
RmDir("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes");
RmDir("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel");
RmDir("C:\\Program Files\\TDSV\\Jim\\skins\\margo");
RmDir("C:\\Program Files\\TDSV\\Jim\\skins\\jim");
RmDir("C:\\Program Files\\TDSV\\Jim\\skins\\default");
RmDir("C:\\Program Files\\TDSV\\Jim\\skins");
RmDir("C:\\Program Files\\TDSV\\Jim\\animation");
RmDir("C:\\Program Files\\TDSV\\Jim\\mus");
RmDir("C:\\Program Files\\TDSV\\Jim\\db");
RmDir("C:\\Program Files\\TDSV\\Jim");
RmDir("C:\\Program Files\\TDSV");
TRegistry *reg = new TRegistry();
reg->RootKey = HKEY_CLASSES_ROOT;
reg->DeleteKey(".jsf");
reg->DeleteKey(".jpl");
reg->Free();
cout << "Done! Jim has been deleted. Press any key to exit";
getch();
getch();
return 0;
}
}
//---------------------------------------------------------------------------
