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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TShape *p1;
        TShape *p2;
        TImage *b;
        TStaticText *zagrajmy;
        TBitBtn *nowa;
        TStaticText *score;
        TStaticText *odbicia;
        TBitBtn *next;
        TTimer *Timer_pilka;
        TTimer *gora1;
        TTimer *dol1;
        TTimer *gora2;
        TTimer *dol2;
        void __fastcall nowaClick(TObject *Sender);
        void __fastcall Timer_pilkaTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall gora1Timer(TObject *Sender);
        void __fastcall dol1Timer(TObject *Sender);
        void __fastcall gora2Timer(TObject *Sender);
        void __fastcall dol2Timer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 