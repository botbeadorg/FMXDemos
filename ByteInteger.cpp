// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ByteInteger.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;

// ---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Switch1Switch(TObject *Sender) {
	TFmxObject *fmxObj = 0;
	TSwitch *sw = (TSwitch*)Sender;
	// typedef System::Set<System::Int8, 0, 31> TIntegerSet;
	if (sw->IsChecked)
		// add an element to the set
			s.operator << (sw->Tag);
	else
		// remove an element from the set
			s.operator >> (sw->Tag);
	for (int i = 0; i < Layout3->ChildrenCount; ++i) {
		fmxObj = Layout3->Children->operator[](i);
		// testing for an element in the set
		if (s.Contains(((TLabel*)fmxObj)->Tag)) {
			((TLabel *)fmxObj)->Text = L"1";
		}
		else {
			((TLabel *)fmxObj)->Text = L"0";
		}
	}
	Label1->Text = s.ToInt();
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender) {
	TFmxObject *fmxObj = 0;
	// clear the set
	s.Clear();
	for (int i = 0; i < Layout1->ChildrenCount; ++i) {
		fmxObj = Layout1->Children->operator[](i);
		((TSwitch *)fmxObj)->IsChecked = false;
	}
	for (int i = 0; i < Layout3->ChildrenCount; ++i) {
		fmxObj = Layout3->Children->operator[](i);
		((TLabel *)fmxObj)->Text = L"0";
	}
	Label1->Text = s.ToInt();
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender) {
	TFmxObject *fmxObj = 0;
	if (s.ToInt() < 255) {
		s = (TIntegerSet)(s.ToInt() + 1);
		for (int i = 0; i < Layout1->ChildrenCount; ++i) {
			fmxObj = Layout1->Children->operator[](i);
			if (s.Contains(((TSwitch *)fmxObj)->Tag))
				((TSwitch *)fmxObj)->IsChecked = true;
			else
				((TSwitch *)fmxObj)->IsChecked = false;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender) {
	s = (TIntegerSet)0;
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender) {
	TFmxObject *fmxObj = 0;
	if (s.ToInt() > 0) {
		s = (TIntegerSet)(s.ToInt() - 1);
		for (int i = 0; i < Layout1->ChildrenCount; ++i) {
			fmxObj = Layout1->Children->operator[](i);
			if (s.Contains(((TSwitch *)fmxObj)->Tag))
				((TSwitch *)fmxObj)->IsChecked = true;
			else
				((TSwitch *)fmxObj)->IsChecked = false;
		}
	}
}
// ---------------------------------------------------------------------------
