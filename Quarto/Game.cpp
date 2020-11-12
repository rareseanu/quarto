#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "UnusedPieces.h"

void Game::Run()
{
	Board board;

	std::string numePlayer;
	std::cout << "Introduceti numele primul player: ";
	std::cin >> numePlayer;
	Player player1(numePlayer);

	std::cout << "\nIntroduceti numele celui de-al 2-lea player: ";
	std::cin >> numePlayer;
	Player player2(numePlayer);

	UnusedPieces unusedPieces;

	std::reference_wrapper<Player>pickingPlayer = player1;
	std::reference_wrapper<Player>placingPlayer = player2;

	while (true) {

		std::cout << board;
		std::cout << "\nUnused pieces: \n";
		std::cout << unusedPieces;

		Piece p;


		while (true) {
			std::cout << pickingPlayer << " choose a piece: ";
			try {
				p = std::move(pickingPlayer.get().PickPiece(std::cin, unusedPieces));
				break;
			}
			catch (const char* errorMessage) {
				std::cout << errorMessage;
			}
		}

		Board::Position pos;

		while (true) {
			std::cout << '\n' << placingPlayer << " choose a position: ";
			try {
				pos = placingPlayer.get().PlacePiece(std::move(p), std::cin, board);
				break;
			}
			catch (const char* errorMessage) {
				std::cout << errorMessage;
			}

		}
		std::swap(pickingPlayer, placingPlayer);
	}
}
