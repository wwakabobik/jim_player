//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <MPlayer.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <FileCtrl.hpp>
#include "trayicon.h"
#include <Graphics.hpp>
//---------------------------------------------------------------------------


class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TTrackBar *TrackBar1;
        TEdit *Edit1;
        TTimer *Timer1;
        TMediaPlayer *MediaPlayer1;
        TListBox *ListBox1;
        TOpenDialog *OpenDialog1;
        TListBox *ListBox2;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TTimer *Timer2;
        TMemo *Memo1;
        TOpenDialog *OpenDialog2;
        TTimer *Timer3;
        TEdit *Edit2;
        TEdit *Edit3;
        TTrackBar *TrackBar2;
        TPopupMenu *PopupMenu2;
        TMenuItem *MenuItem1;
        TMenuItem *MenuItem2;
        TCheckBox *CheckBox1;
        TTrayIcon *TrayIcon1;
        TStatusBar *StatusBar1;
        TMediaPlayer *MediaPlayer2;
        TImage *Image3;
        TPopupMenu *PopupMenu3;
        TMenuItem *MenuItem3;
        TMenuItem *MenuItem4;
        TEdit *Edit4;
        TImage *Image2;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        TImage *Image8;
        TImage *Image9;
        TImage *Image10;
        TImage *Image11;
        TImage *Image12;
        TImage *Image13;
        TImage *Image14;
        TImage *Image16;
        TPopupMenu *PopupMenu4;
        TMenuItem *MenuItem5;
        TMenuItem *MenuItem6;
        TMenuItem *N3;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog3;
        TEdit *Edit5;
        TCheckBox *CheckBox2;
        TMenuItem *HTML1;
        TMemo *Memo2;
        TSaveDialog *SaveDialog2;
        TImage *Image15;
        TPopupMenu *PopupMenu5;
        TMenuItem *MenuItem7;
        TMenuItem *MenuItem8;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TPopupMenu *PopupMenu6;
        TMenuItem *MenuItem9;
        TMenuItem *MenuItem10;
        TTimer *Timer4;
        TEdit *Edit6;
        TEdit *Edit7;
        TButton *Button1;
        TListBox *ListBox3;
        TComboBox *MOOD;
        TMenuItem *N7;
        TPanel *CLOSE_BUTTON;
        TImage *BMP_TEMP;
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall Panel3Click(TObject *Sender);
        void __fastcall Panel2Click(TObject *Sender);
        void __fastcall Panel4Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ListBox2DblClick(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall Panel5Click(TObject *Sender);
        void __fastcall Panel6Click(TObject *Sender);
        void __fastcall Panel8Click(TObject *Sender);
        void __fastcall Panel9Click(TObject *Sender);
        void __fastcall Timer3Timer(TObject *Sender);
        void __fastcall Edit3Click(TObject *Sender);
        void __fastcall Panel7Click(TObject *Sender);
        void __fastcall Panel10Click(TObject *Sender);
        void __fastcall MenuItem1Click(TObject *Sender);
        void __fastcall MenuItem2Click(TObject *Sender);
        void __fastcall ListBox2KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall MenuItem3Click(TObject *Sender);
        void __fastcall MenuItem4Click(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall Image11Click(TObject *Sender);
        void __fastcall Image7Click(TObject *Sender);
        void __fastcall MenuItem5Click(TObject *Sender);
        void __fastcall MenuItem6Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall HTML1Click(TObject *Sender);
        void __fastcall MenuItem7Click(TObject *Sender);
        void __fastcall MenuItem8Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall MenuItem10Click(TObject *Sender);
        void __fastcall MenuItem9Click(TObject *Sender);
        void __fastcall Timer4Timer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall CLOSE_BUTTONClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
//        friend void __fastcall initLang();
          void __fastcall TForm3::WMHotKey(TWMHotKey&);
          void __fastcall TForm3::WMDROPFILES(TMessage&);
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
        double timetoplay; // время проигрывания
        int musstat;     // позиция проигрывания
        int multiplybkg; // размножать фон
        AnsiString BOO;
        bool cashstat;
        int itemscount;
        //WideString exec; // строка запуска
        AnsiString E4T,SBT; // строка скролла
        int randstat;     // позиция рандомизации
        int *randommus;     // массив рандомизации
        AnsiString InitDirectory;
                BEGIN_MESSAGE_MAP
                MESSAGE_HANDLER(WM_HOTKEY,TWMHotKey,WMHotKey); // инициализация HotKey
                MESSAGE_HANDLER(WM_DROPFILES,TMessage,WMDROPFILES); //инициализация перетаскивания файлов
        END_MESSAGE_MAP(TComponent);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
