#include"SceneMgr.h"
#include"DxLib.h"
#include"Input.h"
#include"gameover.h"

#define PI 3.1415926535897932384626433832795f

static int mImageHandle;

static int mImagegame;
static int mImagehelp;
static int mImageend;

static int MenuNumber = 0;  //���j���[�J�[�\���Ǘ��p�ϐ�

static int mImageKnife;

// ������
void gameover_Initialize() {

    mImageHandle = LoadGraph("images/haikeigazo.png"); //�摜�̃��[�h
    
    mImagegame = LoadGraph("images/game.png");
    mImagehelp = LoadGraph("images/help.png");
    mImageend = LoadGraph("images/end.png");

    mImageKnife = LoadGraph("images/knife1.png");
}

// �I������
void gameover_Finalize() {

    DeleteGraph(mImageHandle); //�摜�̉��

    DeleteGraph(mImagegame);
    DeleteGraph(mImagehelp);
    DeleteGraph(mImageend);

    DeleteGraph(mImageKnife);
}

//�X�V
void gameover_Update() {
    //���j���[�J�[�\���ړ�����
    if (iKeyFlg & PAD_INPUT_DOWN) {
        if (++MenuNumber > 1) MenuNumber = 0;
    }
    if (iKeyFlg & PAD_INPUT_UP) {
        if (--MenuNumber < 0) MenuNumber = 1;
    }

    if (iKeyFlg == PAD_INPUT_1) { //Z�L�[��������Ă�����
        switch (MenuNumber) {       //�V�[���ɂ���ď����𕪊�
        case 0:    //���݂̉�ʂ����j���[�Ȃ�
            SceneMgr_ChangeScene(eScene_Game); //�V�[�����Q�[����ʂɕύX
            break;
        case 1:
            SceneMgr_ChangeScene(eScene_Menu); //�V�[�����w���v��ʂɕύX
            break;

        }
    }

}


void gameover_Draw() {

    DrawGraph(0, 0, mImageHandle, FALSE);

    SetFontSize(40);
    DrawString(350, 330, "CONTINUE", GetColor(255, 255, 255));
    DrawString(350, 370, "MENU", GetColor(255, 255, 255));
    SetFontSize(100);
    DrawString(160, 10, "GAME OVER", GetColor(255, 255, 255));

    DrawRotaGraph(320, 345 + MenuNumber * 40, 0.7f,0, mImageKnife, TRUE);
}