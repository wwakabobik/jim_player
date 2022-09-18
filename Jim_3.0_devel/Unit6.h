//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TButton *Button1;
        TMemo *Memo1;
        TButton *Button2;
        TButton *Button3;
        TEdit *Edit1;
        TLabel *Label1;
        TButton *Button4;
        TComboBox *ComboBox1;
        TLabeledEdit *LabeledEdit1;
        TButton *Button5;
        TLabeledEdit *LabeledEdit2;
        TButton *Button6;
        TOpenPictureDialog *OpenPictureDialog1;
        TImage *Image1;
        TComboBox *ComboBox2;
        TImage *Image2;
        TButton *Button7;
        TCheckBox *CheckBox2;
        TListBox *ListBox1;
        TButton *Button8;
        TButton *Button9;
        TButton *Button10;
        TButton *Button11;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TOpenPictureDialog *OpenPictureDialog2;
        TLabeledEdit *LabeledEdit3;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox3;
        TButton *Button12;
        TMemo *Memo2;
        TLabeledEdit *LabeledEdit4;
        TLabeledEdit *LabeledEdit5;
        TLabeledEdit *LabeledEdit6;
        TLabeledEdit *LabeledEdit7;
        TComboBox *ComboBox3;
        TButton *Button13;
        TCheckBox *CheckBox4;
        TButton *Button14;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall CheckBox2Enter(TObject *Sender);
        void __fastcall CheckBox2Exit(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall LabeledEdit4Change(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall ComboBox3Change(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
