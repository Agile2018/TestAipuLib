// TestAipuLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "AipuLib.h"

void RunVideo() {
	AipuLib* aipuLib = new AipuLib();
	
	auto observerError = aipuLib->observableError.map([](string message) {
		return message;
	});


	auto subscriptionError = observerError.subscribe([](string message) {
		
		const char *cstr = message.c_str();
		printf("%s \n", cstr);

	});
	auto frame_input
		= aipuLib->observableFrame.map([](Mat img) {
		return img;
	});

	auto subscriptionFrame = frame_input.subscribe([](Mat img) {
		cv::imshow("video1", img);
	});

	auto observerDatabase = aipuLib->observableUserJSON.map([](string jsonUser) {
		return jsonUser;
	});

	auto subscriptionDatabase = observerDatabase.subscribe([](string jsonUser) {
		const char *cstr = jsonUser.c_str();
		printf("%s \n", cstr);

	});
	aipuLib->InitLibrary();
	aipuLib->LoadConfiguration("directory1.txt");
	aipuLib->RunVideo();

}

int main()
{
	
	RunVideo();
    std::cout << "Good Bye!\n"; 
}
