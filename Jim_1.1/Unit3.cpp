//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
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
int musstat=0;
bool timestat=0;

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
  Image1->Picture->LoadFromFile(Memo1->Lines->Strings[StrToInt(Edit1->Text)-1]);
  }
 catch ( EInvalidGraphic& )
  {
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
ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
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
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel4Click(TObject *Sender)
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
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
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
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
Timer3->Enabled=true;
musstat=0;
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
TrackBar1->Max=getlenght("db\\pic.db");
if (reloadstat2<getlenght("db\\pic.db")-1)
reloadstat2++;
else reloadstat2=0;
Image1->Picture->LoadFromFile(Memo1->Lines->Strings[reloadstat2]);
TrackBar1->Position=reloadstat+1;
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
int retvalue=0;
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
//TrayIcon1->Hint=ModeStr[MediaPlayer1->Mode]+ " песни " + AnsiString(crofilename(MediaPlayer1->FileName)) + "  || всего песен: " + IntToStr(ListBox1->Items->Count)  + " || Сейчас: " + Now();
TrayIcon1->Hint="Джим играет " + AnsiString(crofilename(MediaPlayer1->FileName));
StatusBar1->SimpleText=ModeStr[MediaPlayer1->Mode]+ " песни " + AnsiString(crofilename(MediaPlayer1->FileName)) + "  || всего песен: " + IntToStr(ListBox1->Items->Count)  + " || Сейчас: " + Now();
}
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

void __fastcall TForm3::Button1Click(TObject *Sender)
{
Form1->Timer1->Enabled=false;
Form2->Timer1->Enabled=false;
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form4->ShowModal();

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
ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
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
MediaPlayer1->Pause();
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
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
}
}
//---------------------------------------------------------------------------

