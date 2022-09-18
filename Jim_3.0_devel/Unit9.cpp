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
TForm9 *Form9;
//---------------------------------------------------------------------------

__fastcall TForm9::TForm9(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm9::RadioButton1Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\1.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton2Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\2.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton3Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\3.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton4Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\4.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton5Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\5.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton6Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\6.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton7Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\7.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton8Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\8.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton9Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\9.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::RadioButton10Enter(TObject *Sender)
{
ListBox1->SelectAll();
ListBox2->SelectAll();
ListBox2->DeleteSelected();
ListBox1->DeleteSelected();
ListBox1->Items->LoadFromFile(Form3->InitDirectory+"\\db\\0.jpl");
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
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Panel3Click(TObject *Sender)
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
void __fastcall TForm9::Panel2Click(TObject *Sender)
{
Form9->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Panel1Click(TObject *Sender)
{
if (RadioButton1->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\1.jpl");
else if (RadioButton2->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\2.jpl");
else if (RadioButton3->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\3.jpl");
else if (RadioButton4->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\4.jpl");
else if (RadioButton5->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\5.jpl");
else if (RadioButton6->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\6.jpl");
else if (RadioButton7->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\7.jpl");
else if (RadioButton8->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\8.jpl");
else if (RadioButton9->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\9.jpl");
else if (RadioButton10->Checked)
ListBox1->Items->SaveToFile(Form3->InitDirectory+"\\db\\0.jpl");
else ShowMessage("Вы не выбрали плейлист!");
Form9->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ListBox2KeyDown(TObject *Sender, WORD &Key,
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
void __fastcall TForm9::FormShow(TObject *Sender)
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
