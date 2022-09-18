//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
if (ComboBox1->ItemIndex==0)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM C:\\Program Files\\db\\statistic.db");
Query1->Open();
}
if (ComboBox1->ItemIndex==1)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Group_c LIKE \'\%"+LabeledEdit1->Text+"\%\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==2)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Song_c LIKE \'\%"+LabeledEdit2->Text+"\%\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==3)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Group_c LIKE \'\%" + LabeledEdit1->Text + "\% and Song_c LIKE \%" + LabeledEdit2->Text + "\%\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==4)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, sum(Access_c) FROM db\\statistic.db GROUP BY Group_c");
Query1->Open();
AnsiString Group_b;
int maxcount=0;
Query1->First();
while (!Query1->Eof)
{
if (maxcount<Query1->FieldByName("SUM OF Access_c")->AsInteger)
{
Group_b=Query1->FieldByName("Group_c")->AsString;
maxcount=Query1->FieldByName("SUM OF Access_c")->AsInteger;
}
Query1->Next();
}
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Group_c=\'"+Group_b+"\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==5)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Access_c=(SELECT max(Access_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==6)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, count(Access_c) FROM db\\statistic.db GROUP BY Group_c");
Query1->Open();
AnsiString Group_b;
int maxcount=0;
Query1->First();
while (!Query1->Eof)
{
if (maxcount<Query1->FieldByName("COUNT OF Access_c")->AsInteger)
{
Group_b=Query1->FieldByName("Group_c")->AsString;
maxcount=Query1->FieldByName("COUNT OF Access_c")->AsInteger;
}
Query1->Next();
}
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Group_c=\'"+Group_b+"\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==7)
{
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db WHERE LastAccess_c=(SELECT max(LastAccess_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==8)
{
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db WHERE FirstAccess_c=(SELECT min(FirstAccess_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==9)
{
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db WHERE UserLength_c=(SELECT max(UserLength_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==10)
{
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db WHERE UserLength_c=(SELECT min(UserLength_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==11)
{
int i=0;
Table1->First();
while (!Table1->Eof)
{
i++;
//ShowMessage(Table1->FieldByName("Group_c")->AsString);
Table1->Next();
}
ShowMessage("Количество прослушанных песен: "+IntToStr(i));
}
if (ComboBox1->ItemIndex==12)
{
long int min=0,sec=0;
AnsiString min0,sec0,fullUL;
Table1->First();
while (!Table1->Eof)
{
fullUL=Table1->FieldByName("UserLength_c")->AsString;
int i=1;
min0=fullUL;
sec0=fullUL;
while(fullUL[i]!='\:')
{
min0[i]=fullUL[i];
i++;
}
min0[i]='\0';
i=i+1;
int j=1;
while (i<=fullUL.Length())
{
sec0[j]=fullUL[i];
i++; j++;
}
sec0[j]='\0';
min=StrToInt(min0);
sec+=StrToInt(sec0);
sec+=60*min;
Table1->Next();
}
int sectotal=(IntToStr(sec)-(IntToStr(sec)/60)*60);
int mintotal=IntToStr(sec)/60;
ShowMessage(" "+IntToStr(mintotal)+"\:"+IntToStr(sectotal)+" ");
}
if (ComboBox1->ItemIndex==13)
{
long int min=0,sec=0,sec1=0;
AnsiString min0,sec0,fullUL;
Table1->First();
while (!Table1->Eof)
{
fullUL=Table1->FieldByName("UserLength_c")->AsString;
int i=1;
min0=fullUL;
sec0=fullUL;
while(fullUL[i]!='\:')
{
min0[i]=fullUL[i];
i++;
}
min0[i]='\0';
i=i+1;
int j=1;
while (i<=fullUL.Length())
{
sec0[j]=fullUL[i];
i++; j++;
}
sec0[j]='\0';
min=StrToInt(min0);
sec1=StrToInt(sec0);
sec1+=60*min;
sec1*=Table1->FieldByName("Access_c")->AsInteger;
sec+=sec1;
Table1->Next();
}
int sectotal=(IntToStr(sec)-(IntToStr(sec)/60)*60);
int mintotal=IntToStr(sec)/60;
ShowMessage(" "+IntToStr(mintotal)+"\:"+IntToStr(sectotal)+" ");
}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ComboBox1Change(TObject *Sender)
{
if (ComboBox1->ItemIndex==0)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db");
Query1->Open();
}
if (ComboBox1->ItemIndex==1)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Group_c LIKE \'\%"+LabeledEdit1->Text+"\%\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==2)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Song_c LIKE \'\%"+LabeledEdit2->Text+"\%\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==3)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Group_c LIKE \'\%" + LabeledEdit1->Text + "\% and Song_c LIKE \%" + LabeledEdit2->Text + "\%\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==4)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, sum(Access_c) FROM db\\statistic.db GROUP BY Group_c");
Query1->Open();
AnsiString Group_b;
int maxcount=0;
Query1->First();
while (!Query1->Eof)
{
if (maxcount<Query1->FieldByName("SUM OF Access_c")->AsInteger)
{
Group_b=Query1->FieldByName("Group_c")->AsString;
maxcount=Query1->FieldByName("SUM OF Access_c")->AsInteger;
}
Query1->Next();
}
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Group_c=\'"+Group_b+"\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==5)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Access_c=(SELECT max(Access_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==6)
{
Query1->Close();
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, count(Access_c) FROM db\\statistic.db GROUP BY Group_c");
Query1->Open();
AnsiString Group_b;
int maxcount=0;
Query1->First();
while (!Query1->Eof)
{
if (maxcount<Query1->FieldByName("COUNT OF Access_c")->AsInteger)
{
Group_b=Query1->FieldByName("Group_c")->AsString;
maxcount=Query1->FieldByName("COUNT OF Access_c")->AsInteger;
}
Query1->Next();
}
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c  FROM db\\statistic.db WHERE Group_c=\'"+Group_b+"\'");
Query1->Open();
}
if (ComboBox1->ItemIndex==7)
{
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db WHERE LastAccess_c=(SELECT max(LastAccess_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==8)
{
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db WHERE FirstAccess_c=(SELECT min(FirstAccess_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==9)
{
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db WHERE UserLength_c=(SELECT max(UserLength_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==10)
{
Query1->SQL->Clear();
Query1->SQL->Add("SELECT Group_c, Song_c, Access_c, FirstAccess_c, LastAccess_c, UserLength_c FROM db\\statistic.db WHERE UserLength_c=(SELECT min(UserLength_c) FROM db\\statistic.db)");
Query1->Open();
}
if (ComboBox1->ItemIndex==11)
{
int i=0;
Table1->First();
while (!Table1->Eof)
{
i++;
//ShowMessage(Table1->FieldByName("Group_c")->AsString);
Table1->Next();
}
ShowMessage("Количество прослушанных песен: "+IntToStr(i));
}
if (ComboBox1->ItemIndex==12)
{
long int min=0,sec=0;
AnsiString min0,sec0,fullUL;
Table1->First();
while (!Table1->Eof)
{
fullUL=Table1->FieldByName("UserLength_c")->AsString;
int i=1;
min0=fullUL;
sec0=fullUL;
while(fullUL[i]!='\:')
{
min0[i]=fullUL[i];
i++;
}
min0[i]='\0';
i=i+1;
int j=1;
while (i<=fullUL.Length())
{
sec0[j]=fullUL[i];
i++; j++;
}
sec0[j]='\0';
min=StrToInt(min0);
sec+=StrToInt(sec0);
sec+=60*min;
Table1->Next();
}
int sectotal=(IntToStr(sec)-(IntToStr(sec)/60)*60);
int mintotal=IntToStr(sec)/60;
ShowMessage(" "+IntToStr(mintotal)+"\:"+IntToStr(sectotal)+" ");
}
if (ComboBox1->ItemIndex==13)
{
long int min=0,sec=0,sec1=0;
AnsiString min0,sec0,fullUL;
Table1->First();
while (!Table1->Eof)
{
fullUL=Table1->FieldByName("UserLength_c")->AsString;
int i=1;
min0=fullUL;
sec0=fullUL;
while(fullUL[i]!='\:')
{
min0[i]=fullUL[i];
i++;
}
min0[i]='\0';
i=i+1;
int j=1;
while (i<=fullUL.Length())
{
sec0[j]=fullUL[i];
i++; j++;
}
sec0[j]='\0';
min=StrToInt(min0);
sec1=StrToInt(sec0);
sec1+=60*min;
sec1*=Table1->FieldByName("Access_c")->AsInteger;
sec+=sec1;
Table1->Next();
}
int sectotal=(IntToStr(sec)-(IntToStr(sec)/60)*60);
int mintotal=IntToStr(sec)/60;
ShowMessage(" "+IntToStr(mintotal)+"\:"+IntToStr(sectotal)+" ");
}
}
 //
//---------------------------------------------------------------------------




void __fastcall TForm8::Button2Click(TObject *Sender)
{
Table1->First();
while (!Table1->Eof)
{
Table1->Edit();
Table1->Delete();
Table1->Next();
Table1->Edit();
try {
Table1->Post();
}
catch (...) {}
}
LabeledEdit3->Text=0;
LabeledEdit5->Text=0;
}
//---------------------------------------------------------------------------

