//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Panel2Click(TObject *Sender)
{
DirectoryListBox1->Directory=Label1->Caption;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form5->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Panel1Click(TObject *Sender)
{
Label2->Caption=DirectoryListBox1->Directory;
for (int i=0; i<FileListBox1->Items->Count; i++)
{
FileListBox1->ItemIndex=i;
Form3->Memo1->Lines->Add(FileListBox1->FileName);
Form3->Memo1->Lines->SaveToFile("C:\\Program Files\\TDSV\\Jim\\db\\pic.db");
}
DirectoryListBox1->Directory=Label1->Caption;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form5->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender)
{
Label2->Caption=DirectoryListBox1->Directory;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormShow(TObject *Sender)
{
Label1->Caption=DirectoryListBox1->Directory;
DirectoryListBox1->Directory=Label2->Caption;
}
//---------------------------------------------------------------------------
