#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//�������������
class Computer {
private:
    int c_win=0;//��¼Ӯ�Ĵ���
    int c_choice;//��¼��ȭѡ��

public:
    //���г�ȭ
    void setcChioce(int choice) {
        c_choice = choice;
    }
    //��ó�ȭ���
    int getcChioce() {
        return c_choice;
    }
    //�ı�Ӯ�Ĵ���
    void setcWin(int win) {
        c_win = win;
    }
    //���Ӯ�Ĵ���
    int getcWin() {
        return c_win;
    }
};

//��������࣬ͬ��
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

//������ҳ�ȭ����
int play() {

    cout << "\n������Ѿ������ˣ�����Ŷ!\n\n";
    int result;
    cout << "\t0-ʯͷ 1-���� 2-��" << endl;
  chuquan:  cout << "���ȭ: ";

    cin >> result;
    
    string jg;
    switch (result) {
    case 0:jg = "ʯͷ"; break;
    case 1:jg = "����"; break;
    case 2:jg = "��"; break;
    default: {
        //����������� 1��2��3������������
        cout << " ɵ* ! ��Ҫ�ҳ�ȭ����������!\n";
        
        goto chuquan; break;
    }
    }
    cout << "������� " << jg << endl;
    return result;
}

//չʾ�������ȭ���
int show(int result) {
    string jg2;
    switch (result) {
        
    case 0:jg2 = "ʯͷ"; break;
    case 1:jg2 = "����"; break;
    case 2:jg2 = "��"; break;
    }
    cout << "�����������" << jg2 << endl;
    return result;
}

   
int main() {
    srand((unsigned int)time(NULL));

    cout << "\t�˻���ȭ��Ϸ\n";

    int total = 0;//�ܻغ���
    Player player;//ʵ������Ҷ���
    Computer computer;//ʵ�������������

    //�����ǣ��Ա�����ѭ��
    int flag = 1;
    while (flag==1) {

        //������ҳ�ȭ��������ֵ����ҳ�ȭ���
        player.setpChioce(play());
        //����������ȭ
        computer.setcChioce(show(rand() % 3));

        int com = computer.getcChioce();
        int play = player.getpChioce();

        //�Ƚϳ�ȭ��Ӯ
        if (com == 0 && play == 1 || com == 1 && play == 2 || com == 2 && play == 0) {
            //��������Ӯ�ˣ���ȡӮ�Ĵ������� 1���ٸ�ֵ��Ӯ�Ĵ���
            computer.setcWin(computer.getcWin() + 1);
            cout << "�����Ӯ��! �ٺ� ��" << endl;
        }
        else if (com == play) {
            cout << "��! ƽ��Ŷ!" << endl;
        }
        else {
            //��ң��㣩Ӯ�ˣ���ȡӮ�Ĵ������� 1���ٸ�ֵ��Ӯ�Ĵ���
            player.setpWin(player.getpWin() + 1);
            cout << "��Ȼ����Ӯ��,��..." << endl;
        }
        total++;

        //�����˳�ѡ��
        string sign;
        cout << "\n�����˰�0�˳�����������������֮һս\n";cin >> sign;
         
          system("cls");
                
          if (sign == "0") flag = 0;
    }

    cout << "��һ��������" << total << "���غ�.\n��Ӯ��" 
        << player.getpWin()<< "��\n�����Ӯ��" 
        << computer.getcWin() << "��\nƽ��"
        << total - computer.getcWin() - player.getpWin() << "��\n";
        

    return 0;
}
