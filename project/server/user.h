#ifndef USER_H
#define USER_H

#include<vector>
using namespace std;

enum Flag{
    UP, //登录上去
    MASTER //房主
};



enum type{
    REG,            //注册
    LOGIN,          //登录
    ONLINE,         //在线用户
    EXIT,           //用户下线
    ROOMNAME,      //创建聊天室
    CHATNAME,       //聊天室
    ROOMLIST,       //聊天室列表
    CHATLIST,       //聊天列表
    QUIT,           //退出聊天室
    TEXT,           //文字聊天
    BS,             //弹幕
    AUDIO,          //语音聊天
    VIDEO,          //视频聊天
    UNVIDEO,        //断开视频
};


typedef struct
{
    int type;   //类型
    int flag;   //状态标志位：0:登陆上；1：房主；
    char username[20];  //用户名
    char userpasswd[20];    //密码
    char roomName[20];      //聊天室名称
    char chatname[20];       //聊天对象
    char data[1024];    //数据
}user_t;

#endif // USER_H
