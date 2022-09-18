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
if (!CheckBox1->Checked)
{
for (int i=0; i<FileListBox1->Items->Count; i++)
{
FileListBox1->ItemIndex=i;
Form3->ListBox1->Items->Add(FileListBox1->FileName);
Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
}
}
else {
Form4->Visible=false;
int numsubs,curnum,numsubs2,curnum2,curnum3,curnum4,curnum5,curnum6,curnum7,curnum8,curnum9,numsubs3,numsubs4,numsubs5,numsubs6,numsubs7,numsubs8,numsubs9;
AnsiString topdir=DirectoryListBox1->Directory, topdir2, topdir3, topdir4, topdir5, topdir6, topdir7, topdir8, topdir9;
numsubs=DirectoryListBox1->Items->Count;
curnum=DirectoryListBox1->ItemIndex+1;
for (int i=0; i<FileListBox1->Items->Count; i++)
{
FileListBox1->ItemIndex=i;
Form3->ListBox1->Items->Add(FileListBox1->FileName);
Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
}
while (curnum!=numsubs)
{
DirectoryListBox1->ItemIndex=curnum;
DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
//------------если нет подкаталогов
if (curnum==numsubs)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs2=DirectoryListBox1->Items->Count;
 curnum2=DirectoryListBox1->ItemIndex+1;
 topdir2=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum2!=numsubs2)
  {
  DirectoryListBox1->ItemIndex=curnum2;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
//вставлено
if (curnum2==numsubs2)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs3=DirectoryListBox1->Items->Count;
 curnum3=DirectoryListBox1->ItemIndex+1;
 topdir3=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum3!=numsubs3)
  {
  DirectoryListBox1->ItemIndex=curnum3;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //////////////////
  if (curnum3==numsubs3)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs4=DirectoryListBox1->Items->Count;
 curnum4=DirectoryListBox1->ItemIndex+1;
 topdir4=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum4!=numsubs4)
  {
  DirectoryListBox1->ItemIndex=curnum4;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
    if (curnum4==numsubs4)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs5=DirectoryListBox1->Items->Count;
 curnum5=DirectoryListBox1->ItemIndex+1;
 topdir5=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum5!=numsubs5)
  {
  DirectoryListBox1->ItemIndex=curnum5;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
    if (curnum5==numsubs5)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs6=DirectoryListBox1->Items->Count;
 curnum6=DirectoryListBox1->ItemIndex+1;
 topdir6=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum6!=numsubs6)
  {
  DirectoryListBox1->ItemIndex=curnum6;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
      if (curnum6==numsubs6)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs7=DirectoryListBox1->Items->Count;
 curnum7=DirectoryListBox1->ItemIndex+1;
 topdir7=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum7!=numsubs7)
  {
  DirectoryListBox1->ItemIndex=curnum7;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
        if (curnum7==numsubs7)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs8=DirectoryListBox1->Items->Count;
 curnum8=DirectoryListBox1->ItemIndex+1;
 topdir8=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum8!=numsubs8)
  {
  DirectoryListBox1->ItemIndex=curnum8;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
        if (curnum8==numsubs8)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs9=DirectoryListBox1->Items->Count;
 curnum9=DirectoryListBox1->ItemIndex+1;
 topdir9=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum9!=numsubs9)
  {
  DirectoryListBox1->ItemIndex=curnum9;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
    //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum9++;
DirectoryListBox1->Directory=topdir9;
  }
  }
    //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum8++;
DirectoryListBox1->Directory=topdir8;
  }
  }
    //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum7++;
DirectoryListBox1->Directory=topdir7;
  }
  }
  //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum6++;
DirectoryListBox1->Directory=topdir6;
  }
  }
  //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum5++;
DirectoryListBox1->Directory=topdir5;
  }
  }

  //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum4++;
DirectoryListBox1->Directory=topdir4;
  }
  }
  //////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum3++;
DirectoryListBox1->Directory=topdir3;
  }
  }
//убрано
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum2++;
DirectoryListBox1->Directory=topdir2;
  }
 curnum++;
 DirectoryListBox1->Directory=topdir;
 }
}
}
//Form4->Visible=true;
DirectoryListBox1->Directory=Label1->Caption;
Form1->Timer1->Enabled=true;
Form2->Timer1->Enabled=true;
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->MediaPlayer1->Pause();
Form4->Close();
}

//
//---------------------------------------------------------------------------

/*void __fastcall TForm4::Button2Click(TObject *Sender)
{

} */
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{
Label1->Caption=DirectoryListBox1->Directory;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button1Click(TObject *Sender)
{
int numsubs,curnum,numsubs2,curnum2,curnum3,curnum4,curnum5,curnum6,curnum7,curnum8,curnum9,numsubs3,numsubs4,numsubs5,numsubs6,numsubs7,numsubs8,numsubs9;
AnsiString topdir=DirectoryListBox1->Directory, topdir2, topdir3, topdir4, topdir5, topdir6, topdir7, topdir8, topdir9;
numsubs=DirectoryListBox1->Items->Count;
curnum=DirectoryListBox1->ItemIndex+1;
for (int i=0; i<FileListBox1->Items->Count; i++)
{
FileListBox1->ItemIndex=i;
Form3->ListBox1->Items->Add(FileListBox1->FileName);
Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
}
while (curnum!=numsubs)
{
DirectoryListBox1->ItemIndex=curnum;
DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
//------------если нет подкаталогов
if (curnum==numsubs)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs2=DirectoryListBox1->Items->Count;
 curnum2=DirectoryListBox1->ItemIndex+1;
 topdir2=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum2!=numsubs2)
  {
  DirectoryListBox1->ItemIndex=curnum2;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
//вставлено
if (curnum2==numsubs2)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs3=DirectoryListBox1->Items->Count;
 curnum3=DirectoryListBox1->ItemIndex+1;
 topdir3=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum3!=numsubs3)
  {
  DirectoryListBox1->ItemIndex=curnum3;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //////////////////
  if (curnum3==numsubs3)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs4=DirectoryListBox1->Items->Count;
 curnum4=DirectoryListBox1->ItemIndex+1;
 topdir4=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum4!=numsubs4)
  {
  DirectoryListBox1->ItemIndex=curnum4;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
    if (curnum4==numsubs4)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs5=DirectoryListBox1->Items->Count;
 curnum5=DirectoryListBox1->ItemIndex+1;
 topdir5=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum5!=numsubs5)
  {
  DirectoryListBox1->ItemIndex=curnum5;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
    if (curnum5==numsubs5)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs6=DirectoryListBox1->Items->Count;
 curnum6=DirectoryListBox1->ItemIndex+1;
 topdir6=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum6!=numsubs6)
  {
  DirectoryListBox1->ItemIndex=curnum6;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
      if (curnum6==numsubs6)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs7=DirectoryListBox1->Items->Count;
 curnum7=DirectoryListBox1->ItemIndex+1;
 topdir7=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum7!=numsubs7)
  {
  DirectoryListBox1->ItemIndex=curnum7;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
        if (curnum7==numsubs7)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs8=DirectoryListBox1->Items->Count;
 curnum8=DirectoryListBox1->ItemIndex+1;
 topdir8=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum8!=numsubs8)
  {
  DirectoryListBox1->ItemIndex=curnum8;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
        if (curnum8==numsubs8)
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 curnum++;
 DirectoryListBox1->Directory=topdir;
}
//если есть подкаталоги
else
 {
 for (int i=0; i<FileListBox1->Items->Count; i++)
 {
 FileListBox1->ItemIndex=i;
 Form3->ListBox1->Items->Add(FileListBox1->FileName);
 Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
 }
 numsubs9=DirectoryListBox1->Items->Count;
 curnum9=DirectoryListBox1->ItemIndex+1;
 topdir9=DirectoryListBox1->Directory;
// ShowMessage("≈сть подкаталог!" + DirectoryListBox1->Directory);
 while (curnum9!=numsubs9)
  {
  DirectoryListBox1->ItemIndex=curnum9;
  DirectoryListBox1->Directory=DirectoryListBox1->Items->Strings[DirectoryListBox1->ItemIndex];
  //!!!!!!!!!!!!!!!!!!!!////////////////
    //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum9++;
DirectoryListBox1->Directory=topdir9;
  }
  }
    //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum8++;
DirectoryListBox1->Directory=topdir8;
  }
  }
    //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum7++;
DirectoryListBox1->Directory=topdir7;
  }
  }
  //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum6++;
DirectoryListBox1->Directory=topdir6;
  }
  }
  //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum5++;
DirectoryListBox1->Directory=topdir5;
  }
  }

  //!!!!!!!!!!!!!!!!!!!!////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum4++;
DirectoryListBox1->Directory=topdir4;
  }
  }
  //////////////////
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum3++;
DirectoryListBox1->Directory=topdir3;
  }
  }
//убрано
  for (int i=0; i<FileListBox1->Items->Count; i++)
   {
   FileListBox1->ItemIndex=i;
   Form3->ListBox1->Items->Add(FileListBox1->FileName);
   Form3->ListBox2->Items->Add(AnsiString(crofilename(FileListBox1->FileName)));
   }
curnum2++;
DirectoryListBox1->Directory=topdir2;
  }
 curnum++;
 DirectoryListBox1->Directory=topdir;
 }
}
}
//---------------------------------------------------------------------------



