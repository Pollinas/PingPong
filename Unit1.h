//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TShape *p1;
        TShape *p2;
        TImage *b;
        TStaticText *lets_play;
        TBitBtn *new_game;
        TStaticText *score;
        TStaticText *odbicia;
        TBitBtn *next_round;
        TTimer *ball_timer;
        TTimer *up_p1_timer;
        TTimer *down_p1_timer;
        TTimer *up_p2_timer;
        TTimer *down_p2_timer;
        TShape *Shape1;
        void __fastcall new_gameClick(TObject *Sender);
        void __fastcall ball_timerTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall up_p1_timerTimer(TObject *Sender);
        void __fastcall down_p1_timerTimer(TObject *Sender);
        void __fastcall up_p2_timerTimer(TObject *Sender);
        void __fastcall down_p2_timerTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall next_roundClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 