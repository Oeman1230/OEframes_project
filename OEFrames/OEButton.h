
#ifndef __OEBUTTON_H__
#define __OEBUTTON_H__

#include <memory>

#include "OEWindow.h"
#include "OELabel.h"
#include "BaseWindowObj.h"


class OEButton : public OELabel
{
public:

	OEButton(SDL_Renderer* rend);
	~OEButton();

public:
	
	

private:

	bool _canBeClicked;

	std::function<void(void*, void*)> _onClickAction;

	std::shared_ptr<OELabel> _pressedButtonTexture;




};


#endif // !__OEBUTTON_H__


