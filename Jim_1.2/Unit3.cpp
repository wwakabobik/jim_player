//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit4.h"
#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include <Math.hpp>
#include "library.h"
#include <string.h>
#include "filectrl.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm3 *Form3;
AnsiString ModeStr[7]= {"Не готово", "Приостановлено", "Прослушивание", "Запись", "Поиск", "Пауза", "Открыто"};
int reloadstat=0;
int reloadstat2=0;
int reloadmax=0;
//int musstat=0;
bool timestat=0;


struct TAG // объявляем структуру ID3 тега ver. 1.1
{
unsigned char   tag     [ 03 ]; // сигнатура 'TAG' 3 байта
unsigned char   title   [ 30 ]; // название 30 байт
unsigned char   artist  [ 30 ]; // исполнитель 30 байт
unsigned char   album   [ 30 ]; // альбом 30 байт
unsigned char   year    [ 04 ]; // год 4 байта
unsigned char   comment [ 28 ]; // комментарий 28 байт
unsigned char   sep     [ 01 ]; // нулевой байт
unsigned char   track   [ 01 ]; // номер трека 1 байт
unsigned char   genre   [ 01 ]; // код стиля 1 байт
};

// Функция для чтения ID3 тегов ( параметр - имя файла )
AnsiString __fastcall GetMp3Tag ( AnsiString fName , int callparam )
{
	HANDLE          hFile;
	DWORD           dwFileSize;
	DWORD           dwBytesRead;
	DWORD           dwTagSize;
	DWORD           dwStartPos;
	TAG             tMp3;
    char			c[31];

	hFile = CreateFile ( fName.c_str (), GENERIC_READ, 0, NULL, OPEN_EXISTING,
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
    memmove( c, tMp3.title, 30 ); c[30] = 0;
//	MessageBox( NULL, c, "Title", NULL );
    if (callparam==1)
    return c;
    memmove( c, tMp3.artist, 30 ); c[30] = 0;
//	MessageBox( NULL, c, "Artist", NULL );
    if (callparam==2)
    return c;
    memmove( c, tMp3.album, 30 ); c[30] = 0;
//	MessageBox( NULL, c, "Album", NULL );
    if (callparam==3)
    return c;
    memmove( c, tMp3.year, 4 ); c[4] = 0;
//	MessageBox( NULL, c, "Year", NULL );
    if (callparam==4)
    return c;
    memmove( c, tMp3.comment, 28 ); c[28] = 0;
//    MessageBox( NULL, c, "Comment", NULL );
    if (callparam==5)
    return c;
}


//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::TrackBar1Change(TObject *Sender)
{
 try
 {
 try
  {
  Edit1->Text=TrackBar1->Position;
  reloadstat2=(StrToInt(Edit1->Text)-1);
  Image1->Picture->LoadFromFile(Memo1->Lines->Strings[StrToInt(Edit1->Text)-1]);
  }
 catch ( EInvalidGraphic& )
  {     //
  Memo1->Lines->Delete(StrToInt(Edit1->Text)-1);
  Memo1->Lines->SaveToFile("db\\pic.db");
  TrackBar1->Max=getlenght("db\\pic.db"); } //extension
 }
 catch ( EFOpenError& )
 {
 Memo1->Lines->Delete(StrToInt(Edit1->Text)-1);
 Memo1->Lines->SaveToFile("db\\pic.db");
 TrackBar1->Max=getlenght("db\\pic.db"); } //extension //no such file
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
try
{
if (reloadstat==0)
{
Image2->Picture->LoadFromFile("animation\\gif_sob_2.jpg");
reloadstat=1;
}
else if (reloadstat==1)
{
Image2->Picture->LoadFromFile("animation\\gif_sob_3.jpg");
reloadstat=2;
}
else if (reloadstat==2)
{
Image2->Picture->LoadFromFile("animation\\gif_sob_4.jpg");
reloadstat=3;
}
else if (reloadstat==3)
{
Image2->Picture->LoadFromFile("animation\\gif_sob_5.jpg");
reloadstat=4;
}
else if (reloadstat==4)
{
Image2->Picture->LoadFromFile("animation\\gif_sob_6.jpg");
reloadstat=5;
}
else if (reloadstat==5)
{
Image2->Picture->LoadFromFile("animation\\gif_sob_7.jpg");
reloadstat=6;
}
else if (reloadstat==6)
{
Image2->Picture->LoadFromFile("animation\\gif_sob_8.jpg");
reloadstat=7;
}
else
{
Image2->Picture->LoadFromFile("animation\\gif_sob_1.jpg");
reloadstat=0;
}
}
catch ( EFOpenError& ) {ShowMessage("Нарушение целостности программы. Программа будет закррррыта."); Application->Terminate(); }
}

//---------------------------------------------------------------------------
void __fastcall TForm3::Button2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Form1->Timer1->Enabled=false;
Form2->Timer1->Enabled=false;
Form3->Timer1->Enabled=false;
if (OpenDialog1->Execute())
{
ListBox1->Items->Add(OpenDialog1->FileName);
ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
}
Form1->Timer1->Enabled=true;
Form2->Timer1->Enabled=true;
Form3->Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Panel1Click(TObject *Sender)
{
Form1->Timer1->Enabled=false;
Form2->Timer1->Enabled=false;
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
if (OpenDialog1->Execute())
{
ListBox1->Items->Add(OpenDialog1->FileName);
//ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
ListBox2->Items->Add(AnsiString(GetMp3Tag(OpenDialog1->FileName,2))+" - "+AnsiString(GetMp3Tag(OpenDialog1->FileName,1)));
AnsiString TR;
TR=MediaPlayer1->FileName;
MediaPlayer1->Stop();
MediaPlayer1->Close();
MediaPlayer2->FileName=OpenDialog1->FileName;
MediaPlayer2->Open();
timetoplay+=MediaPlayer2->Length;
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
MediaPlayer1->FileName=TR;
MediaPlayer1->Open();
MediaPlayer1->Position=TrackBar2->Position;
MediaPlayer1->Play();
}
Form1->Timer1->Enabled=true;
Form2->Timer1->Enabled=true;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel3Click(TObject *Sender)
{
if (ListBox2->ItemIndex>= 0)
{
MediaPlayer1->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer1->Open();
MediaPlayer1->Play();
musstat=ListBox2->ItemIndex;
Timer3->Enabled=true;
if (TrackBar2->Enabled)
TrackBar2->Enabled=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel2Click(TObject *Sender)
{
if (ListBox2->ItemIndex>= 0)
{
AnsiString TR;
TR=MediaPlayer1->FileName;
MediaPlayer1->Stop();
MediaPlayer1->Close();
MediaPlayer2->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer2->Open();
timetoplay-=MediaPlayer2->Length;
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
MediaPlayer1->FileName=TR;
MediaPlayer1->Open();
MediaPlayer1->Position=TrackBar2->Position;
MediaPlayer1->Play();
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel4Click(TObject *Sender)
{
if (MediaPlayer1->Mode==2 || MediaPlayer1->Mode == 1)
{
Timer3->Enabled=!(Timer3->Enabled);
TrackBar2->Enabled=!(TrackBar2->Enabled);
MediaPlayer1->Position=TrackBar2->Position;
if (!TrackBar2->Enabled)
MediaPlayer1->Play();
else
{
MediaPlayer1->Pause();
StatusBar1->SimpleText=ModeStr[MediaPlayer1->Mode] + " ||  Всего песен: " + IntToStr(ListBox1->Items->Count) + " || Сейчас: " + Now();
TrayIcon1->Hint="Джим";
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
musstat=0;
try
{
ListBox1->Items->LoadFromFile("db\\mp3.db");
ListBox2->Items->LoadFromFile("db\\mp3init.db");
TrackBar1->Max=getlenght("db\\pic.db");
Memo1->Lines->LoadFromFile("db\\pic.db");
}
catch ( EFOpenError& ) {ShowMessage("Нарушение целостности программы. Программа будет закррррыта."); Application->Terminate(); }
try
{
try
{
Form3->timetoplay=0;
for (int i=0; i<Form3->ListBox1->Items->Count; i++)
{
Form3->MediaPlayer2->FileName=Form3->ListBox1->Items->Strings[i];
Form3->MediaPlayer2->Open();
Form3->timetoplay+=Form3->MediaPlayer2->Length;
Form3->MediaPlayer2->Close();
}
//Form3->MediaPlayer2->FileName=NULL;
if (ListBox1->Items->Count>0)
{
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
Timer3->Enabled=true;
}
}
catch (EStringListError&) { }
musstat=0;
ListBox2->ItemIndex=musstat;
//Timer3->Enabled=false;
}
catch ( EMCIDeviceError& ) { Timer3->Enabled=false; musstat=0;}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ListBox2DblClick(TObject *Sender)
{
if (ListBox2->ItemIndex>= 0)
{
MediaPlayer1->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer1->Open();
MediaPlayer1->Play();
if (TrackBar2->Enabled)
TrackBar2->Enabled=false;
musstat=ListBox2->ItemIndex;
Timer3->Enabled=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N1Click(TObject *Sender)
{
if (ListBox2->ItemIndex>= 0)
{
//timetoplay=0;
AnsiString TR;
TR=MediaPlayer1->FileName;
MediaPlayer1->Stop();
MediaPlayer1->Close();
MediaPlayer2->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer2->Open();
timetoplay-=MediaPlayer2->Length;
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
MediaPlayer1->FileName=TR;
MediaPlayer1->Open();
MediaPlayer1->Position=TrackBar2->Position;
MediaPlayer1->Play();
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N2Click(TObject *Sender)
{
ListBox1->MultiSelect=true;
ListBox2->MultiSelect=true;
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->MultiSelect=false;
ListBox2->MultiSelect=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Timer2Timer(TObject *Sender)
{
try
{                        //
Memo1->Lines->Clear();
Memo1->Lines->LoadFromFile("db\\pic.db");
//TrackBar1->Max=getlenght("db\\pic.db");
TrackBar1->Max=Memo1->Lines->Count;
//if (reloadstat2<getlenght("db\\pic.db")-1)
if (reloadstat2<Memo1->Lines->Count-1)
reloadstat2++;
else reloadstat2=0;
Edit1->Text=reloadstat2+1;
Image1->Picture->LoadFromFile(Memo1->Lines->Strings[reloadstat2]);
//Image1->Picture->LoadFromFile(Memo1->Lines->Strings[]);
TrackBar1->Position=StrToInt(Edit1->Text);
}
catch ( EFOpenError& ) {ShowMessage("Нарушение целостности программы. Программа будет закррррыта."); Application->Terminate(); }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel5Click(TObject *Sender)
{
ListBox1->Items->SaveToFile("db\\mp3.db");
ListBox2->Items->SaveToFile("db\\mp3init.db");
ShowMessage("Плейлист сохранен");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel6Click(TObject *Sender)
{
Form1->Timer1->Enabled=false;
Form2->Timer1->Enabled=false;
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
if (OpenDialog2->Execute())
Memo1->Lines->Add(OpenDialog2->FileName);
Memo1->Lines->SaveToFile("db\\pic.db");
Form1->Timer1->Enabled=true;
Form2->Timer1->Enabled=true;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
TrackBar1->Max=getlenght("db\\pic.db");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel8Click(TObject *Sender)
{
Memo1->Lines->Delete(TrackBar1->Position-1);
Memo1->Lines->SaveToFile("db\\pic.db");
TrackBar1->Max=getlenght("db\\pic.db");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel9Click(TObject *Sender)
{
Timer2->Enabled=!(Timer2->Enabled);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer3Timer(TObject *Sender)
{
try
{
int retvalue=0,retvalue2=0;
retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60);
if (retvalue>9)
Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue);
else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue);

if (!timestat)
{

 retvalue=Floor(((((StrToFloat(MediaPlayer1->Position))/1000)/60)-(StrToInt(MediaPlayer1->Position)/1000)/60)*60);
 if (retvalue>9)
 Edit3->Text=FloatToStr((StrToInt(MediaPlayer1->Position)/1000)/60)+":"+FloatToStr(retvalue);
 else
 Edit3->Text=FloatToStr((StrToInt(MediaPlayer1->Position)/1000)/60)+":0"+FloatToStr(retvalue);
}
else
{
retvalue=Floor((((((StrToFloat(MediaPlayer1->Length)-StrToFloat(MediaPlayer1->Position)))/1000)/60)-((StrToInt(MediaPlayer1->Length)-StrToInt(MediaPlayer1->Position))/1000)/60)*60);
if (retvalue>9)
Edit3->Text=FloatToStr(((StrToInt(MediaPlayer1->Length)-StrToInt(MediaPlayer1->Position))/1000)/60)+":"+FloatToStr(retvalue);
else
Edit3->Text=FloatToStr(((StrToInt(MediaPlayer1->Length)-StrToInt(MediaPlayer1->Position))/1000)/60)+":0"+FloatToStr(retvalue);
}
TrackBar2->Max=MediaPlayer1->Length;
TrackBar2->Position=MediaPlayer1->Position;
if (MediaPlayer1->Position==MediaPlayer1->Length)
{
if (!CheckBox1->Checked)
{
try
{
musstat++;
try
{
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
}
catch ( EStringListError& ) {
musstat=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
}
MediaPlayer1->Open();
MediaPlayer1->Play();
}
catch ( EMCIDeviceError& ) {
musstat++;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
}
}
else
{
int numelem;
if (ListBox1->Items->Count!=0)
numelem=ListBox1->Items->Count-1;
musstat=random(numelem);
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
}
}
if (MediaPlayer1->Mode==2)
{
AnsiString retlength,TS;
TS=AnsiString(timetoplay);
retvalue=0;
retvalue2=0;
retvalue=Floor(((((StrToFloat(TS))/1000)/60)-(StrToInt(TS)/1000)/60)*60);
retvalue2=Floor((((((StrToFloat(TS))/1000)/60)/60)-((StrToInt(TS)/1000)/60)/60)*60);
//retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":"+FloatToStr((StrToInt(TS)/1000)/60)+":"+FloatToStr(retvalue);
if (retvalue>9 && retvalue2>9)
retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":"+FloatToStr(retvalue2)+":"+FloatToStr(retvalue);
else if (retvalue<9 && retvalue2>9) retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":"+FloatToStr(retvalue2)+":0"+FloatToStr(retvalue);
else if (retvalue<9 && retvalue2<9) retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":0"+FloatToStr(retvalue2)+":0"+FloatToStr(retvalue);
else retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":0"+FloatToStr(retvalue2)+":"+FloatToStr(retvalue);
TrayIcon1->Hint="Джим играет " + AnsiString(crofilename(MediaPlayer1->FileName));
StatusBar1->SimpleText=ModeStr[MediaPlayer1->Mode]+ " песни " + AnsiString(crofilename(MediaPlayer1->FileName)) + "  || всего песен: " + IntToStr(ListBox1->Items->Count) + " || " + retlength + " || Сейчас: " + Now();
}
}
catch ( EMCIDeviceError& ) {}
}
//---------------------------------------------------------------------------






void __fastcall TForm3::Edit3Click(TObject *Sender)
{
timestat=!timestat;
}


//---------------------------------------------------------------------------







void __fastcall TForm3::Panel7Click(TObject *Sender)
{
if (!CheckBox1->Checked)
{
if (musstat!=0)
{
musstat--;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
}
else
{
musstat=ListBox2->Items->Count-1;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
}
}
else
{
int numelem;
if (ListBox1->Items->Count!=0)
numelem=ListBox1->Items->Count-1;
musstat=random(numelem);
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel10Click(TObject *Sender)
{
if (!CheckBox1->Checked)
{
try
{
musstat++;
try
{
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
}
catch ( EStringListError& ) {
musstat=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
MediaPlayer1->Open();
MediaPlayer1->Play();
}
MediaPlayer1->Open();
MediaPlayer1->Play();
}
catch ( EMCIDeviceError& ) {
musstat++;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
MediaPlayer1->Open();
MediaPlayer1->Play();
}
}
else
{
int numelem;
if (ListBox1->Items->Count!=0)
numelem=ListBox1->Items->Count-1;
musstat=random(numelem);
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::MenuItem1Click(TObject *Sender)
{
Form1->Timer1->Enabled=false;
Form2->Timer1->Enabled=false;
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
if (OpenDialog1->Execute())
{
ListBox1->Items->Add(OpenDialog1->FileName);
//ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
ListBox2->Items->Add(AnsiString(GetMp3Tag(OpenDialog1->FileName,2))+" - "+AnsiString(GetMp3Tag(OpenDialog1->FileName,1)));
timetoplay=0;
AnsiString TR;
TR=MediaPlayer1->FileName;
MediaPlayer1->Stop();
MediaPlayer1->Close();
for (int i=0; i<ListBox1->Items->Count; i++)
{
MediaPlayer2->FileName=ListBox1->Items->Strings[i];
MediaPlayer2->Open();
timetoplay+=MediaPlayer2->Length;
}
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
MediaPlayer1->FileName=TR;
MediaPlayer1->Open();
MediaPlayer1->Position=TrackBar2->Position;
MediaPlayer1->Play();
}
Form1->Timer1->Enabled=true;
Form2->Timer1->Enabled=true;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MenuItem2Click(TObject *Sender)
{
Form1->Timer1->Enabled=false;
Form2->Timer1->Enabled=false;
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form4->ShowModal();
}
//---------------------------------------------------------------------------








void __fastcall TForm3::ListBox2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==VK_DELETE)
{
if (ListBox2->ItemIndex>= 0)
{
//timetoplay=0;
AnsiString TR;
TR=MediaPlayer1->FileName;
MediaPlayer1->Stop();
MediaPlayer1->Close();
MediaPlayer2->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer2->Open();
timetoplay-=MediaPlayer2->Length;
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
MediaPlayer1->FileName=TR;
MediaPlayer1->Open();
MediaPlayer1->Position=TrackBar2->Position;
MediaPlayer1->Play();
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
}
else if (Key==VK_RETURN)
if (ListBox2->ItemIndex>= 0)
{
MediaPlayer1->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer1->Open();
MediaPlayer1->Play();
if (TrackBar2->Enabled)
TrackBar2->Enabled=false;
musstat=ListBox2->ItemIndex;
Timer3->Enabled=true;
}
}
//---------------------------------------------------------------------------





void __fastcall TForm3::MenuItem3Click(TObject *Sender)
{
Form1->Timer1->Enabled=false;
Form2->Timer1->Enabled=false;
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
if (OpenDialog2->Execute())
Memo1->Lines->Add(OpenDialog2->FileName);
Memo1->Lines->SaveToFile("db\\pic.db");
Form1->Timer1->Enabled=true;
Form2->Timer1->Enabled=true;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
TrackBar1->Max=getlenght("db\\pic.db");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MenuItem4Click(TObject *Sender)
{
Form1->Timer1->Enabled=false;
Form2->Timer1->Enabled=false;
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form5->ShowModal();
}
//---------------------------------------------------------------------------

