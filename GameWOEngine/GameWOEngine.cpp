
#include "Game.h"
#include "SDL_main.h"
#include <list>
#include "Player.h"


int SDL_main(int argc, char* argv[])
{
	Game* game = new Game();
	int errorCode = 0;
	if (game->InitWindow("Title", 1280, 760))
	{
		Player* p = new Player();
		game->AddGameObject(p);

		game->Perform();

		int errorCode = game->GetErroroCode();
		game->Clean();
	}

	delete game;

	return errorCode;

}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug
// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln