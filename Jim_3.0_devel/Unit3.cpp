//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Jpeg.hpp"
#include "Unit9.h"
#include "Unit6.h"
#include "Unit5.h"
#include "Unit4.h"
#include "Unit3.h"
#include "Unit8.h"
#include "Unit11.h"
#include "logo_unit.h"
#include <Math.hpp>
#include "library.h"
#include <string.h>
//#include <inifiles.hpp>
#include "filectrl.hpp"
#include <Registry.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
WideString exec;
AnsiString CurrentWallpaper;
bool reloadedwallpaper=false;
TForm3 *Form3;
AnsiString ModeStr[7]= {"�� ������", "��������������", "�������������", "������", "�����", "�����", "�������"};
int reloadstat=0;
int reloadstat2=0;
int reloadmax=0;
bool timestat=0;    // ������ ������� � ������ ��� �� �����
bool picstat=false; // ��������� �������� ���� ��������� ��������
int scrolledit=0,scrollstat=0;   // ��������� ���������, ������� �����
/*AnsiString E4T,SBT; // ������ �������
int randstat=0;     // ������� ������������
int *randommus;     // ������ ������������*/

int sortstat=0;       /* ������ ����������
0 - �������������
1 - ���������� �� ����� ����� �-�
2 - ���������� �� ����� ����� �-�
3 - ���������� �� �������� �-�
4 - ���������� �� �������� �-�
5 - ���������� �� ����� �-�
6 - ���������� �� ����� �-�  */

        void __fastcall DelDupe();
        void __fastcall MiscList();
        void __fastcall SortByFile();
        void __fastcall SortByGroup();
        void __fastcall SortBySong();
        void __fastcall initLang();
        void __fastcall nullRemoval();
        //void __fastcall setStatistic(AnsiString Group, AnsiString Song, AnsiString AccessTime, AnsiString Length, AnsiString FileName);
        //void __fastcall GetStatPrepare();
/*
void __fastcall GetStatPrepare()
{
if (!Form3->cashstat)
{
bool grerror=true;
AnsiString RS=Form3->ListBox2->Items->Strings[Form3->musstat], SGroup=Form3->ListBox2->Items->Strings[Form3->musstat], SSong=Form3->ListBox2->Items->Strings[Form3->musstat], SLength=Form3->ListBox2->Items->Strings[Form3->musstat], SFileName=crofilename(Form3->ListBox1->Items->Strings[Form3->musstat]);
int i=1;
while (i<=RS.Length())
{
 if (i<=RS.Length()-3)
 {
  SGroup[i]=RS[i];
  if (RS[i]==' ' && RS[i+1]=='\-' && RS[i+2]==' ')
  {
  grerror=false;
  SGroup[i]='\0';
  break;
  }
 }
 i++;
}
if (grerror)
{
SGroup="Unknown";
i=1;
}
else i=i+3;
int j=1;
if (i+1>=RS.Length())
ShowMessage("fuck!");
bool fatal_err=false;
for (;;)
{
if (RS[i]=='\(' && (RS[i+2]=='\:' || RS[i+3]=='\:') && (RS[i+5]=='\)' || RS[i+6]=='\)'))
{
fatal_err=true;
i--;j--;
break;
}
SSong[j]=RS[i];
i++; j++;
if (RS[i]=='\(' && (RS[i+2]=='\:' || RS[i+3]=='\:') && (RS[i+5]=='\)' || RS[i+6]=='\)'))
break;
}
if (!fatal_err)
SSong[j-1]='\0';
else { SSong="NoName"; i++; }
i++; j=1;
while (RS[i]!='\)')
{
SLength[j]=RS[i];
i++; j++;
}
SLength[j]='\0';
setStatistic(SGroup,SSong,Now(),SLength,SFileName);
}
}

void __fastcall setStatistic(AnsiString Group, AnsiString Song, AnsiString AccessTime, AnsiString Length, AnsiString FileName)
{
AnsiString SG1,SS1,SF1,SG2,SS2,SF2;
bool existrecord=false;
Form8->Table1->First();
while (!Form8->Table1->Eof)
{
int correct=0;
Form3->Edit6->Text=Group;
Form3->Edit7->Text=Form8->Table1->FieldByName("Group_c")->AsString;
if (Form3->Edit6->Text==Form3->Edit7->Text)
correct++;
Form3->Edit6->Text=Song;
Form3->Edit7->Text=Form8->Table1->FieldByName("Song_c")->AsString;
if (Form3->Edit6->Text==Form3->Edit7->Text)
correct++;
Form3->Edit6->Text=FileName;
Form3->Edit7->Text=Form8->Table1->FieldByName("FileName_c")->AsString;
if (Form3->Edit6->Text==Form3->Edit7->Text)
correct++;
if (correct==3)
{
existrecord=true;
Form8->Table1->Edit();
Form8->Table1->FieldByName("Access_c")->AsInteger=Form8->Table1->FieldByName("Access_c")->AsInteger+1;
Form8->Table1->FieldByName("LastAccess_c")->AsString=Now();
break;
}
Form8->Table1->Next();
}
if (!existrecord)
{
Form8->Table1->Insert();
Form8->Table1->FieldByName("Group_c")->AsString=Group;
Form8->Table1->FieldByName("Song_c")->AsString=Song;
Form8->Table1->FieldByName("Access_c")->AsInteger=1;
Form8->Table1->FieldByName("FirstAccess_c")->AsString=AccessTime;
Form8->Table1->FieldByName("LastAccess_c")->AsString=AccessTime;
Form8->Table1->FieldByName("FileName_c")->AsString=FileName;
Form8->Table1->FieldByName("UserLength_c")->AsString=Length;
Form8->Table1->Post();
}
} */


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
  try
  {
  Image1->Picture->LoadFromFile(ListBox3->Items->Strings[StrToInt(Edit1->Text)-1]);
  }
  catch (...) {}
  }
 catch ( EInvalidGraphic& )
  {
  ListBox3->Items->Delete(StrToInt(Edit1->Text)-1);
  ListBox3->Items->SaveToFile(InitDirectory+"\\db\\pic.db");
  TrackBar1->Max=getlenght((InitDirectory+"\\db\\pic.db").c_str()); } //extension
 }
 catch ( EFOpenError& )
 {
 ListBox3->Items->Delete(StrToInt(Edit1->Text)-1);
 ListBox3->Items->SaveToFile(InitDirectory+"\\db\\pic.db");
 TrackBar1->Max=getlenght((InitDirectory+"\\db\\pic.db").c_str()); } //extension //no such file
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Timer1Timer(TObject *Sender) // ������
{
int maxedit,maxstat;
scrolledit++;scrollstat++;
maxedit=E4T.Length();
maxstat=SBT.Length();
if (scrollstat==maxstat)
{
scrollstat=0;
StatusBar1->SimpleText=SBT;
}
try
{
Edit4->Text="";
for (int i=scrolledit;i<=maxedit;i++)
Edit4->Text=Edit4->Text+E4T[i];
if (scrolledit==maxedit)
scrolledit=0;
}
catch ( ERangeError& ) {scrolledit=0; Edit4->Text=E4T; }
try
{
StatusBar1->SimpleText="";
for (int i=scrollstat;i<maxstat-1;i++)
StatusBar1->SimpleText=StatusBar1->SimpleText+SBT[i];
if (scrollstat==maxstat-1)
scrollstat=0;
}
catch ( ERangeError& ) { scrollstat=0; StatusBar1->SimpleText=SBT; }
}

//---------------------------------------------------------------------------
void __fastcall TForm3::Button2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Form3->Timer1->Enabled=false;
if (OpenDialog1->Execute())
{
ListBox1->Items->Add(OpenDialog1->FileName);
ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
}
Form3->Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Panel1Click(TObject *Sender)
{
try
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
try
{
if (OpenDialog1->Execute())
{
ListBox1->Items->Add(OpenDialog1->FileName);
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
else
{
AnsiString TTagMP3=AnsiString(GetMp3Tag_DLL(OpenDialog1->FileName.c_str(),0));
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(OpenDialog1->FileName.c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(OpenDialog1->FileName.c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
}
if (!cashstat)
{
AnsiString TR;
TR=MediaPlayer1->FileName;
try
{
MediaPlayer1->Stop();
}
catch (...) {}
MediaPlayer2->FileName=OpenDialog1->FileName;
MediaPlayer2->Open();
timetoplay+=MediaPlayer2->Length;
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(Form3->MediaPlayer2->Length))/1000)/60)-(StrToInt(Form3->MediaPlayer2->Length)/1000)/60)*60);
AnsiString TIME0;
if (retvalue>9)
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer2->Length)/1000)/60)+":"+FloatToStr(retvalue);
else
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer2->Length)/1000)/60)+":0"+FloatToStr(retvalue);
Form3->ListBox2->Items->Strings[ListBox2->Items->Count-1]=Form3->ListBox2->Items->Strings[ListBox2->Items->Count-1]+" \("+TIME0+"\) ";
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
MediaPlayer1->FileName=TR;
try {
MediaPlayer1->Open();
MediaPlayer1->Position=TrackBar2->Position;
MediaPlayer1->Play();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) + "   ***   ";
}
catch ( EMCIDeviceError& ) {}
}
}
}
catch ( EMCIDeviceError& ) {}
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
try { delete randommus; } catch (...) {}
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
if (!cashstat)
{
//nullRemoval();
 AnsiString TSTR=ListBox2->Items->Strings[ListBox2->Items->Count-1];
 int errs=0;
 for (int j=1;j<TSTR.Length();j++)
 {
    if (j+1!=TSTR.Length())
    {
    if (TSTR[j]==' ' && TSTR[j+1]==' ')
    {
    errs++;
    int h=j;
    for (h=j;h<TSTR.Length();h++)
    {
    if(h+1!=TSTR.Length())
    TSTR[h]=TSTR[h+1];
    }
    j--;
    }
  } //
 }        // for j
 if (errs!=0)
 TSTR[TSTR.Length()-errs]='\0';
 else    TSTR[TSTR.Length()-errs]='\0';
 ListBox2->Items->Strings[ListBox2->Items->Count-1]=TSTR;
//
}
}
catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel3Click(TObject *Sender)
{
if (ListBox2->ItemIndex>= 0)
{
Edit4->Text="   ***  "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[ListBox2->ItemIndex].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[ListBox2->ItemIndex].c_str(),1))+ " (";
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
if (TrackBar2->Enabled)
TrackBar2->Enabled=false;
musstat=ListBox2->ItemIndex;
Timer3->Enabled=true;
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat])+"   ***  ";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel2Click(TObject *Sender)
{
if (ListBox2->ItemIndex>= 0)
{
while(ListBox2->SelCount)
{
ListBox2->ItemIndex=0;
while(!ListBox2->Selected[ListBox2->ItemIndex])
ListBox2->ItemIndex++;
if (MediaPlayer1->FileName!=ListBox1->Items->Strings[ListBox2->ItemIndex])
{
MediaPlayer2->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer2->Open();
timetoplay-=MediaPlayer2->Length;
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
}
else timetoplay-=MediaPlayer1->Length;
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
try {
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
} catch (...) {}
}
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
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
{
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
else
{
MediaPlayer1->Pause();
StatusBar1->SimpleText="   "+ModeStr[MediaPlayer1->Mode] + " ||  ����� �����: " + IntToStr(ListBox1->Items->Count) + " || ������: " + Now() + "   ";
SBT=StatusBar1->SimpleText;
TrayIcon1->Hint="����";
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
Form6->Memo2->Clear();
Form6->Memo2->Lines->Add(Form6->LabeledEdit3->Text);
Form6->Memo2->Lines->Add(Form3->Left);
Form6->Memo2->Lines->Add(Form3->Top);
Form6->Memo2->Lines->Add(Form6->ComboBox3->ItemIndex);
int tempbool;
tempbool=Form3->CheckBox1->Checked;
Form6->Memo2->Lines->Add(IntToStr(tempbool));
tempbool=Form3->CheckBox2->Checked;
Form6->Memo2->Lines->Add(IntToStr(tempbool));
Form6->Memo2->Lines->Add(Form4->Label2->Caption);
Form6->Memo2->Lines->Add(Form5->Label2->Caption);
tempbool=Form6->CheckBox4->Checked;
Form6->Memo2->Lines->Add(IntToStr(tempbool));
Form6->Memo2->Lines->Add(Form8->LabeledEdit3->Text);
Form6->Memo2->Lines->Add(Form8->LabeledEdit5->Text);
Form6->Memo2->Lines->SaveToFile("jim.ini");
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
InitDirectory="C:\\Documents and Settings\\WW\\My Documents\\cpp\\jim"; // ���������?
CLOSE_BUTTON->Left=Form3->Width-10;
CLOSE_BUTTON->Top=0;
// ����������� ������� � �������
        RegisterHotKey(Handle,1,MOD_ALT | MOD_CONTROL, int(VK_PRIOR)); // PageDown - ����� �����
        RegisterHotKey(Handle,2,MOD_ALT | MOD_CONTROL, int(VK_NEXT));  // PageUp - ����� �����
        RegisterHotKey(Handle,3,MOD_ALT | MOD_CONTROL, int(VK_ESCAPE)); // Esc - ����
        RegisterHotKey(Handle,4,MOD_ALT | MOD_CONTROL, int(VK_END));    // End - Shuffle
        RegisterHotKey(Handle,5,MOD_ALT | MOD_CONTROL, int(VK_HOME));   // Home - Repeat
        RegisterHotKey(Handle,6,MOD_ALT | MOD_CONTROL, int('1'));       // 1 - �������� 1
        RegisterHotKey(Handle,7,MOD_ALT | MOD_CONTROL, int('2'));       // 2 - �������� 2
        RegisterHotKey(Handle,8,MOD_ALT | MOD_CONTROL, int('3'));       // 3 - �������� 3
        RegisterHotKey(Handle,9,MOD_ALT | MOD_CONTROL, int('4'));       // 4 - �������� 4
        RegisterHotKey(Handle,10,MOD_ALT | MOD_CONTROL, int('5'));      // 5 - �������� 5
        RegisterHotKey(Handle,11,MOD_ALT | MOD_CONTROL, int('6'));      // 6 - �������� 6
        RegisterHotKey(Handle,12,MOD_ALT | MOD_CONTROL, int('7'));      // 7 - �������� 7
        RegisterHotKey(Handle,13,MOD_ALT | MOD_CONTROL, int('8'));      // 8 - �������� 8
        RegisterHotKey(Handle,14,MOD_ALT | MOD_CONTROL, int('9'));      // 9 - �������� 9
        RegisterHotKey(Handle,15,MOD_ALT | MOD_CONTROL, int('0'));      // 0 - �������� 0
        RegisterHotKey(Handle,16,MOD_ALT | MOD_CONTROL, int(VK_SCROLL)); // ����������
        RegisterHotKey(Handle,17,MOD_ALT | MOD_CONTROL, 220);            // ��������
        RegisterHotKey(Handle,18,MOD_ALT | MOD_CONTROL, int(VK_INSERT));  // �������� �� ��
        RegisterHotKey(Handle,19,MOD_ALT | MOD_CONTROL, int(VK_PAUSE)); // ������� �� ��
        //RegisterHotKey(Handle,20,MOD_ALT | MOD_CONTROL, int(VK_SNAPSHOT)); // ������� �� ��
//
//�������������� �����
TRegistry *regwall = new TRegistry;
regwall->OpenKey("Control Panel\\Desktop",false);
CurrentWallpaper=regwall->ReadString("Wallpaper");
// ��������� ���������� �������
randstat=0;
cashstat=0;
itemscount=0;
//�������� ����������
        Memo1->Clear(); //
        Memo1->Lines->LoadFromFile("jim.ini");
        /* initialize init status */
        Form6->Memo1->Lines->LoadFromFile(Memo1->Lines->Strings[0]);
        Form6->LabeledEdit3->Text=Memo1->Lines->Strings[0];
        Form6->Memo2->Lines->LoadFromFile("jim.ini");
        Form3->Left=StrToInt(Form6->Memo2->Lines->Strings[1]);
        Form3->Top=StrToInt(Form6->Memo2->Lines->Strings[2]);
        Form6->ComboBox3->ItemIndex=StrToInt(Form6->Memo2->Lines->Strings[3]);
        Form3->CheckBox1->Checked=StrToInt(Form6->Memo2->Lines->Strings[4]);
        Form3->CheckBox2->Checked=StrToInt(Form6->Memo2->Lines->Strings[5]);
        Form4->Label2->Caption=Form6->Memo2->Lines->Strings[6];
        Form5->Label2->Caption=Form6->Memo2->Lines->Strings[7];
        Form6->CheckBox4->Checked=StrToInt(Form6->Memo2->Lines->Strings[8]);
        Form8->LabeledEdit3->Text=IntToStr(StrToInt(Form6->Memo2->Lines->Strings[9])+1);
        if (Form6->Memo2->Lines->Strings[10]=="0")
                Form8->LabeledEdit5->Text=Now();
        else Form8->LabeledEdit5->Text=Form6->Memo2->Lines->Strings[10];
        Memo1->Clear();
        initLang(); // ����
        CLOSE_BUTTON->Color=StrToInt(Form6->Memo1->Lines->Strings[5]);
        Edit1->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
        Edit2->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
        Edit3->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
        Edit4->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
        Edit1->Font->Name=Form6->Memo1->Lines->Strings[1];
        Edit1->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
        Edit1->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
        Edit1->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
        Edit2->Font->Name=Form6->Memo1->Lines->Strings[1];
        Edit2->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
        Edit2->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
        Edit2->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
        Edit3->Font->Name=Form6->Memo1->Lines->Strings[1];
        Edit3->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
        Edit3->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
        Edit3->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
        Edit4->Font->Name=Form6->Memo1->Lines->Strings[1];
        Edit4->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
        Edit4->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
        Edit4->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
        ListBox2->Color=StrToInt(Form6->Memo1->Lines->Strings[5]);
        ListBox2->Font->Name=Form6->Memo1->Lines->Strings[6];
        ListBox2->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[7]);
        ListBox2->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[8]);
        ListBox2->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[9]);
        Form3->Color=StrToInt(Form6->Memo1->Lines->Strings[10]);
        Form3->Font->Name=Form6->Memo1->Lines->Strings[11];
        Form3->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[12]);
        Form3->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[13]);
        Form3->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[14]);
        StatusBar1->Color=StrToInt(Form6->Memo1->Lines->Strings[15]);
        StatusBar1->Font->Name=Form6->Memo1->Lines->Strings[16];
        StatusBar1->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[17]);
        StatusBar1->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[18]);
        StatusBar1->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[19]);
        Form3->AlphaBlendValue=StrToInt(Form6->Memo1->Lines->Strings[20]);
        Form3->Timer2->Interval=StrToInt(Form6->Memo1->Lines->Strings[21]);
        Image3->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[22]);
        Form6->Image1->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[22]);
        Form6->LabeledEdit2->Text=Form6->Memo1->Lines->Strings[22];
        Image2->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[23]);
        Image10->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[24]);
        Image9->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[25]);
        Image8->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[26]);
        Image4->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[27]);
        Image5->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[28]);
        Image6->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[29]);
        Form3->Image7->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[30]);
        Form3->Image11->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[31]);
        Form3->Image12->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[32]);
        Form3->Image13->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[33]);
        Form3->Image14->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[34]);
        Form6->ListBox1->Items->Strings[0]=Form6->Memo1->Lines->Strings[23];
        Form6->ListBox1->Items->Strings[1]=Form6->Memo1->Lines->Strings[24];
        Form6->ListBox1->Items->Strings[2]=Form6->Memo1->Lines->Strings[25];
        Form6->ListBox1->Items->Strings[3]=Form6->Memo1->Lines->Strings[26];
        Form6->ListBox1->Items->Strings[4]=Form6->Memo1->Lines->Strings[27];
        Form6->ListBox1->Items->Strings[5]=Form6->Memo1->Lines->Strings[28];
        Form6->ListBox1->Items->Strings[6]=Form6->Memo1->Lines->Strings[29];
        Form6->ListBox1->Items->Strings[7]=Form6->Memo1->Lines->Strings[30];
        Form6->ListBox1->Items->Strings[8]=Form6->Memo1->Lines->Strings[31];
        Form6->ListBox1->Items->Strings[9]=Form6->Memo1->Lines->Strings[32];
        Form6->ListBox1->Items->Strings[10]=Form6->Memo1->Lines->Strings[33];
        Form6->ListBox1->Items->Strings[11]=Form6->Memo1->Lines->Strings[34];
        Form6->ListBox1->Items->Strings[12]=Form6->Memo1->Lines->Strings[42];
        Form3->multiplybkg=StrToInt(Form6->Memo1->Lines->Strings[35]);
        Form6->CheckBox2->Checked=multiplybkg;
        Form6->CheckBox1->Checked=StrToInt(Form6->Memo1->Lines->Strings[36]);
        Form6->CheckBox3->Checked=StrToInt(Form6->Memo1->Lines->Strings[37]);
        Form6->LabeledEdit4->Text=Form6->Memo1->Lines->Strings[38];
        Form6->LabeledEdit5->Text=Form6->Memo1->Lines->Strings[39];
        Form6->LabeledEdit6->Text=Form6->Memo1->Lines->Strings[40];
        Form6->LabeledEdit7->Text=Form6->Memo1->Lines->Strings[41];
        Image15->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[42]);
        Form3->ListBox2->Width=StrToInt(Form6->LabeledEdit4->Text);
        Form3->ListBox2->Height=StrToInt(Form6->LabeledEdit5->Text);
        Form3->Image1->Width=StrToInt(Form6->LabeledEdit6->Text);
        Form3->Image1->Height=StrToInt(Form6->LabeledEdit7->Text);
        Form3->Image1->Left=StrToInt(Form6->LabeledEdit4->Text);
        Form3->Width=ListBox2->Width;
        TrackBar2->Width=ListBox2->Width;
        Image4->Top=ListBox2->Top+ListBox2->Height+2;
        Image5->Top=ListBox2->Top+ListBox2->Height+2;
        Image6->Top=ListBox2->Top+ListBox2->Height+2;
        Image7->Top=ListBox2->Top+ListBox2->Height+2;
        Image11->Top=ListBox2->Top+ListBox2->Height+2;
        Image15->Top=ListBox2->Top+ListBox2->Height+2;
        Image12->Left=ListBox2->Width+10;
        Image13->Left=ListBox2->Width+Image12->Width+15;
        Image14->Left=ListBox2->Width+Image12->Width+Image13->Width+20;
        Image12->Top=Image1->Height+20;
        Image13->Top=Image1->Height+20;
        Image14->Top=Image1->Height+20;
        TrackBar1->Top=Image1->Height+20;
        Edit1->Top=Image1->Height+20;
        MOOD->Width=Form3->Width;
        MOOD->Top=Image15->Top+25;
        MOOD->Left=0;
        MOOD->Color=StrToInt(Form6->Memo1->Lines->Strings[5]);
        Form3->Height=MOOD->Top+45;
        Edit1->Left=ListBox2->Width+Image12->Width+Image13->Width+Image14->Width+25;
        TrackBar1->Left=Edit1->Width+ListBox2->Width+Image12->Width+Image13->Width+Image14->Width+25;
        Image16->Picture->LoadFromFile(InitDirectory+"\\animation\\split.bmp");
        /* end of init*/
//����� ��������
//�������������� ���������
if (Form6->CheckBox2->Checked==false)
{
/* single block skin */
for (int i=0; i<=Image3->Picture->Width; i++)
 {
 for (int j=Image3->Picture->Height;j>=0;j--)
  {
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i][j];
  }
 }
 }
 else
 {
/* multiply block skin */
for (int i=0; i<=Form3->Width; i++)
 {
 for (int j=Form3->Height;j>=0;j--)
  {
  int Wcoeff,Hcoeff;
  if (i>Image3->Picture->Width && j>Image3->Picture->Height)
  {
  Wcoeff=i/Image3->Picture->Width;
  Hcoeff=j/Image3->Picture->Height;
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i-Wcoeff*Image3->Picture->Width][j-Hcoeff*Image3->Picture->Height];
  }
  else if (i>Image3->Picture->Width)
  {
  Wcoeff=i/Image3->Picture->Width;
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i-Wcoeff*Image3->Picture->Width][j];
  }
  else if (j>Image3->Picture->Height)
  {
  Hcoeff=j/Image3->Picture->Height;
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i][j-Hcoeff*Image3->Picture->Height];
  }
  else
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i][j];
  }
 }
 }
// ����� ���������
musstat=0;
//�������� DB
try
{
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\mp3.db");
ListBox2->Items->LoadFromFile(InitDirectory+"\\db\\mp3init.db");
TrackBar1->Max=getlenght((InitDirectory+"\\db\\pic.db").c_str());
ListBox3->Items->LoadFromFile(InitDirectory+"\\db\\pic.db");
}
catch ( EFOpenError& ) {ShowMessage("��������� ����������� ���������. ��������� ����� ����������."); Application->Terminate(); }
LOGO->ShowModal();
//���, ��� ����
/*try
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
if (ListBox1->Items->Count>0)
{
Edit4->Text="   ***  "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[0].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[0].c_str(),1))+ " (";
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
Timer3->Enabled=true;
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
}
catch (EStringListError&) { }
musstat=0;
ListBox2->ItemIndex=musstat;
}
catch ( EMCIDeviceError& ) { Timer3->Enabled=false; musstat=0;}
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count); */
scrolledit=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ListBox2DblClick(TObject *Sender)
{
if (ListBox2->ItemIndex>= 0)
{
Edit4->Text="   ***  "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[ListBox2->ItemIndex].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[ListBox2->ItemIndex].c_str(),1))+ " (";
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer1->Open();
MediaPlayer1->Play();
if (TrackBar2->Enabled)
TrackBar2->Enabled=false;
musstat=ListBox2->ItemIndex;
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer3->Enabled=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N1Click(TObject *Sender)
{
try {
if (ListBox2->ItemIndex>= 0)
{
while(ListBox2->SelCount)
{
ListBox2->ItemIndex=0;
while(!ListBox2->Selected[ListBox2->ItemIndex])
ListBox2->ItemIndex++;
if (MediaPlayer1->FileName!=ListBox1->Items->Strings[ListBox2->ItemIndex])
{
MediaPlayer2->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer2->Open();
timetoplay-=MediaPlayer2->Length;
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
}
else timetoplay-=MediaPlayer1->Length;
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
try {
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
} catch (...) {}
}
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
} catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N2Click(TObject *Sender)
{
try {
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
try {
delete randommus;     // ������ ������������
}
catch (...) {}
sortstat=0;
randstat=0;
cashstat=false;
itemscount=0;
Timer4->Enabled=false;
musstat=0;
} catch (...) {}
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Timer2Timer(TObject *Sender) // ��������
{
if (ListBox3->Items->Count)
{
TrackBar1->Enabled=true;
try
{
try
{
TrackBar1->Max=ListBox3->Items->Count;
if (reloadstat2<ListBox3->Items->Count-1)
reloadstat2++;
else { reloadstat2=0; }
Edit1->Text=reloadstat2+1;
try {
try {
Image1->Picture->LoadFromFile(ListBox3->Items->Strings[reloadstat2]);
if (Form6->CheckBox6->Checked)
{
AnsiString WallNow;
BMP_TEMP->Picture->Bitmap->Height=Image1->Picture->Graphic->Height;
BMP_TEMP->Picture->Bitmap->Width=Image1->Picture->Graphic->Width;
BMP_TEMP->Canvas->Draw(0,0,Image1->Picture->Graphic);
BMP_TEMP->Canvas->TextOutA(Screen->Width-140,Screen->Height-40,Edit4->Text);
BMP_TEMP->Picture->SaveToFile("C:\\Program Files\\TDSV\\Jim\\animation\\wall.bmp");
WallNow="C:\\Program Files\\TDSV\\Jim\\animation\\wall.bmp";
SystemParametersInfo(SPI_SETDESKWALLPAPER,0,WallNow.c_str(),SPIF_UPDATEINIFILE);
}
}
catch (...) {reloadstat2=0; }
}
catch ( EInvalidGraphic& ) {}
TrackBar1->Position=StrToInt(Edit1->Text);
}
catch ( EFOpenError& ) {ShowMessage("��������� ����������� ���������. ��������� ����� ����������."); Application->Terminate(); }
}
catch (...) {}
}
else
TrackBar1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel5Click(TObject *Sender)
{
ListBox1->Items->SaveToFile(InitDirectory+"\\db\\mp3.db");
ListBox2->Items->SaveToFile(InitDirectory+"\\db\\mp3init.db");
ShowMessage("�������� ��������");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel6Click(TObject *Sender)
{
TrackBar1->Enabled=true;
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
if (OpenDialog2->Execute())
ListBox3->Items->Add(OpenDialog2->FileName);
ListBox3->Items->SaveToFile(InitDirectory+"\\db\\pic.db");
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
TrackBar1->Max=ListBox3->Items->Count;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel8Click(TObject *Sender)
{
ListBox3->Items->Delete(TrackBar1->Position-1);
ListBox3->Items->SaveToFile(InitDirectory+"\\db\\pic.db");
TrackBar1->Max=ListBox3->Items->Count;
if (ListBox3->Items->Count)
TrackBar1->Enabled=true;
else
TrackBar1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel9Click(TObject *Sender)
{
Timer2->Enabled=!(Timer2->Enabled);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer3Timer(TObject *Sender) // current position on song
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
if (ListBox2->Items->Count>0)
{
try
{
musstat++;
try
{
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
int retvalue=0,retvalue2=0;
retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60);
if (retvalue>9)
Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue);
else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue);
scrolledit=0;
ListBox2->ItemIndex=musstat;
}
catch ( EStringListError& ) {
musstat=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
catch ( EMCIDeviceError& ) {
musstat++;
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
if (!CheckBox2->Checked && musstat==0)
MediaPlayer1->Stop();
}
}
else
{
if (ListBox2->Items->Count>0)
{
if (!Form6->CheckBox3->Checked)
{
int numelem;
if (ListBox1->Items->Count!=0)
numelem=ListBox1->Items->Count-1;
musstat=random(numelem);
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
else //���� ����������������
{
if (randstat<ListBox2->Items->Count*10)
randstat++;
else randstat=0;
musstat=randommus[randstat];
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
}
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
if (retvalue>9 && retvalue2>9)
retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":"+FloatToStr(retvalue2)+":"+FloatToStr(retvalue);
else if (retvalue<9 && retvalue2>9) retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":"+FloatToStr(retvalue2)+":0"+FloatToStr(retvalue);
else if (retvalue<9 && retvalue2<9) retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":0"+FloatToStr(retvalue2)+":0"+FloatToStr(retvalue);
else retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":0"+FloatToStr(retvalue2)+":"+FloatToStr(retvalue);
if (Form6->ComboBox3->ItemIndex==0)
TrayIcon1->Hint="���� ������ " + AnsiString(crofilename(MediaPlayer1->FileName));
else if (Form6->ComboBox3->ItemIndex==1)
TrayIcon1->Hint="Jim playing " + AnsiString(crofilename(MediaPlayer1->FileName));
else if (Form6->ComboBox3->ItemIndex==2)
TrayIcon1->Hint="Jim spiel " + AnsiString(crofilename(MediaPlayer1->FileName));
if (Form6->ComboBox3->ItemIndex==0)
SBT="   "+ModeStr[MediaPlayer1->Mode]+ " ����� " + AnsiString(crofilename(MediaPlayer1->FileName)) + "  || ����� �����: " + IntToStr(ListBox1->Items->Count) + " || " + retlength + " || ������: " + Now() + "   ";
if (Form6->ComboBox3->ItemIndex==1)
SBT="   Playing song " + AnsiString(crofilename(MediaPlayer1->FileName)) + "  || Total: " + IntToStr(ListBox1->Items->Count) + " || " + retlength + " || Now: " + Now() + "   ";
if (Form6->ComboBox3->ItemIndex==2)
SBT="   Spiele singe " + AnsiString(crofilename(MediaPlayer1->FileName)) + "  || Alle: " + IntToStr(ListBox1->Items->Count) + " || " + retlength + " || Jetz: " + Now() + "   ";
}
}
catch ( EMCIDeviceError& ) {}
if (!Form3->Active && Form6->CheckBox5->Checked)
{
reloadedwallpaper=true;
HDC HD = GetWindowDC(GetDesktopWindow());
RECT R1 = Rect(0,20,Screen->Width-40,Screen->Height);
RECT R2 = Rect(0,40,Screen->Width-40,Screen->Height);
//CopyRect(R,BMP_TEMP->Canvas,Rect(0,20,Screen->Width-40,Screen->Height));
//Graphics::TBitmap* mask = new Graphics::TBitmap;
//mask=BMP_TEMP->Picture->Bitmap;   //
//BMP_TEMP->Canvas->BrushCopy(R,BMP_TEMP->Picture->Bitmap,Rect(0,20,Screen->Width-40,Screen->Height),clBlack);
AnsiString S=Edit4->Text,S1=Edit2->Text,S2=Edit3->Text,S3=" "+S1+" / "+S2+" ";
DrawText(HD,S.c_str(), S.Length(), &R1, DT_RIGHT+DT_WORDBREAK);
DrawText(HD,S3.c_str(), S3.Length(), &R2, DT_RIGHT+DT_WORDBREAK);
ReleaseDC(GetDesktopWindow,HD);
}
else
{
if (reloadedwallpaper==true)
{
SystemParametersInfo(SPI_SETDESKWALLPAPER,0,CurrentWallpaper.c_str(),SPIF_UPDATEINIFILE);
reloadedwallpaper=false;
}
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
if (ListBox2->Items->Count>0)
{
if (musstat!=0)
{
musstat--;
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
else
{
musstat=ListBox2->Items->Count-1;
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
}
}
else
{
if (!Form6->CheckBox3->Checked)
{
int numelem;
if (ListBox1->Items->Count!=0)
numelem=ListBox1->Items->Count-1;
musstat=random(numelem);
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
else //���� ����������������
{
if (ListBox1->Items->Count!=0)
{
if (randstat>0)
randstat--;
else randstat=randommus[ListBox2->Items->Count*10-1];
musstat=randommus[randstat];
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
else { randstat=0; musstat=0; MediaPlayer1->Stop(); }

}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Panel10Click(TObject *Sender)
{
if (!CheckBox1->Checked)
{
if (ListBox2->Items->Count>0)
{
try
{
if (musstat+1<ListBox2->Items->Count)
musstat++;
else {musstat=0;}
try
{
try
{
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
scrolledit=0;
}
catch ( EStringListError& ) {
musstat=0;
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
}
catch ( EStringListError& ) {
musstat=0;
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
catch ( EMCIDeviceError& ) {
musstat++;
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
if (!CheckBox2->Checked && musstat==0)
MediaPlayer1->Stop();
}
}
else
{
if (!Form6->CheckBox3->Checked)
{
int numelem;
if (ListBox1->Items->Count!=0)
numelem=ListBox1->Items->Count-1;
musstat=random(numelem);
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
else //���� ����������������
{
if (ListBox1->Items->Count!=0)
{
if (randstat<ListBox2->Items->Count*10)
randstat++;
else randstat=0;
musstat=randommus[randstat];
scrolledit=0;
MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
ListBox2->ItemIndex=musstat;
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
}
else { randstat=0; musstat=0; MediaPlayer1->Stop(); }
}
}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::MenuItem1Click(TObject *Sender)
{
try
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
try
{
if (OpenDialog1->Execute())
{
ListBox1->Items->Add(OpenDialog1->FileName);
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
else
{
AnsiString TTagMP3=AnsiString(GetMp3Tag_DLL(OpenDialog1->FileName.c_str(),0));
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(OpenDialog1->FileName.c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(OpenDialog1->FileName.c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(OpenDialog1->FileName)));
}
if (!cashstat)
{
AnsiString TR;
TR=MediaPlayer1->FileName;
try
{
MediaPlayer1->Stop();
}
catch (...) {}
MediaPlayer2->FileName=OpenDialog1->FileName;
MediaPlayer2->Open();
timetoplay+=MediaPlayer2->Length;
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(Form3->MediaPlayer2->Length))/1000)/60)-(StrToInt(Form3->MediaPlayer2->Length)/1000)/60)*60);
AnsiString TIME0;
if (retvalue>9)
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer2->Length)/1000)/60)+":"+FloatToStr(retvalue);
else
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer2->Length)/1000)/60)+":0"+FloatToStr(retvalue);
Form3->ListBox2->Items->Strings[ListBox2->Items->Count-1]=Form3->ListBox2->Items->Strings[ListBox2->Items->Count-1]+" \("+TIME0+"\) ";
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
MediaPlayer1->FileName=TR;
try {
MediaPlayer1->Open();
MediaPlayer1->Position=TrackBar2->Position;
MediaPlayer1->Play();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) + "   ***   ";
}
catch ( EMCIDeviceError& ) {}
}
}
}
catch ( EMCIDeviceError& ) {}
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
try { delete randommus; } catch (...) {}
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
if (!cashstat)
{
//nullRemoval();
 AnsiString TSTR=ListBox2->Items->Strings[ListBox2->Items->Count-1];
 int errs=0;
 for (int j=1;j<TSTR.Length();j++)
 {
    if (j+1!=TSTR.Length())
    {
    if (TSTR[j]==' ' && TSTR[j+1]==' ')
    {
    errs++;
    int h=j;
    for (h=j;h<TSTR.Length();h++)
    {
    if(h+1!=TSTR.Length())
    TSTR[h]=TSTR[h+1];
    }
    j--;
    }
  } //
 }        // for j
 if (errs!=0)
 TSTR[TSTR.Length()-errs]='\0';
 else    TSTR[TSTR.Length()-errs]='\0';
 ListBox2->Items->Strings[ListBox2->Items->Count-1]=TSTR;
//
}
}
catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MenuItem2Click(TObject *Sender)
{
try {
try {
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
Form4->ShowModal();
try
{
delete randommus;
}
catch (...) {}
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
catch ( EMCIDeviceError& ) {}
//nullRemoval();
timetoplay=0;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->Timer3->Enabled=true;
}
catch (...) {}
}
//---------------------------------------------------------------------------








void __fastcall TForm3::ListBox2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==VK_DELETE)
{
if (ListBox2->ItemIndex>= 0)
{
while(ListBox2->SelCount)
{
ListBox2->ItemIndex=0;
while(!ListBox2->Selected[ListBox2->ItemIndex])
ListBox2->ItemIndex++;
if (MediaPlayer1->FileName!=ListBox1->Items->Strings[ListBox2->ItemIndex])
{
MediaPlayer2->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer2->Open();
timetoplay-=MediaPlayer2->Length;
MediaPlayer2->Stop();
MediaPlayer2->Close();
MediaPlayer2->FileName=NULL;
}
else timetoplay-=MediaPlayer1->Length;
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
try {
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
} catch (...) {}
}
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (Key==VK_RETURN)
if (ListBox2->ItemIndex>= 0)
{
MediaPlayer1->FileName=ListBox1->Items->Strings[ListBox2->ItemIndex];
MediaPlayer1->Open();
MediaPlayer1->Play();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
if (TrackBar2->Enabled)
TrackBar2->Enabled=false;
musstat=ListBox2->ItemIndex;
//if (Form6->CheckBox4->Checked) GetStatPrepare();
Timer3->Enabled=true;
}
}
//---------------------------------------------------------------------------





void __fastcall TForm3::MenuItem3Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
if (OpenDialog2->Execute())
ListBox3->Items->Add(OpenDialog2->FileName);
ListBox3->Items->SaveToFile(InitDirectory+"\\db\\pic.db");
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
TrackBar1->Max=ListBox3->Items->Count;
if (ListBox3->Items->Count)
TrackBar1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MenuItem4Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form5->ShowModal();
if (ListBox3->Items->Count)
TrackBar1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormPaint(TObject *Sender)
{

if (Form6->CheckBox2->Checked==false)
{
// single block skin
for (int i=0; i<=Image3->Picture->Width; i++)
 {
 for (int j=Image3->Picture->Height;j>=0;j--)
  {
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i][j];
  }
 }
 }
 else
 {
// multiply block skin
for (int i=0; i<=Form3->Width; i++)
 {
 for (int j=Form3->Height;j>=0;j--)
  {
  int Wcoeff,Hcoeff;
  if (i>Image3->Picture->Width && j>Image3->Picture->Height)
  {
  Wcoeff=i/Image3->Picture->Width;
  Hcoeff=j/Image3->Picture->Height;
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i-Wcoeff*Image3->Picture->Width][j-Hcoeff*Image3->Picture->Height];
  }
  else if (i>Image3->Picture->Width)
  {
  Wcoeff=i/Image3->Picture->Width;
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i-Wcoeff*Image3->Picture->Width][j];
  }
  else if (j>Image3->Picture->Height)
  {
  Hcoeff=j/Image3->Picture->Height;
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i][j-Hcoeff*Image3->Picture->Height];
  }
  else
  Form3->Canvas->Pixels[i][j]=Image3->Canvas->Pixels[i][j];
  }
 }
 }
 }

//---------------------------------------------------------------------------

void __fastcall TForm3::Image11Click(TObject *Sender)
{
//Application->Terminate();
// ��������\������� ���� ��������� �����������
if (picstat)
{
picstat=false;
Form3->ClientWidth=StrToInt(Form6->LabeledEdit4->Text);
Timer2->Enabled=false;
}
else
{
picstat=true;                                                                    //
Form3->ClientWidth=StrToInt(Form6->LabeledEdit4->Text)+StrToInt(Form6->LabeledEdit6->Text);
//Timer2->Enabled=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image7Click(TObject *Sender)
{
// ����� ��������
Form6->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MenuItem5Click(TObject *Sender)
{
// ���������� ��������� �� ���������
ListBox1->Items->SaveToFile(InitDirectory+"\\db\\mp3.db");
ListBox2->Items->SaveToFile(InitDirectory+"\\db\\mp3init.db");
ShowMessage("�������� ��������");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MenuItem6Click(TObject *Sender)
{
// ���������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
if (SaveDialog1->Execute())
{
if (ExtractFileExt(SaveDialog1->FileName)!=".jpl" && ExtractFileExt(SaveDialog1->FileName)!=".JPL")
SaveDialog1->FileName=SaveDialog1->FileName+".jpl";
ListBox1->Items->SaveToFile(SaveDialog1->FileName);
}
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N3Click(TObject *Sender)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
if (OpenDialog3->Execute())
{
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(OpenDialog3->FileName);

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0));
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
}
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
//if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::HTML1Click(TObject *Sender)
{
Timer2->Enabled=false;
// ���������� ��������� � ������� HTML
if (SaveDialog2->Execute())
{
AnsiString retlength,TS;
TS=AnsiString(timetoplay);
int retvalue=0;
int retvalue2=0;
retvalue=Floor(((((StrToFloat(TS))/1000)/60)-(StrToInt(TS)/1000)/60)*60);
retvalue2=Floor((((((StrToFloat(TS))/1000)/60)/60)-((StrToInt(TS)/1000)/60)/60)*60);
if (retvalue>9 && retvalue2>9)
retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":"+FloatToStr(retvalue2)+":"+FloatToStr(retvalue);
else if (retvalue<9 && retvalue2>9) retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":"+FloatToStr(retvalue2)+":0"+FloatToStr(retvalue);
else if (retvalue<9 && retvalue2<9) retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":0"+FloatToStr(retvalue2)+":0"+FloatToStr(retvalue);
else retlength=FloatToStr(((StrToInt(TS)/1000)/60)/60)+":0"+FloatToStr(retvalue2)+":"+FloatToStr(retvalue);
if (ExtractFileExt(SaveDialog2->FileName)!=".htm" && ExtractFileExt(SaveDialog2->FileName)!=".html")
SaveDialog2->FileName=SaveDialog2->FileName+".html";
Memo2->Clear();
Memo2->Lines->Add("<HTML>");
Memo2->Lines->Add("<HEAD>");
Memo2->Lines->Add("<TITLE>Jim Playlist, "+ Now()+"</TITLE>");
Memo2->Lines->Add("</HEAD>");
Memo2->Lines->Add("<BODY bgcolor=navy text=yellow link=yellow vlink=yellow alink=yellow>");
Memo2->Lines->Add("<H1>�������� ������������ ������ 2.0</H1><BR>");
for (int i=0;i<ListBox2->Items->Count;i++)
Memo2->Lines->Add(ListBox2->Items->Strings[i]+"<BR>");
Memo2->Lines->Add("<BR><BR>����� � ��������� �����: " + IntToStr(ListBox1->Items->Count) + "<BR>����� �����������������: " + retlength);
Memo2->Lines->Add("<BR><BR>�������� ������������: <a href=\"http:\\\\illusionist7.narod.ru\">http:\\\\illusionist7.narod.ru</a>");
Memo2->Lines->Add("</BODY>");
Memo2->Lines->Add("</HTML>");
Memo2->Lines->SaveToFile(SaveDialog2->FileName);
}
Timer2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall SortByGroup() // ���������� �� ������ (��������)
{
if (sortstat!=3)
{
for (int j=0; j<Form3->ListBox2->Items->Count; j++)
{
for (int i=j; i<Form3->ListBox2->Items->Count; i++)
{
 if (i!=j)
 {
 AnsiString STR1=Form3->ListBox2->Items->Strings[j],STR2=Form3->ListBox2->Items->Strings[i];
 int maxlength;
 if (STR1.Length()<STR2.Length())
 maxlength=STR1.Length();
 else maxlength=STR2.Length();
 for (int k=1; k<maxlength; k++)
  {
  if (STR1[k]<STR2[k])
  break;
  if (STR2[k]<STR1[k])
  {
   AnsiString tempname,tempname2;
   tempname=Form3->ListBox2->Items->Strings[j];
   tempname2=Form3->ListBox1->Items->Strings[j];
   Form3->ListBox2->Items->Strings[j]=Form3->ListBox2->Items->Strings[i];
   Form3->ListBox1->Items->Strings[j]=Form3->ListBox1->Items->Strings[i];
   Form3->ListBox2->Items->Strings[i]=tempname;
   Form3->ListBox1->Items->Strings[i]=tempname2;
   break;
   }
  }
 }
}
}
sortstat=3;
}
else
{
for (int j=0; j<Form3->ListBox2->Items->Count; j++)
{
for (int i=j; i<Form3->ListBox2->Items->Count; i++)
{
 if (i!=j)
 {
 AnsiString STR1=Form3->ListBox2->Items->Strings[j],STR2=Form3->ListBox2->Items->Strings[i];
 int maxlength;
 if (STR1.Length()<STR2.Length())
 maxlength=STR1.Length();
 else maxlength=STR2.Length();
 for (int k=1; k<maxlength; k++)
  {
  if (STR2[k]<STR1[k])
  break;
  if (STR1[k]<STR2[k])
  {
   AnsiString tempname,tempname2;
   tempname=Form3->ListBox2->Items->Strings[j];
   tempname2=Form3->ListBox1->Items->Strings[j];
   Form3->ListBox2->Items->Strings[j]=Form3->ListBox2->Items->Strings[i];
   Form3->ListBox1->Items->Strings[j]=Form3->ListBox1->Items->Strings[i];
   Form3->ListBox2->Items->Strings[i]=tempname;
   Form3->ListBox1->Items->Strings[i]=tempname2;
   break;
   }
  }
 }
}
}
sortstat=4;
}
}

void __fastcall SortBySong() // ���������� �� ������
{
int k=1,k1=1,ks,ks1;
if (sortstat!=5)
{
for (int j=0; j<Form3->ListBox2->Items->Count; j++)
{
for (int i=j; i<Form3->ListBox2->Items->Count; i++)
{
 int k=1,k1=1,ks=0,ks1=0;
 if (i!=j)
 {
 AnsiString STR1=Form3->ListBox2->Items->Strings[j],STR2=Form3->ListBox2->Items->Strings[i];
 for(;;)
 {
 if (STR1[k]==' ' && STR1[k+1]=='\-' && STR1[k+2]==' ')
 break;
 k++;
 }
 for(;;)
 {
if (STR2[k1]==' ' && STR2[k1+1]=='\-' && STR2[k1+2]==' ')
 break;
 k1++;
 }
 ks=k+2;ks1=k1+2;
 for (k=ks,k1=ks1; k<STR1.Length(),k1<STR2.Length(); k++,k1++)
  {
  if (STR1[k]<STR2[k1])
  break;
  if (STR2[k1]<STR1[k])
  {
   AnsiString tempname,tempname2;
   tempname=Form3->ListBox2->Items->Strings[j];
   tempname2=Form3->ListBox1->Items->Strings[j];
   Form3->ListBox2->Items->Strings[j]=Form3->ListBox2->Items->Strings[i];
   Form3->ListBox1->Items->Strings[j]=Form3->ListBox1->Items->Strings[i];
   Form3->ListBox2->Items->Strings[i]=tempname;
   Form3->ListBox1->Items->Strings[i]=tempname2;
   break;
   }
  if (k==STR1.Length() || k1==STR2.Length())
  break;
  }
 }
}
}
sortstat=5;
}
else
{
for (int j=0; j<Form3->ListBox2->Items->Count; j++)
{
for (int i=j; i<Form3->ListBox2->Items->Count; i++)
{
 int k=1,k1=1,ks=0,ks1=0;
 if (i!=j)
 {
 AnsiString STR1=Form3->ListBox2->Items->Strings[j],STR2=Form3->ListBox2->Items->Strings[i];
 for(;;)
 {
 if (STR1[k]==' ' && STR1[k+1]=='\-' && STR1[k+2]==' ')
 break;
 k++;
 }
 for(;;)
 {
if (STR2[k1]==' ' && STR2[k1+1]=='\-' && STR2[k1+2]==' ')
 break;
 k1++;
 }
 ks=k+2;ks1=k1+2;
 for (k=ks,k1=ks1; k<STR1.Length(),k1<STR2.Length(); k++,k1++)
  {
  if (STR1[k]>STR2[k1])
  break;
  if (STR2[k1]>STR1[k])
  {
   AnsiString tempname,tempname2;
   tempname=Form3->ListBox2->Items->Strings[j];
   tempname2=Form3->ListBox1->Items->Strings[j];
   Form3->ListBox2->Items->Strings[j]=Form3->ListBox2->Items->Strings[i];
   Form3->ListBox1->Items->Strings[j]=Form3->ListBox1->Items->Strings[i];
   Form3->ListBox2->Items->Strings[i]=tempname;
   Form3->ListBox1->Items->Strings[i]=tempname2;
   break;
   }
  if (k==STR1.Length() || k1==STR2.Length())
  break;
  }
 }
}
}
sortstat=6;
}
}

void __fastcall SortByFile() // ���������� �� ����� �����
{
if (sortstat!=1)
{
for (int j=0; j<Form3->ListBox2->Items->Count; j++)
{
for (int i=j; i<Form3->ListBox2->Items->Count; i++)
{
 if (i!=j)
 {
 AnsiString STR1=Form3->ListBox1->Items->Strings[j],STR2=Form3->ListBox1->Items->Strings[i];
 int maxlength;
 if (STR1.Length()<STR2.Length())
 maxlength=STR1.Length();
 else maxlength=STR2.Length();
 for (int k=1; k<maxlength; k++)
  {
  if (STR1[k]<STR2[k])
  break;
  if (STR2[k]<STR1[k])
  {
   AnsiString tempname,tempname2;
   tempname=Form3->ListBox2->Items->Strings[j];
   tempname2=Form3->ListBox1->Items->Strings[j];
   Form3->ListBox2->Items->Strings[j]=Form3->ListBox2->Items->Strings[i];
   Form3->ListBox1->Items->Strings[j]=Form3->ListBox1->Items->Strings[i];
   Form3->ListBox2->Items->Strings[i]=tempname;
   Form3->ListBox1->Items->Strings[i]=tempname2;
   break;
   }
  }
 }
}
}
sortstat=1;
}
else
{
for (int j=0; j<Form3->ListBox2->Items->Count; j++)
{
for (int i=j; i<Form3->ListBox2->Items->Count; i++)
{
 if (i!=j)
 {
 AnsiString STR1=Form3->ListBox1->Items->Strings[j],STR2=Form3->ListBox1->Items->Strings[i];
 int maxlength;
 if (STR1.Length()<STR2.Length())
 maxlength=STR1.Length();
 else maxlength=STR2.Length();
 for (int k=1; k<maxlength; k++)
  {
  if (STR1[k]>STR2[k])
  break;
  if (STR2[k]>STR1[k])
  {
   AnsiString tempname,tempname2;
   tempname=Form3->ListBox2->Items->Strings[j];
   tempname2=Form3->ListBox1->Items->Strings[j];
   Form3->ListBox2->Items->Strings[j]=Form3->ListBox2->Items->Strings[i];
   Form3->ListBox1->Items->Strings[j]=Form3->ListBox1->Items->Strings[i];
   Form3->ListBox2->Items->Strings[i]=tempname;
   Form3->ListBox1->Items->Strings[i]=tempname2;
   break;
   }
  }
 }
}
}
sortstat=2;
}
}

void __fastcall DelDupe() // �������� ����������
{
for (int j=0; j<Form3->ListBox2->Items->Count; j++)
{
for (int i=0; i<Form3->ListBox2->Items->Count; i++)
{
 if (i!=j)
 {
 AnsiString STR1=Form3->ListBox1->Items->Strings[j],STR2=Form3->ListBox1->Items->Strings[i];
  if (STR1==STR2)
  {
AnsiString TR=Form3->MediaPlayer1->FileName;
Form3->MediaPlayer1->Stop();
Form3->MediaPlayer1->Close();
Form3->MediaPlayer2->FileName=Form3->ListBox1->Items->Strings[i];
Form3->MediaPlayer2->Open();
Form3->timetoplay-=Form3->MediaPlayer2->Length;
Form3->MediaPlayer2->Stop();
Form3->MediaPlayer2->Close();
Form3->MediaPlayer2->FileName=NULL;
Form3->MediaPlayer1->FileName=TR;
Form3->MediaPlayer1->Open();
Form3->MediaPlayer1->Position=Form3->TrackBar2->Position;
Form3->MediaPlayer1->Play();
Form3->ListBox1->Items->Delete(i);
Form3->ListBox2->Items->Delete(i);
   break;
  }
  }
 }
}
} 

void __fastcall MiscList() // ���������� ����
{
DelDupe();
AnsiString *misc;
AnsiString *misc2;
misc = new AnsiString[Form3->ListBox2->Items->Count];
misc2 = new AnsiString[Form3->ListBox2->Items->Count];
for (int i=0;i<Form3->ListBox2->Items->Count;i++)
{
misc[i]=0;
misc2[i]=0;
}
bool error=true;
int j;
for (int k=0; k<Form3->ListBox2->Items->Count;k++)
{
error=true;
randomize();
while (error)
{
j=random(Form3->ListBox2->Items->Count);
error=false;
for (int i=0;i<Form3->ListBox2->Items->Count;i++)
{ if (Form3->ListBox2->Items->Strings[j]==misc[i]) error=true; }
if (!error)
{
misc[k]=Form3->ListBox2->Items->Strings[j];
misc2[k]=Form3->ListBox1->Items->Strings[j];
}
}
}
for (int i=0;i<Form3->ListBox2->Items->Count;i++)
{
Form3->ListBox2->Items->Strings[i]=misc[i];
Form3->ListBox1->Items->Strings[i]=misc2[i];
}
}

//---------------------------------------------------------------------------


void __fastcall TForm3::MenuItem7Click(TObject *Sender)
{
if (!cashstat)
SortByFile();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MenuItem8Click(TObject *Sender)
{
if (!cashstat)
SortByGroup();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N4Click(TObject *Sender)
{
if (!cashstat)
SortBySong();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::N5Click(TObject *Sender)
{
if (!cashstat)
MiscList();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N6Click(TObject *Sender)
{
if (!cashstat)
DelDupe();
}
//---------------------------------------------------------------------------

void __fastcall initLang()
{
if (Form6->ComboBox3->ItemIndex==0) // �������
{
Form6->Button1->Caption="������� ����";
Form6->Button2->Caption="������� �����";
Form6->Button3->Caption="���������";
Form6->Button4->Caption="����������";
Form6->Button5->Caption="����������";
Form6->Button6->Caption="����������";
Form6->Button7->Caption="������� ����������� ��� ������";
Form6->Button8->Caption="�������� ���������";
Form6->Button9->Caption="��������� ��� ����";
Form6->Button10->Caption="��������� ����";
Form6->Button11->Caption="�����";
Form6->Button12->Caption="���������� �����";
Form6->Label1->Caption="�����-����������";
Form6->LabeledEdit1->EditLabel->Caption="�������� ��� ����� ��������, ��";
Form6->LabeledEdit2->EditLabel->Caption="������� ��������";
Form6->LabeledEdit3->EditLabel->Caption="������ �� ���������";
Form6->LabeledEdit4->EditLabel->Caption="������ ���������";
Form6->LabeledEdit5->EditLabel->Caption="������ ���������";
Form6->LabeledEdit6->EditLabel->Caption="������ ��������";
Form6->LabeledEdit7->EditLabel->Caption="������ ��������";
Form6->CheckBox2->Caption="������� ���";
Form6->CheckBox1->Caption="�� ID3V1.1\\Filename";
Form6->CheckBox3->Caption="����� ������������";
Form6->ComboBox1->Items->Strings[0]="���������� �������";
Form6->ComboBox1->Items->Strings[1]="��������";
Form6->ComboBox1->Items->Strings[2]="������� ����";
Form6->ComboBox1->Items->Strings[3]="������ �������";
Form6->ComboBox2->Items->Strings[0]="�����";
Form6->ComboBox2->Items->Strings[1]="������";
Form6->ComboBox2->Items->Strings[2]="������";
Form6->ComboBox2->Items->Strings[3]="�����";
Form6->ComboBox2->Items->Strings[4]="��������";
Form6->ComboBox2->Items->Strings[5]="�������";
Form6->ComboBox2->Items->Strings[6]="��������� ��������";
Form6->ComboBox2->Items->Strings[7]="���������";
Form6->ComboBox2->Items->Strings[8]="������� ��������";
Form6->ComboBox2->Items->Strings[9]="�������� ��������";
Form6->ComboBox2->Items->Strings[10]="������� ��������";
Form6->ComboBox2->Items->Strings[11]="����������\\��������� ��������";
Form6->ComboBox2->Items->Strings[12]="�����������";
Form3->Image2->Hint="���������� �����";
Form3->Image8->Hint="�����";
Form3->Image9->Hint="������";
Form3->Image10->Hint="��������� �����";
Form3->Image4->Hint="�������� \\ ��. ���� - �����";
Form3->Image5->Hint="������� \\ ��. ���� - �����";
Form3->Image6->Hint="��������� �������� \\ ��. ���� - �����";
Form3->Image15->Hint="����������� \\ ��. ���� - �����";
Form3->Image7->Hint="���������";
Form3->Image11->Hint="�������\\������� �������� ��������";
Form3->Image12->Hint="�������� �������� \\ ��. ���� - �����";
Form3->Image13->Hint="������� �������� \\ ��. ���� - �����";
Form3->Image14->Hint="����������\\��������� ��������";
Form4->Panel1->Caption="��������";
Form4->Panel2->Caption="������";
Form5->Panel1->Caption="��������";
Form5->Panel2->Caption="������";
Form4->CheckBox1->Caption="��������� � ������������";
Form3->N1->Caption="������� ����������";
Form3->N2->Caption="������� ��";
Form3->N6->Caption="������� ���������";
Form3->MenuItem1->Caption="�������� ����";
Form3->MenuItem2->Caption="�������� �������";
Form3->MenuItem3->Caption="�������� ����";
Form3->MenuItem4->Caption="�������� �������";
Form3->MenuItem5->Caption="��������� �� ���������";
Form3->MenuItem6->Caption="��������� ���";
Form3->N3->Caption="���������";
Form3->HTML1->Caption="��������� HTML";
Form3->MenuItem7->Caption="�� ����� �����";
Form3->MenuItem8->Caption="�� ��������";
Form3->N4->Caption="�� �����";
Form3->N5->Caption="����������";
Form3->MenuItem9->Caption="�������";
Form3->MenuItem10->Caption="������� ��";
Form6->Button13->Caption="� ���������";
Form6->CheckBox4->Caption="����� ����������";
Form6->Button14->Caption="����������";
}
if (Form6->ComboBox3->ItemIndex==1)
{
Form6->Button1->Caption="Choose the colour";
Form6->Button2->Caption="Choose the font";
Form6->Button3->Caption="Save";
Form6->Button4->Caption="Set";
Form6->Button5->Caption="Set";
Form6->Button6->Caption="Set";
Form6->Button7->Caption="Choose the image for the button";
Form6->Button8->Caption="Cancell the changes";
Form6->Button9->Caption="Save as a skin";
Form6->Button10->Caption="Load the skin";
Form6->Button11->Caption="Exit";
Form6->Button12->Caption="Set the skin";
Form6->Label1->Caption="Alfa-component";
Form6->LabeledEdit1->EditLabel->Caption="Interval for the picture change, ms";
Form6->LabeledEdit2->EditLabel->Caption="Background picture";
Form6->LabeledEdit3->EditLabel->Caption="Default skin";
Form6->LabeledEdit4->EditLabel->Caption="Playlist width";
Form6->LabeledEdit5->EditLabel->Caption="Playlist height";
Form6->LabeledEdit6->EditLabel->Caption="Picture width";
Form6->LabeledEdit7->EditLabel->Caption="Picture height";
Form6->CheckBox2->Caption="Multiply the background";
Form6->CheckBox1->Caption="by ID3V1.1\\Filename";
Form6->CheckBox3->Caption="Smart randomisation";
Form6->ComboBox1->Items->Strings[0]="Time indicator";
Form6->ComboBox1->Items->Strings[1]="Playlist";
Form6->ComboBox1->Items->Strings[2]="Main window";
Form6->ComboBox1->Items->Strings[3]="Status line";
Form6->ComboBox2->Items->Strings[0]="Back";
Form6->ComboBox2->Items->Strings[1]="Forward";
Form6->ComboBox2->Items->Strings[2]="Play";
Form6->ComboBox2->Items->Strings[3]="Pause";
Form6->ComboBox2->Items->Strings[4]="Add";
Form6->ComboBox2->Items->Strings[5]="Delete";
Form6->ComboBox2->Items->Strings[6]="Save playlist";
Form6->ComboBox2->Items->Strings[7]="Options";
Form6->ComboBox2->Items->Strings[8]="Show Picture";
Form6->ComboBox2->Items->Strings[9]="Add a picture";
Form6->ComboBox2->Items->Strings[10]="Delete a picture";
Form6->ComboBox2->Items->Strings[11]="Stop\\launch the slideshow";
Form6->ComboBox2->Items->Strings[12]="Sort";
Form3->Image2->Hint="Previous song";
Form3->Image8->Hint="Pause";
Form3->Image9->Hint="Play";
Form3->Image10->Hint="Next song";
Form3->Image4->Hint="Add \\ right click - options";
Form3->Image5->Hint="Delete \\ right click - options";
Form3->Image6->Hint="Save playlist \\ right click - options";
Form3->Image15->Hint="Sort \\ right click - options";
Form3->Image7->Hint="Options";
Form3->Image11->Hint="Open\\Close picture viewing";
Form3->Image12->Hint="Add a picture \\ right click - options";
Form3->Image13->Hint="Delete a picture \\ right click - options";
Form3->Image14->Hint="Stop\\launch the slideshow";
Form4->Panel1->Caption="Add";
Form4->Panel2->Caption="Cancell";
Form5->Panel1->Caption="Add";
Form5->Panel2->Caption="Cancell";
Form4->CheckBox1->Caption="Add in the subcatalogues";
Form3->N1->Caption="Delete the marked";
Form3->N2->Caption="Delete all";
Form3->N6->Caption="Delete the dublicates";
Form3->MenuItem1->Caption="Add a file";
Form3->MenuItem2->Caption="Add a catalogue";
Form3->MenuItem3->Caption="Add a file";
Form3->MenuItem4->Caption="Add a catalogue";
Form3->MenuItem5->Caption="Save as default";
Form3->MenuItem6->Caption="Save as";
Form3->N3->Caption="Load";
Form3->HTML1->Caption="Save HTML";
Form3->MenuItem7->Caption="By the filename";
Form3->MenuItem8->Caption="By the alphabet";
Form3->N4->Caption="By the song";
Form3->N5->Caption="Shuffle";
Form3->MenuItem9->Caption="Delete";
Form3->MenuItem10->Caption="Delete all";
Form6->Button13->Caption="About Programm";
Form6->CheckBox4->Caption="Statistic on\off";
Form6->Button14->Caption="Statistic";
}
if (Form6->ComboBox3->ItemIndex==2)
{
Form6->Button1->Caption="Wahle Farbe";
Form6->Button2->Caption="Wahle Schrift";
Form6->Button3->Caption="Erhalten";
Form6->Button4->Caption="Wahl";
Form6->Button5->Caption="Wahl";
Form6->Button6->Caption="Wahl";
Form6->Button7->Caption="Erhalten the image fur the button";
Form6->Button8->Caption="Abschaffung";
Form6->Button9->Caption="Erhalten Fell";
Form6->Button10->Caption="Wahl Fell";
Form6->Button11->Caption="Exit";
Form6->Button12->Caption="Wahl als Fell";
Form6->Label1->Caption="Alfa-component";
Form6->LabeledEdit1->EditLabel->Caption="Intervale fur Abbildung, ms";
Form6->LabeledEdit2->EditLabel->Caption="Hinterground Abbildung";
Form6->LabeledEdit3->EditLabel->Caption="Default Fell";
Form6->LabeledEdit4->EditLabel->Caption="Abhorenlist Breite";
Form6->LabeledEdit5->EditLabel->Caption="Abhorenlist Hohe";
Form6->LabeledEdit6->EditLabel->Caption="Abbildung Breite";
Form6->LabeledEdit7->EditLabel->Caption="Abbildung Hohe";
Form6->CheckBox2->Caption="Vervielfultigen Hintergrund";
Form6->CheckBox1->Caption="Nach ID3V1.1\\Filename";
Form6->CheckBox3->Caption="Kluge Zufall";
Form6->ComboBox1->Items->Strings[0]="Zeiteindikator";
Form6->ComboBox1->Items->Strings[1]="Abhorenlist";
Form6->ComboBox1->Items->Strings[2]="Wichtigste Fenster";
Form6->ComboBox1->Items->Strings[3]="Zeilezustand";
Form6->ComboBox2->Items->Strings[0]="Zuruck";
Form6->ComboBox2->Items->Strings[1]="Voran";
Form6->ComboBox2->Items->Strings[2]="Spiele";
Form6->ComboBox2->Items->Strings[3]="Pause";
Form6->ComboBox2->Items->Strings[4]="Hinzufugen";
Form6->ComboBox2->Items->Strings[5]="Fortschaffen";
Form6->ComboBox2->Items->Strings[6]="Erhalten Abhorenlist";
Form6->ComboBox2->Items->Strings[7]="Stimmen";
Form6->ComboBox2->Items->Strings[9]="Hinzufugen Abbildung";
Form6->ComboBox2->Items->Strings[8]="Hinzusetzen Abbildung";
Form6->ComboBox2->Items->Strings[10]="Entfernen Abbildung";
Form6->ComboBox2->Items->Strings[11]="Anhalten\\Starten Slideshow";
Form6->ComboBox2->Items->Strings[12]="Sortieren";
Form3->Image2->Hint="Zuruck";
Form3->Image8->Hint="Pause";
Form3->Image9->Hint="Spiele";
Form3->Image10->Hint="Voraus";
Form3->Image4->Hint="Hinzusetzen";
Form3->Image5->Hint="Entfernen";
Form3->Image6->Hint="Erhalten";
Form3->Image15->Hint="Sortieren";
Form3->Image7->Hint="Stimmen";
Form3->Image11->Hint="Abbildung offenen\\ zumachen";
Form3->Image12->Hint="Hinzusetzen Abbildung";
Form3->Image13->Hint="Entfernen Abbildung";
Form3->Image14->Hint="Stop\\Starten Slideshow";
Form4->Panel1->Caption="Hinzusetzen";
Form4->Panel2->Caption="Aufhebung";
Form5->Panel1->Caption="Hinzusetzen";
Form5->Panel2->Caption="Aufhebung";
Form4->CheckBox1->Caption="Hinzusetzen im Subcataloge";
Form3->N1->Caption="Entfernen";
Form3->N2->Caption="Entfernen Alles";
Form3->N6->Caption="Entfernen Duplicaten";
Form3->MenuItem1->Caption="Hinzusetzen File";
Form3->MenuItem2->Caption="Hinzusetzen Cataloge";
Form3->MenuItem3->Caption="Hinzusetzen File";
Form3->MenuItem4->Caption="Hinzusetzen Cataloge";
Form3->MenuItem5->Caption="Erhalten Verschweigen";
Form3->MenuItem6->Caption="Erhalten als";
Form3->N3->Caption="Beladen";
Form3->HTML1->Caption="Erhalten HTML";
Form3->MenuItem7->Caption="Als File";
Form3->MenuItem8->Caption="Als ABC";
Form3->N4->Caption="Als Singe";
Form3->N5->Caption="Verwirren";
Form3->MenuItem9->Caption="Entfernen";
Form3->MenuItem10->Caption="Entfernen Alles";
Form6->Button13->Caption="Uber Programme";
Form6->CheckBox4->Caption="Statistik";
Form6->Button14->Caption="Statistik";
}
}

void __fastcall TForm3::MenuItem10Click(TObject *Sender)
{
ListBox3->Items->Clear();
reloadstat2=0;
ListBox3->Items->SaveToFile(InitDirectory+"\\db\\pic.db");
TrackBar1->Position=0;
TrackBar1->Enabled=false;
TrackBar1->Max=ListBox3->Items->Count;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MenuItem9Click(TObject *Sender)
{
ListBox3->Items->Delete(TrackBar1->Position-1);
ListBox3->Items->SaveToFile(InitDirectory+"\\db\\pic.db");
TrackBar1->Max=getlenght((InitDirectory+"\\db\\pic.db").c_str());
if (ListBox3->Items->Count)
TrackBar1->Enabled=true;
else
TrackBar1->Enabled=false;
}

void __fastcall nullRemoval()
{
for (int i=0;i<Form3->ListBox2->Items->Count;i++)
 {
 AnsiString TSTR=Form3->ListBox2->Items->Strings[i];
 int errs=0;
 for (int j=1;j<TSTR.Length();j++)
 {
    if (j+1!=TSTR.Length())
    {
    if (TSTR[j]==' ' && TSTR[j+1]==' ')
    {
    errs++;
    int h=j;
    for (h=j;h<TSTR.Length();h++)
    {
    if(h+1!=TSTR.Length())
    TSTR[h]=TSTR[h+1];
    }
    j--;
    }
  }
 }
 if (errs!=0)
 TSTR[TSTR.Length()-errs]='\0';
 else    TSTR[TSTR.Length()-errs]='\0';
 Form3->ListBox2->Items->Strings[i]=TSTR;
 }
}

//---------------------------------------------------------------------------


void __fastcall TForm3::Timer4Timer(TObject *Sender) // cashstat timer
{
if (itemscount<ListBox1->Items->Count)
{
MediaPlayer2->FileName=ListBox1->Items->Strings[itemscount];
if (MediaPlayer2->FileName!=MediaPlayer1->FileName)
{
MediaPlayer2->Open();
timetoplay+=MediaPlayer2->Length; //
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(Form3->MediaPlayer2->Length))/1000)/60)-(StrToInt(Form3->MediaPlayer2->Length)/1000)/60)*60);
AnsiString TIME0;
if (retvalue>9)
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer2->Length)/1000)/60)+":"+FloatToStr(retvalue);
else
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer2->Length)/1000)/60)+":0"+FloatToStr(retvalue);
Form3->ListBox2->Items->Strings[itemscount]=Form3->ListBox2->Items->Strings[itemscount]+" \("+TIME0+"\) ";
MediaPlayer2->Close();
//nullRemoval();
 AnsiString TSTR=ListBox2->Items->Strings[itemscount];
 int errs=0;
 for (int j=1;j<TSTR.Length();j++)
 {
    if (j+1<TSTR.Length())
    {
    if (TSTR[j]==' ' && TSTR[j+1]==' ')
    {
    errs++;
    int h=j;
    for (h=j;h<TSTR.Length();h++)
    {
    if(h+1<TSTR.Length())
    TSTR[h]=TSTR[h+1];
    }
    j--;
    }
  } //
 }        // for j
 if (errs!=0)
 TSTR[TSTR.Length()-errs]='\0';
 else    TSTR[TSTR.Length()-errs]='\0';
 ListBox2->Items->Strings[itemscount]=TSTR;
//
itemscount++;
}
else
{
timetoplay+=MediaPlayer1->Length;
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(Form3->MediaPlayer1->Length))/1000)/60)-(StrToInt(Form3->MediaPlayer1->Length)/1000)/60)*60);
AnsiString TIME0;
if (retvalue>9)
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue);
else
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue);
Form3->ListBox2->Items->Strings[itemscount]=Form3->ListBox2->Items->Strings[itemscount]+" \("+TIME0+"\) ";
//nullRemoval();
 AnsiString TSTR=ListBox2->Items->Strings[itemscount];
 int errs=0;
 for (int j=1;j<TSTR.Length();j++)
 {
    if (j<TSTR.Length())
    {
    if (TSTR[j]==' ' && TSTR[j+1]==' ')
    {
    errs++;
    int h=j;
    for (h=j;h<TSTR.Length();h++)
    {
    if(h+1<TSTR.Length())
    TSTR[h]=TSTR[h+1];
    }
    j--;
    }
  }
 }        // for j
 if (errs!=0)
 TSTR[TSTR.Length()-errs]='\0';
 else    TSTR[TSTR.Length()-errs]='\0';
 ListBox2->Items->Strings[itemscount]=TSTR;
//
itemscount++;
}
}
else { itemscount=0; Timer4->Enabled=false; /* nullRemoval(); */ cashstat=false; }
}
//---------------------------------------------------------------------------








void __fastcall TForm3::Button1Click(TObject *Sender)
{
//LOGO->ShowModal(); //
FILE *F;
if (!FileExists(InitDirectory+"\\jim2.ini"))
F=fopen((InitDirectory+"\\jim2.ini").c_str(),"w+");
TIniFile *Ini;
Ini = new TIniFile(InitDirectory+"\\jim2.ini");
Ini->WriteString("Test","main",ParamStr(0));
Ini->WriteString("���������","�����",Font->Name);

}
//---------------------------------------------------------------------------

void __fastcall TForm3::WMHotKey(TWMHotKey& a)
{
SystemParametersInfo(SPI_SETDESKWALLPAPER,0,CurrentWallpaper.c_str(),SPIF_UPDATEINIFILE);
if (a.HotKey==1)
        {
        if (!CheckBox1->Checked)
        {
        if (ListBox2->Items->Count>0)
        {
        if (musstat!=0)
        {
        musstat--;
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        ListBox2->ItemIndex=musstat;
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue;
        retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        else
        {
        musstat=ListBox2->Items->Count-1;
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        ListBox2->ItemIndex=musstat;
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        }
        }
        else
        {
        if (!Form6->CheckBox3->Checked)
        {
        int numelem;
        if (ListBox1->Items->Count!=0)
        numelem=ListBox1->Items->Count-1;
        musstat=random(numelem);
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        ListBox2->ItemIndex=musstat;
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        else //���� ����������������
        {
        if (ListBox1->Items->Count!=0)
        {
        if (randstat>0)
        randstat--;
        else randstat=randommus[ListBox2->Items->Count*10-1];
        musstat=randommus[randstat];
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        ListBox2->ItemIndex=musstat;
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        else { randstat=0; musstat=0; MediaPlayer1->Stop(); }
        }
        }
        }
else if (a.HotKey==2)
        {
        if (!CheckBox1->Checked)
        {
        if (ListBox2->Items->Count>0)
        {
        try
        {
        if (musstat+1<ListBox2->Items->Count)
        musstat++;
        else {musstat=0;}
        try
        {
        try
        {
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        scrolledit=0;
        }
        catch ( EStringListError& ) {
        musstat=0;
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        ListBox2->ItemIndex=musstat;
        }
        catch ( EStringListError& ) {
        musstat=0;
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        catch ( EMCIDeviceError& ) {
        musstat++;
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        if (!CheckBox2->Checked && musstat==0)
        MediaPlayer1->Stop();
        }
        }
        else
        {
        if (!Form6->CheckBox3->Checked)
        {
        int numelem;
        if (ListBox1->Items->Count!=0)
        numelem=ListBox1->Items->Count-1;
        musstat=random(numelem);
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        ListBox2->ItemIndex=musstat;
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        else //���� ����������������
        {
        if (ListBox1->Items->Count!=0)
        {
        if (randstat<ListBox2->Items->Count*10)
        randstat++;
        else randstat=0;
        musstat=randommus[randstat];
        scrolledit=0;
        MediaPlayer1->FileName=ListBox1->Items->Strings[musstat];
        ListBox2->ItemIndex=musstat;
        MediaPlayer1->Open();
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        else { randstat=0; musstat=0; MediaPlayer1->Stop(); }
        }
        }
        }
else if (a.HotKey==3)
{
        if (MediaPlayer1->Mode==2 || MediaPlayer1->Mode == 1)
        {
        Timer3->Enabled=!(Timer3->Enabled);
        TrackBar2->Enabled=!(TrackBar2->Enabled);
        MediaPlayer1->Position=TrackBar2->Position;
        if (!TrackBar2->Enabled)
        {
        MediaPlayer1->Play();
//        //if (Form6->CheckBox4->Checked) GetStatPrepare();
        int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
        }
        else
        {
        MediaPlayer1->Pause();
        TrayIcon1->Hint="����";
        }
        }
        }
else if (a.HotKey==4)
{
        CheckBox1->Checked=!(CheckBox1->Checked);
}
else if (a.HotKey==5)
{
        CheckBox2->Checked=!(CheckBox2->Checked);
}
else if (a.HotKey==6)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\1.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==7)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\2.jpl");

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==8)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\3.jpl");

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==9)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\4.jpl");

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==10)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\5.jpl");

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==11)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\6.jpl");

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==12)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\7.jpl");

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==13)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\8.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==14)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\9.jpl");

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==15)
{
// �������� ���������
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
MediaPlayer1->Close();
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
timetoplay=0;
ListBox1->Items->LoadFromFile(InitDirectory+"\\db\\0.jpl");

for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(ListBox1->Items->Strings[i].c_str(),1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
musstat=0;
ListBox2->ItemIndex=musstat;
MediaPlayer1->FileName=ListBox1->Items->Strings[0];
MediaPlayer1->Open();
MediaPlayer1->Play();
////if (Form6->CheckBox4->Checked) GetStatPrepare();
int retvalue=Floor(((((StrToFloat(MediaPlayer1->Length))/1000)/60)-(StrToInt(MediaPlayer1->Length)/1000)/60)*60); if (retvalue>9) Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue); else Edit2->Text=FloatToStr((StrToInt(MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue); E4T="   ***  "+AnsiString(ListBox2->Items->Strings[musstat]) +"   ***  ";
Timer1->Enabled=true;
Timer2->Enabled=true;
Timer3->Enabled=true;
delete randommus;
randommus = new int[ListBox2->Items->Count*10];
randomize();
for (int i=0; i<ListBox2->Items->Count*10; i++)
randommus[i]=random(ListBox2->Items->Count);
}
else if (a.HotKey==16)
{
Form6->CheckBox4->Enabled=!(Form6->CheckBox4->Enabled);
}
else if (a.HotKey==17)
{
Timer2->Enabled=!(Timer2->Enabled);
}
else if (a.HotKey==18)
{
Form6->CheckBox6->Enabled=!(Form6->CheckBox4->Enabled);
}
else if (a.HotKey==19)
{
Form6->CheckBox5->Enabled=!(Form6->CheckBox4->Enabled);
}
}
//---------------------------------------------------------------------------















//---------------------------------------------------------------------------

void __fastcall TForm3::N7Click(TObject *Sender)
{
Form9->ShowModal();
}
//---------------------------------------------------------------------------




void __fastcall TForm3::FormDestroy(TObject *Sender)
{
SystemParametersInfo(SPI_SETDESKWALLPAPER,0,CurrentWallpaper.c_str(),SPIF_UPDATEINIFILE);
DragAcceptFiles(Handle,false);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::WMDROPFILES(TMessage &Msg)
{
char Filename[2048];
int Count, i, added=0, LB1C;
if (ListBox1->Items->Count!=0)
LB1C=ListBox1->Items->Count-1;
else LB1C=0;
Count = DragQueryFile((void*) Msg.WParam,0xFFFFFFFF,Filename,sizeof(Filename));
for (i=0;i<Count;i++)
{
DragQueryFile((void*) Msg.WParam,i,Filename,sizeof(Filename));
if (ExtractFileExt(Filename)=="\.mp3")
{
added++;
 ListBox1->Items->Add(Filename);
}
}
DragFinish((void*) Msg.WParam);
if (added>0)
{
Form3->timetoplay=0;
AnsiString TR;
  Form3->ListBox2->SelectAll();
  Form3->ListBox2->DeleteSelected();
  AnsiString TTagMP3;
  int cursong=-1;
  for (int i=0; i<Form3->ListBox1->Items->Count;i++)
  {
  if (!Form6->CheckBox1->Checked)
  Form3->ListBox2->Items->Add(AnsiString(crofilename(Form3->ListBox1->Items->Strings[i])));
  else
  {
   if (Form3->ListBox1->Items->Strings[i]!=Form3->MediaPlayer1->FileName)
   {
   TTagMP3=GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[i].c_str(),0);
   AnsiString TT1,TT2,TT3;
   int error=0;
   try { TT1=TTagMP3[1]; } catch (...) {error++;}
   try { TT2=TTagMP3[2]; } catch (...) {error++;}
   try { TT3=TTagMP3[3]; } catch (...) {error++;}
   if (!error)
   {
   if ((TT1=="T") && (TT2=="A") && (TT3=="G"))
   Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[i].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[i].c_str(),1)));
   else Form3->ListBox2->Items->Add(AnsiString(crofilename(Form3->ListBox1->Items->Strings[i])));
   }
   else Form3->ListBox2->Items->Add(AnsiString(crofilename(Form3->ListBox1->Items->Strings[i])));
   }
   else
   {
   cursong=i;
   Form3->ListBox2->Items->Add(AnsiString(crofilename(Form3->ListBox1->Items->Strings[i])));
   }
  }
   }
     if (cursong>=0)
  {
  if (!Form6->CheckBox1->Checked)
  Form3->ListBox2->Items->Add(AnsiString(crofilename(Form3->ListBox1->Items->Strings[cursong])));
  else
   {
   Form3->MediaPlayer1->Stop();
   Form3->MediaPlayer1->Close();
   TTagMP3=GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[cursong].c_str(),0);
   AnsiString TT1,TT2,TT3;
   int error=0;
   try { TT1=TTagMP3[1]; } catch (...) {error++;}
   try { TT2=TTagMP3[2]; } catch (...) {error++;}
   try { TT3=TTagMP3[3]; } catch (...) {error++;}
   if (!error)
   {
   if ((TT1=="T") && (TT2=="A") && (TT3=="G"))
   Form3->ListBox2->Items->Strings[cursong]=(AnsiString(GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[cursong].c_str(),2))+" - "+AnsiString(GetMp3Tag_DLL(Form3->ListBox1->Items->Strings[cursong].c_str(),1)));
   else Form3->ListBox2->Items->Strings[cursong]=(AnsiString(crofilename(Form3->ListBox1->Items->Strings[cursong])));
   }
   else Form3->ListBox2->Items->Strings[cursong]=(AnsiString(crofilename(Form3->ListBox1->Items->Strings[cursong])));
   }
   Form3->MediaPlayer1->Open();
   Form3->MediaPlayer1->Position=Form3->TrackBar2->Position;
   Form3->MediaPlayer1->Play();
   }
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;
}
}
void __fastcall TForm3::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
ReleaseCapture();
((TControl *) Sender)->Perform(WM_SYSCOMMAND,0xF012,0);        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormResize(TObject *Sender)
{
CLOSE_BUTTON->Left=Form3->Width-10;
CLOSE_BUTTON->Top=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::CLOSE_BUTTONClick(TObject *Sender)
{
Form3->Close();
Application->Terminate();
}








void __fastcall TForm3::FormCreate(TObject *Sender)
{
DragAcceptFiles(Handle,true);        
}
//---------------------------------------------------------------------------


