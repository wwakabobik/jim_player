//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "library.h"
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
Form1->Timer1->Enabled=true;
Form2->Timer1->Enabled=true;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->MediaPlayer1->Pause();
Form4->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Panel1Click(TObject *Sender)
{
Label2->Caption=DirectoryListBox1->Directory;
if (!CheckBox1->Checked)
{
for (int i=0; i<FileListBox1->Items->Count; i++)
{
FileListBox1->ItemIndex=i;
Form3->ListBox1->Items->Add(FileListBox1->FileName);
//Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
//Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
// Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
//   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
Form3->ListBox2->Items->Add(AnsiString(GetMp3Tag(FileListBox1->FileName,2))+" - "+AnsiString(GetMp3Tag(FileListBox1->FileName,1)));
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
DirectoryListBox1->Directory=Label1->Caption;
Form3->timetoplay=0;
AnsiString TR;
for (int i=0; i<Form3->ListBox1->Items->Count-1; i++)
{
if (Form3->ListBox1->Items->Strings[i]!=Form3->MediaPlayer1->FileName)
{
try
{
Form3->MediaPlayer2->FileName=Form3->ListBox1->Items->Strings[i];
Form3->MediaPlayer2->Open();
Form3->timetoplay+=Form3->MediaPlayer2->Length;
Form3->MediaPlayer2->Close();
}
catch ( EMCIDeviceError& ) {}
}
else Form3->timetoplay+=Form3->MediaPlayer1->Length;
}
//Form3->MediaPlayer2->Stop();
//Form3->MediaPlayer2->Close();
Form3->MediaPlayer2->FileName=NULL;
Form1->Timer1->Enabled=true;
Form2->Timer1->Enabled=true;
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

