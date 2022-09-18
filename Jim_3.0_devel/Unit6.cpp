//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit3.h"
#include "Unit7.h"
//#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall initLang()
{
if (Form6->ComboBox3->ItemIndex==0) // русский
{
Form6->Button1->Caption="Выбрать цвет";
Form6->Button2->Caption="Выбрать шрифт";
Form6->Button3->Caption="Сохранить";
Form6->Button4->Caption="Установить";
Form6->Button5->Caption="Установить";
Form6->Button6->Caption="Установить";
Form6->Button7->Caption="Выбрать изображение для кнопки";
Form6->Button8->Caption="Отменить изменение";
Form6->Button9->Caption="Сохранить как скин";
Form6->Button10->Caption="Загрузить скин";
Form6->Button11->Caption="Выйти";
Form6->Button12->Caption="Установить шкуру";
Form6->Label1->Caption="Альфа-компонента";
Form6->LabeledEdit1->EditLabel->Caption="Интервал для смены картинок, мс";
Form6->LabeledEdit2->EditLabel->Caption="Фоновая картинка";
Form6->LabeledEdit3->EditLabel->Caption="Шкурка по умолчанию";
Form6->LabeledEdit4->EditLabel->Caption="Ширина плейлиста";
Form6->LabeledEdit5->EditLabel->Caption="Высота плейлиста";
Form6->LabeledEdit6->EditLabel->Caption="Ширина картинки";
Form6->LabeledEdit7->EditLabel->Caption="Высота картинки";
Form6->CheckBox2->Caption="Множить фон";
Form6->CheckBox1->Caption="по ID3V1.1\\Filename";
Form6->CheckBox3->Caption="Умная рандомизация";
Form6->ComboBox1->Items->Strings[0]="Индикаторы времени";
Form6->ComboBox1->Items->Strings[1]="Плейлист";
Form6->ComboBox1->Items->Strings[2]="Главное окно";
Form6->ComboBox1->Items->Strings[3]="Строка статуса";
Form6->ComboBox2->Items->Strings[0]="Назад";
Form6->ComboBox2->Items->Strings[1]="Вперед";
Form6->ComboBox2->Items->Strings[2]="Играть";
Form6->ComboBox2->Items->Strings[3]="Пауза";
Form6->ComboBox2->Items->Strings[4]="Добавить";
Form6->ComboBox2->Items->Strings[5]="Удалить";
Form6->ComboBox2->Items->Strings[6]="Сохранить плейлист";
Form6->ComboBox2->Items->Strings[7]="Настройки";
Form6->ComboBox2->Items->Strings[8]="Открыть картинки";
Form6->ComboBox2->Items->Strings[9]="Добавить картинку";
Form6->ComboBox2->Items->Strings[10]="Удалить картинку";
Form6->ComboBox2->Items->Strings[11]="Остановить\\запустить слайдшоу";
Form6->ComboBox2->Items->Strings[12]="Сортировать";
Form3->Image2->Hint="предыдущая песня";
Form3->Image8->Hint="Пауза";
Form3->Image9->Hint="Играть";
Form3->Image10->Hint="следующая песня";
Form3->Image4->Hint="Добавить \\ Пр. клик - опции";
Form3->Image5->Hint="Удалить \\ Пр. клик - опции";
Form3->Image6->Hint="Сохранить плейлист \\ Пр. клик - опции";
Form3->Image15->Hint="Сортировать \\ Пр. клик - опции";
Form3->Image7->Hint="Настройки";
Form3->Image11->Hint="Открыть\\Закрыть просмотр картинок";
Form3->Image12->Hint="Добавить картинку \\ Пр. клик - опции";
Form3->Image13->Hint="Удалить картинку \\ Пр. клик - опции";
Form3->Image14->Hint="Остановить\\Запустить слайдшоу";
Form4->Panel1->Caption="Добавить";
Form4->Panel2->Caption="Отмена";
Form5->Panel1->Caption="Добавить";
Form5->Panel2->Caption="Отмена";
Form4->CheckBox1->Caption="Добавлять в подкаталогах";
Form3->N1->Caption="Удалить выделенное";
Form3->N2->Caption="Удалить всё";
Form3->N6->Caption="Удалить дупликаты";
Form3->MenuItem1->Caption="Добавить файл";
Form3->MenuItem2->Caption="Добавить каталог";
Form3->MenuItem3->Caption="Добавить файл";
Form3->MenuItem4->Caption="Добавить каталог";
Form3->MenuItem5->Caption="Сохранить по умолчанию";
Form3->MenuItem6->Caption="Сохранить как";
Form3->N3->Caption="Загрузить";
Form3->HTML1->Caption="Сохранить HTML";
Form3->MenuItem7->Caption="По имени файла";
Form3->MenuItem8->Caption="По алфавиту";
Form3->N4->Caption="По песне";
Form3->N5->Caption="Перемешать";
Form3->MenuItem9->Caption="Удалить";
Form3->MenuItem10->Caption="Удалить всё";
Form6->Button13->Caption="О программе";
Form6->CheckBox4->Caption="Вести статистику";
Form6->Button14->Caption="Статистика";
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

void __fastcall TForm6::Button1Click(TObject *Sender)
{
if (ColorDialog1->Execute())
{
if (ComboBox1->ItemIndex==0)
{
Form3->Edit2->Color=ColorDialog1->Color;
Form3->Edit3->Color=ColorDialog1->Color;
}
if (ComboBox1->ItemIndex==1)
Form3->ListBox2->Color=ColorDialog1->Color;
if (ComboBox1->ItemIndex==2)
Form3->Color=ColorDialog1->Color;
if (ComboBox1->ItemIndex==3)
Form3->StatusBar1->Color=ColorDialog1->Color;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender)
{
if (FontDialog1->Execute())
{
if (ComboBox1->ItemIndex==0)
{
Form3->Edit2->Font->Assign(FontDialog1->Font);
Form3->Edit3->Font->Assign(FontDialog1->Font);
}
if (ComboBox1->ItemIndex==1)
Form3->ListBox2->Font->Assign(FontDialog1->Font);
if (ComboBox1->ItemIndex==2)
Form3->Font->Assign(FontDialog1->Font);
if (ComboBox1->ItemIndex==3)
Form3->StatusBar1->Font->Assign(FontDialog1->Font);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender)
{
Memo1->Lines->Clear();
/* данные об Edit'ах*/
Memo1->Lines->Add(Form3->Edit2->Color);
Memo1->Lines->Add(Form3->Edit2->Font->Name);
Memo1->Lines->Add(Form3->Edit2->Font->Color);
Memo1->Lines->Add(Form3->Edit2->Font->Charset);
Memo1->Lines->Add(Form3->Edit2->Font->Size);
/* данные об ListBox'e*/
Memo1->Lines->Add(Form3->ListBox2->Color);
Memo1->Lines->Add(Form3->ListBox2->Font->Name);
Memo1->Lines->Add(Form3->ListBox2->Font->Color);
Memo1->Lines->Add(Form3->ListBox2->Font->Charset);
Memo1->Lines->Add(Form3->ListBox2->Font->Size);
/* данные об Form'e*/
Memo1->Lines->Add(Form3->Color);
Memo1->Lines->Add(Form3->Font->Name);
Memo1->Lines->Add(Form3->Font->Color);
Memo1->Lines->Add(Form3->Font->Charset);
Memo1->Lines->Add(Form3->Font->Size);
/* данные об StatusBar'e*/
Memo1->Lines->Add(Form3->StatusBar1->Color);
Memo1->Lines->Add(Form3->StatusBar1->Font->Name);
Memo1->Lines->Add(Form3->StatusBar1->Font->Color);
Memo1->Lines->Add(Form3->StatusBar1->Font->Charset);
Memo1->Lines->Add(Form3->StatusBar1->Font->Size);
/* данные об альфа-компоненте */
Memo1->Lines->Add(Form3->AlphaBlendValue);
/* данные о таймере */
Memo1->Lines->Add(Form3->Timer2->Interval);
/* данные о картинке */
Memo1->Lines->Add(LabeledEdit2->Text);
/* данные о кнопках */
//for (int i=0; i<ListBox1->Items->Count-1;i++)
//Memo1->Lines->Add(ListBox1->Items->Strings[i]);
Memo1->Lines->Add(ListBox1->Items->Strings[0]);
Memo1->Lines->Add(ListBox1->Items->Strings[1]);
Memo1->Lines->Add(ListBox1->Items->Strings[2]);
Memo1->Lines->Add(ListBox1->Items->Strings[3]);
Memo1->Lines->Add(ListBox1->Items->Strings[4]);
Memo1->Lines->Add(ListBox1->Items->Strings[5]);
Memo1->Lines->Add(ListBox1->Items->Strings[6]);
Memo1->Lines->Add(ListBox1->Items->Strings[7]);
Memo1->Lines->Add(ListBox1->Items->Strings[8]);
Memo1->Lines->Add(ListBox1->Items->Strings[9]);
Memo1->Lines->Add(ListBox1->Items->Strings[10]);
Memo1->Lines->Add(ListBox1->Items->Strings[11]);

/* размножать ли? */
Memo1->Lines->Add(StrToInt(AnsiString(Form3->multiplybkg)));
int tempint;
tempint=CheckBox1->Checked;
Memo1->Lines->Add(tempint);
tempint=CheckBox3->Checked;
Memo1->Lines->Add(tempint);
Memo1->Lines->Add(LabeledEdit4->Text);
Memo1->Lines->Add(LabeledEdit5->Text);
Memo1->Lines->Add(LabeledEdit6->Text);
Memo1->Lines->Add(LabeledEdit7->Text);
Memo1->Lines->Add(ListBox1->Items->Strings[12]);
Memo1->Lines->SaveToFile(LabeledEdit3->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button4Click(TObject *Sender)
{
try {
Form3->AlphaBlendValue=StrToInt(Edit1->Text);
}
catch ( EConvertError& ) { ShowMessage("Некорректный ввод. Введите целое число от 0 до 255.");}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button5Click(TObject *Sender)
{
try {
Form3->Timer2->Interval=StrToInt(LabeledEdit1->Text);
}
catch ( EConvertError& ) { ShowMessage("Некорректный ввод. Введите целое число.");}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button6Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
if (OpenPictureDialog1->Execute())
{
Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
LabeledEdit2->Text=OpenPictureDialog1->FileName;
Form3->Image3->Picture->LoadFromFile(OpenPictureDialog1->FileName);
}
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->Timer3->Enabled=true;     //
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button7Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
if (OpenPictureDialog2->Execute())
{
Image2->Picture->LoadFromFile(OpenPictureDialog2->FileName);
Image2->Picture->LoadFromFile(OpenPictureDialog2->FileName);
if (ComboBox2->ItemIndex==0)
ListBox1->Items->Strings[0]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==1)
ListBox1->Items->Strings[1]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==2)
ListBox1->Items->Strings[2]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==3)
ListBox1->Items->Strings[3]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==4)
ListBox1->Items->Strings[4]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==5)
ListBox1->Items->Strings[5]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==6)
ListBox1->Items->Strings[6]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==7)
ListBox1->Items->Strings[7]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==8)
ListBox1->Items->Strings[8]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==9)
ListBox1->Items->Strings[9]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==10)
ListBox1->Items->Strings[10]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==11)
ListBox1->Items->Strings[11]=OpenPictureDialog2->FileName;
if (ComboBox2->ItemIndex==12)
ListBox1->Items->Strings[12]=OpenPictureDialog2->FileName;
}
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->Timer3->Enabled=true;
}          //
//---------------------------------------------------------------------------
void __fastcall TForm6::CheckBox2Enter(TObject *Sender)
{
Form3->multiplybkg=CheckBox2->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::CheckBox2Exit(TObject *Sender)
{
Form3->multiplybkg=CheckBox2->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button9Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
if (SaveDialog1->Execute())
{
if (ExtractFileExt(SaveDialog1->FileName)!=".jsf" && ExtractFileExt(SaveDialog1->FileName)!=".JSF")
SaveDialog1->FileName=SaveDialog1->FileName+".jsf";
ListBox1->Items->SaveToFile(SaveDialog1->FileName);
Memo1->Lines->Clear();
// данные об Edit'ах
Memo1->Lines->Add(Form3->Edit2->Color);
Memo1->Lines->Add(Form3->Edit2->Font->Name);
Memo1->Lines->Add(Form3->Edit2->Font->Color);
Memo1->Lines->Add(Form3->Edit2->Font->Charset);
Memo1->Lines->Add(Form3->Edit2->Font->Size);
// данные об ListBox'e
Memo1->Lines->Add(Form3->ListBox2->Color);
Memo1->Lines->Add(Form3->ListBox2->Font->Name);
Memo1->Lines->Add(Form3->ListBox2->Font->Color);
Memo1->Lines->Add(Form3->ListBox2->Font->Charset);
Memo1->Lines->Add(Form3->ListBox2->Font->Size);
// данные об Form'e
Memo1->Lines->Add(Form3->Color);
Memo1->Lines->Add(Form3->Font->Name);
Memo1->Lines->Add(Form3->Font->Color);
Memo1->Lines->Add(Form3->Font->Charset);
Memo1->Lines->Add(Form3->Font->Size);
// данные об StatusBar'e
Memo1->Lines->Add(Form3->StatusBar1->Color);
Memo1->Lines->Add(Form3->StatusBar1->Font->Name);
Memo1->Lines->Add(Form3->StatusBar1->Font->Color);
Memo1->Lines->Add(Form3->StatusBar1->Font->Charset);
Memo1->Lines->Add(Form3->StatusBar1->Font->Size);
// данные об альфа-компоненте
Memo1->Lines->Add(Form3->AlphaBlendValue);
// данные о таймере
Memo1->Lines->Add(Form3->Timer2->Interval);
// данные о картинке
Memo1->Lines->Add(LabeledEdit2->Text);
// данные о кнопках
//for (int i=0; i<ListBox1->Items->Count-1;i++)
//Memo1->Lines->Add(ListBox1->Items->Strings[i]);
Memo1->Lines->Add(ListBox1->Items->Strings[0]);
Memo1->Lines->Add(ListBox1->Items->Strings[1]);
Memo1->Lines->Add(ListBox1->Items->Strings[2]);
Memo1->Lines->Add(ListBox1->Items->Strings[3]);
Memo1->Lines->Add(ListBox1->Items->Strings[4]);
Memo1->Lines->Add(ListBox1->Items->Strings[5]);
Memo1->Lines->Add(ListBox1->Items->Strings[6]);
Memo1->Lines->Add(ListBox1->Items->Strings[7]);
Memo1->Lines->Add(ListBox1->Items->Strings[8]);
Memo1->Lines->Add(ListBox1->Items->Strings[9]);
Memo1->Lines->Add(ListBox1->Items->Strings[10]);
Memo1->Lines->Add(ListBox1->Items->Strings[11]);
// размножать ли?
Memo1->Lines->Add(StrToInt(AnsiString(Form3->multiplybkg)));
int tempint;
tempint=CheckBox1->Checked;
Memo1->Lines->Add(tempint);
tempint=CheckBox3->Checked;
Memo1->Lines->Add(tempint);
Memo1->Lines->Add(LabeledEdit4->Text);
Memo1->Lines->Add(LabeledEdit5->Text);
Memo1->Lines->Add(LabeledEdit6->Text);
Memo1->Lines->Add(LabeledEdit7->Text);
Memo1->Lines->Add(ListBox1->Items->Strings[12]);
Memo1->Lines->SaveToFile(SaveDialog1->FileName);

}
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->Timer3->Enabled=true;

}
//---------------------------------------------------------------------------


void __fastcall TForm6::Button11Click(TObject *Sender)
{
Form6->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button10Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
if (OpenDialog1->Execute())
{
Form6->Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
/* initialize init status */
Form3->Edit1->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
Form3->Edit2->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
Form3->Edit3->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
Form3->Edit4->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
Form3->Edit1->Font->Name=Form6->Memo1->Lines->Strings[1];
Form3->Edit1->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
Form3->Edit1->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
Form3->Edit1->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
Form3->Edit2->Font->Name=Form6->Memo1->Lines->Strings[1];
Form3->Edit2->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
Form3->Edit2->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
Form3->Edit2->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
Form3->Edit3->Font->Name=Form6->Memo1->Lines->Strings[1];
Form3->Edit3->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
Form3->Edit3->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
Form3->Edit3->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
Form3->Edit4->Font->Name=Form6->Memo1->Lines->Strings[1];
Form3->Edit4->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
Form3->Edit4->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
Form3->Edit4->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
Form3->ListBox2->Color=StrToInt(Form6->Memo1->Lines->Strings[5]);
Form3->ListBox2->Font->Name=Form6->Memo1->Lines->Strings[6];
Form3->ListBox2->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[7]);
Form3->ListBox2->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[8]);
Form3->ListBox2->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[9]);
Form3->Color=StrToInt(Form6->Memo1->Lines->Strings[10]);
Form3->Font->Name=Form6->Memo1->Lines->Strings[11];
Form3->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[12]);
Form3->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[13]);
Form3->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[14]);
Form3->StatusBar1->Color=StrToInt(Form6->Memo1->Lines->Strings[15]);
Form3->StatusBar1->Font->Name=Form6->Memo1->Lines->Strings[16];
Form3->StatusBar1->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[17]);
Form3->StatusBar1->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[18]);
Form3->StatusBar1->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[19]);
Form3->AlphaBlendValue=StrToInt(Form6->Memo1->Lines->Strings[20]);
Form3->Timer2->Interval=StrToInt(Form6->Memo1->Lines->Strings[21]);
Form3->Image3->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[22]);
Form6->Image1->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[22]);
Form6->LabeledEdit2->Text=Form6->Memo1->Lines->Strings[22];
Form3->Image2->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[23]);
Form3->Image10->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[24]);
Form3->Image9->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[25]);
Form3->Image8->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[26]);
Form3->Image4->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[27]);
Form3->Image5->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[28]);
Form3->Image6->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[29]);
Form3->Image7->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[30]);
Form3->Image11->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[31]);
Form3->Image12->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[32]);
Form3->Image13->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[33]);
Form3->Image14->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[34]);
Form3->multiplybkg=StrToInt(Form6->Memo1->Lines->Strings[35]);
Form6->CheckBox2->Checked=Form3->multiplybkg;
Form6->CheckBox1->Checked=StrToInt(Form6->Memo1->Lines->Strings[36]);
Form6->CheckBox3->Checked=StrToInt(Form6->Memo1->Lines->Strings[37]);
Form6->LabeledEdit4->Text=Form6->Memo1->Lines->Strings[38];
Form6->LabeledEdit5->Text=Form6->Memo1->Lines->Strings[39];
Form6->LabeledEdit6->Text=Form6->Memo1->Lines->Strings[40];
Form6->LabeledEdit7->Text=Form6->Memo1->Lines->Strings[41];
Form3->ListBox2->Width=StrToInt(Form6->LabeledEdit4->Text);
Form3->ListBox2->Height=StrToInt(Form6->LabeledEdit5->Text);
Form3->Image1->Width=StrToInt(Form6->LabeledEdit6->Text);
Form3->Image1->Height=StrToInt(Form6->LabeledEdit7->Text);
Form3->Image1->Left=StrToInt(Form6->LabeledEdit4->Text);
Form3->Height=Form3->ListBox2->Top+Form3->ListBox2->Height+80;
Form3->Width=Form3->ListBox2->Width;
Form3->TrackBar2->Width=Form3->ListBox2->Width;
Form3->Image4->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image5->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image6->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image7->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image11->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image15->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image12->Left=Form3->ListBox2->Width+10;
Form3->Image13->Left=Form3->ListBox2->Width+Form3->Image12->Width+15;
Form3->Image14->Left=Form3->ListBox2->Width+Form3->Image12->Width+Form3->Image13->Width+20;
Form3->Image12->Top=Form3->Image1->Height+20;
Form3->Image13->Top=Form3->Image1->Height+20;
Form3->Image14->Top=Form3->Image1->Height+20;
Form3->TrackBar1->Top=Form3->Image1->Height+20;
Form3->Edit1->Top=Form3->Image1->Height+20;
Form3->Edit1->Left=Form3->ListBox2->Width+Form3->Image12->Width+Form3->Image13->Width+Form3->Image14->Width+25;
Form3->TrackBar1->Left=Form3->Edit1->Width+Form3->ListBox2->Width+Form3->Image12->Width+Form3->Image13->Width+Form3->Image14->Width+25;
Form3->Image16->Picture->LoadFromFile("animation\\split.bmp");
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
/* end of init*/
}
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->Timer3->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button8Click(TObject *Sender)
{
Form6->Memo1->Clear();
Form6->Memo1->Lines->LoadFromFile(LabeledEdit3->Text);
/* initialize init status */
Form3->Edit1->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
Form3->Edit2->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
Form3->Edit3->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
Form3->Edit4->Color=StrToInt(Form6->Memo1->Lines->Strings[0]);
Form3->Edit1->Font->Name=Form6->Memo1->Lines->Strings[1];
Form3->Edit1->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
Form3->Edit1->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
Form3->Edit1->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
Form3->Edit2->Font->Name=Form6->Memo1->Lines->Strings[1];
Form3->Edit2->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
Form3->Edit2->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
Form3->Edit2->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
Form3->Edit3->Font->Name=Form6->Memo1->Lines->Strings[1];
Form3->Edit3->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
Form3->Edit3->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
Form3->Edit3->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
Form3->Edit4->Font->Name=Form6->Memo1->Lines->Strings[1];
Form3->Edit4->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[2]);
Form3->Edit4->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[3]);
Form3->Edit4->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[4]);
Form3->ListBox2->Color=StrToInt(Form6->Memo1->Lines->Strings[5]);
Form3->ListBox2->Font->Name=Form6->Memo1->Lines->Strings[6];
Form3->ListBox2->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[7]);
Form3->ListBox2->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[8]);
Form3->ListBox2->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[9]);
Form3->Color=StrToInt(Form6->Memo1->Lines->Strings[10]);
Form3->Font->Name=Form6->Memo1->Lines->Strings[11];
Form3->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[12]);
Form3->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[13]);
Form3->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[14]);
Form3->StatusBar1->Color=StrToInt(Form6->Memo1->Lines->Strings[15]);
Form3->StatusBar1->Font->Name=Form6->Memo1->Lines->Strings[16];
Form3->StatusBar1->Font->Color=StrToInt(Form6->Memo1->Lines->Strings[17]);
Form3->StatusBar1->Font->Charset=StrToInt(Form6->Memo1->Lines->Strings[18]);
Form3->StatusBar1->Font->Size=StrToInt(Form6->Memo1->Lines->Strings[19]);
Form3->AlphaBlendValue=StrToInt(Form6->Memo1->Lines->Strings[20]);
Form3->Timer2->Interval=StrToInt(Form6->Memo1->Lines->Strings[21]);
Form3->Image3->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[22]);
Form6->Image1->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[22]);
Form6->LabeledEdit2->Text=Form6->Memo1->Lines->Strings[22];
Form3->Image2->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[23]);
Form3->Image10->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[24]);
Form3->Image9->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[25]);
Form3->Image8->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[26]);
Form3->Image4->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[27]);
Form3->Image5->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[28]);
Form3->Image6->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[29]);
Form3->Image7->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[30]);
Form3->Image11->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[31]);
Form3->Image12->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[32]);
Form3->Image13->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[33]);
Form3->Image14->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[34]);
Form3->multiplybkg=StrToInt(Form6->Memo1->Lines->Strings[35]);
Form6->CheckBox2->Checked=Form3->multiplybkg;
Form6->CheckBox1->Checked=StrToInt(Form6->Memo1->Lines->Strings[36]);
Form6->CheckBox3->Checked=StrToInt(Form6->Memo1->Lines->Strings[37]);
Form6->LabeledEdit4->Text=Form6->Memo1->Lines->Strings[38];
Form6->LabeledEdit5->Text=Form6->Memo1->Lines->Strings[39];
Form6->LabeledEdit6->Text=Form6->Memo1->Lines->Strings[40];
Form6->LabeledEdit7->Text=Form6->Memo1->Lines->Strings[41];
Form3->Image15->Picture->LoadFromFile(Form6->Memo1->Lines->Strings[42]);
Form3->ListBox2->Width=StrToInt(Form6->LabeledEdit4->Text);
Form3->ListBox2->Height=StrToInt(Form6->LabeledEdit5->Text);
Form3->Image1->Width=StrToInt(Form6->LabeledEdit6->Text);
Form3->Image1->Height=StrToInt(Form6->LabeledEdit7->Text);
Form3->Image1->Left=StrToInt(Form6->LabeledEdit4->Text);
Form3->Height=Form3->ListBox2->Top+Form3->ListBox2->Height+80;
Form3->Width=Form3->ListBox2->Width;
Form3->TrackBar2->Width=Form3->ListBox2->Width;
Form3->Image4->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image5->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image6->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image7->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image11->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image15->Top=Form3->ListBox2->Top+Form3->ListBox2->Height+2;
Form3->Image12->Left=Form3->ListBox2->Width+10;
Form3->Image13->Left=Form3->ListBox2->Width+Form3->Image12->Width+15;
Form3->Image14->Left=Form3->ListBox2->Width+Form3->Image12->Width+Form3->Image13->Width+20;
Form3->Image12->Top=Form3->Image1->Height+20;
Form3->Image13->Top=Form3->Image1->Height+20;
Form3->Image14->Top=Form3->Image1->Height+20;
Form3->TrackBar1->Top=Form3->Image1->Height+20;
Form3->Edit1->Top=Form3->Image1->Height+20;
Form3->Edit1->Left=Form3->ListBox2->Width+Form3->Image12->Width+Form3->Image13->Width+Form3->Image14->Width+25;
Form3->TrackBar1->Left=Form3->Edit1->Width+Form3->ListBox2->Width+Form3->Image12->Width+Form3->Image13->Width+Form3->Image14->Width+25;
Form3->Image16->Picture->LoadFromFile("animation\\split.bmp");
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
Form3->Image16->Picture->LoadFromFile("animation\\split.bmp");
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Button12Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
if (OpenDialog1->Execute())
{
LabeledEdit3->Text=OpenDialog1->FileName;
Form6->Memo2->Clear();
Form6->Memo2->Lines->Add(Form6->LabeledEdit3->Text);
Form6->Memo2->Lines->Add(Form3->Left);
Form6->Memo2->Lines->Add(Form3->Top);
Form6->Memo2->Lines->SaveToFile("C:\\Program Files\\TDSV\\Jim\\jim.ini");
}
Form3->Timer1->Enabled=true;
Form3->Timer2->Enabled=true;
Form3->Timer3->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::LabeledEdit4Change(TObject *Sender)
{
try
{
if (StrToInt(LabeledEdit4->Text)<209)
{
ShowMessage("Значение должно быть больше или равно 210");
LabeledEdit4->Text=210;
}
}
catch ( EConvertError& ) { ShowMessage("Неверный ввод");}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button13Click(TObject *Sender)
{
Form7->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm6::ComboBox3Change(TObject *Sender)
{
initLang();                   //  //
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Button14Click(TObject *Sender)
{
//Form8->ShowModal();
}
//---------------------------------------------------------------------------



