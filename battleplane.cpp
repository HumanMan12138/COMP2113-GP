#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include "head.h"


//function to create the game board
void create(char map[10][10]){ //input a map, output map with three planes
    srand(time(NULL));//initialize the random number generator with the current time
    for(int k=1;k<=3;k++){//loop to create 3 planes
        while(true){
            //randomly generate the position and orientation of the plane
            int di=rand()%10,dj=rand()%10,dir=rand()%4;

            //check if the ship can be placed in the chosen position and orientation
            if(dir==0){     //left 
                if(dj-3<0)continue;
                if(di-2<0)continue;
                if(di+2>9)continue;
                if(map[di][dj]!='\0')continue;
                if(map[di-2][dj-1]!='.'||map[di-1][dj-1]!='.'||map[di][dj-1]!='.'||map[di+1][dj-1]!='.'||map[di+2][dj-1]!='.')continue;
                if(map[di][dj-2]!='.')continue;
                if(map[di-1][dj-3]!='.'||map[di][dj-3]!='.'||map[di+1][dj-3]!='.')continue;
                map[di][dj]='X'+k;
                map[di-2][dj-1]=map[di-1][dj-1]=map[di][dj-1]=map[di+1][dj-1]=map[di+2][dj-1]='0'+k;
                map[di][dj-2]='0'+k;
                map[di-1][dj-3]=map[di][dj-3]=map[di+1][dj-3]='0'+k;
                break;
            }
            else if(dir==1){    //up
                if(di-3<0)continue;
                if(dj-2<0)continue;
                if(dj+2>9)continue;
                if(map[di][dj]!='.')continue;
                if(map[di-1][dj-2]!='.'||map[di-1][dj-1]!='.'||map[di-1][dj]!='.'||map[di-1][dj+1]!='.'||map[di-1][dj+2]!='.')continue;
                if(map[di-2][dj]!='.')continue;
                if(map[di-3][dj-1]!='.'||map[di-3][dj]!='.'||map[di-3][dj+1]!='.')continue;
                map[di][dj]='X'+k;
                map[di-1][dj-2]=map[di-1][dj-1]=map[di-1][dj]=map[di-1][dj+1]=map[di-1][dj+2]='0'+k;
                map[di-2][dj]='0'+k;
                map[di-3][dj-1]=map[di-3][dj]=map[di-3][dj+1]='0'+k;
                break;
            }
            else if(dir==2){    //right
                if(dj+3>9)continue;
                if(di-2<0)continue;
                if(di+2>9)continue;
                if(map[di][dj]!='.')continue;
                if(map[di-2][dj+1]!='.'||map[di-1][dj+1]!='.'||map[di][dj+1]!='.'||map[di+1][dj+1]!='.'||map[di+2][dj+1]!='.')continue;
                if(map[di][dj+2]!='.')continue;
                if(map[di-1][dj+3]!='.'||map[di][dj+3]!='.'||map[di+1][dj+3]!='.')continue;
                map[di][dj]='X'+k;
                map[di-2][dj+1]=map[di-1][dj+1]=map[di][dj+1]=map[di+1][dj+1]=map[di+2][dj+1]='0'+k;
                map[di][dj+2]='0'+k;
                map[di-1][dj+3]=map[di][dj+3]=map[di+1][dj+3]='0'+k;
                break;
            }
            else if(dir==3){    //down
                if(di+3>9)continue;
                if(dj-2<0)continue;
                if(dj+2>9)continue;
                if(map[di][dj]!='\0')continue;
                if(map[di+1][dj-2]!='.'||map[di+1][dj-1]!='.'||map[di+1][dj]!='.'||map[di+1][dj+1]!='.'||map[di+1][dj+2]!='.')continue;
                if(map[di+2][dj]!='.')continue;
                if(map[di+3][dj-1]!='.'||map[di+3][dj]!='.'||map[di+3][dj+1]!='.')continue;
                map[di][dj]='X';
                map[di+1][dj-2]=map[di+1][dj-1]=map[di+1][dj]=map[di+1][dj+1]=map[di+1][dj+2]='0'+k;
                map[di+2][dj]='0'+k;
                map[di+3][dj-1]=map[di+3][dj]=map[di+3][dj+1]='0'+k;
                break;
            }
        }
    }
    return;
}
void print(char now[10][10]){   //print the board
    for(int i=0;i<10;i++){
        printf("%c ",'A'+i);
        for(int j=0;j<10;j++){
            if(now[i][j]=='+')printf("\033[1;33m%c\033[0m ",now[i][j]);//introducing some colours
            else if(now[i][j]=='1')printf("\033[1;31m%c\033[0m ",now[i][j]);
            else if(now[i][j]=='2')printf("\033[1;32m%c\033[0m ",now[i][j]);
            else if(now[i][j]=='3')printf("\033[1;34m%c\033[0m ",now[i][j]);
            else if(now[i][j]=='X'+1)printf("\033[1;31m%c\033[0m ",now[i][j]-1);
            else if(now[i][j]=='X'+2)printf("\033[1;32m%c\033[0m ",now[i][j]-2);
            else if(now[i][j]=='X'+3)printf("\033[1;34m%c\033[0m ",now[i][j]-3);
            else if(now[i][j]=='X')printf("\033[1;33m%c\033[0m ",now[i][j]);
            else printf("%c ",now[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for(int i=0;i<10;i++){
        printf("%d ",i);
    }
    return;
}
void check(char map[10][10],char board[10][10],char input[],int &cnt,int &num){     //check the move with input player board, answer board, user input, bullets used and number of planes left, get bullets and number of planes left
    int i=input[0]-'A',j=input[1]-'0';
    if(map[i][j]=='.'){
        board[i][j]=' ';
        printf("You missed!\n");
        cnt++;
        return;
    }
    if(map[i][j]>='1'&&map[i][j]<='3'){
        board[i][j]='+';
        printf("You hit the body!\n");
        cnt++;
        return;
    }
    if(map[i][j]>='X'+1&&map[i][j]<='X'+3){
        board[i][j]='X';
        if(num-1==2)printf("Good Job! You shot down the plane! There are 2 planes left!\n");
        if(num-1==1)printf("Great!! You shot down another plane!! There is only 1 plane left!!\n");
        if(num-1==0)printf("Congratulations!! No plane left, You win!!\n");
        cnt++;
        num--;
        return;
    }
    return;
}
int battleplane(){
    printf("Battleplane is played on 10 * 10 board on which the fleet of planes are settled. It is a strategy type guessing game for one player. \n");
    for (int i = 0; i <= 30000; i++) { //use two empty for loop to delay the printing time
        for (int j = 0; j <= 30000; j++);
    }
    printf("There are three planes fixed on the board, which do not overlap.(Warmly reminder ^*^ : They might be really close to each other)\n");
    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j <= 30000; j++);
    }
    printf("The player will continuously be asked to call 'shots' by inputting the coordinate of the point they would like to fire at.\n");
    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j <= 30000; j++);
    }
    printf("Please note that player will be provided only 25 bullets! You will lose if you used up all the bullets.\n");
    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j <= 30000; j++);
    }
    printf("Your objective is to find all the heads of the planes and shoot them down.\n");
    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j <= 30000; j++);
    }
    printf("Once the players have destroyed the fleet, they win that level!\n");
    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j <= 30000; j++);
    }
    printf("Have a look at the plane from four possible directions:\n");
    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j <= 30000; j++);
    }
    printf("  *          +++          +            +\n");
    printf("+++++         +           + +        + +\n");
    printf("  +         +++++        *+++        ++++*\n");
    printf(" +++          *           + +        + +\n");
    printf("                          +            +\n");
    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j <= 30000; j++);
    }

    char map[10][10],board[10][10];
    printf("Welcome to our game!!\n");
    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j <= 30000; j++);
    }
    while(true){
        memset(map,'.',sizeof(map)); //initializing all elements of answer board to dots
        create(map);
        memset(board,'.',sizeof(board)); //player board
        print(board);
        int cnt=0,num=3;
        while(true){
            if(cnt<=24){ //used bullets within valid value
                char input[5];
                while(true){
                    printf("\nPlease enter your move(row and column):\n");
                    scanf("%s",input);
                    if(strlen(input)!=2||input[0]<'A'||input[0]>'J'||input[1]<'0'||input[1]>'9'){
                        printf("Invaild input.Please enter your move again.\n");
                    }
                    else if(board[input[0]-'A'][input[1]-'0']!='.'){
                        printf("You have already hitted %s.Please enter your move again.\n",input);
                    }
                    else break;
                }
                check(map,board,input,cnt,num);
                if(!num){
                    printf("You used %d bullets totally.\n",cnt);
                    printf("The complete board is:\n");
                    print(map);
                    return 1;
                }
                else {
                    printf("Bullet left:%d\n",25-cnt);
                    print(board);
                }
            }
            else { //used up all bullets
                printf("You used up all the bullet. Game lost.\n");
                return 0;
            }
        }    
    }
}









