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
int bounces = 0;
int pointsL = 0;
int pointsR = 0;
char turn = 'L';
bool p1Up = false;
bool p1Down = false;
bool p2Up = false;
bool p2Down = false;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::new_gameClick(TObject *Sender)
{
   new_game->Visible = false;
   lets_play->Visible = false;
   ball_timer->Enabled = true;
   //turaGracza = 'L';
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ball_timerTimer(TObject *Sender)
{
     b->Left += x;
     b->Top += y;

     // odbij od górnej sciany
    if(b->Top-5 <= tlo->Top) y = -y;
     // odbij od dolnej sciany
    if(b->Top+b->Height+5 >= tlo->Height) y = -y;

         //odbcie od lewej paletki
    if (b->Left >= p1->Left
        && b->Left <= p1->Left + p1->Width
        && b->Top >= p1->Top - b->Height/2
        && b->Top <= p1->Top + p1->Height - b->Height/2)
         {
             x = -x;
            bounces++;
           if (p1Up == true) y -= 1;
           if (p1Down == true) y += 1;

           //odbicie na srodku lewej paletki
           if (b->Top+b->Height >= p1->Top + p1->Height/2
               && b->Top <= p1->Top + p1->Height/2)
               x++;
         }

    //skucha po lewej
    if (b->Left < tlo->Left) {
          turn = 'L';
          pointsR++;
          lets_play->Caption = "Punkt dla gracza lewego >";
           //loss();
           //return;
        }

    //odbcie od prawej paletki
    if (b->Left + b->Width >= p2->Left
        && b->Left + b->Width <= p2->Left + p2->Width
        && b->Top >= p2->Top - b->Height/2
        && b->Top <= p2->Top + p2->Height - b->Height/2)
         {
             x = -x;
             bounces++ ;

           if (p2Up == true) y -= 1;
           if (p2Down == true) y += 1;

           //odbicie na srodku paletki
           if (b->Top+b->Height >= p2->Top + p2->Height/2
               && b->Top <= p2->Top + p2->Height/2)
               x--;
         }


    //skucha po prawej 
    if (b->Left+b->Width > tlo->Left+tlo->Width) {
                turn = 'R';
                pointsR++;
                lets_play->Caption = "Punkt dla gracza prawego >";
                //loss();
                //return;
        }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == VK_UP) {
  up_p2_timer->Enabled = true;
   p2Up = true;
  }
  if (Key == VK_DOWN){
   down_p2_timer->Enabled = true;
    p2Down = true;
  }
  if (Key == 'a' || Key == 'A') {
   up_p1_timer->Enabled = true;
     p1Up = true;
  }
  if (Key == 'z' || Key == 'Z'){
  down_p1_timer->Enabled = true;
  p2Down = true;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::up_p1_timerTimer(TObject *Sender)
{
  if (p1->Top  > 10)
  p1->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::down_p1_timerTimer(TObject *Sender)
{
  if (p1->Top + p1->Height <tlo->Height -10)
  p1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::up_p2_timerTimer(TObject *Sender)
{
   if(p2->Top > 10) p2->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::down_p2_timerTimer(TObject *Sender)
{
   if (p2->Top + p2->Height <tlo->Height -10) p2->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == VK_UP){
   up_p2_timer->Enabled = false;
   p2Up = false;
   }
  if (Key == VK_DOWN){
   down_p2_timer->Enabled = false;
   p2Down = false;
   }
  if (Key == 'a' || Key == 'A') {
  up_p1_timer->Enabled = false;
  p1Up = false;
  }
  if (Key == 'z' || Key == 'Z') {
   down_p1_timer->Enabled = false;
   p1Down = false;
   }
}
//---------------------------------------------------------------------------


