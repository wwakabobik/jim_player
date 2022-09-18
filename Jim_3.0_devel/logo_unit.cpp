//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "logo_unit.h"
#include "library.h"
#include <Math.hpp>
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLOGO *LOGO;
//---------------------------------------------------------------------------
__fastcall TLOGO::TLOGO(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TLOGO::Image1Click(TObject *Sender)
{
LOGO->Close();
}
//---------------------------------------------------------------------------
void __fastcall TLOGO::FormPaint(TObject *Sender)
{
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
        if (Form3->ListBox1->Items->Count>0)
                {
                Form3->Edit4->Text="   ***  "+AnsiString(GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[0].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[0].c_str(),1))+ " (";
                int scrolledit=0;
                Form3->MediaPlayer1->FileName=Form3->ListBox1->Items->Strings[0];
                Form3->MediaPlayer1->Open();
                Form3->MediaPlayer1->Play();
                Form3->Timer3->Enabled=true;
                int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(Form3->MediaPlayer1->Length))/1000)/60)-(StrToInt(Form3->MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Form3->Edit2->Text=FloatToStr((StrToInt(Form3->MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Form3->Edit2->Text=FloatToStr((StrToInt(Form3->MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); Form3->E4T="   ***  "+AnsiString(Form3->ListBox2->Items->Strings[Form3->musstat]) +"   ***  ";
                }
        }
  catch (EStringListError&) { }
  Form3->musstat=0;
  Form3->ListBox2->ItemIndex=Form3->musstat;
 }
 catch ( EMCIDeviceError& ) { Form3->Timer3->Enabled=false; Form3->musstat=0;}
 Form3->randommus = new int[Form3->ListBox2->Items->Count*10];
 randomize();
 for (int i=0; i<Form3->ListBox2->Items->Count*10; i++)
 Form3->randommus[i]=random(Form3->ListBox2->Items->Count);
//LOGO->Canvas->CopyRect(Rect(0,0,320,400),Image1->Canvas,Rect(0,0,320,400));
LOGO->Close();
Form3->Visible=true;        
}
//---------------------------------------------------------------------------
void __fastcall TLOGO::Timer1Timer(TObject *Sender)
{
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
        if (Form3->ListBox1->Items->Count>0)
                {
                                Form3->Edit4->Text="   ***  "+AnsiString(GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[0].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[0].c_str(),1))+ " (";
                int scrolledit=0;
                try {
                randomize();
                int curchoise=random(4);
                if (GetCurrentDir()==Form3->InitDirectory)
                {
                if (curchoise==0)
                {
                Form3->MediaPlayer2->FileName=GetCurrentDir()+"\\mus\\logo1.wav";
                Form3->MediaPlayer2->Open();
                Form3->MediaPlayer2->Play();
                Sleep(1500);
                }

                if (curchoise==1)
                {
                Form3->MediaPlayer2->FileName=GetCurrentDir()+"\\mus\\logo2.wav";
                Form3->MediaPlayer2->Open();
                Form3->MediaPlayer2->Play();
                Sleep(3500);
                }
                if (curchoise==2)
                {
                Form3->MediaPlayer2->FileName=GetCurrentDir()+"\\mus\\logo3.wav";
                Form3->MediaPlayer2->Open();
                Form3->MediaPlayer2->Play();
                Sleep(3500);
                }
                if (curchoise==3)
                {
                Form3->MediaPlayer2->FileName=GetCurrentDir()+"\\mus\\logo4.wav";
                Form3->MediaPlayer2->Open();
                Form3->MediaPlayer2->Play();
                Sleep(1500);
                }
                }
                }
                catch (...) { }
                Form3->MediaPlayer1->FileName=Form3->ListBox1->Items->Strings[0];
                Form3->MediaPlayer1->Open();
                Form3->MediaPlayer1->Play();
                Form3->Timer3->Enabled=true;
                int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(Form3->MediaPlayer1->Length))/1000)/60)-(StrToInt(Form3->MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Form3->Edit2->Text=FloatToStr((StrToInt(Form3->MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Form3->Edit2->Text=FloatToStr((StrToInt(Form3->MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); Form3->E4T="   ***  "+AnsiString(Form3->ListBox2->Items->Strings[Form3->musstat]) +"   ***  ";
                }
        }
  catch (EStringListError&) { }
  Form3->musstat=0;
  Form3->ListBox2->ItemIndex=Form3->musstat;
 }
 catch ( EMCIDeviceError& ) { Form3->Timer3->Enabled=false; Form3->musstat=0;}
 Form3->randommus = new int[Form3->ListBox2->Items->Count*10];
 randomize();
 for (int i=0; i<Form3->ListBox2->Items->Count*10; i++)
 Form3->randommus[i]=random(Form3->ListBox2->Items->Count);
//LOGO->Canvas->CopyRect(Rect(0,0,320,400),Image1->Canvas,Rect(0,0,320,400));
Timer1->Enabled=false;
LOGO->Close();
Form3->Visible=true;        
}
//---------------------------------------------------------------------------
