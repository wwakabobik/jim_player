//---------------------------------------------------------------------------

#ifndef logo_unitH
#define logo_unitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TLOGO : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TTimer *Timer1;
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TLOGO(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLOGO *LOGO;
//---------------------------------------------------------------------------
#endif
