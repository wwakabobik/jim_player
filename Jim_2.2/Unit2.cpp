//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

int reloadstat=0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
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
void __fastcall TForm2::Panel2Click(TObject *Sender)
{
Form2->Visible=false;
Form1->Show();
}
//---------------------------------------------------------------------------

