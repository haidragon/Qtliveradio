#ifndef CHATROOM_H
#define CHATROOM_H

#include <QDialog>
#include"user.h"
#include<QTcpSocket>
#include"clientsocket.h"
#include<QCloseEvent>
#include"chatroom.h"
#include<QListWidgetItem>
#include<QUdpSocket>
#include<QTcpSocket>
#include<QCamera>
#include<QCameraInfo>
#include<QHostAddress>
#include<QTimer>
#include<QLabel>
#include<QKeyEvent>
#include <QMultimedia>
#include <QFile>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <QAudioOutput>

const qint64 TIME_TRANSFORM = 1000 * 1000;              // 微秒转秒;

//解析wav音频文件用到的结构体
struct WAVFILEHEADER
{
    // RIFF 头
    char RiffName[4];
    unsigned long nRiffLength;

    // 数据类型标识符
    char WavName[4];

    // 格式块中的块头
    char FmtName[4];
    unsigned long nFmtLength;

    // 格式块中的块数据
    unsigned short nAudioFormat;
    unsigned short nChannleNumber;
    unsigned long nSampleRate;
    unsigned long nBytesPerSecond;
    unsigned short nBytesPerSample;
    unsigned short nBitsPerSample;

    // 数据块中的块头
    char    DATANAME[4];
    unsigned long   nDataLength;
};

namespace Ui {
class ChatRoom;
}

class ChatRoom : public QDialog
{
    Q_OBJECT

public:
    explicit ChatRoom(ClientSocket *cs, QTcpSocket *socket, QString curRoom,
                      user_t user, QWidget *parent = 0);
    ~ChatRoom();
    void uiDesign();    //界面设计
    void udpVideo();    //udp视频协议
    void udpAudio();    //udp音频协议
    void showChatList();        //刚进聊天室自动添加到用户列表
    virtual bool eventFilter(QObject *obj, QEvent *ev); //按enter发送消息
    qint64 addWavHeader(QString catheFileName , QString wavFileName);//将raw转换为wav
    void sendMsg(QString audioname);        //通过udp发送音频信息
    void dispaly();//播放音频

protected:
    virtual void closeEvent (QCloseEvent *);//关闭事件

private slots:
    void onsigChatName(user_t user);//添加用户名到列表
    void onsigChatList(user_t user);//刷新列表
    void on_chatlist_btn_clicked();//刷新按钮
    void onsigMasterExit(user_t user);//房主退出
    void on_send_clicked();//发送信息
    void onsigChatText(user_t user);//文字聊天信息处理
    void on_video_clicked();//视频
    void onsigVideo(user_t user);//视频处理
    void onsigunVideo(user_t user);//关闭视频
    void UdpReadRead();//udp处理槽函数
    void onvideoChanged(QVideoFrame);//视频采集成图片
    void onTimeOut();//定时器槽函数
    void onsigBs(user_t user);//弹幕处理
    void on_bs_clicked();//弹幕按钮
    void on_audio_clicked();//音频按钮
    void ReadyReadAudio();//音频udp处理槽函数
    void on_gift_clicked();//送礼按钮

private:
    Ui::ChatRoom *ui;
    user_t user;
    QString curRoom;//保存当前房间名
    QTcpSocket *socket;
    ClientSocket *cs;

    QUdpSocket *socketWrite;
    QUdpSocket *socketRead;
    QUdpSocket *socketWdaudio;
    QUdpSocket *socketRdaudio;

    QHostAddress groupAddress;
    QHostAddress groupAddress1;
    QCamera *camera;
    QTimer *timer;
    QLabel *label;

    QFile *file;
    QAudioInput * input;
    QAudioOutput* output;
    QString filename;
    QString audioname;
    QString recname;
};

#endif // CHATROOM_H


