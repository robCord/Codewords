#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace  std;

int main()
{
	//todo start our loop to play again
	//Our var to play again
	bool playAgain = false;
	string usersChoiceToPlayAgain;
	do
	{

		const int	MAX_WRONG = 8;
		//enter values for words as strings
		vector<string> words;
		words.push_back("GUESS");
		words.push_back("HANGMAN");
		words.push_back("DIFFICULT");
		//shuffles word order
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		const string THE_WORD = words[0];
		int wrong = 0;
		string soFar(THE_WORD.size(), '-');
		string used = "";

		cout << "Welcome to Hangman. Good luck!\n";
		//
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			//display general info
			cout << "\n\nYou have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left.\n";
			cout << "\nYou've used the following letters:\n" << used << endl;
			cout << "\nSo far, the word is:\n" << soFar << endl;
			//give input to player to play fame 
			char guess;
			cout << "\n\nEnter your guess: ";
			cin >> guess;
			guess = toupper(guess);
			//should player input a guess already entered, gives a retry
			while (used.find(guess) != string::npos)
			{
				cout << "\nYou've already guessed" << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			used += guess;
			//player correctly guesses a letter
			if (THE_WORD.find(guess) != string::npos)
			{
				cout << "That's right! " << guess << " is in the word\n";

				for (int i = 0; i < THE_WORD.length(); i++)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			//incorrect answer increases wrong
			else
			{
				cout << "sorry, " << guess << " isn't in the word.\n";
				++wrong;
			}

		}
		//player reaches maximum guesses
		if (wrong == MAX_WRONG)
		{
			cout << "\nYou've been hanged";
		}
		else
		{
			cout << "\nYou guessed it!";
		}
		//gives player info of what the word was 
		cout << "\nThe word was " << THE_WORD << endl;

		//give player input to play again
		cout << "\nWould you like to play again? (y/n)";
		cin.ignore();
		getline(cin, usersChoiceToPlayAgain);
		//player options for exiting or playing again
		if (usersChoiceToPlayAgain == "Y" || usersChoiceToPlayAgain == "y" || usersChoiceToPlayAgain == "Yes" || usersChoiceToPlayAgain == "yes" || usersChoiceToPlayAgain == "YES" || usersChoiceToPlayAgain == "Sure")
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;

		}
	} while (playAgain);
	return 0;
}