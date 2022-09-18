//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Registry.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (CheckBox1->Checked)
{
MkDir("C:\\Program Files\\TDSV");
MkDir("C:\\Program Files\\TDSV\\Jim");
RenameFile("res\\Jim.ex~","C:\\Program Files\\TDSV\\Jim\\Jim.exe");
RenameFile("res\\Джим.pd~","C:\\Program Files\\TDSV\\Jim\\Джим.pdf");
RenameFile("res\\jim.in~","C:\\Program Files\\TDSV\\Jim\\jim.ini");
RenameFile("res\\library.dl~","C:\\Program Files\\TDSV\\Jim\\library.dll");
RenameFile("res\\Uninstall.ex~","C:\\Program Files\\TDSV\\Jim\\Uninstall.exe");
AnsiString ENV;
char buf[512];
GetEnvironmentVariable(LPCSTR("HOMEDRIVE"),buf,512);
ENV=AnsiString(buf);
GetEnvironmentVariable(LPCSTR("HOMEPATH"),buf,512);
ENV=ENV+AnsiString(buf)+"\\Desktop\\";
RenameFile("res\\Джим.ln~",ENV+"Джим.lnk");
GetEnvironmentVariable(LPCSTR("HOMEDRIVE"),buf,512);
ENV=AnsiString(buf);
GetEnvironmentVariable(LPCSTR("HOMEPATH"),buf,512);
ENV=ENV+AnsiString(buf)+"\\Рабочий Стол\\";
RenameFile("res\\Джим.ln~",ENV+"Джим.lnk");
GetEnvironmentVariable(LPCSTR("HOMEDRIVE"),buf,512);
ENV=AnsiString(buf);
GetEnvironmentVariable(LPCSTR("HOMEPATH"),buf,512);
ENV=ENV+AnsiString(buf)+"\\Start Menu\\Programs\\";
MkDir(ENV+"Jim Player");
ENV=ENV+"Jim Player\\";
RenameFile("res\\Джим.l~~",ENV+"Джим.lnk");
RenameFile("res\\Manual.ln~",ENV+"Manual.lnk");
RenameFile("res\\Uninstall.ln~",ENV+"Uninstall.lnk");
MkDir("C:\\Program Files\\TDSV\\Jim\\animation");
RenameFile("res\\0.jp~","C:\\Program Files\\TDSV\\Jim\\animation\\0.jpg");
RenameFile("res\\2.jp~","C:\\Program Files\\TDSV\\Jim\\animation\\2.jpg");
RenameFile("res\\3.jp~","C:\\Program Files\\TDSV\\Jim\\animation\\3.jpg");
RenameFile("res\\4.jp~","C:\\Program Files\\TDSV\\Jim\\animation\\4.jpg");
RenameFile("res\\5.jp~","C:\\Program Files\\TDSV\\Jim\\animation\\5.jpg");
RenameFile("res\\split.bm~","C:\\Program Files\\TDSV\\Jim\\animation\\split.bmp");
MkDir("C:\\Program Files\\TDSV\\Jim\\mus");
RenameFile("res\\hello.mp~","C:\\Program Files\\TDSV\\Jim\\mus\\hello.mp3");
MkDir("C:\\Program Files\\TDSV\\Jim\\db");
RenameFile("res\\0.~pl","C:\\Program Files\\TDSV\\Jim\\db\\0.jpl");
RenameFile("res\\1.~pl","C:\\Program Files\\TDSV\\Jim\\db\\1.jpl");
RenameFile("res\\2.~pl","C:\\Program Files\\TDSV\\Jim\\db\\2.jpl");
RenameFile("res\\3.~pl","C:\\Program Files\\TDSV\\Jim\\db\\3.jpl");
RenameFile("res\\4.~pl","C:\\Program Files\\TDSV\\Jim\\db\\4.jpl");
RenameFile("res\\5.~pl","C:\\Program Files\\TDSV\\Jim\\db\\5.jpl");
RenameFile("res\\6.~pl","C:\\Program Files\\TDSV\\Jim\\db\\6.jpl");
RenameFile("res\\7.~pl","C:\\Program Files\\TDSV\\Jim\\db\\7.jpl");
RenameFile("res\\8.~pl","C:\\Program Files\\TDSV\\Jim\\db\\8.jpl");
RenameFile("res\\9.~pl","C:\\Program Files\\TDSV\\Jim\\db\\9.jpl");
RenameFile("res\\mp3.db~","C:\\Program Files\\TDSV\\Jim\\db\\mp3.db");
RenameFile("res\\mp3init.db~","C:\\Program Files\\TDSV\\Jim\\db\\mp3init.db");
RenameFile("res\\pic.db~","C:\\Program Files\\TDSV\\Jim\\db\\pic.db");
RenameFile("res\\statistic.db~","C:\\Program Files\\TDSV\\Jim\\db\\statistic.db");
RenameFile("res\\statistic.VA~","C:\\Program Files\\TDSV\\Jim\\db\\statistic.VAL");
//скины
MkDir("C:\\Program Files\\TDSV\\Jim\\skins");
MkDir("C:\\Program Files\\TDSV\\Jim\\skins\\default");
RenameFile("res\\skins\\default\\addmp3.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\addmp3.jpg");
RenameFile("res\\skins\\default\\remmp3.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\remmp3.jpg");
RenameFile("res\\skins\\default\\rewind.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\rewind.jpg");
RenameFile("res\\skins\\default\\forward.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\forward.jpg");
RenameFile("res\\skins\\default\\play.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\play.jpg");
RenameFile("res\\skins\\default\\pause.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\pause.jpg");
RenameFile("res\\skins\\default\\pausepic.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\pausepic.jpg");
RenameFile("res\\skins\\default\\savelist.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\savelist.jpg");
RenameFile("res\\skins\\default\\pref.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\pref.jpg");
RenameFile("res\\skins\\default\\openpic.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\openpic.jpg");
RenameFile("res\\skins\\default\\sort.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\default\\sort.jpg");
RenameFile("res\\skins\\default\\jim.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\default\\jim.bmp");
RenameFile("res\\skins\\default\\default.jsf","C:\\Program Files\\TDSV\\Jim\\skins\\default\\default.jsf");

MkDir("C:\\Program Files\\TDSV\\Jim\\skins\\margo");
RenameFile("res\\skins\\margo\\addmp3.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\addmp3.jpg");
RenameFile("res\\skins\\margo\\remmp3.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\remmp3.jpg");
RenameFile("res\\skins\\margo\\rewind.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\rewind.jpg");
RenameFile("res\\skins\\margo\\forward.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\forward.jpg");
RenameFile("res\\skins\\margo\\play.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\play.jpg");
RenameFile("res\\skins\\margo\\pause.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\pause.jpg");
RenameFile("res\\skins\\margo\\pausepic.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\pausepic.jpg");
RenameFile("res\\skins\\margo\\savelist.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\savelist.jpg");
RenameFile("res\\skins\\margo\\pref.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\pref.jpg");
RenameFile("res\\skins\\margo\\openpic.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\openpic.jpg");
RenameFile("res\\skins\\margo\\sort.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\sort.jpg");
RenameFile("res\\skins\\margo\\margo.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\margo.bmp");
RenameFile("res\\skins\\margo\\margo.jsf","C:\\Program Files\\TDSV\\Jim\\skins\\margo\\margo.jsf");

MkDir("C:\\Program Files\\TDSV\\Jim\\skins\\jim");
RenameFile("res\\skins\\jim\\addmp3.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\addmp3.jpg");
RenameFile("res\\skins\\jim\\remmp3.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\remmp3.jpg");
RenameFile("res\\skins\\jim\\rewind.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\rewind.jpg");
RenameFile("res\\skins\\jim\\forward.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\forward.jpg");
RenameFile("res\\skins\\jim\\play.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\play.jpg");
RenameFile("res\\skins\\jim\\pause.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\pause.jpg");
RenameFile("res\\skins\\jim\\pausepic.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\pausepic.jpg");
RenameFile("res\\skins\\jim\\savelist.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\savelist.jpg");
RenameFile("res\\skins\\jim\\pref.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\pref.jpg");
RenameFile("res\\skins\\jim\\openpic.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\openpic.jpg");
RenameFile("res\\skins\\jim\\sort.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\sort.jpg");
RenameFile("res\\skins\\jim\\jim.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\jim.bmp");
RenameFile("res\\skins\\jim\\jim.jsf","C:\\Program Files\\TDSV\\Jim\\skins\\jim\\jim.jsf");

MkDir("C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes");
RenameFile("res\\skins\\darkeyes\\addmp3.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\addmp3.jpg");
RenameFile("res\\skins\\darkeyes\\remmp3.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\remmp3.jpg");
RenameFile("res\\skins\\darkeyes\\rewind.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\rewind.jpg");
RenameFile("res\\skins\\darkeyes\\forward.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\forward.jpg");
RenameFile("res\\skins\\darkeyes\\play.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\play.jpg");
RenameFile("res\\skins\\darkeyes\\pause.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\pause.jpg");
RenameFile("res\\skins\\darkeyes\\pausepic.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\pausepic.jpg");
RenameFile("res\\skins\\darkeyes\\savelist.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\savelist.jpg");
RenameFile("res\\skins\\darkeyes\\pref.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\pref.jpg");
RenameFile("res\\skins\\darkeyes\\openpic.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\openpic.jpg");
RenameFile("res\\skins\\darkeyes\\sort.jpg","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\sort.jpg");
RenameFile("res\\skins\\darkeyes\\darkeyes.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\darkeyes.bmp");
RenameFile("res\\skins\\darkeyes\\darkeyes.jsf","C:\\Program Files\\TDSV\\Jim\\skins\\darkeyes\\darkeyes.jsf");

MkDir("C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel");
RenameFile("res\\skins\\ro_angel\\addmp3.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\addmp3.bmp");
RenameFile("res\\skins\\ro_angel\\remmp3.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\remmp3.bmp");
RenameFile("res\\skins\\ro_angel\\rewind.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\rewind.bmp");
RenameFile("res\\skins\\ro_angel\\forward.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\forward.bmp");
RenameFile("res\\skins\\ro_angel\\play.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\play.bmp");
RenameFile("res\\skins\\ro_angel\\pause.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\pause.bmp");
RenameFile("res\\skins\\ro_angel\\pausepic.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\pausepic.bmp");
RenameFile("res\\skins\\ro_angel\\savelist.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\savelist.bmp");
RenameFile("res\\skins\\ro_angel\\pref.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\pref.bmp");
RenameFile("res\\skins\\ro_angel\\openpic.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\openpic.bmp");
RenameFile("res\\skins\\ro_angel\\sort.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\sort.bmp");
RenameFile("res\\skins\\ro_angel\\ro_angel.bmp","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\ro_angel.bmp");
RenameFile("res\\skins\\ro_angel\\ro_angel.jsf","C:\\Program Files\\TDSV\\Jim\\skins\\ro_angel\\ro_angel.jsf");

// JPL
TRegistry *reg = new TRegistry();
reg->RootKey = HKEY_CLASSES_ROOT;
reg->OpenKey(".jpl",true);
reg->WriteString("","Jim Playlist");
reg->CloseKey();
reg->OpenKey(".jpl\\DefaultIcon",true);
reg->WriteString("", "C:\\Program Files\\TDSV\\Jim\\Jim.exe,0");
reg->CloseKey();
reg->OpenKey(".jpl\\shell\\open\\command",true);
reg->WriteString("","\"C:\\Program Files\\TDSV\\Jim\\Jim.exe\" %1");
reg->CloseKey();
// JSF
reg->RootKey = HKEY_CLASSES_ROOT;
reg->OpenKey(".jsf",true);
reg->WriteString("","Jim Skin");
reg->CloseKey();
reg->OpenKey(".jsf\\DefaultIcon",true);
reg->WriteString("", "C:\\Program Files\\TDSV\\Jim\\Jim.exe,0");
reg->CloseKey();
//Mp3
reg->RootKey = HKEY_CLASSES_ROOT;
reg->OpenKey(".mp3",true);
reg->WriteString("","Jim Mp3");
reg->CloseKey();
reg->OpenKey(".mp3\\DefaultIcon",true);
reg->WriteString("", "C:\\Program Files\\TDSV\\Jim\\Jim.exe,0");
reg->CloseKey();
reg->OpenKey(".mp3\\shell\\open\\command",true);
reg->WriteString("","\"C:\\Program Files\\TDSV\\Jim\\Jim.exe\" %1");
reg->CloseKey();
ShowMessage("Установка Завершена!");
reg->Free();
RmDir("res\\skins\\darkeyes");
RmDir("res\\skins\\ro_angel");
RmDir("res\\skins\\margo");
RmDir("res\\skins\\jim");
RmDir("res\\skins\\default");
RmDir("res\\skins");
RmDir("res\\skins\\darkeyes");
RmDir("res\\skins");
RmDir("res");
Application->Terminate();
}
else ShowMessage("Вы не приняли соглашение!"); Application->Terminate();
/*reg->DeleteKey(".jsf");
reg->DeleteKey(".jpl");
reg->DeleteKey(".my");
reg->Free(); */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Enter(TObject *Sender)
{
if (CheckBox1->Checked)
Button1->Enabled=true;
else Button1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Exit(TObject *Sender)
{
if (CheckBox1->Checked)
Button1->Enabled=true;
else Button1->Enabled=false;
}
//---------------------------------------------------------------------------
