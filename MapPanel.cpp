#pragma once
#include "MapPanel.h"

void MapPanel::makePanel()
{
	wxPNGHandler* handler = new wxPNGHandler;
	wxImage::AddHandler(handler);
	mapPanelWidget.add(new pngLogo(MapPanel::getContext(), wxID_ANY, wxBitmap("images/parking-map.PNG", wxBITMAP_TYPE_PNG), wxPoint(250, 00), wxSize(950, 800), "PNG Logo"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1002, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(330, 355), wxSize(41, 50), "LotA"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1003, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(320, 450), wxSize(41, 50), "LotB"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1004, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(320, 550), wxSize(41, 50), "LotC"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1005, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(395, 630), wxSize(41, 50), "LotD"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1006, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(520, 660), wxSize(41, 50), "LotE"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1007, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(660, 660), wxSize(41, 50), "LotF"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1008, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(770, 660), wxSize(41, 50), "LotG"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1009, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(770, 560), wxSize(41, 50), "LotH"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1010, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(760, 250), wxSize(41, 50), "LotI"));
	mapPanelWidget.add(new pngButton(MapPanel::getContext(), 1011, wxBitmap("images/mapmarker.PNG", wxBITMAP_TYPE_PNG), wxPoint(700, 190), wxSize(41, 50), "LotJ"));
	
	wxWindowList& children = MapPanel::getContext()->GetChildren();
	for (wxWindowList::Node* node = children.GetFirst(); node; node = node->GetNext())
	{
		wxWindow* current = (wxWindow*)node->GetData();
		if (current->GetName() == "PNG Logo")
		{
			// do nothing
		}
		else if (current->GetName().substr(0, 3) == "Lot")
		{
			current->Raise();
			current->SetName(current->GetName().substr(3,4));
		}
	}
}

void MapPanel::destroyPanel()
{
	mapPanelWidget.destroy();
}

wxString MapPanel::getWidgetValue(wxString widgetName)
{
	if (widgetName == "username")
	{
		return mapPanelWidget.getValueByName("username");
	}
	else if (widgetName == "password")
	{
		return mapPanelWidget.getValueByName("password");
	}
}