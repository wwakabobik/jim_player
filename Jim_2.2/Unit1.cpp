//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "library.h"
#include <SysUtils.hpp>
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

int reloadstat=0;


void __fastcall TForm1::Panel2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (ListBox1->ItemIndex>-1)
{
try
{
char tempword[1024];
WideString S=ListBox1->Items->Strings[ListBox1->ItemIndex];
int i=1;
while (S[i]!=0)
{
tempword[i-1]=S[i];
i++;
}
tempword[i-1]='\0';
Panel1->Caption=(AnsiString(translate(tempword)));
}
catch (EInvalidPointer&) {}   //fuck!
Memo1->Lines->Clear();
Memo2->Lines->Clear();
Memo3->Lines->Clear();
unsigned char bukva;
WideString S;
S=Panel1->Caption;
for (int j=1; j<80; j++)
{
bukva=S[j];
if (bukva!='\0')
{
j++;
Memo2->Lines->Add(AnsiString(binaryconvert(bukva,7))+AnsiString(binaryconvert(bukva,6))+AnsiString(binaryconvert(bukva,5))+AnsiString(binaryconvert(bukva,4))+AnsiString(binaryconvert(bukva,3))+AnsiString(binaryconvert(bukva,2))+AnsiString(binaryconvert(bukva,1))+AnsiString(binaryconvert(bukva,0)));
int number=bukva;
Memo1->Lines->Add(number);
Memo3->Lines->Add(hexconvert(number));
}
else break;
}
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo2->Lines->Add("10011111");
Memo2->Lines->Add("11100010");
Memo2->Lines->Add("10100101");
Memo2->Lines->Add("10100001");
Memo2->Lines->Add("11101111");
Memo2->Lines->Add("10101011");
Memo2->Lines->Add("11101110");
Memo2->Lines->Add("10100001");
Memo2->Lines->Add("10101011");
Memo2->Lines->Add("11101110");
Memo1->Lines->Add("159");
Memo1->Lines->Add("226");
Memo1->Lines->Add("165");
Memo1->Lines->Add("161");
Memo1->Lines->Add("239");
Memo1->Lines->Add("171");
Memo1->Lines->Add("238");
Memo1->Lines->Add("161");
Memo1->Lines->Add("171");
Memo1->Lines->Add("238");
Memo3->Lines->Add("09f");
Memo3->Lines->Add("0e2");
Memo3->Lines->Add("0a5");
Memo3->Lines->Add("0a1");
Memo3->Lines->Add("0ef");
Memo3->Lines->Add("0ab");
Memo3->Lines->Add("0ee");
Memo3->Lines->Add("0a1");
Memo3->Lines->Add("0ab");
Memo3->Lines->Add("0ee");
Panel1->Caption="Я тебя люблю!";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if (reloadstat==0)
{
Image1->Picture->LoadFromFile("animation\\gif_sob_2.jpg");
reloadstat=1;
}
else if (reloadstat==1)
{
Image1->Picture->LoadFromFile("animation\\gif_sob_3.jpg");
reloadstat=2;
}
else if (reloadstat==2)
{
Image1->Picture->LoadFromFile("animation\\gif_sob_4.jpg");
reloadstat=3;
}
else if (reloadstat==3)
{
Image1->Picture->LoadFromFile("animation\\gif_sob_5.jpg");
reloadstat=4;
}
else if (reloadstat==4)
{
Image1->Picture->LoadFromFile("animation\\gif_sob_6.jpg");
reloadstat=5;
}
else if (reloadstat==5)
{
Image1->Picture->LoadFromFile("animation\\gif_sob_7.jpg");
reloadstat=6;
}
else if (reloadstat==6)
{
Image1->Picture->LoadFromFile("animation\\gif_sob_8.jpg");
reloadstat=7;
}
else
{
Image1->Picture->LoadFromFile("animation\\gif_sob_1.jpg");
reloadstat=0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Form1->Visible=false;
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

