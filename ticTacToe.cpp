#include <iostream>
#include <GL/glut.h>
#include <string>
#include <utility>

#include "ticTacToe.h"
#include "board.h"

using std::cout;
using std::endl;
using std::pair;

typedef pair<int, int> pii;

Board board (3, 3);
int view_left, view_bottom, view_right, view_top;
int current_player = 1;
bool is_completed = false;

void display(void)
{
    fill_board();
    draw_initial_board();
    int winner = check_win();
    if (winner != 0) {
        display_win(winner);
    }
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tic Tac Toe");

    init();
    
    glutMouseFunc(process_mouse);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void process_mouse(int button, int state, int x, int y)
{
    if (!is_completed && button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        int i = (x / 500.0 * 100 - 5) / 30;
        int j = (y / 500.0 * 100 - 5) / 30;
        if (inside(i, j) && board.getXY(i, 3-j-1) == 0) {
            board.setXY(i, 3 - j - 1, current_player);
            display();
            current_player = 3 - current_player;
        }
    }
}

pair< int, pii> find_next_move(int player, int max_player)
{
    vector<pii> valid_moves = find_valid_moves(player);
    if (valid_moves.size() == 0) {
        return terminal_utility(max_player);
    }
    for (int i = 0; i < valid_moves.size(); i++) {





int check_win(void)
{
    for (int i = 0; i < 3; i++) {
        if (check_row(i) != 0) {
            return check_row(i);
        }
        if (check_col(i) != 0) {
            return check_col(i);
        }
    }
    if (board.getXY(0, 0) != 0 && board.getXY(0, 0) == board.getXY(1, 1) && board.getXY(0, 0) == board.getXY(2, 2)) {
        return board.getXY(0, 0);
    }
    if (board.getXY(0, 2) != 0 && board.getXY(0, 2) == board.getXY(1, 1) && board.getXY(0, 2) == board.getXY(2, 0)) {
        return board.getXY(0, 2);
    }
    return 0;
}

pair<int, pii> terminal_utility(int max_player)
{
    int winner = check_win();
    if (winner == max_player) {
        return make_pair(1, make_pair(-1, -1));
    } else if (winner == 3 - max_player) {
        return make_pair(-1, make_pair(-1, -1));
    } else {
        return make_pair(0, make_pair(-1, -1));
    }
}



void display_win(int winner) 
{
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(view_left, view_bottom);
        glVertex2f(view_right, view_bottom);
        glVertex2f(view_right, view_top);
        glVertex2f(view_left, view_top);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    std::string message = "Player 0 wins!";
    message[7] = winner + '0';

    glRasterPos2f(35, 50);
    for (int i = 0; i < message.size(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    cout << "Player " << winner << " wins!" << endl;
    is_completed = true;
}

int check_row(int x) 
{
    if (board.getXY(x, 0) == 0) {
        return 0;
    }
    for (int i = 1; i < 3; i++) {
        if (board.getXY(x, i) != board.getXY(x, 0)) {
            return 0;
        }
    }
    return board.getXY(x, 0);
}

int check_col(int y)
{
    if (board.getXY(0, y) == 0) {
        return 0;
    }
    for (int i = 1; i < 3; i++) {
        if (board.getXY(i, y) != board.getXY(0, y)) {
            return 0;
        }
    }
    return board.getXY(0, y);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    
    view_left = 0;
    view_right = 100;
    view_bottom = 0;
    view_top = 100;

    gluOrtho2D(view_left, view_right, view_bottom, view_top);
    glClear(GL_COLOR_BUFFER_BIT);
}

void fill_board(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.getXY(i, j) == 0) {
                continue;
            } else {
                fill_player(i, j, board.getXY(i, j));
            }
        }
    }
}

void fill_player(int x, int y, int player) 
{
    if (player == 1) {
        glColor3f(1.0, 0.0, 0.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    glBegin(GL_POLYGON);
        glVertex2f(x * 30 + 5, y * 30 + 5);
        glVertex2f(x * 30 + 5 + 30, y * 30 + 5);
        glVertex2f(x * 30 + 5 + 30, y * 30 + 5 + 30);
        glVertex2f(x * 30 + 5, y * 30 + 5 + 30);
    glEnd();
}

void draw_initial_board(void)
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        for (int i = 1; i < 3; i++) {
            glVertex2f(view_left + 5, i * 30 + 5);
            glVertex2f(view_right - 5, i * 30 + 5);

            glVertex2f(i * 30 + 5, view_bottom + 5);
            glVertex2f(i * 30 + 5, view_top - 5);
        }

    glEnd();
}

bool inside(int x, int y)
{
    if (x < 0 || x >= 3) {
        return false;
    }
    if (y < 0 || y >= 3) {
        return false;
    }
    return true;
}


