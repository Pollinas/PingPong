//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8 ;
int iloscOdbic = 0;
int punktyL = 0;
int punktyP = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nowaClick(TObject *Sender)
{
   nowa->Visible = false;
   zagrajmy->Visible = false;
   Timer_pilka->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
     b->Left += x;
     b->Top += y;

     // odbij od górnej sciany
    if(b->Top-5 <= tlo->Top) y = -y;
     // odbij od dolnej sciany
    if(b->Top+b->Height+5 >= tlo->Height) y = -y;

    //skucha
    if((b->Left-5 <= p1->Left-p1->Width-5)
        ||(b->Left+b->Width+5 >=  p2->Left+5))
         {
            Timer_pilka->Enabled = false;
            b->Visible = false;
            score->Visible = true;
            odbicia->Visible = true;
            next->Visible = true;
            nowa->Visible = true;
            zagrajmy->Visible = true; zagrajmy->Caption="Punkt dla gracza";
         }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == VK_UP) gora2->Enabled = true;
  if (Key == VK_DOWN) dol2->Enabled = true;
  if (Key == 'a' || Key == 'A') gora1->Enabled = true;
  if (Key == 'z' || Key == 'Z') dol1->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::gora1Timer(TObject *Sender)
{
  p1->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::dol1Timer(TObject *Sender)
{
  p1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::gora2Timer(TObject *Sender)
{
   p2->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::dol2Timer(TObject *Sender)
{
   p2->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == VK_UP) gora2->Enabled = false;
  if (Key == VK_DOWN) dol2->Enabled = false;
  if (Key == 'a' || Key == 'A') gora1->Enabled = false;
  if (Key == 'z' || Key == 'Z') dol1->Enabled = false;
}
//---------------------------------------------------------------------------

