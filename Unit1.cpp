//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -6;
int y = -6 ;
int bounces = 0;
int pointsL = 0;
int pointsR = 0;

bool p1Up = false;
bool p1Down = false;
bool p2Up = false;
bool p2Down = false;

void out(){
     Form1->ball_timer->Enabled = false;
     Form1->b->Visible = false;
     Form1->lets_play->Visible = true;
     Form1->odbicia->Caption="Iloœæ odbiæ: " + IntToStr(bounces); Form1->odbicia->Visible = true;
     Form1->score->Caption = IntToStr(pointsL)+" : "+IntToStr(pointsR);
     Form1->score->Visible = true;
     Form1->next_round->Visible = true;
     Form1->new_game->Visible = true;
}

void nextRound(){
     //przywrocenie ustawienia pilki
     Form1->b->Left = Form1->tlo->Width/2 - Form1->b->Width/2;
     Form1->b->Top =  Form1->tlo->Height/2 - Form1->b->Height/2;

     x=-6;y=-6;
     bounces = 0;
     Form1->ball_timer->Enabled = true;
     Form1->b->Visible = true;
     Form1->lets_play->Visible = false;
     Form1->odbicia->Visible = false;
     Form1->score->Visible = false;
     Form1->next_round->Visible = false;
     Form1->new_game->Visible = false;

}

void newGame(){
   nextRound();
   pointsR = 0; pointsL =0;
}

void cornerHit(){
   int aux = x;

   if (x*y >= 0) {
      x = -y ;
      y = -aux;
   }

   if (x*y < 0) {
       x = y ;
       y = aux;
   }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::new_gameClick(TObject *Sender)
{
    if(pointsR!=0 || pointsL!=0) {
       if(Application->MessageBox("Czy na pewno chcesz zacz¹æ od nowa?", "PotwierdŸ",
       MB_YESNO | MB_ICONQUESTION) == IDYES) newGame();
       }

     else newGame();
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
    // odbicie od rogu lewej paletki
     if (b->Left >= p1->Left && b->Left <= p1->Left + p1->Width
        && ((y<0 && (b->Top > p1->Top + p1->Height - b->Height/2)
        && (b->Top <= p1->Top + p1->Height))
        || (y>=0 && (b->Top < p1->Top - b->Height/2)
        && (b->Top + b->Height >=  p1->Top) ))){

        bounces++;
        cornerHit();
     }

    //skucha po lewej
    if (b->Left < tlo->Left) {
          pointsR++;
          lets_play->Caption = "Punkt dla gracza lewego >";
          out();
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

     // odbicie od rogu prawej paletki
         if (b->Left+ b->Width <= p2->Left + p2->Width
            && b->Left + b->Width >= p2->Left
            && ((y<0 && (b->Top > p2->Top + p2->Height - b->Height/2)
            && (b->Top <= p2->Top + p2->Height))
            || (y>=0 && (b->Top < p2->Top - b->Height/2)
            && (b->Top + b->Height >=  p2->Top) ))){

        bounces++;
        cornerHit();
     }

    //skucha po prawej 
    if (b->Left+b->Width > tlo->Left+tlo->Width) {

                pointsL++;
                lets_play->Caption = "Punkt dla gracza prawego >";
                 out();

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


void __fastcall TForm1::next_roundClick(TObject *Sender)
{
     nextRound();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  if (Application->MessageBoxA("Czy na pewno zakoñczyæ program?", "PotwierdŸ",
      MB_YESNO | MB_ICONQUESTION) == IDNO)
      {
        Action = caNone;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   if (Application->MessageBoxA(" Witaj w grze PingPong.\n\n"
        "Lewy gracz steruje wciskaj¹c klawisze A oraz Z.\n"
        "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³.\n\n"
        "Dla urozmaiecenia zabawy :\n"
        "Kiedy odbijesz pi³kê na œrodku paletki, wówczas zmienisz jej k¹t odbiciai pi³ka przypieszy.\n"
        "Im d³u¿ej odbijasz, tym pi³ka szybciej przemieszcza siê.\n\n"
        "Mi³ej zabawy!\n\n",
        "PingPong", MB_OK | MB_ICONQUESTION) == IDOK )
        {
         Form1-> Visible = true;
        }
}
//---------------------------------------------------------------------------

