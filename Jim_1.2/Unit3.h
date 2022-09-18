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
//---------------------------------------------------------------------------


class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TTrackBar *TrackBar1;
        TEdit *Edit1;
        TImage *Image2;
        TTimer *Timer1;
        TLabel *Label2;
        TLabel *Label1;
        TLabel *Label3;
        TMediaPlayer *MediaPlayer1;
        TListBox *ListBox1;
        TOpenDialog *OpenDialog1;
        TListBox *ListBox2;
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TTimer *Timer2;
        TMemo *Memo1;
        TPanel *Panel5;
        TPanel *Panel6;
        TPanel *Panel8;
        TPanel *Panel9;
        TOpenDialog *OpenDialog2;
        TTimer *Timer3;
        TEdit *Edit2;
        TEdit *Edit3;
        TLabel *Label17;
        TTrackBar *TrackBar2;
        TPanel *Panel7;
        TPanel *Panel10;
        TPopupMenu *PopupMenu2;
        TMenuItem *MenuItem1;
        TMenuItem *MenuItem2;
        TCheckBox *CheckBox1;
        TTrayIcon *TrayIcon1;
        TStatusBar *StatusBar1;
        TMediaPlayer *MediaPlayer2;
        TPopupMenu *PopupMenu3;
        TMenuItem *MenuItem3;
        TMenuItem *MenuItem4;
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
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
        double timetoplay;
        int musstat;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
