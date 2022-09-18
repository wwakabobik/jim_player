//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit5.h"
#include "Unit3.h"
#include "Unit6.h"
#include "library.h"
#include <Math.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


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


TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------



void __fastcall TForm4::Panel2Click(TObject *Sender)
{
DirectoryListBox1->Directory=Label1->Caption;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form4->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Panel1Click(TObject *Sender)
{
try
{
Label2->Caption=DirectoryListBox1->Directory;
if (!CheckBox1->Checked)
{
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
}
else {
Form4->Visible=false;
int numsubs,curnum=0,numsubs2=0,curnum2=0,curnum3=0,curnum4=0,curnum5=0,curnum6=0,curnum7,curnum8,curnum9,numsubs3=0,numsubs4,numsubs5,numsubs6,numsubs7,numsubs8,numsubs9;
AnsiString topdir=DirectoryListBox1->Directory, topdir2, topdir3, topdir4, topdir5, topdir6, topdir7, topdir8, topdir9;
numsubs=DirectoryListBox1->Items->Count;
curnum=DirectoryListBox1->ItemIndex+1;
for (int i=0; i<FileListBox1->Items->Count; i++)
{
FileListBox1->ItemIndex=i;
Form3->ListBox1->Items->Add(FileListBox1->FileName);
}
while (curnum!=numsubs)
{
DirectoryListBox1->ItemIndex=curnum;
DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
if (curnum==numsubs)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 numsubs2=DirectoryListBox1->Items->Count;
 curnum2=DirectoryListBox1->ItemIndex+1;
 topdir2=DirectoryListBox1->Directory;
 while (curnum2!=numsubs2)
  {
  DirectoryListBox1->ItemIndex=curnum2;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
if (curnum2==numsubs2)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 curnum2++;
 DirectoryListBox1->Directory=topdir;
}
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 numsubs3=DirectoryListBox1->Items->Count;
 curnum3=DirectoryListBox1->ItemIndex+1;
 topdir3=DirectoryListBox1->Directory;
 while (curnum3!=numsubs3)
  {
  DirectoryListBox1->ItemIndex=curnum3;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  if (curnum3==numsubs3)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 curnum3++;
 DirectoryListBox1->Directory=topdir;
}
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 numsubs4=DirectoryListBox1->Items->Count;
 curnum4=DirectoryListBox1->ItemIndex+1;
 topdir4=DirectoryListBox1->Directory;
 while (curnum4!=numsubs4)
  {
  DirectoryListBox1->ItemIndex=curnum4;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
    if (curnum4==numsubs4)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 curnum4++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 numsubs5=DirectoryListBox1->Items->Count;
 curnum5=DirectoryListBox1->ItemIndex+1;
 topdir5=DirectoryListBox1->Directory;
// ShowMessage("Есть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum5!=numsubs5)
  {
  DirectoryListBox1->ItemIndex=curnum5;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
    if (curnum5==numsubs5)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
}
 curnum5++;
 DirectoryListBox1->Directory=topdir;
}
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 numsubs6=DirectoryListBox1->Items->Count;
 curnum6=DirectoryListBox1->ItemIndex+1;
 topdir6=DirectoryListBox1->Directory;
 while (curnum6!=numsubs6)
  {
  DirectoryListBox1->ItemIndex=curnum6;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
      if (curnum6==numsubs6)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 curnum6++;
 DirectoryListBox1->Directory=topdir;
}
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 if (!Form6->CheckBox1->Checked)
  Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
  else
  {
    AnsiString TTagMP3;  try  {  TTagMP3=GetMp3Tag(FileListBox1->FileName,0);  }  catch (...) {}
  if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
  Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
  else Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
}
 }
 numsubs7=DirectoryListBox1->Items->Count;
 curnum7=DirectoryListBox1->ItemIndex+1;
 topdir7=DirectoryListBox1->Directory;
 while (curnum7!=numsubs7)
  {
  DirectoryListBox1->ItemIndex=curnum7;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
        if (curnum7==numsubs7)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 if (!Form6->CheckBox1->Checked)
  Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
  else
  {
    AnsiString TTagMP3;  try  {  TTagMP3=GetMp3Tag(FileListBox1->FileName,0);  }  catch (...) {}
  if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
  Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
  else Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
}
 }
 curnum7++;
 DirectoryListBox1->Directory=topdir;
}
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 numsubs8=DirectoryListBox1->Items->Count;
 curnum8=DirectoryListBox1->ItemIndex+1;
 topdir8=DirectoryListBox1->Directory;
 while (curnum8!=numsubs8)
  {
  DirectoryListBox1->ItemIndex=curnum8;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
        if (curnum8==numsubs8)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 curnum8++;
 DirectoryListBox1->Directory=topdir;
}
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 }
 numsubs9=DirectoryListBox1->Items->Count;
 curnum9=DirectoryListBox1->ItemIndex+1;
 topdir9=DirectoryListBox1->Directory;
 while (curnum9!=numsubs9)
  {
  DirectoryListBox1->ItemIndex=curnum9;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   }
curnum9++;
DirectoryListBox1->Directory=topdir9;
  }
  }
curnum8++;
DirectoryListBox1->Directory=topdir8;
  }
  }
curnum7++;
DirectoryListBox1->Directory=topdir7;
  }
  }
curnum6++;
DirectoryListBox1->Directory=topdir6;
  }
  }
curnum5++;
DirectoryListBox1->Directory=topdir5;
  }
  }
curnum4++;
DirectoryListBox1->Directory=topdir4;
  }
  }

curnum3++;
DirectoryListBox1->Directory=topdir3;
  }
  }
curnum2++;
DirectoryListBox1->Directory=topdir2;
  }
curnum++;
 DirectoryListBox1->Directory=topdir;
 }
}
}
}
catch (...) {}
DirectoryListBox1->Directory=Label1->Caption;
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
   TTagMP3=GetMp3Tag(Form3->ListBox1->Items->Strings[i],0);
   AnsiString TT1,TT2,TT3;
   int error=0;
   try { TT1=TTagMP3[1]; } catch (...) {error++;}
   try { TT2=TTagMP3[2]; } catch (...) {error++;}
   try { TT3=TTagMP3[3]; } catch (...) {error++;}
   if (!error)
   {
   if ((TT1=="T") && (TT2=="A") && (TT3=="G"))
   Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(Form3->ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(Form3->ListBox1->Items->Strings[i],1)));
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
   TTagMP3=GetMp3Tag(Form3->ListBox1->Items->Strings[cursong],0);
   AnsiString TT1,TT2,TT3;
   int error=0;
   try { TT1=TTagMP3[1]; } catch (...) {error++;}
   try { TT2=TTagMP3[2]; } catch (...) {error++;}
   try { TT3=TTagMP3[3]; } catch (...) {error++;}
   if (!error)
   {
   if ((TT1=="T") && (TT2=="A") && (TT3=="G"))
   Form3->ListBox2->Items->Strings[cursong]=(AnsiString(GetMp3Tag(Form3->ListBox1->Items->Strings[cursong],2))+" - "+AnsiString(GetMp3Tag(Form3->ListBox1->Items->Strings[cursong],1)));
   else Form3->ListBox2->Items->Strings[cursong]=(AnsiString(crofilename(Form3->ListBox1->Items->Strings[cursong])));
   }
   else Form3->ListBox2->Items->Strings[cursong]=(AnsiString(crofilename(Form3->ListBox1->Items->Strings[cursong])));
   }
   Form3->MediaPlayer1->Open();
   Form3->MediaPlayer1->Position=Form3->TrackBar2->Position;
   Form3->MediaPlayer1->Play();
   }
/*for (int i=0; i<Form3->ListBox1->Items->Count; i++)
{
if (Form3->ListBox1->Items->Strings[i]!=Form3->MediaPlayer1->FileName)
{
try
{
Form3->MediaPlayer2->FileName=Form3->ListBox1->Items->Strings[i];
try {
Form3->MediaPlayer2->Open();
}
catch ( EMCIDeviceError& ) { /}
Form3->timetoplay+=Form3->MediaPlayer2->Length;
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(Form3->MediaPlayer2->Length))/1000)/60)-(StrToInt(Form3->MediaPlayer2->Length)/1000)/60)*60);
AnsiString TIME0;
if (retvalue>9)
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer2->Length)/1000)/60)+":"+FloatToStr(retvalue);
else
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer2->Length)/1000)/60)+":0"+FloatToStr(retvalue);
Form3->ListBox2->Items->Strings[i]=Form3->ListBox2->Items->Strings[i]+" \("+TIME0+"\) ";
Form3->MediaPlayer2->Close();
}
catch ( EMCIDeviceError& ) {}
}
else
{
Form3->timetoplay+=Form3->MediaPlayer1->Length;
int retvalue=0,retvalue2=0; retvalue=Floor(((((StrToFloat(Form3->MediaPlayer1->Length))/1000)/60)-(StrToInt(Form3->MediaPlayer1->Length)/1000)/60)*60);
AnsiString TIME0;
if (retvalue>9)
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer1->Length)/1000)/60)+":"+FloatToStr(retvalue);
else
TIME0=FloatToStr((StrToInt(Form3->MediaPlayer1->Length)/1000)/60)+":0"+FloatToStr(retvalue);
Form3->ListBox2->Items->Strings[i]=Form3->ListBox2->Items->Strings[i]+" \("+TIME0+"\) ";
}
} */
Form3->cashstat=true;
Form3->itemscount=0;
Form3->Timer4->Enabled=true;  //!!!!
//Form3->MediaPlayer2->Stop();
//Form3->MediaPlayer2->Close();
Form3->MediaPlayer2->FileName=NULL;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->TrackBar2->Enabled=false;
Form3->Timer3->Enabled=true;
Form4->Close();
}

//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{
Label1->Caption=DirectoryListBox1->Directory;
DirectoryListBox1->Directory=Label2->Caption;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------




void __fastcall TForm4::FormCreate(TObject *Sender)
{
Label2->Caption=DirectoryListBox1->Directory;
}
//---------------------------------------------------------------------------

