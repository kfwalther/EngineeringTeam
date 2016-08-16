#pragma once

/**
* @class TerminalUI
* @brief WoJ TerminalUI object.
* @author Joshua Griffith
* @date 2016
* @ingroup WheelOfJeopardy
*/

#include <string>
#include <vector>

#include "UserInterface.h"

#include "Sector.h"

class TerminalUI : UserInterface
{
public:
	// Define the constructor and destructor.
	TerminalUI(Player * const & player1, Player * const & player2);
	virtual ~TerminalUI();

	// Define the UserInterface object methods.
	virtual bool submitAnswer(int answer);
	virtual void endGame();
	virtual std::vector<std::string> listCategories();
	virtual void run();

	virtual void promptPreGame();
	virtual void displayPlayerInfo();
	virtual int promptSelect(std::vector<std::string> const & options);

	// User Interface Handlers
	virtual void UI_StartTurn();
	virtual void UI_LostTurn();
	virtual void UI_SpinWheel();
	virtual void UI_Category(std::string category);
	virtual void UI_PostQuestion(Question & question);
	virtual std::string UI_AnswerQuestion();
	virtual bool UI_AskUseToken();
	virtual void UI_UseToken();
	virtual void UI_LoseTurn();
	virtual void UI_AddFreeTurn();
	virtual void UI_Bankrupt();
	virtual void UI_SpinAgain();
	virtual void UI_CorrectAnswer();
	virtual void UI_WrongAnswer();
	virtual void UI_TimeExpired();
	virtual void UI_EndTurn();
	virtual int UI_ChooseCategory(Wheel::StringVectorType const & categories);
	virtual void UI_OpponentChoice();
	virtual int UI_OpposingVote(Wheel::StringVectorType const & categories, Player * const & player);
	virtual void UI_OpponentVoteWinner(std::string const & categoryName);
	virtual void UI_GameSummary();
	virtual void UI_Timer(double time);
	virtual void UI_EndTimer();
};