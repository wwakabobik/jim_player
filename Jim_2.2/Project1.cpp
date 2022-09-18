//---------------------------------------------------------------------------

#include <vcl.h>
#include "Unit3.h"

//#include "PreUnit3.cpp"
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit4.cpp", Form4);
USEFORM("Unit5.cpp", Form5);
USEFORM("Unit6.cpp", Form6);
USEFORM("Unit7.cpp", Form7);
USEFORM("Unit9.cpp", Form1);
//---------------------------------------------------------------------------
#include "Unit3.cpp"
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR S, int)
{
       exec=S;
       try
        {
                 Application->Initialize();
                 Application->Title = "Джим 2.2";
                 Application->HelpFile = "Джим.pdf";
                 Application->CreateForm(__classid(TForm3), &Form3);
                 Application->CreateForm(__classid(TForm4), &Form4);
                 Application->CreateForm(__classid(TForm5), &Form5);
                 Application->CreateForm(__classid(TForm6), &Form6);
                 Application->CreateForm(__classid(TForm7), &Form7);
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();   //
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
         exec=S;
        return 0;
}
//---------------------------------------------------------------------------
