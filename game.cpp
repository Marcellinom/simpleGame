#include <bits/stdc++.h>
#include <conio.h>
#include <random>
#include <windows.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
// defining map size
#define mapX 20
#define mapY 10

void gameinit(char map[][mapX]) {
        for(int y=0; y<mapY; y++)
        for(int x=0; x<mapX; x++)
            if(x==0 || y==0 || x==mapX-1 || y==mapY-1) 

                if(y==1 && x==0) map[y][x] = '>';
                else if (y==mapY-2 && x==mapX-1) map[y][x] = '<';
                else map[y][x] = '#';

            else map[y][x] = ' ';

    std::default_random_engine re;
    re.seed(time(NULL));
    std::uniform_int_distribution<int> ranX(2, mapX-3);
    std::uniform_int_distribution<int> ranY(2, mapY-3);

    int asteroid=mapX-5;
    while(asteroid--)
        map [ranY(re)]
            [ranX(re)] = '0';
    map[1][1] = '*';
}
void print(char map[][mapX], int level=0) {
    system("cls");
    cout <<"\
    reach 10 levels to win!\n\
    wasd/arrow-key to move\n\
    dont touch the 0's and the wall!\n\n";
    for(int y=0; y<mapY; y++) {
        for(int x=0; x<mapX; x++) {
            if(y==1 && x==0) cout << "in =";
            else if(x==0) cout <<"    ";
        cout <<map[y][x];
            if(y==mapY-2 && x==mapX-1) cout <<"= out";
        }
        cout<<endl;
    }
    if(level)
    cout << "\n    level "<<level<<endl;

}
void endScreen(string res, char map[][mapX]){
    print(map);
    Sleep(500);
    char opt;
    do{
        system("cls");
        cout << "YOU "<<res<<" !\n";
        cout << "retry? (y/n): ";
        cin >> opt;
        if(opt == 'y')      gameinit(map);
        else if(opt == 'n') exit(0);

    } while(opt!='y' && opt!='n');
}

tuple <int,int> findCurr(char map[][mapX]) {
    for(int i=0; i<mapY; ++i)
    for(int j=0; j<mapX; ++j)
        if(map[i][j] == '*')
        return make_tuple(j,i);
    return make_tuple(1,1);
}

bool changePos(char *nmap, char *omap) {
    char temp = *nmap;
    *nmap = '*';
    *omap = ' ';
    if(temp == ' ') return 1;
    return 0;
}
void moveUp(char map[][mapX]) {
    int x,y;
    tie(x,y) = findCurr(map);
    if(!changePos(&map[y-1][x],&map[y][x]))
        endScreen("LOSE",map);
    // else map[mapY-2][x] = '*';
}
void moveDown(char map[][mapX]) {
    int x,y;
    tie(x,y) = findCurr(map);
    if(!changePos(&map[y+1][x],&map[y][x]))
        endScreen("LOSE",map);
    // else map[1][x] = '*';
}
void moveLeft(char map[][mapX]) {
    int x,y;
    tie(x,y) = findCurr(map);
    if(!changePos(&map[y][x-1],&map[y][x]))
        endScreen("LOSE",map);
    // else map[y][mapX-2] = '*'; 
}
void moveRight(char map[][mapX],int &l) {
    int x,y;
    tie(x,y) = findCurr(map);
    if(map[y][x+1] == '<') {
        if(*&l==10) 
        {
            *&l=0;
            endScreen("WIN",map);
        } 
        else 
        {
            *&l+=1;
            gameinit(map);
        }return;
    }
    if(!changePos(&map[y][x+1],&map[y][x]))
        endScreen("LOSE",map);
    // else map[y][1] = '*';
}
int getMovement(char m,char map[][mapX],int *l) {
    switch(m) {
        case 'w': moveUp(map);break;
        case 'a': moveLeft(map);break;
        case 's': moveDown(map);break;
        case 'd': moveRight(map,*l);break;
        case KEY_UP: moveUp(map);break;
        case KEY_LEFT: moveLeft(map);break;
        case KEY_DOWN: moveDown(map);break;
        case KEY_RIGHT: moveRight(map,*l);break;
        // default: return 0;
    }
    return 1;
}

int main(){
    //          y   x
    char map[mapY][mapX];
    gameinit(map);
    int level=1;
    do{
        print(map,level);
    } while(getMovement(getch(),map,&level));    
}