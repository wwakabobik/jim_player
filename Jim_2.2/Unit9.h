//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TRadioButton *RadioButton9;
        TRadioButton *RadioButton10;
        TPanel *Panel1;
        TListBox *ListBox2;
        TListBox *ListBox1;
        TPanel *Panel2;
        TPanel *Panel3;
        void __fastcall RadioButton1Enter(TObject *Sender);
        void __fastcall RadioButton2Enter(TObject *Sender);
        void __fastcall RadioButton3Enter(TObject *Sender);
        void __fastcall RadioButton4Enter(TObject *Sender);
        void __fastcall RadioButton5Enter(TObject *Sender);
        void __fastcall RadioButton6Enter(TObject *Sender);
        void __fastcall RadioButton7Enter(TObject *Sender);
        void __fastcall RadioButton8Enter(TObject *Sender);
        void __fastcall RadioButton9Enter(TObject *Sender);
        void __fastcall RadioButton10Enter(TObject *Sender);
        void __fastcall Panel3Click(TObject *Sender);
        void __fastcall Panel2Click(TObject *Sender);
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall ListBox2KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
