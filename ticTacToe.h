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

