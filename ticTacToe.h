#include <utility>
#include <vector>
#include <string>

using std::pair;
using std::vector;

typedef pair<int, int> pii;

void init(void);
void display(void);
void draw_initial_board(void);
void fill_board(void);
void fill_player(int x, int y, int player);
bool inside(int x, int y);
void process_mouse(int button, int state, int x, int y);
int check_win(void);
int check_row(int x);
int check_col(int y);
void display_win(int winner);
pair< int, pii> find_next_move(int player, int max_player);
vector<pii> find_valid_moves(int player);
pair<int, pii> terminal_utility(int max_player);
vector<pii> find_valid_moves(int player);
void move_computer(void);
bool loadTexture(char *filename, unsigned int *texture);
void move_player(int i, int j);
void reset_board(void);
void print_message(std::string message);

