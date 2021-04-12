#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//定义计算机玩家类
class Computer {
private:
    int c_win=0;//记录赢的次数
    int c_choice;//记录出拳选择

public:
    //进行出拳
    void setcChioce(int choice) {
        c_choice = choice;
    }
    //获得出拳结果
    int getcChioce() {
        return c_choice;
    }
    //改变赢的次数
    void setcWin(int win) {
        c_win = win;
    }
    //获得赢的次数
    int getcWin() {
        return c_win;
    }
};

//定义玩家类，同上
class Player {
private:
    int p_win=0;
    int p_choice;

public:
    void setpChioce(int choice) {
        p_choice = choice;
    }
    int getpChioce() {
        return p_choice;
    }

    void setpWin(int win) {
        p_win = win;
    }
    int getpWin() {
        return p_win;
    }
};

//定义玩家出拳函数
int play() {

    cout << "\n计算机已经出好了，你快出哦!\n\n";
    int result;
    cout << "\t0-石头 1-剪刀 2-布" << endl;
  chuquan:  cout << "请出拳: ";

    cin >> result;
    
    string jg;
    switch (result) {
    case 0:jg = "石头"; break;
    case 1:jg = "剪刀"; break;
    case 2:jg = "布"; break;
    default: {
        //如果不按数字 1，2，3，则重新输入
        cout << " 傻* ! 不要乱出拳，看清数字!\n";
        
        goto chuquan; break;
    }
    }
    cout << "你出的是 " << jg << endl;
    return result;
}

//展示计算机出拳结果
int show(int result) {
    string jg2;
    switch (result) {
        
    case 0:jg2 = "石头"; break;
    case 1:jg2 = "剪刀"; break;
    case 2:jg2 = "布"; break;
    }
    cout << "计算机出的是" << jg2 << endl;
    return result;
}

   
int main() {
    srand((unsigned int)time(NULL));

    cout << "\t人机猜拳游戏\n";

    int total = 0;//总回合数
    Player player;//实例化玩家对象
    Computer computer;//实例化计算机对象

    //定义标记，以便跳出循环
    int flag = 1;
    while (flag==1) {

        //调用玩家出拳函数并赋值给玩家出拳结果
        player.setpChioce(play());
        //计算机随机出拳
        computer.setcChioce(show(rand() % 3));

        int com = computer.getcChioce();
        int play = player.getpChioce();

        //比较出拳输赢
        if (com == 0 && play == 1 || com == 1 && play == 2 || com == 2 && play == 0) {
            //计算机玩家赢了，获取赢的次数并加 1，再赋值给赢的次数
            computer.setcWin(computer.getcWin() + 1);
            cout << "计算机赢了! 嘿嘿 ！" << endl;
        }
        else if (com == play) {
            cout << "哈! 平局哦!" << endl;
        }
        else {
            //玩家（你）赢了，获取赢的次数并加 1，再赋值给赢的次数
            player.setpWin(player.getpWin() + 1);
            cout << "竟然被你赢了,额..." << endl;
        }
        total++;

        //设置退出选择
        string sign;
        cout << "\n不玩了按0退出，按其他键继续与之一战\n";cin >> sign;
         
          system("cls");
                
          if (sign == "0") flag = 0;
    }

    cout << "你一共进行了" << total << "个回合.\n你赢了" 
        << player.getpWin()<< "局\n计算机赢了" 
        << computer.getcWin() << "局\n平局"
        << total - computer.getcWin() - player.getpWin() << "次\n";
        

    return 0;
}
