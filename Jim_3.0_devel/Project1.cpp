//---------------------------------------------------------------------------
#define ID3LIB_LINKOPTION 1
#include <vcl.h>
#include "Unit3.h"
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit4.cpp", Form4);
USEFORM("Unit5.cpp", Form5);
USEFORM("Unit6.cpp", Form6);
USEFORM("Unit7.cpp", Form7);
USEFORM("Unit8.cpp", Form8);
USEFORM("Unit11.cpp", Form11);
USEFORM("logo_unit.cpp", LOGO);
USEFORM("Unit9.cpp", Form9);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Джим 3.0";
                 Application->HelpFile = "Джим.pdf";
                 Application->CreateForm(__classid(TForm3), &Form3);
                 Application->CreateForm(__classid(TForm4), &Form4);
                 Application->CreateForm(__classid(TForm5), &Form5);
                 Application->CreateForm(__classid(TForm6), &Form6);
                 Application->CreateForm(__classid(TForm7), &Form7);
                 Application->CreateForm(__classid(TForm8), &Form8);
                 Application->CreateForm(__classid(TForm11), &Form11);
                 Application->CreateForm(__classid(TLOGO), &LOGO);
                 Application->CreateForm(__classid(TForm9), &Form9);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
