// ---------------------------------------------------------------------------
/*
 https://github.com/botbead
 2020-07-26
 */

#include <fmx.h>
#pragma hdrstop

#include "MessageManager.h"
#include "MessageSubscriber.h"
#include <System.Messaging.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	(new TForm2(Application))->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Memo1ChangeTracking(TObject *Sender) {
	TMessageManager::DefaultManager->SendMessage(this,
		new TMessage__1<UnicodeString>(Memo1->Lines->Text), true);
}
// ---------------------------------------------------------------------------
