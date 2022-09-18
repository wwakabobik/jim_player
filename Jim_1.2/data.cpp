//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <string.h>
#include <SysUtils.hpp>
#pragma hdrstop
#include "library.h"
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
        return 1;
}

char* translate(AnsiString convert)
{
AnsiString input = AnsiString(convert);
if (input=="Afrikaans") return("Ek het jou liefe");
if (input=="Albanian") return("Te dua");
if (input=="Portugal") return("Gosto De Ti, Porra!");
if (input=="Alsacien") return("Ich hoan dich gear");
if (input=="Amharic") return("Afekrishalehou");
if (input=="Arabic") return("Ana Behibek");
if (input=="Assamese") return("Moi tomak bhal pau");
if (input=="Basc") return("Nere Maitea");
if (input=="Batak") return("Holong rohangku di ho");
if (input=="Bavarian") return("I mog di narrisch gern");
if (input=="Bengali") return("Ami tomAy bhAlobAshi");
if (input=="Berber") return("Lakh tirikh");
if (input=="Bicol") return("Namumutan ta ka");
if (input=="Bolivian") return("Quechua qanta munani");
if (input=="Bulgarian") return("Obicham te");
if (input=="Burmese") return("Chit pa de");
if (input=="Cambodian") return("Bon sro lanh oon");
if (input=="Cantonese") return("Moi oiy neya");
if (input=="Catalan") return("T'estim");
if (input=="Cebuano") return("Gihigugma ko ikaw");
if (input=="Chickasaw") return("Chiholloli");
if (input=="Corsican") return("Ti tengu cara");
if (input=="Croatian") return("LJUBim te");
if (input=="Czech") return("Miluji te");
if (input=="Danish") return("Jeg elsker dig");
if (input=="Dutch") return("Ik hou van jou");
if (input=="Ecuador") return("Quechua canda munani");
if (input=="English") return("I love you");
if (input=="Esperanto") return("Mi amas vin");
if (input=="Estonian") return("Mina armastan sind");
if (input=="Farsi") return("Tora dust midaram");
if (input=="Filipino") return("Mahal kita");
if (input=="Finnish") return("Mina rakastan sinua");
if (input=="Flemish") return("Ik zie oe geerne");
if (input=="French") return("Je t'aime");
if (input=="Friesian") return("Ik hald fan dei");
if (input=="Gaelic") return("Ta gra agam ort");
if (input=="German") return("Ich liebe Dich");
if (input=="Georgian") return("Mikvarkhar");
if (input=="Greek") return("s'ayapo");
if (input=="Greek (old)") return("(Ego) philo su");
if (input=="Greenlandic") return("Asavakit");
if (input=="Gujrati") return("Hoon tane pyar karoochhoon");
if (input=="Hausa") return("Ina sonki");
if (input=="Hawaiian") return("Aloha I'a Au Oe");
if (input=="Hebrew") return("Ani ohev otach");
if (input=="Hindi") return("Mai tumase pyar karata hun");
if (input=="Hokkien") return("Wa ai lu");
if (input=="Hopi") return("Nu' umi unangwa'ta");
if (input=="Hungarian") return("Szeretlek");
if (input=="Icelandic") return("Eg elska thig");
if (input=="Indi") return("Mai Tujhe Pyaar Kartha Ho");
if (input=="Indonesian") return("Saya cinta padamu");
if (input=="Iranian") return("Mahn doostaht doh-rahm");
if (input=="Irish") return("Taim i' ngra leat");
if (input=="Italian") return("Ti amo");
if (input=="Japanese") return("Kimi o ai shiteru");
if (input=="Javanese") return("Kulo tresno");
if (input=="Kabardinian") return("Sa wa fuwa uzohyau");
if (input=="Kanada") return("Naanu Ninnanu Preethisuthene");
if (input=="Kiswahili") return("Nakupenda");
if (input=="Klingon") return("Qabang");
if (input=="Korean") return("No-rul sarang hae");
if (input=="Lao") return("Koi muk jao");
if (input=="Latin") return("Te amo");
if (input=="Latin (old)") return("(Ego) amo te");
if (input=="Latvian") return("Es milu tevi");
if (input=="Lebanese") return("Bahibak");
if (input=="Lingala") return("Nalingi yo");
if (input=="Lisbon") return("Lingo gramo-te bue, chavalinha");
if (input=="Lithuanian") return("Ta-ve mee-lyu");
if (input=="Lojban") return("Mi do prami");
if (input=="Luo") return("Aheri");
if (input=="Macedonian") return("SAKAM TE!");
if (input=="Madrid lingo") return("Me molas, tronca");
if (input=="Malay") return("Saya cintakan mu");
if (input=="Malayalam") return("Njyaan Ninne' Preetikyunnu");
if (input=="Malaysian") return("Saya Cintamu");
if (input=="Mandarin") return("Wo ai ni");
if (input=="Marathi") return("Me tujhashi prem karto");
if (input=="Mohawk") return("Konoronhkwa");
if (input=="Navaho") return("Ayor anosh'ni");
if (input=="Ndebele") return("Niyakutanda");
if (input=="Norwegian") return("Eg elskar deg");
if (input=="Op Op") return("Lopveop Yopuop");
if (input=="Osetian") return("Aez dae warzyn");
if (input=="Pakistani") return("Mujhe Tumse Muhabbat Hai");
if (input=="Persian") return("Tora dost daram");
if (input=="Pig Latin") return("Ie Ovele Ouye");
if (input=="Polish") return("Kocham Cie");
if (input=="Portuguese") return("Amo-te");
if (input=="Portuguese (Brazilian)") return("Eu te amo");
if (input=="Punjabi") return("Mai taunu pyar karda");
if (input=="Quenya") return("Tye-mela'ne");
if (input=="Romanian") return("Te iu besc");
if (input=="Romanian") return("Te Ador");
if (input=="Russian") return("Я тебя люблю");
if (input=="Scot Gaelic") return("Tha gradh agam ort");
if (input=="Serbian") return("ljubim te");
if (input=="Spanish") return("ly'ish (Te amo)");
if (input=="Serbocroatian") return("Volim te");
if (input=="Shona") return("Ndinokuda");
if (input=="Sinhalese") return("Mama oyata adarei");
if (input=="Sioux") return("Techihhila");
if (input=="Slovak") return("Lubim ta");
if (input=="Slovene") return("Ljubim te");
if (input=="Srilankan") return("Mama Oyata Arderyi");
if (input=="Swahili") return("Naku penda");
if (input=="Swedish") return("Jag a'lskar dig");
if (input=="Swiss-German") return("Ch'ha di ga'rn");
if (input=="Syrian/Lebanese") return("BHEBBEK");
if (input=="Tagalog") return("Mahal kita");
if (input=="Tahitian") return("Ua Here Vau Ia Oe");
if (input=="Tamil") return("n'An unnaik kAthalikkinREn");
if (input=="Tatar") return("Min sine jaratam");
if (input=="Tcheque") return("MILUJI TE");
if (input=="Telugu") return("Neenu ninnu pra'mistu'nnanu");
if (input=="Thai") return("Khao Raak Thoe");
if (input=="Tunisian") return("Ha eh bak");
if (input=="Turkish") return("Seni seviyorum");
if (input=="Ukrainian") return("Я тебе кохаю");
if (input=="Urdu") return("Mujhe tumse mohabbat hai");
if (input=="Uzbekski") return("Men senga sevaman");
if (input=="Vietnamese") return("Anh ye'u em");
if (input=="Vlaams") return("Ik hue van ye");
if (input=="Vulcan") return("Wani ra yana ro aisha");
if (input=="Welsh") return("'Rwy'n dy garu di");
if (input=="Yiddish") return("Ich libe dich");
if (input=="Yugoslavian") return("Ya te volim");
if (input=="Zazi") return("Ezhele hezdege");
if (input=="Zulu") return("Mena Tanda Wena");
if (input=="Zuni") return("Tom ho' ichema");
}

int binaryconvert(char bukva, int i)
{
int x=bukva, z;
z = (x>>i&1);
return z;
}

inline char dectohex (int covnum)
{
if (covnum ==0) return '0';
else if (covnum ==1) return '1';
else if (covnum == 2) return '2';
else if (covnum == 3) return '3';
else if (covnum == 4) return '4';
else if (covnum == 5) return '5';
else if (covnum == 6) return '6';
else if (covnum == 7) return '7';
else if (covnum == 8) return '8';
else if (covnum == 9) return '9';
else if (covnum == 10) return 'A';
else if (covnum == 11) return 'B';
else if (covnum == 12) return 'C';
else if (covnum == 13) return 'D';
else if (covnum == 14) return 'E';
else if (covnum == 15) return 'F';
}

WideString hexconvert(int gchar)
{
WideString returnme="000";
int i=3,tempnum;
while (i!=0)
{
tempnum=gchar%16;
gchar/=16;
returnme[i]=dectohex(tempnum);
i--;
}
return returnme;
}
//---------------------------------------------------------------------------
