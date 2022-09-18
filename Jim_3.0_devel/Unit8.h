//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TTable *Table1;
        TQuery *Query1;
        TDBGrid *DBGrid2;
        TDataSource *DataSource2;
        TComboBox *ComboBox1;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TDBNavigator *DBNavigator1;
        TDBGrid *DBGrid1;
        TButton *Button1;
        TLabeledEdit *LabeledEdit3;
        TLabeledEdit *LabeledEdit5;
        TButton *Button2;
        TEdit *Edit1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
