
#ifndef __OEBUTTON_H__
#define __OEBUTTON_H__

#include <memory>

#include "OEWindow.h"
#include "OELabel.h"
#include "BaseWindowObj.h"


class OEButton : public BaseWindowObj
{
public:

	OEButton(OEWindow* mainWin);
	~OEButton();

	bool isClickable() { return _canBeClicked;}
	void setClickable( bool status) { _canBeClicked = status; }
public:
	
	void changeTextureToPressed();
	void changeTextureToUnpressed();
	void setPressedButtonTexture(std::shared_ptr<OEFrame> newTexture);
	void setUnpressedButtonTexture(std::shared_ptr<OEFrame> newTexture);


	void addClickListener(BaseWindowObj::BaseReaction action, void* caller);
	void doClickActions(void* arg);

public:

	void repaint();

private:

	OEWindow* _winPtr;

	bool _canBeClicked;

	

	std::vector<BaseWindowObj::BaseListener> _onClickActions;

	std::shared_ptr<OEFrame> _currentTexture;



	std::shared_ptr<OEFrame> _pressedButtonTexture;
	std::shared_ptr<OEFrame>  _unpressedButtonTexture;



};


#endif // !__OEBUTTON_H__


