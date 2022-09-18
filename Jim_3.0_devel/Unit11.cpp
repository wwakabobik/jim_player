//---------------------------------------------------------------------------
#define ID3LIB_LINKOPTION 1
#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#include "library.h"
#include "id3/tag.h"
#include "id3/utils.h"
#include "id3/misc_support.h"
#include "id3/readers.h"
#include "id3/io_helpers.h"
#include "Unit11.h"
//#include "MP3FileInfo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

ID3_Tag myTag;

const char* __fastcall return_ID3v2TAG(char* FileName, ID3_FrameID param)
{
//myTag.Clear();
//myTag.
myTag.Link(FileName, ID3TT_ALL);
ID3_Frame* frame = myTag.Find(param);
ID3_Field* field = 0;
//    if(frame==0) { return 0; }
//    if(!frame->Contains(ID3FN_TEXTENC))
//     { delete frame; return 0; } // frame contains no text
      // look for field type
//    if(frame->Contains(ID3FN_TEXT)) // Text field
//     {
   field = frame->GetField(ID3FN_TEXT);
//    }
//
//    if(frame->Contains(ID3FN_URL) && (field==0)) // URL field
//     { field = frame->GetField(ID3FN_URL); }
//
//    if(field==0) { delete frame; return 0; } // no field found

//    field->SetEncoding(ID3TE_ISO8859_1); // use Latin-1 charset
const char* res = field->GetRawText();
return res;
return 0;
}

void __fastcall TForm11::Button1Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
Form3->Timer4->Enabled=false;
//Form3->Timer5->Enabled=false;
//Form3->Timer6->Enabled=false;

//    myTag.Link(Edit1->Text.c_str(), ID3TT_ALL);
if (OpenDialog1->Execute())
{ }
char* FileName = OpenDialog1->FileName.c_str();
myTag.Clear();
    myTag.Link(FileName, ID3TT_ALL);
    const Mp3_Headerinfo* mp3info;
    mp3info = myTag.GetMp3HeaderInfo();
Memo1->Lines->Add(AnsiString(myTag.GetFileName()));
if (myTag.HasLyrics())
Memo1->Lines->Add("Lyrics : yes");
if (myTag.HasV1Tag())
Memo1->Lines->Add("ID3V1 : yes");
if (myTag.HasV2Tag())
Memo1->Lines->Add("ID3V2 : yes");
Memo1->Lines->Add("Size: "+AnsiString((int)myTag.GetFileSize()));
Memo1->Lines->Add("MPEG: "+AnsiString(mp3info->layer));
Memo1->Lines->Add("Verison: "+AnsiString(mp3info->version));
Memo1->Lines->Add("Bitrate: "+AnsiString(mp3info->bitrate));
Memo1->Lines->Add("Channelmode: "+AnsiString(mp3info->channelmode));
Memo1->Lines->Add("Moeext: "+AnsiString(mp3info->modeext));
Memo1->Lines->Add("Emphasis: "+AnsiString(mp3info->emphasis));
Memo1->Lines->Add("CRC: "+AnsiString(mp3info->crc));
Memo1->Lines->Add("VBR: "+AnsiString(mp3info->vbr_bitrate));
Memo1->Lines->Add("Frequency: "+AnsiString(mp3info->frequency));
Memo1->Lines->Add("Framesize: "+AnsiString(mp3info->framesize));
Memo1->Lines->Add("Frames: "+AnsiString(mp3info->frames));
Memo1->Lines->Add("Time: "+AnsiString(mp3info->time));
//exeption
Memo1->Lines->Add("Channel mode: "+AnsiString(get_channel_mode(mp3info->channelmode)));
Memo1->Lines->Add("Time: "+AnsiString(get_mpeg_version(mp3info->version)));
Memo1->Lines->Add("Time: "+AnsiString(get_layer(mp3info->layer)));
Memo1->Lines->Add("Time: "+AnsiString(get_bitrate(mp3info->bitrate,mp3info->vbr_bitrate)));

//TAG
//Memo1->Lines->Add(AnsiString(getID3v2TAG("ARTIST",AnsiString(myTag.GetFileName()).c_str())));
//Memo1->Lines->Add(AnsiString(getID3v2TAG("TITLE",AnsiString(myTag.GetFileName()).c_str())));
//Memo1->Lines->Add(AnsiString(getID3v2TAG("TRACK",AnsiString(myTag.GetFileName()).c_str())));
//Memo1->Lines->Add(AnsiString(Int(mp3info->privatebit)));
//Memo1->Lines->Add(AnsiString(Int(mp3info->copyrighted)));
//Memo1->Lines->Add(AnsiString(Int(mp3info->original)));
//Memo1->Lines->Add(AnsiString());
//Memo1->Lines->Add(AnsiString());
//  */
/*MP3FileInfo mp3fi;
if (OpenDialog1->Execute())
      if(!mp3fi.Init(OpenDialog1->FileName.c_str()))
Application->Terminate();
      Memo1->Lines->Add(Edit1->Text);
      Memo1->Lines->Add("Filename : " + AnsiString(mp3fi.szFilename));
      Memo1->Lines->Add("Filesize : " + AnsiString(mp3fi.nFileSize));
      Memo1->Lines->Add("ID3 Tags : " + AnsiString((mp3fi.bHasV1Tag?"ID3V1":"")) + AnsiString((mp3fi.bHasV1Tag&mp3fi.bHasV2Tag?" and ":"")) + AnsiString((mp3fi.bHasV2Tag?"ID3V2":"")));
      if(mp3fi.bHasLyrics)
      Memo1->Lines->Add("Lyrics : yes" );
//
//      Memo1->Lines->Add(+ AnsiString());
//      Memo1->Lines->Add(+ AnsiString());
//      Memo1->Lines->Add(+ AnsiString());
//      Memo1->Lines->Add(+ AnsiString());

//      printf("\n  %s:\n", "File");
//      printf("    %-20s : %s\n",        "Filename", mp3fi.szFilename);
//      printf("    %-20s : %i bytes\n",  "Filesize", mp3fi.nFileSize);
//      printf("    %-20s : %s%s%s\n",    "ID3 Tags", (mp3fi.bHasV1Tag?"ID3V1":""), (mp3fi.bHasV1Tag&mp3fi.bHasV2Tag?" and ":""), (mp3fi.bHasV2Tag?"ID3V2":""));
//      if(mp3fi.bHasLyrics)
//       printf("    %-20s : yes\n", "Lyrics");
Memo1->Lines->Add("Header");
Memo1->Lines->Add("MPEG : " + AnsiString(mp3fi.szMpegVersion) + " " +AnsiString(mp3fi.szMpegLayer));
Memo1->Lines->Add("Bitrate : " + AnsiString(mp3fi.szBitRate));
Memo1->Lines->Add("Audio : " + AnsiString(mp3fi.nSampleRate) + "Hz " + AnsiString(mp3fi.szChannelMode));
Memo1->Lines->Add("Length : " + AnsiString(mp3fi.nLength) + " seconds");
//      printf("\n  %s:\n", "Header");
//      printf("    %-20s : %s %s\n",       "MPEG",     mp3fi.szMpegVersion, mp3fi.szMpegLayer);
//      printf("    %-20s : %s\n",          "BitRate",  mp3fi.szBitRate);
//      printf("    %-20s : %iHz %s\n",     "Audio",    mp3fi.nSampleRate, mp3fi.szChannelMode);
//      printf("    %-20s : %i seconds\n",  "Length",   mp3fi.nLength);

Memo1->Lines->Add("Artist : " + AnsiString(mp3fi.szArtist));
Memo1->Lines->Add("Title : " + AnsiString(mp3fi.szTitle));
Memo1->Lines->Add("Track : " + AnsiString(mp3fi.nTrack));
Memo1->Lines->Add("Album : " + AnsiString(mp3fi.szAlbum));
Memo1->Lines->Add("Year : " + AnsiString(mp3fi.nYear));
Memo1->Lines->Add("Genre : " + AnsiString(mp3fi.szGenre));
Memo1->Lines->Add("Comment : " + AnsiString(mp3fi.szComment));
Memo1->Lines->Add("Composer : " + AnsiString(mp3fi.szComposer));
Memo1->Lines->Add("Encoded by : " + AnsiString(mp3fi.szEncodedBy));
Memo1->Lines->Add("Original Artist : " + AnsiString(mp3fi.szOriginalArtist));
Memo1->Lines->Add("URL : " + AnsiString(mp3fi.szURL));
Memo1->Lines->Add("Copyright : " + AnsiString(mp3fi.szCopyright));
/*
      if(mp3fi.bHasV1Tag || mp3fi.bHasV2Tag)
       {
        heading("ID3V1 Tag (and up)");
        listUp("Artist",  mp3fi.szArtist);
        listUp("Title",   mp3fi.szTitle);
        listUp("Track",   mp3fi.nTrack);
        listUp("Album",   mp3fi.szAlbum);
        listUp("Year",    mp3fi.nYear);
        listUp("Genre",   mp3fi.szGenre);
        listUp("Comment", mp3fi.szComment);
       }

      if(mp3fi.bHasV2Tag)
       {
        heading("V2 specific");
        listUp("Composer", mp3fi.szComposer);
        listUp("Encoded By", mp3fi.szEncodedBy);
        listUp("Original Artist", mp3fi.szOriginalArtist);
        listUp("URL", mp3fi.szURL);
        listUp("Copyright", mp3fi.szCopyright);
       }

      printf("\n");
      printf("Press any key to continue\n");
      _getch(); */

}
//---------------------------------------------------------------------------
void __fastcall TForm11::Button2Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
Form3->Timer4->Enabled=false;
if (OpenDialog1->Execute())
{ }
char* FileName = OpenDialog1->FileName.c_str();
//myTag.Clear();
myTag.Link(FileName, ID3TT_ALL);
if (myTag.HasV1Tag() || myTag.HasV2Tag())
{
Memo1->Lines->Add("Artist: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_LEADARTIST)));
Memo1->Lines->Add("Title: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_TITLE)));
Memo1->Lines->Add("Album: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_ALBUM)));
Memo1->Lines->Add("Year: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_YEAR)));
Memo1->Lines->Add("Comment: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_COMMENT)));
//Memo1->Lines->Add("Track No: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_TRACKNUM)));
}
if (myTag.HasV2Tag())
{
Memo1->Lines->Add("Composer: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_COMPOSER)));
Memo1->Lines->Add("Copyright: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_COPYRIGHT)));
Memo1->Lines->Add("Encoded by: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_ENCODEDBY)));
Memo1->Lines->Add("Orig. Artist: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_ORIGARTIST)));
Memo1->Lines->Add("URL: "+AnsiString(return_ID3v2TAG(FileName,ID3FID_WWWUSER)));
}   // 
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button3Click(TObject *Sender)
{
Form3->Timer1->Enabled=false;
Form3->Timer2->Enabled=false;
Form3->Timer3->Enabled=false;
Form3->Timer4->Enabled=false;

if (OpenDialog1->Execute())
{ }
char* FileName = OpenDialog1->FileName.c_str();
myTag.Clear();
    myTag.Link(FileName, ID3TT_ALL);
    const Mp3_Headerinfo* mp3info;
    mp3info = myTag.GetMp3HeaderInfo();
Memo1->Lines->Add("Time: "+AnsiString(mp3info->time));
Memo1->Lines->Add("Time: "+AnsiString(get_bitrate(mp3info->bitrate,mp3info->vbr_bitrate)));
}
//---------------------------------------------------------------------------

