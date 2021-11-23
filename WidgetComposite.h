#pragma once
#ifndef WIDGETCOMPOSITE_H
#define WIDGETCOMPOSITE_H
#include "wx/wx.h"
#include <vector>
using namespace std;

class WidgetComponent
{
	public:
		virtual void destroy() = 0;
		// returns the objects name
		virtual wxString getName() = 0;
		// returns the relevent value for the object
		// input is the name of the object
		virtual wxString getValueByName(wxString name) = 0;
};

class TextField : public WidgetComponent
{
	wxStaticText* staticText;
	public:
		TextField(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, wxString name)
		{
			staticText = new wxStaticText(parent,id,label,pos,size);
			staticText->SetName(name);
		}
		void destroy()
		{
			staticText->Destroy();
		}
		wxString getName()
		{
			return staticText->GetName();
		}
		wxString getValueByName(wxString name)
		{
			return staticText->GetLabel();
		}
};
class TextInput : public WidgetComponent
{
	wxTextCtrl* textInput;
	public:
		TextInput(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, wxString name)
		{
			textInput = new wxTextCtrl(parent, id, label, pos, size);
			textInput->SetName(name);
		}
		void destroy()
		{
			textInput->Destroy();
		}
		wxString getName()
		{
			return textInput->GetName();
		}
		wxString getValueByName(wxString name)
		{
			return textInput->GetValue();
		}
};
class TextButton : public WidgetComponent
{
	wxButton* button;
	public:
		TextButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, wxString name)
		{
			button = new wxButton(parent, id, label, pos, size);
			button->SetName(name);
		}
		void destroy()
		{
			button->Destroy();
		}
		wxString getName()
		{
			return button->GetName();
		}
		wxString getValueByName(wxString name)
		{
			return button->GetName();
		}
};

class pngLogo : public WidgetComponent
{
	wxStaticBitmap* png;
	public:
		pngLogo(wxWindow* parent, wxWindowID id, const wxGDIImage& label, const wxPoint& pos, const wxSize& size, wxString name)
		{
			png = new wxStaticBitmap(parent, id, label, pos, size);
			png->SetName(name);
		}
		void destroy()
		{
			png->Destroy();
		}
		wxString getName()
		{
			return png->GetName();
		}
		wxString getValueByName(wxString name)
		{
			return png->GetName();
		}
};

class pngButton : public WidgetComponent
{
	wxBitmapButton* pngB;
public:
	pngButton(wxWindow* parent, wxWindowID id, const wxBitmap& bitmap, const wxPoint& pos, const wxSize& size, wxString name)
	{
		pngB = new wxBitmapButton(parent, id, bitmap, pos, size);
		pngB->SetName(name);
	}
	void destroy()
	{
		pngB->Destroy();
	}
	wxString getName()
	{
		return pngB->GetName();
	}
	wxString getValueByName(wxString name)
	{
		return pngB->GetName();
	}
};

class WidgetComposite : public WidgetComponent
{
	vector <WidgetComponent*> widgets;
	public:
		void add(WidgetComponent* widget)
		{
			widgets.push_back(widget);
		}
		void destroy()
		{
			for (int i = 0; i < widgets.size(); i++)
			{
				widgets[i]->destroy();
			}
		}
		int sizeOf()
		{
			return widgets.size();
		}
		wxString getName()
		{
			return "widgetComposite";
		}
		wxString getValueByName(wxString name)
		{
			for (int i = 0; i < widgets.size(); i++)
			{
				if (widgets[i]->getName() == name)
				{
					return widgets[i]->getValueByName(name);
				}
			}
		}
};
#endif // !WIDGETCOMPOSITE_H