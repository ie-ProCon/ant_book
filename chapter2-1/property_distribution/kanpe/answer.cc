#include <iostream>
#include <vector>

std::vector<char> get_char_vec(const int width);
int get_ans(std::vector<std::vector<char> >& field);
std::string cinline();
bool dfs(void);
std::vector<std::vector<char> > init_field(const int height, const int width);

const char ALREADY_VISITED = '/';

const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;
const int x_move[4] = {0, 0, -1, 1};
const int y_move[4] = {-1, 1, 0, 0};

int main(int argc,char* argv[]) {
    int h;
    int w;
    std::cin >> h;
    std::cin >> w;
    bool end_flag = (h==0) && (w==0);
    while(!end_flag) {
        std::vector<std::vector<char> > field = init_field(h, w);
        int ans = get_ans(field);
        std::cout << ans << std::endl;
        std::cin >> h;
        std::cin >> w;
        end_flag = (h==0) && (w==0);
    }
    return 0;
}

int dfs(const char org, const int x, const int y, std::vector<std::vector<char> >& field) {
    const int height = field.size();
    const int width  = field[0].size();
    bool x_inside = (0<=x) && (x<width); 
    bool y_inside = (0<=y) && (y<height); 
    if (!x_inside || !y_inside) {
        return 0; 
    }

    const char c = field[y][x];
    if (org != c) {
        return 1; 
    }
    field[y][x] = ALREADY_VISITED;
    dfs(org, x+x_move[UP], y+y_move[UP], field);
    dfs(org, x+x_move[DOWN], y+y_move[DOWN], field);
    dfs(org, x+x_move[LEFT], y+y_move[LEFT], field);
    dfs(org, x+x_move[RIGHT], y+y_move[RIGHT], field);

    return 1;
}

int get_ans(std::vector<std::vector<char> >& field) {
    const int height = field.size();
    const int width  = field[0].size();
    int ans = 0;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            char c = field[y][x];
            if (c == ALREADY_VISITED) {
                continue; 
            }
            ans += dfs(c, x, y, field); 
        }
    }
    return ans;
}

std::vector<std::vector<char> > init_field(const int height, const int width) {
    std::vector<std::vector<char> > field(height);
    for (int y = 0; y < height; y++) {
        std::vector<char> row(width);
        for (int x = 0; x < width; x++) {
            std::cin >> row[x];
        }
        field[y] = row;
    }
    return field;
}
