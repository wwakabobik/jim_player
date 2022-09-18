//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit6.h"
#include "library.h"
#include "Unit3.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------


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
    memmove( c, tMp3.tag, 30 ); c[30] = 0;
//	MessageBox( NULL, c, "Title", NULL );
    if (callparam==0)
    return c;
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


__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\1.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\2.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\3.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton4Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\4.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton5Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\5.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton6Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\6.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton7Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\7.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton8Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\8.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton9Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\9.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton10Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile("db\\0.jpl");
for (int i=0;i<ListBox1->Items->Count;i++)
{
if (!Form6->CheckBox1->Checked)
ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
else
{
AnsiString TTagMP3=GetMp3Tag(ListBox1->Items->Strings[i],0);
if ((TTagMP3[1]=='T') && (TTagMP3[2]=='A') && (TTagMP3[3]=='G'))
ListBox2->Items->Add(AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],2))+" - "+AnsiString(GetMp3Tag(ListBox1->Items->Strings[i],1)));
else ListBox2->Items->Add(AnsiString(crofilename(ListBox1->Items->Strings[i])));
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel3Click(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
for (int i=0; i<Form3->ListBox1->Items->Count;i++)
ListBox1->Items->Add(Form3->ListBox1->Items->Strings[i]);
for (int i=0; i<Form3->ListBox2->Items->Count;i++)
ListBox2->Items->Add(Form3->ListBox2->Items->Strings[i]);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel2Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel1Click(TObject *Sender)
{
if (RadioButton1->Checked)
ListBox1->Items->SaveToFile("db\\1.jpl");
else if (RadioButton2->Checked)
ListBox1->Items->SaveToFile("db\\2.jpl");
else if (RadioButton3->Checked)
ListBox1->Items->SaveToFile("db\\3.jpl");
else if (RadioButton4->Checked)
ListBox1->Items->SaveToFile("db\\4.jpl");
else if (RadioButton5->Checked)
ListBox1->Items->SaveToFile("db\\5.jpl");
else if (RadioButton6->Checked)
ListBox1->Items->SaveToFile("db\\6.jpl");
else if (RadioButton7->Checked)
ListBox1->Items->SaveToFile("db\\7.jpl");
else if (RadioButton8->Checked)
ListBox1->Items->SaveToFile("db\\8.jpl");
else if (RadioButton9->Checked)
ListBox1->Items->SaveToFile("db\\9.jpl");
else if (RadioButton10->Checked)
ListBox1->Items->SaveToFile("db\\0.jpl");
else ShowMessage("Вы не выбрали плейлист!");
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox2KeyDown(TObject *Sender, WORD &Key,
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
ListBox1->Items->Delete(ListBox2->ItemIndex);
ListBox2->Items->Delete(ListBox2->ItemIndex);
}
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
for (int i=0; i<Form3->ListBox1->Items->Count;i++)
ListBox1->Items->Add(Form3->ListBox1->Items->Strings[i]);
for (int i=0; i<Form3->ListBox2->Items->Count;i++)
ListBox2->Items->Add(Form3->ListBox2->Items->Strings[i]);
RadioButton1->Checked=false;
RadioButton2->Checked=false;
RadioButton3->Checked=false;
RadioButton4->Checked=false;
RadioButton5->Checked=false;
RadioButton6->Checked=false;
RadioButton7->Checked=false;
RadioButton8->Checked=false;
RadioButton9->Checked=false;
RadioButton10->Checked=false;
}
//---------------------------------------------------------------------------
