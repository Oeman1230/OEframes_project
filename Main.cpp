
#include <iostream>
#include <string>

#include <conio.h>
#include <chrono>
#include <thread>

#include "../OESDL_Module/OESDL_Module.h"
#include "./OEFrames/OEWindow.h"
#include "./OEFrames/OEFrame.h"
#include "./OEFrames/OELabel.h"
#include "./OEFrames/OEFrameWrapper.h"
#include "./OEFrames/OELabelWrapper.h"

#include "../OESDL_Module/OET_Figures/OET_Square.h"

//#include <OETexture.h>
//#include <OET_Figures/OET_Square.h>



int main()
{



	OEWindow oewin;
	//std::shared_ptr<OEWindow> oewinPtr{ &oewin };

	oewin.setBounds(100, 100, 500, 500);
	oewin.setWinName("win");
	oewin.setBackground(SDLColors::GREEN);
	oewin.makeWindow();

	auto frameWrap = OEFrameWrapper();

	frameWrap.setWindow(&oewin);
	frameWrap.setBounds(50, 50, 300, 300);
	frameWrap.setBackground(SDLColors::BLUE);
	frameWrap.setVisible(true);

	oewin.add(frameWrap.build());


	/*
	std::shared_ptr<OELabel>lab = std::make_shared<OELabel>(oewin.getRend());
	lab->setBounds(30, 100, 20, 20);
	lab->setFontSize(100);
	lab->setTextColor(SDLColors::GRAY);
	lab->setBackground(SDLColors::PINK);
	
	*/

	auto labWrap = OELabelWrapper();
	labWrap.setBackground(SDLColors::RED);
	labWrap.setBounds(50, 100, 200, 100);
	labWrap.setFontSize(100);
	labWrap.setTextColor(SDLColors::BLACK);
	labWrap.setVisible(true);
	labWrap.setText("hello sdl");
	labWrap.setWindow(&oewin);

	auto labWrap2 = OELabelWrapper();
	labWrap2.setBackground(SDLColors::GREEN);
	labWrap2.setBounds(100, 300, 200, 100);
	labWrap2.setFontSize(100);
	labWrap2.setTextColor(SDLColors::BLUE);
	labWrap2.setVisible(true);
	labWrap2.setText("Button2");
	labWrap2.setWindow(&oewin);


	oewin.add(labWrap.build());
	oewin.add(labWrap2.build());

	oewin.addMouseClickListener([&](void* caller, void* arg)
		{
			OELabel* label = (OELabel*)caller;
			label->setText("SET");


		}, labWrap.getFrame().get());

	oewin.addEventsListener([&](void* caller, void* arg)
		{
			auto e = (SDL_Event*)arg;

			if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_r)
			{
				auto lab = (OELabel*)(caller);
				lab->setText("RESET");
			}

		}, labWrap.getFrame().get());

	oewin.addMouseClickListener([&](void* caller, void* arg)
		{
			OELabel* label = (OELabel*)caller;
			label->setText("SET");


		}, labWrap2.getFrame().get());

	oewin.addEventsListener([&](void* caller, void* arg)
		{
			auto e = (SDL_Event*)arg;

			if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_r)
			{
				auto lab = (OELabel*)(caller);
				lab->setText("RESET");
			}

		}, labWrap2.getFrame().get());


	oewin.addMouseClickListener([&](void* caller, void* arg)
		{
			OELabel* label = (OELabel*)caller;
			label->setText("PRESS");

		}, labWrap.getFrame().get(), ClickManager::Mode::ON_BTN_DOWN);

	oewin.addMouseClickListener([&](void* caller, void* arg)
		{
			OELabel* label = (OELabel*)caller;
			label->setText("PRESS");

		}, labWrap2.getFrame().get(), ClickManager::Mode::ON_BTN_DOWN);

	//OELabel* test = (OELabel*)(labWrap.getFrame().get());

	/*for (int i = 0; i < 10000; i++)
	{
		test->setText("Pisudes(((");


	}*/

	std::cout << SDL_GetError() << "\n";
	oewin.startMainThread();

	std::cout << SDL_GetError() << "\n";
	//oewinPtr.reset();


	return 0;
}

int main5()
{

	OEWindow oewin = OEWindow();
	oewin.setBounds(100, 100, 500, 500);
	oewin.setWinName("win");
	oewin.setBackground(SDLColors::GREEN);
	oewin.makeWindow();

	std::shared_ptr<OETexture> frameTexture = std::make_shared<OETexture>(oewin.getRend());

	TTF_Font* font = TTF_OpenFont("C:/Windows/Fonts/times.ttf", 10);

	for (int i = 0; i < 100000000; i++)
	{

		//SDL_Rect curRect = frameTexture->getOnScreenRect();

		//frameTexture->free();

		////SDL_Surface* tempSurf = TTF_RenderText_Blended(font, "text", SDLColors::BLACK);// , bgColor);

		///*if (tempSurf == nullptr)
		//{
		//	throw ("CANT_CREATE_TEXT");
		//}*/
		//SDL_Surface* tempSurf;
		////frameTexture->setTextureBySurface(tempSurf);

		//tempSurf = TTF_RenderText_LCD(font, "text", SDLColors::BLACK, SDLColors::WHITE);

		//if (tempSurf == nullptr)
		//{
		//	throw ("CANT_CREATE_TEXT");
		//}

		//frameTexture->setTextureBySurface(tempSurf);
		//888888888888888888

		std::shared_ptr<BaseWindowObj> frame;

		OELabelWrapper wrap = OELabelWrapper();
		wrap.setWindow(&oewin);
		wrap.setBounds(100, 100, 100, 100);
		wrap.setBackground(SDLColors::GREEN);
		wrap.setTextColor(SDLColors::PINK);
		wrap.setVisible(true);

		frame = wrap.build();
		std::shared_ptr<OELabel> lab = std::dynamic_pointer_cast<OELabel>(frame);
		lab->setText("text");

		oewin.add(frame);

		oewin.removeAll();
		frame.reset();

	}

	std::cout << SDL_GetError();

	return 0;
}

int main4()
{
	OEWindow oewin;
	oewin.setBounds(100, 100, 500, 500);
	oewin.setWinName("win");
	oewin.setBackground(SDLColors::GREEN);
	oewin.makeWindow();
	std::shared_ptr<OELabel>lab = std::make_shared<OELabel>(oewin.getRend());
	lab->setBounds(30, 100, 20, 20);
	lab->setFontSize(100);
	lab->setTextColor(SDLColors::GRAY);
	lab->setBackground(SDLColors::PINK);
	std::cout << SDL_GetError() << "\n";
	lab->setText("Hello");

	std::cout << SDL_GetError() << "\n";

	lab->setVisible(true);

	oewin.add(lab);

	std::cout << SDL_GetError() << "\n";
	oewin.startMainThread();

	return 0;
}

int main3()
{
	


	OEWindow oewin;

	oewin.setBounds(100, 100, 500, 500);
	oewin.setWinName("win");
	oewin.setBackground(SDLColors::GREEN);

	oewin.makeWindow();


	oewin.addEventsListener([&](void* caller, void* arg)
		{
			OEWindow* thisWin = (OEWindow*)(caller);
			
			SDL_Event* e = (SDL_Event*)arg;

			if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_w)
			{

				thisWin->setBackground(SDLColors::ORANGE);

				
				
			}

			if (e->type == SDL_KEYUP)
			{
				thisWin->setBackground(thisWin->standartBGColor);
			}

			



		}
	, &oewin);

	
	std::shared_ptr<OEFrame> frame = std::make_shared<OEFrame>(oewin.getRend());

	frame->setBounds(50, 50, 300, 300);
	frame->setBackground(SDLColors::BLUE);
	frame->setVisible(false);

	oewin.add(frame);

	std::cout << SDL_GetError() << "\n";

	std::shared_ptr<OEFrame> frame2 = std::make_shared<OEFrame>(oewin.getRend());

	frame2->setBounds(100, 100, 100, 100);
	frame2->setBackground(SDLColors::RED);
	frame2->setVisible(false);

	frame->add(frame2);


	std::shared_ptr<OELabel>lab = std::make_shared<OELabel>(oewin.getRend());
	lab->setBounds(30, 100, 20, 20);
	lab->setFontSize(100);
	lab->setTextColor(SDLColors::GRAY);
	lab->setBackground(SDLColors::PINK);

	std::cout << SDL_GetError() << "\n";
	lab->getOETexture().lock()->setAlpha(0);
;

	lab->setText("Hello");

	lab->setVisible(true);

	oewin.add(lab);

	frame->addEventsListener([&](void* caller, void* arg) 
		{
			OEFrame* thisFrame = (OEFrame*)caller;
			SDL_Event* e = (SDL_Event*)arg;

			if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_w)
			{
				//thisFrame->setVisible(!thisFrame->getVisibilityStatus());
				
			}


		}, 
		(void*)frame2.get());


	std::cout << SDL_GetError() << "\n";
	oewin.startMainThread();





	/*do
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		try
		{
			events = SDL_EventReaderSingleton::getInstance().lock()->getEvents();

		}
		catch (const std::exception&)
		{
			std::cout << "smthing wrong\n";
			continue;
		}
		
		if (events == nullptr)
		{
			std::cout << "nullptr events\n";
			continue;
		}

		if (_kbhit())
		{

			std::cout << "pressed\n";

			break;

		}


		for(auto it : *events.get())
		{
			if (it == nullptr)
				continue;

			e = *it.get();

		}


	} while (e.type != SDL_QUIT);*/


	//oewin.clear();

	return 0;

}

int main2()
{
	
	std::shared_ptr<OESDL_Module> sdlMod = std::make_shared<OESDL_Module>();

	OESDL_ModuleSingleton::setInstance(sdlMod);

	std::weak_ptr<OESDL_Module> ref = OESDL_ModuleSingleton::getInstance();

	ref.lock()->createMainWinDiscr("Norm", 100, 100);

	float deltaTime = 0;
	long long startTickTime = 0;
	long long prevTickTime = 0;

	bool isActive = true;


	

	while (isActive)
	{
		SDL_RenderClear(sdlMod->getRend());

		SDL_Event e;

		while (SDL_PollEvent(&e))
		{

		}

		if (_kbhit())
		{

			std::cout << "pressed\n";

			isActive = false;

		}

		SDL_RenderPresent(sdlMod->getRend());
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		
		



	}

	

	/*while ((start + toGo) >= GetTickCount64())
	{
		if (_kbhit())
		{
			keyInt = _getch();

			menuCon.directLogAppend(std::to_string(keyInt));

			break;
		}
		else
		{
			continue;
		}

	}*/

	//system("pause");

	

	return 0;
}

//int main2()
//{
//
//	OESDL_Module mod = OESDL_Module();
//
//	mod.createMainWinDiscr("helloWin", 1000, 600);
//
//	std::shared_ptr<OETexture> texture = std::make_shared<OETexture>(mod.getRend());
//
//	TSquare square = TSquare(mod.getRend(), mod.getWinSurf());
//
//	SDL_Color color{ 255,255,255,255 };
//	texture = square.createSquare(100, 100, color);
//
//	mod.rendPresent();
//	
//	mod.showWin();
//	mod.updateWin();
//	
//
//	system("pause");
//
//	return 0;
//}

