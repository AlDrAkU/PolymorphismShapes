#pragma once
#include <vector>

class  DaeShape;

class Game
{
public: 
	explicit Game( const Window& window );
	Game( const Game& other ) = delete;
	Game& operator=( const Game& other ) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( );

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	Window m_Window;
	std::vector< DaeShape * > m_pShapes;

	const float m_TransPerSec{ 100.0f };
	TTF_Font *m_pFont;

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( );

	void CreateLabelFont( );
	void CloseLabelFont( );
	void CreateShapes( );
	void DeleteShapes( );
	void DrawShapes( );
	void MoveShapes( float elapsedSec );

};